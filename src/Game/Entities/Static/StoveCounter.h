#include "BaseCounter.h"
#include "Item.h"

class StoveCounter:public BaseCounter{
    private:
        bool isCooking = false;
        bool isCooked = true;
        Item* item;
        int count = 0;
        bool isActive = false;

    public:
        StoveCounter(int x, int y, int width, int height, Item* item, ofImage sprite);
        bool getIsCooking(){return isCooking;}
        void setIsCooking(bool value){this->isCooking = value;}

        bool getIsCooked(){return isCooked;}
        void setIsCooked(bool value){this->isCooked = value;}

        void cooking();
        void tick(){count++;}
        void cookingToggle();
        void showItem();
        
};      
