#include "Parameters.h"
#include "iostream"

Parameters::Parameters() {
	gui_panel.setup();
	gui_panel.add(separation_radius_multiplier.set("Separation Radius Multiplier", 5, 0, 10));
	gui_panel.add(mouse_seeking_multiplier.set("Mouse Seeking Multiplier", 0.25, 0, 3));
	gui_panel.add(separation_multiplier.set("Separation Multiplier", 1.5, 0, 3));
	gui_panel.add(cohesion_multiplier.set("Cohesion Multiplier", 0.9, 0, 3));
	gui_panel.add(alignment_multiplier.set("Alignment Multiplier", 0.9, 0, 3));

	gui_panel.add(max_force.set("Maximum Force", 0.15, 0.05, 1));
	gui_panel.add(max_speed.set("Maximum Speed", 4, 1, 10));

	gui_panel.add(are_separation_lines_showing.set("Show Separation Lines?", false));
	gui_panel.add(is_wrap_around.set("Do Boids Wrap Around?", true));
	gui_panel.add(is_mouse_seeking_enabled.set("Are Boids Seeking Mouse?", false));
	gui_panel.add(are_beaks_visible.set("Are Beaks Visible?", true));
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

float Parameters::get_max_force() const {
	return max_force;
}

float Parameters::get_max_speed() const {
	return max_speed;
}

bool Parameters::get_is_wrap_around() const {
	return is_wrap_around;
}

bool Parameters::get_is_mouse_seeking_enabled() const {
	return is_mouse_seeking_enabled;
}

bool Parameters::get_are_beaks_visible() const {
	return are_beaks_visible;
}

bool Parameters::get_are_separation_lines_showing() const {
	return are_separation_lines_showing;
}

