#include "HighScore.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <sstream>
#include <time.h>
#include <fstream>
#include <stack>


HighScore::HighScore()
{
	font.loadFromFile("text2.ttf");
	int i = 0;

	ifstream myfile("example.txt");

	
	name.loadFromFile("text2.ttf");

	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			text[i].setString(line);
			arr = line;
			i++;
		}
		myfile.close();
	}
	else cout << "Unable to open file";
}

HighScore::~HighScore()
{
}

void HighScore::draw(sf::RenderWindow &window)
{
	sf::Texture h_score;
	h_score.loadFromFile("back2.jpg");
	
	sf::Sprite high_score;
	high_score.setTexture(h_score);
	high_score.setPosition(-200, -400);
	//high_score.setTextureRect(sf::IntRect(0, 0, 1370, 690));
	sf::Font score;
	score.loadFromFile("text2.ttf");
	sf::Text high;
	high.setFont(score);
	high.setString("HIGH SCORE");
	high.setColor(sf::Color::Cyan);
	high.setCharacterSize(80);
	high.setStyle(sf::Text::Bold);
	high.setPosition(900 / 2 - high.getGlobalBounds().width / 2, 150);

	sf::Font fnt;
	fnt.loadFromFile("text2.ttf");
	sf::Text txt;
	txt.setFont(fnt);
	txt.setString("Press ESCAPE key for the Main Menu");
	txt.setColor(sf::Color::Red);
	txt.setStyle(sf::Text::Bold);
	txt.setCharacterSize(50);
	txt.setPosition(150,600);

	

	while (window.isOpen())
	{

		sf::Event event;

		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();

				break;
			}
		}
		if (sf::Keyboard::isKeyPressed)
		{
			if (event.key.code == sf::Keyboard::Escape)
				break;
		}
		window.clear();
		window.draw(high_score);
		window.draw(txt);
		window.draw(high);
		for (int i = 0; i < 2; i++)
		{
			text[i].setColor(sf::Color::Cyan);
			text[i].setFont(name);
			text[i].setPosition(900 / 2 - text[i].getGlobalBounds().width / 2, 300 + (i * 70));
			text[i].setStyle(sf::Text::Regular);
			text[i].setCharacterSize(50);
			window.draw(text[i]);
		}
		window.display();
	}
}

int HighScore::score()
{
	int x;
	x = stoi(arr);
	return x;
}