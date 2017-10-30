#include "..\Headers\Wall.h"

Wall::Wall() : Tile()
{
	walkable = false;
	texturePath = "Sprites/wood.png";
}

Wall::~Wall()
{

}

void Wall::Update(double DeltaTime)
{
}
