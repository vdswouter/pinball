#include "pinballGame.h"

void pinballGame::setup(int w, int h, GameControls *gc) {
    controls = gc;
    playFieldWidth = w;
    playFieldHeight = h;
    
    _playfield = new Playfield(playFieldWidth, playFieldHeight);
    
    _ball = new Ball(0, 0);
    
    for (int i = 0; i < controls->holePositions.size(); i++) {
        _holes.push_back(new Hole(controls->holePositions[i].x,controls->holePositions[i].y, controls->holeRadius));
    }
}

//--------------------------------------------------------------
void pinballGame::update() {
    _playfield->update();

    if (!_playfield->isDefeated()) {
        for (int i = 0; i < _holes.size(); i++) {
            _holes[i]->update(controls->holePositions[i].x,controls->holePositions[i].y);
            
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
        // YOU LOSE
        ofSetColor(125, 25, 125);
        ofRect(0, 0, playFieldWidth, playFieldHeight);
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
