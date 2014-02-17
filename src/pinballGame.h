#pragma once

#include "ofMain.h"
#include "Playfield.h"
#include "Hole.h"
#include "Ball.h"
#include "GameControls.h"

class pinballGame {
    
    public:
        void setup(int w, int h, GameControls *gc);
        void update();
        void draw();
    
        void setPosition(int x, int y );

    private:
        GameControls *controls;
        int playFieldWidth;
        int playFieldHeight;
    
        Playfield *_playfield;
        Ball *_ball;
        vector<Hole *> _holes;
};
