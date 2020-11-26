//
// Created by joshu on 11/3/2020.
//

#include "Restaurant.h"
#include "State.h"

Player *Restaurant::getPlayer() {
    return player;
}

void Restaurant::setPlayer(Player *player) {
    this->player = player;
}

Restaurant::Restaurant() {

    
    entityManager = new EntityManager();;
    initMode();
    this->player = new Player(0, 600, 64, 64, chefPlayerImage, entityManager);    
    initItems();
    initCounters();
    initClients();
    generateClient();


    


}

void Restaurant::initMode(){

    if(State::level == 1){
    chefPlayerImage.load("images/chef.png");
    font1.load("Font1square.ttf", 26);//Taken from: https://www.fontspace.com/wendys-waffles-font-f29505
    floor.load("images/floor.jpg");
    tables.load("images/tables.png");
    fancyTables.load("images/Fancy.png");//Taken from:Rpg Maker Sprites
    fancyTable1.cropFrom(fancyTables,12,12,84,64);
    fancyTable1.resize(180,130);
    decor.load("images/sprite.png");//Taken from:Rpg Maker Sprites
    chair1.cropFrom(decor,107,13,139,37);
    chair1.resize(150,60);
    }


    else if(State::level == 2){
    chefPlayerImage.load("images/animalChef.png");//Taken from: https://www.pngwing.com/en/free-png-zzlty
    font1.load("AnimalFont.ttf", 36);//Taken from: https://www.fontspace.com/vtks-animal-2-font-f6428
    animals.load("images/animalsSprite.png");//Taken from: https://i.pinimg.com/originals/86/09/37/860937b98fb697f20efd321522f237b1.png
    treesSprite.load("images/treesSprite2.png");//Taken from: https://pnghut.com/png/St9jPq8v75/pok%C3%A9mon-platinum-tile-based-video-game-isometric-graphics-in-games-and-pixel-art-sprite-projection-transparent-png#

    smallTree.cropFrom(treesSprite,903,1216,90,76);
    mediumTree.cropFrom(treesSprite,312,1266,69,112);
    bigTree.cropFrom(treesSprite,722,1360,270,230);
    bigTree2.cropFrom(treesSprite,3,1365,95,215);
    plant.cropFrom(treesSprite,614,1233,67,37);
    pasto.cropFrom(treesSprite,0,150,800,49);
    deadTree.cropFrom(treesSprite, 320,1418,58,160);
    }

    else if(State::level == 3){
        floor.load("images/spaceBackground.jpg");//Taken from: <a href='https://www.freepik.es/vectores/estrella'>Vector de Estrella creado por upklyak - www.freepik.es</a>
        chefPlayerImage.load("images/alienChef.png");//Taken from: https://pnghut.com/png/a86wFbKTMG/baby-groot-star-lord-clip-art-marvel-comics-guardians-of-the-galaxy-transparent-png
        font1.load("SpaceFont.ttf", 26);//Taken from: https://www.fontspace.com/game-battles-font-f31916
    }
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
    if(State::level == 1){
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

    else if(State::level == 2){
    temp.cropFrom(animals,99,62,73,122);//conejo
    people.push_back(temp);
    temp.cropFrom(animals,491,90,97,92);//mono
    people.push_back(temp);
    temp.cropFrom(animals,99,247,73,108);//gato
    people.push_back(temp);
    temp.cropFrom(animals,487,235,101,121);//cabra
    people.push_back(temp);
    temp.cropFrom(animals,95,426,73,113);//pollo
    people.push_back(temp);
    temp.cropFrom(animals,287,434,109,101);//koala
    people.push_back(temp);
    }

    else if(State::level == 3){
        temp.load("images/alien.png");//alien Taken from: https://www.pngwing.com/en/free-png-pfqla
        people.push_back(temp);
        temp.load("images/astronaut.png");//astronaut Taken from: https://flyclipart.com/astronaut-flying-cartoon-astronaut-clipart-png-515021#
        people.push_back(temp);
    }
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
    Inspector* gadget = new Inspector(0, 50, 64, 72,people[ofRandom(people.size())], b, &money);
    entityManager->addClient(gadget);
    entityManager->inspector = gadget;
    gadgetTicks = 0;
    }else{
    Client *c1 = new Client(0, 50, 64, 72,people[ofRandom(people.size())], b);
    entityManager->addClient(c1);
    }
}
void Restaurant::render() {

    if(State::level == 1){
        floor.draw(0,0, ofGetWidth(), ofGetHeight());
        for(int i=0;i<3;i++){
        chair1.draw(200,85+(150*i));
        fancyTable1.draw(250,50+(150*i));
        chair1.draw(425,85+(150*i));
        chair1.draw(500,85+(150*i));
        fancyTable1.draw(550,50+(150*i));
        chair1.draw(725,85+(150*i));
        }
    }

    else if(State::level == 2){
    double xCoord = -49.5;
    int n = 40;
    for(double yCoord = -24; yCoord < ofGetWidth() + 24; yCoord+=24){
    pasto.draw(xCoord,yCoord);
    pasto.draw(xCoord + 800,yCoord);
    if(xCoord == -49.5) xCoord = 0;
    else{ xCoord = -49.5;};
    }
     plant.draw(250, 30, 16, 9);
     plant.draw(700, 40, 16, 9);
     plant.draw(350, 400, 33, 18);
     plant.draw(500, 450, 33, 18);
     plant.draw(400, 250, 23, 13);
     plant.draw(150, 50, 16, 9);
     plant.draw(180, 90, 16, 9);
     plant.draw(130, 150, 33, 18);
     plant.draw(140, 200, 16, 9);
     plant.draw(125, 200, 16, 9);
     plant.draw(135, 250, 16, 9);
     plant.draw(140, 255, 16, 9);
     plant.draw(150, 300, 16, 9);
     smallTree.draw(350, 55, 27, 23);
     smallTree.draw(600, 50, 27, 23);
     smallTree.draw(550, 80, 40, 34);
     smallTree.draw(250, 200, 42, 36);
     smallTree.draw(350, 300 , 49, 42);
    deadTree.draw(700, 250, 43, 120);
    deadTree.draw(400, 300, 43, 120);
    deadTree.draw(650, 100, 26, 72);

    for(int i = 0; i < 6; i++){

        smallTree.draw(140 + i * 80, n * (3 + i), 27, 23);
        mediumTree.draw(120 + i * 100, 0, 17, 28);
        mediumTree.draw(160 + i * 100, 0, 17, 28);
        mediumTree.draw(200 + i * 100, 0, 17, 28);
        mediumTree.draw(240 + i * 100, 20, 17, 28);
        mediumTree.draw(120 + i * 100, 30, 17, 28);
        mediumTree.draw(200 + i * 100, 30, 17, 28);
        mediumTree.draw(150 + i * 100, n * i, 34.5, 56);
        mediumTree.draw(150 + i * 100, n * (2 + i), 17, 28);
        mediumTree.draw(135 + i * 100, n * (4 + i), 17, 28);
        mediumTree.draw(200 + i * 100, n, 34.5, 56);
        mediumTree.draw(200 + i * 100, n + 70, 51, 84);
        mediumTree.draw(200 + i * 100, n + 175, 59, 95);
        mediumTree.draw(200 + i * 100, n + 293.75);
    }
    
    bigTree2.draw(250, 50, 47, 107);
    bigTree2.draw(450, 50, 47, 107);
    bigTree2.draw(350, 150, 71, 161);
    bigTree2.draw(550, 200, 76, 172);
    bigTree2.draw(160, 220, 76, 172);
    bigTree.draw(400, 125, 150, 127);

    }
    else if(State::level == 3) floor.draw(0,0, ofGetWidth(), ofGetHeight());

    player->render();
    entityManager->render();
    ofSetColor(0, 100, 0);
    if(State::level == 2) ofSetColor(0,0,0);
    string moneyStr = "money: " + to_string(money);
    font1.drawString(moneyStr , ofGetWidth()/2 - font1.stringWidth(moneyStr)/2, font1.stringHeight(moneyStr) +2);
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
