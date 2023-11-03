#include "CollisionRect.h"

void CollisionRect::SetWorldPosition(Vector2 WorldPos)
{
	WorldPosition = WorldPos;
	DebugRect.WorldPosition = WorldPos;
}

Vector2 CollisionRect::GetWorldPosition()
{
	return WorldPosition;
}

bool CollisionRect::CollidingWithPoint(Vector2 Point)
{
	return (Point.X > WorldPosition.X && Point.X < WorldPosition.X + Size.X && Point.Y > WorldPosition.Y && Point.Y < WorldPosition.Y + Size.Y);
}
