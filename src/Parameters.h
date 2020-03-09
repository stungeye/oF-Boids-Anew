#pragma once

#include "ofxGui.h"

class Parameters {
	
	ofxPanel gui_panel;

	ofParameter<int> separation_radius;
	ofParameter<int> cohesion_radius;
	ofParameter<int> alignment_radius;

	ofParameter<float> separation_multiplier;
	ofParameter<float> mouse_seeking_multiplier;
	ofParameter<float> cohesion_multiplier;
	ofParameter<float> alignment_multiplier;

	ofParameter<float> max_force;
	ofParameter<float> max_speed;
	
	ofParameter<bool> are_separation_lines_showing;
	ofParameter<bool> is_wrap_around;
	ofParameter<bool> is_mouse_seeking_enabled;
	ofParameter<bool> are_beaks_visible;
	ofParameter<bool> are_steering_behaviours_banded;

	ofxButton randomize;
	
public:
	Parameters();
	void draw();

	int get_separation_radius() const;
	int get_cohesion_radius() const;
	int get_alignment_radius() const;

	float get_mouse_seeking_multiplier() const;
	float get_separation_multiplier() const;
	float get_cohesion_multiplier() const;
	float get_alignment_multiplier() const;

	float get_max_force() const;
	float get_max_speed() const;
	
	bool get_are_separation_lines_showing() const;
	bool get_is_wrap_around() const;
	bool get_is_mouse_seeking_enabled() const;
	bool get_are_beaks_visible() const;
	bool get_are_steering_behaviours_banded() const;

private:
	void randomize_parameters();
};
