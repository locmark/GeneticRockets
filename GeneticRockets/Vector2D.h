//#pragma once
//
//#include <math.h>
//#include <SFML\System.hpp>
//
//class Vector2D
//{
//public:
//	Vector2D();
//	Vector2D(float x, float y)
//	{
//		this->x = x;
//		this->y = y;
//	}
//	
//	inline float x() const { return this->x; }
//	inline float y() const { return this->y; }
//	float r() const { return sqrtf(this->x * this->x + this->y * this->y); }
//	float angle() const { return atan2f(this->y, this->x); }
//
//	void operator*= (float a) {
//		this->x *= a; 
//		this->y *= a;
//	}
//
//	void operator+= (const Vector2D& vector) { 
//		this->x += vector.x();
//		this->y += vector.y();
//	}
//
//	Vector2D operator+ (const Vector2D& vector) { return Vector2D(x() + vector.x(), y() + vector.y()); }
//	Vector2D operator* (float a) { return Vector2D(this->x * a, this->y * a); }
//	Vector2D operator/ (float a) { return Vector2D(this->x / a, this->y / a); }
//
//	sf::Vector2f GetSFMLVector() const { return sf::Vector2f(this->x, this->y); }
//private:
//	float x;
//	float y;
//};
//
