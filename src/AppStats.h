//
//  AppStats.h
//  _EXD_ProjectionPinball
//
//  Created by Wouter Vandersyppe on 11/02/14.
//
//
#ifndef _OF_STATS
#define _OF_STATS

#include "ofMain.h"
#include "ofxGui.h"

class AppStats {
    
public:
    
    void update();
    void draw();
    void setup();
    
    int kinectAngle = 0;
    int videoTreshold = 80;

private:
    ofxGuiGroup FPSui;
    ofxFloatSlider fpsslider;
    vector<float> fpshistory;
    
    ofxGuiGroup kinectDataPanel;
    ofxIntSlider KinectAngleSlider;
    ofxIntSlider videoThresholdSlider;
    
    void setKinectAngle(int & angle);
    void setVideoThreshold(int & threshold);
    
};

#endif
