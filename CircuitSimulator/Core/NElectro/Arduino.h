#pragma once
#include <vector>
#include <GameObject.h>
#include <Pin.h>
#include <RenderManager.h>
#include <WImage.h>
#include <IMoveable.h>


namespace VoltValues {
	const int HIGH = 5;
	const int LOW = 0;
}
enum PinState {
	INPUT,
	OUTPUT
};

class Arduino :public GameObject, public IMoveable
{
public:
	Arduino();
	float DigitalRead(int PIN);
	void DigitalWrite(int PIN, float Value);
	void SetPinMode(int PIN, PinState State);

public:
	const int AmountOfPins = 20;
	//std::vector<Pin> Pins{};
	std::vector<std::unique_ptr<Pin>> Pins{};
	const int LEDBuiltIn = 13;

protected:
	void Tick(double DeltaTime) override;
	
//protected:
//	RenderManager& RManager = RenderManager::getInstance();
public:
	std::unique_ptr<WImage> Image = std::make_unique<WImage>();
public:
	void SetWorldPosition(Vector2 WorldPos);
	Vector2 GetWorldPosition();
	
};

