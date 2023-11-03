#include "Rect.h"
#include <stdio.h>
#include <RenderingUtils.h>
#include <RenderManager.h>

void RenderedRect::Render(Camera& Cam)
{
	if (!IsEnabled) {
		return;
	}

	SDL_Rect RenderRect = RenderingUtils::WorldToScreen(Scale, Cam, WorldPosition, Size);
	RenderManager& RManager = RenderManager::getInstance();
	SDL_SetRenderDrawColor(mRenderer, Color.r, Color.g, Color.b, Color.a);
	SDL_RenderDrawRect(mRenderer, &RenderRect);
	SDL_SetRenderDrawColor(mRenderer,RManager.BACKGROUND_COLOR.r, RManager.BACKGROUND_COLOR.g, RManager.BACKGROUND_COLOR.b, RManager.BACKGROUND_COLOR.a);
}
