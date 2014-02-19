#include "pinballGame.h"

void pinballGame::setup(int w, int h, GameControls *gc) {
    controls = gc;
    playFieldWidth = w;
    playFieldHeight = h;
    
    calibreBoldBig.loadFont("Calibre-Bold.ttf", 160);
    calibreBoldMedium.loadFont("Calibre-Bold.ttf", 100);
    calibreBoldSmall.loadFont("Calibre-Bold.ttf", 36);
    
    _playfield = new Playfield(playFieldWidth, playFieldHeight);
    
    _ball = new Ball(0, 0);
    
    _startTimestamp = ofGetElapsedTimef();
    
    for (int i = 0; i < controls->holePositions.size(); i++) {
        Hole *h = new Hole(controls->holePositions[i].x,controls->holePositions[i].y, controls->holeRadius);
        h->setActive(true,0);
        _holes.push_back(h);
    }
}

//--------------------------------------------------------------
void pinballGame::update() {
    _playfield->update();
    _playfield->conquerspeed = controls->speed;
    _ball->setRadius(controls->ballRadius);

    if (!_playfield->isDefeated()) {
        for (int i = 0; i < _holes.size(); i++) {
            _holes[i]->update(controls->holePositions[i].x,controls->holePositions[i].y, controls->holeRadius);
            
            if (_holes[i]->isActive() && _ball->detectCircularHit(_holes[i])) {
                _playfield->conquer(0.1);
                _holes[i]->setActive(false, 400);
                _ball->resetTrack();
            } else {
                float conqueredPx = playFieldHeight - playFieldHeight * _playfield->conquered();
                _holes[i]->setActive(_holes[i]->y() < conqueredPx);
            }
        }
    } else {
        if (_score == 0) {
            _score = ofGetElapsedTimef() - _startTimestamp;
        }
    }
}

//--------------------------------------------------------------
void pinballGame::draw() {
    if (_playfield->isDefeated()) {
        ofSetColor(252, 179, 52);
        ofRect(0, 0, playFieldWidth, playFieldHeight);
        
        ofSetColor(255, 255, 255);
        char score[3];
        sprintf(score, "%g", round(_score));
        float scoreW = calibreBoldBig.stringWidth(score);
        calibreBoldBig.drawString(score, playFieldWidth / 2 - scoreW / 2, 355);
        
        float tryW = calibreBoldSmall.stringWidth("NICE TRY!");
        calibreBoldSmall.drawString("NICE TRY!", playFieldWidth / 2 - tryW / 2, 480);
        
        float knqrW = calibreBoldMedium.stringWidth("KNQR");
        calibreBoldMedium.drawString("KNQR", playFieldWidth / 2 - knqrW / 2, 655);
    } else {
        _playfield->draw();
        
        for (int i = 0; i < _holes.size(); i++) {
            _holes[i]->draw();
        }
        _ball->draw();
    }
}

void pinballGame::setPosition(int x, int y ) {
    _ball->setPosition(x, y);
}

void pinballGame::reset() {
    _startTimestamp = ofGetElapsedTimef();
    _score = 0;
    _playfield->reset();
    _ball->resetTrack();
}