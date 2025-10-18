#include "RenderedObject.h"
#include <RenderManager.h>
#include <iostream>

//SDL_Rect RenderedObject::WorldToScreen(SDL_Rect Rect, Vector2 RectScale, Camera Cam)
//{
//	int RectX = ((int)((float)((Rect.x - Cam.WorldPosition.X) * Cam.Scale.Y) + Cam.Size.X / 2));
//	int RectY = ((int)((float)((Rect.y - Cam.WorldPosition.Y) * Cam.Scale.Y) + Cam.Size.Y / 2));
//	int RectW = (int)((float)Rect.w * RectScale.X * Cam.Scale.X);
//	int RectH = (int)((float)Rect.h * RectScale.Y * Cam.Scale.Y);
//
//	return SDL_Rect{ RectX,RectY,RectW,RectH};
//}

//SDL_Rect RenderedObject::WorldToScreen(Vector2 RectScale, Camera Cam, Vector2 WorldPosition, Vector2 Size)
//{
//	Vector2 RectPosOnScreen = WorldToScreen(Vector2(WorldPosition.X,WorldPosition.Y), Cam);
//	int RectX = (int)((RectPosOnScreen.X)+Cam.Size.X/2.0);
//	int RectY = (int)((RectPosOnScreen.Y) + Cam.Size.Y / 2.0);
//	int RectW = (int)(Size.X* RectScale.X * Cam.Scale.X);
//	int RectH = (int)(Size.Y* RectScale.Y* Cam.Scale.Y);
//
//	return SDL_Rect{ RectX,RectY,RectW,RectH };
//}

//Vector2 RenderedObject::GetTopLeftWorldPosition(Vector2 WorldPos, Vector2 PivotRelToWorld, Vector2 Scale)
//{
//	return Vector2((WorldPos - PivotRelToWorld).X* Scale.X, (WorldPos - PivotRelToWorld).Y * Scale.Y);
//}
//	

//Vector2 RenderedObject::WorldToScreen(Vector2 Vec, Camera Cam)
//{
//	return Vector2 ((Vec -(Cam.WorldPosition - Cam.PivotRelativeToWorldPosition))*Cam.Scale);
//}

RenderedObject::RenderedObject()
{
	RenderManager& RManager = RenderManager::getInstance();
	RManager.RegisterRenderedObject(*this);
	mRenderer = RManager.gRenderer;
	AddChild(Transform);
	
}

RenderedObject::~RenderedObject()
{
	RenderManager& RManager = RenderManager::getInstance();
	RManager.UnregisterRenderedObject(*this);
}
