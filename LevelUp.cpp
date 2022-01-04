#include "LevelUp.h"

int NextLevel()
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
                    window.close();
                    hit_enter = 1;

                if (evnt.type == Event::KeyReleased)
                {
                    window.close();
                    hit_enter = 1;
                }
            }

            Texture textBackground;
            textBackground.loadFromFile("images/levelup.jpg");

            Sprite spriteBackground(textBackground);

            window.draw(spriteBackground);
            window.display();
        }

        if (hit_enter == 1)
        {
            break;
        }
    }
    return 0;
}

LevelUp::~LevelUp()
{

}