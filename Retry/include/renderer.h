#pragma once

#include <iostream>
#include <vector>
#include <SDL2\SDL.h>
#include <SDL_image.h>
#include "resourceManager.h"
#include "vector2.h"
#include "entity.h"
#include "scene.h"

class __declspec(dllexport) Renderer
{
public:
	static Renderer* GetInstance();
	static void Destroy();

		static void RenderScene(Scene* scene) {
		GetInstance()->renderScene(scene);
	}
	static void ChangeResolution(int height, int widht);

	static void RenderImage(SDL_Texture * tex, Vector2 pos, Vector2 scale) {
		GetInstance()->renderImage(tex, pos, scale);
	}
	static void RenderImage(SDL_Texture * tex, Vector2 pos, Vector2 scale, Vector2 partPos, Vector2 partSize) {
		GetInstance()->renderImage(tex, pos, scale, partPos, partSize);
	}
	static void ChangeBuffer() { GetInstance()->changeBuffer(); }
	static double GetDeltaTime() { return GetInstance()->getDeltaTime(); }

private:
	static Renderer* instance;
	static int h;
	static int w;

	void changeBuffer();
	void renderScene(Scene* scene);
	void renderEntity(Entity * entity);
	void renderImage(SDL_Texture * tex, Vector2 pos, Vector2 scale);
	void renderImage(SDL_Texture * tex, SDL_Color * color, Vector2 pos, Vector2 scale);
	void renderImage(SDL_Texture * tex, Vector2 pos, Vector2 scale, Vector2 partPos, Vector2 partSize);
	void renderImage(SDL_Texture * tex, SDL_Color * color, Vector2 pos, Vector2 scale, Vector2 partPos, Vector2 partSize);
	void calculateDeltaTime();
	double getDeltaTime() { return deltaTime; }
	SDL_Renderer* getRenderer() { return renderer; };


	double deltaTime;
	double lastTime;
	SDL_Window* window;
	SDL_Renderer* renderer;
	Renderer();
	~Renderer();

};

