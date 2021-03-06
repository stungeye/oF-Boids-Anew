#pragma once

#include "ofMain.h"

class Mouser
{
	/* Play with these constants to tweak how mouse pointer is drawn. */
	const float DRAW_RADIUS = 20;
	const float DRAW_STROKE = 3;
	const ofColor DEFAULT_COLOR = ofColor::cornflowerBlue;
	const ofColor TOUCHING_COLOR = ofColor::cornflowerBlue;

	/* Private Properties */
	ofVec2f location;

public:
	void update();
	void draw();
	void draw(ofVec2f otherLocation);
	ofVec2f get_location() const;
};

