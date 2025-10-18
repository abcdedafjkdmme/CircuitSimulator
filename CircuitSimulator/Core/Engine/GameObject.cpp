#include <GameObject.h>
#include "GameObjectManager.h"
#include <stdio.h>

//#include "Singleton.cc"

GameObject::GameObject() {
	GameObjectManager::getInstance().RegisterGameObject(*this);
	//printf("game object consturected \n");
}

GameObject::~GameObject() {
	//printf("game object deleted \n");
	GameObjectManager::getInstance().UnregisterGameObject(*this);

	for (auto* Child : Children)
	{
		Child->Parent = nullptr;
	}
	
}

void GameObject::AddChild(GameObject& Obj)
{
	Children.push_back(&Obj);
	Obj.Parent = this;
}
