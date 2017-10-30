#pragma once

#include <entity.h>

class Tile : public Entity
{
public:
	Tile();
	virtual ~Tile();

	bool walkable;
};