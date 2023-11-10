#include <Arduino.h>
#include <stdio.h>

Arduino::Arduino() {

	Image->SetTexture("../CircuitSimulator/Core/NElectro/Resources/arduino-2168193_1280.png");
	Image->Size = Vector2(512, 362.8);

	for (size_t i = 0; i < AmountOfPins; i++)
	{
		std::unique_ptr<Pin> newPin = std::make_unique<Pin>();
		newPin->SetWorldPosition(Image->GetWorldPosition());
		Pins.push_back(std::move(newPin));
	}
	
}

float Arduino::DigitalRead(int PIN)
{
	return Pins[PIN]->Volt;
}

void Arduino::DigitalWrite(int PIN, float Value)
{
	Pins[PIN]->Volt = Value;

	
	
	("Value of pin %i is %f volts \n",PIN, Value);
}

void Arduino::SetPinMode(int PIN, PinState State)
{
	
	switch (State)
	{
	case INPUT:
		Pins[PIN] -> ImpendanceState = Pin::ImpendanceStates::HIGH;
		break;
	case OUTPUT:
		Pins[PIN]->ImpendanceState = /*Pins[PIN]->*/Pin::ImpendanceStates::LOW;
		break;
	default:
		break;
	}

	//debug
	switch (State)
	{
	case PinState::INPUT:
		printf("Set state to Input \n");
		break;
	case PinState::OUTPUT:
		printf("set state to Output \n");
		break;
	default:
		break;
	}

}



void Arduino::Tick(double DeltaTime)
{
	
	
}

void Arduino::SetWorldPosition(Vector2 WorldPos)
{
	for (auto& Pin : Pins)
	{
		/*Pin->SetWorldPosition(WorldPos + (Pin->GetWorldPosition() - Image->GetWorldPosition()));*/
		Pin->SetWorldPosition(WorldPos + Vector2(327.0, 19.2));
	}
	Image->SetWorldPosition(WorldPos);
}

Vector2 Arduino::GetWorldPosition()
{
	return Image->GetWorldPosition();
}


