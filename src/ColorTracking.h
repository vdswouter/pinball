//
//  ColorTracking.h
//  _EXD_ProjectionPinball
//
//  Created by Wouter Vandersyppe on 14/02/14.
//
//

#ifndef _OF_VideoTracking
#define _OF_VideoTracking

#include "ofMain.h"
#include "ofxOpenCv.h"

class ColorTracking {
    
public:
    void setup();
    void update();
    void draw();
    void setColor(int x,int y);
    
    ofPoint BallPosition;
    
    ofEvent<void> NEW_POSITION;
    
    bool PickColor = false;
    int tolerance = 5;
    int minArea = 500;
    int maxArea = 10000;
    
    ofVec2f getVideoDimensions();
    ofxCvColorImage rgb;

private:
    ofVideoGrabber video;
    ofxCvColorImage hsb;
    ofxCvGrayscaleImage hue;
    ofxCvGrayscaleImage sat;
    ofxCvGrayscaleImage bri;
    ofxCvGrayscaleImage filtered;
    ofxCvContourFinder contours;
    
    int w = 640;
    int h = 480;
    int drawW = 320;
    int drawH = 240;
    int ofsetX = 230;
    int ofsetY = 10;
    int findHue = 0;
    ofColor findHueColor;
    
    
};

#endif
