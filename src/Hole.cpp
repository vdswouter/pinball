#include "Hole.h"

Hole::Hole(int x, int y, int radius) : PositionedCircle::PositionedCircle(x, y, radius) {
    ofLog() << "[HOLE] Constructor";
    _isActive = true;
    _resetAfter = 0;
}

void Hole::update(int x, int y, int radius) {
    _x = x;
    _y = y;
    setRadius(radius);

    if (_resetAfter > 0 && ofGetElapsedTimeMillis() - _resetTimestamp > _resetAfter) {
        this->setActive(!_isActive, 0);
    }
}

void Hole::draw() {
    if (_isActive) {
        ofSetColor(0,0,0,30);
        ofCircle(_x, _y, _radius);
    }   
}

void Hole::setActive(bool isActive, int resetAfter) {
    _isActive = isActive;
    
    _resetAfter = resetAfter;
    
    if (resetAfter > 0) {
        _resetTimestamp = ofGetElapsedTimeMillis();
        _resetAfter = resetAfter;
    }
}

bool Hole::isActive() {
    return _isActive;
}