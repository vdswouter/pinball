#pragma once

#include "ofMain.h"
#include "PositionedCircle.h"
#include "Shape.h"

class Ball : public PositionedCircle {
    
    public:
        explicit Ball(int x, int y, int radius = 12);
        void update();
        void draw();
        void setPosition(int x, int y);
        void resetTrack();

    private:
        vector<Shape> _track;
    
};

