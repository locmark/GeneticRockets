#pragma once

#include "DNA.h"

#include <SFML\Graphics.hpp>



class Rocket
{
private:
	sf::Vector2f position;
	sf::Vector2f speed;
	sf::Vector2f acceleration;

	DNA dna;
	int score;
	bool crashed = false;

	sf::RectangleShape rect;
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
};

