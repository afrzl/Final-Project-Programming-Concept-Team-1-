#include "LevelUp.h"

int NextLevel()
{
    RenderWindow window(VideoMode(720, 720),    // UKURAN WINDOW
        " Snake Game! ",           // NAMA WINDOW AWAL
        sf::Style::Close);

    LevelUp menu(720, 720);   // UKURAN PREPOSISI TEKS DI WINDOW AWAL

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
                    if (evnt.key.code == Keyboard::Enter)
                    {
                        window.close();
                        hit_enter = 1;
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

        if (hit_enter == 1)
        {
            break;
        }
    }
    return 0;
}

LevelUp::LevelUp(float width, float height)
{

    if (!font.loadFromFile("fonts/GothicA1-Medium.ttf")) {} //FONT MENU LUR...

    menuLevel.setFont(font);
    menuLevel.setFillColor(sf::Color::Green);
    menuLevel.setString("LEVEL UP!");
    menuLevel.setCharacterSize(40);
    menuLevel.setPosition(sf::Vector2f(width / 2 - 50, height / 2 - 50));
}


LevelUp::~LevelUp()
{

}

// Draw Main Menu
void LevelUp::draw(sf::RenderWindow& window)
{
    window.draw(menuLevel);
}