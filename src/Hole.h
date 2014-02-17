#pragma once

#include "ofMain.h"
#include "PositionedCircle.h"

class Hole : public PositionedCircle {
    
    public:
        explicit Hole(int x, int y, int radius = 22);
        void update();
        void draw();
        void setActive(bool isActive, int resetAfter = 0);
        bool isActive();
    
    private:
        bool _isActive;
        unsigned long _resetTimestamp;
        unsigned int _resetAfter;
};

