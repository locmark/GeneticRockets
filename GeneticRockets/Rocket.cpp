#include "stdafx.h"
#include "Rocket.h"

#include <math.h>

Rocket::Rocket() :
	rect(sf::Vector2f((int)ROCKET_WIDTH, ROCKET_HEIGHT)),
	acceleration(0.0f, 0.0f),
	speed(0.0f, 0.0f),
	position(400 - ROCKET_WIDTH / 2, 600 - ROCKET_HEIGHT)
{
	rect.setPosition(position);
	rect.setOrigin(ROCKET_WIDTH/2, ROCKET_HEIGHT/2);
	rect.setFillColor(sf::Color(255, 255, 255, 150));
}


Rocket::~Rocket()
{
}

static float CalcDistance(sf::Vector2f vec1, sf::Vector2f vec2)
{
	vec1 -= vec2;
	return sqrt(vec1.x*vec1.x + vec1.y*vec1.y);
}

static float Map(float value, float a, float b, float c, float d)
{
	float kk = value - a;
	if (c > d) {
		return c - ((kk / (b - a)) * (abs(d - c)));
	}
	else {
		return ((kk / (b - a)) * (abs(d - c))) + c;
	}
}

void Rocket::CalcScore()
{
	//score = 1000/CalcDistance(this->position, target);
	float distance = CalcDistance(this->position, target);
	//score = Map(distance, 0, 1000, 100, 1);
	score = 10000 / distance;
	if (crashed)
		score /= 50;
	if (won)
		score *= 10;
}

void Rocket::ApplyForce(sf::Vector2f force)
{
	this->acceleration = force;
	
}

void Rocket::Update(int count)
{
	if (!crashed && !won)
	{
		if (position.x < 0 || position.x > SCREEN_WIDTH ||
			position.y < 0 || position.y > SCREEN_HEIGHT)
			crashed = true;

		float distance = CalcDistance(this->position, target);
		if (distance < 10)
			won = true;

		ApplyForce(dna.GetForce(count));
		//physics
		this->speed += this->acceleration;
		this->position += this->speed;

		this->acceleration = sf::Vector2f();
	}
}

void Rocket::Draw(sf::RenderWindow & window)
{
	this->rect.setRotation(90 + std::atan2(speed.y, speed.x) * 180 / 3.14f);
	rect.setPosition(position);
	window.draw(rect);
}
