#pragma once

#include "ofMain.h"
#include "AppStats.h"
#include "AppControls.h"
#include "GameControls.h"
#include "ColorTracking.h"
#include "ofxQuadWarp.h"
#include "testGraphics.h"
#include "pinballGame.h"

class pinBall : public ofBaseApp{

public:
	void setup();
	void update();
	void draw();

    void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);
    
    bool showStats = false;
    bool showMapControls = false;
    bool showGameControls = false;
    bool showInfo = true;
    
private:
    vector<ofPoint> screenspace;
    int fieldWidth = 500;
    int fieldHeight = 1000;
    int fieldX = 100;
    int fieldY = 20;
    
    ColorTracking colorTr;
		
    ofxQuadWarp videoWarper;
    ofMatrix4x4 videoMatrix;
    
    ofxQuadWarp projectionWrapper;
    ofMatrix4x4 projectionMatrix;

    AppStats stats;
    AppControls appControls;
    GameControls gameControls;
    
    testGraphics testGraphics;
    pinballGame game;
    
    void newPoint();
    void newVideoBounds();
    void newProjectionBounds();
    
    ofFbo frameBuffer;
};
