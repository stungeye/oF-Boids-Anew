#include "Mouser.h"

/* Set Mouser location to the location of the mouse pointer. */

void Mouser::update() {
	location.x = ofGetMouseX();
	location.y = ofGetMouseY();
}

/* Draw the mouse pointer as a circle with a black stroke.

   Circle fill color changes when the boid arrives.

   Tweak the following constants in the Mouser.h file:
     DRAW_RADIUS 
     DRAW_STROKE
     DEFAULT_COLOR
     TOUCHING_COLOR
*/

void Mouser::draw(ofVec2f otherLocation)
{
	// How far is the other?
	float distance_to_other = location.distance(otherLocation);

	// Draw pseudo-stroke in black
	ofSetColor(ofColor::black);  
	ofDrawCircle(location.x, location.y, DRAW_RADIUS + DRAW_STROKE);

	// The fill changes if other location is in our 2x radius hit zone.
	if (distance_to_other <= DRAW_RADIUS * 2) {
		ofSetColor(TOUCHING_COLOR);  
	}
	else {
		ofSetColor(DEFAULT_COLOR);  
	}

	// Draw circle with selected fill color.
	ofDrawCircle(location.x, location.y, DRAW_RADIUS);  
}

/* If you don't care about collision colour change here's a simpler draw(). */

void Mouser::draw() {
	ofSetColor(ofColor::black);                                      // pseudo-stroke is black
	ofDrawCircle(location.x, location.y, DRAW_RADIUS + DRAW_STROKE); // draw stroke
	ofSetColor(DEFAULT_COLOR);                                       // fill is default color
	ofDrawCircle(location.x, location.y, DRAW_RADIUS);               // draw fill
}

/* Public Getter - Mouse Location */

ofVec2f Mouser::get_location() const {
	return location;
}
