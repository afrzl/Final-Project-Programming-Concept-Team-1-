#include "Main.h"

int Snake();

int main()
{
    RenderWindow window(VideoMode(720, 720),    // UKURAN WINDOW
        " Snake Game! ",           // NAMA WINDOW AWAL
        sf::Style::Close);

    Menuu menu(150, 400);   // UKURAN PREPOSISI TEKS DI WINDOW AWAL

    while (true) {
        while (window.isOpen())
        {
            Event evnt;
            while (window.pollEvent(evnt))
            {
                if (evnt.type == Event::Closed)
                    window.close();

                if (evnt.type == Event::KeyReleased)
                {
                    if (evnt.key.code == Keyboard::Up)
                    {
                        menu.moveUp();
                        break;
                    }

                    if (evnt.key.code == Keyboard::Down)
                    {
                        menu.moveDown();
                        break;
                    }

                    if (evnt.key.code == Keyboard::Enter)
                    {

                        if (menu.mainMenuPressed() == 0)
                        {
                            window.close();
                            page_number = 0;
                        }
                        if (menu.mainMenuPressed() == 1)
                        {
                            window.close();
                            page_number = 1;
                        }
                        if (menu.mainMenuPressed() == 2)
                        {
                            window.close();
                            page_number = 2;
                        }
                    }
                }


            }

            // KODINGAN LOGO MENU, LOGO LETAKNYA DIATAS PILIHAN BERMAIN
            Texture logo;
            logo.loadFromFile(" XXXXXXXXX "); // LETAK LOGO MENU

            Sprite sp(logo);

            sp.setScale(.4f, .2f); // UKURAN LOGO DI MENU

            window.clear(sf::Color::Blue); //Background dari MENU nya
            menu.draw(window);
            window.draw(sp);
            window.display();

        }
        if (page_number == 0)
        {
            Snake();
            break;
        }
        if (page_number == 1)
        {
            // KODINGAN TENTANG GAME
            printf("Tentang Game");
            break;
        }
        if (page_number == 2)
        {
            // KODINGAN KELUAR GAME
            break;
        }
    }
    return 0;
}