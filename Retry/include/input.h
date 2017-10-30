#pragma once

#include <SDL2\SDL.h>
#include "vector2.h"

class __declspec(dllexport) Input
{
public:
	static Input* GetInstance();
	

	static bool GetKey(int keyCode) {
		return GetInstance()->getKey(keyCode);
	}
	static bool GetKeyUp(int keyCode) {
		return GetInstance()->getKeyUp(keyCode);
	}
	static bool GetKeyDown(int keyCode) {
		return GetInstance()->getKeyDown(keyCode);
	}
	static bool GetMouseButton(int number) {
		return GetInstance()->getMouseButton(number);
	}
	static bool GetMouseButtonDown(int number)
	{
		return GetInstance()->getMouseButtonDown(number);
	}
	static bool GetMouseButtonUp(int number)
	{
		return GetInstance()->getMouseButtonUp(number);
	}
	static bool GetMustQuit() { return GetInstance()->mustquit; };

	static void Update() { GetInstance()->update(); }
private:
	static Input* instance;

	Input();
	~Input();

	void update();
	bool getKey(int keyCode);
	bool getKeyUp(int keyCode);
	bool getKeyDown(int keyCode);

	bool getMouseButton(int number);
	bool getMouseButtonDown(int number);
	bool getMouseButtonUp(int number);

	Vector2 getMouseToScreen();



	bool keys[282];
	bool keysUp[282];
	bool keysDown[282];

	bool keysalreadyUp[282];
	bool keysalreadyDown[282];

	bool mouseButton[20];
	bool mouseButtonUp[20];
	bool mouseButtonDown[20];

	bool mouseButtonAlreadyUp[20];
	bool mouseButtonAlreadyDown[20];

	bool mustquit = false;

	Vector2 mousePos;
};