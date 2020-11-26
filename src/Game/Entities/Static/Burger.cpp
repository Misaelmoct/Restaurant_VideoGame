//
// Created by joshu on 11/4/2020.
//

#include "Burger.h"
#include "State.h"

Burger::Burger(int x, int y, int width, int height){
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
}

void Burger::addIngredient(Item *item) {
    ingredients.push(item);
}

void Burger::render(){
    int counter = 1;
    stack <Item*, vector<Item*> > copyTarget;
        while( !ingredients.empty()){
        copyTarget.push(ingredients.top());
        ingredients.pop();;
    }
        while( !copyTarget.empty()){
        if(copyTarget.top()->name == "patty"){
            ofSetColor(139,69,19);
        }
            if(State::level == 3){
        if(copyTarget.top()->name == "bottomBun" || copyTarget.top()->name == "topBun") ofSetColor(60,208,150);
        else if(copyTarget.top()->name == "lettuce") ofSetColor(0,50,0);
        else if(copyTarget.top()->name == "cheese") ofSetColor(252,16,99);
        else if(copyTarget.top()->name == "tomato") ofSetColor(0,20,150);
            }
        copyTarget.top()->sprite.draw(x,y-(counter * 10),width,height);
        ofSetColor(255);
        counter++;
        ingredients.push(copyTarget.top());
        copyTarget.pop();
        ofSetColor(255,255,255);
    }

}

void Burger::clear(){
    while(!ingredients.empty()){
    ingredients.pop();
    }
}

bool Burger:: equals(Burger *b){
   bool equal = true;
    stack<Item*, vector<Item*> > copyTarget(ingredients);
    stack<Item*, vector<Item*> > copyPar(b->ingredients);
    if (this->ingredients.size() != b->ingredients.size()){
        equal = false;
    }

    while(!copyPar.empty() && equal){
        equal = false;
        if(copyTarget.top()->name.compare(copyPar.top()->name) == 0){
                equal = true;
            }
        copyTarget.pop();
        copyPar.pop();

    }
    return equal;

}

void Burger::deleteIngredient(){
    if(!ingredients.empty()){
    ingredients.pop();
    }
}