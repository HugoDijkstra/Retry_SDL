#pragma once

#include <SDL2\SDL.h>
#include <SDL_image.h>
#include <string>
#include <iostream>

class __declspec(dllexport) Image
{
public:
	Image();
	Image(SDL_Renderer* renderer, std::string path);
	virtual ~Image();
	SDL_Texture* getTexture() { return texture; };
protected:
	Uint32 format;
	int w, h;
	SDL_Texture* texture;
};