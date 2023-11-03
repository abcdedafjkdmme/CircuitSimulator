#pragma once
#include <vector>
#include <GameObject.h>
#include <IMoveable.h>
#include <Vector2.h>

class Wire;

class Pin: public GameObject, public IMoveable
{

public:
	enum ImpendanceStates {
		HIGH,
		LOW
	};
	ImpendanceStates ImpendanceState{ ImpendanceStates::LOW };
	float Volt = { 0.0 };
		
public:
	Vector2 WorldPosition{ 0.0,0.0 };
	void SetWorldPosition(Vector2 WorldPos) override;
	Vector2 GetWorldPosition() override;
public:
	~Pin() override;
		
};

