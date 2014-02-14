//
//  GameControls.cpp
//  _EXD_ProjectionPinball
//
//  Created by Wouter Vandersyppe on 13/02/14.
//
//

#include "GameControls.h"

void GameControls::setup(){
    for (int i = 0; i < 6; i++) {
        holePositions.push_back(ofPoint(0,0));
    }
    
    holesControls.setup();
    holesControls.setName("Holes Positions");
    holesControls.add(hole1slider.setup("Hole 1", ofVec2f(0, 0), ofVec2f(0, 0), ofVec2f(ofGetWidth(), ofGetHeight())));
    holesControls.add(hole2slider.setup("Hole 2", ofVec2f(0, ofGetHeight()), ofVec2f(0, 0), ofVec2f(ofGetWidth(), ofGetHeight())));
    holesControls.add(hole3slider.setup("Hole 3", ofVec2f(ofGetWidth(), 0), ofVec2f(0, 0), ofVec2f(ofGetWidth(), ofGetHeight())));
    holesControls.add(hole4slider.setup("Hole 4", ofVec2f(ofGetWidth(), ofGetHeight()), ofVec2f(0,0), ofVec2f(ofGetWidth(), ofGetHeight())));
    holesControls.add(hole5slider.setup("Hole 5", ofVec2f(ofGetWidth(), ofGetHeight()), ofVec2f(0,0), ofVec2f(ofGetWidth(), ofGetHeight())));
    holesControls.add(hole6slider.setup("Hole 6", ofVec2f(ofGetWidth(), ofGetHeight()), ofVec2f(0,0), ofVec2f(ofGetWidth(), ofGetHeight())));
    holesControls.add(holeRadiusSlider.setup("Radius", 50, 0, 200));

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
    
}

void GameControls::draw(){
    holesControls.draw();
}