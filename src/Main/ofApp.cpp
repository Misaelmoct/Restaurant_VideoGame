#include "ofApp.h"
#include "Images.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetWindowTitle("Java Game Box");
	//States
	menuState = new MenuState();
	gameState = new GameState();
	winState = new WinState();
	gameover=new LoseState();
	// Initial State
	currentState = menuState;

	music.load("No Copyright Music Retro 80's Funky Jazz Hop Instrumental Copyright Free Music   Sundance Remix (320 kbps).mp3");
	//Royalty Free Music taken from:https://www.youtube.com/watch?v=LOFAkeAZXgE&ab_channel=PepsenDK 
	music.setLoop(true);
	

	music1.load("Bensound - The Jazz Piano _ Royalty Free Music (320 kbps).mp3");
	//Royalty Free Music taken from:https://www.youtube.com/watch?v=UImwn5BkSt8&ab_channel=TheSound-BeYourSound
	music1.setLoop(true);
	music1.setVolume(0.5);
	music1.play();
	

	overm.load("(No Copyright Music) Sad Emotional Piano Music (320 kbps).mp3");
	//Royalty Free Music taken from:https://www.youtube.com/watch?v=MzXCyO0DcyU&ab_channel=DSProductions-NoCopyrightMusic
	music.setLoop(true);
}

//--------------------------------------------------------------
void ofApp::update(){
	if (currentState != nullptr){
		currentState->tick();
		if(currentState->hasFinished()){
			if(currentState->getNextState() == "Menu"){
				music.stop();
				overm.stop();
				music1.play();
				currentState = menuState;
			}else if(currentState->getNextState() == "Game"){
				currentState = gameState;
			}else if(currentState->getNextState()=="Win"){
				music1.stop();
				music.play();
				currentState = winState;
			}else if(currentState->getNextState()=="Lose"){
				music1.stop();
				overm.play();
				currentState = gameover;
			}
			currentState->reset();
		}
	}
		
}

//--------------------------------------------------------------
void ofApp::draw(){
	if (currentState != nullptr)
		currentState->render();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (currentState != nullptr)
		currentState->keyPressed(key);

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	if (currentState != nullptr)
			currentState->keyReleased(key);
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
	if (currentState != nullptr)
		currentState->mouseMoved(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	if (currentState != nullptr)
		currentState->mouseDragged(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	if (currentState != nullptr)
		currentState->mousePressed(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	if (currentState != nullptr)
		currentState->mouseReleased(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
	if (currentState != nullptr)
			currentState->mouseEntered(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
	if (currentState != nullptr)
		currentState->mouseExited(x, y);
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
	if (currentState != nullptr)
			currentState->windowResized(w, h);
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
	if (currentState != nullptr)
		currentState->gotMessage(msg);
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 
	if (currentState != nullptr)
		currentState->dragEvent(dragInfo);
}
