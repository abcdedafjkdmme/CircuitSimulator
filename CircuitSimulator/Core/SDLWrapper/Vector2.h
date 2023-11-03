#pragma once
class Vector2
{
public:
	Vector2(double _X, double _Y) :X(_X), Y(_Y) {};

	double X;
	double Y;

	void Normalize();
	Vector2 Normalized();

	friend Vector2 operator+(const Vector2& v1, const Vector2& v2)
	{	
		return Vector2(v1.X + v2.X, v1.Y + v2.Y);
	}
	friend Vector2 operator-(const Vector2& v1, const Vector2& v2)
	{
		return Vector2(v1.X - v2.X, v1.Y - v2.Y);
	}
	friend Vector2 operator*(const Vector2& v1, const float& f1)
	{
		return Vector2(v1.X* f1, v1.Y* f1);
	}
	friend Vector2 operator*(const Vector2& v1, const Vector2&v2)
	{
		return Vector2(v1.X * v2.X, v1.Y * v2.Y);
	}
	friend Vector2 operator/(const Vector2& v1, const float& f1)
	{
		return Vector2(v1.X / f1, v1.Y / f1);
	}
	friend Vector2 operator/(const Vector2& v1, const Vector2& v2)
	{
		return Vector2(v1.X / v2.X, v1.Y / v2.Y);
	}

};

