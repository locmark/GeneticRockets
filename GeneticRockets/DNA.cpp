#include "stdafx.h"
#include "DNA.h"

#include <cstdlib>


DNA::DNA() :
	forces(dnaLenght)
{
	for (size_t i = 0; i < dnaLenght; i++)
	{
		float x = ((rand() % 2000) - 1000) / 10000.0f;
		float y = ((rand() % 2000) - 1000) / 10000.0f;
		forces[i] = sf::Vector2f(x, y);
	}
}


DNA::~DNA()
{
}

void DNA::Mutate()
{
	for (size_t i = 0; i < dnaLenght; i++)
	{
		if (rand() % 1000 < 5)
		{
			float x = ((rand() % 2000) - 1000) / 10000.0f;
			float y = ((rand() % 2000) - 1000) / 10000.0f;
			forces[i] = sf::Vector2f(x, y);
		}
	}
	
}
