#pragma once

#include <entity.h>
#include "Room.h"
class Player : public Entity
{
public:
	Player();
	virtual ~Player();

	void Update(double DeltaTime);

	Room* currentRoom;
private:
};