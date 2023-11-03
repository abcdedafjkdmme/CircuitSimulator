#pragma once
#include "RenderedObject.h"
class RenderedRect :public RenderedObject
{

public:
    //Rect(SDL_Renderer* Renderer) :RenderedObject(Renderer) {};
    Vector2 WorldPosition{ 0.0,0.0 };
    Vector2 Size{ 0.0,0.0 };
    Vector2 Scale{ 1.0,1.0 };
    SDL_Color Color{ 0x00, 0xFF, 0x00, 0x7F };
    bool IsEnabled{ true };
    void Render(Camera& Cam) override;
     
};

