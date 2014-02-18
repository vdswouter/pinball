//
//  GameControls.cpp
//  _EXD_ProjectionPinball
//
//  Created by Wouter Vandersyppe on 13/02/14.
//
//

#include "GameControls.h"

void GameControls::setup(int w, int h){
    for (int i = 0; i < 6; i++) {
        holePositions.push_back(ofPoint(0,0));
    }
    
    holesControls.setup();
    holesControls.setName("Holes Positions");
    holesControls.add(hole1slider.setup("Hole 1", ofVec2f(50, 50), ofVec2f(0, 0), ofVec2f(w, h)));
    holesControls.add(hole2slider.setup("Hole 2", ofVec2f(100, 100), ofVec2f(0, 0), ofVec2f(w, h)));
    holesControls.add(hole3slider.setup("Hole 3", ofVec2f(150, 150), ofVec2f(0, 0), ofVec2f(w, h)));
    holesControls.add(hole4slider.setup("Hole 4", ofVec2f(200, 200), ofVec2f(0,0), ofVec2f(w, h)));
    holesControls.add(hole5slider.setup("Hole 5", ofVec2f(250, 250), ofVec2f(0,0), ofVec2f(w, h)));
    holesControls.add(hole6slider.setup("Hole 6", ofVec2f(300, 300), ofVec2f(0,0), ofVec2f(w, h)));
    holesControls.add(holeRadiusSlider.setup("Radius", holeRadius, 0, 200));
    holesControls.add(speedSlider.setup("speed", speed, 0, 10));

}

void GameControls::update(){
    holePositions[0].x = hole1slider->x;
    holePositions[0].y = hole1slider->y;
    holePositions[1].x = hole2slider->x;
    holePositions[1].y = hole2slider->y;
    holePositions[2].x = hole3slider->x;
    holePositions[2].y = hole3slider->y;
    holePositions[3].x = hole4slider->x;
    holePositions[3].y = hole4slider->y;
    holePositions[4].x = hole5slider->x;
    holePositions[4].y = hole5slider->y;
    holePositions[5].x = hole6slider->x;
    holePositions[5].y = hole6slider->y;
    holeRadius = holeRadiusSlider.value;
    speed = speedSlider.value;
    
}

void GameControls::draw(){
    holesControls.draw();
}