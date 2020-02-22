#pragma once

#include "ofMain.h"
#include "Mouser.h"
#include "Parameters.h"
#include <vector>

class Boid
{
	/* Play with these constants to tweak the seeking. */
	const float MAX_SPEED = 7;
	const float MAX_FORCE = 0.25;
	const float SLOW_APPROACH_RADIUS = 100;

	/* Want bigger Boids? Tiny ones? */
	const float DRAW_RADIUS = 10;
	const float DRAW_STROKE = 5;

	/* Private Properties */
	ofVec2f location;
	ofVec2f velocity;
	ofVec2f acceleration;
	ofColor color;
	std::vector<int> debug_boids;
	const Mouser& mouse;
	const std::vector<Boid>& boids;
	Parameters& params;

public:
	Boid(float x, float y, ofColor color, const Mouser& m, const std::vector<Boid>& bs, Parameters& p);
	ofVec2f seek(ofVec2f targetLocation) const;
	ofVec2f separate();
	void update();
	void draw() const;
	ofVec2f get_location() const;
private:
	float heading_in_degrees() const;
};
