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
        if(ingredient->name == "patty"){
            ofSetColor(139,69,19);
        }
        ingredient->sprite.draw(x,y-(counter * 10),width,height);
        counter++;
        ofSetColor(255,255,255);
    }
}

void Burger::clear(){
    ingredients.empty();
}