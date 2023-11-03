#pragma once
#include "Pin.h"
#include <GameObject.h>
#include <memory>
#include <SDL2_gfxPrimitives.h>
#include <Line2d.h>
#include <SDL_pixels.h>

class Wire : public GameObject
{
public:
	Wire() = default;
	void MakeConnections(Pin& _StartPin, Pin& _EndPin);

protected:
	Pin* StartPin{nullptr};
	Pin* EndPin{nullptr};
	float Volt{ 0 };

protected:
	SDL_Color WireColor{ 0x0,  0x0, 0x80, 0xFF };
	Uint8 WireThickness{ 10 };
	std::unique_ptr<Line2d> RenderedLine = std::make_unique<Line2d>(WireThickness, WireColor);
protected:
	void Tick(double DeltaTime) override;
};

