#pragma once
#include "RenderedObject.h"
#include <SDL.h>
#include <SDL_image.h>
#include "Vector2.h"
#include <IMoveable.h>

class WImage :public RenderedObject, public IMoveable
{

public:
    //WImage(SDL_Renderer* Renderer) :RenderedObject(Renderer) {};

protected:
    SDL_Texture* Texture{ NULL };

public:
    SDL_Point GetSizeOfTexture(SDL_Texture* texture) {
        SDL_Point size;
        SDL_QueryTexture(texture, NULL, NULL, &size.x, &size.y);
        return size;
    }
public:
    double Angle{};
    SDL_Point* Center{ NULL };
    Vector2 WorldPosition{0.0,0.0};
    Vector2 Size{0.0,0.0};
    Vector2 Scale{ 1.0,1.0 };
    SDL_RendererFlip Flip = SDL_FLIP_NONE;
    SDL_Rect* Clip{NULL};
public:
    void SetWorldPosition(Vector2 WorldPos) override;
    Vector2 GetWorldPosition() override;

public:
    void SetTexture(std::string path);

public:
    void Render(Camera& Cam) override;
    ~WImage() override;
};

