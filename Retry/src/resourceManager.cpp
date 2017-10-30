#include "../include/resourceManager.h"

ResourceManager* ResourceManager::instance = NULL;

ResourceManager::ResourceManager()
{
	std::cout << "--- Created ResourceManager ---" << std::endl;
}

ResourceManager::~ResourceManager()
{
	std::map<std::string, Image*>::iterator it = imageBlob.begin();
	while (it != imageBlob.end()) {
		delete it->second;
		it = imageBlob.erase(it);
	}
	std::cout << "--- Destroyed ResourceManager ---" << std::endl;
	imageBlob.clear();
}

ResourceManager * ResourceManager::GetInstance()
{
	if (instance == NULL)
	{
		instance = new ResourceManager();
	}
	return instance;
}

void ResourceManager::Destroy()
{
	delete instance;
}

Image * ResourceManager::getImage(std::string path)
{
	std::map<std::string, Image*>::iterator it = imageBlob.find(path);
	while (it == imageBlob.end())
	{
		Image* image = new Image(renderer, path);
		imageBlob.emplace(path, image);
		std::cout << "Image added: " << path << std::endl;
		return image;
	}
	return it->second;
}

void ResourceManager::removeImage(std::string path)
{
	std::map<std::string, Image*>::iterator it = imageBlob.find(path);
	while (it != imageBlob.end())
	{
		Image* image = it->second;
		imageBlob.erase(path);

		delete image;
		return;
	}
	std::cout << path << ": not found." << std::endl;
}
