#include "Snake.h"

const int jumlah_kotak = 30;
const int size_kotak = 24;
const int width = 720;
const int height = 720;

float delay = 0.1;
int level, arah_snake, last_arah_snake, bagian_snake, life_snake, jalan, score, end;

struct Snake
{
    int x, y;
} snake[100];

struct Fruit
{
    int x, y;
} fruit;

int NextLevel();
int Over();

void getFood()
{
    fruit.x = rand() % (jumlah_kotak - 4) + 2;
    fruit.y = rand() % (jumlah_kotak - 8) + 4;
    for (int i = 0; i < bagian_snake; i++) {
        if (snake[i].x == fruit.x && snake[i].y == fruit.y) {
            getFood();
        }
    }
}

void moveSnake()
{
    for (int i = bagian_snake; i > 0; --i)
    {
        snake[i].x = snake[i - 1].x;
        snake[i].y = snake[i - 1].y;
    }

    if (arah_snake == 0) snake[0].y += 1;
    if (arah_snake == 1) snake[0].x -= 1;
    if (arah_snake == 2) snake[0].x += 1;
    if (arah_snake == 3) snake[0].y -= 1;

    if ((snake[0].x == fruit.x) && (snake[0].y == fruit.y))
    {
        bagian_snake++;
        score += 5;
        getFood();
        if (score % 500 == 0)
        {
            jalan = 0;
            bagian_snake = 2;
            delay = delay * 95 / 100;
            NextLevel();
            level++;
        }
    }

    if (snake[0].x > jumlah_kotak) snake[0].x = 0;
    if (snake[0].x < 0) snake[0].x = jumlah_kotak;

    if (snake[0].y > jumlah_kotak) snake[0].y = 0;
    if (snake[0].y < 0) snake[0].y = jumlah_kotak;

}

void arahKeyboard()
{
    if (Keyboard::isKeyPressed(Keyboard::Left) && last_arah_snake != 2) {
        arah_snake = 1;
        jalan = 1;
    }
    if (Keyboard::isKeyPressed(Keyboard::Right) && last_arah_snake != 1) {
        arah_snake = 2;
        jalan = 1;
    }
    if (Keyboard::isKeyPressed(Keyboard::Up) && last_arah_snake != 0) {
        arah_snake = 3;
        jalan = 1;
    }
    if (Keyboard::isKeyPressed(Keyboard::Down) && last_arah_snake != 3) {
        arah_snake = 0;
        jalan = 1;
    }
}

void gameOver()
{
    fruit.x = 10;
    fruit.y = 10;
    snake[0].x = 10;
    snake[0].y = 5;
    life_snake = 1;

    jalan = 0;
    bagian_snake = 2;
    arah_snake = 0;
    last_arah_snake = arah_snake;
    level = 1;
    score = 0;
    end = 0;
}

void borderCheck() {
    if ((snake[0].x == (jumlah_kotak - 1)) && arah_snake == 2) {
        end = 1;
    }
    if ((snake[0].y == 3) && arah_snake == 3) {
        end = 1;
    }
    if ((snake[0].y == (jumlah_kotak - 1)) && arah_snake == 0) {
        end = 1;
    }
    if ((snake[0].x == 0) && arah_snake == 1) {
        end = 1;
    }
}

void collisionCheck(RenderWindow* window) {
    for (int i = 1; i < bagian_snake; i++) {
        if (snake[0].x == snake[i].x && snake[0].y == snake[i].y) {
            bagian_snake = i;
            life_snake--;
        }
    }
}

Snakee::~Snakee()
{

}

int GameSnake()
{
    RenderWindow window(VideoMode(width, height), "Snake Madness!");
    window.setFramerateLimit(60);
    srand(time(0));

    Texture textbackground, textheadUp, textheadDown, textheadLeft, textheadRight, textbody, textfruit, textgate;
    textbackground.loadFromFile("images/background.png");
    textheadUp.loadFromFile("images/headUp.png");
    textheadDown.loadFromFile("images/headDown.png");
    textheadLeft.loadFromFile("images/headLeft.png");
    textheadRight.loadFromFile("images/headRight.png");
    textbody.loadFromFile("images/body.png");
    textfruit.loadFromFile("images/fruit.png");
    textgate.loadFromFile("images/gate.png");

    Sprite spriteBackground(textbackground), spriteheadUp(textheadUp), spriteheadDown(textheadDown), spriteheadLeft(textheadLeft), spriteheadRight(textheadRight), spritebody(textbody), spritefruit(textfruit), spritegate(textgate);

    float timer = 0;
    float time;
    Clock clock;

    gameOver();
    moveSnake();

    Font font;
    if (!font.loadFromFile("fonts/GothicA1-Medium.ttf"))
    {
        std::cerr << ".Error while loading font" << std::endl;
        system("pause");
    }

    while (window.isOpen())
    {
        Event e;
        while (window.pollEvent(e))
            if (e.type == e.Closed)
                window.close();

        arahKeyboard();

        time = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer += time;

        if (timer >= delay) {
            if (jalan != 0)
            {
                moveSnake();
                borderCheck();
                collisionCheck(&window);
                if(end == 1 || life_snake == 0)
                {
                    window.close();
                    Over();
                    return 0;
                };

                timer = 0;
                last_arah_snake = arah_snake;
            }
        }

        window.clear();
        window.draw(spriteBackground);

        for (int i = 0; i < jumlah_kotak; i++)
        {
            spritegate.setPosition(i * size_kotak, 3 * size_kotak);
            window.draw(spritegate);
            spritegate.setPosition(i * size_kotak, (jumlah_kotak - 1) * size_kotak);
            window.draw(spritegate);
            if (i > 3)
            {
                spritegate.setPosition(0 * size_kotak, i * size_kotak);
                window.draw(spritegate);
                spritegate.setPosition((jumlah_kotak - 1) * size_kotak, i * size_kotak);
                window.draw(spritegate);
            }
        }

        for (int i = 0; i < bagian_snake; i++)
        {
            if (i == 0)
            {
                if (arah_snake == 1)
                {
                    spriteheadLeft.setPosition(snake[i].x * size_kotak, snake[i].y * size_kotak);
                    window.draw(spriteheadLeft);
                }
                else if (arah_snake == 2)
                {
                    spriteheadRight.setPosition(snake[i].x * size_kotak, snake[i].y * size_kotak);
                    window.draw(spriteheadRight);
                }
                else if (arah_snake == 3)
                {
                    spriteheadUp.setPosition(snake[i].x * size_kotak, snake[i].y * size_kotak);
                    window.draw(spriteheadUp);
                }
                else if (arah_snake == 0)
                {
                    spriteheadDown.setPosition(snake[i].x * size_kotak, snake[i].y * size_kotak);
                    window.draw(spriteheadDown);
                }
            }
            else
            {
                spritebody.setPosition(snake[i].x * size_kotak, snake[i].y * size_kotak);
                window.draw(spritebody);
            }
        }

        spritefruit.setPosition(fruit.x * size_kotak, fruit.y * size_kotak);
        window.draw(spritefruit);

        Text text;

        std::string stringScore = "Score : " + std::to_string(score);
        text.setPosition(3 * size_kotak, 1 * size_kotak);
        text.setFont(font);
        text.setCharacterSize(24);
        text.setString(stringScore);
        window.draw(text);

        std::string stringLevel = "Level : " + std::to_string(level);
        text.setPosition(10 * size_kotak, 1 * size_kotak);
        text.setFont(font);
        text.setString(stringLevel);
        window.draw(text);

        window.display();
    }
    return 0;
}
