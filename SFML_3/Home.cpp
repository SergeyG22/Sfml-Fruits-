#include "Home.h"
#include <iostream>

sf::Sprite Home::loadSpriteHome(std::string filename)
{

	if (!home_t.loadFromFile(filename))
	{
		std::cout << "Fail loading texture\n";
	};
	home_s.setTexture(home_t);
	home_s.setOrigin(75,75);
	home_s.setPosition(100, 100);

	return home_s;
}

sf::Sprite Home::loadSpriteZZZ(std::string filename)
{

	if (!ZZZ_t.loadFromFile(filename))
	{
		std::cout << "Fail loading texture\n";
	};
	ZZZ_s.setTexture(ZZZ_t);
	ZZZ_s.setPosition(165, 10);

	return ZZZ_s;
}






Home::Home()
{
}


Home::~Home()
{
}
