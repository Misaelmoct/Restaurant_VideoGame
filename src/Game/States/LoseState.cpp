#include "LoseState.h"

LoseState::LoseState() {
	startButton = new Button(ofGetWidth()/2, ofGetHeight()/2, 64, 50, "START MENU");
	gameover.load("image/Lose.jpg");
}
void LoseState::tick() {
	startButton->tick();
	if(startButton->wasPressed()){
		setNextState("Menu");
		setFinished(true);
	}
}
void LoseState::render() {
	ofSetBackgroundColor(50,10,10);
	gameover.draw(0,0);
    ofSetColor(255,255,255);
	startButton->render();
}

void LoseState::keyPressed(int key){
	
}

void LoseState::mousePressed(int x, int y, int button){
	startButton->mousePressed(x, y);
}

void LoseState::reset(){
	setFinished(false);
	setNextState("");
	startButton->reset();
}