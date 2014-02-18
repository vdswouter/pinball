//
//  GameControls.h
//  _EXD_ProjectionPinball
//
//  Created by Wouter Vandersyppe on 13/02/14.
//
//
#ifndef _OF_GameCONTROL
#define _OF_GameCONTROL

#include "ofMain.h"
#include "ofxGui.h"

class GameControls {
    
public:
    void setup(int w, int h);
    void update();
    void draw();
    
    vector<ofPoint> holePositions;
    int holeRadius = 50;
    
private:
    ofxPanel holesControls;
    ofxVec2Slider hole1slider;
    ofxVec2Slider hole2slider;
    ofxVec2Slider hole3slider;
    ofxVec2Slider hole4slider;
    ofxVec2Slider hole5slider;
    ofxVec2Slider hole6slider;
    ofxIntSlider holeRadiusSlider;
    
};

#endif
