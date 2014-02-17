#include "PositionedObject.h"

PositionedObject::PositionedObject(int x, int y, int radius) {
    ofLog() << "[PositionedObject] Constructor";
    _x = x;
    _y = y;
}

void PositionedObject::setPosition(int x, int y) {
    _x = x;
    _y = y;
}

bool PositionedObject::detectHit(PositionedObject *object) {
    return false;
}

int PositionedObject::x() {
    return _x;
}

int PositionedObject::y() {
    return _y;
}