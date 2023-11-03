#pragma once
#include <GameObject.h>
#include "Pin.h"
#include <GameObjectManager.h>
#include <WImage.h>
#include <RenderManager.h>


class Bulb : public GameObject
{
    

   // GameObjectManager& Manager = GameObjectManager::getInstance();
public:
    std::unique_ptr<Pin> InPin = std::make_unique<Pin>();
    Bulb();
   

protected:
    //float Brightness{ 0 };
   
    const float VoltTheresholdForLitBulb{ 90.0 };

protected:
    void Tick(double DeltaTime) override;
public:
    std::unique_ptr<WImage> Image = std::make_unique<WImage>();
    const std::string LitImagePath = "Core/NElectro/Resources/LedBright.png";
    const std::string DimImagePath = "Core/NElectro/Resources/LedDim.png";

public:
    void SetWorldPosition(Vector2 WorldPos);
    Vector2 GetWorldPosition();
};

