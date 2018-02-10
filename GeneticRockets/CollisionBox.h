#pragma once
class CollisionBox
{
public:
	CollisionBox(float x, float y, float width, float height);

	bool CheckCollision(const CollisionBox& box) const;

	float x() const { return _x; }
	float y() const { return _y; }
	float width() const { return _width; }
	float height() const { return _height; }
private:
	float _x;
	float _y;
	float _width;
	float _height;
	float _angle;
};

