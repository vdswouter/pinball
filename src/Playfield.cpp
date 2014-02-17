#include "Playfield.h"

Playfield::Playfield(int w, int h) {
    width = w;
    height = h;
    ofLog() << "[PLAYFIELD] Constructor";
    _conquered = .5;
}

void Playfield::update() {
    _conquered -= .001;
}

void Playfield::draw() {
    // Draw main playground
    ofSetColor(200, 30, 75);
    ofRect(0, 0, width, height);
    
    // Draw conquered
    ofSetColor(25, 125, 255);
    ofRect(0, 0, width * _conquered, height);
}

void Playfield::conquer(float points) {
    _conquered += points;
    
    if (_conquered > 1) {
        _conquered = 1;
    } else if (_conquered < 0) {
        _conquered = 0;
    }
}

bool Playfield::isDefeated() {
    return _conquered <= 0;
}

bool Playfield::isConquered() {
    return _conquered >= .99;
}