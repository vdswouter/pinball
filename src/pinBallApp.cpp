#include "pinBallApp.h"

//--------------------------------------------------------------
void pinBall::setup(){
    ofEnableSmoothing();
    ofSetBackgroundColor(33);
    ofSetFrameRate(60);
    
    stats.setup();
    appControls.setup();
}

//--------------------------------------------------------------
void pinBall::update(){
    stats.update();
    appControls.update();
}

//--------------------------------------------------------------
void pinBall::draw(){
    if (showStats) {
        stats.draw();
    }
    if (showMapControls) {
        appControls.draw();
    }
}

//--------------------------------------------------------------
void pinBall::keyPressed(int key){
    switch (key) {
        case 's':
            showStats = !showStats;
            break;
        case 'm':
            showMapControls = !showMapControls;
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

}

//--------------------------------------------------------------
void pinBall::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void pinBall::windowResized(int w, int h){

}

//--------------------------------------------------------------
void pinBall::gotMessage(ofMessage msg){
    ofLogWarning() << "Got Message: " << msg.message;
}

//--------------------------------------------------------------
void pinBall::dragEvent(ofDragInfo dragInfo){ 

}
