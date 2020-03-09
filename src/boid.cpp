#include "boid.h"

/* A Boid has a settable location and colour, along with a 
   reference to a Mouser (user's mouse). 
 
  See boid.h for a Boid's private properties. */

Boid::Boid(float x, float y, ofColor color, const Mouser& m, const std::vector<Boid>& bs, Parameters& p):
	mouse(m), boids(bs), params(p) {
	location.set(x, y);
	velocity.set(ofRandomf(), ofRandomf());
	this->color = color;
}

/* Update a Boid's location through this process:

	 - Seek: Calculate Acceleration Required To Follow Mouse Pointer
	 - Accelerate: Apply Acceleration to Current Velocity
	 - Move: Apply Velocity to Current Location
*/

void Boid::update() {
	// Perceive the need for seeking, separation, alignment and cohesion.
	// Accelerate! Add desired steering vectors to the Boid's velocity.

	ofVec2f acceleration;

	acceleration += separate() * params.get_separation_multiplier();
	acceleration += align() * params.get_alignment_multiplier();
	acceleration += coalesce() * params.get_cohesion_multiplier();

	if (params.get_is_mouse_seeking_enabled()) {
		acceleration += seek(mouse.get_location(), true) * params.get_mouse_seeking_multiplier();
	}

	acceleration.limit(3 * params.get_max_force());

	velocity += acceleration;

	// Limit Boid to a maximum speed.
	velocity.limit(params.get_max_speed());

	// Move! 
	location += velocity;

}

/* Boids seek a target location by moving while correcting for speed and angle.

   Seeking force calculation:

   - Full speed towards the target (desired velocity)
   - Correct for current velocity. (desired velocity - current velocity)
   - Slow down your approach as you get close. (max speed scaled to distance)

*/

ofVec2f Boid::seek(ofVec2f target_location, bool slow_approach) const {
	// Delta between target location and current location
	const auto desire_line = target_location - location;

	// The length of the distance to cover.
	const auto distance_to_cover = desire_line.length();

	// Starting from a max, scale down the boid's speed, as we approach target.
	auto approach_speed = params.get_max_speed();
	if (slow_approach && (distance_to_cover < SLOW_APPROACH_RADIUS)) {
		approach_speed *= distance_to_cover / SLOW_APPROACH_RADIUS;
	}

	// Boid desires to move at full speed towards the target location.
	auto steering_unit_vector(desire_line);
	steering_unit_vector.normalize();
	const auto approach_speed_towards_target = steering_unit_vector * approach_speed;

	// What's the difference between full speed towards target and boid's current velocity?
	auto velocity_corrected_steering_force = approach_speed_towards_target - velocity;

	// Limit steering force to a maximum.
	return velocity_corrected_steering_force.limit(params.get_max_force());
}

ofVec2f Boid::separate() {

	if (params.get_are_separation_lines_showing()) {
		debug_boids.clear();
	}

	ofVec2f sum_of_steering_vectors;

	auto count = 0;
	auto pos = 0;

	for (const auto& boid : boids) {
		auto line_between_boids = get_location() - boid.get_location();
		const auto distance = line_between_boids.length();

		if ((distance > 0) && (distance < params.get_separation_radius())) {

			if (params.get_are_separation_lines_showing()) {
				debug_boids.push_back(pos);
			}

			const auto steering_vector = line_between_boids.normalize() / distance;
			sum_of_steering_vectors += steering_vector;
			count++;
		}
		pos++;
	}

	ofVec2f summative_steering_vector;

	if (count > 0) {
		sum_of_steering_vectors /= count;
	}

	if (sum_of_steering_vectors.length() > 0) {
		sum_of_steering_vectors.normalize();
		sum_of_steering_vectors *= params.get_max_speed();
		summative_steering_vector = sum_of_steering_vectors - velocity;
		summative_steering_vector.limit(params.get_max_force());
	}

	return summative_steering_vector;
}

ofVec2f Boid::align() const {
	ofVec2f sum_of_alignment_vectors;

	for (const auto& boid : boids) {
		auto line_between_boids = location - boid.get_location();
		const float distance = line_between_boids.length();

		if ((distance > 0) && (distance < params.get_alignment_radius())) {
			sum_of_alignment_vectors += boid.get_velocity();
		}
	}

	ofVec2f summative_steering_vector;
	if (sum_of_alignment_vectors.length() > 0) {
		sum_of_alignment_vectors.normalize();
		sum_of_alignment_vectors *= params.get_max_speed();
		summative_steering_vector = sum_of_alignment_vectors - velocity;
		summative_steering_vector.limit(params.get_max_force());
	}

	return summative_steering_vector;
}

ofVec2f Boid::coalesce() const {
	ofVec2f sum_of_location_vectors;
	auto count = 0.0;

	for (const auto& boid : boids) {
		auto line_between_boids = location - boid.get_location();
		const auto distance = line_between_boids.length();

		if ((distance > 0) && (distance < params.get_cohesion_radius())) {
			sum_of_location_vectors += boid.get_location();
			count++;
		}
	}

	if (count > 0) {
		return seek(sum_of_location_vectors / count, false);
	}

	return {0, 0};
}

void Boid::wrap_around() {
	const auto width = ofGetWidth();
	const auto height = ofGetHeight();

	if (location.x < -DRAW_RADIUS) {
		location.x = width + DRAW_RADIUS;
	}
	if (location.y < -DRAW_RADIUS) {
		location.y = height + DRAW_RADIUS;
	}
	if (location.x > width + DRAW_RADIUS) {
		location.x = -DRAW_RADIUS;
	}
	if (location.y > height + DRAW_RADIUS) {
		location.y = -DRAW_RADIUS;
	}
}

/* Draw the Boid as a circle with line nose: O-
   
   The length of a Boid's nose scales to its speed.

   The DRAW_RADIUS and DRAW_STROKE constants are set in the boid.h file.

   A Boid's color is set using setup().
*/

void Boid::draw() const {

	ofSetLineWidth(DRAW_STROKE); // Set stroke witdh for lines

	ofPushMatrix(); // Save the global coordinates

	ofTranslate(location.x, location.y); // Translate coords to the boid's position

	ofSetColor(ofColor::black); // Stroke is black
	ofDrawCircle(0, 0, DRAW_RADIUS + DRAW_STROKE); // Draw the "body" stroke
	ofSetColor(color); // Fill is this->color
	ofDrawCircle(0, 0, DRAW_RADIUS); // Draw the "body" fill
	ofSetColor(ofColor::black); // Stroke is black 

	if (params.get_are_beaks_visible()) {
		// Length of boid's nose depends on radius and current velocity.
		const auto noseLength = DRAW_RADIUS * 1.1 + 3 * velocity.length();
		ofRotateZDeg(heading_in_degrees()); // Rotate coordinate system to its heading
		ofDrawLine(0, 0, noseLength, 0); // Draw the "nose" stroke
	}

	ofPopMatrix(); // Pop the saved global coordinates


	if (params.get_are_separation_lines_showing()) {

		ofSetLineWidth(3);
		ofSetColor(ofColor::darkSlateGray); // Fill is this->color

		for (auto boid_num : debug_boids) {
			const auto l2 = boids[boid_num].get_location();
			auto length = (location - l2).length();
			ofDrawLine(location.x, location.y, l2.x, l2.y);
		}
	}
}

/* Public Getter - Boid's Location */

ofVec2f Boid::get_location() const {
	return location;
}

ofVec2f Boid::get_velocity() const {
	return velocity;
}

/* Private Helper - Boid's Heading in Degrees */

float Boid::heading_in_degrees() const {
	// The angle between the xAxis and the boid's velocity is:	
	ofVec2f xAxis(1, 0);
	return xAxis.angle(velocity);
}
