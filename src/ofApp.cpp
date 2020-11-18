#include "ofApp.h"

//--SETUP------------------------------------------------------------
void ofApp::setup() {
    // Set a white background.
    ofBackground(ofColor::white); 
    
    // Populate our flock of boids.
    populate_flock();
}


//--UPDATE------------------------------------------------------------
void ofApp::update() {

    // Update the mouse object with the current mouse position.
    the_mouse.update();

    // Grow or shirk the boid based on the number of boids GUI slider.
    if (params.get_number_of_boids() > boids.size()) {
        populate_flock();
    }
    else if (params.get_number_of_boids() < boids.size()) {
        // Couldn't use .erase(boids.begin() + params.get_number_of_boids(), boids.end())
        // Even though we're removing from the end, erase() assumes that shuffling might
        // be required and therefore requires a Boid& Boid::operator=(const Boid& other)

        // Instead we clear the entire flock and let it repopulate on the next update();
        boids.clear();
    }

    // Wrap boids at vertical and horizontal edges if this is enabled in the GUI.
    if (params.get_is_wrap_around()) {
        for (auto& boid : boids) {
            boid.wrap_around();
        }
    }

    // Update the flock.
    for (auto& boid : boids) {
        boid.update();
    }
}

//--DRAW------------------------------------------------------------
void ofApp::draw() {
    // Draw mouse if boids are set to seek it.
    if (params.get_is_mouse_seeking_enabled()) {
        the_mouse.draw();
    }

    // Draw flock of boids.
    for (const auto& boid : boids) {
        boid.draw();
    }

    // Optionally show GUI buttons and sliders.
    if (show_gui) {
        params.draw();
    }
}

// Used to toggle the GUI buttons and sliders using the 'g' key.
// Was able to make key param const, even though original signature doesn't include const.
void ofApp::keyReleased(const int key) {
    if (key == 'g') {
        show_gui = !show_gui;

        // Only show a mouse cursor if the GUI buttons and sliders are enable.
        if (show_gui) {
            ofShowCursor();
        }
        else {
            ofHideCursor();
        }
    }
}

// Used in draw() to grow the flock based on the number of boids set by the GUI boids sliders.
// Also used in setup() to fill the boids vector with its initial population of boids. 
void ofApp::populate_flock() {
    boids.reserve(params.get_number_of_boids());

    for (auto i = boids.size(); i < params.get_number_of_boids(); ++i) {
        // Call to emplace_back uses Boid constructor to create a new boid to be added to the boids vector.
        boids.emplace_back(
            ofRandomWidth(),
            ofRandomHeight(),
            ofColor::darkorange, // Fill color of boid. 
            the_mouse, // Reference to the Mouser object. 
            boids, // Reference to the flock (vector of Boids)
            params // Reference to the Parameters object.
        );
    }
}
