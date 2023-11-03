#pragma once
#include <Vector2.h>
#include <SDL.h>
#include <Camera.h>

namespace RenderingUtils {

	static Vector2 WorldToScreen(Vector2 Vec, Camera Cam)
	{
		return Vector2((Vec - (Cam.WorldPosition - Cam.PivotRelativeToWorldPosition)) * Cam.Scale);
	}

	static SDL_Rect WorldToScreen(Vector2 RectScale, Camera Cam, Vector2 WorldPosition, Vector2 Size)
	{
		Vector2 RectPosOnScreen = WorldToScreen(Vector2(WorldPosition.X, WorldPosition.Y), Cam);
		int RectX = (int)((RectPosOnScreen.X) /*+ Cam.Size.X / 2.0*/);
		int RectY = (int)((RectPosOnScreen.Y) /*+ Cam.Size.Y / 2.0*/);
		int RectW = (int)(Size.X * RectScale.X * Cam.Scale.X);
		int RectH = (int)(Size.Y * RectScale.Y * Cam.Scale.Y);

		return SDL_Rect{ RectX,RectY,RectW,RectH };
	}

	static Vector2 ScreenToWorld(Vector2 Vec, Camera Cam)
	{
		return Vector2((Vec/Cam.Scale)+(Cam.WorldPosition-Cam.PivotRelativeToWorldPosition));
	}

	//Vector2 RenderedObject::GetTopLeftWorldPosition(Vector2 WorldPos, Vector2 PivotRelToWorld, Vector2 Scale)
	//{
	//	return Vector2((WorldPos - PivotRelToWorld).X* Scale.X, (WorldPos - PivotRelToWorld).Y * Scale.Y);
	//}
	//	

	
}