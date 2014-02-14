//
//  AppStats.cpp
//  _EXD_ProjectionPinball
//
//  Created by Wouter Vandersyppe on 11/02/14.
//
//

#include "AppStats.h"

void AppStats::setup(ColorTracking *colorTrackingClass){
    ct = colorTrackingClass; 
    
    FPSui.setup();
    FPSui.setName("Framerate");
    FPSui.add(fpsslider.setup("FPS", ofGetFrameRate(), 0, 60));
    fpsslider.setSize(100, fpsslider.getHeight());
    FPSui.setSize(100, FPSui.getHeight());

    fpshistory.reserve(100);
    for (int i = 0; i < 100; i++) {
        fpshistory.push_back(0);
    }
    toleranceSlider.addListener(this, &AppStats::setTolerance);
    minAreaSlider.addListener(this, &AppStats::setTolerance);
    maxAreaSlider.addListener(this, &AppStats::setTolerance);
    btnSetColor.addListener(this, &AppStats::setColorHandler);
    
    videoDataPanel.setup();
    videoDataPanel.add(toleranceSlider.setup("ColorTolerance", ct->tolerance, 0, 30));
    videoDataPanel.add(minAreaSlider.setup("Minimum ball Area", 500, 0, 5000));
    videoDataPanel.add(maxAreaSlider.setup("Maximum ball Area", 10000, 0, 20000));
    videoDataPanel.add(btnSetColor.setup("Set The Color"));
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
    videoDataPanel.draw();
    if (!FPSui.minimized) {
        ofSetColor(0, 200);
        ofRect(FPSui.getPosition().x, FPSui.getPosition().y + FPSui.getHeight(), 100, 60);
        ofSetColor(255);
        for (int i = 0; i < fpshistory.size(); i++) {
            ofEllipse(FPSui.getPosition().x+i, FPSui.getPosition().y + FPSui.getHeight() + (60-fpshistory[i]), 2, 2);
        }
    }
}

void AppStats::setTolerance(int & val){
    ct->tolerance = toleranceSlider.value;
    ct->minArea = minAreaSlider.value;
    ct->maxArea = maxAreaSlider.value;
}

void AppStats::setColorHandler(){
    ct->PickColor = true;
}