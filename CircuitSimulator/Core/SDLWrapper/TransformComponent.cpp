#include "TransformComponent.h"



void TransformComponent::SetGlobalTranslation(Vector2 Translation)
{
	GlobalTransform.ApplyTransforms(Translation, GlobalTransform.GetRotation(), GlobalTransform.GetScale());
	UpdateLocalTransforms();
}

void TransformComponent::SetGlobalRotation(double Rotation)
{
	GlobalTransform.ApplyTransforms(GlobalTransform.GetTranslation(), Rotation, GlobalTransform.GetScale());
	UpdateLocalTransforms();
}

void TransformComponent::SetGlobalScale(Vector2 Scale)
{
	GlobalTransform.ApplyTransforms(GlobalTransform.GetTranslation(), GlobalTransform.GetRotation(), Scale);
	UpdateLocalTransforms();
}

void TransformComponent::SetLocalTranslation(Vector2 Translation)
{
	LocalTransform.ApplyTransforms(Translation, GlobalTransform.GetRotation(), GlobalTransform.GetScale());
	UpdateGlobalTransforms();
}

void TransformComponent::SetLocalRotation(double Rotation)
{
	LocalTransform.ApplyTransforms(GlobalTransform.GetTranslation(), Rotation, GlobalTransform.GetScale());
	UpdateGlobalTransforms();
}

void TransformComponent::SetLocalScale(Vector2 Scale)
{
	LocalTransform.ApplyTransforms(GlobalTransform.GetTranslation(), GlobalTransform.GetRotation(), Scale);
	UpdateGlobalTransforms();
}

TransformComponent* TransformComponent::GetParentsTransformComponent()
{

	if (Parent->Parent == nullptr) {
		return nullptr;
	}
	TransformComponent* ParentGlobalTransform = Parent->Parent->GetChildByClass<TransformComponent>();
	return ParentGlobalTransform;

}

void TransformComponent::UpdateGlobalTransforms()
{
	TransformComponent* ParentTransformComponent = GetParentsTransformComponent();
	if (ParentTransformComponent == nullptr) {
		GlobalTransform.TransformationMatrix = LocalTransform.TransformationMatrix;
		
	}
	else {
		Transform2d ParentGlobalTransform = ParentTransformComponent->GlobalTransform;
		GlobalTransform.TransformationMatrix = ParentGlobalTransform.TransformationMatrix * LocalTransform.TransformationMatrix;
	}

	UpdateAllChildrensGlobalTransforms();
	
}

void TransformComponent::UpdateLocalTransforms()
{
	TransformComponent* ParentTransformComponent = GetParentsTransformComponent();
	if (ParentTransformComponent == nullptr) {
		LocalTransform.TransformationMatrix = GlobalTransform.TransformationMatrix;
		
	}
	else {
		Transform2d ParentGlobalTransform = ParentTransformComponent->GlobalTransform;
		LocalTransform.TransformationMatrix = ParentGlobalTransform.TransformationMatrix.inverse() * GlobalTransform.TransformationMatrix;
	}

	UpdateAllChildrensGlobalTransforms();
}

void TransformComponent::UpdateAllChildrensGlobalTransforms()
{
	// update transform of each children
	for (auto* Obj : Parent->Children)
	{
		//if the transform component is this do nothing
		if (Obj == this) {
			continue;
		}
		TransformComponent* ChildTransform = Obj->GetChildByClass<TransformComponent>();
		ChildTransform->UpdateGlobalTransforms();
	}
}
