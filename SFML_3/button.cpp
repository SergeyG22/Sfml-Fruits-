#include "button.h"
#include <iostream>
#include <Windows.h>
#include <vector>
#include <random>
#include "bug.h"

#pragma comment(lib,"user32.lib")


sf::Sprite Button_number1_::loadSpriteButton1(std::string filename)
{
	if (!button_t1.loadFromFile(filename))
	{
		std::cout << "button download error\n";
	}
	button_s1.setTexture(button_t1);

	return button_s1;
}



void Button_number1_::button_pressed1_(sf::Event& event,sf::Vector2f pos,  sf::RenderWindow & window, sf::WindowHandle& wHandle,float&s)
{
	Bug b;
	wHandle = window.getSystemHandle();

	if (event.type == sf::Event::MouseButtonPressed)
	{
		
		if (event.key.code == sf::Mouse::Left)
			if (button_s1.getGlobalBounds().contains(pos.x, pos.y)) 
			{
				pressed_b = true;
				std::cout << pos.x << ' '<< pos.y << std::endl;
				
				std::cout << "Button is pressed number 1\n";
				speed_up(s);
				
				HCURSOR Cursor= LoadCursor(NULL,IDC_HAND);
				SetClassLongPtr(wHandle, GCLP_HCURSOR, reinterpret_cast<LONG_PTR>(Cursor));	
				dX = pos.x - button_s1.getPosition().x;
				dY = pos.y - button_s1.getPosition().y;
			}
	}

	
		
	if (event.type == sf::Event::MouseButtonReleased)
		
		if (event.key.code == sf::Mouse::Left)
		{
			if (button_s1.getGlobalBounds().contains(pos.x, pos.y)) 
			{
				
				pressed_b = false;
				HCURSOR Cursor = LoadCursor(NULL, IDC_ARROW);
				SetClassLongPtr(wHandle, GCLP_HCURSOR, reinterpret_cast<LONG_PTR>(Cursor));
			}
		}
	if (pressed_b) { button_s1.setPosition(pos.x - dX, pos.y - dY); }
}


void Button_number3_::button_pressed3_(sf::Event& event, sf::Vector2f pos, sf::RenderWindow & window, sf::WindowHandle& wHandle)
{
	wHandle = window.getSystemHandle();

	if (event.type == sf::Event::MouseButtonPressed)
	{

		if (event.key.code == sf::Mouse::Left)
			if (button_s1.getGlobalBounds().contains(pos.x, pos.y))
			{
				pressed_b = true;
				
				std::cout << "Button is pressed number 2\n";

				//std::this_thread::sleep_for(std::chrono::milliseconds(300));			
				HCURSOR Cursor = LoadCursor(NULL, IDC_HAND);
				SetClassLongPtr(wHandle, GCLP_HCURSOR, reinterpret_cast<LONG_PTR>(Cursor));
				dX = pos.x - button_s1.getPosition().x;
				dY = pos.y - button_s1.getPosition().y;
			}
	}



	if (event.type == sf::Event::MouseButtonReleased)

		if (event.key.code == sf::Mouse::Left)
		{
			if (button_s1.getGlobalBounds().contains(pos.x, pos.y)){
			pressed_b = false;
			HCURSOR Cursor = LoadCursor(NULL, IDC_ARROW);
			SetClassLongPtr(wHandle, GCLP_HCURSOR, reinterpret_cast<LONG_PTR>(Cursor));
			}
		}
	if (pressed_b) { button_s1.setPosition(pos.x - dX, pos.y - dY); }

}


void Button_number2_::button_pressed2_(sf::Event& event, sf::Vector2f pos, sf::RenderWindow & window, sf::WindowHandle& wHandle,float& s)
{
	wHandle = window.getSystemHandle();

	if (event.type == sf::Event::MouseButtonPressed)
	{

		if (event.key.code == sf::Mouse::Left)
			if (button_s1.getGlobalBounds().contains(pos.x, pos.y))
			{
				pressed_b = true;
				std::cout << "Button is pressed number 3\n";
				speed_low(s);
				HCURSOR Cursor = LoadCursor(NULL, IDC_HAND);
				SetClassLongPtr(wHandle, GCLP_HCURSOR, reinterpret_cast<LONG_PTR>(Cursor));
				dX = pos.x - button_s1.getPosition().x;
				dY = pos.y - button_s1.getPosition().y;
			}
	}



	if (event.type == sf::Event::MouseButtonReleased)

		if (event.key.code == sf::Mouse::Left)
		{
			if (button_s1.getGlobalBounds().contains(pos.x, pos.y)) {
			pressed_b = false;
			HCURSOR Cursor = LoadCursor(NULL, IDC_ARROW);
			SetClassLongPtr(wHandle, GCLP_HCURSOR, reinterpret_cast<LONG_PTR>(Cursor));
		}
		}
	if (pressed_b) { button_s1.setPosition(pos.x - dX, pos.y - dY); }

}

float Button_number1_::speed_up(float& a) 
{
	a += 0.1;
	return a;
}

float Button_number2_::speed_low(float& a)
{
	a -= 0.1;
	return a;
}