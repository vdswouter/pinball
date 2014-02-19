#include "Shape.h"

Shape::Shape(int x, int y) : PositionedObject::PositionedObject(x, y) {
    type = ofRandom(0, 3);
    radius = ofRandom(2, 20);
    r = 62;
    g = 153;
    b = 102;
}

void Shape::draw() {
    ofSetColor(r, g, b);
    
    if (radius < 16) {
        ofLog() << "type: " << type;

        switch (type) {
            case 0:
                ofCircle(_x, _y, radius);
                break;
                
            case 1:
            case 2:
                ofRect(_x - radius * .5, _y - radius * .5, radius, radius);
                break;

            default:
                ofCircle(_x, _y, radius);
                break;
        }
    }
}