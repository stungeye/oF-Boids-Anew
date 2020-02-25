#include "Parameters.h"
#include "iostream"

Parameters::Parameters() {
	gui_panel.setup();
	gui_panel.add(separation_radius_multiplier.set("Separation Radius Multiplier", 4, 0, 10));
	gui_panel.add(mouse_seeking_multiplier.set("Mouse Seeking Multiplier", 0.25, 0, 3));
	gui_panel.add(separation_multiplier.set("Separation Multiplier", 1.5, 0, 3));
	gui_panel.add(cohesion_multiplier.set("Cohesion Multiplier", 1, 0, 3));
	gui_panel.add(alignment_multiplier.set("Alignment Multiplier", 1, 0, 3));
	gui_panel.add(debug_separation_lines.set("Debug Separation Lines", false));
}

void Parameters::draw() {
	gui_panel.draw();
}

int Parameters::get_separation_radius_multiplier() const {
	return separation_radius_multiplier;
}

float Parameters::get_mouse_seeking_multiplier() const {
	return mouse_seeking_multiplier;
}

float Parameters::get_separation_multiplier() const {
	return separation_multiplier;
}

float Parameters::get_cohesion_multiplier() const {
	return cohesion_multiplier;
}

float Parameters::get_alignment_multiplier() const {
	return alignment_multiplier;
}

float Parameters::get_debug_separation_lines() const {
	return debug_separation_lines;
}

