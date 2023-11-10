#pragma once
#include <Arduino.h>

class UserArduino :public Arduino
{
public:
	UserArduino();
	~UserArduino() override;
protected:
	
	void Tick(double DeltaTime) override;
	

};

