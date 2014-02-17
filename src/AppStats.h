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
#include "ColorTracking.h"

class AppStats {
    
public:
    
    void update();
    void draw();
    void setup(ColorTracking *colorTrackingClass);

private:
    ColorTracking *ct;
    
    ofxGuiGroup FPSui;
    ofxFloatSlider fpsslider;
    vector<float> fpshistory;
    
    ofxGuiGroup videoDataPanel;
    ofxIntSlider toleranceSlider;
    ofxIntSlider minAreaSlider;
    ofxIntSlider maxAreaSlider;
    ofxIntSlider kinectAngleSlider;
    ofxButton btnSetColor;
    
    void setTolerance(int & val);
    void setColorHandler();
    void setKinectAngle(int & kinect);
};

#endif
