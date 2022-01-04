#include "GameOver.h"

int main();
int GameSnake();

int Over()
{
    RenderWindow window(VideoMode(720, 720),
        " Snake Madness! ",
        sf::Style::Close);

    while (true) {
        while (window.isOpen())
        {
            Event evnt;
            while (window.pollEvent(evnt))
            {
                if (evnt.type == Event::Closed)
                {
                    window.close();
                    hitEnter = 1;
                }

                if (evnt.type == Event::KeyReleased)
                {
                    window.close();
                    hitEnter = 1;
                }
            }

            Texture textbackground;
            textbackground.loadFromFile("images/gameover.jpg");

            Sprite spriteBackground(textbackground);

            window.draw(spriteBackground);
            window.display();

        }
        if (hitEnter == 1)
        {
            main();
            break;
        }
    }
    return 0;
}


GameOver::~GameOver()
{

}