#include "BaseCounter.h"
#include "Item.h"

class StoveCounter:public BaseCounter{
    private:
        bool isCooking = false;
        bool isRaw = true;
        Item* item;
        int count = 0;
        bool isActive = false;
    
    public:
        StoveCounter(int x, int y, int width, int height, Item* item, ofImage sprite);
        bool getIsCooking(){return isCooking;}
        void setIsCooking(bool value){this->isCooking = value;}

        bool getIsRaw(){return isRaw;}
        void setIsRaw(bool value){this->isRaw = value;}

        void cooking();
        void showItem(){
            if (item != nullptr){
                item->sprite.draw(x+width/2 -25, y-30, 50, 30);
            }
        }
};      
