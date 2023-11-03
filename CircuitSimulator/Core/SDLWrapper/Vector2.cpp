#include "Vector2.h"
#include <cmath>

void Vector2::Normalize()
{
	double l = X * X + Y * Y;
	if (l != 0) {
		l = std::sqrt(l);
		X /= l;
		Y /= l;
	}
	
}

Vector2 Vector2::Normalized()
{
	Vector2 v = *this;
	v.Normalize();
	return v;
}
