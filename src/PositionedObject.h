#pragma once

#include "ofMain.h"

class PositionedObject {
    
    public:
        explicit PositionedObject(int x, int y, int radius = 12);
        void setPosition(int x, int y);
        bool detectHit(PositionedObject *object);
        int x();
        int y();
    
    protected:
        int _x;
        int _y;
};

