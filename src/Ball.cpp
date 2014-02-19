#include "Ball.h"

Ball::Ball(int x, int y, int radius) : PositionedCircle::PositionedCircle(x, y, radius) {
    ofLog() << "[BALL] Constructor";
}

void Ball::update() {
}

void Ball::draw() {
    if (_track.size() > 0) {
        ofSetColor(255, 255, 255);
        int i = _track.size();
        for (int j = 0; j < _track.size() && j < 20; j++) {
            Shape s = _track[i];
            s.draw();
            i--;
        }
    }
    
    ofSetColor(0);
    ofCircle(_x, _y, _radius);
    ofSetColor(255);
}

void Ball::setPosition(int x, int y) {
    _track.push_back(Shape(x, y));
    _x = x;
    _y = y;
}

void Ball::resetTrack() {
    _track.clear();
}