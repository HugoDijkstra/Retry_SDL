#include "../include/renderer.h"

Renderer* Renderer::instance = NULL;
int Renderer::w = 640;
int Renderer::h = 480;

Renderer * Renderer::GetInstance()
{
	if (instance == NULL)
	{
		instance = new Renderer();
	}
	return instance;
}

void Renderer::Destroy()
{
	delete instance;
}

Renderer::Renderer()
{
	lastTime = 0;
	deltaTime = 0;
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		std::cout << "SDL2 could not be initiated: " << SDL_GetError() << std::endl;
		exit(-1);
	}
	if (IMG_Init(IMG_INIT_PNG) == 0)
	{
		std::cout << "SDL2_IMG could not be initiated: " << IMG_GetError() << std::endl;
		SDL_Quit();
		exit(-2);
	}
	window = SDL_CreateWindow("Retry engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480,NULL);
	if (window == NULL)
	{
		std::cout << "Window could not be created: " << SDL_GetError() << std::endl;
		SDL_Quit();
		exit(-2);
	}
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
	if (renderer == NULL)
	{
		std::cout << "renderer could not be created: " << SDL_GetError() << std::endl;
		SDL_DestroyWindow(window);
		SDL_Quit();
		exit(-3);
	}
	std::cout << "--- Created Renderer ---" << std::endl;

	ResourceManager::GetInstance()->renderer = getRenderer();
}

Renderer::~Renderer()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	IMG_Quit();
	std::cout << "--- Destroyed Renderer ---" << std::endl;

}




void Renderer::renderImage(SDL_Texture * tex, Vector2 pos, Vector2 scale)
{
	SDL_Rect rect;

	rect.x = pos.x;
	rect.y = pos.y;
	rect.h = scale.y;
	rect.w = scale.x;

	SDL_RenderCopyEx(renderer, tex, NULL, &rect, 0, NULL, SDL_FLIP_NONE);
}

void Renderer::renderImage(SDL_Texture * tex, SDL_Color* color, Vector2 pos, Vector2 scale)
{
	SDL_Rect rect;

	rect.x = pos.x;
	rect.y = pos.y;
	rect.h = scale.y;
	rect.w = scale.x;

	SDL_SetTextureColorMod(tex, color->r, color->g, color->b);
	SDL_SetTextureAlphaMod(tex, color->a);

	SDL_RenderCopyEx(renderer, tex, NULL, &rect, 0, NULL, SDL_FLIP_NONE);
}


void Renderer::renderImage(SDL_Texture* tex, Vector2 pos, Vector2 scale, Vector2 partPos, Vector2 partSize)
{
	SDL_Rect rect;
	SDL_Rect Srect;

	rect.x = pos.x;
	rect.y = pos.y;
	rect.h = scale.y;
	rect.w = scale.x;

	Srect.x = partPos.x;
	Srect.y = partPos.y;
	Srect.h = partSize.y;
	Srect.w = partSize.x;

	SDL_SetTextureColorMod(tex, 255, 255, 255);
	SDL_SetTextureAlphaMod(tex, 255);
	SDL_RenderCopyEx(renderer, tex, &Srect, &rect, 0, NULL, SDL_FLIP_NONE);
}

void Renderer::renderImage(SDL_Texture* tex, SDL_Color* color, Vector2 pos, Vector2 scale, Vector2 partPos, Vector2 partSize)
{
	SDL_Rect rect;
	SDL_Rect Srect;

	rect.x = pos.x;
	rect.y = pos.y;
	rect.h = scale.y;
	rect.w = scale.x;

	Srect.x = partPos.x;
	Srect.y = partPos.y;
	Srect.h = partSize.y;
	Srect.w = partSize.x;

	SDL_SetTextureColorMod(tex, color->r, color->g, color->b);
	SDL_SetTextureAlphaMod(tex, color->a);
	SDL_RenderCopyEx(renderer, tex, &Srect, &rect, 0, NULL, SDL_FLIP_NONE);
}

void Renderer::changeBuffer()
{
	SDL_RenderPresent(renderer);
	SDL_RenderClear(renderer);
	calculateDeltaTime();
}

void Renderer::renderScene(Scene* scene)
{
	std::vector<Entity*>::iterator it = scene->getEntities()->begin();
	while (it != scene->getEntities()->end())
	{
		Entity* et = (*it);
		renderEntity(et);
		it++;
	}
}

void Renderer::renderEntity(Entity* entity)
{

	SDL_Rect rect;
	if (entity->texturePath != "") {
		Vector2 pos = entity->getParentPosition();

		rect.x = pos.x;
		rect.y = pos.y;
		rect.h = entity->Size.y;
		rect.w = entity->Size.x;
		SDL_Color *color = entity->getColor();
		SDL_Texture* tex = ResourceManager::GetImage(entity->texturePath)->getTexture();
		SDL_SetTextureColorMod(tex, color->r, color->g, color->b);
		SDL_SetTextureAlphaMod(tex, color->a);
//		std::cout << pos << std::endl;
		if (entity->parent != NULL)
			SDL_RenderCopyEx(renderer, tex, NULL, &rect, entity->rotation, NULL, SDL_FLIP_NONE);
		else
			SDL_RenderCopyEx(renderer, tex, NULL, &rect, entity->rotation, NULL, SDL_FLIP_NONE);
	}

	std::vector<Entity*>::iterator it = entity->children.begin();
	while (it != entity->children.end())
	{
		renderEntity((*it));
		it++;
	}
}

void Renderer::calculateDeltaTime()
{
	double timeNow = SDL_GetTicks();
	deltaTime = (timeNow - lastTime) / 1000.0;
	lastTime = timeNow;
}

void Renderer::ChangeResolution(int height, int widht)
{
	Renderer::w = widht;
	Renderer::h = height;
	SDL_SetWindowSize(GetInstance()->window, w, h);
}
