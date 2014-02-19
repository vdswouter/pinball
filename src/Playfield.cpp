#include "Playfield.h"

Playfield::Playfield(int w, int h) {
    width = w;
    height = h;
    ofLog() << "[PLAYFIELD] Constructor";
    _conquered = .5;
}

void Playfield::update() {
    _conquered -= conquerspeed / 3000;
}

void Playfield::draw() {
    // Draw main playground
    ofSetColor(234, 59, 64);
    ofRect(0, 0, width, height);
    
    // Draw conquered
    ofSetColor(41, 81, 103);
    ofRect(0, height - height * _conquered, width, height * _conquered);
}

float Playfield::conquered() {
    return _conquered;
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

void Playfield::reset() {
    _conquered = .15;
}