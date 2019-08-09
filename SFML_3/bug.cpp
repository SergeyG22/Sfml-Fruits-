#include "bug.h"
#include <string>
#include <cmath>
#include <Windows.h>
#include "Home.h"


sf::Sprite Bug::loadSpriteBug(std::string filename)
{
	if (!bug_t.loadFromFile(filename)) { std::cout << "Load from error\n"; };
	bug_s.setTexture(bug_t);
	return bug_s;
}


void Bug::movement_ (float& time){
	if (hold_button)
	{
	bug_s.setPosition(positionX, positionY);
    }
	
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) { hold_button = false; }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) { 
		
		hold_button = true; }
	
	bug_s.setOrigin(50,50);
	if (hold_button) {
		
			dX = positionX - random_positionX;
			dY = positionY - random_positionY;
	}
	angle = (atan2(dY,dX)) * 180 / 3.14159265;

	distance = sqrt((random_positionX - positionX)*(random_positionX - positionX) + (random_positionY - positionY)*(random_positionY - positionY));

	if(hold_button)
	{
			positionX += speed*time*(random_positionX - positionX) / distance;
			positionY += speed*time*(random_positionY - positionY) / distance;
	}
	bug_s.setRotation(angle);

	if (bug_s.getGlobalBounds().intersects(apple_s.getGlobalBounds()))
	{
		 ++event_current;
		 rand_();
		 
	}



		
}

sf::Sprite Bug::loadSpriteFone(std::string filename)
{

	if (!fone_t.loadFromFile(filename))
	{
		std::cout << "Fail loading texture\n";
	};
	fone_s.setTexture(fone_t);

	return fone_s;
}

sf::Sprite Bug::loadSpriteApple(std::string filename)
{
	
	if (!apple_t.loadFromFile(name_fruit_banana))
	{
		std::cout << "Fail loading texture\n";
	};
	apple_s.setTexture(apple_t);
	apple_s.setOrigin(32.5,40);
	apple_s.setPosition(random_positionX, random_positionY);
	
		
	return apple_s;
}

void Bug::rand_()
{
	


	

	std::mt19937 mt(rd());// генератор случайных чисел для координат
	std::uniform_real_distribution<double> dist(0.0, 800.0);

	std::mt19937 mt_(rd_());
	std::uniform_real_distribution<double> dist_(0.0, 600.0);

	random_positionX = (int)dist(mt);
	random_positionY = (int)dist_(mt_);

	std::mt19937 mt_fruit(rd_f());// генератор случайных чисел для фруктов
	std::uniform_real_distribution<double>r_fruit(0,5);


	total = (int)r_fruit(rd_f);
	name_fruit_banana = object[total];

	



	if (a == 1) {
		system("cls");
		a = 0;
	}
	

}

void Bug::drag_and_drop_bug(sf::Event& event, sf::Vector2f pos, sf::RenderWindow & window, sf::WindowHandle& wHandle)
{
	
	wHandle = window.getSystemHandle();
	
	
	if (event.type == sf::Event::MouseButtonPressed)
	{

		if (event.key.code == sf::Mouse::Left)
			if (bug_s.getGlobalBounds().contains(pos.x, pos.y))
			{
				
				pressed_b = true;
				hold_button = false;
				HCURSOR Cursor = LoadCursor(NULL, IDC_HAND);
				SetClassLongPtr(wHandle, GCLP_HCURSOR, reinterpret_cast<LONG_PTR>(Cursor));
				dX = pos.x - bug_s.getPosition().x;
				dY = pos.y - bug_s.getPosition().y;
			}
	}

	if (event.type == sf::Event::MouseButtonReleased)

		if (event.key.code == sf::Mouse::Left)
		{
			if (bug_s.getGlobalBounds().contains(pos.x, pos.y))
			{
				pressed_b = false;
				hold_button = true;	
				HCURSOR Cursor = LoadCursor(NULL, IDC_ARROW);
				SetClassLongPtr(wHandle, GCLP_HCURSOR, reinterpret_cast<LONG_PTR>(Cursor));
			}
		}
	if (pressed_b)
	{
		bug_s.setPosition(pos.x - dX, pos.y - dY);
		positionX = pos.x - dX;
		positionY = pos.y - dY;		
	}

}



