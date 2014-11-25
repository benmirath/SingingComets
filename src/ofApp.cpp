#include "ofApp.h"
//#include <Poco/Path.h>

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
    
}

//--------------------------------------------------------------
void ofApp::update(){
//    core.update();
    
    if (keysPressed[357] == true) ship.accelerate();
    if (keysPressed[356] == true) ship.rotation -= .1;
    if (keysPressed[358] == true) ship.rotation += .1;
    if (keysPressed[32] == true) ship.shoot(shots);
    
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
                asteroids.at(i).shotCollision (asteroids, shots, i, j);
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
        asteroids.push_back(Asteroid(ofRandom (50, ofGetWidth() - 50), ofRandom(50, ofGetHeight() - 50), ofRandom(1, 3), 0, ofRandom(359), 0));
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    keysPressed[key] = true;
    cout << key << endl;
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
        
        /* Stick your maximilian 'play()' code in here ! Declare your objects in testApp.h.
         
         For information on how maximilian works, take a look at the example code at
         
         http://www.maximilian.strangeloop.co.uk
         
         under 'Tutorials'.
         
         */
        
        
        
        sample=beat.play(0.25, 0, beat.length);
        
        wave=sine1.sinebuf(abs(mouseX));/* mouse controls sinewave pitch. we get abs value to stop it dropping
                                         //										 delow zero and killing the soundcard*/
        
        mymix.stereo(sample + wave, outputs, 0.5);
        
        
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