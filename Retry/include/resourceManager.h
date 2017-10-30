#pragma once

#include "image.h"
#include <map>
#include <string>
#include "renderer.h"

class __declspec(dllexport) ResourceManager
{
public:
	static ResourceManager* GetInstance();
	static void Destroy();
	static Image* GetImage(std::string path) { return GetInstance()->getImage(path); }
	static void RemoveImage(std::string path) { GetInstance()->removeImage(path); }

	SDL_Renderer* renderer;
private:

	static ResourceManager* instance;
	ResourceManager();
	virtual ~ResourceManager();
	Image* getImage(std::string path);
	void removeImage(std::string path);

	std::map<std::string, Image*> imageBlob;

};