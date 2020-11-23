#include "Entity.h"
#include "BaseCounter.h"

class StoveCounter:public BaseCounter{
    private:
        Item *item;
        bool isCooking = false;
        bool isRaw = true;

    public:
        StoveCounter(int x, int y, int width, int height, Item* item, ofImage sprite);
        Item* getItem();
        void showItem();
        bool getIsCooking(){return isCooking;}
        bool getIsRaw(){return isRaw;}
        void setIsCooking(bool value){
            this->isCooking = value;
        }
        void setIsRaw(bool value){
            this->isRaw = value;
        }
};