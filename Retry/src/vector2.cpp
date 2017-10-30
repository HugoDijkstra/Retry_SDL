#include "../include/vector2.h"

Vector2::Vector2(float x, float y) {
	this->x = x;
	this->y = y;
}
Vector2::~Vector2()
{
}


Vector2::Vector2()
{
	x = 0;
	y = 0;
}

Vector2 Vector2::operator+(const Vector2 & oth)
{
	return Vector2(this->x + oth.x, this->y + oth.y);
}

void Vector2::operator+=(const Vector2 & oth)
{
	this->x += oth.x;
	this->y += oth.y;
}

Vector2 Vector2::operator-(const Vector2 & oth)
{
	return Vector2(this->x - oth.x, this->y - oth.y);

}

void Vector2::operator-=(const Vector2 & oth)
{
	this->x -= oth.x;
	this->y -= oth.y;
}

Vector2 Vector2::operator*(const float & oth)
{
	return Vector2(this->x * oth, this->y * oth);
}

void Vector2::operator*=(const float & oth)
{
	this->x *= oth;
	this->y *= oth;
}

Vector2 Vector2::operator/(const float & oth)
{
	return Vector2(this->x / oth, this->y / oth);
}

void Vector2::operator/=(const float & oth)
{
	this->x /= oth;
	this->y /= oth;
}


float Vector2::magnitude()
{
	return (sqrt((x*x) + (y*y)));
}

void Vector2::normalize()
{
	float mag = magnitude();
	if (mag != 0)
	{
		x /= mag;
		y /= mag;
	}
}

Vector2 Vector2::normalized()
{
	float mag = magnitude();
	if (mag != 0)
	{
		float x = this->x / mag;
		float y = this->y / mag;
		return Vector2(x, y);
	}
	return Vector2(0, 0);
}

float Vector2::angle()
{
	return atan2(y,x);
}

float Vector2::Distance(Vector2 a, Vector2 b)
{
	return (a - b).magnitude();
}

//Vector2 Vector

std::ostream & operator<<(std::ostream & os, const Vector2 & oth)
{
	return os << "(" << oth.x << "," << oth.y << ")";
}
