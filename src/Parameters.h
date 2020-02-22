#pragma once

#include "ofxGui.h"

class Parameters {
	
	ofxPanel gui_panel;
	ofParameter<int> separation_radius_multiplier;
	ofParameter<float> separation_multiplier;
	ofParameter<float> mouse_seeking_multiplier;
	ofParameter<float> cohesion_multiplier;
	ofParameter<float> alignment_multiplier;
	
public:
	Parameters();
	void draw();
	int get_separation_radius_multiplier() const;
	float get_mouse_seeking_multiplier() const;
	float get_separation_multiplier() const;
	float get_cohesion_multiplier() const;
	float get_alignment_multiplier() const;
};
