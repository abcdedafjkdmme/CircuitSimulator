#include "UserArduino.h"
#include <stdio.h>



UserArduino::UserArduino()
{
	//Arduino::Arduino();
	SetPinMode(1, PinState::OUTPUT);
	DigitalWrite(5, 100.0);
}

void UserArduino::Tick(double DeltaTime) {
	
	if (DigitalRead(6) > 10) {
		DigitalWrite(6, 0.0);
	}
	else DigitalWrite(6, 100.0);
}



UserArduino::~UserArduino()
{
	
	
}
