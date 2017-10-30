#include "..\include\scene.h"

Scene::Scene()
{
}

Scene::~Scene()
{
	std::vector<Entity*>::iterator it = entities.begin();
	while (it != entities.end())
	{
		Entity* e = (*it);
		std::cout << e << std::endl;
		it = entities.erase(it);
		if (e != NULL)
			if (e->parent == NULL)
				delete e;
	}
}

void Scene::addEntity(Entity * entity)
{
	entities.push_back(entity);
}

void Scene::removeEntity(Entity * entity)
{
	std::vector<Entity*>::iterator it = entities.begin();
	while (it != entities.end())
	{
		if ((*it) == entity)
		{
			entities.erase(it);
			return;
		}
		it++;
	}
}


void Scene::update(float DeltaTime)
{
	std::vector<Entity*>::iterator it = entities.begin();
	while (it != entities.end())
	{
		(*it)->Update(DeltaTime);
		it++;
	}
}
