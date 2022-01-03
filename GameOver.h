#include <SFML/Graphics.hpp>
#include <string>


class GameOver :
	public State
{
public:
	GameOver();
	~GameOver();


	//Updates komponen
	void update(double deltaT);
	
	//Menggambarkan komponen
	void draw(sf::RenderWindow * w);

	//Memproses komponen 
	void processStuff(double deltaT, sf::Vector2f mousePos);

	//Updates tombol penekanan
	void updateKeyBinds(double deltaT);

	bool switchState(); //memnentukan apakah pemain akan bermain lagi

	void setScore(std::string newScore); //menetapkan skor 

private:
	sf::Font font;
	int *score; //skor pemain

	sf::Text playerScore;//menampilkan skor
	sf::Mouse::Button* playAgain; //izikan pemain opsi play again

	sf::RectangleShape background; //background
	sf::Texture backgroundTexture;

};
