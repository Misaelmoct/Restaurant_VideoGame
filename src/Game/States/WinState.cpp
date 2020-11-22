#include "WinState.h"

WinState::WinState() {
	win.load("images/win.png");
}
void WinState::tick() {
	if(this->getRestart()){
		setNextState("Menu");
		setFinished(true);
	}
}
void WinState::render() {
	ofSetBackgroundColor(10,10,50);
	ofSetColor(255,255,255);
    win.draw(0,0, ofGetWidth(), ofGetHeight());
	ofDrawBitmapString("Press SPACEBAR to restart",ofGetWidth()/2 - 50, ofGetHeight()/2);
}

void WinState::keyPressed(int key){
	if(key==' '){
		this->setRestart(true);
	}
}

void WinState::mousePressed(int x, int y, int button){
}

void WinState::reset(){
	setRestart(false);
	setFinished(false);
	setNextState("");
}