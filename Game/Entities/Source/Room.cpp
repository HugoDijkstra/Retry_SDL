#include "../Headers/Room.h"

Room::Room() : Entity()
{

}
Room::Room(std::string room) : Entity()
{
	std::vector< std::string> fullSplit = util::splitString(room, '[');
	std::vector<std::string> roomOptions = util::splitString(fullSplit[0], ',');
	std::vector<std::string> roomTiles = util::splitString(fullSplit[1], ',');
	roomSizeX = stoi(roomOptions[0]);
	roomSizeY = stoi(roomOptions[1]);
	int row = 0;
	int x = 0;
	for (int i = 0; i < (roomSizeX * roomSizeY) ; i++)
	{
		
		Wall* wall;
		Tile* tile;
		switch (stoi(roomTiles[i]))
		{
		case 1:
			wall = new Wall();
			wall->position = Vector2(x, row) * 30;
			tiles.push_back(wall);
			children.push_back(wall);
			break;
		case 0:
			tile = new Tile();
			tiles.push_back(tile);
			children.push_back(tile);
			break;
		default:
			std::cout << "tile: " << stoi(roomTiles[i]) << " unknown at " << i << std::endl;
			break;
		}
		x++;
		if (x == roomSizeX)
		{
			row++;
			x = 0;
		}

		
	}
}

Room::~Room()
{
}
