#include "Transform2d.h"
//#include <iostream>



Vector2 Transform2d::GetTranslation()
{
	return Vector2(TransformationMatrix(0,2),TransformationMatrix(1,2));
}

double Transform2d::GetRotation()
{
	return atan2(TransformationMatrix(0, 1), TransformationMatrix(1, 1));
}


Vector2 Transform2d::GetScale()
{
	return Vector2(
		sqrt(TransformationMatrix(0,0) * TransformationMatrix(0, 0) + TransformationMatrix(0, 1) * TransformationMatrix(0, 1)),
		sqrt(TransformationMatrix(1, 0) * TransformationMatrix(1, 0) + TransformationMatrix(1, 1) * TransformationMatrix(1, 1))
	);
}

Eigen::Matrix3d Transform2d::Translated(Eigen::Vector2d Trans)
{

	return MMath::TranslateMatrix(IdentityMatrix, Trans);
	/*Eigen::Matrix3d NewTransform = TransformationMatrix;

	NewTransform(0, 3) = Trans.x();
	NewTransform(1, 3) = Trans.y();

	return  NewTransform * TransformationMatrix;*/
}



Eigen::Matrix3d Transform2d::Scaled(Eigen::Vector2d Scale)
{
	return MMath::ScaleMatrix(IdentityMatrix, Scale);

	/*Eigen::Matrix3d NewTransform = TransformationMatrix;

	NewTransform(0, 0) = Scale.x();
	NewTransform(1, 1) = Scale.y();
	
	return NewTransform* TransformationMatrix;*/
}

Eigen::Matrix3d Transform2d::Rotated(double Rotation)
{
	return MMath::RotateMatrix(IdentityMatrix, Rotation);

	/*Eigen::Matrix3d NewTransform = TransformationMatrix;

	double SineOfRotation = std::sin(Rotation/180.0* M_PI);

	double CosOfRotation = std::cos(Rotation/180.0* M_PI);

	NewTransform(0, 0) = CosOfRotation;
	NewTransform(0, 1) = SineOfRotation;
	NewTransform(1, 0) = -SineOfRotation;
	NewTransform(1, 1) = CosOfRotation;


	return NewTransform*TransformationMatrix;*/
}

void Transform2d::ApplyTransforms(Vector2 Translation, double Rotation, Vector2 Scale)
{

	Eigen::Matrix3d AppliedTrans =  MMath::TranslateMatrix(IdentityMatrix, Eigen::Vector2d(Translation.X, Translation.Y));
	Eigen::Matrix3d AppliedRot   =  MMath::RotateMatrix(IdentityMatrix, Rotation);
	Eigen::Matrix3d AppliedScale =	MMath::ScaleMatrix(IdentityMatrix, Eigen::Vector2d(Scale.X, Scale.Y));

	TransformationMatrix = AppliedTrans * AppliedRot * AppliedScale;


}
