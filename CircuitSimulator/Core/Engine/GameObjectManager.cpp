#include "GameObjectManager.h"
#include <GameObject.h>
#include <Bulb.h>
#include <memory>
#include <stdio.h>


void GameObjectManager::RegisterGameObject(GameObject& GameObj)
{
	
	GameObjects.push_back(GameObj);
	
}

void GameObjectManager::UnregisterGameObject(GameObject& GameObj)
{
	
	GameObjects.erase(std::remove(GameObjects.begin(), GameObjects.end(), GameObj), GameObjects.end());

}



void GameObjectManager::TickAllGameObjects(double DeltaTime)
{
	for (size_t i = 0; i < GameObjects.size(); i++)
	{
		GameObjects[i].get().Tick(DeltaTime);
	}
	/*for (std::unique_ptr<GameObject> Obj : GameObjects)
	{
		Obj->Tick(DeltaTime);
	}*/
}

void GameObjectManager::SendInputToAllGameObject(SDL_Event& InputEvent)
{
	for (size_t i = 0; i < GameObjects.size(); i++)
	{
		GameObjects[i].get().Input(InputEvent);
	}
	/*for (std::unique_ptr<GameObject> Obj : GameObjects)
	{
		Obj->Input(InputEvent);
	}*/
}


