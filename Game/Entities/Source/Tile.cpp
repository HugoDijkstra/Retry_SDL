#include "..\Headers\Tile.h"

Tile::Tile() : Entity()
{
	Size = Vector2(30, 30);
	walkable = true;
	
}

Tile::~Tile()
{
}
