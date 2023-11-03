#include "Pin.h"

void Pin::SetWorldPosition(Vector2 WorldPos)
{
	WorldPosition = WorldPos;
}

Vector2 Pin::GetWorldPosition()
{
	return WorldPosition;
}

Pin::~Pin()
{
	
}
