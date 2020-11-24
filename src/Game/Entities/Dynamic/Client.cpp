#include "Client.h"

int Client::leavingCount = 0;


Client::Client(int x, int y, int width, int height, ofImage sprite, Burger* burger): Entity(x, y, width, height, sprite){
    this->burger = burger;
}
Client::~Client(){
    burger->~Burger();
}

void Client::render(){
    ofSetColor (255,255,255);
    burger->render();
   if(patience % 100 == 0){
    a += 12;
    }
    ofDrawBitmapString(to_string(a), ofGetWidth()/2, 50);
    sprite.draw(x, y, width, height);
    ofSetColor(255,0,0,a);
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
        leavingCount++; 
    }
    if(leavingCount==10){
        isLost = true;
        // leavingCount++;
    }
    if(nextClient != nullptr){
        nextClient->tick();
    }
}

int Client::serve(Burger* burger){
    
    if (burger->equals(this->burger)){
    isLeaving = true;
    return 10;
    }
    else if(nextClient == nullptr){
        return 0;
    }
    return nextClient->serve(burger);
}

Burger* Client::getBurger(){
    return this->burger;
}
