#include "PositionedCircle.h"

PositionedCircle::PositionedCircle(int x, int y, int radius) : PositionedObject::PositionedObject(x, y) {
    ofLog() << "[PositionedCircle] Constructor";
    _radius = radius;
}

void PositionedCircle::setRadius(int radius) {
    _radius = radius;
}

int PositionedCircle::radius() {
    return _radius;
}

bool PositionedCircle::detectCircularHit(PositionedCircle *circle) {
    int dx = _x - circle->x();
    int dy = _y - circle->y();
    int radii = _radius + circle->radius();
    
    return (dx * dx) + (dy * dy) < radii * radii;
}