#pragma once
#include "Client.h"



class Inspector: public Client{
    private:
    int *money1;

    public:

    Inspector(int, int, int, int, ofImage, Burger*, int*);
    ~Inspector();
    void tick();
    int getPatience(){return patience;}
    static bool badReview;
};