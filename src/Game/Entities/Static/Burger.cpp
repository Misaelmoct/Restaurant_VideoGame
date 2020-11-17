//
// Created by joshu on 11/4/2020.
//

#include "Burger.h"

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
        copyTarget.top()->sprite.draw(x,y-(counter * 10),width,height);
        counter++;
        ingredients.push(copyTarget.top());
        copyTarget.pop();
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
    ingredients.pop();
}