#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>

using namespace sf;

int Snake();
void collisionCheck(RenderWindow* window);
void borderCheck(RenderWindow* window);
void gameOver();
void arahKeyboard();
void moveSnake();
void getFood();

class Snakee
{
	~Snakee();
public:

private:
	sf::Font font;
};
