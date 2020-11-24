#pragma once
#include "Entity.h"
#include "Burger.h"

class Client: public Entity{
    protected:
        Burger* burger;
        int originalPatience;
        int patience=2000;
        static int leavingCount;
        bool isLost = false;
    public:
        Client(int, int, int, int, ofImage, Burger*);
        ~Client();
        virtual void tick();
        void render();
        int serve(Burger*);
        Client* nextClient=nullptr;
        bool isLeaving=false;
        Burger* getBurger();
        bool getLost(){return isLost;}
        void resetCount(){this->leavingCount = 0;}

};