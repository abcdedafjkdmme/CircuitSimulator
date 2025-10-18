//Using SDL and standard IO
#include "Application.h"
#include <SDL.h>
#include <stdio.h>
#include <chrono>
#include <GameObject.h>
#include "GameObjectManager.h"
#include <SDL_image.h>
#include <RenderingUtils.h>





bool Application::init()
{


	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		
		("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		return false;
	}

	
	//Initialize PNG loading
	int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) & imgFlags))
	{
		printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
		return false;
	}

	if (!RManager.Init()) {
		printf("render manager coldnt be init");
		return false;
	}
	return true;


}

void Application::close()
{
	

	

	RManager.Quit();
	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();

	
}

void Application::SDLEventLoop()
{
	if (Event.type == SDL_QUIT) {
		IsApplicationRunning = false;
	}
	

	
	//printf("app");
}

void Application::GameLoop()
{
	
	while (SDL_PollEvent(&Event)) {
		ObjectManager.SendInputToAllGameObject(Event);
		SDLEventLoop();
	}

	
	CurrentTime = SDL_GetPerformanceCounter();
	DeltaTime = ((CurrentTime - LastTime) * 1000 * 0.001 / (double)SDL_GetPerformanceFrequency());

	ObjectManager.TickAllGameObjects(DeltaTime);
	RManager.RenderAllObjects(DeltaTime);

	int32_t timeToSleep = tickInteval - DeltaTime;
	if (timeToSleep > 0)
	{
		SDL_Delay(timeToSleep); // energy saving
	}

	LastTime = CurrentTime;
}

int Application::Run()
{
	
	CurrentTime = SDL_GetPerformanceCounter();
	
	while (IsApplicationRunning) {
		GameLoop();	
	}
	//Free resources and close SDL
	close();

	return 0;

}






