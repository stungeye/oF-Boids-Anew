#include "Parameters.h"
#include "iostream"

Parameters::Parameters() {

	randomize.addListener(this, &Parameters::randomize_parameters);

	gui_panel.setup("Boid Parameters");

	gui_panel.add(number_of_boids.set("Number of Boids", 300, 1, 1000));
	gui_panel.add(separation_radius.set("Separation Radius", 35, 10, 100));
	gui_panel.add(alignment_radius.set("Alignment Radius", 85, 10, 300));
	gui_panel.add(cohesion_radius.set("Cohesion Radius", 130, 10, 400));

	gui_panel.add(mouse_seeking_multiplier.set("Mouse Seeker X", 0.25, 0, 2));
	gui_panel.add(separation_multiplier.set("Separation X", 1.65, 0, 4));
	gui_panel.add(alignment_multiplier.set("Alignment X", 0.95, 0, 2));
	gui_panel.add(cohesion_multiplier.set("Cohesion X", 0.75, 0, 2));

	gui_panel.add(max_force.set("Maximum Force", 0.075, 0.01, 0.3));
	gui_panel.add(max_speed.set("Maximum Speed", 4.5, 1, 6));

	gui_panel.add(are_steering_behaviours_banded.set("Banded Behaviours?", false));
	gui_panel.add(are_separation_lines_showing.set("Show Separation Lines?", false));
	gui_panel.add(is_wrap_around.set("Do Boids Wrap Around?", true));
	gui_panel.add(is_mouse_seeking_enabled.set("Are Boids Seeking Mouse?", false));
	gui_panel.add(are_beaks_visible.set("Are Beaks Visible?", true));

	gui_panel.add(randomize.setup("Randomize!"));
}

void Parameters::draw() {
	gui_panel.draw();
}

size_t Parameters::get_number_of_boids() const {
	return number_of_boids;
}

int Parameters::get_separation_radius() const {
	return separation_radius;
}

int Parameters::get_cohesion_radius() const {
	return cohesion_radius;
}

int Parameters::get_alignment_radius() const {
	return alignment_radius;
}

float Parameters::get_mouse_seeking_multiplier() const {
	return mouse_seeking_multiplier;
}

float Parameters::get_separation_multiplier() const {
	return separation_multiplier;
}

float Parameters::get_cohesion_multiplier() const {
	return cohesion_multiplier;
}

float Parameters::get_alignment_multiplier() const {
	return alignment_multiplier;
}

float Parameters::get_max_force() const {
	return max_force;
}

float Parameters::get_max_speed() const {
	return max_speed;
}

bool Parameters::get_is_wrap_around() const {
	return is_wrap_around;
}

bool Parameters::get_is_mouse_seeking_enabled() const {
	return is_mouse_seeking_enabled;
}

bool Parameters::get_are_beaks_visible() const {
	return are_beaks_visible;
}

bool Parameters::get_are_steering_behaviours_banded() const {
	return are_steering_behaviours_banded;
}

bool Parameters::get_are_separation_lines_showing() const {
	return are_separation_lines_showing;
}

void Parameters::randomize_parameters() {
	separation_multiplier = ofRandom(separation_multiplier.getMin(), separation_multiplier.getMax());
	alignment_multiplier = ofRandom(alignment_multiplier.getMin(), alignment_multiplier.getMax());
	cohesion_multiplier = ofRandom(cohesion_multiplier.getMin(), cohesion_multiplier.getMax());
	mouse_seeking_multiplier = ofRandom(mouse_seeking_multiplier.getMin(), mouse_seeking_multiplier.getMax());

	separation_radius = ofRandom(separation_radius.getMin(), separation_radius.getMax());
	alignment_radius =  ofRandom(alignment_radius.getMin(), alignment_radius.getMax());
	cohesion_radius = ofRandom(cohesion_radius.getMin(), cohesion_radius.getMax());

	max_force = ofRandom(max_force.getMin(), max_force.getMax());
	max_speed = ofRandom(max_speed.getMin(), max_speed.getMax());
}
