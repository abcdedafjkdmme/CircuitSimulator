#pragma once

#include <string>
#include <SDL.h>
#include  <SDL_image.h>
#include <Vector2.h>
#include "Camera.h"


class RenderedObject 
{
public: 

   
    RenderedObject(/*SDL_Renderer* Renderer*/) /*:mRenderer(Renderer)*/;
    virtual ~RenderedObject();

    SDL_Renderer* mRenderer;
    virtual void Render(Camera& Cam) {};
    int ZIndex = 0;


    friend bool operator==(const RenderedObject& v1, const RenderedObject& v2)
    {
        return &v1 == &v2;
    }
//protected:
//    Vector2 GetTopLeftWorldPosition(Vector2 WorldPos, Vector2 PivotRelToWorld, Vector2 Scale);
//    Vector2 WorldToScreen(Vector2 Vec, Camera Cam);
//    SDL_Rect WorldToScreen(Vector2 RectScale, Camera Cam, Vector2 WorldPosition, Vector2 Size);
    
   
};

