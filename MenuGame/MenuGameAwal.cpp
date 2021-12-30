#include "MenuGameAwal.h"

Menuu::Menuu(float width, float height)
{

	if(!font.loadFromFile("XXXXXXX.ttf")){} //FONT MENU LUR...

	mainMenu[0].setFont(font);
	mainMenu[0].setFillColor(sf::Color::Green);
	mainMenu[0].setString("Bermain");
	mainMenu[0].setCharacterSize(40);
	mainMenu[0].setPosition(sf::Vector2f(width / 2 - 50, height / (Max_main_menu + 1)));

	mainMenu[1].setFont(font);
	mainMenu[1].setFillColor(sf::Color::White);
	mainMenu[1].setString("Tentang");
	mainMenu[1].setCharacterSize(40);
	mainMenu[1].setPosition(sf::Vector2f(width / 2 - 50, height / (Max_main_menu + 1) * 2));

	mainMenu[2].setFont(font);
	mainMenu[2].setFillColor(sf::Color::White);
	mainMenu[2].setString("Keluar");
	mainMenu[2].setCharacterSize(40);
	mainMenu[2].setPosition(sf::Vector2f(width / 2 - 50, height / (Max_main_menu + 1) * 3));

	mainMenuSelected = 0;
}


Menuu::~Menuu()
{

}

// Draw Main Menu
void Menuu::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < 3; i++)
	{
		window.draw(mainMenu[i]);
	}
}

// PILIHAN KEATAS
void Menuu::moveUp()
{
	if (mainMenuSelected - 1 >= -1)
	{
		mainMenu[mainMenuSelected].setFillColor(sf::Color::White);

		mainMenuSelected--;
		if (mainMenuSelected == -1)
		{
			mainMenuSelected = 2;
		}
		mainMenu[mainMenuSelected].setFillColor(sf::Color::Green);
	}
}


// PILIHAN KEBAWAH
void Menuu::moveDown()
{
	if (mainMenuSelected + 1 <= Max_main_menu)
	{
		mainMenu[mainMenuSelected].setFillColor(sf::Color::White);

		mainMenuSelected++;
		if (mainMenuSelected == 3)
		{
			mainMenuSelected = 0;
		}
		mainMenu[mainMenuSelected].setFillColor(sf::Color::Green);
	}
}
