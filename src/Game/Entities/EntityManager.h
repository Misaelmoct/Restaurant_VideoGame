#pragma once

#include "Entity.h"
#include "Client.h"
#include "Inspector.h"

class EntityManager {

public:
	Client* firstClient;
	Inspector* inspector;
	void tick();
	void render();
	void addEntity(Entity *e);
	void addClient(Client *c);
	void removeLeavingClients();
	std::vector<Entity*> entities;
	bool getLose(){return firstClient->getLost();}
	void resetCount(){firstClient->resetCount();}

};