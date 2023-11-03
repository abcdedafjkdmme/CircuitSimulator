#include <GameObject.h>
//#include "GameObjectManager.h"
#include <stdio.h>
//#include "Singleton.cc"

GameObject::GameObject() {
	GameObjectManager::getInstance().RegisterGameObject(*this);
	//printf("game object consturected \n");
}

GameObject::~GameObject() {
	//printf("game object deleted \n");
	GameObjectManager::getInstance().UnregisterGameObject(*this);

	
}