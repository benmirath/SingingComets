//
//  musicEntity.cpp
//  SingingComets
//
//  Created by Ben Miller on 11/17/14.
//
//
#include "ofMain.h"
#include "ofApp.h"
#include "musicEntity.h"


MusicEntity::MusicEntity() {
    pos.x = ofGetWidth() / 2;
    pos.y = ofGetHeight() / 2;
    velocity = 0;
    angle = 0;
    rotation = 0;
}


void MusicEntity::update() {
    if (pos.x < 1) pos.x = ofGetWidth();
    if (pos.x > ofGetWidth()) pos.x = 1;
    if (pos.y < 1) pos.y = ofGetHeight();
    if (pos.y > ofGetHeight()) pos.y = 1;
    
    pos.x += cos (angle) * velocity;
    pos.y += sin (angle) * velocity;    
}
void MusicEntity::render(){

}
double MusicEntity::returnVoice() {
    return voice.sinebuf(abs(pos.y));
}