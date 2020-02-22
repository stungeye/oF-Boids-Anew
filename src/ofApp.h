#pragma once

#include "ofMain.h"

#include "boid.h"
#include "Mouser.h"
#include "Parameters.h"

#include <vector>

class ofApp : public ofBaseApp{
	const int NUMBER_OF_BOIDS = 100;

	// A vector of Boids and a Mouser.
	std::vector<Boid> boids;
	Mouser the_mouse;
	Parameters params;
	bool show_gui = false;

	public:
		void setup();
		void update();
		void draw();
		void keyReleased(int key);
};

