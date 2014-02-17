#pragma once

#include "ofMain.h"

class Playfield {
    
    public:
        Playfield();
        void update();
        void draw();
        void conquer(float points);
        bool isDefeated();
        bool isConquered();
    
    private:
        float _conquered;
};

