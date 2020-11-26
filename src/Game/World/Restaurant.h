//
// Created by joshu on 11/3/2020.
//

#ifndef APGAMEENGINE_RESTAURANT_H
#define APGAMEENGINE_RESTAURANT_H
#include "ofMain.h"
#include "Player.h"
#include "EntityManager.h"
#include "BaseCounter.h"
#include "Inspector.h"
#include "StoveCounter.h"

class Restaurant {
    private:
        Player* player;
        EntityManager* entityManager;
        int ticks=0;
        int gadgetTicks = 1;
        std::vector<ofImage> people;
        int money =0;

    public:
        Restaurant();
        Player* getPlayer();
        void setPlayer(Player *player);
        Item* cheese;
        Item* lettuce;
        Item* tomato;
        Item* burger;
        Item* botBread;
        Item* topBread;
        vector<Item*> ingredientsAvailable;
        ofImage floor,decor,tables,chair1,fancyTables, fancyTable1; 
        void initItems();
        void initCounters();
        void initClients();
        void generateClient();
        void generateInspector();
        void serveClient();
        void tick();
        void render();
        void keyPressed(int key);
        ofTrueTypeFont font1;
        int getMoney(){return money;}
        bool lost(){return entityManager->getLose();}
        void resetCount(){entityManager->resetCount();}
        EntityManager* getManager(){ return entityManager;}
};


#endif //APGAMEENGINE_RESTAURANT_H
