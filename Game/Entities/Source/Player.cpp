#include "..\Headers\Player.h"

Player::Player() : Entity()
{
	texturePath = "Sprites/pepe.png";
	Size = Vector2(30, 30);
}

Player::~Player()
{
}

void Player::Update(double DeltaTime)
{
	bool canWalkUp = true;
	bool canWalkDown = true;
	bool canWalkRight = true;
	bool canWalkLeft = true;

	if (currentRoom != NULL)
	{
		std::vector<Tile*>::iterator it = currentRoom->tiles.begin();
		while (it != currentRoom->tiles.end())
		{
			Tile* tile = (*it);
			if (!tile->walkable)
			{
				SDL_Rect result;
				Vector2 parentPos = getParentPosition();
				if (CheckCollision(&tile->EntityRect(), &result)) {
					std::cout << result.x << " : " << result.y << " | " << result.h << " : " << result.w << std::endl;
					if (result.x > parentPos.x)
						canWalkRight = false;
					if (result.x < parentPos.x)
						canWalkLeft = false;
					if (result.y > parentPos.y)
						canWalkDown = false;
					if (result.y < parentPos.y)
						canWalkUp = false;
				}
			}
			it++;
		}
	}

	Entity::Update(DeltaTime);
	if (Input::GetKey(SDLK_s))
	{
		if (canWalkDown)
			position += Vector2(0, 100.0f * DeltaTime);
	}
	else if (Input::GetKey(SDLK_w))
	{
		if (canWalkRight)
			position -= Vector2(0, 100.0f * DeltaTime);
	}

	if (Input::GetKey(SDLK_a))
	{
		if (canWalkLeft)
			position -= Vector2(100.0f* DeltaTime, 0);
	}
	else if (Input::GetKey(SDLK_d))
	{
		if (canWalkRight)
			position += Vector2(100.0f * DeltaTime, 0);
	}

}
