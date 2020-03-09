#include "Parameters.h"
#include "iostream"

Parameters::Parameters() {

	randomize.addListener(this, &Parameters::randomize_parameters);

	gui_panel.setup("Boid Parameters");
	gui_panel.add(separation_radius.set("Separation Radius", 35, 10, 100));
	gui_panel.add(cohesion_radius.set("Cohesion Radius", 200, 10, 500));
	gui_panel.add(alignment_radius.set("Alignment Radius", 100, 10, 500));

	gui_panel.add(mouse_seeking_multiplier.set("Mouse Seeker X", 0.25, 0, 3));
	gui_panel.add(separation_multiplier.set("Separation X", 1.5, 0, 3));
	gui_panel.add(cohesion_multiplier.set("Cohesion X", 0.9, 0, 3));
	gui_panel.add(alignment_multiplier.set("Alignment X", 0.9, 0, 3));

	gui_panel.add(max_force.set("Maximum Force", 0.15, 0.01, 0.5));
	gui_panel.add(max_speed.set("Maximum Speed", 4, 1, 7));

	gui_panel.add(are_separation_lines_showing.set("Show Separation Lines?", false));
	gui_panel.add(is_wrap_around.set("Do Boids Wrap Around?", true));
	gui_panel.add(is_mouse_seeking_enabled.set("Are Boids Seeking Mouse?", false));
	gui_panel.add(are_beaks_visible.set("Are Beaks Visible?", true));

	gui_panel.add(randomize.setup("Randomize!"));
}

void Parameters::draw() {
	gui_panel.draw();
}

int Parameters::get_separation_radius() const {
	return separation_radius;
}

int Parameters::get_cohesion_radius() const {
	return cohesion_radius;
}

int Parameters::get_alignment_radius() const {
	return alignment_radius;
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

void Parameters::randomize_parameters() {
	separation_multiplier = ofRandom(separation_multiplier.getMin(), separation_multiplier.getMax());
	alignment_multiplier = ofRandom(alignment_multiplier.getMin(), alignment_multiplier.getMax());
	cohesion_multiplier = ofRandom(cohesion_multiplier.getMin(), cohesion_multiplier.getMax());
	mouse_seeking_multiplier = ofRandom(mouse_seeking_multiplier.getMin(), mouse_seeking_multiplier.getMax());

	separation_radius = ofRandom(separation_radius.getMin(), separation_radius.getMax());
	alignment_radius =  ofRandom(alignment_radius.getMin(), alignment_radius.getMax());
	cohesion_radius = ofRandom(cohesion_radius.getMin(), cohesion_radius.getMax());

	max_force = ofRandom(max_force.getMin(), max_force.getMax());
	max_speed = ofRandom(max_speed.getMin(), max_speed.getMax());
}
