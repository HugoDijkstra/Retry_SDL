#pragma once

#include <entity.h>
#include "..\Headers\Tile.h"
#include "..\Headers\Wall.h"
#include <map>
#include <string>

class Room : public Entity
{
public:
	Room();
	Room(std::string room);
	virtual ~Room();
	int roomSizeX;
	int roomSizeY;

	std::vector<Tile*> tiles;
};