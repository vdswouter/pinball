#include "Ball.h"

Ball::Ball(int x, int y, int radius) : PositionedCircle::PositionedCircle(x, y, radius) {
    ofLog() << "[BALL] Constructor";
}

void Ball::update() {
}

void Ball::draw() {
    if (_track.size() > 0) {
        ofSetColor(255, 125, 25);
        int i = _track.size();
        for (int j = 0; j < 10; j++) {
            ofPoint point = _track[i];
            ofCircle(point.x, point.y, 4);
            i--;
        }
    }
    
    ofSetColor(255, 255, 255);
    ofCircle(_x, _y, _radius);
}

void Ball::setPosition(int x, int y) {
    _track.push_back(ofPoint(x, y, 0));
    _x = x;
    _y = y;
}

void Ball::resetTrack() {
    _track.clear();
}