//
//  controls.cpp
//  _EXD_ProjectionPinball
//
//  Created by Wouter Vandersyppe on 11/02/14.
//
//

#include "AppControls.h"

void AppControls::setup(ColorTracking * colorTracking){
    ct = colorTracking;
    for (int i = 0; i < 4; i++) {
        videoBounds.push_back(ofPoint(0,0));
        projectionBounds.push_back(ofPoint(0,0));
    }
    
    DimProjectionSlider.addListener(this, &AppControls::DimProjectionSliderHandler);
    projectionControls.setup();
    projectionControls.setName("Projection Coords");
    projectionControls.add(ULProjectionslider.setup("UP LEFT", ofVec2f(0, 0), ofVec2f(0, 0), ofVec2f(ofGetWidth(), ofGetHeight())));
    projectionControls.add(URProjectionslider.setup("UP RIGHT", ofVec2f(ofGetWidth(), 0), ofVec2f(0, 0), ofVec2f(ofGetWidth(), ofGetHeight())));
    projectionControls.add(DRProjectionslider.setup("DOWN RIGHT", ofVec2f(ofGetWidth(), ofGetHeight()), ofVec2f(0,0), ofVec2f(ofGetWidth(), ofGetHeight())));
    projectionControls.add(DLProjectionslider.setup("DOWN LEFT", ofVec2f(0, ofGetHeight()), ofVec2f(0, 0), ofVec2f(ofGetWidth(), ofGetHeight())));
    projectionControls.add(btnHideVideoControls.setup("Hide Video Controls", false));
    projectionControls.add(DimProjectionSlider.setup("Projection Dim", 0, 0, 100));
    
    ofVec2f vid = ct->getVideoDimensions();
    videoControls.setup();
    videoControls.setName("Video Input Coords");
    videoControls.setPosition(projectionControls.getPosition().x + projectionControls.getWidth() +10, projectionControls.getPosition().y);
    videoControls.add(ULVideoslider.setup("UP LEFT", ofVec2f(0, 0), ofVec2f(0, 0), vid));
    videoControls.add(URVideoslider.setup("UP RIGHT", ofVec2f(vid.x, 0), ofVec2f(0, 0), vid));
    videoControls.add(DRVideoslider.setup("DOWN RIGHT", ofVec2f(vid.x, vid.y), ofVec2f(0,0), vid));
    videoControls.add(DLVideoslider.setup("DOWN LEFT", ofVec2f(0, vid.y), ofVec2f(0, 0), vid));
    
}

void AppControls::update(){
    vector<ofPoint> projectionBoundsPrev = projectionBounds;
    vector<ofPoint> videoBoundsPrev = videoBounds;
    
    projectionBounds[0].x = ULProjectionslider->x;
    projectionBounds[0].y = ULProjectionslider->y;
    projectionBounds[1].x = URProjectionslider->x;
    projectionBounds[1].y = URProjectionslider->y;
    projectionBounds[2].x = DRProjectionslider->x;
    projectionBounds[2].y = DRProjectionslider->y;
    projectionBounds[3].x = DLProjectionslider->x;
    projectionBounds[3].y = DLProjectionslider->y;
    
    videoBounds[0].x = ULVideoslider->x;
    videoBounds[0].y = ULVideoslider->y;
    videoBounds[1].x = URVideoslider->x;
    videoBounds[1].y = URVideoslider->y;
    videoBounds[2].x = DRVideoslider->x;
    videoBounds[2].y = DRVideoslider->y;
    videoBounds[3].x = DLVideoslider->x;
    videoBounds[3].y = DLVideoslider->y;
    
    if (projectionBoundsPrev != projectionBounds) {
        ofNotifyEvent(NEW_PROJECTIONBOUNDS);
    }
    if (videoBoundsPrev != videoBounds) {
        ofNotifyEvent(NEW_VIDEOBOUNDS);
    }
}

void AppControls::setMaximums(int w, int h){
}

void AppControls::DimProjectionSliderHandler(int &dim){
    projectionDim = dim/100.0f;
}

void AppControls::draw(){
    projectionControls.draw();
    if (!btnHideVideoControls.getParameter().cast<bool>()) {
        videoControls.draw();
        ct->rgb.draw(videoControls.getPosition().x, videoControls.getPosition().y + videoControls.getHeight() + 10);
        ofSetColor(255, 100, 100, 70);
        ofSetLineWidth(3);
        ofSetPolyMode(OF_POLY_WINDING_NONZERO);
        ofBeginShape();
        for (int i = 0; i < videoBounds.size(); i++) {
            ofVertex(videoControls.getPosition().x + videoBounds[i].x, videoControls.getPosition().y + videoControls.getHeight() + 10 + videoBounds[i].y);
        }
        ofEndShape();
        ofSetColor(100, 255, 100);
        for (int i = 0; i < videoBounds.size(); i++) {
            ofCircle(videoControls.getPosition().x + videoBounds[i].x, videoControls.getPosition().y + videoControls.getHeight() + 10 + videoBounds[i].y, 3);
        }
    }
    
}