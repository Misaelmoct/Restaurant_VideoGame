//
// Created by joshu on 11/4/2020.
//

#ifndef APGAMEENGINE_BURGER_H
#define APGAMEENGINE_BURGER_H

#include "Item.h"
#include "Entity.h"

class Burger {
private:
    int x,y,width,height;
 stack <Item*, vector<Item*> >ingredients;

public:
    Burger(int, int, int, int);
    void addIngredient(Item *item);
    void deleteIngredient();
    void render();
    void clear();
    bool equals(Burger*);
    void setY(int y){
        this->y = y;
    }

};


#endif //APGAMEENGINE_BURGER_H
