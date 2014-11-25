//
//  asteroid.cpp
//  SingingComets
//
//  Created by Ben Miller on 11/17/14.
//
//

#include "musicEntity.h"
#include "asteroid.h"

Asteroid::Asteroid (float X, float Y, float V, int T, float A, float R) {
    MusicEntity::MusicEntity();
    pos.x = X;
    pos.y = Y;
    velocity = V;
    angle = A;
    type = T;
    rotation = R;
    
    if (type == 0) {
        w = ofRandom (80, 100);
    } else if (type == 1) {
        w = ofRandom (60, 80);
    } else if (type == 2) {
        w = ofRandom (30, 60);
    } else if (type == 3) {
        w = ofRandom (15, 25);
    }
}
Asteroid::~Asteroid () {
    
}

void Asteroid::render() {
    MusicEntity::render();
    ofPushMatrix ();
    ofTranslate (pos.x, pos.y);
    ofNoFill ();
    
    ofSetColor (200, 255, 255, 180);
    ofEllipse (0, 0, w, w);
    ofPopMatrix ();
}

void Asteroid::shotCollision(vector<Asteroid>& asteroids, vector<PlayerShot>& shots, int asteroidIndex, int shotIndex, double& explosionSound) {
    Asteroid asteroid = asteroids[asteroidIndex];
    PlayerShot shot = shots[shotIndex];
    
    if (ofDist(pos.x, pos.y, shot.pos.x, shot.pos.y) < w/2 + 2) {
        shots.erase(shots.begin() + shotIndex);
        if (asteroid.type == 0) {
            asteroids.push_back(Asteroid (pos.x + ofRandom(-5, 5), pos.y + ofRandom(-5, 5), asteroid.velocity + ofRandom(2), 1, ofRandom(359), 0));
            asteroids.push_back(Asteroid (pos.x + ofRandom(-5, 5), pos.y + ofRandom(-5, 5), asteroid.velocity + ofRandom(2), 1, ofRandom(359), 0));
        } else if (asteroid.type == 1) {
            asteroids.push_back(Asteroid (pos.x + ofRandom(-5, 5), pos.y + ofRandom(-5, 5), asteroid.velocity + ofRandom(2), 2, ofRandom(359), 0));
            asteroids.push_back(Asteroid (pos.x + ofRandom(-5, 5), pos.y + ofRandom(-5, 5), asteroid.velocity + ofRandom(2), 2, ofRandom(359), 0));
        } else if (asteroid.type == 2) {
            asteroids.push_back(Asteroid (pos.x + ofRandom(-5, 5), pos.y + ofRandom(-5, 5), asteroid.velocity + ofRandom(2), 3, ofRandom(359), 0));
            asteroids.push_back(Asteroid (pos.x + ofRandom(-5, 5), pos.y + ofRandom(-5, 5), asteroid.velocity + ofRandom(2), 3, ofRandom(359), 0));
        }
        asteroids.erase(asteroids.begin() + asteroidIndex);
        explosionSound = 0;
        
    }
}

void Asteroid::playerCollision(Player& player, Asteroid& asteroid) {
    if (ofDist(pos.x, pos.y, player.pos.x, player.pos.y) < w/2 + 5) {
        ofSetColor(200, 255, 255, 180);
        ofEllipse (player.pos.x, player.pos.y, 100, 100);
        player.alive = false;
    }
}

double Asteroid::returnVoice() {
    double returnVal = pos.y;
    if (type == 0) {
        returnVal = returnVal / 4;
    } else if (type == 1) {
        returnVal = returnVal / 3;
    } else if (type == 2) {
        returnVal = returnVal / 2;
    } else if (type == 3) {
        returnVal = returnVal;
    }

    return voice.coswave(abs(returnVal));

}