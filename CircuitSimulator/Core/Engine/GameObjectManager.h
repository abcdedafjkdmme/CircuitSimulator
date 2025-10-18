#pragma once
#include <vector>
#include <memory>
#include <stdio.h>
#include <GameObject.h>
#include <SDL.h>

class Application;

class GameObjectManager
{
	friend class GameObject;
	friend class Application;

public:
	static GameObjectManager& getInstance() {
		static GameObjectManager   instance; // Guaranteed to be destroyed.
		// Instantiated on first use.
		return instance;
	}
protected:
	std::vector<std::reference_wrapper<GameObject>> GameObjects;
public:
	void RegisterGameObject(GameObject& GameObj);
	void UnregisterGameObject(GameObject& GameObj);

	/*template <typename T>
	T* AddGameObject() {
		T* ObjToAdd = new T();
		RegisterGameObject(*(static_cast<GameObject*>(ObjToAdd)));
		return ObjToAdd;
	};

	void RemoveGameObject(GameObject* ObjToRemove) {
		UnregisterGameObject(*ObjToRemove);
		delete ObjToRemove;
	};*/

protected:
	void TickAllGameObjects(double DeltaTime);
	void SendInputToAllGameObject(SDL_Event& InputEvent);


};

