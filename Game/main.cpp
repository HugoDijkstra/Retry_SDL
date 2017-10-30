#include <renderer.h>
#include <image.h>
#include <resourceManager.h>
#include "Entities\Headers\Player.h"
#include "Entities\Headers\Testety.h"
#include "Entities\Headers\Room.h"
//#undef main


int main(int argc, char *argv[])
{
	bool quit = false;
	Scene* scene = new Scene();
	Player* entity0 = new Player();
	Testity* entity1 = new Testity(Vector2(20, 0), Vector2(20, 20), "Sprites/wood.png");
	entity0->SetColor(255, 18, 13, 255);
	scene->addEntity(entity0);
	entity0->AddChild(entity1);
	std::string roomstr =	
		"3,3[0,0,0,"
		"0,1,0,"
		"0,0,0,";
	Room* room = new Room(roomstr);
	scene->addEntity(room);
	std::cout << room->children.size() << std::endl;
	entity0->currentRoom = room;
	while (!Input::GetMustQuit())
	{
		Input::Update();
		scene->update(Renderer::GetDeltaTime());
		Renderer::RenderScene(scene);
		Renderer::ChangeBuffer();
		SDL_Event e;
	}
	ResourceManager::Destroy();
	Renderer::Destroy();
	delete scene;

	return 0;
}