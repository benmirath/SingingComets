//
//  musicEntity.cpp
//  CCLab_Final_MusicalComets
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
    if (pos.x < 0) pos.x = ofGetWidth();
    if (pos.x > ofGetWidth()) pos.x = 0;
    if (pos.y < 0) pos.y = ofGetHeight();
    if (pos.y > ofGetHeight()) pos.y = 0;
    
    pos.x += cos (angle) * velocity;
    pos.y += sin (angle) * velocity;
    
    //determine placement
//    int tone = ofMap(pos.y, 0, ofGetHeight(), 60, 72);
    
    
}
void MusicEntity::render(){

}

void MusicEntity::audioOut(float * output, int bufferSize, int nChannels){
    //pan = 0.5f;
    float leftScale = 1 - pan;
    float rightScale = pan;
    
    // sin (n) seems to have trouble when n is very large, so we
    // keep phase in the range of 0-TWO_PI like this:
    while (phase > TWO_PI){
        phase -= TWO_PI;
    }
    
    if ( bNoise == true){
        // ---------------------- noise --------------
        for (int i = 0; i < bufferSize; i++){
            lAudio[i] = output[i*nChannels    ] = ofRandom(0, 1) * volume * leftScale;
            rAudio[i] = output[i*nChannels + 1] = ofRandom(0, 1) * volume * rightScale;
        }
    } else {
        phaseAdder = 0.95f * phaseAdder + 0.05f * phaseAdderTarget;
        for (int i = 0; i < bufferSize; i++){
            phase += phaseAdder;
            float sample = sin(phase);
            lAudio[i] = output[i*nChannels    ] = sample * volume * leftScale;
            rAudio[i] = output[i*nChannels + 1] = sample * volume * rightScale;
        }
    }
    
}