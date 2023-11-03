#include "PushButton.h"
#include <ApplicationStatics.h>

PushButton::PushButton()
{

	Image->SetTexture(UnpushedImage);
	
}

PushButton::~PushButton()
{
	
}

void PushButton::SetWorldPosition(Vector2 WorldPos)
{
	ColRect.SetWorldPosition(WorldPos + (ColRect.GetWorldPosition() - Image->GetWorldPosition()));
	Image->SetWorldPosition(WorldPos);
	
}

Vector2 PushButton::GetWorldPosition()
{
	return Image->GetWorldPosition();
}



void PushButton::Tick(double DeltaTime)
{
	
	if (PassedTimeSinceButtonPushedDown > TimeNeededToBeUnpushed) {
		IsButtonPushedDown = false;
	}

	if (IsButtonPushedDown) {
		PassedTimeSinceButtonPushedDown += DeltaTime;
		Image->SetTexture(PushedDownImage);
	}
	else {
		PassedTimeSinceButtonPushedDown = 0.0;
		Image->SetTexture(UnpushedImage);
	}

	
}

void PushButton::Input(SDL_Event& InputEvent)
{
	if (InputEvent.type == SDL_MOUSEBUTTONDOWN && InputEvent.button.button == SDL_BUTTON_LEFT) {
		//printf("mouse %f %f  col %f %f \n",ApplicationStatics::GetMouseWorldPosition().X, ApplicationStatics::GetMouseWorldPosition().Y,ColRect.WorldPosition.X,ColRect.WorldPosition.Y);
		if (ColRect.CollidingWithPoint(ApplicationStatics::GetMouseWorldPosition())) {
			IsButtonPushedDown = true;
		}
			
	}
}
