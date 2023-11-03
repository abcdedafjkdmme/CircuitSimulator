#pragma once
#include <Vector2.h>
#include <RenderingUtils.h>
#include <RenderManager.h>

namespace ApplicationStatics {
	static Vector2 GetMouseWorldPosition()
	{

		int MouseX;
		int MouseY;
		SDL_GetMouseState(&MouseX, &MouseY);
		auto Camera = RenderManager::getInstance().ActiveCamera;
		return RenderingUtils::ScreenToWorld(Vector2(MouseX, MouseY), Camera);
	}
}
