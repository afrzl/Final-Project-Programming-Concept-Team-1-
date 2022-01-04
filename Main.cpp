#include "Main.h"

int GameSnake();

int main()
{
    RenderWindow window(VideoMode(720, 720),
        " Snake Madness! ",
        sf::Style::Close);

    Menuu menu(720, 480);

    while (true) {
        while (window.isOpen())
        {
            Event evnt;
            while (window.pollEvent(evnt))
            {
                if (evnt.type == Event::Closed)
                    window.close();
                    page_number = 2;

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

            Texture textBackground;
            textBackground.loadFromFile("images/mainmenu.png");


            Sprite spriteBackground(textBackground);

            window.draw(spriteBackground);
            menu.draw(window);
            window.display();

        }
        
        if (page_number == 0)
        {
            GameSnake();
            break;
        }
        if (page_number == 1)
        {
            tentang();
        }
        if (page_number == 2)
        {
            break;
        }
    }
    return 0;
}

int tentang()
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
                page_number = 2;

                if (evnt.type == Event::KeyReleased)
                {
                    if (evnt.key.code == Keyboard::Enter)
                    {
                        window.close();
                        page_number = 0;
                    }
                }
            }

            // KODINGAN LOGO MENU, LOGO LETAKNYA DIATAS PILIHAN BERMAIN
            Texture textTentang;
            textTentang.loadFromFile("images/tentang.png"); // LETAK LOGO MENU
            Sprite spriteTentang(textTentang);
            window.draw(spriteTentang);
            window.display();

        }

        if (page_number == 0)
        {
            main();
            break;
        }
    }

    return 0;
}