#pragma once

#include "ofMain.h"
#include "PositionedObject.h"

class Shape : public PositionedObject {
    
    public:
        explicit Shape(int x, int y);
        void draw();
        void setup();
        int type;
        int radius;
        int r;
        int g;
        int b;
    
    void kaktNenShape(int x, int y, int radius);
};

