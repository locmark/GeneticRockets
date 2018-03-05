#pragma once

#include "DNA.h"

#include <SFML\Graphics.hpp>
#include "CollisionBox.h"



class Rocket
{
public:
	Rocket();
	~Rocket();

	void CalcScore();
	inline float GetScore() { return this->score; }

	DNA GetDna() { return dna; }
	void SetDna(DNA dna) { this->dna = dna; }

	void ApplyForce(sf::Vector2f);
	void Update(int count);
	void Draw(sf::RenderWindow& window);

	CollisionBox GetCollisionBox() { return CollisionBox(position.x, position.y, ROCKET_WIDTH, ROCKET_HEIGHT); }
	void Crash() { crashed = true; }
private:
	sf::Vector2f position;
	sf::Vector2f speed;
	sf::Vector2f acceleration;

	DNA dna;
	int score;
	bool crashed = false;
	bool won = false;

	sf::RectangleShape rect;
};

