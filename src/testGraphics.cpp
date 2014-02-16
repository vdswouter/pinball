//
//  testGraphics.cpp
//  _EXD_ProjectionPinball
//
//  Created by Wouter Vandersyppe on 16/02/14.
//
//

#include "testGraphics.h"

void testGraphics::setup(){
    centerPoint.set(0, 0, 0);
    
    rightEmitter.setPosition(ofVec3f(100, 100));
    rightEmitter.setVelocity(ofVec3f(-150.0, 150.0, 150.0));
    rightEmitter.posSpread = ofVec3f(10, 10, 10);
    rightEmitter.velSpread = ofVec3f(200,200,200);
    rightEmitter.life = 2;
    rightEmitter.lifeSpread = 10;
    rightEmitter.numPars = 2;
    rightEmitter.size = 12;
    rightEmitter.color = ofColor(0, 150, 255);
    rightEmitter.colorSpread = ofColor(50, 50, 50);
    
    vectorField.allocate(128, 128, 3);
    ofLoadImage(tex, "tex.png");
    
    rotAcc = 4500;
    gravAcc = 13500;
    drag = 0.5;
    fieldMult = 30.0;
}

void testGraphics::update(){
    for (int y = 0; y < vectorField.getHeight(); y++) {
        for (int x = 0; x< vectorField.getWidth(); x++) {
            int index = vectorField.getPixelIndex(x, y);
            float angle = ofNoise(x / (float)vectorField.getWidth() * 4.0f, y / (float)vectorField.getHeight() * 4.0f, ofGetElapsedTimef() * 0.05f) * TWO_PI * 2.0f;
            ofVec2f dir(cos(angle), sin(angle));
            dir.normalize().scale(ofNoise(x / (float)vectorField.getWidth() * 4.0f, y / (float)vectorField.getHeight() * 4.0f, ofGetElapsedTimef() * 0.05 + 10.0f));
            vectorField.setColor(x, y, ofColor_<float>(dir.x, dir.y, 0.0f));
        }
    }
    
    // Add forces.
    float dt = MIN(ofGetLastFrameTime(), 1.0f / 10.0f);
    particleSystem.gravitateTo(centerPoint, gravAcc, 1.0f, 10.0f, false);
    particleSystem.rotateAround(centerPoint, rotAcc, 10.0f, false);
    particleSystem.applyVectorField(vectorField.getPixels(), vectorField.getWidth(), vectorField.getHeight(), vectorField.getNumChannels(), ofGetWindowRect(), fieldMult);
    
    particleSystem.update(dt, drag);
    
    particleSystem.addParticles(rightEmitter);
}

void testGraphics::setPosition(int x, int y){
    rightEmitter.setPosition(ofVec3f(x, y));
}

void testGraphics::draw(){
//    cam.begin();
    // Draw system.

    ofSetLineWidth(2.0);
    particleSystem.draw(tex);
    
//    cam.end();
}