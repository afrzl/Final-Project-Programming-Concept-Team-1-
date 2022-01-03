#include "GameOver.h"
#include <iostream>


GameOver::GameOver()
{
	this->font.loadFromFile("Fontsxxxxx.ttf");
	this->backgroundTexture.loadFromFile("xxxxx.png");

	this->score = nullptr;

	//Text skor pemain
	this->playerScore.setPosition(sf::Vector2f(350, 200));
	this->playerScore.setFillColor(sf::Color::Black);
	this->playerScore.setFont(this->font);
	this->playerScore.setCharacterSize(80);


	//Text tombol play
	this->playAgain = new Button(sf::Vector2f(275,400),nullptr,sf::Vector2f(300,100),
		sf::Color(200,200,200), sf::Color(140,140,140), sf::Color(100,100,100), &this->font, "Play Again",
		45,sf::Color::Black);
	this->playAgain->setTextPos(sf::Vector2f(300, 400));

	//Background
	this->background.setSize(sf::Vector2f(800, 800));
	//this->background.setFillColor(sf::Color::Cyan);
	this->background.setTexture(&this->backgroundTexture);
}


GameOver::~GameOver()
{
	delete this->playAgain;
}


//Update komponen
void GameOver::update(double deltaT)
{
	this->updateKeyBinds(deltaT); //Memeriksa apakah pemain ingin Keluar
}

//Menggambar komponen dalam state
void GameOver::draw(sf::RenderWindow * w)
{
	//Pertama Background
	w->draw(this->background);
	//Menggambarkan tombol
	w->draw(this->playerScore); //Menampilkan skor pemain
	this->playAgain->draw(w); //Menampilkan tombol play again
}

//Memproses komponen
void GameOver::processStuff(double deltaT, sf::Vector2f mousePos)
{
	//Updates skor text
	this->playerScore.setString(std::to_string(State::getHolderScore()));
	this->playAgain->checkState(mousePos);
}

//Updates penekanan tombol 
void GameOver::updateKeyBinds(double deltaT)
{
	State::checkForQuit(); //Memeriksa apakah pemain ingin keluar
}


//Menentukan apakah pemain ingin bermain lagi
bool GameOver::switchState()
{
	//Jika memilih tombol PlayAgain maka akan mengulang game
	return (this->playAgain->isPressed());
}


//Updates skor pemain
void GameOver::setScore(std::string newScore)
{
	this->playerScore.setString(newScore);
}
