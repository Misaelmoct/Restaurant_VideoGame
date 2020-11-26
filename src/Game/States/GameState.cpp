#include "GameState.h"

GameState::GameState() {
    this->restaurant = new Restaurant();
}
void GameState::tick() {
	restaurant->tick();
	if(restaurant->getMoney()==100 && State::level == 1){
		setNextState("Win");
		setFinished(true);
	}else if(restaurant->getMoney()==200 && State::level == 2){
		setNextState("Win");
		setFinished(true);
	}else if(restaurant->getMoney()==300 && State::level == 3){
		setNextState("Win");
		setFinished(true);
	}else if(restaurant->getManager()->firstClient != nullptr && restaurant->lost()){
		setNextState("Lose");
		setFinished(true);
	}
}
void GameState::render() {
	restaurant->render();
}

void GameState::keyPressed(int key){
	if(key=='L'|| key=='l'){
		setNextState("Lose");
		setFinished(true);
	}else if(key=='w'||key=='W'){
		setNextState("Win");
		setFinished(true);
	}else{
		restaurant->keyPressed(key);
	}
}

void GameState::mousePressed(int x, int y, int button){
}

void GameState::keyReleased(int key){
}

void GameState::reset(){
	restaurant->resetCount();
	restaurant = new Restaurant();
	setFinished(false);
	setNextState("");
}