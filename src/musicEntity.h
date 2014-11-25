//
//  musicEntity.h
//  SingingComets
//
//  Created by Ben Miller on 11/17/14.
//
//

#pragma once
#include "ofMain.h"
#include "ofxMaxim.h"

class MusicEntity {
    
public:
    MusicEntity();
    ofPoint pos;
    float
        velocity,
        angle,
        rotation;
    ofxMaxiOsc voice;
    
    void update();
    void render();
    double returnVoice();

};

