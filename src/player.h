//
//  player.h
//  CCLab_Final_MusicalComets
//
//  Created by Ben Miller on 11/17/14.
//
//

#pragma once
#include "ofMain.h"
#include "musicEntity.h"
#include "playerShot.h"

class Player : public MusicEntity {
//class Player {

public:
    Player ();
    Player (float x, float y);
    float shotTimer;
    float shotRate;
    float maxSpeed;
    bool alive;
    void shoot (vector<PlayerShot>& SHOTS);
//    void shoot (ofApp app);
    void checkBoost ();
    void update ();
    void render ();
    void accelerate ();
    
};