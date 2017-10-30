#pragma once

#include <map>
#include "entity.h"
#include "input.h"

class __declspec(dllexport) Scene
{
public:
	Scene();
	virtual ~Scene();

	void addEntity(Entity* entity);
	void removeEntity(Entity* entity);
	void update(float DeltaTime);
	std::vector<Entity*>* getEntities() { return &entities; }
private:
	std::vector<Entity*> entities;
};