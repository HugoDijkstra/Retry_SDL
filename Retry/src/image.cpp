#include "..\include\image.h"

Image::Image()
{
}

Image::Image(SDL_Renderer* renderer, std::string path)
{
	SDL_Surface* surface = IMG_Load(path.c_str());
	if (surface == NULL)
	{
		std::cout << "Image could not be loaded: " << IMG_GetError() << std::endl;
		return;
	}
	this->texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
	SDL_QueryTexture(texture, &format, NULL, &w, &h);

	std::cout << "Sprite loaded: " << w << "x" << h << " : " << format << " : " << path << std::endl;
}

Image::~Image()
{
	SDL_DestroyTexture(texture);
}
