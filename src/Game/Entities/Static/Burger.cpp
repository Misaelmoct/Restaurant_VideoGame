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
    ingredients.push_back(item);
}

void Burger::render(){
    int counter = 1;
    for (Item* ingredient:ingredients){
        ingredient->sprite.draw(x,y-(counter * 10),width,height);
        counter++;
    }
}

void Burger::clear(){
    ingredients.empty();
}

bool Burger:: equals(Burger *b){
    bool equal = true;
    if (b->ingredients.size() != this->ingredients.size()){
        equal = false;
    }
    for(int i = 0; i < ingredients.size() && equal; i++){
        equal = false;
        for (Item *b1: b->ingredients){
            if (ingredients[i]->name.compare(b1->name));
            equal = true;
        }
    }
    return equal;
}

void Burger::deleteIngredient(){
    ingredients.pop_back();
}