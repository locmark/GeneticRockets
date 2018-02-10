#include "stdafx.h"
#include "CollisionBox.h"


CollisionBox::CollisionBox(float x, float y, float width, float height)
{
	_x = x;
	_y = y;
	_width = width;
	_height = height;
}

bool CollisionBox::CheckCollision(const CollisionBox & box) const
{
	return (box.x() > _x && box.x() < _x + _width && box.y() > _y && box.y() < _y + _height);
}

