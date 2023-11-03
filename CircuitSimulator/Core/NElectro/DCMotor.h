#pragma once
#include "GameObject.h"
#include <WImage.h>
#include <Pin.h>

class DCMotor :public GameObject, public IMoveable
{

	std::unique_ptr<WImage> BackgroundImage = std::make_unique<WImage>();
	std::unique_ptr<WImage> CogWheelImage = std::make_unique<WImage>();
public:
	std::unique_ptr<Pin> InPin = std::make_unique<Pin>();
	double RPM{ 10 };
public:
	DCMotor();
private:
	void Tick(double DeltaTime) override;
public:
	void SetWorldPosition(Vector2 WorldPos) override;
	Vector2 GetWorldPosition() override;
	
};

