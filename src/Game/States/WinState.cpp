#include "WinState.h"

WinState::WinState() {
	startButton = new Button(ofGetWidth()/2, ofGetHeight()/2, 64, 50, "Restart");
	win.load("images/win.png");
}
void WinState::tick() {
	startButton->tick();
	if(startButton->wasPressed()){
		setNextState("Menu");
		setFinished(true);
	}
}
void WinState::render() {
	ofSetBackgroundColor(10,10,50);
	ofSetColor(255,255,255);
    win.draw(0,0, ofGetWidth(), ofGetHeight());
	startButton->render();
}

void WinState::keyPressed(int key){
	
}

void WinState::mousePressed(int x, int y, int button){
	startButton->mousePressed(x, y);
}

void WinState::reset(){
	setFinished(false);
	setNextState("");
	startButton->reset();
}