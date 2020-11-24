#include "MenuState.h"

MenuState::MenuState() {
	startButton = new Button(ofGetWidth()/2, ofGetHeight()/2, 64, 50, "Start");
	background.load("images/background1.jpg");
}
void MenuState::tick() {
	startButton->tick();
	if(startButton->wasPressed()){
		setNextState("Game");
		setFinished(true);

	}
}
void MenuState::render() {
	// ofSetBackgroundColor(230, 230, 250);
	ofSetBackgroundColor(10,30,30);
	background.draw(0,0);
	ofSetColor(255);
	ofDrawBitmapString("Press 'E' to collect ingredients. \nPress 'S' to serve",200,600);
	startButton->render();
}

void MenuState::keyPressed(int key){
	
}

void MenuState::mousePressed(int x, int y, int button){
	startButton->mousePressed(x, y);
}

void MenuState::reset(){
	setFinished(false);
	setNextState("");
	startButton->reset();
}