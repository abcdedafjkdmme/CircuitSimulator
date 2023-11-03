#pragma once

#include <GameObject.h>
#include <GameObjectManager.h>
#include <RenderManager.h>
#include "UserArduino.h"
#include <DCMotor.h>

class RootGameObject :public GameObject
{
protected:
	GameObjectManager& Manager = GameObjectManager::getInstance();
	RenderManager& RManager = RenderManager::getInstance();
protected:
	std::unique_ptr<UserArduino> NewArduino = std::make_unique<UserArduino>();
	std::unique_ptr<DCMotor> NewMotor= std::make_unique<DCMotor>();
public:
	RootGameObject();
protected:
	void Tick(double DeltaTime) override;
};

