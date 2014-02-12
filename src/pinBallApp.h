#pragma once

#include "ofMain.h"
#include "AppStats.h"
#include "AppControls.h"

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
    
private:
    AppStats stats;
    AppControls appControls;
		
};
