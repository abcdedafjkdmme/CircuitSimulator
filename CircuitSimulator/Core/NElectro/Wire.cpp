#include "Wire.h"
#include <stdio.h>



void Wire::MakeConnections(Pin& _StartPin, Pin& _EndPin)
{
	// if the start or end pins were previously set by making connection then clear all rendered points so it doesnt seem like same wire is connected to multiple pins
	if (StartPin || EndPin) {
		RenderedLine->RemoveAllPoints();
	}

	StartPin = &(_StartPin);
	EndPin = &(_EndPin);
	RenderedLine->AddPoint(_StartPin.GetWorldPosition());
	RenderedLine->AddPoint(_EndPin.GetWorldPosition());
}

void Wire::Tick(double DeltaTime)
{
	if (StartPin != nullptr && EndPin != nullptr) {
		Volt = StartPin->Volt;
		EndPin->Volt = Volt;
	}
	
}



