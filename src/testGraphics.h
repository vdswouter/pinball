//
//  testGraphics.h
//  _EXD_ProjectionPinball
//
//  Created by Wouter Vandersyppe on 16/02/14.
//
//

#ifndef ___EXD_ProjectionPinball__testGraphics__
#define ___EXD_ProjectionPinball__testGraphics__

#include "ofMain.h"
#include "ofxParticles.h"

class testGraphics {
    
public:
    void setup();
    void update();
    void draw();
    
    void setPosition(int x, int y);
    
private:
    ofVec3f centerPoint;
    ofVec3f mousePos;
    ofVec3f mouseVel;
    ofVec3f prevMousePos;
    ofVec3f prevMouseVel;
    
    ofxParticleSystem particleSystem;
    ofxParticleEmitter rightEmitter;
    float rotAcc, gravAcc, fieldMult, drag;
    ofFloatPixels vectorField;
    
    ofTexture tex;
//    ofEasyCam cam;
};

#endif