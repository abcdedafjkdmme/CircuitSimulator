#pragma once

#pragma once
#include <SDL.h>
#include "GameObjectManager.h"
#include "RenderManager.h"

class Application
{
	
protected:
	GameObjectManager& ObjectManager = GameObjectManager::getInstance();
	RenderManager& RManager = RenderManager::getInstance();

protected:
	SDL_Event Event{};
	bool IsApplicationRunning = true;
	//deltat time calculatorio 
	Uint64 CurrentTime = 0;
	Uint64 LastTime = 0;
	double DeltaTime = 0;
	int32_t tickInteval = 1000 / 60;


public:
	bool init();
	int Run();
protected:	
	virtual void SDLEventLoop();
	virtual void GameLoop();
	virtual void close();

	
};

