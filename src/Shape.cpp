#include "Shape.h"

Shape::Shape(int x, int y) : PositionedObject::PositionedObject(x, y) {
    type = ofRandom(0, 3);
    radius = ofRandom(2, 20);
    r = 62;
    g = 153;
    b = 102;
}

void Shape::setup(){

    
}

void Shape::draw() {
//    ofSetColor(ofRandom(255), ofRandom(255), ofRandom(255));
//    
//    if (radius < 16) {
//        ofLog() << "type: " << type;
//
//        switch (type) {
//            case 0:
//                ofCircle(_x, _y, radius);
//                break;
//                
//            case 1:
//            case 2:
//                ofRect(_x - radius * .5, _y - radius * .5, radius, radius);
//                break;
//
//            default:
//                ofCircle(_x, _y, radius);
//                break;
//        }
//    }
}

void Shape::kaktNenShape(int xpos, int ypos, int radius){
    type = ofRandom(0, 3);
    int color = ofRandom(0,6);
    int alpha = 200;
    
    switch (color) {
        case 0:
            ofSetColor(22, 147, 165, alpha);
            break;
            
        case 1:
            ofSetColor(69,181,196, alpha);
            break;
            
        case 2:
            ofSetColor(126,206,202, alpha);
            break;
            
        case 3:
            ofSetColor(160,222,214, alpha);
            break;
            
        case 4:
            ofSetColor(199,237,232, alpha);
            break;
            
        default:
            ofSetColor(69,181,196, alpha);
            break;
    }
    
    
    switch (type) {
        case 0:
            ofCircle(xpos, ypos, radius);
            break;
            
        case 1:
            ofTriangle(xpos, ypos - radius, xpos + radius*0.5, ypos+radius*0.5, xpos-radius*0.5, ypos+radius*0.5);
            break;
        case 2:
            ofRect(xpos - radius * .5, ypos - radius * .5, radius, radius);
            break;
            
        default:
            ofCircle(xpos, ypos, radius);
            break;
    }
    ofSetColor(255, 255, 255, 255);
}