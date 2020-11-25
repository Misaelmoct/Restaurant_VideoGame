#pragma once
#include "BaseCounter.h"

class StoveCounter:public BaseCounter{
    private:
        Item* item;


    public:
        StoveCounter(int x, int y, int width, int height, Item* item,ofImage sprite);

};