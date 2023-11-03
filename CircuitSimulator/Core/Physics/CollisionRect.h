#pragma once
#include <Vector2.h>
#include <Rect.h>
#include <RenderManager.h>
#include <stdio.h>
#include <IMoveable.h>

class CollisionRect:public IMoveable
{
public:
	CollisionRect(Vector2 _WorldPosition, Vector2 _Size, bool _DebugEnabled) : WorldPosition(_WorldPosition), Size(_Size), DebugEnabled(_DebugEnabled) {
		DebugRect.IsEnabled = _DebugEnabled;
		DebugRect.WorldPosition = _WorldPosition;
		DebugRect.Size = _Size;
		DebugRect.ZIndex = 1000;
	};

	Vector2 WorldPosition;
	Vector2 Size;
	void SetWorldPosition(Vector2 WorldPos);
	Vector2 GetWorldPosition();

	bool DebugEnabled;
	RenderedRect DebugRect{};
	bool CollidingWithPoint(Vector2 Point);

	
	
	
};

