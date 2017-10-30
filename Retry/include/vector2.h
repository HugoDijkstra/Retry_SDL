#pragma once

#include <math.h>
#include <iostream>
class __declspec(dllexport) Vector2
{
public:
	float x, y;
	Vector2();
	Vector2(float x, float y);
	virtual ~Vector2();

	Vector2 operator+(const Vector2 &oth);
	void operator+=(const Vector2 &oth);
	Vector2 operator-(const Vector2 &oth);
	void operator-=(const Vector2 &oth);
	//times
	Vector2 operator*(const float &oth);
	void operator*=(const float &oth);
	//defide
	Vector2 operator/(const float &oth);
	void operator/=(const float &oth);

	friend std::ostream& operator<<(std::ostream& os, const  Vector2 &oth);
	float magnitude();
	void normalize();
	Vector2 normalized();
	float angle();

	static float Distance(Vector2 a, Vector2 b);
private:
};