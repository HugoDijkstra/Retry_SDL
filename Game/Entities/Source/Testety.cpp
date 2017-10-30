#include "../Headers/Testety.h"

Testity::Testity() : Entity()
{

}

Testity::Testity(Vector2 position, Vector2 size) : Entity(position, size)
{
}

Testity::Testity(Vector2 position, Vector2 size, std::string path) : Entity(position, size, path)
{
}

Testity::~Testity()
{
}

void Testity::Update(double DeltaTime)
{
	rotation += 100.0f * DeltaTime;
}
