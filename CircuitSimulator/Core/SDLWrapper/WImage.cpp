#include "WImage.h"
#include <stdio.h>
#include <RenderingUtils.h>


WImage::WImage()
{
	

}

void WImage::SetWorldPosition(Vector2 WorldPos)
{
	WorldPosition = WorldPos;
}

Vector2 WImage::GetWorldPosition()
{
	return WorldPosition;
}

void WImage::SetTexture(std::string path)
{

	Texture = IMG_LoadTexture(mRenderer, path.c_str());

	// if the default size is not provided use size of texture
	if (Size.X == 0 || Size.Y == 0) {
		SDL_Point TextureSize = GetSizeOfTexture(Texture);
		Size.X = TextureSize.x;
		Size.Y = TextureSize.y;
	}

	if (Texture == NULL) {
		printf("couldnt set texture %s \n",SDL_GetError());
	}
}

void WImage::Render(Camera& Cam)
{
	if (mRenderer == NULL) {
		printf("renderer is null");
		return;
	}

	/*SDL_Rect RenderQuad = { ((WorldPosition.X - Cam.WorldPosition.X)* Cam.Scale.Y)+ Cam.Size.X/2 ,
							((WorldPosition.Y- Cam.WorldPosition.Y)* Cam.Scale.Y)+Cam.Size.Y/ 2,
							Size.X* Scale.X * Cam.Scale.X,
							Size.Y*Scale.Y* Cam.Scale.Y };*/

	SDL_Rect RenderQuad = RenderingUtils::WorldToScreen(Scale, Cam, WorldPosition,Size );

	//Set clip rendering dimensions
	if (Clip != NULL)
	{
		RenderQuad.w = Clip->w;
		RenderQuad.h = Clip->h;
	}

	SDL_RenderCopyEx(mRenderer, Texture, Clip, &RenderQuad, Angle,Center,Flip );
}

WImage::~WImage()
{
	
	RenderedObject::~RenderedObject();
	SDL_DestroyTexture(Texture);
	Texture = NULL;
	

}