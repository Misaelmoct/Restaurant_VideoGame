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
}

void Player::render(){
    BaseCounter* ac = getActiveCounter();
    if(ac != nullptr){
        ac->showItem();
    }
    ofSetColor(256,256,256);
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
                burger->addIngredient(item);
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
