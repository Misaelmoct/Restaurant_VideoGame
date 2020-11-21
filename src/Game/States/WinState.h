#pragma once

#include "State.h"

class WinState : public State {
private:
	ofImage img1,win;
	bool restart=false;

public:
	WinState();
	void tick();
	void render();
	void keyPressed(int key);
	void mousePressed(int x, int y, int button);
	void reset();
	bool getRestart(){return restart;}
	void setRestart(bool r){this->restart = r;}
};