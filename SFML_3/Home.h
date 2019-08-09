#pragma once
#include <SFML/Graphics.hpp>
class Home
{
	sf::Texture home_t;
	sf::Texture ZZZ_t;
public:
	sf::Sprite loadSpriteHome(std::string);
	sf::Sprite loadSpriteZZZ(std::string);
	sf::Sprite home_s;
	sf::Sprite ZZZ_s;
	Home();
	~Home();
};

