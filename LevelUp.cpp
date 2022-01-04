#include "LevelUp.h"

int NextLevel()
{
    RenderWindow window(VideoMode(720, 720),    // UKURAN WINDOW
        " Snake Madness! ",           // NAMA WINDOW AWAL
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

            // KODINGAN LOGO MENU, LOGO LETAKNYA DIATAS PILIHAN BERMAIN
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