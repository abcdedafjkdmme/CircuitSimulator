#include "Transform2d.h"
#include <cmath>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif


Transform2d::Transform2d()
{
	IdentityMatrix <<1, 0, 0,
					 0, 1, 0,
					 0, 0, 1;

	TransformationMatrix = IdentityMatrix;

}



Eigen::Matrix3d Transform2d::Translated(Eigen::Vector2d Trans)
{
	Eigen::Matrix3d NewTransform = TransformationMatrix;

	NewTransform(0, 3) = Trans.x();
	NewTransform(1, 3) = Trans.y();

	return  NewTransform * TransformationMatrix;
}

Eigen::Matrix3d Transform2d::Scaled(Eigen::Vector2d Scale)
{
	Eigen::Matrix3d NewTransform = TransformationMatrix;

	NewTransform(0, 0) = Scale.x();
	NewTransform(1, 1) = Scale.y();
	
	return NewTransform* TransformationMatrix;
}

Eigen::Matrix3d Transform2d::Rotated(double Rotation)
{
	Eigen::Matrix3d NewTransform = TransformationMatrix;

	double SineOfRotation = std::sin(Rotation/180.0* M_PI);

	double CosOfRotation = std::cos(Rotation/180.0* M_PI);

	NewTransform(0, 0) = CosOfRotation;
	NewTransform(0, 1) = SineOfRotation;
	NewTransform(1, 0) = -SineOfRotation;
	NewTransform(1, 1) = CosOfRotation;


	return NewTransform*TransformationMatrix;
}
