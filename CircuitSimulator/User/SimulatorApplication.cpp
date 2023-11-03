#include "SimulatorApplication.h"

void SimulatorApplication::SDLEventLoop() {
    //printf("%s \n", IsLeftMouseButtonHeldDown ? "true" : "false");
	Application::SDLEventLoop();
	if (Event.type == SDL_MOUSEWHEEL) {
		// zoom in and out
		RManager.ActiveCamera.Scale.X = (RManager.ActiveCamera.Scale.X + (Event.wheel.y*0.02));
		RManager.ActiveCamera.Scale.Y = (RManager.ActiveCamera.Scale.Y + (Event.wheel.y*0.02));
	}
    if (Event.type == SDL_MOUSEBUTTONDOWN ) {
        if (Event.button.button == SDL_BUTTON_LEFT) {
            IsLeftMouseButtonHeldDown = true;
        }
        
    }
    if (Event.type == SDL_MOUSEBUTTONUP) {
        if (Event.button.button == SDL_BUTTON_LEFT) {
            IsLeftMouseButtonHeldDown = false;
        }
    }
    

    if (Event.type == SDL_MOUSEMOTION) {
        if (!IsLeftMouseButtonHeldDown) {
            return;
        }
        Vector2 CameraMovement = { (float)(-Event.motion.xrel) *(1/RManager.ActiveCamera.Scale.X) ,
                                   (float)(- Event.motion.yrel) * (1/RManager.ActiveCamera.Scale.Y)};

       


        RManager.ActiveCamera.WorldPosition = RManager.ActiveCamera.WorldPosition+CameraMovement;
        
    }
	/*if (Event.type == SDL_KEYDOWN) {
		switch (Event.key.keysym.sym) {
           case SDLK_UP:
            RManager.ActiveCamera.WorldPosition.Y -= 2.5*1/RManager.ActiveCamera.Scale.Y;
            break;

        case SDLK_DOWN:
            RManager.ActiveCamera.WorldPosition.Y += 2.5 * 1/RManager.ActiveCamera.Scale.Y;
           break;

        case SDLK_LEFT:
            RManager.ActiveCamera.WorldPosition.X -= 2.5 * 1/RManager.ActiveCamera.Scale.X;
            break;
            

        case SDLK_RIGHT:
            RManager.ActiveCamera.WorldPosition.X += 2.5 * 1/RManager.ActiveCamera.Scale.X;
            break;

        default:
        
            break;
		}
	}*/
}



