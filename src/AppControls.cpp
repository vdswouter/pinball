//
//  controls.cpp
//  _EXD_ProjectionPinball
//
//  Created by Wouter Vandersyppe on 11/02/14.
//
//

#include "AppControls.h"

void AppControls::setup(){
    for (int i = 0; i < 4; i++) {
        videoBounds.push_back(ofPoint(0,0));
        projectionBounds.push_back(ofPoint(0,0));
    }
    
    projectionControls.setup();
    projectionControls.setName("Projection Coords");
    projectionControls.add(ULProjectionslider.setup("UP LEFT", ofVec2f(0, 0), ofVec2f(0, 0), ofVec2f(ofGetWidth(), ofGetHeight())));
    projectionControls.add(DLProjectionslider.setup("DOWN LEFT", ofVec2f(0, ofGetHeight()), ofVec2f(0, 0), ofVec2f(ofGetWidth(), ofGetHeight())));
    projectionControls.add(URProjectionslider.setup("UP RIGHT", ofVec2f(ofGetWidth(), 0), ofVec2f(0, 0), ofVec2f(ofGetWidth(), ofGetHeight())));
    projectionControls.add(DRProjectionslider.setup("DOWN RIGHT", ofVec2f(ofGetWidth(), ofGetHeight()), ofVec2f(0,0), ofVec2f(ofGetWidth(), ofGetHeight())));
    
    videoControls.setup();
    videoControls.setName("Video Input Coords");
    videoControls.setPosition(projectionControls.getPosition().x + projectionControls.getWidth() +10, projectionControls.getPosition().y);
    videoControls.add(ULVideoslider.setup("UP LEFT", ofVec2f(0, 0), ofVec2f(0, 0), ofVec2f(ofGetWidth(), ofGetHeight())));
    videoControls.add(DLVideoslider.setup("DOWN LEFT", ofVec2f(0, ofGetHeight()), ofVec2f(0, 0), ofVec2f(ofGetWidth(), ofGetHeight())));
    videoControls.add(URVideoslider.setup("UP RIGHT", ofVec2f(ofGetWidth(), 0), ofVec2f(0, 0), ofVec2f(ofGetWidth(), ofGetHeight())));
    videoControls.add(DRVideoslider.setup("DOWN RIGHT", ofVec2f(ofGetWidth(), ofGetHeight()), ofVec2f(0,0), ofVec2f(ofGetWidth(), ofGetHeight())));
}

void AppControls::update(){
    projectionBounds[0].x = ULProjectionslider->x;
    projectionBounds[0].y = ULProjectionslider->y;
    projectionBounds[1].x = DLProjectionslider->x;
    projectionBounds[1].y = DLProjectionslider->y;
    projectionBounds[2].x = URProjectionslider->x;
    projectionBounds[2].y = URProjectionslider->y;
    projectionBounds[3].x = DRProjectionslider->x;
    projectionBounds[3].y = DRProjectionslider->y;
    
    videoBounds[0].x = ULVideoslider->x;
    videoBounds[0].y = ULVideoslider->y;
    videoBounds[1].x = DLVideoslider->x;
    videoBounds[1].y = DLVideoslider->y;
    videoBounds[2].x = URVideoslider->x;
    videoBounds[2].y = URVideoslider->y;
    videoBounds[3].x = DRVideoslider->x;
    videoBounds[3].y = DRVideoslider->y;
}

void AppControls::draw(){
    projectionControls.draw();
    videoControls.draw();
}