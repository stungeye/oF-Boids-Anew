#pragma once

#include "ofxGui.h"

class Parameters {
	
	ofxPanel gui_panel;
	ofxFloatSlider separation_multiplier;
	ofParameter<int> separation_radius_multiplier;
	ofxFloatSlider mouse_seeking_multiplier;
	
public:
	Parameters();
	void draw();
	float get_separation_multiplier();
	int get_separation_radius_multiplier() const;
	float get_mouse_seeking_multiplier();
};
