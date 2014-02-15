//
//  ColorTracking.cpp
//  _EXD_ProjectionPinball
//
//  Created by Wouter Vandersyppe on 14/02/14.
//
//

#include "ColorTracking.h"

void ColorTracking::setup(){
    video.initGrabber(w, h, true);
    
    rgb.allocate(w, h);
    hsb.allocate(w, h);
    hue.allocate(w, h);
    sat.allocate(w, h);
    bri.allocate(w, h);
    filtered.allocate(w, h);
    
    findHueColor = ofColor::fromHsb(findHue, 255, 255);
}

void ColorTracking::update(){
    video.update();
    
    if (video.isFrameNew()) {
        rgb.setFromPixels(video.getPixels(),w,h);
        rgb.mirror(false, true);
        hsb = rgb;
        hsb.convertRgbToHsv();
        hsb.convertToGrayscalePlanarImages(hue, sat, bri);
        for (int i=0; i < w*h; i++) {
            filtered.getPixels()[i] = ofInRange(hue.getPixels()[i], findHue-tolerance, findHue+tolerance) ? 255 : 0;
        }
        filtered.flagImageChanged();
        
        contours.findContours(filtered, minArea, maxArea, 1, false);
        if (contours.nBlobs == 1) {
            BallPosition = contours.blobs[0].centroid;
            ofNotifyEvent(NEW_POSITION);
        }
    }

}

void ColorTracking::draw(){
    if (PickColor) {
        rgb.draw(ofsetX,ofsetY, w, h);
        ofDrawBitmapString("Click the image to pick your color", ofsetX + 10, ofsetY + 10);

    }else{
        rgb.draw(ofsetX,ofsetY, drawW, drawH);
        contours.draw(ofsetX, ofsetY, drawW, drawH);
        ofSetColor(255, 100, 100);
        ofCircle((BallPosition.x/w)*drawW+ofsetX, (BallPosition.y/h)*drawH+ofsetY, 2);
        ofSetColor(255);
        ofDrawBitmapString("RGB", ofsetX + 10, ofsetY + 10);
        
        hsb.draw(ofsetX + drawW,ofsetY, drawW, drawH);
        ofDrawBitmapString("HSB", ofsetX + drawW + 10, ofsetY + 10);
        
        ofSetColor(findHueColor);
        ofRect(ofsetX + 2*drawW, ofsetY, drawW, drawH);
        ofSetColor(255);
        ofDrawBitmapString("The Selected Color", ofsetX + 2*drawW + 10, ofsetY + 10);

        hue.draw(ofsetX,ofsetY+drawH, drawW, drawH);
        ofDrawBitmapString("Hue", ofsetX + 10, ofsetY+drawH + 10);
        
        sat.draw(ofsetX + drawW,ofsetY+drawH, drawW, drawH);
        ofDrawBitmapString("Saturation", ofsetX + drawW + 10, ofsetY+drawH + 10);
        
        bri.draw(ofsetX+ 2* drawW,ofsetY+drawH, drawW, drawH);
        ofDrawBitmapString("Brightness", ofsetX+ 2* drawW + 10, ofsetY+drawH + 10);
        
        filtered.draw(ofsetX,ofsetY + 2*drawH, drawW, drawH);
        ofDrawBitmapString("Filtered", ofsetX + drawW + 10, ofsetY + 2*drawH + 10);
        
        contours.draw(ofsetX,ofsetY + 2*drawH, drawW, drawH);

    }
}

void ColorTracking::setColor(int x, int y){
    if (ofsetX < x && x < ofsetX+w && ofsetY < y && y < ofsetY+h) {
        int mx = x-ofsetX;
        int my = y-ofsetY;
        ofLogNotice() << "x: " << mx << " y: " << my;
        findHue = hue.getPixels()[my*w+mx];
        findHueColor.setHue(findHue);
        findHueColor.setSaturation(sat.getPixels()[my*w+mx]);
        findHueColor.setBrightness(bri.getPixels()[my*w+mx]);
        PickColor = false;
    }
}

ofVec2f ColorTracking::getVideoDimensions(){
    return ofVec2f(w, h);
}