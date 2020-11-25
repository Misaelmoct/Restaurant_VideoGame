//
// Created by joshu on 11/3/2020.
//

#include "Restaurant.h"

Player *Restaurant::getPlayer() {
    return player;
}

void Restaurant::setPlayer(Player *player) {
    this->player = player;
}

Restaurant::Restaurant() {
    font1.load("Font1square.ttf", 26);
    tables.load("images/tables.png");
    fancyTables.load("images/Fancy.png");//Taken from:Rpg Maker Sprites
    fancyTable1.cropFrom(fancyTables,12,12,84,64);
    fancyTable1.resize(180,130);
    decor.load("images/sprite.png");//Taken from:Rpg Maker Sprites
    chair1.cropFrom(decor,107,13,139,37);
    chair1.resize(150,60);

    floor.load("images/floor.jpg");
    entityManager = new EntityManager();
    ofImage chefPlayerImage;
    chefPlayerImage.load("images/chef.png");
    this->player = new Player(0, 600, 64, 64, chefPlayerImage, entityManager);    
    initItems();
    initCounters();
    initClients();
    generateClient();

}
void Restaurant::initItems(){
    ofImage burgerSpriteSheet, cheeseImg, lettuceImg, tomatoImg, burgerImg, botBreadImg, topBreadImg, plateImg;
    burgerSpriteSheet.load("images/burger.png");
    topBreadImg.cropFrom(burgerSpriteSheet, 25, 16, 112, 43); // top bun
    burgerImg.cropFrom(burgerSpriteSheet, 30, 134, 103, 48); // patty
    cheeseImg.cropFrom(burgerSpriteSheet, 169, 213, 102, 39); // cheese
    tomatoImg.cropFrom(burgerSpriteSheet, 169, 158, 110, 41); // tomato
    lettuceImg.cropFrom(burgerSpriteSheet, 161, 62, 117, 34); // lettuce
    botBreadImg.cropFrom(burgerSpriteSheet, 444, 270, 115, 39); // bottom bun
    plateImg.cropFrom(burgerSpriteSheet, 575, 263, 131, 51); // plate

    cheese = new Item(cheeseImg, "cheese");
    lettuce = new Item(lettuceImg, "lettuce");
    tomato = new Item(tomatoImg, "tomato");
    burger = new Item(burgerImg, "patty");
    botBread = new Item(botBreadImg, "bottomBun");
    topBread = new Item(topBreadImg, "topBun");
    ingredientsAvailable = {cheese, lettuce, tomato};
}
void Restaurant::initCounters(){
    int counterWidth = 96;
    int yOffset = 500;
    ofImage counterSheet, plateCounterImg, cheeseCounterImg, stoveCounterImg, lettuceCounterImg, emptyCounterImg, tomatoCounterImg, breadCounterImg;
    counterSheet.load("images/kitchen_cabinets_by_ayene_chan.png");
    stoveCounterImg.cropFrom(counterSheet, 224,12,32,43);//stoveTop
    lettuceCounterImg.cropFrom(counterSheet,96,76,32,43);//Vegetables
    emptyCounterImg.cropFrom(counterSheet,0,245,30,43);//Empty
    tomatoCounterImg.cropFrom(counterSheet,96,200,32,48);//fruit basket
    cheeseCounterImg.cropFrom(counterSheet,64,73,32,46);//cheese
    plateCounterImg.cropFrom(counterSheet,0,133,32,50);//plates
    breadCounterImg.cropFrom(counterSheet,0,63,34,56);//buns
    entityManager->addEntity(new BaseCounter(0,yOffset-16, counterWidth, 117, nullptr, plateCounterImg));
    entityManager->addEntity( new BaseCounter(counterWidth,yOffset-7, counterWidth,108, cheese, cheeseCounterImg));
    entityManager->addEntity(new StoveCounter(counterWidth*2,yOffset, counterWidth, 102, burger, stoveCounterImg));
    entityManager->addEntity(new BaseCounter(counterWidth*3, yOffset, counterWidth, 102, lettuce, lettuceCounterImg));
    entityManager->addEntity(new BaseCounter(counterWidth*4,yOffset, counterWidth, 102, nullptr, emptyCounterImg));
    entityManager->addEntity(new BaseCounter(counterWidth*5, yOffset -10, counterWidth, 113, tomato, tomatoCounterImg));
    entityManager->addEntity(new BaseCounter(counterWidth*6, yOffset-32, counterWidth, 133, botBread, breadCounterImg));
    entityManager->addEntity(new BaseCounter(counterWidth*7, yOffset-32, counterWidth, 133, topBread, breadCounterImg));

}
void Restaurant::initClients(){
    ofImage temp;
    temp.load("images/People/Car_Designer3Female.png");
    people.push_back(temp);
    temp.load("images/People/Freedom_Fighter2Male.png");
    people.push_back(temp);
    temp.load("images/People/Hipster.png");
    people.push_back(temp);
    temp.load("images/People/Lawyer2Male.png");
    people.push_back(temp);
    temp.load("images/People/Mad_Scientist3Female.png");
    people.push_back(temp);
    temp.load("images/People/Programmer2Male.png");
    people.push_back(temp);
    temp.load("images/People/Songwriter3Male.png");
    people.push_back(temp);
    temp.load("images/People/Weather_Reporter2Female.png");
    people.push_back(temp);
}
void Restaurant::tick() {
    ticks++;
    if(ticks % 400 == 0){
        generateClient();

        if(entityManager->inspector == nullptr){
        gadgetTicks++;
        if(gadgetTicks >= 2) Inspector::badReview = false;
        }
    }
    player->tick();
    entityManager->tick();

}


void Restaurant::generateClient(){
    Burger* b = new Burger(72, 100, 50, 25);
    b->addIngredient(botBread);
    b->addIngredient(burger);
    for( int c = 1; c <= 3; c++){
        b->addIngredient(ingredientsAvailable[ofRandom(0, 3)]);
    }
    b->addIngredient(topBread);
    
    if(gadgetTicks == 5 && entityManager->inspector == nullptr){
    Inspector* gadget = new Inspector(0, 50, 64, 72,people[ofRandom(8)], b, &money);
    entityManager->addClient(gadget);
    entityManager->inspector = gadget;
    gadgetTicks = 0;
    }else{
    Client *c1 = new Client(0, 50, 64, 72,people[ofRandom(8)], b);
    entityManager->addClient(c1);
    }
}
void Restaurant::render() {
    floor.draw(0,0, ofGetWidth(), ofGetHeight());
    for(int i=0;i<3;i++){
        chair1.draw(200,85+(150*i));
        fancyTable1.draw(250,50+(150*i));
        chair1.draw(425,85+(150*i));
        chair1.draw(500,85+(150*i));
        fancyTable1.draw(550,50+(150*i));
        chair1.draw(725,85+(150*i));
    }

    player->render();
    entityManager->render();
    ofSetColor(0, 100, 0);
    string moneyStr = "money    ";
    font1.drawString("money: " + to_string(money), ofGetWidth()/2 - moneyStr.length()/2*26, 32);
    ofSetColor(256, 256, 256);

    if (entityManager->inspector != nullptr && entityManager->inspector->getPatience() > 1700){
        ofSetColor(200, 0, 0);
        string str = "INSPECTOR!";
        font1.drawString(str,(ofGetWidth()/2 - font1.stringWidth(str)/2) , ofGetHeight()/2 - font1.stringHeight(str));
        ofSetColor(256, 256, 256);
    }
    if(Inspector::badReview == true){
        ofSetColor(200, 0, 0);
        string str = "BAD REVIEW!";
        font1.drawString(str, ofGetWidth()/2 - font1.stringWidth(str)/2, ofGetHeight()/2 - font1.stringHeight(str));
        ofSetColor(256, 256, 256);
    }
}
void Restaurant::serveClient(){
    if(entityManager->firstClient!= nullptr){
        money += entityManager->firstClient->serve(player->getBurger());
        player->clearStack();
    }
}
void Restaurant::keyPressed(int key) {
    player->keyPressed(key);
    if(key == 's'){
        serveClient();
    }
}
