#include "pinBallApp.h"

//--------------------------------------------------------------
void pinBall::setup(){
    ofEnableSmoothing();
    ofSetFrameRate(60);
    ofSetBackgroundColor(0, 0, 0);
    ofSetCircleResolution(64);
    
    //set the screenspace
    ofPoint screenspacetopleft = ofPoint(fieldX,fieldY);
    ofPoint screenspacetopright = ofPoint(fieldX + fieldWidth,fieldY);
    ofPoint screenspacebottomright = ofPoint(fieldX + fieldWidth,fieldY + fieldHeight);
    ofPoint screenspacebottomleft = ofPoint(fieldX, fieldY + fieldHeight);
    
    screenspace.push_back(screenspacetopleft);
    screenspace.push_back(screenspacetopright);
    screenspace.push_back(screenspacebottomright);
    screenspace.push_back(screenspacebottomleft);
    //---
    
    videoWarper.setup();
    ofAddListener(appControls.NEW_VIDEOBOUNDS, this, &pinBall::newVideoBounds);
    frameBuffer.allocate();
    projectionWrapper.setup();
    ofAddListener(appControls.NEW_PROJECTIONBOUNDS, this, &pinBall::newProjectionBounds);
    
    colorTr.setup();
    ofAddListener(colorTr.NEW_POSITION, this, &pinBall::newPoint);

    stats.setup(& colorTr);
    appControls.setup(& colorTr);
    gameControls.setup(fieldWidth, fieldHeight);
    
//    testGraphics.setup();
    game.setup(fieldWidth, fieldHeight, & gameControls);
}

//--------------------------------------------------------------
void pinBall::update(){
    stats.update();
    appControls.update();
    gameControls.update();
    
    colorTr.update();
    
//    testGraphics.update();
    game.update();
}

//--------------------------------------------------------------
void pinBall::draw(){
    ofSetColor(0);
    ofRect(0, 0, ofGetWidth(), ofGetHeight());
    ofSetColor(255);
    
    frameBuffer.begin();
    {
        ofClear(255, 255, 255,0);
        ofSetColor(100, 255, 100, 100);
        ofRect(fieldX, fieldY, fieldWidth, fieldHeight);
        ofSetColor(255, 0, 0);
        ofCircle(colorTr.BallPositionMapped.x, colorTr.BallPositionMapped.y, 8);
//        testGraphics.draw();
        game.draw();
        ofSetColor(255);
    }
    frameBuffer.end();
    
    glPushMatrix();
    glMultMatrixf(projectionMatrix.getPtr() );
    {
        frameBuffer.draw(0, 0);
    }
    glPopMatrix();

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
        ofRect(20, ofGetHeight() - 100, 500, 90);
        ofSetColor(255);
        ofDrawBitmapString("Press V to show/hide Video Controls\nPress M to show/hide Mapping Controls\nPress G to show Game Controls\nPress I to show/hide this window \nPress F to toggle fullscreen mode \nPress S to start the game", 25, ofGetHeight()-85);
    }

}
void pinBall::newProjectionBounds(){
    ofLogNotice() << "new ProjectionBounds " << ofGetFrameNum();
    projectionWrapper.setSourcePoints(screenspace);
    projectionWrapper.setTargetPoints(appControls.projectionBounds);
    projectionWrapper.update();
    
    projectionMatrix = projectionWrapper.getMatrix();
    //    cout<<videoMatrix<<endl;
}

void pinBall::newVideoBounds(){
    ofLogNotice() << "new videobounds " << ofGetFrameNum();
    videoWarper.setSourcePoints(appControls.videoBounds);
    videoWarper.setTargetPoints(screenspace);
    videoWarper.update();
    
    videoMatrix = videoWarper.getMatrix();
//    cout<<videoMatrix<<endl;
}

void pinBall::newPoint(){
    colorTr.BallPositionMapped = videoMatrix.preMult(ofVec3f(colorTr.BallPosition));
    //SEND THE DATA TO THE DRAW CLASS
//    testGraphics.setPosition(colorTr.BallPositionMapped.x, colorTr.BallPositionMapped.y);
    game.setPosition(colorTr.BallPositionMapped.x, colorTr.BallPositionMapped.y);
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
        case 's':
            //TODO: RESTART THE GAME!
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
