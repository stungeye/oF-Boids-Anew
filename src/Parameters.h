#pragma once

#include "ofxGui.h"

class Parameters {
	
	ofxPanel gui_panel;
	ofParameter<int> separation_radius_multiplier;
	ofParameter<float> separation_multiplier;
	ofParameter<float> mouse_seeking_multiplier;
	ofParameter<float> cohesion_multiplier;
	ofParameter<float> alignment_multiplier;
	ofParameter<bool> are_separation_lines_showing;
	ofParameter<bool> is_wrap_around;
	ofParameter<bool> is_mouse_seeking_enabled;
	
public:
	Parameters();
	void draw();
	int get_separation_radius_multiplier() const;
	float get_mouse_seeking_multiplier() const;
	float get_separation_multiplier() const;
	float get_cohesion_multiplier() const;
	float get_alignment_multiplier() const;
	bool get_are_separation_lines_showing() const;
	bool get_is_wrap_around() const;
	bool get_is_mouse_seeking_enabled() const;
};
