#include "DCMotor.h"

DCMotor::DCMotor()
{
	BackgroundImage->SetTexture("Resources/DcMotor.png");
	CogWheelImage->SetTexture("Resources/DcMotorCogwheel.png");
}

void DCMotor::Tick(double DeltaTime)
{
	RPM = InPin->Volt;
	CogWheelImage->Angle += RPM;
}

void DCMotor::SetWorldPosition(Vector2 WorldPos)
{
	BackgroundImage->SetWorldPosition(WorldPos);
	CogWheelImage->SetWorldPosition(WorldPos);
	InPin->SetWorldPosition( WorldPos + Vector2(249, 463));
}

Vector2 DCMotor::GetWorldPosition()
{
	return BackgroundImage->GetWorldPosition();
}
