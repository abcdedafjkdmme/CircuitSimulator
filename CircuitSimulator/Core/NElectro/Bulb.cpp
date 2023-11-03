#include "Bulb.h"
#include <stdio.h>


Bulb::Bulb() {
	Image->SetTexture(DimImagePath);
}


void Bulb::Tick(double DeltaTime)
{
	if (InPin== nullptr) {
		return;
	}
	if (InPin->Volt > VoltTheresholdForLitBulb) {
		Image->SetTexture(LitImagePath);
	}
	else {
		Image->SetTexture(DimImagePath);
	}
}

void Bulb::SetWorldPosition(Vector2 WorldPos)
{
	/*InPin->SetWorldPosition(WorldPos + (InPin->GetWorldPosition() - Image->GetWorldPosition()));*/
	InPin->SetWorldPosition(WorldPos + Vector2(255.0,497));
	Image->SetWorldPosition(WorldPos);
}
