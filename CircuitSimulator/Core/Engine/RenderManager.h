#pragma once

#include <vector>
#include <Camera.h>
#include <Vector2.h>
#include <RenderedObject.h>
#include <memory>

class RenderManager
{
friend class RenderedObject;

public:
	//Screen dimension constants
	const int SCREEN_WIDTH = 1280;
	const int SCREEN_HEIGHT = 720;
	const SDL_Color BACKGROUND_COLOR{ 3,0,28, 0xFF };
public:
	SDL_Renderer* gRenderer = NULL;
	SDL_Window* gWindow = NULL;
public:
	Camera ActiveCamera =Camera(Vector2{0.0,0.0},
								Vector2{1.0,1.0},
								Vector2(SCREEN_WIDTH,SCREEN_HEIGHT));

	
public:
	static RenderManager& getInstance() {
		static RenderManager   instance; // Guaranteed to be destroyed.
		// Instantiated on first use.
		return instance;
	}

public:
	void SortAllRenderObjectsByZIndex();
public:
	//std::vector<RenderedObject*> RenderedObjects;
	std::vector <std::reference_wrapper<RenderedObject>> RenderedObjects;
	void RegisterRenderedObject(RenderedObject& Obj);
	void UnregisterRenderedObject(RenderedObject & Obj);

//public:
//	template <typename T>
//	T* AddRenderedObject() {
//		T* ObjToAdd = new T(gRenderer);
//		RegisterRenderedObject(static_cast<RenderedObject*>(ObjToAdd));
//		return ObjToAdd;
//	};
//
//	void RemoveRenderedObject(RenderedObject* ObjToRemove) {
//		UnregisterRenderedObject(ObjToRemove);
//		delete ObjToRemove;
//	};

public:
	void RenderAllObjects(double DeltaTime);
	bool Init();
	void Quit();
};

