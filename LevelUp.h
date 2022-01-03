#include <SFML/Graphics.hpp>
#define Max_menu_next_level 3

using namespace std;
using namespace sf;

int hit_enter;
class LevelUp
{

public:
	LevelUp(float width, float height);

	void draw(sf::RenderWindow& window);

	int mainMenuPressed()
	{
		return menuNextLevel;
	}

	~LevelUp();
private:
	int menuNextLevel;
	sf::Font font;
	sf::Text menuLevel;

};

