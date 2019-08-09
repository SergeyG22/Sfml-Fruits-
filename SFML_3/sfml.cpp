#include <SFML/Graphics.hpp>
#include <iostream>
#include <Windows.h>
#include <string>
#include <vector>
#include "bug.h"
#include "button.h"
#include "Home.h"

////БОЖИЕ КОРОВКИ

using namespace sf;




int main()
{
	setlocale(LC_ALL,"russian");
	
	sf::RenderWindow window(sf::VideoMode(800,600), "SFML works!");
	window.setMouseCursorVisible(false);
	sf::WindowHandle wHandle;	
	sf::Vector2i pixelPos;
	sf::Vector2f pos;
	std::vector<char>v;
	Bug bug;
	Bug_2t bug_2t;
	Home home;
	
	Button_number1_ button1_;
	Button_number2_ button2_;
	Button_number3_ button3_;
	button1_.set_position(60,235);
	button2_.set_position(60,340);
	button3_.set_position(200,500);

	Clock clock;

	sf::View fixed = window.getView();
	sf::Texture texture_cursor;
	texture_cursor.loadFromFile("cursor.png");
	sf::Sprite sprite_cursor(texture_cursor);



	sf::Font font_;
	if (!font_.loadFromFile("fonts_online_.ttf"))
	{
		std::cout << "FAIL LOADING text";
	}




	sf::Font font;
	if (!font.loadFromFile("fonts_online.ttf"))
	{
		std::cout << "FAIL LOADING text";
	}
	


	sf::String str = L" ";
	sf::Text txt;
	txt.setPosition(295, 50);
	txt.setFont(font);
	txt.setScale(1.5, 1.5);
	txt.setFillColor(sf::Color::White);
	txt.setOutlineColor(sf::Color::Red);
	txt.setOutlineThickness(1.0);













	while (window.isOpen())
	{

		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 4000;


		sf::Event event;
		while (window.pollEvent(event))
		{
			pixelPos = sf::Mouse::getPosition(window);
			pos = window.mapPixelToCoords(pixelPos);

			button1_.button_pressed1_(event, pos, window, wHandle,bug.speed);
			button2_.button_pressed2_(event, pos, window, wHandle,bug.speed);
			button3_.button_pressed3_(event, pos, window, wHandle);

			bug.drag_and_drop_bug(event, pos, window, wHandle);
			bug_2t.drag_and_drop_bug(event, pos, window, wHandle);
			

			if (bug.bug_s.getGlobalBounds().intersects(home.home_s.getGlobalBounds()))
			{

				if (event.type == sf::Event::MouseButtonReleased)
				{

					if (event.key.code == sf::Mouse::Left)
					{
					
						bug.hold_button = false;
						bug.bug_s.setColor(sf::Color::Transparent);
						bug.bug_s.setPosition(100,100);// правит баг когда жук исчезает на границе дома и не реагирует на мышь

						bug.sleep_home = true;
					}
				}

			}



			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.key.code == sf::Mouse::Left)
				{
					if (bug.bug_s.getGlobalBounds().contains(pos.x, pos.y))
					{
						
						bug.bug_s.setColor(sf::Color::White);
						bug.sleep_home = false;
					}
				}
			}


			if (bug_2t.bug_s.getGlobalBounds().intersects(home.home_s.getGlobalBounds()))
			{

				if (event.type == sf::Event::MouseButtonReleased)
				{

					if (event.key.code == sf::Mouse::Left)
					{

						bug_2t.hold_button = false;
						bug_2t.bug_s.setColor(sf::Color::Transparent);
						bug_2t.bug_s.setPosition(100, 100);// правит баг когда жук исчезает на границе дома и не реагирует на мышь


						bug_2t.sleep_home = true;
					}
				}

			}


			if (event.type == sf::Event::MouseButtonPressed)
			{

				if (event.key.code == sf::Mouse::Left)
				{
					if (bug_2t.bug_s.getGlobalBounds().contains(pos.x, pos.y))
					{

						bug_2t.bug_s.setColor(sf::Color::White);
						bug_2t.sleep_home = false;
					}
				}

			}
			
			if (event.type == sf::Event::TextEntered)
			{
				// Handle ASCII characters only
              
				if (event.text.unicode < 128)
				{
					str += static_cast<char>(event.text.unicode);
					txt.setString(str);					
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
				{
					break;
				}
			}

			

			if (event.type == sf::Event::Closed)
				window.close();
		}

		sprite_cursor.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));
		window.clear();

		window.draw(bug.loadSpriteFone("fone.png"));
		bug.movement_(time);
		bug_2t.movement_(time);

	//		window.draw(button1_.loadSpriteButton1("button.png"));
	

		//	window.draw(button2_.loadSpriteButton1("button2.png"));
	

		
		if (button3_.pressed_b)
		{
			//window.draw(button3_.loadSpriteButton1("button2.png"));
		}
		if (bug.sleep_home)
		{
			window.draw(home.loadSpriteZZZ("zzz.png"));
		}

		if (bug_2t.sleep_home)
		{
			window.draw(home.loadSpriteZZZ("zzz.png"));
		}
		if (sf::Keyboard::isKeyPressed(Keyboard::Backspace))
		{
			str.clear();			
		}
		
		window.draw(home.loadSpriteHome("home.png"));	
		window.draw(bug.loadSpriteBug("bug.png"));	
		window.draw(bug.loadSpriteApple("apple.png"));		
		window.draw(bug_2t.loadSpriteBug("bug.png"));
		window.draw(bug_2t.loadSpriteApple("apple.png"));
	    window.draw(sprite_cursor);
		
	    window.display();
	}

	return 0;
}

