#include "Entity.h"
#include "Burger.h"

class Client: public Entity{
    private:
        Burger* burger;
        int originalPatience;
        int patience=2000;
    public:
        Client(int, int, int, int, ofImage, Burger*);
        ~Client();
        void tick();
        void render();
        int serve(Burger*);
        Client* nextClient=nullptr;
        bool isLeaving=false;
        Burger* getBurger();



};