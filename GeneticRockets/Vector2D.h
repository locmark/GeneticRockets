#pragma once

#include <math.h>
#include <sfml\system.hpp>

class Vector2D
{
public:
	Vector2D() {}
	Vector2D(float x, float y)
	{
		_x = x;
		_y = y;
	}
	
	inline float x() const { return _x; }
	inline float y() const { return _y; }
	float r() const { return sqrtf(_x * _x + _y * _y); }
	float angle() const { return atan2f(_y, _x); }

	void operator*= (float a) {
		_x *= a; 
		_y *= a;
	}

	void operator+= (const Vector2D& vector) { 
		_x += vector.x();
		_y += vector.y();
	}

	Vector2D operator+ (const Vector2D& vector) { return Vector2D(x() + vector.x(), y() + vector.y()); }
	Vector2D operator* (float a) { return Vector2D(_x * a, _y * a); }
	Vector2D operator/ (float a) { return Vector2D(_x / a, _y / a); }

	sf::Vector2f getsfmlvector() const { return sf::Vector2f(_x, _y); }
private:
	float _x;
	float _y;
};

