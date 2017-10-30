#pragma once

#include "util.h"
#include "input.h"
#include "vector2.h"
#include <vector>
#include <iostream>

class __declspec(dllexport) Entity
{
public:
	Entity();
	Entity(Vector2 position, Vector2 size);
	Entity(Vector2 position, Vector2 size, std::string path);
	virtual ~Entity();
	Vector2 position;
	Vector2 Size;
	double rotation;
	std::string texturePath;

	void updateChildren(double DeltaTime);
	virtual void Update(double DeltaTime);
	bool CheckCollision(SDL_Rect * with, SDL_Rect * result);
	int EntityID() { return entityID; }
	void AddChild(Entity * entity);
	void RemoveChild(Entity * entity);
	Vector2 getParentPosition();
	SDL_Color* getColor() { return &color; }
	void SetColor(int r, int g, int b, int a);

	SDL_Rect EntityRect();

	Entity* parent;
	std::vector<Entity*> children;
private:

	SDL_Color color;
	int entityID;
	static int entityIDCounter;

};