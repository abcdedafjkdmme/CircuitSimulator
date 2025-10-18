#pragma once
#include "Vector2.h"
#include "MMath.h"
//#include <Dense>

class Transform2d
{
public:
	Transform2d() {};
	
	/*Eigen::Vector2d Translation{ 0.0,0.0 };
	Eigen::Vector2d Scale{ 0.0,0.0 };
	double Rotation{};*/
	
	const Eigen::Matrix3d IdentityMatrix = (Eigen::Matrix3d() <<  1, 0, 0,
																  0, 1, 0,
																  0, 0, 1).finished();

	Eigen::Matrix3d TransformationMatrix = IdentityMatrix;

	Vector2 GetTranslation();
	double GetRotation();
	Vector2 GetScale();

	Eigen::Matrix3d Translated(Eigen::Vector2d Trans);
	Eigen::Matrix3d Scaled(Eigen::Vector2d Scale);
	Eigen::Matrix3d Rotated(double Rotation);

	void ApplyTransforms(Vector2 Translation, double Rotation, Vector2 Scale);
	

};

