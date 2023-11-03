#include "Line2d.h"
#include <SDL2_gfxPrimitives.h>
#include <RenderingUtils.h>

//SDL2_GFXPRIMITIVES_SCOPE int aacircleColor(SDL_Renderer* renderer, Sint16 x, Sint16 y, Sint16 rad, Uint32 color);

void Line2d::Render(Camera& Cam)
{
	
	for (size_t i = 0; i < Points.size(); i++)
	{

		//if next point does not exist in points vector
		if (!(i < Points.size() - 1)) {
			return;
		}

		Line2dPoint CurrentPoint = Points[i];
		Line2dPoint NextPoint = Points[i + 1];

		Vector2 CurrentPointScreenPosition = RenderingUtils::WorldToScreen(CurrentPoint.GlobalPosition, Cam);
		Vector2 NextPointScreenPosition = RenderingUtils::WorldToScreen(NextPoint.GlobalPosition, Cam);

		thickLineRGBA(
			mRenderer,
			CurrentPointScreenPosition.X,
			CurrentPointScreenPosition.Y,
			NextPointScreenPosition.X,
			NextPointScreenPosition.Y,
			LineThickness* (Cam.Scale.X+Cam.Scale.Y),
			LineColor.r,
			LineColor.g,
			LineColor.b,
			LineColor.a);

		
	}
	
}

void Line2d::AddPoint(Vector2 GlobalPos)
{
	Points.push_back(Line2dPoint{GlobalPos});
}

void Line2d::RemoveAllPoints()
{
	Points.clear();
}
