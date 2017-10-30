#include "../include/util.h"

#define DEBUG true
SDL_Rect util::Vector2ToRect(Vector2 position, Vector2 scale)
{
	SDL_Rect rect;
	rect.x = position.x;
	rect.y = position.y;
	rect.w = scale.x;
	rect.h = scale.y;

	return rect;
}

SDL_Point util::Vector2ToPoint(Vector2 point)
{
	SDL_Point p;
	p.x = point.x;
	p.y = point.y;
	return p;
}

std::vector<std::string> util::splitString(std::string string, char at)
{
	std::vector<std::string> strings;
	std::string curString = "";
	for (int i = 0; i < string.length(); i++)
	{
		if (string[i] != at)
		{
			if (string[i] != ' ')
			{
				curString += string[i];
			}
			else
			{
				continue;
			}
		}
		else
		{
			strings.push_back(curString);
			curString = "";
		}
	}
	strings.push_back(curString);
	return strings;
}
