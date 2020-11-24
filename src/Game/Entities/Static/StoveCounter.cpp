#include "StoveCounter.h"

StoveCounter::StoveCounter(int x, int y, int width, int height, Item* item, ofImage sprite):BaseCounter(x,y,width,height,item,sprite){
    this->item = item;
}

void StoveCounter::cooking(){
    if(isActive){
        if(count%151==150){
            ofSetColor(139,69,19);
            item->sprite.draw(x+width/2 -25, y-30, 50, 30);
            isActive = false;
            isCooked = true;
        }
    }
}
void StoveCounter::cookingToggle(){
    if(isActive){this->isActive = false;}
    else if(!isActive){this->isActive = true;}
}

void StoveCounter::tick(){
    count++;
}

void StoveCounter::showItem(){
    if(item != nullptr){
        if(!isCooked){
            ofSetColor(0);
            item->sprite.draw(x+width/2 -25, y-30, 50, 30);
        }else{
            ofSetColor(139,69,19);
            item->sprite.draw(x+width/2 -25, y-30, 50, 30);
        }
    }
}

