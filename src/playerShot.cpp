//
//  playerShot.cpp
//  CCLab_Final_MusicalComets
//
//  Created by Ben Miller on 11/17/14.
//
//

#include "musicEntity.h"
#include "playerShot.h"

//#include "ofApp.h"

PlayerShot::PlayerShot (float X, float Y, float A, float V, float R) {
    MusicEntity::MusicEntity();
    pos.x = X;
    pos.y = Y;
    angle = A;
    velocity = V;
    rotation = R;
    
    lifespan = 40;
    runtime = 0;
}
PlayerShot::~PlayerShot() {
}
void PlayerShot::render() {
    MusicEntity::render();
    ofPushMatrix ();
    ofTranslate (pos.x, pos.y);
    ofFill();
    ofSetColor(200, 255, 255);
    
    ofEllipse (0, 0, 3, 3);
    ofNoFill();
    ofPopMatrix ();
}
void PlayerShot::dissipate(vector<PlayerShot>& shots, int index) {
    runtime++;
    if (runtime > lifespan) {
        shots.erase(shots.begin() + index);
    }
}
