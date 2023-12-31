#include "RootGameObject.h"
#include <Bulb.h>
#include <Wire.h>
#include <stdio.h>
#include <PushButton.h>




RootGameObject::RootGameObject()
{
	
	NewMotor->SetWorldPosition(Vector2(550.0, 200.0));
	UserArduino* NewArduino = new UserArduino();
	NewArduino->SetWorldPosition(Vector2(100.0, 700.0));

	/*UserArduino* NewArduino2 = new UserArduino();
	NewArduino2->SetWorldPosition(Vector2(500.0, 900.0));*/

	Bulb* NewBulb = new Bulb();
	NewBulb->Image->ZIndex = -1;
	NewBulb->SetWorldPosition(Vector2(000.0, -100.0));

	Wire* NewWire = new Wire();
	NewWire->MakeConnections(*(NewArduino->Pins[5]), *(NewMotor->InPin));

	Wire* NewWire2 = new Wire();
	NewWire2->MakeConnections(*(NewArduino->Pins[6]), *(NewBulb->InPin));

	PushButton* NewButton = new PushButton();
	NewButton->Image->ZIndex = -2;
	NewButton->SetWorldPosition(Vector2(-500.0, 200.0));

	//delete NewArduino;

}

void RootGameObject::Tick(double DeltaTime) {
	
}

