#pragma once

#include "CollisionBox.h"
#include <SFML\Graphics.hpp>

class Wall
{
public:
	Wall(float x, float y, float width, float height);
	CollisionBox GetCollisionBox();
	void Draw(sf::RenderWindow & window);
private:
	float _x;
	float _y;
	float _height;
	float _width;

	sf::RectangleShape rect;
};

