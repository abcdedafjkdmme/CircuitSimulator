#pragma once
#include <stdio.h>
#include <SDL.h>
#include <GameObjectManager.h>
#include <memory>
//class GameObjectManager;

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
};

