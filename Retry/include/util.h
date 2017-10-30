#pragma once

#include "vector2.h"
#include <SDL2\SDL.h>
#include <string>
#include <vector>
namespace util
{
	__declspec(dllexport) SDL_Rect Vector2ToRect(Vector2 position, Vector2 scale);
	__declspec(dllexport) SDL_Point Vector2ToPoint(Vector2 point);
	__declspec(dllexport) std::vector<std::string> splitString(std::string string, char at);
}
