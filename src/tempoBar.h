//
//  tempoBar.h
//  SingingComets
//
//  Created by Ben Miller on 11/25/14.
//
//

#pragma once
#include "ofMain.h"
#include "musicEntity.h"

class TempoBar {

public:
    TempoBar();
    ofPoint pos;
    int w,h,speed;
    void update(),
        display();
    
};