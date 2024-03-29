#pragma once

#include "ofMain.h"
#include "Mouser.h"
#include "Parameters.h"
#include <vector>

class Boid {
	/* Play with these constants to tweak the seeking. */
	const float MAX_SPEED = 5;
	const float MAX_FORCE = 0.2;
	const float SLOW_APPROACH_RADIUS = 100;

	/* Want bigger Boids? Tiny ones? */
	const float DRAW_RADIUS = 4;
	const float DRAW_STROKE = 2;

	/* Private Properties */
	ofVec2f location;
	ofVec2f velocity;
	ofColor color;
	std::vector<int> debug_boids;
	const Mouser& mouse;
	const std::vector<Boid>& boids;
	const Parameters& params;

public:
	Boid(float x, float y, ofColor color, const Mouser& m, const std::vector<Boid>& bs, Parameters& p);
	void update();
	void draw() const;
	ofVec2f get_location() const;
	ofVec2f get_velocity() const;
	void wrap_around();
private:
	ofVec2f seek(ofVec2f target_location, bool slow_approach) const;
	ofVec2f separate();
	ofVec2f align() const;
	ofVec2f coalesce(bool maximize_distance) const;
	float heading_in_degrees() const;
};
