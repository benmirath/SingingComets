//
//  playerShot.h
//  CCLab_Final_MusicalComets
//
//  Created by Ben Miller on 11/17/14.
//
//

#pragma once
#include "ofMain.h"
//#include "ofApp.h"
#include "musicEntity.h"

class PlayerShot : public MusicEntity {
//class PlayerShot {

    public:
        PlayerShot (float X, float Y, float A, float V, float R);
    ~PlayerShot ();
        float lifespan;
        float runtime;
        void dissipate(vector<PlayerShot>& shots, int index);
        void render ();
        void accelerate ();    
};