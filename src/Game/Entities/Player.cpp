#include "Player.h"
#include "State.h"

Player::Player(int x, int y, int width, int height, ofImage sprite, EntityManager* em) : Entity(x, y, width, height, sprite){
    this->burger = new Burger(ofGetWidth()-110, 100, 100, 50);
    if(State::level == 1){
    vector<ofImage> chefAnimframes;
    ofImage temp;
    temp.cropFrom(sprite, 30,3,66,120);
    chefAnimframes.push_back(temp);
    temp.cropFrom(sprite, 159,3,66,120);
    chefAnimframes.push_back(temp);
    temp.cropFrom(sprite, 287, 3,67,120);
    chefAnimframes.push_back(temp);
    temp.cropFrom(sprite, 31,129,66,120);
    chefAnimframes.push_back(temp);
    this->chefAnim = new Animation(50, chefAnimframes);
    }
    this->entityManager = em;
    
}
void Player::tick(){
    if(State::level == 1) chefAnim->tick();
    if(facing == "left"){
        x-=speed;
    }else if(facing == "right"){
        x+=speed;
    }
    if(x <= 0){
        facing = "right";
    }else if(x + width >= ofGetWidth()){
        facing = "left";
    }
    
    if(isCooking){
        cookingTimer++;
        if(cookingTimer%201==200){
            isCooked = true;
            isCooking = false;
            hasBeenCooked = true;
            cookingTimer++;
        }
    }
}

void Player::render(){
     ofSetColor(255,0,128);
    if(isCooking){
        ofDrawBitmapString("Cooking...",225,475);
    }else if(isCooked){
        ofDrawBitmapString("Cooked",225,475);
    }else{
        ofDrawBitmapString("Cook",225,475);
    }
    ofSetColor(255,255,255);
    BaseCounter* ac = getActiveCounter();
    if(dynamic_cast<StoveCounter*>(ac)){
        if(isCooking){
            ofSetColor(255,255,255); 
            ac->showItem();
        }else if(isCooked){
            ofSetColor(139,69,19);
            ac->showItem();
        }else{
            ofSetColor(255,255,255);
            ac->showItem();
        }
    }
    else if(ac != nullptr){
        ac->showItem();
        ofSetColor(255,255,255);
    }
    
    ofSetColor(256,256,256);
    ofImage currentFrame = chefAnim->getCurrentFrame();
    if(State::level == 1){ ofImage currentFrame = chefAnim->getCurrentFrame();
   if(facing == "left"){
       currentFrame.mirror(false, true);
    }
     currentFrame.draw(x, y, width, height);
    }else{
        sprite.draw(x, y, width, height);
    }
   burger->render();
}


void Player::keyPressed(int key){
    if(key == 'e'){
        BaseCounter* ac = getActiveCounter();
        if(ac != nullptr){
            Item* item = ac->getItem();
            if(item != nullptr){
                if(dynamic_cast<StoveCounter*>(ac) != NULL){
                    if(dynamic_cast<StoveCounter*>(ac) && !isCooking && !hasBeenCooked){
                        isCooking = true;
                    }else if(dynamic_cast<StoveCounter*>(ac) && isCooked && hasBeenCooked){
                        burger->addIngredient(item);
                        isCooking = false;
                        isCooked = false;
                        hasBeenCooked = false;
                    }
                }else{burger->addIngredient(item);}
            }
        }
    }

    if (key == 'u'){
        burger->deleteIngredient();
    }
}
BaseCounter* Player::getActiveCounter(){
    for(Entity* e:entityManager->entities){
        BaseCounter* c = dynamic_cast<BaseCounter*>(e);
        if(x + e->getWidth()/2 >= e->getX() && x +e->getWidth()/2 <e->getX() + e->getWidth()){
            return c;
        }
    }
    return nullptr;
}
void Player::keyReleased(int key){
}
void Player::mousePressed(int x, int y, int button){

}

void Player::setFacing(string facing){
    this->facing = facing;
}

void Player::clearStack(){
    burger->clear();
}
