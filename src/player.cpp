//
//  player.cpp
//  CCLab_Final_MusicalComets
//
//  Created by Ben Miller on 11/17/14.
//
//

#include "ofMain.h"
#include "musicEntity.h"
#include "player.h"


Player::Player () {
    MusicEntity::MusicEntity();
    pos.x = ofGetWidth()/2;
    pos.y = ofGetHeight()/2;
    rotation = 0;
    shotRate = 5;
    shotTimer = 0;
    maxSpeed = 10;
    alive = true;

}
Player::Player (float x, float y) {
    MusicEntity::MusicEntity();
    pos.x = x;
    pos.y = y;
    rotation = 0;
    shotRate = 5;
    shotTimer = 0;
    maxSpeed = 10;
    alive = true;
}
void Player::shoot(vector<PlayerShot>& SHOTS) {
    if (shotTimer == 0) {
        shotTimer = shotRate;
        //    snd_shoot.play();
        //    snd_shoot.rewind();

        SHOTS.push_back(PlayerShot(pos.x, pos.y, rotation + PI/2, 10, rotation + PI/2));
        cout << "FIRE!" << endl;

    }
    
}

void Player::accelerate() {
    float xt = cos (angle) * velocity + cos (rotation + PI/2) * 0.25;
    float yt = sin (angle) * velocity + sin (rotation + PI/2) * 0.25;
    if (velocity <= maxSpeed) velocity = sqrt(pow(yt, 2)+pow(xt, 2));
    else velocity = maxSpeed - 0.1;
    angle = atan2(yt, xt);
}

void Player::update() {
    MusicEntity::update();
    if (shotTimer > 0) shotTimer--;
    else shotTimer = 0;
}

void Player::render() {
    ofSetColor(200, 255, 255, 180);
    MusicEntity::render();
    ofPushMatrix();
    ofTranslate(pos.x, pos.y);
    ofRotate(ofRadToDeg(rotation));
    ofNoFill();
    
    //setStroke equivalent
    
    ofTriangle(0, 12, 8, -8, -8, -8);
    ofPopMatrix();
}
