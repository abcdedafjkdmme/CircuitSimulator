#pragma once
#include <Dense>
#include <cmath>
#include <stdio.h>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

namespace MMath {


	static Eigen::Matrix3d TranslateMatrix(Eigen::Matrix3d MatrixToTransform, Eigen::Vector2d Trans)
	{
		Eigen::Matrix3d NewTransform = MatrixToTransform;

		NewTransform(0,2) = Trans.x();
		NewTransform(1,2) = Trans.y();

		return NewTransform;

	}



	static Eigen::Matrix3d ScaleMatrix(Eigen::Matrix3d MatrixToTransform, Eigen::Vector2d Scale)
	{
		Eigen::Matrix3d NewTransform = MatrixToTransform;

		NewTransform(0, 0) = Scale.x();
		NewTransform(1, 1) = Scale.y();

		return NewTransform;
	}

	static Eigen::Matrix3d RotateMatrix(Eigen::Matrix3d MatrixToTransform, double Rotation)
	{
		Eigen::Matrix3d NewTransform = MatrixToTransform;

		double SineOfRotation = std::sin(Rotation);

		double CosOfRotation = std::cos(Rotation);

		NewTransform(0, 0) = CosOfRotation;
		NewTransform(0, 1) = SineOfRotation;
		NewTransform(1, 0) = -SineOfRotation;
		NewTransform(1, 1) = CosOfRotation;


		return NewTransform;
	}

	static double RadianToDegree(double Radian) {
		return Radian * 180.0 / M_PI;
	}
	static double DegreeToRadian(double Degree) {
		return Degree * M_PI / 180.0;
	}

};