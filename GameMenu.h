#include <SFML/Graphics.hpp>
#define Max_main_menu 3

class Menuu
{

public:
	Menuu(float width, float height);

	void draw(sf::RenderWindow& window);
	void moveUp();
	void moveDown();

	int mainMenuPressed()
	{
		return mainMenuSelected;
	}

	~Menuu();

private:
	int mainMenuSelected;
	sf::Font font;
	sf::Text mainMenu[Max_main_menu];
};
