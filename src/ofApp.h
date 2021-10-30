#pragma once

#include "ofMain.h"

#include "boid.h"
#include "Mouser.h"
#include "Parameters.h"

#include <vector>

class ofApp : public ofBaseApp {
public:
	void setup() override;
	void update() override;
	void draw() override;
	void keyReleased(int key) override;

private:
	void populate_flock();

	std::vector<Boid> boids;
	Mouser the_mouse;
	Parameters params;
	bool show_gui = true;
};
