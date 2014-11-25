//
//  musicEntity.h
//  CCLab_Final_MusicalComets
//
//  Created by Ben Miller on 11/17/14.
//
//

#pragma once
#include "ofMain.h"
//#include "ofApp.h"
#include "sound.h"

class MusicEntity {
    
public:
    MusicEntity();
    MusicEntity(Sound s);
//    MusicEntity(ofApp app);
//    MusicEntity(Sound _core);
    ofPoint pos;
//    Sound core;
    float velocity;
    float angle;
    float rotation;
    void update();
    void render();
    
//    AUDIO
    void audioOut(float * input, int bufferSize, int nChannels);
    ofSoundStream soundStream;
    
    float 	pan;
    int		sampleRate;
    bool 	bNoise;
    float 	volume;
    
    vector <float> lAudio;
    vector <float> rAudio;
    
    //------------------- for the simple sine wave synthesis
    float 	targetFrequency;
    float 	phase;
    float 	phaseAdder;
    float 	phaseAdderTarget;

};

