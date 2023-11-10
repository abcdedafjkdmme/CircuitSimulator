#pragma once
#include "GameObject.h"
#include <RenderManager.h>
#include <WImage.h>
#include <IMoveable.h>
#include <CollisionRect.h>
#include <string>

class PushButton : public GameObject,public IMoveable
{
//protected:
//    RenderManager& RManager = RenderManager::getInstance();
public:
    PushButton();
    ~PushButton() override;
    std::unique_ptr<WImage> Image = std::make_unique<WImage>();
private:
    bool IsButtonPushedDown{ false };
    double PassedTimeSinceButtonPushedDown{ 0.0 };
    const double TimeNeededToBeUnpushed{ 0.4 };
    const std::string PushedDownImage = "../CircuitSimulator/Core/NElectro/Resources/PushButtonPushed.png";
    const std::string UnpushedImage = "../CircuitSimulator/Core/NElectro/Resources/PushButtonUnpushed.png";
   
public:
    CollisionRect ColRect{ Vector2(0.0,0.0),Vector2(500.0,500.0),true };
    void SetWorldPosition(Vector2 WorldPos) override;
    Vector2 GetWorldPosition() override;

protected:
    void Tick(double DeltaTime) override;
    void Input(SDL_Event& InputEvent) override;

};

