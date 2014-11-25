#pragma once

#include "ofMain.h"
#include "ofxMaxim.h"
#include "musicEntity.h"
#include "player.h"
#include "asteroid.h"
#include "playerShot.h"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    void restart ();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    void audioRequested 	(float * input, int bufferSize, int nChannels); /* output method */
    void audioReceived 	(float * input, int bufferSize, int nChannels); /* input method */
    
    //GAMEPLAY
    bool keysPressed[400];
    int
        asteroidCount,
        asteroidCountMin,
        asteroidCountMax;

    Player ship;
    vector<PlayerShot> shots;
    vector<Asteroid> asteroids;

    //AUDIO
    int	initialBufferSize; /* buffer size */
    int	sampleRate;
    double
        wave,
        sample,
        outputs[2];
    vector<double> myOutputs;
    
    ofxMaxiMix mymix;
    ofxMaxiOsc sine1;
    ofxMaxiSample
        laser,
        explosion,
        voice1,
        voice2,
        voice3;
    
};