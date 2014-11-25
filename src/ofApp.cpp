#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //VISUALS
    ofSetWindowShape(1000, 800);
    ofSetFrameRate(30);
    ofBackground(0);
    ofEnableAlphaBlending();
    ofSetBackgroundAuto(false);
    
    //GAMEPLAY
    asteroidCountMin = 3;
    asteroidCountMax = 7;
    ship = Player(ofGetWidth()/2, ofGetHeight()/2);
    shots = vector<PlayerShot>();
    asteroids = vector<Asteroid>();
    ofHideCursor();
    restart();
    
    sampleRate 			= 44100; /* Sampling Rate */
    initialBufferSize	= 512;	/* Buffer Size. you have to fill this buffer with sound*/
    
    laser.load(ofToDataPath("Laser.wav"));
    laser.getLength();
    laser.position = laser.length;
    explosion.load(ofToDataPath("Explosion.wav"));
    explosion.getLength();
    explosion.position = explosion.length;
    voice1.load(ofToDataPath("Voice.wav"));
    voice1.getLength();
    voice1.position = voice1.length;
    voice2.load(ofToDataPath("Voice2.wav"));
    voice2.getLength();
    voice2.position = voice2.length;
    voice3.load(ofToDataPath("Voice3.wav"));
    voice3.getLength();
    voice3.position = voice3.length;
    ofSoundStreamSetup(2,0,this, sampleRate, initialBufferSize, 4);/* Call this last ! */
}

//--------------------------------------------------------------
void ofApp::update(){
    if (keysPressed[357] == true) ship.accelerate();
    if (keysPressed[356] == true) ship.rotation -= .1;
    if (keysPressed[358] == true) ship.rotation += .1;
    if (keysPressed[32] == true && ship.shotTimer == 0) {
        ship.shoot(shots);
        laser.position = 0;
    }
    
    if (ship.alive) {
        ship.update();
    }
    for (int i = 0; i < shots.size(); i++){
        try {
            shots.at(i).update();
        }
        catch (const out_of_range) {
            continue;
        }
    }
    for (int i = 0; i < asteroids.size(); i++){
        try {
            asteroids.at(i).update();
            if (ship.alive) asteroids.at(i).playerCollision(ship, asteroids.at(i));
            for (int j = 0; j < shots.size(); j++) {
                if (asteroids.at(i).type == 0) {
                    asteroids.at(i).shotCollision (asteroids, shots, i, j, voice1.position);
                } else if (asteroids.at(i).type == 1) {
                    asteroids.at(i).shotCollision (asteroids, shots, i, j, voice2.position);
                } else if (asteroids.at(i).type == 2) {
                    asteroids.at(i).shotCollision (asteroids, shots, i, j, voice3.position);
                } else if (asteroids.at(i).type == 3) {
                    asteroids.at(i).shotCollision (asteroids, shots, i, j, explosion.position);
                }
            }
        }
        catch (out_of_range) {
            continue;
        }
    }
    if (ship.alive == false) restart();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(0, 50);
    ofFill();
    ofRect(0,0,ofGetWidth(),ofGetHeight());
    if (ship.alive) {
        ship.render();
    }
    for (int i = 0; i < shots.size(); i++){
        try {
            shots.at(i).render();
            shots.at(i).dissipate(shots, i);
        }
        catch (out_of_range) {
            continue;
        }
        
    }
    for (int i = 0; i < asteroids.size(); i++){
        try {
            asteroids.at(i).render();
        } catch (out_of_range) {
            continue;
        }

    }
    
//--------------------------------------------------------------
}

void ofApp::restart() {
    ship.alive = true;
    ship.velocity = 0;
    ship.pos.x = ofGetWidth()/2;
    ship.pos.y = ofGetHeight()/2;
    
    asteroids.clear();
    shots.clear();
    
    asteroidCount = ofRandom(asteroidCountMin, asteroidCountMax);
    for (int i = 0; i < asteroidCount; i++) {
        asteroids.push_back(
            Asteroid(
                ofRandom (50, ofGetWidth() - 50),
                ofRandom(50, ofGetHeight() - 50),
                ofRandom(1, 3),
                0,
                ofRandom(359),
                0
            )
        );
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    keysPressed[key] = true;
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    keysPressed[key] = false;
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}
//--------------------------------------------------------------
void ofApp::audioRequested 	(float * output, int bufferSize, int nChannels){
    
    for (int i = 0; i < bufferSize; i++){
        sample = 0;
        wave = 0;
        wave += ship.returnVoice();
        for (int i = 0; i < asteroids.size(); i++){
            try {
                wave += asteroids.at(i).returnVoice();
            } catch (out_of_range) {
                continue;
            }
            
        }
        
        sample += laser.playOnce();
        sample += explosion.playOnce();
        sample += voice1.playOnce();
        sample += voice2.playOnce();
        sample += voice3.playOnce();
            
        mymix.stereo(wave + sample, outputs, 0.5);
        output[i*nChannels    ] = outputs[0]; /* You may end up with lots of outputs. add them here */
        output[i*nChannels + 1] = outputs[1];
    }
    
}

//--------------------------------------------------------------
void ofApp::audioReceived 	(float * input, int bufferSize, int nChannels){
    
    
    /* You can just grab this input and stick it in a double, then use it above to create output*/
    
    for (int i = 0; i < bufferSize; i++){
        
        /* you can also grab the data out of the arrays*/
        
        
    }
    
}