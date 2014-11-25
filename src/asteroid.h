//
//  asteroid.h
//  CCLab_Final_MusicalComets
//
//  Created by Ben Miller on 11/17/14.
//
//

#pragma once
#include "ofMain.h"
#include "musicEntity.h"
#include "player.h"
#include "playerShot.h"

class Asteroid : public MusicEntity {
//class Asteroid {

public:
    float w;
    int type;
    Asteroid (float X, float Y, float V, int T, float A, float R);
    ~Asteroid ();
    void shotCollision (vector<Asteroid>& asteroids, vector<PlayerShot>& shots, int asteroidIndex, int shotIndex);
    void playerCollision (Player& player, Asteroid& asteroid);
    void render();
    void acceleration();
};