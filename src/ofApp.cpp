// #include <iostream>

#include "ofApp.h"

//--SETUP------------------------------------------------------------
void ofApp::setup() {
	ofBackground(ofColor::white); // Set a white background.
	populate_flock();
}


//--UPDATE------------------------------------------------------------
void ofApp::update() {
	// Update the mouse and the boids.
	the_mouse.update();

	if (params.get_number_of_boids() > boids.size()) {
		populate_flock();
	} else if (params.get_number_of_boids() < boids.size()) {
		// Couldn't use .erase(boids.begin() + params.get_number_of_boids(), boids.end())
		// Even though we're removing from the end, erase() assumes that shuffling might
		// be required and therefore requires a Boid& Boid::operator=(const Boid& other)

		// Instead we clear the entire flock and let it repopulate on the next update();
		 boids.clear();
	}

	if (params.get_is_wrap_around()) {
		for (auto& boid : boids) {
			boid.wrap_around();
		}
	}

	for (auto& boid : boids) {
		boid.update();
	}
}

//--DRAW------------------------------------------------------------
void ofApp::draw() {
	if (params.get_is_mouse_seeking_enabled()) {
		// Draw the mouse and the boids.
		the_mouse.draw();
	}

	for (const auto& boid : boids) {
		boid.draw();
	}

	if (show_gui) {
		params.draw();
	}
}

void ofApp::keyReleased(int key) {
	if (key == 'g') {
		show_gui = !show_gui;

		if (show_gui) {
			ofShowCursor();
		}
		else {
			ofHideCursor();
		}
	}
}

void ofApp::populate_flock() {
	boids.reserve(params.get_number_of_boids());

	for (auto i = boids.size(); i < params.get_number_of_boids(); ++i) {
		boids.emplace_back(
			ofRandomWidth(),
			ofRandomHeight(),
			ofColor::darkorange, // fill color
			the_mouse, // the Mouser
			boids, // the boids vector
			params
			);
	}
}
