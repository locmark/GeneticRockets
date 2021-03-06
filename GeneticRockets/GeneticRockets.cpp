// GeneticRockets.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <SFML\Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <vector>

#include "Rocket.h"
#include "DNA.h"
#include "Wall.h"

#include "Vector2D.h"

#define log(a) std::cout << a << std::endl

const int rocketsAmount = 20;

inline void WindowLoop(sf::RenderWindow& window)
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
	}
}

void NewGeneration(std::vector<Rocket>& rockets)
{
	std::vector<Rocket> tempRockets;
	int scoreSum = 0;
	for (Rocket& rocket : rockets)
	{
		rocket.CalcScore();
		scoreSum += rocket.GetScore();
		for (size_t i = 0; i < rocket.GetScore(); i++)
		{
			tempRockets.push_back(rocket);
		}
	}
	log("scoreSum : " << scoreSum);

	rockets.clear();

	for (size_t i = 0; i < rocketsAmount; i++)
	{
		DNA parent1 = tempRockets[rand() % scoreSum].GetDna();
		DNA parent2 = tempRockets[rand() % scoreSum].GetDna();
		DNA child;

		for (size_t j = 0; j < dnaLenght; j++)
		{
			sf::Vector2f force;
			if (rand() % 2)
				force = parent1.GetForce(j);
			else
				force = parent2.GetForce(j);

			child.SetForce(force, j);
		}

		child.Mutate();

		Rocket childRocket;
		childRocket.SetDna(child);

		rockets.push_back(childRocket);
	}
}

int main()
{
	srand(time(NULL));
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Rockets", sf::Style::Default, settings);
	//window.setFramerateLimit(60);

	sf::Clock clock;
	float time;

	sf::CircleShape targetShape(20);
	targetShape.setPosition(target.x, target.y);

	std::vector<Rocket> rockets(rocketsAmount);
	Wall wall(150, 300, 500, 10);

	log("max rand val : " << RAND_MAX);
	int i = 0;
	while (window.isOpen())
	{
		WindowLoop(window);

		++i;
		if (i >= dnaLenght)
		{
			i = 0;
			NewGeneration(rockets);
		}
			
		
		time = clock.getElapsedTime().asSeconds();

		for (Rocket& rocket : rockets)
		{
			if (wall.GetCollisionBox().CheckCollision(rocket.GetCollisionBox()))
			{
				rocket.Crash();
			}
			rocket.Update(i);
		}
			

		window.clear();

		for (Rocket& rocket : rockets)
			rocket.Draw(window);
		window.draw(targetShape);
		wall.Draw(window);

		window.display();
	}

	return 0;
}

