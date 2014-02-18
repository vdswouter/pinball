#pragma once

#include "ofMain.h"

class Playfield {
    
    public:
        Playfield(int w, int h);
        void update();
        void draw();
        void conquer(float points);
        bool isDefeated();
        bool isConquered();
        float conquerspeed;
    
    private:
        float _conquered;
        int width;
        int height;
};

