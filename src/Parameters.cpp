#include "Parameters.h"
#include "iostream"

Parameters::Parameters() {
	gui_panel.setup();
	gui_panel.add(separation_multiplier.setup("Separation Multiplier", 2, 0, 3));
	gui_panel.add(separation_radius_multiplier.set("Separation Radius Multiplier", 4, 0, 10));
	gui_panel.add(mouse_seeking_multiplier.setup("Mouse Seeking Multiplier", 0.5, 0, 3));
}

void Parameters::draw() {
	gui_panel.draw();
}

float Parameters::get_separation_multiplier() {
	return separation_multiplier;
}

int Parameters::get_separation_radius_multiplier() const {
	return separation_radius_multiplier;
}

float Parameters::get_mouse_seeking_multiplier() {
	return mouse_seeking_multiplier;
}

