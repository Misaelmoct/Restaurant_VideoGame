#include "StoveCounter.h"

StoveCounter::StoveCounter(int x, int y, int width, int height, Item* item, ofImage sprite):BaseCounter(x,y,width,height,item,sprite){
    this->item = item;
}

void StoveCounter::cooking(){
    if(isActive){
        count++;
        if(count%150>=1){
            ofSetColor(222,184,185);
        }else if(count%150>=60){
            ofSetColor(205,133,63);
        }else if(count%150>=100){
            ofSetColor(139,69,19);
        }
        if(count%10==1){
            showItem();
        }
        if(count%151==150){
            isActive = false;
            isRaw = false;
        }
}

