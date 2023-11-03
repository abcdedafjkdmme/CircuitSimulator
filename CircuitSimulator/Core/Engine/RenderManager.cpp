#include "RenderManager.h"
#include <algorithm> // for std::sort


void RenderManager::SortAllRenderObjectsByZIndex()
{
	std::sort(RenderedObjects.begin(), RenderedObjects.end(),
		[](auto a, auto b) { return a.get().ZIndex < b.get().ZIndex; });
}

void RenderManager::RegisterRenderedObject(RenderedObject& Obj)
{
	RenderedObjects.push_back(Obj);

}

void RenderManager::UnregisterRenderedObject(RenderedObject & Obj)
{

	RenderedObjects.erase(std::remove(RenderedObjects.begin(), RenderedObjects.end(), Obj), RenderedObjects.end());

}

bool RenderManager::Init()
{
	//Create window
	gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT,  SDL_WINDOW_RESIZABLE | SDL_WINDOW_MAXIMIZED);
	if (gWindow == NULL)
	{
		printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		return false;
	}

	//creater renderer
	gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
	if (gRenderer == NULL)
	{
		printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
		return false;
	}
	//Initialize renderer color
	SDL_SetRenderDrawColor(gRenderer, BACKGROUND_COLOR.r, BACKGROUND_COLOR.g , BACKGROUND_COLOR.b , BACKGROUND_COLOR.a);
	return true;
}



void RenderManager::RenderAllObjects(double DeltaTime)
{
	//Clear screen
	SDL_RenderClear(gRenderer);

	//sort for z index to wrok
	SortAllRenderObjectsByZIndex();
	//draw all rendered things
	for (auto Obj : RenderedObjects)
	{
		Obj.get().Render(ActiveCamera);
	}

	//Update screen
	SDL_RenderPresent(gRenderer);
	
}

void RenderManager::Quit()
{
	//Destroy window
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	//destory renderer
	SDL_DestroyRenderer(gRenderer);
	gRenderer = NULL;
}
