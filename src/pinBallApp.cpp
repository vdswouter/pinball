#include "pinBallApp.h"

//--------------------------------------------------------------
void pinBall::setup(){
    ofEnableSmoothing();
    ofSetBackgroundColor(33);
    ofSetFrameRate(60);
    
    colorTr.setup();

    stats.setup(& colorTr);
    appControls.setup();
    gameControls.setup();
    
}

//--------------------------------------------------------------
void pinBall::update(){
    stats.update();
    appControls.update();
    gameControls.update();
    
    colorTr.update();
}

//--------------------------------------------------------------
void pinBall::draw(){
    if (showStats) {
        stats.draw();
        colorTr.draw();
    }
    if (showMapControls) {
        appControls.draw();
    }
    if (showGameControls) {
        gameControls.draw();
    }
    if (showInfo) {
        ofSetColor(0);
        ofRect(20, ofGetHeight() - 100, 500, 80);
        ofSetColor(255);
        ofDrawBitmapString("Press V to show/hide Video Controls\nPress M to show/hide Mapping Controls\nPress G to show Game Controls\nPress I to show/hide this window", 25, ofGetHeight()-85);
    }
}

//--------------------------------------------------------------
void pinBall::keyPressed(int key){
    switch (key) {
        case 'v':
            showStats = !showStats;
            showMapControls = false;
            showGameControls = false;
            break;
        case 'm':
            showStats = false;
            showGameControls = false;
            showMapControls = !showMapControls;
            break;
        case 'g':
            showGameControls = !showGameControls;
            showMapControls = false;
            showStats = false;
            break;
        case 'i':
            showInfo = !showInfo;
            break;
        case 'f':
            ofSetFullscreen(!ofGetWindowMode());
            break;
    }
}

//--------------------------------------------------------------
void pinBall::keyReleased(int key){

}

//--------------------------------------------------------------
void pinBall::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void pinBall::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void pinBall::mousePressed(int x, int y, int button){
    if (colorTr.PickColor) {
        colorTr.setColor(x, y);
    }
}

//--------------------------------------------------------------
void pinBall::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void pinBall::windowResized(int w, int h){
    appControls.setMaximums(w, h);
    
}

//--------------------------------------------------------------
void pinBall::gotMessage(ofMessage msg){
    ofLogWarning() << "Got Message: " << msg.message;
}

//--------------------------------------------------------------
void pinBall::dragEvent(ofDragInfo dragInfo){ 

}
