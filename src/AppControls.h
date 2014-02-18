//
//  controls.h
//  _EXD_ProjectionPinball
//
//  Created by Wouter Vandersyppe on 11/02/14.
//
//
#ifndef _OF_CONTROL
#define _OF_CONTROL

#include "ofMain.h"
#include "ofxGui.h"
#include "ColorTracking.h"

class AppControls {
    
public:
    void setup(ColorTracking * colorTracking);
    void update();
    void draw();
    void setMaximums(int w, int h);
    
    vector<ofPoint> videoBounds;
    vector<ofPoint> projectionBounds;
    float projectionDim = 0;
    
    ofEvent<void> NEW_PROJECTIONBOUNDS;
    ofEvent<void> NEW_VIDEOBOUNDS;

    
private:
    ofxPanel projectionControls;
    ofxVec2Slider ULProjectionslider;
    ofxVec2Slider DLProjectionslider;
    ofxVec2Slider URProjectionslider;
    ofxVec2Slider DRProjectionslider;
    ofxToggle btnHideVideoControls;
    ofxIntSlider DimProjectionSlider;
    void DimProjectionSliderHandler(int & dim);
    
    ofxPanel videoControls;
    ofxVec2Slider ULVideoslider;
    ofxVec2Slider DLVideoslider;
    ofxVec2Slider URVideoslider;
    ofxVec2Slider DRVideoslider;
    
    ofxPanel gameControls;
    vector<ofxVec2Slider> sliders;
    
    ColorTracking *ct;
};

#endif
