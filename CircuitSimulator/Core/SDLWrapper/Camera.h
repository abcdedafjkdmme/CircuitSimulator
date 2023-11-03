#pragma once
#include "Vector2.h"


class Camera
{
public:
	Camera(Vector2 _WorldPosition, Vector2 _Scale, Vector2 _Size) :WorldPosition(_WorldPosition), Scale(_Scale), Size(_Size){};
	Vector2 WorldPosition;
	Vector2 Size;
	Vector2 PivotRelativeToWorldPosition{ Size / 2 };
	
	Vector2 Scale{ 1.0,1.0 };
};

