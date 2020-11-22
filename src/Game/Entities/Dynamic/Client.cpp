#include "Client.h"


Client::Client(int x, int y, int width, int height, ofImage sprite, Burger* burger): Entity(x, y, width, height, sprite){
    this->burger = burger;
}
Client::~Client(){
    burger->~Burger();
}

void Client::render(){
    ofSetColor (255,255,255);
    burger->render();
    if (patience<=500){
        ofSetColor(50,0,0);
    }else if(patience<=1000){
        ofSetColor(80,0,0);
    }else if(patience<=1500){
        ofSetColor(100,0,0);
    }
    sprite.draw(x, y, width, height);
    // ofDrawRectangle(getBounds());
    if(nextClient != nullptr){
        nextClient->render();
    }
}

void Client::tick(){
    patience--;
    burger->setY(y);
    if(patience == 0){
        isLeaving = true;
        leavingCount+=1; 
    }
    if(leavingCount == 10){
        isLost = true;
    }
    if(nextClient != nullptr){
        nextClient->tick();
    }
}

int Client::serve(Burger* burger){
    isLeaving = true;
    return 10;
}
