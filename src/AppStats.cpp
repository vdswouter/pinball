//
//  AppStats.cpp
//  _EXD_ProjectionPinball
//
//  Created by Wouter Vandersyppe on 11/02/14.
//
//

#include "AppStats.h"

void AppStats::setup(){
    FPSui.setup();
    FPSui.setName("Framerate");
    FPSui.add(fpsslider.setup("FPS", ofGetFrameRate(), 0, 60));
    fpsslider.setSize(100, fpsslider.getHeight());
    FPSui.setSize(100, FPSui.getHeight());

    fpshistory.reserve(100);
    for (int i = 0; i < 100; i++) {
        fpshistory.push_back(0);
    }
    KinectAngleSlider.addListener(this, &AppStats::setKinectAngle);
    videoThresholdSlider.addListener(this, &AppStats::setVideoThreshold);
    
    kinectDataPanel.setup();
    kinectDataPanel.add(KinectAngleSlider.setup("Kinect Angle", kinectAngle, -30, 30));
    kinectDataPanel.add(videoThresholdSlider.setup("threshold", videoTreshold, 0, 200));
}

void AppStats::update(){
    for (int i = 0; i < 99; i++) {
        fpshistory[i] = fpshistory[i+1];
    }
    fpsslider.operator=(round(ofGetFrameRate()));
    fpshistory[99] = ofGetFrameRate();
    FPSui.setPosition(ofGetWidth()-110, 10);
}

void AppStats::draw(){
    FPSui.draw();
    kinectDataPanel.draw();
    if (!FPSui.minimized) {
        ofSetColor(0, 200);
        ofRect(FPSui.getPosition().x, FPSui.getPosition().y + FPSui.getHeight(), 100, 60);
        ofSetColor(255);
        for (int i = 0; i < fpshistory.size(); i++) {
            ofEllipse(FPSui.getPosition().x+i, FPSui.getPosition().y + FPSui.getHeight() + (60-fpshistory[i]), 2, 2);
        }
    }
}

void AppStats::setKinectAngle(int &angle){
    kinectAngle = angle;
}
void AppStats::setVideoThreshold(int &threshold){
    
}