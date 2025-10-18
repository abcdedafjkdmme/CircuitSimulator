#pragma once
#include <stdio.h>
//#include <GameObjectManager.h>
#include <SDL.h>
#include <memory>
#include <vector>

class GameObjectManager;

class GameObject
{
	friend class GameObjectManager;
public:
	 GameObject();
	virtual ~GameObject();

public:

	virtual void Tick(double DeltaTime) {  };
	virtual void Input(SDL_Event& InputEvent) {};
	
	friend bool operator==(const GameObject& v1, const GameObject& v2)
	{
		return &v1 == &v2;
	}
public:
	GameObject* Parent{ nullptr };

	std::vector<GameObject*> Children;

	void AddChild(GameObject& Obj);

	template<typename T>
	T* GetChildByClass() {
		for (auto* Child : Children)
		{

			T* CastedChild = dynamic_cast<T*>(Child);
			if (CastedChild)
			{
				return CastedChild;
			}
		}
		return nullptr;
	}
};

