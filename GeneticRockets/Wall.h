#pragma once

#include "CollisionBox.h"
#include <SFML\Graphics.hpp>

class Wall
{
public:
	Wall();
	CollisionBox GetCollisionBox();
	void Draw(sf::RenderWindow & window);
private:
	float x;
	float y;
	float height;
	float width;

	sf::RectangleShape rect;
};

