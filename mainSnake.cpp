#include <SFML/Graphics.hpp>

using namespace sf;

const int lebar_window=40; //Lebar tampilan window game.
const int tinggi_window=40; //Tinggi tampilan window game.
const int windowGame=15; //Ukuran winddow game.
const int width=lebar_window*windowGame;
const int hight=tinggi_window*windowGame;

int gerak_ular=1; //Awalan, arah ular, 0,1,2,3.
int lastFrameDirection=gerak_ular;
int bagian_Snake=6; //Jumlah bagian snake diawal game.
int jumlah_Hidup=3; //Jumlah maksimal gigit badan.

struct ular {
    int x;
    int y;
} s[100];

void borderCheck (){
    if ( (s[0].x ==  lebar_window ) && gerak_ular==0 ) s[0].x=0;
    if ( (s[0].x ==  -1) && gerak_ular==2 ) s[0].x=lebar_window-1;
    if ( (s[0].y ==  tinggi_window) && gerak_ular==1 ) s[0].y=0;
    if ( (s[0].y ==  -1) && gerak_ular==3 ) s[0].y=tinggi_window-1;
}

void collisionCheck (RenderWindow *window){
    for (int i=1;i<bagian_Snake;i++)
        if (s[0].x==s[i].x && s[0].y==s[i].y){
            bagian_Snake=i;
            jumlah_Hidup--;
            if (jumlah_Hidup==0){
                window->close();
                printf("Game Selesai!")
                ;
            }
        }
}

void ular_move (){
    for (int i=bagian_Snake;i>0;i--){
        s[i].x = s[i-1].x;
        s[i].y = s[i-1].y;
    }
    if (gerak_ular == 0) s[0].x +=1;
    if (gerak_ular == 1) s[0].y +=1;
    if (gerak_ular == 2) s[0].x -=1;
    if (gerak_ular == 3) s[0].y -=1;
}

void arah_Keyboard (){
    if ( Keyboard::isKeyPressed(Keyboard::Right) &&  lastFrameDirection!= 2 )
        gerak_ular=0;
    if ( Keyboard::isKeyPressed(Keyboard::Down)  &&  lastFrameDirection!= 3 )
        gerak_ular=1;
    if ( Keyboard::isKeyPressed(Keyboard::Left)  &&  lastFrameDirection!= 0 )
        gerak_ular=2;
    if ( Keyboard::isKeyPressed(Keyboard::Up)  && lastFrameDirection!= 1 )
        gerak_ular=3;
}

int main()
{
    RenderWindow window(VideoMode(width,hight),"SNAKE GAME GGWP");
    window.setFramerateLimit(60);

    Texture t1,t2,t3,t4;
    t1.loadFromFile("Images/white.png"); //Get texture background.
    t2.loadFromFile("Images/red.png"); //Get texture badan.
    t3.loadFromFile("Images/green.png"); //Get texture buah.
    t4.loadFromFile("Images/white.png"); //Get texture kepala.

    Sprite sprite1(t1); //texture bg.
    Sprite sprite2(t2); //textire body.
    Sprite sprite3(t4); //texture head.
    Sprite sprite4(t3); //texture fruit.

    float delay=0.1;
    float timer=0;
    float time;
    Clock clock;

    while (window.isOpen()){
        Event e;
        while (window.pollEvent(e))
            if (e.type == e.Closed)
                window.close();

        arah_Keyboard();

        time = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer+=time;

        if (timer>=delay){
            ular_move();
            borderCheck();
            collisionCheck(&window);

            timer=0;
            lastFrameDirection=gerak_ular;
        }

        window.clear();

        sprite3.setPosition(s[0].x*windowGame , s[0].y*windowGame); //kepala ular.
        window.draw(sprite3);

        for (int i=1;i<bagian_Snake;i++){

        sprite2.setPosition( s[i].x*windowGame , s[i].y*windowGame); //badan ular.
        window.draw(sprite2);

        }

        window.display();
    }
}

