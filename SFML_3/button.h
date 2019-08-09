#pragma once
#include <SFML/Graphics.hpp>
#include <Windows.h>

class Button_number1_
{
	
public:
	sf::Texture button_t1;
	sf::Texture button_t2;
	sf::Sprite button_s1;
	sf::Sprite button_s2;
	
	float dX = 0;
	float dY = 0;
	sf::WindowHandle wHandle;
	sf::Sprite loadSpriteButton1(std::string filename);
	Button_number1_() {};
	void button_pressed1_(sf::Event&,sf::Vector2f,  sf::RenderWindow&, sf::WindowHandle&,float& );
	bool pressed_b = false;
	void set_position(int x,int y) { button_s1.setPosition(x,y); button_s2.setPosition(x,y); };
	float speed_up(float&);
	
};

class Button_number2_ :public Button_number1_
{
	
public:
	void button_pressed2_(sf::Event&, sf::Vector2f, sf::RenderWindow&, sf::WindowHandle&, float&);
	float speed_low(float&);
};

class Button_number3_ :public Button_number1_
{
	
public:
	void button_pressed3_(sf::Event&, sf::Vector2f, sf::RenderWindow&, sf::WindowHandle&);
	
};