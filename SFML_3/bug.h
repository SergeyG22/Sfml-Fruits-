#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>
#include <vector>

class Bug
{
	std::string name_fruit_banana = "banana.png";
	int total=0;
	int random_;
	bool pressed_b = false;
	
	sf::Texture bug_t;
	sf::Texture fone_t;
	sf::Texture apple_t;
	
	sf::Sprite fone_s;
	
	std::random_device rd;
	std::random_device rd_;
	std::random_device rd_f;

	int event_number = 5;
	int event_current = 0;
	double distance;
	int random_positionX=400;
	int random_positionY=400;
	
	float angle;
	float dX=0;
	float dY=0;
	int a = 0;//Переманная ответственная за очистку экрана
	sf::Clock clock;
	float time;
	
	
public:
	std::vector<std::string>object = { "apple.png" ,"banana.png","cherry.png","orange.png",
		"pineapple.png","red_berry.png" };
	sf::Sprite apple_s;
	Bug() {
	        
	};
	int apple;
	int banana;
	int cherry;
	int pineapple;
	int red_berry;

	float speed = 0.5;
	bool hold_button = true;
	int sleep_home = false;
	int positionX = 400;
	int positionY = 200;
	sf::Sprite bug_s;
	sf::Sprite loadSpriteBug(std::string filename);
	sf::Sprite loadSpriteFone(std::string filename);
	sf::Sprite loadSpriteApple(std::string filename);
	void rand_();
	void drag_and_drop_bug(sf::Event& , sf::Vector2f , sf::RenderWindow &, sf::WindowHandle&);	
	void movement_(float&);
	
};

class Bug_2t :public Bug
{
	
public:
	Bug_2t()
	{
		positionX = 100;
		positionY = 200;
		speed = 0.7;
	};



};