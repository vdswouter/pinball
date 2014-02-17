#pragma once

#include "ofMain.h"
#include "PositionedObject.h"

class PositionedCircle : public PositionedObject {
    
    public:
        explicit PositionedCircle(int x, int y, int radius = 12);
        void setRadius(int radius);
        int radius();
        bool detectCircularHit(PositionedCircle *object);
    
    protected:
        int _radius;
};

