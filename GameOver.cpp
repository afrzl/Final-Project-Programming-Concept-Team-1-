#include "GameOver.h"

int main();
int GameSnake();

int Over()
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

            // KODINGAN LOGO MENU, LOGO LETAKNYA DIATAS PILIHAN BERMAIN
            Texture textbackground;
            textbackground.loadFromFile("images/gameover.jpg"); // LETAK LOGO MENU

            Sprite spriteBackground(textbackground);

            window.clear(sf::Color::Black); //Background dari MENU nya
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