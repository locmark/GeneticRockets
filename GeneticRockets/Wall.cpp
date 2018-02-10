#include "stdafx.h"
#include "Wall.h"


Wall::Wall() :
	rect(sf::Vector2f((int)width, height))
{
	rect.setPosition(sf::Vector2f(this->x, this->y));
}

CollisionBox Wall::GetCollisionBox()
{
	return CollisionBox();
}

void Wall::Draw(sf::RenderWindow & window)
{
	window.draw(rect);
}

