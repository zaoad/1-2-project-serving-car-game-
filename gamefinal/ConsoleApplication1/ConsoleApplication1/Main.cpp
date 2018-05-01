#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <SFML/System.hpp>
#include <Windows.h>
#include "time.h"
#include <sstream>
#include <string.h>
#include <fstream>
#include "HighScore.h"
#include <random>

using namespace std;
using namespace sf;

int ppp;
int c = 0;
int zz = 1;
int cr = 1;
int j = 1;
int lev1 = 1;
int lev2= 2;
int lev3 = 3;

bool game = true;

bool release = true;

int main()
{
	j = 1;
	cr = 1;
	srand(time(0));
	sf::RenderWindow window(sf::VideoMode(1370, 680), "Survivor");
	window.setVerticalSyncEnabled(true);
	int count = 0;
	static int flag=0;
//////sound/////
/*	sf::SoundBuffer buffer0,buffer1,buffer2;
	sf::Sound gari,horn,crash ;
	if (!buffer0.loadFromFile("car1.wav"))
	{
		std::cout << "Error" << std::endl;
	}

	gari.setBuffer(buffer0);
	gari.setVolume(60);

	if (!buffer1.loadFromFile("horn.wav"))
	{
		std::cout << "Error" << std::endl;
	}
	horn.setBuffer(buffer1);
	horn.setVolume(80);
	if (!buffer2.loadFromFile("crash.wav"))
	{
		std::cout << "Error" << std::endl;
	}

	crash.setBuffer(buffer2);
	crash.setVolume(80);
*/
		goto main_menu;
	main_menu:{
		///////////main menu image//////////////////////
	count = 0;
	zz = 1;
	j = 1;
	cr = 1;
	sf::Texture main_menu;
		main_menu.loadFromFile("front.jpg");
		sf::Sprite menu;
		menu.setTexture(main_menu);
		////////////////////////////////////////////////
		sf::Music music, music1;
		music.openFromFile("menusound.wav");
		music.setVolume(40);
		music1.openFromFile("highscoremusic.wav");
		music1.setVolume(50);

		////////////////////////////////////////////////////////////

		music.play();

		//////////////////////main menu//////////////////////////////
		sf::Font title;
		title.loadFromFile("text.ttf");


		sf::Text ttl("Surviving Car", title, 90);
		ttl.setStyle(sf::Text::Bold);
		ttl.setColor(sf::Color::Black);

		ttl.setPosition(900 / 2 - ttl.getGlobalBounds().width / 2, 150);
		sf::Mouse::setPosition(sf::Vector2i(10, 100), window);



		sf::Text menu_text[4];

		window.draw(menu);
		window.draw(ttl);

		string str[] = { "New Game", "High Score", "Credit", "Exit" };
		int k;
		for (k = 0; k < 4; k++)
		{
			menu_text[k].setFont(title);
			menu_text[k].setCharacterSize(45);
			menu_text[k].setString(str[k]);
			menu_text[k].setColor(sf::Color::Red);
			menu_text[k].setPosition(550, 300 + k * 100);
			window.draw(menu_text[k]);
		}

		while (window.isOpen())
		{
			sf::Event event;
			sf::Vector2f mouse(sf::Mouse::getPosition(window));
			while (window.pollEvent(event))
			{
				switch (event.type)
				{
				case sf::Event::Closed:
					window.close();

					break;

				case sf::Event::MouseButtonPressed:

					if (release && (menu_text[0].getGlobalBounds().contains(mouse)))
						goto level;

					if (release && (menu_text[1].getGlobalBounds().contains(mouse)))
					{
						music.stop();
						music1.play();
						HighScore h;
						HighScore HighScore();
						h.draw(window);

						goto main_menu;
					}
					if (release && (menu_text[2].getGlobalBounds().contains(mouse))){
						goto credit_game;
						
					}
					if (release && (menu_text[3].getGlobalBounds().contains(mouse)))
						goto exit_game;

					release = false;
					break;

				case sf::Event::MouseButtonReleased:
					release = true;
					break;
				}

			}

			window.draw(menu);
			window.draw(ttl);




			if (menu_text[0].getGlobalBounds().contains(mouse))
			{
				menu_text[0].setColor(sf::Color::Blue);
				menu_text[0].setCharacterSize(55);
			}
			else
			{
				menu_text[0].setColor(sf::Color::Red);
				menu_text[0].setCharacterSize(45);
			}

			if (menu_text[1].getGlobalBounds().contains(mouse))
			{
				menu_text[1].setColor(sf::Color::Green);
				menu_text[1].setCharacterSize(55);
			}
			else
			{
				menu_text[1].setColor(sf::Color::Red);
				menu_text[1].setCharacterSize(45);
			}

			if (menu_text[2].getGlobalBounds().contains(mouse))
			{
				menu_text[2].setColor(sf::Color::Cyan);
				menu_text[2].setCharacterSize(55);
			}
			else
			{
				menu_text[2].setColor(sf::Color::Red);
				menu_text[2].setCharacterSize(45);
			}
			if (menu_text[3].getGlobalBounds().contains(mouse))
			{
				menu_text[3].setColor(sf::Color::Magenta);
				menu_text[3].setCharacterSize(55);
			}
			else
			{
				menu_text[3].setColor(sf::Color::Red);
				menu_text[3].setCharacterSize(45);
			}

			window.draw(menu_text[0]);
			window.draw(menu_text[1]);
			window.draw(menu_text[2]);
			window.draw(menu_text[3]);
			window.display();
		}
	}


level:{
	///////////main menu image//////////////////////
	count = 0;
	zz = 1;
	sf::Texture level;
	level.loadFromFile("front.jpg");
	sf::Sprite level0;
	level0.setTexture(level);
	////////////////////////////////////////////////
	sf::Music music, music1;
	music.openFromFile("menusound.wav");
	music.setVolume(40);

	music1.openFromFile("highscoremusic.wav");
	music1.setVolume(50);

	////////////////////////////////////////////////////////////

	music.play();

	//////////////////////main menu//////////////////////////////
	sf::Font title;
	title.loadFromFile("text.ttf");


	sf::Text ttl("LEVEL", title, 90);
	ttl.setStyle(sf::Text::Bold);
	ttl.setColor(sf::Color::Black);

	ttl.setPosition(900 / 2 - ttl.getGlobalBounds().width / 2, 150);
	sf::Mouse::setPosition(sf::Vector2i(10, 100), window);



	sf::Text level_text[3];

	window.draw(level0);
	window.draw(ttl);

	string str[] = { "Level 1", "Level 2", "Level 3" };
	int k;
	for (k = 0; k < 3; k++)
	{
		level_text[k].setFont(title);
		level_text[k].setCharacterSize(45);
		level_text[k].setString(str[k]);
		level_text[k].setColor(sf::Color::Red);
		level_text[k].setPosition(550, 300 + k * 100);
		window.draw(level_text[k]);
	}

	while (window.isOpen())
	{
		sf::Event event;
		sf::Vector2f mouse(sf::Mouse::getPosition(window));
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();

				break;

			case sf::Event::MouseButtonPressed:

				if (release && (level_text[0].getGlobalBounds().contains(mouse)))
				{
					count = 0;
					goto game1;
					lev1 = 2;
					
				}


				if (release && (level_text[1].getGlobalBounds().contains(mouse)))
				{
					count = 51;
					goto game1;
					lev2 = 2;
				}
				if (release && (level_text[2].getGlobalBounds().contains(mouse)))
				{
					count = 95;
					goto game1;
					lev3 = 2;
				}

				release = false;
				break;

			case sf::Event::MouseButtonReleased:
				release = true;
				break;
			}

		}

		window.draw(level0);
		window.draw(ttl);




		if (level_text[0].getGlobalBounds().contains(mouse))
		{
			level_text[0].setColor(sf::Color::Cyan);
			level_text[0].setCharacterSize(55);
		}
		else
		{
			level_text[0].setColor(sf::Color::Red);
			level_text[0].setCharacterSize(45);
		}
		if (level_text[1].getGlobalBounds().contains(mouse))
		{
			level_text[1].setColor(sf::Color::Green);
			level_text[1].setCharacterSize(55);
		}
		else
		{
			level_text[1].setColor(sf::Color::Red);
			level_text[1].setCharacterSize(45);
		}
		if (level_text[2].getGlobalBounds().contains(mouse))
		{
			level_text[2].setColor(sf::Color::Magenta);
			level_text[2].setCharacterSize(55);
		}
		else
		{
			level_text[2].setColor(sf::Color::Red);
			level_text[2].setCharacterSize(45);
		}


		window.draw(level_text[0]);
		window.draw(level_text[1]);
		window.draw(level_text[2]);

		window.display();
	}
}



credit_game:
	{
		sf::RenderWindow window(sf::VideoMode(1370, 690), "Moving a shape");

		Texture t50,t51;
		sf::Music  music2;
		
		music2.openFromFile("highscoremusic.wav");
		music2.setVolume(50);
		music2.play();
		if (!t50.loadFromFile("credit.jpg"))
			cout << "error" << endl;
		t51.loadFromFile("zk.png");
		Sprite Capture(t50),capture1(t51);
		Capture.setPosition(0, 0);
		capture1.setPosition(400, 250);

		while (window.isOpen()){
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
					goto main_menu;
			}




			window.clear();

			window.draw(Capture);
			window.draw(capture1);
			window.display();
		}

	}



game1:
	{
		Texture t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t30, t31, t32, t33;
		Texture t15, t16, t17, t18, t19, t20, t21, t22, t23, t24, t25, t26, t27, t28, t34,t35;
		Texture t36, t37, t38,t39;
		t15.loadFromFile("hgrass.png");
		t30.loadFromFile("go.png");
		t16.loadFromFile("carcanfly.png");
		t1.loadFromFile("mcar1.png");
		t2.loadFromFile("road1.png");
		t3.loadFromFile("roadrun.png");
		t4.loadFromFile("roadrun.png");
		t5.loadFromFile("polz.png");
		t6.loadFromFile("truckb.png");
		t7.loadFromFile("road1.png");
		t8.loadFromFile("race.png");
		t9.loadFromFile("sondorz.png");
		t10.loadFromFile("road1.png");
		t11.loadFromFile("lalcarz.png");
		t12.loadFromFile("taxib.png");
		t13.loadFromFile("bluebb.png");
		t14.loadFromFile("redbb.png");
		t17.loadFromFile("sidewalk.png");
		t18.loadFromFile("sidewalk.png");
		t31.loadFromFile("firet.png");
		t19.loadFromFile("mcar2.png");
		t20.loadFromFile("mcar3.png");
		t21.loadFromFile("mcar4.png");
		t22.loadFromFile("bons.png");
		t23.loadFromFile("b.png");
		t24.loadFromFile("back3.png");
		t25.loadFromFile("grass.png");
		t26.loadFromFile("rasta.png");
		t27.loadFromFile("hgrass.png");
		t32.loadFromFile("back1.png");
		t33.loadFromFile("ladeywlk.png");
		t34.loadFromFile("baby.png");
		t35.loadFromFile("countline.png");
		t36.loadFromFile("scoreback.png");
		t37.loadFromFile("scoreback.png");
		t38.loadFromFile("scoreback.png");
		t39.loadFromFile("scoreback.png");
		Sprite car1(t1), ima(t2), border(t3), border1(t4), fish2(t5), fish3(t6), ima1(t7), truck1(t8), ambulance(t9);
		Sprite race1(t11), race2(t12), race3(t13), race4(t14), side1(t17), side2(t18), grass(t25);
		Sprite h1(t15), carfly(t16), car2(t19), car3(t20), car4(t21), bonus(t22), policeb(t23), sidebackground(t24), h0(t26), hf(t27), fire(t31), sidebackground1(t32);
		Sprite lady(t33), baby(t34),line(t35),sback(t36),grasso(t37),h1o(t38),hfo(t39);
		ima.setTexture(t2);
		ima1.setTexture(t7);
		
		//////////music/////
		sf::Music musicc;
		musicc.openFromFile("garirawaj.wav");
		musicc.setVolume(60);
		musicc.setLoop(true);
		musicc.play();

		sf::SoundBuffer buffer1,buffer2;
		sf::Sound horn,crash;

		if (!buffer1.loadFromFile("jumpsong.wav"))
		{
			std::cout << "Error" << std::endl;
		}

		horn.setBuffer(buffer1);
		horn.setVolume(80);

		if (!buffer2.loadFromFile("crash1.wav"))
		{
			std::cout << "Error" << std::endl;
		}

		crash.setBuffer(buffer2);
		crash.setVolume(80);


        if (zz == 1){
			game = true;
			cout << "zz  1" << endl;
		}
		else {
			game = false;

		}

		int walk = 0;
		int lal = 1;
		int c = 1;
		int bby = 1;
		int ldy = 1;
		int po = 1;
		int fly = 30;
		int car = 0;
		int r3 = 1;
		int r2 = 1;
		int hol = 1;
		int r1 = 1;
		int blu = 1;
		int am = 4;
		int tr = 3;
		int f3 = 2;
		int f2 = 1;
		int r4 = 1;
		int beg = 1;
		int num = 3;
		int  jump = 3, delay = 50;
		int kk = 1;
		int pol = 1;
		int trk = 1; int fis2 = 1; int fis3 = 1; int ambu = 1; int r1st ; int r2nd = 1; int r3rd = 1; int r4th = 1;

		while (window.isOpen()){
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
			window.clear();
			
    if (game){
            cout << "zz  1" << endl;
            c++;
            fly++;
            car++;
            delay--;
			r1++;
			po++;

			if (fly > 24){
				if (car1.getGlobalBounds().intersects(truck1.getGlobalBounds()) || car1.getGlobalBounds().intersects(race1.getGlobalBounds()) || car1.getGlobalBounds().intersects(race2.getGlobalBounds()) || car1.getGlobalBounds().intersects(race3.getGlobalBounds()) || car1.getGlobalBounds().intersects(race4.getGlobalBounds()) || car1.getGlobalBounds().intersects(fish2.getGlobalBounds()) || car1.getGlobalBounds().intersects(fish3.getGlobalBounds()) || car1.getGlobalBounds().intersects(ambulance.getGlobalBounds()) || car1.getGlobalBounds().intersects(policeb.getGlobalBounds()) || car1.getGlobalBounds().intersects(lady.getGlobalBounds()) || car1.getGlobalBounds().intersects(baby.getGlobalBounds()))
				{
					j = j+1;

					cout << "j=2" << endl;
					//goto gameovr;
				}
			}
			if (j == 2){//carmove
				if (event.type == sf::Event::KeyPressed){
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
						if (car1.getPosition().y > -600){
							car1.move(0, -5);
							car2.move(0, -5);
							car3.move(0, -5);
							car4.move(0, -5);
							fire.move(0, -5);
						}
						Sleep(1);
					}
				}

				if (event.type == sf::Event::KeyPressed){
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
						if (car1.getPosition().y < 0){
							car1.move(0, 5);
							car2.move(0, 5);
							car3.move(0, 5);
							car4.move(0, 5);
							fire.move(0, 5);
						}
						Sleep(1);
					}
				}

				if (event.type == sf::Event::KeyPressed){
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
						if (car1.getPosition().x > -47){
							car1.move(-5, 0);
							car2.move(-5, 0);
							car3.move(-5, 0);
							car4.move(-5, 0);
							fire.move(-5, 0);
						}
						Sleep(1);
					}
				}

				if (event.type == sf::Event::KeyPressed){
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
						if (car1.getPosition().x < 260){
							car1.move(5, 0);
							car2.move(5, 0);
							car3.move(5, 0);
							car4.move(5, 0);
							fire.move(5, 0);
						}
						Sleep(1);
					}
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)){
					horn.play();
				}
				//fly car
				if (delay < 70){
					if (event.type == sf::Event::KeyPressed){
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)){
							if (jump > 0){
								carfly.setPosition(car1.getPosition().x, car1.getPosition().y);
								//car1.setPosition(100,100 );
								car1.move(0, -4);
								car2.move(0, -4);
								car3.move(0, -4);
								car4.move(0, -4);
								fire.move(0, -4);
								fly = 0;
								jump = jump - 1;
								delay = 100;
							}
						}
					}
				}
			}
			//vehiles stand still when people walk over

			if (fly < 25)
			{
				carfly.move(0, -4);
			}
			if (fly == 24){
				car1.move(0, -96);
				car2.move(0, -96);
				car3.move(0, -96);
				car4.move(0, -96);
				fire.move(0, -96);
			}
			//jump bonus



			if (border.getPosition().y > 45){

				border.setPosition(0, 0);
			}
			if (border1.getPosition().y > 45){

				border1.setPosition(0, 0);

			}
			//car return
			//////////////////////////********************************leval1***********************************///////////
			if (count <= 50)
			{
				if (c % 500 == 499&&fish2.getPosition().y>750){
					fis2 = 1;
					int xx = rand() % 4;

					if (xx == 0)
					{
						fish2.setPosition(0, 0);
					}
					if (xx == 1)
					{
						fish2.setPosition(100, 0);
					}
					if (xx == 2)
					{
						fish2.setPosition(190, 0);
					}
					if (xx == 3)
					{
						fish2.setPosition(270, 0);
					}

				}

				if (c % 450 == 449 && fish3.getPosition().y>750)
				{

					fis3 = 1;
					int xy = rand() % 4;
					if (xy == 0)
					{
						fish3.setPosition(0, 0);
					}
					if (xy == 1)
					{
						fish3.setPosition(-90, 0);
					}
					if (xy == 2)
					{
						fish3.setPosition(90, 0);
					}
					if (xy == 3)
					{
						fish3.setPosition(180, 0);
					}
				}

				if (c % 480 == 479 && truck1.getPosition().y>750)
				{

					trk = 1;
					int xy = rand() % 4;
					if (xy == 0)
					{
						truck1.setPosition(0, 0);

					}
					if (xy == 1)
					{
						truck1.setPosition(-90, 0);
					}
					if (xy == 2)
					{
						truck1.setPosition(-180, 0);

					}
					if (xy == 3)
					{
						truck1.setPosition(95, 0);
					}
				}
				//bonusmove
				if (c % 1000 == 900)
				{

					int xy = rand() % 4;
					if (xy == 0)
						bonus.setPosition(0, 0);
					if (xy == 1)
						bonus.setPosition(-90, 0);
					if (xy == 2)
						bonus.setPosition(-180, 0);
					if (xy == 3)
						bonus.setPosition(95, 0);
				}
				if (c % 600 == 599 && ambulance.getPosition().y>750)
				{

					ambu = 1;
					int xy = rand() % 4;
					ambulance.setPosition(0, 0);
					if (xy == 0)
					{
						ambulance.setPosition(-270, 0);
					}
					if (xy == 1)
					{
						ambulance.setPosition(-190, 0);
					}
					if (xy == 2)
					{
						ambulance.setPosition(-90, 0);
					}
					if (xy == 3)
					{
						ambulance.setPosition(0, 0);
					}
				}
				if (r1 % 600 == 590 && race1.getPosition().y>810){
					//r1st = 1;
					int xy = rand() % 4;
					if (xy == 0){
						race1.setPosition(0, 0);
					}
					if (xy == 1){
						race1.setPosition(100, 0);
					}
					if (xy == 2){
						race1.setPosition(190, 0);
					}
					if (xy == 3)
					{
						race1.setPosition(270, 0);
					}
				}
				if (c % 700 == 669 && race2.getPosition().y>810){
					int xy = rand() % 4;
					r2nd = 1;
					if (xy == 0){
						race2.setPosition(0, 0);
					}
					if (xy == 1)
					{
						race2.setPosition(-90, 0);
					}
					if (xy == 2)
					{
						race2.setPosition(180, 0);
					}
					if (xy == 3)
					{
						race2.setPosition(95, 0);
					}
				}
				if (c % 680 == 620 && race3.getPosition().y>810){
					r3rd = 1;
					int xy = rand() % 4;
					if (xy == 0)
					{
						race3.setPosition(0, 0);

					}
					if (xy == 1)
					{
						race3.setPosition(-90, 0);
					}
					if (xy == 2)
					{
						race3.setPosition(-180, 0);
					}
					if (xy == 3)
					{
						race3.setPosition(95, 0);
					}
				}
				if (c % 760 == 700 && race4.getPosition().y>810){
					r4th = 1;
					int xy = rand() % 4;
					if (xy == 0)
					{
						race4.setPosition(0, 0);
					}
					if (xy == 1)
					{
						race4.setPosition(-90, 0);
					}
					if (xy == 2)
					{
						race4.setPosition(-175, 0);
					}
					if (xy == 3)
					{
						race4.setPosition(-275, 0);
					}
				}
			}
			////////////////////////////////*******************lavel2*********************?/////////////////////
			if (count > 50 && count <= 100)
			{
				if (c % 410 == 400){
					fis2 = 1;
					int xx = rand() % 4;

					if (xx == 0)
					{
						fish2.setPosition(0, 0);
					}
					if (xx == 1)
					{
						fish2.setPosition(100, 0);
					}
					if (xx == 2)
					{
						fish2.setPosition(190, 0);
					}
					if (xx == 3)
					{
						fish2.setPosition(270, 0);
					}

				}

				if (c % 400 == 399)
				{

					fis3 = 1;
					int xy = rand() % 4;
					if (xy == 0)
					{
						fish3.setPosition(0, 0);
					}
					if (xy == 1)
					{
						fish3.setPosition(-90, 0);
					}
					if (xy == 2)
					{
						fish3.setPosition(90, 0);
					}
					if (xy == 3)
					{
						fish3.setPosition(180, 0);
					}
				}

				if (c % 430 == 429)
				{

					trk = 1;
					int xy = rand() % 4;
					if (xy == 0)
					{
						truck1.setPosition(0, 0);

					}
					if (xy == 1)
					{
						truck1.setPosition(-90, 0);
					}
					if (xy == 2)
					{
						truck1.setPosition(-180, 0);

					}
					if (xy == 3)
					{
						truck1.setPosition(95, 0);
					}
				}
				//bonusmove
				if (c % 900 == 800)
				{

					int xy = rand() % 4;
					if (xy == 0)
						bonus.setPosition(0, 0);
					if (xy == 1)
						bonus.setPosition(-90, 0);
					if (xy == 2)
						bonus.setPosition(-180, 0);
					if (xy == 3)
						bonus.setPosition(95, 0);
				}
				if (c % 480 == 450)
				{

					ambu = 1;
					int xy = rand() % 4;
					ambulance.setPosition(0, 0);
					if (xy == 0)
					{
						ambulance.setPosition(-270, 0);
					}
					if (xy == 1)
					{
						ambulance.setPosition(-190, 0);
					}
					if (xy == 2)
					{
						ambulance.setPosition(-90, 0);
					}
					if (xy == 3)
					{
						ambulance.setPosition(0, 0);
					}
				}
				if (r1 % 510 == 500){
					//r1st = 1;
					int xy = rand() % 4;
					if (xy == 0){
						race1.setPosition(0, 0);
					}
					if (xy == 1){
						race1.setPosition(100, 0);
					}
					if (xy == 2){
						race1.setPosition(190, 0);
					}
					if (xy == 3)
					{
						race1.setPosition(270, 0);
					}
				}
				if (c % 430 == 410){
					int xy = rand() % 4;
					r2nd = 1;
					if (xy == 0){
						race2.setPosition(0, 0);
					}
					if (xy == 1)
					{
						race2.setPosition(-90, 0);
					}
					if (xy == 2)
					{
						race2.setPosition(180, 0);
					}
					if (xy == 3)
					{
						race2.setPosition(95, 0);
					}
				}
				if (c % 460 == 459){
					r3rd = 1;
					int xy = rand() % 4;
					if (xy == 0)
					{
						race3.setPosition(0, 0);

					}
					if (xy == 1)
					{
						race3.setPosition(-90, 0);
					}
					if (xy == 2)
					{
						race3.setPosition(-180, 0);
					}
					if (xy == 3)
					{
						race3.setPosition(95, 0);
					}
				}
				if (c % 530 == 500){
					r4th = 1;
					int xy = rand() % 4;
					if (xy == 0)
					{
						race4.setPosition(0, 0);
					}
					if (xy == 1)
					{
						race4.setPosition(-90, 0);
					}
					if (xy == 2)
					{
						race4.setPosition(-175, 0);
					}
					if (xy == 3)
					{
						race4.setPosition(-275, 0);
					}
				}
			}
			//////////////////////////88888888*****level3******/////////////////////////
			if (count > 100)
			{
				if (c % 380 == 379){
					fis2 = 1;
					int xx = rand() % 4;

					if (xx == 0)
					{
						fish2.setPosition(0, 0);
					}
					if (xx == 1)
					{
						fish2.setPosition(100, 0);
					}
					if (xx == 2)
					{
						fish2.setPosition(190, 0);
					}
					if (xx == 3)
					{
						fish2.setPosition(270, 0);
					}

				}

				if (c % 360 == 350)
				{

					fis3 = 1;
					int xy = rand() % 4;
					if (xy == 0)
					{
						fish3.setPosition(0, 0);
					}
					if (xy == 1)
					{
						fish3.setPosition(-90, 0);
					}
					if (xy == 2)
					{
						fish3.setPosition(90, 0);
					}
					if (xy == 3)
					{
						fish3.setPosition(180, 0);
					}
				}

				if (c % 340 == 339)
				{

					trk = 1;
					int xy = rand() % 4;
					if (xy == 0)
					{
						truck1.setPosition(0, 0);

					}
					if (xy == 1)
					{
						truck1.setPosition(-90, 0);
					}
					if (xy == 2)
					{
						truck1.setPosition(-180, 0);

					}
					if (xy == 3)
					{
						truck1.setPosition(95, 0);
					}
				}
				//bonusmove
				if (c % 1100 == 1000)
				{

					int xy = rand() % 4;
					if (xy == 0)
						bonus.setPosition(0, 0);
					if (xy == 1)
						bonus.setPosition(-90, 0);
					if (xy == 2)
						bonus.setPosition(-180, 0);
					if (xy == 3)
						bonus.setPosition(95, 0);
				}
				if (c % 460 == 459)
				{

					ambu = 1;
					int xy = rand() % 4;
					ambulance.setPosition(0, 0);
					if (xy == 0)
					{
						ambulance.setPosition(-270, 0);
					}
					if (xy == 1)
					{
						ambulance.setPosition(-190, 0);
					}
					if (xy == 2)
					{
						ambulance.setPosition(-90, 0);
					}
					if (xy == 3)
					{
						ambulance.setPosition(0, 0);
					}
				}
				if (r1 % 375 == 370){
					//r1st = 1;
					int xy = rand() % 4;
					if (xy == 0){
						race1.setPosition(0, 0);
					}
					if (xy == 1){
						race1.setPosition(100, 0);
					}
					if (xy == 2){
						race1.setPosition(190, 0);
					}
					if (xy == 3)
					{
						race1.setPosition(270, 0);
					}
				}
				if (c % 380 == 370){
					int xy = rand() % 4;
					r2nd = 1;
					if (xy == 0){
						race2.setPosition(0, 0);
					}
					if (xy == 1)
					{
						race2.setPosition(-90, 0);
					}
					if (xy == 2)
					{
						race2.setPosition(180, 0);
					}
					if (xy == 3)
					{
						race2.setPosition(95, 0);
					}
				}
				if (c % 300 == 290){
					r3rd = 1;
					int xy = rand() % 4;
					if (xy == 0)
					{
						race3.setPosition(0, 0);

					}
					if (xy == 1)
					{
						race3.setPosition(-90, 0);
					}
					if (xy == 2)
					{
						race3.setPosition(-180, 0);
					}
					if (xy == 3)
					{
						race3.setPosition(95, 0);
					}
				}
				if (c % 330 == 320){
					r4th = 1;
					int xy = rand() % 4;
					if (xy == 0)
					{
						race4.setPosition(0, 0);
					}
					if (xy == 1)
					{
						race4.setPosition(-90, 0);
					}
					if (xy == 2)
					{
						race4.setPosition(-175, 0);
					}
					if (xy == 3)
					{
						race4.setPosition(-275, 0);
					}
				}
			}
			//policebarricades move
			if (policeb.getPosition().y>950)
			{
				//count++;
				int xy = rand() % 2;
				if (xy == 0)
					policeb.setPosition(0, 0);
				if (xy == 1)
					policeb.setPosition(170, 0);
			}
			//people walker

			lady.move(-2, .08);
			walk++;
			if (walk % 32 == 0){
				walk++;
			}
			lady.setTextureRect(sf::IntRect(((walk % 32) / 8) * 27, 0, 25, 35));
			if (lady.getPosition().x <= -630)
			{
				int xy = rand() % 5;
				if (xy == 0)
				{
					lady.setPosition(0, 0);
				}
				if (xy == 1)
				{
					lady.setPosition(0, 100);
				}
				if (xy == 2)
				{
					lady.setPosition(0, 200);
				}
				if (xy == 3)
				{
					lady.setPosition(0, 300);
				}
				if (xy == 4)
				{
					lady.setPosition(0, 400);
				}

			}

			if (lady.getGlobalBounds().intersects(race1.getGlobalBounds()))
				race1.move(0, -2);
			if (lady.getGlobalBounds().intersects(race2.getGlobalBounds()))
				race2.move(0, -3);
			if (lady.getGlobalBounds().intersects(race3.getGlobalBounds()))
				race3.move(0, -4);
			if (lady.getGlobalBounds().intersects(race4.getGlobalBounds()))
				race4.move(0, -3);
			if (lady.getGlobalBounds().intersects(fish2.getGlobalBounds()))
				fish2.move(0, -3);
			if (lady.getGlobalBounds().intersects(fish3.getGlobalBounds()))
				fish3.move(0, -4);
			if (lady.getGlobalBounds().intersects(truck1.getGlobalBounds()))
				truck1.move(0, -2);
			if (lady.getGlobalBounds().intersects(ambulance.getGlobalBounds()))
				ambulance.move(0, -5);

			baby.move(1.7, -.05);
			walk++;
			if (walk % 21 == 0){
				walk++;
			}
			baby.setTextureRect(sf::IntRect(((walk % 21) / 7) * 30, 0, 30, 35));
			if (baby.getPosition().x >= 699)
			{
				int xy = rand() % 5;
				if (xy == 0)
				{
					baby.setPosition(0, 0);
				}
				if (xy == 1)
				{
					baby.setPosition(0,-200 );
				}
				if (xy == 2)
				{
					baby.setPosition(0, -110);
				}
				if (xy == 3)
				{
					baby.setPosition(0, 80);
				}
				if (xy == 4)
				{
					baby.setPosition(0, -510);
				}
			}
			if (baby.getGlobalBounds().intersects(race1.getGlobalBounds()))
				race1.move(0, -2);
			if (baby.getGlobalBounds().intersects(race2.getGlobalBounds()))
				race2.move(0, -3);
			if (baby.getGlobalBounds().intersects(race3.getGlobalBounds()))
				race3.move(0, -4);
			if (baby.getGlobalBounds().intersects(race4.getGlobalBounds()))
				race4.move(0, -3);
			if (baby.getGlobalBounds().intersects(fish2.getGlobalBounds()))
				fish2.move(0, -3);
			if (baby.getGlobalBounds().intersects(fish3.getGlobalBounds()))
				fish3.move(0, -4);
			if (baby.getGlobalBounds().intersects(truck1.getGlobalBounds()))
				truck1.move(0, -2);
			if (baby.getGlobalBounds().intersects(ambulance.getGlobalBounds()))
				ambulance.move(0, -2);

			if (car1.getGlobalBounds().intersects(bonus.getGlobalBounds()))
			{
				jump = jump + 2;
				bonus.setPosition(-1000, 0);
			}
    }
	if (game)
	{
		fish2.move(0, 3.8);
		fish3.move(0, 4.8);
		truck1.move(0, 3);
		ambulance.move(0, 5.5);
		if (c > 300)
			race1.move(0, 2.5);
		if (c > 250)
			race2.move(0, 4);
		if (c > 350)
			race3.move(0, 4.8);
		if (c > 400)
			race4.move(0, 3.9);
		bonus.move(0, 2);
		policeb.move(0, 3.2);
		border.move(0, 2.5);
		border1.move(0, 2.5);
		hf.move(0, 4);
		h0.move(0, 4);
		h1.move(0, 4);
		hfo.move(0, 4);
		sback.move(0, 4);
		h1o.move(0, 4);




		//bonus not intersect with vehicles
		if (bonus.getGlobalBounds().intersects(race1.getGlobalBounds()) || bonus.getGlobalBounds().intersects(truck1.getGlobalBounds()))
		{
			bonus.move(0, -5);
		}
		if (bonus.getGlobalBounds().intersects(fish2.getGlobalBounds()) || bonus.getGlobalBounds().intersects(race2.getGlobalBounds()) || bonus.getGlobalBounds().intersects(race4.getGlobalBounds()))
		{
			bonus.move(0, -3);
		}
		//vehicles not crush with each other
		if (truck1.getGlobalBounds().intersects(race1.getGlobalBounds()))
		{
			truck1.move(0, -5);
		}
		if (truck1.getGlobalBounds().intersects(fish2.getGlobalBounds()) || truck1.getGlobalBounds().intersects(race2.getGlobalBounds()) || truck1.getGlobalBounds().intersects(race4.getGlobalBounds()))
		{
			truck1.move(0, -3);
		}
		if (race1.getGlobalBounds().intersects(fish2.getGlobalBounds()) || race1.getGlobalBounds().intersects(race2.getGlobalBounds()) || race1.getGlobalBounds().intersects(race4.getGlobalBounds()))
		{
			race1.move(0, -3);
		}
		//3 move vehicles not crush
		if (fish2.getGlobalBounds().intersects(race2.getGlobalBounds()) || fish2.getGlobalBounds().intersects(race4.getGlobalBounds()))
		{
			fish2.move(0, -5);
		}
		if (fish2.getGlobalBounds().intersects(race3.getGlobalBounds()) || fish2.getGlobalBounds().intersects(fish3.getGlobalBounds()))
		{
			fish2.move(0, -2);
		}
		if (race2.getGlobalBounds().intersects(race4.getGlobalBounds()))
		{
			race2.move(0, -5);
		}
		if (race2.getGlobalBounds().intersects(race3.getGlobalBounds()) || race2.getGlobalBounds().intersects(fish3.getGlobalBounds()))
		{
			race2.move(0, -2);
		}
		if (race4.getGlobalBounds().intersects(race3.getGlobalBounds()) || race4.getGlobalBounds().intersects(fish3.getGlobalBounds()))
		{
			race4.move(0, -2);
		}
		//4 move vehicles not crush
		if (fish3.getGlobalBounds().intersects(race3.getGlobalBounds()))
		{
			fish3.move(0, -5);
		}
		if (fish3.getGlobalBounds().intersects(ambulance.getGlobalBounds()))
		{
			fish3.move(0, -2);
		}
		if (race3.getGlobalBounds().intersects(ambulance.getGlobalBounds()))
		{
			race3.move(0, -2);
		}

		if (race1.getGlobalBounds().intersects(race2.getGlobalBounds()) || race1.getGlobalBounds().intersects(race3.getGlobalBounds()) || race1.getGlobalBounds().intersects(race4.getGlobalBounds()) || race1.getGlobalBounds().intersects(fish2.getGlobalBounds()) || race1.getGlobalBounds().intersects(fish3.getGlobalBounds()) || race1.getGlobalBounds().intersects(ambulance.getGlobalBounds()))
		{
			race1.move(0, -15);
		}
		if (j == 3)
		{
			game = FALSE;
			flag = 1;
			zz = 2;
		}
		if (h1.getPosition().y > 1900)
			h1.setPosition(0, 0);
		if (h0.getPosition().y > 1900)
			h0.setPosition(0, 0);
		if (hf.getPosition().y > 1900)
			hf.setPosition(0, 0);
		if (h1o.getPosition().y > 1900)
			h1o.setPosition(0, 0);
		if (sback.getPosition().y >1900)
			sback.setPosition(0, 0);
		if (hfo.getPosition().y > 1900)
			hfo.setPosition(0, 0);

		line.setPosition(400, 750);
		side1.setPosition(495, 0);
		side2.setPosition(864, 0);
		h0.setOrigin(-408, 1180);
		sback.setOrigin(-880, 1180);
		h1.setOrigin(-408, 70);
		h1o.setOrigin(-880, 70);
		bonus.setOrigin(-690, 500);
		hf.setOrigin(-408, 1830);
		hfo.setOrigin(-880, 1830);
		car1.setOrigin(-560, -600);
		car2.setOrigin(-560, -600);
		car3.setOrigin(-560, -600);
		car4.setOrigin(-560, -600);
		carfly.setOrigin(-560, -600);
		ima.setPosition(510, 0);
		grass.setPosition(410, 0);
		grasso.setPosition(880, 0);

		ima1.setPosition(510, 320);
		border.setOrigin(-586, 0);
		border1.setOrigin(-776, 0);
		fish2.setOrigin(-527, 70);
		fish3.setOrigin(-600, 70);
		truck1.setOrigin(-700, 110);
		ambulance.setOrigin(-790, 70);
		if (c > 200)
		{
			race1.setOrigin(-530, 100);
			if (lal == 1)
			{
				r1 = 1;
				race1.setPosition(0, 0);
				lal = 2;
			}
		}
		if (c > 350)
		{
			race2.setOrigin(-610, 100);
			if (blu == 1)
			{
				r2 = 1;
				race1.setPosition(0, 0);
				blu = 2;
			}
		}

		if (c > 150)
		{
			race3.setOrigin(-700, 100);
			if (hol == 1)
			{
				r3 = 1;
				race3.setPosition(0, 0);
				hol = 2;
			}
		}
		if (c > 100)
		{
			race4.setOrigin(-790, 100);
			if (beg == 1)
			{
				r4 = 1;
				race1.setPosition(0, 0);
				beg = 2;
			}
		}
		fire.setOrigin(-530, -575);
		sidebackground.setPosition(0, 0);
		sidebackground1.setPosition(880, 0);
		///////////9483*********counttttttttttttttttttttttttt/////////////////////////////////////
		if (race1.getGlobalBounds().intersects(line.getGlobalBounds()))
			{
				count++;
				race1.move(0,200);
			}
		if (race2.getGlobalBounds().intersects(line.getGlobalBounds()))
		{
				count++;
				race2.move(0, 200);
		}
		if (race3.getGlobalBounds().intersects(line.getGlobalBounds()))
			{
				count++;
				race3.move(0, 200);
			}

		if (race4.getGlobalBounds().intersects(line.getGlobalBounds()))
		{
				count++;
				race4.move(0,200);
		}
		if (fish2.getGlobalBounds().intersects(line.getGlobalBounds()))
		{
				count++;
				fish2.move(0,200);
		}
		if (fish3.getGlobalBounds().intersects(line.getGlobalBounds()))
		{
				count++;
				fish3.move(0,200);			
		}
		if (truck1.getGlobalBounds().intersects(line.getGlobalBounds()))
		{
				count++;
				truck1.move(0,200);
		}
		if (ambulance.getGlobalBounds().intersects(line.getGlobalBounds()))
		{
			count++;
			ambulance.move(0,200);
		}
		

		//********************************level2*****************************************/////////////////////////
		if (count > 50 && j == 2){
			policeb.setOrigin(-530, 200);
			cout << "shhhhhhhhooootttttttt" << endl;
			if (pol == 1)
			{
				policeb.setPosition(0, 0);
				pol = 2;
			}
			fish2.move(0, 1.7);
			fish3.move(0, 1.7);
			truck1.move(0, 1.7);
			ambulance.move(0, 1.7);
			race1.move(0, 1.7);
			race2.move(0, 1.7);
			race3.move(0, 1.7);
			race4.move(0, 1.7);
			bonus.move(0, 1.7);
			border.move(0, .5);
			border1.move(0, .5);
			hf.move(0, 1.5);
			h0.move(0, 1.5);
			h1.move(0, 1.5);
			hfo.move(0, 1.5);
			sback.move(0, 1.5);
			h1o.move(0, 1.5);
		}
		/*********************************level3**************************//////////////////////////////

		if (count > 100 && j == 2){
			baby.setOrigin(-450, -400);
			if (bby == 1)
			{
				baby.setPosition(0, 0);
				bby = 2;
			}
			cout << "fuvkkkkkkkkk" << endl;

			lady.setOrigin(-900, -200);
			if (ldy == 1)
			{
				lady.setPosition(0, 0);
				ldy = 2;
			}
			fish2.move(0, 1.9);
			fish3.move(0, 1.9);
			truck1.move(0, 1.9);
			ambulance.move(0, 1.9);
			race1.move(0, 1.9);
			race2.move(0, 1.9);
			race3.move(0, 1.9);
			race4.move(0, 1.9);
			bonus.move(0, 1.9);
			policeb.move(0, 2);
			border.move(0, 2);
			border1.move(0, 2);
			hf.move(0, 2);
			h0.move(0, 2);
			h1.move(0, 2);
			hfo.move(0, 2);
			sback.move(0, 2);
			h1o.move(0, 2);
		}
	}
			window.draw(ima);
			window.draw(ima1);

			window.draw(border);
			window.draw(border1);
			window.draw(policeb);
			window.draw(fish2);
			window.draw(fish3);

			window.draw(truck1);
			window.draw(ambulance);
			window.draw(race1);
			window.draw(race2);
			window.draw(race3);
			window.draw(race4);
			window.draw(side1);
			window.draw(side2);
			window.draw(lady);
			if (count>90)
			window.draw(baby);
			window.draw(sidebackground);
			window.draw(sidebackground1);
			window.draw(grass);
			window.draw(grasso);
			window.draw(hf);
			window.draw(hfo);
			window.draw(h1);
			window.draw(h1o);
			window.draw(h0);
			window.draw(sback);
			window.draw(bonus);
			window.draw(ambulance);
			window.draw(line);
			if (fly >= 24 && car % 40 <= 10)
				window.draw(car1);
			if (fly >= 24 && car % 40 >= 10 && car % 40 <= 20)
				window.draw(car2);
			if (fly >= 24 && car % 40 >= 20 && car % 40 <= 30)
				window.draw(car3);
			if (fly >= 24 && car % 40 >= 30 && car % 40 < 40)
				window.draw(car4);
			if (fly < 25)
				window.draw(carfly);
			sf::Text text, text1;
			sf::Font font, font1;
			font.loadFromFile("text2.ttf");
			font1.loadFromFile("text2.ttf");
			text.setFont(font);
			text1.setFont(font1);
			char ch[20], ch1[20];
			//nt count=10;
			sprintf(ch, "Your Score:\n\n %d\n", count);
			sprintf(ch1, "jump: %d", jump);
			text.setString(ch);
			text.setCharacterSize(20);
			text.setPosition(890, 100);
			text.setColor(sf::Color::Black);
			window.draw(text);
			text1.setString(ch1);
			text1.setCharacterSize(20);
			text1.setPosition(890, 300);
			text1.setColor(sf::Color::Black);
		//	gari.play();
			window.draw(text1);

			if (!game&&c>70)
			{
				/*if (event.type == sf::Event::KeyPressed){
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::RShift))
					{
					cout << "key is pressed" << endl;
					goto high_score;
					}
					}*/
			//	crash.play();
			//	gari.stop();
					musicc.stop();

				while(cr == 1){
					crash.play();
					cout << "k=1" << endl;
					cr=2;
				}


				c--;
				fish2.move(0, 0);
				fish3.move(0, 0);
				truck1.move(0, 0);
				ambulance.move(0, 0);
				race1.move(0, 0);
				race2.move(0, 0);
				race3.move(0, 0);
				race4.move(0, 0);
				bonus.move(0, 0);
				policeb.move(0, 0);
				border.move(0, 0);
				border1.move(0, 0);
				hf.move(0, 0);
				h0.move(0, 0);
				h1.move(0, 0);
				//lady.move(2, -0.08);
				//baby.move(-1.7, 0.05);
				window.draw(car2);
				window.draw(fire);
				Texture t30;
				t30.loadFromFile("go.png");
				Sprite gameover(t30);
				gameover.setPosition(500, 240);
				//window.draw(gameover);


					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
					{
                        musicc.stop();
						HighScore h;
						ppp = h.score();
						if (count > ppp)
						{
							goto scoring;
						}
						else goto main_menu;
					}
					else
					{
					    musicc.stop();


						sf::Font scre;
						scre.loadFromFile("Lobster_1.3.otf");

						std::stringstream sss;
						sss << "Your Score: " << count;

						sf::Text pp;
						pp.setCharacterSize(70);
						pp.setColor(sf::Color::Red);
						pp.setFont(scre);
						pp.setString(sss.str());
						pp.setPosition(500,300);

						/////////////////////////////////////////////

						sf::Font fontt;
						fontt.loadFromFile("Pacifico.ttf");
						sf::Text textt;
						textt.setFont(fontt);
						textt.setString("Press ENTER to continue");
						textt.setColor(sf::Color::Blue);
						textt.setCharacterSize(40);
						textt.setPosition(450, 550);
						sf::Font fonttt;
						fonttt.loadFromFile("Lobster_1.3.otf");
						sf::Text texttt;
						texttt.setFont(fonttt);
						texttt.setString("gameover!");
						texttt.setColor(sf::Color::Red);
						texttt.setCharacterSize(70);
						texttt.setPosition(530, 200);

			//			window.clear();
			//			crash.stop();
			//			gari.stop();
						//window.draw(gameover);
						window.draw(pp);
						window.draw(textt);
						window.draw(texttt);
						//window.display();

						//count = 0;
						//goto main_menu;
					}

		}

	window.display();

	}
	printf("%d", count);
}
scoring:
{
	int xx = 1;
	string name;

	int aa;
	bool flagg = false;
	int ccc = count;
	count = 0;

	while (window.isOpen())
	{
		window.setFramerateLimit(300);

		sf::Texture g_over;
		g_over.loadFromFile("score.jpg");
		sf::Sprite gover;
		gover.setTexture(g_over);
		gover.setPosition(0, 0);

		sf::Font fnt;
		fnt.loadFromFile("Pacifico.ttf");
		sf::Text txt;
		txt.setFont(fnt);
		txt.setString("Enter your name & Press Enter key to save");
		txt.setColor(sf::Color::Black);
		txt.setCharacterSize(45);
		txt.setPosition(900 / 2 - txt.getGlobalBounds().width / 2, 200);

		sf::RectangleShape rct(sf::Vector2f(3, 40));
		rct.setFillColor(sf::Color::Black);
		rct.setPosition(900 / 2 - txt.getGlobalBounds().width / 2, 400);
		rct.setScale(xx, xx);
	

		bool br = 1;




		sf::Event event;

		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();


				break;

			case sf::Event::TextEntered:
				if (event.text.unicode != 13 && event.text.unicode != 8)
				{
					name.push_back((char)event.text.unicode);
				}
				else if (event.text.unicode == 8)
				{
					if (!name.empty())
						name.pop_back();
				}
				else
				{
					br = 0;
				}
				break;
				break;
			}
		}

		if (!br)
		{
			std::ofstream ofs("example.txt", std::ofstream::out);

			ofs << name;
			ofs << "\n";
			ofs << ccc;
			ofs.close();
		}


		sf::Font font;
		font.loadFromFile("high.ttf");
		sf::Text text;
		text.setFont(font);
		text.setString(name);
		text.setColor(sf::Color::Black);
		text.setCharacterSize(45);
		text.setPosition(900 / 2 - text.getGlobalBounds().width / 2, 300);


//		sf::Font xt;
	//	xt.loadFromFile("high.ttf");
		sf::Text txtt;
		txtt.setFont(font);
		txtt.setString("Press ESCAPE key for the Main Menu");
		txtt.setColor(sf::Color::Black);
		txtt.setStyle(sf::Text::Bold);
		txtt.setCharacterSize(50);
		txtt.setPosition(900 / 2 - txtt.getGlobalBounds().width / 2, 650);


		if (sf::Keyboard::isKeyPressed)
		{
			if (event.key.code == sf::Keyboard::Escape)
				goto main_menu;
		}

		window.clear();


		window.draw(gover);
		window.draw(txt);
		window.draw(txtt);
		window.draw(text);
		window.display();
	}
}



exit_game:
{

	return EXIT_SUCCESS;
}
}



