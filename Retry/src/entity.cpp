#include "..\include\entity.h"

int Entity::entityIDCounter = 0;

Entity::Entity()
{
	position = Vector2(0, 0);
	entityID = entityIDCounter++;
	SetColor(255, 255, 255, 255);
	texturePath = "";
	rotation = 0;
	parent = NULL;
}

Entity::Entity(Vector2 position, Vector2 size) : Entity()
{
	parent = NULL;
	this->position = position;
	this->Size = size;
	texturePath = "";
	SetColor(255, 255, 255, 255);
}

Entity::Entity(Vector2 position, Vector2 size, std::string path) : Entity()
{
	parent = NULL;
	this->position = position;
	this->Size = size;
	this->texturePath = path;
	SetColor(255, 255, 255, 255);
}

Entity::~Entity()
{
	std::vector<Entity*>::iterator it = children.begin();
	while (it != children.end())
	{
		Entity* e = (*it);
		it = children.erase(it);
		delete e;
		e = NULL;
	}
}

void Entity::Update(double DeltaTime)
{
	updateChildren(DeltaTime);
}

bool Entity::CheckCollision(SDL_Rect * with, SDL_Rect* result)
{
	return (SDL_IntersectRect(&util::Vector2ToRect(getParentPosition(), Size), with, result));
}

void Entity::AddChild(Entity* entity)
{
	if (entity->parent != NULL)
	{
		if (entity->parent == this)
		{
			std::cout << this->entityID << " is trying to adopt " << entity->entityID << std::endl;
			return;
		}
		else
		{
			entity->parent->RemoveChild(entity);
		}
	}
	children.push_back(entity);
	entity->parent = this;
}

void Entity::RemoveChild(Entity* entity)
{
	std::vector<Entity*>::iterator it = children.begin();
	while (it != children.end())
	{
		if ((*it) == entity)
		{
			entity->parent = NULL;
			children.erase(it);
		}
	}
}

Vector2 Entity::getParentPosition()
{
	if (parent == NULL)
	{
		return position;
	}
	return position + parent->getParentPosition();
}

void Entity::updateChildren(double DeltaTime)
{
	std::vector<Entity*>::iterator it = children.begin();
	while (it != children.end())
	{
		if ((*it) != NULL)
		{
			(*it)->Update(DeltaTime);
			it++;
		}
		else
		{
			it = children.erase(it);
		}
	}
}

void Entity::SetColor(int r, int g, int b, int a)
{
	color.r = r;
	color.g = g;
	color.b = b;
	color.a = a;
}

SDL_Rect Entity::EntityRect()
{
	return util::Vector2ToRect(getParentPosition(),Size);
}
