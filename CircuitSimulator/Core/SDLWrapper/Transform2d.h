#pragma once
#include "Vector2.h"
#include <Dense>

class Transform2d
{
public:
	Transform2d();

	/*Eigen::Vector2d Translation{ 0.0,0.0 };
	Eigen::Vector2d Scale{ 0.0,0.0 };
	double Rotation{};*/
	Eigen::Matrix3d TransformationMatrix;
	Eigen::Matrix3d IdentityMatrix;
	Eigen::Matrix3d Translated(Eigen::Vector2d Trans);
	Eigen::Matrix3d Scaled(Eigen::Vector2d Scale);
	Eigen::Matrix3d Rotated(double Rotation);


	

	

};

