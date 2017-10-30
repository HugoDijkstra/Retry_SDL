#pragma once
#include <entity.h>

class Testity : public Entity
{
public:
	Testity();
	Testity(Vector2 position, Vector2 size);
	Testity(Vector2 position, Vector2 size, std::string path);
	virtual ~Testity();
	void Update(double DeltaTime);
protected:
};