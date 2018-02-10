#include "stdafx.h"
#include "Wall.h"


Wall::Wall(float x, float y, float width, float height) :
	rect(sf::Vector2f(width, height))
{
	_x = x;
	_y = y;
	_width = width;
	_height = height;
	rect.setPosition(sf::Vector2f(_x, _y));
}



CollisionBox Wall::GetCollisionBox()
{
	return CollisionBox(_x, _y, _width, _height);
}

void Wall::Draw(sf::RenderWindow & window)
{
	window.draw(rect);
}

