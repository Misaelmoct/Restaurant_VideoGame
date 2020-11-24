#include "LoseState.h"

LoseState::LoseState() {
	gameover.load("images/Lose1.jpg");
}
void LoseState::tick() {
	if(this->getRestart()){
		setNextState("Menu");
		setFinished(true);
	}
}
void LoseState::render() {
	ofSetBackgroundColor(0,0,0);
    ofSetColor(255,0,0);
	gameover.draw(0,0, ofGetWidth(), ofGetHeight());
	ofDrawBitmapString("Press SPACEBAR to restart",ofGetWidth()/2 -50,ofGetHeight()/2 -100);
}

void LoseState::keyPressed(int key){
	if(key==' '){
		this->setRestart(true);
	}
}

void LoseState::mousePressed(int x, int y, int button){
}

void LoseState::reset(){
	setRestart(false);
	setFinished(false);
	setNextState("");
}