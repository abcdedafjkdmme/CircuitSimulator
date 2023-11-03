#pragma once
#include <Vector2.h>

class IMoveable {
	virtual void SetWorldPosition(Vector2 WorldPos) = 0;
	virtual Vector2 GetWorldPosition() = 0;
};