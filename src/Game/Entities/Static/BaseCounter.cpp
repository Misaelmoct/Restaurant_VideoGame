//
// Created by joshu on 11/3/2020.
//

#include "BaseCounter.h"
#include "State.h"

BaseCounter::BaseCounter(int x, int y, int width, int height,Item* item, ofImage sprite) : Entity(x, y, width, height, sprite){
    this->item = item;
}

Item* BaseCounter::getItem(){
    return item;
}

void BaseCounter::showItem(){
    if (item != nullptr){
        if(State::level == 3){
        if(item->name == "bottomBun" || item->name == "topBun") ofSetColor(60,208,150);
        else if(item->name == "lettuce") ofSetColor(0,50,0);
        else if(item->name == "cheese") ofSetColor(252,16,99);
        else if(item->name == "tomato") ofSetColor(0,20,150);
        }
        item->sprite.draw(x+width/2 -25, y-30, 50, 30);
    }
}
