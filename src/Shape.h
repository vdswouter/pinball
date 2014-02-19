#pragma once

#include "ofMain.h"
#include "PositionedObject.h"

class Shape : public PositionedObject {
    
    public:
        explicit Shape(int x, int y);
        void draw();
        int type;
        int radius;
        int r;
        int g;
        int b;
};

