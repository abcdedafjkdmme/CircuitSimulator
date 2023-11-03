#pragma once
#include "RenderedObject.h"
#include <Vector2.h>
#include <vector>


struct Line2dPoint {
	Vector2 GlobalPosition{ 0.0,0.0 };
	
};

class Line2d :public RenderedObject
{
public:
	Line2d(Uint8 _LineThickness, SDL_Color _LineColor):LineThickness(_LineThickness),LineColor(_LineColor){
		//RenderedObject::RenderedObject();
		
	};

private:
	Uint8 LineThickness{ };
	SDL_Color LineColor{  };
	std::vector<Line2dPoint> Points{};

	void Render(Camera& Cam) override;

public:
	void AddPoint(Vector2 GlobalPos);
	void RemoveAllPoints();
};


