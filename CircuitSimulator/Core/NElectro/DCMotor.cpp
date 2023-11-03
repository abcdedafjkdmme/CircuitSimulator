#include "DCMotor.h"

DCMotor::DCMotor()
{
	BackgroundImage->SetTexture("Core/NElectro/Resources/DcMotor.png");
	CogWheelImage->SetTexture("Core/NElectro/Resources/DcMotorCogwheel.png");
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
