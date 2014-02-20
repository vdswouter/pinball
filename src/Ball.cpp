#include "Ball.h"

Ball::Ball(int x, int y, int radius) : PositionedCircle::PositionedCircle(x, y, radius) {
    ofLog() << "[BALL] Constructor";
    fbo.allocate();
    Shape(0, 0);
}

void Ball::update() {
}

void Ball::draw() {
//    if (_track.size() > 0) {
//        ofSetColor(255, 255, 255);
//        int i = _track.size();
//        for (int j = 0; j < _track.size() && j < 20; j++) {
//            Shape s = _track[i];
//            s.draw();
//            i--;
//        }
//    }
    ofSetColor(255, 255, 255, 255);
    fbo.draw(0, 0);

    ofSetColor(0);
    ofCircle(_x, _y, _radius);
    ofSetColor(255);
}

void Ball::setPosition(int x, int y) {
    fbo.begin();
    {
        Shape(0, 0).kaktNenShape(x, y, (abs(prevx - x) + abs(prevy - y))/5);
    }
    fbo.end();
    _x = x;
    _y = y;
    prevx = x;
    prevy = y;
}

void Ball::resetTrack() {
    fbo.begin();
    {
        ofClear(255, 255, 255, 0);
    }
    fbo.end();
}