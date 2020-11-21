#pragma once

#include "State.h"

class LoseState : public State {
private:
	ofImage img1,gameover;
	bool restart=false;


public:
	LoseState();
	void tick();
	void render();
	void keyPressed(int key);
	void mousePressed(int x, int y, int button);
	void reset();
	bool getRestart(){return restart;}
	void setRestart(bool r){this->restart=r;}
};