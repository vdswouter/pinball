#include "pinballGame.h"

void pinballGame::setup() {
    ofSetFrameRate(60);
    ofSetCircleResolution(64);
    
    _playfield = new Playfield();
    
    _ball = new Ball(ofGetMouseX(), ofGetMouseY());
    
    _holes.push_back(new Hole(280, 680));
    _holes.push_back(new Hole(480, 70));
    _holes.push_back(new Hole(720, 130));
    _holes.push_back(new Hole(860, 380));
}

//--------------------------------------------------------------
void pinballGame::update() {
    _playfield->update();

    if (!_playfield->isDefeated()) {
        for (int i = 0; i < _holes.size(); i++) {
            _holes[i]->update();
            
            if (_holes[i]->isActive() && _ball->detectCircularHit(_holes[i])) {
                _playfield->conquer(0.1);
                _holes[i]->setActive(false, 400);
                _ball->resetTrack();
            }
        }
    }
}

//--------------------------------------------------------------
void pinballGame::draw() {
    if (_playfield->isDefeated()) {
        ofSetColor(125, 25, 125);
        ofRect(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
    } else {
        _playfield->draw();
        
        for (int i = 0; i < _holes.size(); i++) {
            _holes[i]->draw();
        }
        
        _ball->draw();
    }
}

//--------------------------------------------------------------
void pinballGame::keyPressed(int key) {
    
}

//--------------------------------------------------------------
void pinballGame::keyReleased(int key) {
    
}

//--------------------------------------------------------------
void pinballGame::mouseMoved(int x, int y ) {
    _ball->setPosition(x, y);
}

//--------------------------------------------------------------
void pinballGame::mouseDragged(int x, int y, int button) {
    
}

//--------------------------------------------------------------
void pinballGame::mousePressed(int x, int y, int button) {
    
}

//--------------------------------------------------------------
void pinballGame::mouseReleased(int x, int y, int button) {
    
}

//--------------------------------------------------------------
void pinballGame::windowResized(int w, int h) {
    
}

//--------------------------------------------------------------
void pinballGame::gotMessage(ofMessage msg) {
    
}

//--------------------------------------------------------------
void pinballGame::dragEvent(ofDragInfo dragInfo) {
    
}
