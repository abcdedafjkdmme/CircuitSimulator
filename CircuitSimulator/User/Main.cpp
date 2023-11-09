#include <Application.h>
#include "RootGameObject.h"
#include "SimulatorApplication.h"
//#include <WImage.h>
//#include <Vector2.h>
//#include <Dense>


int main(int argc, char* args[])
{
	
	SimulatorApplication App = SimulatorApplication();
	if (!App.init()) {
		return -1;
	}
	GameObjectManager& Manager = GameObjectManager::getInstance();
	//sandbox
	std::unique_ptr<RootGameObject> Root = std::make_unique<RootGameObject>();
	
	App.Run();
	return 0;
}
