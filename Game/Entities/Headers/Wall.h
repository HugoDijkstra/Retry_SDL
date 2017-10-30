#pragma once

#include "Tile.h"

class Wall : public Tile
{
public:
	Wall();
	virtual ~Wall();
	void Update(double DeltaTime);
private:

};