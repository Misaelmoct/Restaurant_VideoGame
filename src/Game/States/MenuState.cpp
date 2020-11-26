#include "MenuState.h"
int State::level = 1;
MenuState::MenuState() {
	startButton = new Button(ofGetWidth()/2, ofGetHeight()/2, 64, 50, "Start");
	background.load("images/background1.jpg");
	levelF.load("LevelFont.ttf", 26);//Taken from: https://www.fontspace.com/f-zero-gp-legend-font-f11371
	
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
	ofSetColor(255,223,0);
	levelF.drawString("LEVEL " + to_string(State::level), ofGetWidth()/2 - levelF.stringWidth("LEVEL")/2, ofGetWidth()/2 + 30);
	ofSetColor(255);
	ofDrawBitmapString("Press 'E' to collect ingredients.\nPress 'U' to delete last picked ingredient.\nPress 'S' to serve. " ,200,600);
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