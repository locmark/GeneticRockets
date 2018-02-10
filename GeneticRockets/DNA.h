#pragma once

#include <vector>
#include <SFML\Graphics.hpp>



class DNA
{
private:
	std::vector<sf::Vector2f> forces;
public:
	DNA();
	~DNA();
	sf::Vector2f GetForce(int i) { return forces[i]; }
	
	void SetForce(sf::Vector2f force, int i) { forces[i] = force; }
	void Mutate();
};

