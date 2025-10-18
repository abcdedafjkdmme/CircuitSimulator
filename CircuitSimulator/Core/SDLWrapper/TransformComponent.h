#pragma once
#include "GameObject.h"
#include "Transform2d.h"

class TransformComponent : public GameObject
{
public:
	Transform2d GlobalTransform;
	Transform2d LocalTransform;

	

	void SetGlobalTranslation(Vector2 Translation);
	void SetGlobalRotation(double Rotation);
	void SetGlobalScale(Vector2 Scale);

	void SetLocalTranslation(Vector2 Translation);
	void SetLocalRotation(double Rotation);
	void SetLocalScale(Vector2 Scale);

private:
	TransformComponent* GetParentsTransformComponent();
	void UpdateGlobalTransforms();
	void UpdateLocalTransforms();
	void UpdateAllChildrensGlobalTransforms();

};

