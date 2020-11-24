#include "Inspector.h"

Inspector::Inspector(int x, int y, int width, int height, ofImage sprite, Burger *burger, int *money1): Client(x, y, width, height, sprite, burger){
    this->money1 = money1;
}
Inspector::~Inspector(){
    }

void Inspector:: tick(){
        patience--;
    burger->setY(y);
    if(patience == 0){
        isLeaving = true;
    }
    if(nextClient != nullptr){
        nextClient->tick();
    }
    if(patience == 0){
       (*money1) /= 2; 
    }
}
