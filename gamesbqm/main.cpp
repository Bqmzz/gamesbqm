#define _CRT_SECURE_NO_WARNINGS
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <utility>
#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
#include <math.h>
#include <vector>
#include <fstream>
#include "stdlib.h"
#include "Player.h"
#include "Platform.h"
#include "Bullet.h"
#include "Coin.h"
#include "Monster.h"
#include "Blood.h"
#include "Buffer.h"
#include "Bitmap.h"
using namespace std;

int bulletCheck;

int main()
{
	srand(time(NULL));
	sf::RenderWindow window(sf::VideoMode(1080, 720), "Princess running");
	sf::View view(sf::Vector2f(1.0f, 1.0f), sf::Vector2f(1080.0f, 720.0f));

	//------------------------------------------------------------- Back & But ------------------------------------------------------------//
	// Background เริ่มเกม
	sf::RectangleShape wall1(sf::Vector2f(1080.0f, 720.0f));
	wall1.setPosition(0.0f, 0.0f);
	sf::Texture w1;
	w1.loadFromFile("wall1.png");
	wall1.setTexture(&w1);

	// Button Play Score Exit
	sf::RectangleShape wall2(sf::Vector2f(1080.0f, 720.0f));
	wall2.setPosition(0.0f, 0.0f);
	sf::Texture w2;
	w2.loadFromFile("picwall2.png");
	wall2.setTexture(&w2);

	// Button play
	sf::RectangleShape wall3(sf::Vector2f(1080.0f, 720.0f));
	wall3.setPosition(0.0f, 0.0f);
	sf::Texture w3;
	w3.loadFromFile("picwall3.png");
	wall3.setTexture(&w3);

	// Button score
	sf::RectangleShape wall4(sf::Vector2f(1080.0f, 720.0f));
	wall4.setPosition(0.0f, 0.0f);
	sf::Texture w4;
	w4.loadFromFile("picwall4.png");
	wall4.setTexture(&w4);

	// Button exit
	sf::RectangleShape wall5(sf::Vector2f(1080.0f, 720.0f));
	wall5.setPosition(0.0f, 0.0f);
	sf::Texture w5;
	w5.loadFromFile("picwall5.png");
	wall5.setTexture(&w5);

	// Button howtoplay
	sf::RectangleShape wallhtp(sf::Vector2f(1080.0f, 720.0f));
	wallhtp.setPosition(0.0f, 0.0f);
	sf::Texture whtp;
	whtp.loadFromFile("wallhtp.png");
	wallhtp.setTexture(&whtp);

	// Background game1
	sf::RectangleShape background1(sf::Vector2f(10000.0f, 720.0f));
	background1.setPosition(0.0f, 0.0f);
	sf::Texture bg1;
	bg1.loadFromFile("wall1eiei.png");
	background1.setTexture(&bg1);

	// Background game2
	sf::RectangleShape background2(sf::Vector2f(10000.0f, 720.0f));
	background2.setPosition(10000.0f, 0.0f);
	sf::Texture bg2;
	bg2.loadFromFile("wall2eiei.png");
	background2.setTexture(&bg2);

	// Background game3
	sf::RectangleShape background3(sf::Vector2f(10000.0f, 720.0f));
	background3.setPosition(20000.0f, 0.0f);
	sf::Texture bg3;
	bg3.loadFromFile("wall3eiei.png");
	background3.setTexture(&bg3);

	// How to play
	sf::RectangleShape backgroundhtp(sf::Vector2f(10000.0f, 720.0f));
	backgroundhtp.setPosition(20000.0f, 0.0f);
	sf::Texture bghtp;
	bghtp.loadFromFile("howtoplay.png");
	background3.setTexture(&bghtp);

	// Background endgame
	sf::RectangleShape yeah(sf::Vector2f(1080.0f, 720.0f));
	yeah.setPosition(0.0f, 0.0f);
	sf::Texture fn;
	fn.loadFromFile("picwallend.png");
	yeah.setTexture(&fn);

	// Black menu
	sf::RectangleShape backmenuone(sf::Vector2f(1080.0f, 720.0f));
	backmenuone.setPosition(0.0f, 0.0f);
	sf::Texture bm1;
	bm1.loadFromFile("wallbackmenu1.png");
	backmenuone.setTexture(&bm1);

	sf::RectangleShape backmenutwo(sf::Vector2f(1080.0f, 720.0f));
	backmenutwo.setPosition(0.0f, 0.0f);
	sf::Texture bm2;
	bm2.loadFromFile("wallbackmenu2.png");
	backmenutwo.setTexture(&bm2);

	// Background keyname
	sf::RectangleShape key(sf::Vector2f(1080.0f, 720.0f));
	key.setPosition(0.0f, 0.0f);
	sf::Texture kn;
	kn.loadFromFile("picwallkeyname.png");
	key.setTexture(&kn);

	//------------------------------------------------------------- Music & Sound ------------------------------------------------------------//
	sf::SoundBuffer soundone;
	if (!soundone.loadFromFile("MerryGo.ogg"))
		return -1;

	sf::Sound soundtwo;
	soundtwo.setBuffer(soundone);

	//soundjump
	sf::SoundBuffer soundjump;
	soundjump.loadFromFile("jump.ogg");
	sf::Sound Sound2;
	Sound2.setBuffer(soundjump);

	//soundjump
	sf::SoundBuffer soundwrap;
	soundwrap.loadFromFile("jump.ogg");
	sf::Sound Sound3;
	Sound3.setBuffer(soundwrap);

	//soundmenu
	sf::Music music;
	music.openFromFile("MerryGo.ogg");
	music.setLoop(true);
	music.setVolume(20.f);

	//----------------------------------------------------------- Font -------------------------------------------------------------//
	sf::Font font;
	font.loadFromFile("Marshmallow.otf");
	std::ostringstream point;
	sf::Text Score;
	Score.setCharacterSize(50);
	Score.setString(point.str());
	Score.setFont(font);
	Score.setFillColor(sf::Color::White);

	int countscore = 0;
	sf::Font fontscore;
	fontscore.loadFromFile("Marshmallow.otf");
	std::ostringstream point1;
	sf::Text scoregame;
	scoregame.setCharacterSize(50);
	scoregame.setString(point1.str());
	scoregame.setFont(fontscore);
	scoregame.setFillColor(sf::Color::White);

	sf::Font fontt;
	fontt.loadFromFile("Marshmallow.otf");
	std::ostringstream fontty;
	sf::Text fontbu;
	fontbu.setCharacterSize(50);
	fontbu.setString(fontty.str());
	fontbu.setFont(font);
	fontbu.setFillColor(sf::Color::Green);
	sf::Text fontbuu;
	fontbuu.setCharacterSize(50);
	fontbuu.setString(fontty.str());
	fontbuu.setFont(font);
	fontbuu.setFillColor(sf::Color::Red);

	sf::Text fontbl;
	fontbl.setCharacterSize(50);
	fontbl.setString(fontty.str());
	fontbl.setFont(font);
	fontbl.setFillColor(sf::Color::Green);

	sf::Text fontbll;
	fontbll.setCharacterSize(50);
	fontbll.setString(fontty.str());
	fontbll.setFont(font);
	fontbll.setFillColor(sf::Color::Green);

	sf::Text fontblll;
	fontblll.setCharacterSize(50);
	fontblll.setString(fontty.str());
	fontblll.setFont(font);
	fontblll.setFillColor(sf::Color::Green);

	sf::Text fonthighsc;
	fonthighsc.setCharacterSize(50);
	fonthighsc.setString(fontty.str());
	fonthighsc.setFont(font);
	fonthighsc.setFillColor(sf::Color::Yellow);

	// Player princess
	sf::Texture playertexture;
	playertexture.loadFromFile("picmyprincess.png");
	Player player(&playertexture, sf::Vector2u(6, 5), 0.15f, 250.0f, 200.0f);

	//----------------------------------------------------------- Item -------------------------------------------------------------//
	//Item up
	sf::Texture bup;
	bup.loadFromFile("uppoint.png");
	std::vector <Blood> BloodupVector;

	//Item down
	sf::Texture bdown;
	bdown.loadFromFile("downpoint.png");
	std::vector <Blood> BlooddownVector;

	//Super power
	sf::Texture POINTX2;
	POINTX2.loadFromFile("picpower.png");
	std::vector <Buffer> X2Vector;
	sf::Texture stateX10;
	stateX10.loadFromFile("picpower.png");
	sf::RectangleShape x10(sf::Vector2f(200, 200));
	x10.setTexture(&stateX10);

	//endscore
	int EndScore = 0;
	sf::Text Send;
	Send.setCharacterSize(50);
	Send.setFont(font);
	Send.setFillColor(sf::Color::White);

	//End scorestar
	int EndNumStar = 0;
	sf::Text CSTER;
	sf::Font gameover;
	gameover.loadFromFile("Marshmallow.otf");
	CSTER.setCharacterSize(50);
	CSTER.setString(fontty.str());
	CSTER.setFont(gameover);
	CSTER.setFillColor(sf::Color::White);

	//New score
	sf::Text NewScore;
	NewScore.setCharacterSize(50);
	NewScore.setString(fontty.str());
	NewScore.setFont(font);
	NewScore.setFillColor(sf::Color::White);

	sf::Texture HPbar;
	HPbar.loadFromFile("picblood.png");
	sf::Sprite hpbar;
	hpbar.setTexture(HPbar);
	hpbar.setPosition(300, -100);

	sf::Texture load;
	load.loadFromFile("picwallload.png");
	sf::RectangleShape ll(sf::Vector2f(1080, 720));
	ll.setPosition(sf::Vector2f(0, 0));
	ll.setTexture(&load);

	float MyHP = 100000;
	hpbar.setTexture(HPbar);
	sf::RectangleShape HP(sf::Vector2f(MyHP / 400.0f, 30));
	HP.setPosition(sf::Vector2f(450, 46));
	HP.setFillColor(sf::Color::White);
	HP.setSize(sf::Vector2f(MyHP / 400.f, 15));

	float Downlaod = 0;
	sf::RectangleShape DL(sf::Vector2f(Downlaod / 50.0f, 20));
	DL.setPosition(sf::Vector2f(285, 647.5f));
	DL.setFillColor(sf::Color::White);
	DL.setSize(sf::Vector2f(Downlaod / 150.f, 19));

	//Coin
	sf::Texture coin;
	coin.loadFromFile("piccoin.png");
	std::vector <Coin*> starVector;

	//Monter
	sf::Texture monterone;
	monterone.loadFromFile("picmonter1.png");
	std::vector <Monster> alienVector;

	sf::Texture montertwo;
	montertwo.loadFromFile("picmonter2.png");
	std::vector <Monster> alien1Vector;

	sf::Texture monterthree;
	monterthree.loadFromFile("picmonter3.png");
	std::vector <Monster> alien2Vector;

	//Bullet
	sf::Texture BULLET;
	BULLET.loadFromFile("bullet1.png");
	Bullet bullet1(&BULLET, sf::Vector2u(3, 1), 0.15f, 600.0f, player.GetPosition());

	//Platform
	std::vector<Platform> platforms;
	//map1
	platforms.push_back(Platform(nullptr, sf::Vector2f(120.0f, 687.072f), sf::Vector2f(1700.0f, 143.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(700.0f, 20.0f), sf::Vector2f(2900.0f, 450.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(700.0f, 20.0f), sf::Vector2f(7500.0f, 450.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(120.0f, 20.0f), sf::Vector2f(5700.0f, 450.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(120.0f, 20.0f), sf::Vector2f(6100.0f, 450.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(500.0f, 50.0f), sf::Vector2f(6700.0f, 365.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(120.0f, 687.072f), sf::Vector2f(4050.00f, 143.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(2500.0f, 100.0f), sf::Vector2f(1250.0f, 670.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(800.0f, 100.0f), sf::Vector2f(3650.0f, 670.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(1500.0f, 100.0f), sf::Vector2f(4100.0f, 670.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(1090.0f, 100.0f), sf::Vector2f(5100.0f, 670.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(2000.0f, 100.0f), sf::Vector2f(8800.0f, 670.0f)));

	//map2
	platforms.push_back(Platform(nullptr, sf::Vector2f(120.0f, 687.072f), sf::Vector2f(11700.0f, 143.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(700.0f, 50.0f), sf::Vector2f(12900.0f, 450.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(120.0f, 100.0f), sf::Vector2f(16693.0f, 160.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(82.0f, 90.0f), sf::Vector2f(14793.0f, 550.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(700.0f, 20.0f), sf::Vector2f(17500.0f, 450.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(120.0f, 20.0f), sf::Vector2f(15700.0f, 450.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(120.0f, 20.0f), sf::Vector2f(16100.0f, 450.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(500.0f, 50.0f), sf::Vector2f(16700.0f, 365.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(120.0f, 687.072f), sf::Vector2f(14050.00f, 143.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(2500.0f, 100.0f), sf::Vector2f(11250.0f, 670.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(800.0f, 100.0f), sf::Vector2f(13650.0f, 670.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(1500.0f, 100.0f), sf::Vector2f(14100.0f, 670.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(1090.0f, 100.0f), sf::Vector2f(15100.0f, 670.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(2000.0f, 100.0f), sf::Vector2f(18800.0f, 670.0f)));

	//map3
	platforms.push_back(Platform(nullptr, sf::Vector2f(120.0f, 687.072f), sf::Vector2f(21700.0f, 143.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(700.0f, 20.0f), sf::Vector2f(22900.0f, 450.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(120.0f, 20.0f), sf::Vector2f(25700.0f, 450.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(120.0f, 20.0f), sf::Vector2f(26100.0f, 450.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(500.0f, 50.0f), sf::Vector2f(26700.0f, 365.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(120.0f, 687.072f), sf::Vector2f(24050.00f, 143.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(2500.0f, 100.0f), sf::Vector2f(21250.0f, 670.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(800.0f, 100.0f), sf::Vector2f(23650.0f, 670.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(1500.0f, 100.0f), sf::Vector2f(24100.0f, 670.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(1090.0f, 100.0f), sf::Vector2f(25100.0f, 670.0f)));
	platforms.push_back(Platform(nullptr, sf::Vector2f(4000.0f, 100.0f), sf::Vector2f(29000.0f, 670.0f)));

	//Point coin
	sf::Texture pointcoin;
	pointcoin.loadFromFile("piccoinny.png");
	sf::RectangleShape coinny(sf::Vector2f(40, 40));
	coinny.setPosition(sf::Vector2f(80, 80));
	coinny.setTexture(&pointcoin);

	//Menu Pause
	sf::Texture pauseone;
	pauseone.loadFromFile("picwallpause.png");
	sf::RectangleShape pp(sf::Vector2f(1080, 720));
	pp.setTexture(&pauseone);

	//Pause resume
	sf::Texture pausetwo;
	pausetwo.loadFromFile("picwallpause1.png");
	sf::RectangleShape pr(sf::Vector2f(1080, 720));
	pr.setTexture(&pausetwo);

	//Pause menu
	sf::Texture pausethree;
	pausethree.loadFromFile("picwallpause2.png");
	sf::RectangleShape pm(sf::Vector2f(1080, 720));
	pm.setTexture(&pausethree);

	//Pause exit
	sf::Texture pausefour;
	pausefour.loadFromFile("picwallpause3.png");
	sf::RectangleShape pe(sf::Vector2f(1080, 720));
	pe.setTexture(&pausefour);

	//End
	sf::Texture end;
	end.loadFromFile("picwallover.png");
	sf::RectangleShape ee(sf::Vector2f(1080, 720));
	ee.setTexture(&end);

	sf::Texture High;
	High.loadFromFile("picwallhighscore.png");
	sf::RectangleShape hh(sf::Vector2f(1080, 720));
	hh.setTexture(&High);

	sf::Texture backHigh;
	backHigh.loadFromFile("picwallhighscore1.png");
	sf::RectangleShape bh(sf::Vector2f(1080, 720));
	bh.setTexture(&High);

	sf::String playerInput;
	std::ofstream fileWriter;
	std::ostringstream keyname;
	sf::Text Keyname;
	Keyname.setCharacterSize(50);
	Keyname.setString(" ");
	Keyname.setFont(font);
	Keyname.setFillColor(sf::Color::Black);

	int i = 0;
	int q = 0;
	int Bul = 0;
	int count = 0;
	int state = 0;
	int countloop = 0;
	int soundcount = 0;

	float deltaTime = 0.0f;
	float countTimeAdd = 0;
	float countTimeSub = 0;
	float countTimeBul = 0;
	float countTimeBul1 = 0;
	float countTimeBul2 = 0;
	float countTimex2 = 0;

	sf::Clock clock;
	sf::Clock timerpausemenu;
	sf::Clock timer;
	sf::Clock timercoli;

	bool slide;
	bool checkdraw = false;
	bool checkmap1 = false;
	bool checkmap2 = false;
	bool checkcoli = false;
	bool checkBul1 = false;
	bool checkBul2 = false;
	bool checkAdd = false;
	bool checkSub = false;
	bool checkBul = false;
	bool checkx2 = false;
	bool Cload = false;
	bool START = true;
	bool MENU = true;
	bool Rank = false;
	bool SCORE1 = true;
	bool endGame = false;
	bool MemScore = false;
	bool sound_over = false;
	bool checkpause = false;
	bool cheakhighscore = false;

	std::map<int, std::string> keepscore;
	std::ifstream fileReader;
	std::string word;

	//Textbox
	char charr = ' ';
	sf::RectangleShape cursor;
	cursor.setSize(sf::Vector2f(5.0f, 30.0f));
	cursor.setOrigin(sf::Vector2f(2.5f, 15.0f));
	cursor.setFillColor(sf::Color::Black);
	
	sf::Text text("", font);
	Keyname.setPosition(320, 560);
	text.setCharacterSize(60);
	text.setFillColor(sf::Color::Yellow);
	text.setPosition(320, 560);
	cursor.setPosition(320.0f + text.getGlobalBounds().width + 10, 560.0f);

	float totalTime_cursor = 0;
	sf::Clock clock_cursor;
	bool state_cursor = false;
	std::string user_name = "";
	fstream myFile;

	while (window.isOpen())
	{
		music.play();
		while (MENU == true)
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

			sf::Vector2f mouesPosition = sf::Vector2f(0.0f, 0.0f);
			mouesPosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));

			deltaTime = clock.restart().asSeconds();
			if (cheakhighscore == false) 
			{
				window.draw(wall1);
				window.draw(wall2);
				window.draw(wallhtp);
			}
			if (sf::Mouse::getPosition(window).x >= 427 && sf::Mouse::getPosition(window).y >= 275 && sf::Mouse::getPosition(window).x <= 660 && sf::Mouse::getPosition(window).y <= 348)
			{
				window.draw(wall3);
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) 
				{
					MENU = false;
					START = false;
					MemScore = true;
				}
			}
			else if (sf::Mouse::getPosition(window).x >= 427 && sf::Mouse::getPosition(window).y >= 395 && sf::Mouse::getPosition(window).x <= 660 && sf::Mouse::getPosition(window).y <= 466)
			{
				window.draw(wall4);
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && (timerpausemenu.getElapsedTime().asSeconds() >= 0.3))
				{
					MENU = false;
					START = false;
					Rank = true;
				}
			}
			else if (sf::Mouse::getPosition(window).x >= 427 && sf::Mouse::getPosition(window).y >= 515 && sf::Mouse::getPosition(window).x <= 660 && sf::Mouse::getPosition(window).y <= 584)
			{
				window.draw(wall5);
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) 
				{
					window.close();
					break;
				}
			}
			else if (sf::Mouse::getPosition(window).x >= 427 && sf::Mouse::getPosition(window).y >= 635 && sf::Mouse::getPosition(window).x <= 660 && sf::Mouse::getPosition(window).y <= 702)
			{
				window.draw(wallhtp);
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					window.draw(backgroundhtp);
					break;
				}
			}
			window.display();
		}
		while (Rank == true) 
		{
			
			if (countloop == 0) 
			{
				view.setCenter(540, 360);
			}

			sf::Vector2f mouesPosition = sf::Vector2f(0.0f, 0.0f);
			mouesPosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));
			cout << sf::Mouse::getPosition(window).x << " " << sf::Mouse::getPosition(window).y << endl;
			printf("\nWe are in rank\n");
			window.clear();
			window.draw(hh);
			sf::Text text1("", font);
			text1.setCharacterSize(30);
			text1.setFillColor(sf::Color::White);
			fileReader.open("bamja.txt");
			if (!fileReader) std::cout << "Not found inFile\n";
			do 
			{
				
				fileReader >> word;
				std::string first_token = word.substr(0, word.find(','));
				int second_token = std::stoi(word.substr(word.find(',') + 1, word.length()));
				keepscore[second_token] = first_token;
			} 
			while (fileReader.good());
			fileReader.close();
			std::map<int, std::string>::iterator end = keepscore.end();
			std::map<int, std::string>::iterator beg = keepscore.begin();
			end--;
			beg--;
			int currentDisplay = 0;
			for (std::map<int, std::string>::iterator it = end; it != beg; it--) 
			{
				text1.setString(it->second);
				text1.setPosition(view.getCenter().x - 170, 210 + 80 * currentDisplay);
				window.draw(text1);
				text1.setString(std::to_string(it->first));
				text1.setPosition(view.getCenter().x + 95, 210 + 80 * currentDisplay);
				window.draw(text1);
				currentDisplay++;
				if (currentDisplay == 5)
				{
					break;
				}
			}

			if (sf::Mouse::getPosition(window).x >= 416 && sf::Mouse::getPosition(window).y >= 636 && sf::Mouse::getPosition(window).x <= 665 && sf::Mouse::getPosition(window).y <= 685)
			{
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					Rank = false;
					MENU = true;
				}
			}
			window.display();
		}

		while (MemScore == true) 
		{

			countTimeAdd += deltaTime;
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

			if (event.type == sf::Event::TextEntered && charr != event.text.unicode)
			{
				if (event.text.unicode == 13) 
				{
					user_name = playerInput;
					playerInput.clear();
					MENU = true;
				}
				else if (event.text.unicode == 8 && playerInput.getSize() > 0) 
				{
					playerInput = playerInput.substring(0, playerInput.getSize() - 1);
				}
				else {
					if (playerInput.getSize() < 10) 
					{
						if (countTimeAdd > 0.2) 
						{
							playerInput += event.text.unicode;
							countTimeAdd = 0;
						}
					}
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) 
				{
					MENU = false;
					Rank = false;
					Cload = true;
					soundcount = 0;
				}
				charr = event.text.unicode;
				text.setString(playerInput);
				cursor.setPosition(320.0f + text.getGlobalBounds().width + 10, 560.0f);
			}
			else if (event.type == sf::Event::EventType::KeyReleased && charr != ' ') 
			{
				charr = ' ';
			}
			window.clear();
			window.draw(key);
			window.draw(Keyname);

			totalTime_cursor += clock_cursor.restart().asSeconds();
			if (totalTime_cursor >= 0.5) 
			{
				totalTime_cursor = 0;
				state_cursor = !state_cursor;
			}
			if (state_cursor == true) {
				window.draw(cursor);
			}
			window.draw(text);
			if (Cload == true) 
			{
				window.draw(ll);
				Downlaod += 95;
				DL.setSize(sf::Vector2f(Downlaod / 150.f, 19));
				window.draw(DL);
				if (Downlaod > 80000) 
				{
					Downlaod = 80000;
					MemScore = false;
					START = true;
					Cload = false;
				}
			}
			window.display();
		}

		deltaTime = 0;
		clock.restart();
		cout << user_name << endl;

		Downlaod = 0;
		MyHP = 78000;
		state = 0;
		EndNumStar = 0;

		//Coin map1
		for (int posi = 0; posi < 1550; posi += 60) 
		{
			starVector.push_back(new Coin(&coin, sf::Vector2u(9, 1), 0.08f, 800.0f + posi, 550.0f));
		}
		for (int posi = 0; posi < 200; posi += 60) 
		{
			starVector.push_back(new Coin(&coin, sf::Vector2u(9, 1), 0.08f, 2630.0f + posi, 370.0f));
		}
		starVector.push_back(new Coin(&coin, sf::Vector2u(9, 1), 0.08f, 2850.0f, 320.0f));
		starVector.push_back(new Coin(&coin, sf::Vector2u(9, 1), 0.08f, 2900.0f, 300.0f));
		starVector.push_back(new Coin(&coin, sf::Vector2u(9, 1), 0.08f, 2950.0f, 280.0f));
		starVector.push_back(new Coin(&coin, sf::Vector2u(9, 1), 0.08f, 3000.0f, 300.0f));
		starVector.push_back(new Coin(&coin, sf::Vector2u(9, 1), 0.08f, 3050.0f, 320.0f));
		starVector.push_back(new Coin(&coin, sf::Vector2u(9, 1), 0.08f, 3100.0f, 370.0f));
		starVector.push_back(new Coin(&coin, sf::Vector2u(9, 1), 0.08f, 3150.0f, 370.0f));
		for (int posi = 0; posi < 1300; posi += 60) 
		{
			starVector.push_back(new Coin(&coin, sf::Vector2u(9, 1), 0.08f, 3500.0f + posi, 550.0f));
		}
		for (int posi = 0; posi < 900; posi += 60) 
		{
			starVector.push_back(new Coin(&coin, sf::Vector2u(9, 1), 0.08f, 4700.0f + posi, 550.0f));
		}
		starVector.push_back(new Coin(&coin, sf::Vector2u(9, 1), 0.08f, 5743.0f, 370.0f));
		starVector.push_back(new Coin(&coin, sf::Vector2u(9, 1), 0.08f, 5770.0f, 330.0f));
		starVector.push_back(new Coin(&coin, sf::Vector2u(9, 1), 0.08f, 5800.0f, 290.0f));
		starVector.push_back(new Coin(&coin, sf::Vector2u(9, 1), 0.08f, 5850.0f, 260.0f));
		starVector.push_back(new Coin(&coin, sf::Vector2u(9, 1), 0.08f, 5900.0f, 240.0f));
		starVector.push_back(new Coin(&coin, sf::Vector2u(9, 1), 0.08f, 5950.0f, 260.0f));
		starVector.push_back(new Coin(&coin, sf::Vector2u(9, 1), 0.08f, 6000.0f, 290.0f));
		starVector.push_back(new Coin(&coin, sf::Vector2u(9, 1), 0.08f, 6030.0f, 330.0f));
		starVector.push_back(new Coin(&coin, sf::Vector2u(9, 1), 0.08f, 6070.0f, 370.0f));
		for (int posi = 0; posi < 350; posi += 60) 
		{
			starVector.push_back(new Coin(&coin, sf::Vector2u(9, 1), 0.08f, 6570.0f + posi, 265.0f));
		}
		starVector.push_back(new Coin(&coin, sf::Vector2u(9, 1), 0.08f, 6167.0f, 370.0f));
		starVector.push_back(new Coin(&coin, sf::Vector2u(9, 1), 0.08f, 6180.0f, 340.0f));
		starVector.push_back(new Coin(&coin, sf::Vector2u(9, 1), 0.08f, 6210.0f, 310.0f));
		starVector.push_back(new Coin(&coin, sf::Vector2u(9, 1), 0.08f, 6250.0f, 305.0f));
		starVector.push_back(new Coin(&coin, sf::Vector2u(9, 1), 0.08f, 6300.0f, 280.0f));
		starVector.push_back(new Coin(&coin, sf::Vector2u(9, 1), 0.08f, 6340.0f, 250.0f));
		starVector.push_back(new Coin(&coin, sf::Vector2u(9, 1), 0.08f, 6400.0f, 280.0f));
		starVector.push_back(new Coin(&coin, sf::Vector2u(9, 1), 0.08f, 6451.0f, 310.0f));
		starVector.push_back(new Coin(&coin, sf::Vector2u(9, 1), 0.08f, 6340.0f, 290.0f));
		starVector.push_back(new Coin(&coin, sf::Vector2u(9, 1), 0.08f, 6400.0f, 280.0f));
		starVector.push_back(new Coin(&coin, sf::Vector2u(9, 1), 0.08f, 6451.0f, 280.0f));
		for (int posi = 0; posi < 600; posi += 60) 
		{
			starVector.push_back(new Coin(&coin, sf::Vector2u(9, 1), 0.08f, 7250.0f + posi, 370.0f));
		}
		for (int posi = 0; posi < 1000; posi += 60) 
		{
			starVector.push_back(new Coin(&coin, sf::Vector2u(9, 1), 0.08f, 8119.0f + posi, 550.0f));
		}

		//Coin map2
		for (int posi = 0; posi < 1550; posi += 60) 
		{
			starVector.push_back(new Coin(&coin, sf::Vector2u(9, 1), 0.08f, 10800.0f + posi, 550.0f));
		}
		for (int posi = 0; posi < 200; posi += 60) 
		{
			starVector.push_back(new Coin(&coin, sf::Vector2u(9, 1), 0.08f, 12630.0f + posi, 370.0f));
		}

		starVector.push_back(new Coin(&coin, sf::Vector2u(9, 1), 0.08f, 12850.0f, 320.0f));
		starVector.push_back(new Coin(&coin, sf::Vector2u(9, 1), 0.08f, 12900.0f, 300.0f));
		starVector.push_back(new Coin(&coin, sf::Vector2u(9, 1), 0.08f, 12950.0f, 280.0f));
		starVector.push_back(new Coin(&coin, sf::Vector2u(9, 1), 0.08f, 13000.0f, 300.0f));
		starVector.push_back(new Coin(&coin, sf::Vector2u(9, 1), 0.08f, 13050.0f, 320.0f));
		starVector.push_back(new Coin(&coin, sf::Vector2u(9, 1), 0.08f, 13100.0f, 370.0f));
		starVector.push_back(new Coin(&coin, sf::Vector2u(9, 1), 0.08f, 13150.0f, 370.0f));
		for (int posi = 0; posi < 1200; posi += 60) 
		{
			starVector.push_back(new Coin(&coin, sf::Vector2u(9, 1), 0.08f, 13500.0f + posi, 550.0f));
		}
		for (int posi = 0; posi < 400; posi += 60) 
		{
			starVector.push_back(new Coin(&coin, sf::Vector2u(9, 1), 0.08f, 15124.0f + posi, 550.0f));
		}
		starVector.push_back(new Coin(&coin, sf::Vector2u(9, 1), 0.08f, 15743.0f, 370.0f));
		starVector.push_back(new Coin(&coin, sf::Vector2u(9, 1), 0.08f, 15770.0f, 330.0f));
		starVector.push_back(new Coin(&coin, sf::Vector2u(9, 1), 0.08f, 15800.0f, 290.0f));
		starVector.push_back(new Coin(&coin, sf::Vector2u(9, 1), 0.08f, 15850.0f, 260.0f));
		starVector.push_back(new Coin(&coin, sf::Vector2u(9, 1), 0.08f, 15900.0f, 240.0f));
		starVector.push_back(new Coin(&coin, sf::Vector2u(9, 1), 0.08f, 15950.0f, 260.0f));
		starVector.push_back(new Coin(&coin, sf::Vector2u(9, 1), 0.08f, 16000.0f, 290.0f));
		starVector.push_back(new Coin(&coin, sf::Vector2u(9, 1), 0.08f, 16030.0f, 330.0f));
		starVector.push_back(new Coin(&coin, sf::Vector2u(9, 1), 0.08f, 16070.0f, 370.0f));
		for (int posi = 0; posi < 350; posi += 60) 
		{
			starVector.push_back(new Coin(&coin, sf::Vector2u(9, 1), 0.08f, 16570.0f + posi, 265.0f));
		}
		starVector.push_back(new Coin(&coin, sf::Vector2u(9, 1), 0.08f, 16167.0f, 370.0f));
		starVector.push_back(new Coin(&coin, sf::Vector2u(9, 1), 0.08f, 16180.0f, 340.0f));
		starVector.push_back(new Coin(&coin, sf::Vector2u(9, 1), 0.08f, 16210.0f, 310.0f));
		starVector.push_back(new Coin(&coin, sf::Vector2u(9, 1), 0.08f, 16250.0f, 305.0f));
		starVector.push_back(new Coin(&coin, sf::Vector2u(9, 1), 0.08f, 16300.0f, 280.0f));
		starVector.push_back(new Coin(&coin, sf::Vector2u(9, 1), 0.08f, 16340.0f, 250.0f));
		starVector.push_back(new Coin(&coin, sf::Vector2u(9, 1), 0.08f, 16400.0f, 280.0f));
		starVector.push_back(new Coin(&coin, sf::Vector2u(9, 1), 0.08f, 16451.0f, 310.0f));
		starVector.push_back(new Coin(&coin, sf::Vector2u(9, 1), 0.08f, 16340.0f, 290.0f));
		starVector.push_back(new Coin(&coin, sf::Vector2u(9, 1), 0.08f, 16400.0f, 280.0f));
		starVector.push_back(new Coin(&coin, sf::Vector2u(9, 1), 0.08f, 16451.0f, 280.0f));
		for (int posi = 0; posi < 600; posi += 60) 
		{
			starVector.push_back(new Coin(&coin, sf::Vector2u(9, 1), 0.08f, 17250.0f + posi, 370.0f));
		}
		for (int posi = 0; posi < 650; posi += 60) 
		{
			starVector.push_back(new Coin(&coin, sf::Vector2u(9, 1), 0.08f, 18012.0f + posi, 550.0f));
		}
		for (int posi = 0; posi < 1550; posi += 60) 
		{
			starVector.push_back(new Coin(&coin, sf::Vector2u(9, 1), 0.08f, 20800.0f + posi, 550.0f));
		}
		for (int posi = 0; posi < 200; posi += 60) 
		{
			starVector.push_back(new Coin(&coin, sf::Vector2u(9, 1), 0.08f, 22630.0f + posi, 370.0f));
		}
		starVector.push_back(new Coin(&coin, sf::Vector2u(9, 1), 0.08f, 22850.0f, 320.0f));
		starVector.push_back(new Coin(&coin, sf::Vector2u(9, 1), 0.08f, 22900.0f, 300.0f));
		starVector.push_back(new Coin(&coin, sf::Vector2u(9, 1), 0.08f, 22950.0f, 280.0f));
		starVector.push_back(new Coin(&coin, sf::Vector2u(9, 1), 0.08f, 23000.0f, 300.0f));
		starVector.push_back(new Coin(&coin, sf::Vector2u(9, 1), 0.08f, 23050.0f, 320.0f));
		starVector.push_back(new Coin(&coin, sf::Vector2u(9, 1), 0.08f, 23100.0f, 370.0f));
		starVector.push_back(new Coin(&coin, sf::Vector2u(9, 1), 0.08f, 23150.0f, 370.0f));
		for (int posi = 0; posi < 1300; posi += 60) 
		{
			starVector.push_back(new Coin(&coin, sf::Vector2u(9, 1), 0.08f, 23500.0f + posi, 550.0f));
		}
		for (int posi = 0; posi < 500; posi += 60) 
		{
			starVector.push_back(new Coin(&coin, sf::Vector2u(9, 1), 0.08f, 24700.0f + posi, 550.0f));
		}
		starVector.push_back(new Coin(&coin, sf::Vector2u(9, 1), 0.08f, 25743.0f, 370.0f));
		starVector.push_back(new Coin(&coin, sf::Vector2u(9, 1), 0.08f, 25770.0f, 330.0f));
		starVector.push_back(new Coin(&coin, sf::Vector2u(9, 1), 0.08f, 25800.0f, 290.0f));
		starVector.push_back(new Coin(&coin, sf::Vector2u(9, 1), 0.08f, 25850.0f, 260.0f));
		starVector.push_back(new Coin(&coin, sf::Vector2u(9, 1), 0.08f, 25900.0f, 240.0f));
		starVector.push_back(new Coin(&coin, sf::Vector2u(9, 1), 0.08f, 25950.0f, 260.0f));
		starVector.push_back(new Coin(&coin, sf::Vector2u(9, 1), 0.08f, 26000.0f, 290.0f));
		starVector.push_back(new Coin(&coin, sf::Vector2u(9, 1), 0.08f, 26030.0f, 330.0f));
		starVector.push_back(new Coin(&coin, sf::Vector2u(9, 1), 0.08f, 26070.0f, 370.0f));
		starVector.push_back(new Coin(&coin, sf::Vector2u(9, 1), 0.08f, 26167.0f, 370.0f));
		starVector.push_back(new Coin(&coin, sf::Vector2u(9, 1), 0.08f, 26180.0f, 340.0f));
		starVector.push_back(new Coin(&coin, sf::Vector2u(9, 1), 0.08f, 26210.0f, 310.0f));
		starVector.push_back(new Coin(&coin, sf::Vector2u(9, 1), 0.08f, 26250.0f, 305.0f));
		starVector.push_back(new Coin(&coin, sf::Vector2u(9, 1), 0.08f, 26300.0f, 280.0f));
		starVector.push_back(new Coin(&coin, sf::Vector2u(9, 1), 0.08f, 26340.0f, 250.0f));
		starVector.push_back(new Coin(&coin, sf::Vector2u(9, 1), 0.08f, 26400.0f, 280.0f));
		for (int posi = 0; posi < 350; posi += 60) 
		{
			starVector.push_back(new Coin(&coin, sf::Vector2u(9, 1), 0.08f, 26570.0f + posi, 265.0f));
		}
		for (int posi = 0; posi < 1500; posi += 60) 
		{
			starVector.push_back(new Coin(&coin, sf::Vector2u(9, 1), 0.08f, 27365.0f + posi, 550.0f));
		}
		starVector.push_back(new Coin(&coin, sf::Vector2u(9, 1), 0.08f, 6451.0f, 310.0f));
		starVector.push_back(new Coin(&coin, sf::Vector2u(9, 1), 0.08f, 6340.0f, 290.0f));
		starVector.push_back(new Coin(&coin, sf::Vector2u(9, 1), 0.08f, 6400.0f, 280.0f));
		starVector.push_back(new Coin(&coin, sf::Vector2u(9, 1), 0.08f, 6451.0f, 280.0f));

		//Monster
		alienVector.push_back(Monster(&monterone, sf::Vector2u(12, 1), 0.08f, 70.0f, 80.0f, rand() % 50 + 2331.0f, -10.0f));
		alienVector.push_back(Monster(&monterone, sf::Vector2u(12, 1), 0.08f, 70.0f, 80.0f, rand() % 50 + 3071.0f, -10.0f));
		alienVector.push_back(Monster(&monterone, sf::Vector2u(12, 1), 0.08f, 70.0f, 80.0f, rand() % 50 + 5337.0f, -10.0f));
		alienVector.push_back(Monster(&monterone, sf::Vector2u(12, 1), 0.08f, 70.0f, 80.0f, rand() % 50 + 6815.0f, -10.0f));
		alienVector.push_back(Monster(&monterone, sf::Vector2u(12, 1), 0.08f, 70.0f, 80.0f, rand() % 50 + 8928.0f, -10.0f));

		alien1Vector.push_back(Monster(&montertwo, sf::Vector2u(12, 1), 0.08f, 70.0f, 80.0f, rand() % 50 + 11580.0f, -10.0f));
		alien1Vector.push_back(Monster(&montertwo, sf::Vector2u(12, 1), 0.08f, 70.0f, 80.0f, rand() % 50 + 15504.0f, -10.0f));
		alien1Vector.push_back(Monster(&montertwo, sf::Vector2u(12, 1), 0.08f, 70.0f, 80.0f, rand() % 50 + 16943.0f, -10.0f));

		alien2Vector.push_back(Monster(&monterthree, sf::Vector2u(12, 1), 0.08f, 70.0f, 80.0f, rand() % 50 + 22955.0f, -10.0f));
		alien2Vector.push_back(Monster(&monterthree, sf::Vector2u(12, 1), 0.08f, 70.0f, 80.0f, rand() % 50 + 25416.0f, -10.0f));

		BloodupVector.push_back(Blood(&bup, sf::Vector2u(3, 1), 0.08f, 1090.0f, 545.0f));
		BloodupVector.push_back(Blood(&bup, sf::Vector2u(3, 1), 0.08f, 3456.0f, 180.0f));
		BloodupVector.push_back(Blood(&bup, sf::Vector2u(3, 1), 0.08f, 3848.0f, 545.0f));
		BloodupVector.push_back(Blood(&bup, sf::Vector2u(3, 1), 0.08f, 5012.0f, 545.0f));

		BloodupVector.push_back(Blood(&bup, sf::Vector2u(3, 1), 0.08f, 8474.0f, 540.0f));
		BloodupVector.push_back(Blood(&bup, sf::Vector2u(3, 1), 0.08f, 12033.0f, 370.0f));
		BloodupVector.push_back(Blood(&bup, sf::Vector2u(3, 1), 0.08f, 14818.0f, 390.0f));
		BloodupVector.push_back(Blood(&bup, sf::Vector2u(3, 1), 0.08f, 23532.0f, 370.0f));
		BloodupVector.push_back(Blood(&bup, sf::Vector2u(3, 1), 0.08f, 27265.0f, 180.0f));
		BloodupVector.push_back(Blood(&bup, sf::Vector2u(3, 1), 0.08f, 2740.0f, 280.0f));
		BloodupVector.push_back(Blood(&bup, sf::Vector2u(3, 1), 0.08f, 6122.9f, 365.0f));
		BloodupVector.push_back(Blood(&bup, sf::Vector2u(3, 1), 0.08f, 10728.0f, 545.0f));
		BloodupVector.push_back(Blood(&bup, sf::Vector2u(3, 1), 0.08f, 18198.0f, 545.0f));
		BloodupVector.push_back(Blood(&bup, sf::Vector2u(3, 1), 0.08f, 22663.0f, 365.0f));
		BloodupVector.push_back(Blood(&bup, sf::Vector2u(3, 1), 0.08f, 22663.0f, 365.0f));

		BlooddownVector.push_back(Blood(&bdown, sf::Vector2u(3, 1), 0.08f, 1278.0f, 545.0f));
		BlooddownVector.push_back(Blood(&bdown, sf::Vector2u(3, 1), 0.08f, 3249.0f, 370.0f));
		BlooddownVector.push_back(Blood(&bdown, sf::Vector2u(3, 1), 0.08f, 5230.0f, 545.0f));
		BlooddownVector.push_back(Blood(&bdown, sf::Vector2u(3, 1), 0.08f, 5630.0f, 545.0f));


		BlooddownVector.push_back(Blood(&bdown, sf::Vector2u(3, 1), 0.08f, 6840.0f, 280.0f));
		BlooddownVector.push_back(Blood(&bdown, sf::Vector2u(3, 1), 0.08f, 4655.0f, 545.0f));
		BlooddownVector.push_back(Blood(&bdown, sf::Vector2u(3, 1), 0.08f, 8003.0f, 545.0f));
		BlooddownVector.push_back(Blood(&bdown, sf::Vector2u(3, 1), 0.08f, 14090.0f, 545.0f));
		BlooddownVector.push_back(Blood(&bdown, sf::Vector2u(3, 1), 0.08f, 21981.0f, 370.0f));
		BlooddownVector.push_back(Blood(&bdown, sf::Vector2u(3, 1), 0.08f, 26445.0f, 280.0f));
		BlooddownVector.push_back(Blood(&bdown, sf::Vector2u(3, 1), 0.08f, 12527.0f, 350.0f));
		BlooddownVector.push_back(Blood(&bdown, sf::Vector2u(3, 1), 0.08f, 15540.0f, 345.0f));
		BlooddownVector.push_back(Blood(&bdown, sf::Vector2u(3, 1), 0.08f, 16473.0f, 280.0f));
		BlooddownVector.push_back(Blood(&bdown, sf::Vector2u(3, 1), 0.08f, 25206.0f, 545.0f));

		//Power
		X2Vector.push_back(Buffer(&POINTX2, sf::Vector2u(3, 1), 0.08f, 5506.0f, 380.0f));
		X2Vector.push_back(Buffer(&POINTX2, sf::Vector2u(3, 1), 0.08f, 13442.0f, 545.0f));
		X2Vector.push_back(Buffer(&POINTX2, sf::Vector2u(3, 1), 0.08f, 27265.0f, 545.0f));
		X2Vector.push_back(Buffer(&POINTX2, sf::Vector2u(3, 1), 0.08f, 20719.0f, 545.0f));
		X2Vector.push_back(Buffer(&POINTX2, sf::Vector2u(3, 1), 0.08f, 26071.0f, 365.0f));

		while (START == true) 
		{
			music.pause();
			slide = false;
			count = 10;
			deltaTime = clock.restart().asSeconds();
			sf::Vector2f pos = player.GetPosition();
			std::cout << pos.x << ' ' << pos.y << '\n';
			sf::Vector2f mouesPosition = sf::Vector2f(0.0f, 0.0f);
			mouesPosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));

			if ((checkpause == false && endGame == false) && state != 3) 
			{
				player.update(deltaTime, starVector, X2Vector);
			}

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
			//Coin
			for (int i = 0; i < starVector.size(); i++) 
			{
				starVector[i]->update(deltaTime);
			}
			//Blood up
			for (int i = 0; i < BloodupVector.size(); i++) 
			{
				BloodupVector[i].update(deltaTime, player);
			}
			//Blood down
			for (int i = 0; i < BlooddownVector.size(); i++) 
			{
				BlooddownVector[i].update(deltaTime, player);
			}
			//Power
			for (int i = 0; i < X2Vector.size(); i++) 
			{
				X2Vector[i].update(deltaTime);
			}
			//Monster
			for (int i = 0; i < alienVector.size(); i++) 
			{
				alienVector[i].update1(deltaTime, bullet1);
				if (checkpause == false) 
				{
					alienVector[i].update2(deltaTime, player);
				}
			}
			for (int i = 0; i < alien1Vector.size(); i++) 
			{
				alien1Vector[i].update1(deltaTime, bullet1);
				if (checkpause == false) 
				{
					alien1Vector[i].update2(deltaTime, player);
				}
			}
			for (int i = 0; i < alien2Vector.size(); i++) 
			{
				alien2Vector[i].update1(deltaTime, bullet1);
				if (checkpause == false) 
				{
					alien2Vector[i].update2(deltaTime, player);
				}
			}

			sf::Vector2f direction;
			for (Platform& platform : platforms)
				if (platform.GetCollider().CheckCollision(player.GetCollider(), direction, 1.0f)) 
				{
					player.OnCollision(direction);
				}
			for (i = 0; i < alienVector.size(); i++) 
			{
				for (Platform& platform : platforms)
					if (platform.GetCollider().CheckCollision(alienVector[i].GetCollider(), direction, 1.0f)) 
					{
						alienVector[i].OnCollision(direction);
					}
			}
			for (i = 0; i < alien1Vector.size(); i++) 
			{
				for (Platform& platform : platforms)
					if (platform.GetCollider().CheckCollision(alien1Vector[i].GetCollider(), direction, 1.0f)) 
					{
						alien1Vector[i].OnCollision(direction);
					}
			}
			for (i = 0; i < alien2Vector.size(); i++) 
			{
				for (Platform& platform : platforms)
					if (platform.GetCollider().CheckCollision(alien2Vector[i].GetCollider(), direction, 1.0f)) 
					{
						alien2Vector[i].OnCollision(direction);
					}
			}

			point1.str(" ");
			point1 << "SCORE :  " << int(pos.x - 200);
			EndScore = int(pos.x - 200);
			EndNumStar = player.getNumCoin();
			scoregame.setPosition({ 40,30 });
			scoregame.setString(point1.str());

			hpbar.setPosition(view.getCenter().x - 210, -90);
			HP.setPosition(view.getCenter().x - 60, 56);
			Score.setPosition(view.getCenter().x - 485, 95);
			scoregame.setPosition(view.getCenter().x - 510, 30);
			coinny.setPosition(view.getCenter().x - 480, 88);

			view.setCenter(player.GetPosition().x, 360.0f);
			if (view.getCenter().x - 540.0f <= 0.0f) 
			{
				view.setCenter(540.0f, 360.0f);
			}
			if (view.getCenter().x + 540.0f >= 30000.0f) 
			{
				view.setCenter(29460.0f, 360.0f);
			}

			//Score
			point.str(" ");
			point << "      " << player.getNumCoin();
			Score.setString(point.str());

			fontty.str(" ");
			fontty << "  " << EndScore;
			Send.setString(fontty.str());

			fontty.str(" ");
			fontty << "  " << EndNumStar;
			CSTER.setString(fontty.str());

			fontty.str(" ");
			fontty << "  " << EndScore + EndNumStar;
			NewScore.setString(fontty.str());

			//Monster
			for (i = 0; i < alienVector.size(); i++) 
			{
				if (alienVector[i].colAlien() == 2) 
				{
					MyHP -= 10000;
					HP.setSize(sf::Vector2f(MyHP / 320.f, 15));
					checkcoli = true;
					q = 0;
				}
			}
			for (i = 0; i < alien1Vector.size(); i++) 
			{
				if (alien1Vector[i].colAlien() == 2) 
				{
					MyHP -= 10000;
					HP.setSize(sf::Vector2f(MyHP / 320.f, 15));
					checkcoli = true;
					q = 0;
				}
			}
			for (i = 0; i < alien2Vector.size(); i++) 
			{
				if (alien2Vector[i].colAlien() == 2) 
				{
					MyHP -= 10000;
					HP.setSize(sf::Vector2f(MyHP / 320.f, 15));
					checkcoli = true;
					q = 0;
				}
			}

			//Blood up
			for (i = 0; i < BloodupVector.size(); i++) 
			{
				if (BloodupVector[i].colBloodup() == 1) 
				{
					MyHP += 1000;
					HP.setSize(sf::Vector2f(MyHP / 320.f, 15));
					if (MyHP > 78000) MyHP = 78000;
					fontty.str(" ");
					fontty << "+5000 HP";
					fontbu.setString(fontty.str());
					fontbu.setPosition({ player.GetPosition().x , player.GetPosition().y - 90 });
					checkAdd = true;
				}
			}
			if (checkAdd == true) 
			{
				countTimeAdd += deltaTime;
				if (countTimeAdd > 0.75) 
				{
					fontbu.setPosition({ -800, 350 });
					countTimeAdd = 0;
					checkAdd = false;
				}
			}
			//Blood down
			for (i = 0; i < BlooddownVector.size(); i++) 
			{
				if (BlooddownVector[i].colBlooddown() == 2) 
				{
					MyHP -= 5000;
					HP.setSize(sf::Vector2f(MyHP / 320.f, 15));
					fontty.str(" ");
					fontty << "-5000 HP";
					fontbuu.setString(fontty.str());
					fontbuu.setPosition({ player.GetPosition().x,player.GetPosition().y - 90 });
					checkSub = true;
				}
			}
			if (checkSub == true) 
			{
				countTimeSub += deltaTime;
				if (countTimeSub > 0.75) 
				{
					fontbuu.setPosition({ -800, 350 });
					countTimeSub = 0;
					checkSub = false;
				}
			}
			//Power
			x10.setPosition(player.GetPosition().x, player.GetPosition().y - 30);
			if (player.getBuffStatus() == true) 
			{
				state = 1;
			}
			else 
			{
				state = 0;
			}

			ee.setPosition(view.getCenter().x - 540, 0);
			pp.setPosition(view.getCenter().x - 540, 0);
			pr.setPosition(view.getCenter().x - 540, 0);
			pm.setPosition(view.getCenter().x - 540, 0);
			pe.setPosition(view.getCenter().x - 540, 0);
			backmenuone.setPosition(view.getCenter().x - 540, 0);
			backmenutwo.setPosition(view.getCenter().x - 540, 0);
			Send.setPosition(view.getCenter().x - 100, 440);
			CSTER.setPosition(view.getCenter().x - 100, 516);
			yeah.setPosition(view.getCenter().x - 540, 0);
			NewScore.setPosition(view.getCenter().x - 108, 277);

			if (player.GetPosition().x >= 29160 && player.GetPosition().x <= 29527) 
			{
				state = 3;
			}

			if ((player.GetPosition().x >= 9221 && player.GetPosition().x <= 9300) && (player.GetPosition().y >= 327 && player.GetPosition().y <= 620))
			{
				Sound3.play();
				player.SetPosition(10568, 40);
				checkmap1 = true;
			}
			if ((player.GetPosition().x >= 18805 && player.GetPosition().x <= 18820) && (player.GetPosition().y >= 327 && player.GetPosition().y <= 620))
			{
				Sound3.play();
				player.SetPosition(20568, 40);
				checkmap2 = true;
				checkmap1 = false;
			}

			window.clear();
			window.setView(view);
			for (Platform& platform : platforms) 
			{
				platform.Draw(window);
			}

			window.draw(background1);
			window.draw(background2);
			window.draw(background3);
			window.draw(coinny);

			if (state == 1) 
			{
				window.draw(x10);
			}
			if (checkcoli == true) 
			{
				if (q < 10) 
				{
					if (q % 2 == 0 && timercoli.getElapsedTime().asSeconds() >= 0.1) 
					{
						checkdraw = true;
						q++;
						timercoli.restart();
					}
					else if (q % 2 != 0 && timercoli.getElapsedTime().asSeconds() >= 0.1) 
					{
						checkdraw = false;
						q++;
						timercoli.restart();
					}
					if (q == 10) 
					{
						checkcoli = false;
					}
				}
			}
			if (checkdraw == false) 
			{
				player.Draw(window);
			}

			window.draw(hpbar);
			window.draw(HP);
			window.draw(Score);
			window.draw(scoregame);
			window.draw(fontbu);
			window.draw(fontbuu);

			for (int i = 0; i < starVector.size(); i++) 
			{
				starVector[i]->draw(window);
			}
			for (int i = 0; i < BloodupVector.size(); i++) 
			{
				BloodupVector[i].draw(window);
			}
			for (int i = 0; i < BlooddownVector.size(); i++) 
			{
				BlooddownVector[i].draw(window);
			}
			for (int i = 0; i < X2Vector.size(); i++) 
			{
				X2Vector[i].draw(window);
			}
			for (int i = 0; i < alienVector.size(); i++) 
			{
				alienVector[i].draw(window);
			}
			for (int i = 0; i < alien1Vector.size(); i++)
			{
				alien1Vector[i].draw(window);
			}
			for (int i = 0; i < alien2Vector.size(); i++) 
			{
				alien2Vector[i].draw(window);
			}
			if (endGame == false && state != 3)
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) 
				{
					checkpause = true;
				}
			}

			if (checkpause == true) 
			{
				window.draw(pp);
				Send.setPosition(view.getCenter().x - 45, 200);
				CSTER.setPosition(view.getCenter().x - 45, 250);
				window.draw(CSTER);
				window.draw(Send);
				if (sf::Mouse::getPosition(window).x >= 416 && sf::Mouse::getPosition(window).y >= 307 && sf::Mouse::getPosition(window).x <= 655 && sf::Mouse::getPosition(window).y <= 368)
				{
					window.draw(pr);
					Send.setPosition(view.getCenter().x - 45, 200);
					CSTER.setPosition(view.getCenter().x - 45, 250);
					window.draw(CSTER);
					window.draw(Send);
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) 
					{
						checkpause = false;
					}
				}
				else if (sf::Mouse::getPosition(window).x >= 416 && sf::Mouse::getPosition(window).y >= 397 && sf::Mouse::getPosition(window).x <= 655 && sf::Mouse::getPosition(window).y <= 457)
				{
					window.draw(pm);
					Send.setPosition(view.getCenter().x - 45, 200);
					CSTER.setPosition(view.getCenter().x - 45, 250);
					window.draw(CSTER);
					window.draw(Send);
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) 
					{
						timerpausemenu.restart();
						checkpause = false;
						MENU = true;
						START = false;
						Rank = false;

						wall1.setPosition(view.getCenter().x - 540, 0.0f);
						wall2.setPosition(view.getCenter().x - 540, 0.0f);
						wall3.setPosition(view.getCenter().x - 540, 0.0f);
						wall4.setPosition(view.getCenter().x - 540, 0.0f);
						wall5.setPosition(view.getCenter().x - 540, 0.0f);
						wallhtp.setPosition(view.getCenter().x - 540, 0.0f);
						key.setPosition(view.getCenter().x - 540, 0.0f);
						hh.setPosition(view.getCenter().x - 540, 0.0f);
					    charr = event.text.unicode;
						text.setString(playerInput);
						cursor.setPosition(view.getCenter().x + 5 + text.getGlobalBounds().width + 10, 555.0f);
						Keyname.setPosition(view.getCenter().x - 200, 550);
						text.setPosition(view.getCenter().x - 15, 535.0f);
						ll.setPosition(view.getCenter().x - 540, 0.0f);
						DL.setPosition(view.getCenter().x - 255, 647.5f);
					}
				}
				else if (sf::Mouse::getPosition(window).x >= 416 && sf::Mouse::getPosition(window).y >= 486 && sf::Mouse::getPosition(window).x <= 655 && sf::Mouse::getPosition(window).y <= 546)
				{
					window.draw(pe);
					Send.setPosition(view.getCenter().x - 45, 200);
					CSTER.setPosition(view.getCenter().x - 45, 250);
					window.draw(CSTER);
					window.draw(Send);
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) 
					{
						window.close();
						break;
					}
				}
			}
			if (checkpause == false)
			{
				MyHP -= 5;
			}
			if (MyHP < 78000) {
				HP.setSize(sf::Vector2f(MyHP / 320.f, 15));
				if (MyHP < 0 || player.GetPosition().y >= 600) 
				{
					MyHP = 0;
					endGame = true;
					for (; soundcount < 1; soundcount++) 
					{
						sound_over = true;
					}
				}
			}
			if (endGame == true) 
			{
				window.draw(ee);
				window.draw(CSTER);
				window.draw(NewScore);
				window.draw(Send);
				window.draw(backmenuone);

				if (sf::Mouse::getPosition(window).x >= 400 && sf::Mouse::getPosition(window).y >= 600 && sf::Mouse::getPosition(window).x <= 680 && sf::Mouse::getPosition(window).y <= 650)
				{
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
					{

						cout << "Save score" << endl;

						vector<pair<int, string> > score;
						string temp, tempString;
						int tempInt = 0, X = 1;
						while (window.pollEvent(event))
						{
							if (event.type == sf::Event::Closed)
								window.close();
							fileWriter.open("bamja.txt", std::ios::out | std::ios::app);
							fileWriter << "\n" << user_name << "," << EndScore + EndNumStar;
							fileWriter.close();
							playerInput.clear();
						}
						myFile.close();

						MENU = true;
						START = false;
						Rank = false;
						sound_over = false;

						wall1.setPosition(view.getCenter().x - 540, 0.0f);
						wall2 .setPosition(view.getCenter().x - 540, 0.0f);
						wall3.setPosition(view.getCenter().x - 540, 0.0f);
						wall4.setPosition(view.getCenter().x - 540, 0.0f);
						wall5.setPosition(view.getCenter().x - 540, 0.0f);
						wallhtp.setPosition(view.getCenter().x - 540, 0.0f);
						key.setPosition(view.getCenter().x - 540, 0.0f);
						hh.setPosition(view.getCenter().x - 540, 0.0f);
						charr = event.text.unicode;
						text.setString(playerInput);
						cursor.setPosition(view.getCenter().x + 5 + text.getGlobalBounds().width + 10, 555.0f);
						Keyname.setPosition(view.getCenter().x - 240, 500);
						text.setPosition(view.getCenter().x - 15, 535.0f);
						ll.setPosition(view.getCenter().x - 540, 0.0f);
						DL.setPosition(view.getCenter().x - 255, 647.5f);
					}
				}
			}
			sound_over = false;
			if (state == 3) 
			{
				window.draw(yeah);
				window.draw(backmenuone);
				window.draw(CSTER);
				window.draw(NewScore);
				window.draw(Send);

				if (sf::Mouse::getPosition(window).x >= 400 && sf::Mouse::getPosition(window).y >= 600 && sf::Mouse::getPosition(window).x <= 680 && sf::Mouse::getPosition(window).y <= 650)
				{
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
					{
						cout << "Save score" << endl;

						vector<pair<int, string> > score;
						string temp, tempString;
						int tempInt = 0, X = 1;
						while (window.pollEvent(event))
						{
							if (event.type == sf::Event::Closed)
								window.close();
							fileWriter.open("bamja.txt", std::ios::out | std::ios::app);
							fileWriter << "\n" << user_name << "," << EndScore + EndNumStar;
							fileWriter.close();
							playerInput.clear();
						}
						myFile.close();

						MENU = true;
						START = false;
						Rank = false;
						sound_over = false;

						wall1.setPosition(view.getCenter().x - 540, 0.0f);
						wall2.setPosition(view.getCenter().x - 540, 0.0f);
						wall3.setPosition(view.getCenter().x - 540, 0.0f);
						wall4.setPosition(view.getCenter().x - 540, 0.0f);
						wall5.setPosition(view.getCenter().x - 540, 0.0f);
						wallhtp.setPosition(view.getCenter().x - 540, 0.0f);
						key.setPosition(view.getCenter().x - 540, 0.0f);
						hh.setPosition(view.getCenter().x - 540, 0.0f);
						charr = event.text.unicode;
						text.setString(playerInput);
						text.setString(playerInput);
						cursor.setPosition(view.getCenter().x + 5 + text.getGlobalBounds().width + 10, 555.0f);
						Keyname.setPosition(view.getCenter().x - 200, 555);
						text.setPosition(view.getCenter().x - 15, 535.0f);
						ll.setPosition(view.getCenter().x - 540, 0.0f);
						DL.setPosition(view.getCenter().x - 255, 647.5f);
					}
				}
			}
			if (checkpause == false) 
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) 
				{
					Sound2.play();
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) 
				{
					bulletCheck = player.getcheck();
					soundtwo.play();
					bullet1.attack(pos);
					Bul = 1;
				}
				if (Bul >= 1) 
				{
					if (bulletCheck == 1) 
					{
						bullet1.update(deltaTime);
					}
					else 
					{
						bullet1.update2(deltaTime);
					}
					bullet1.draw(window);
					for (i = 0; i < alienVector.size(); i++) 
					{
						if (alienVector[i].hit1() == 1) 
						{
							bullet1.del();
						}
					}
					for (i = 0; i < alien1Vector.size(); i++) 
					{
						if (alien1Vector[i].hit1() == 1) 
						{
							bullet1.del();
						}
					}
					for (i = 0; i < alien2Vector.size(); i++) 
					{
						if (alien2Vector[i].hit1() == 1) 
						{
							bullet1.del();
						}
					}
				}
				if (abs(player.GetPosition().x - bullet1.GetPosition().x) >= 500.0f) 
				{
					Bul = 0;
					bullet1.isAvaliable();
				}
			}
			window.display();
		}

		countloop++;
		endGame = false;
		player.SetPosition(200, 520);
		player.ResetNumstar();

		for (int i = 0; i < starVector.size(); i++) 
		{
			starVector.erase(starVector.begin() + i);
		}
		starVector.clear();

		for (int i = 0; i < alienVector.size(); i++) 
		{
			alienVector.erase(alienVector.begin() + i);
		}
		alienVector.clear();

		for (int i = 0; i < alien1Vector.size(); i++) 
		{
			alien1Vector.erase(alien1Vector.begin() + i);
		}
		alien1Vector.clear();

		for (int i = 0; i < alien2Vector.size(); i++)
		{
			alien2Vector.erase(alien2Vector.begin() + i);
		}
		alien2Vector.clear();

		for (int i = 0; i < BloodupVector.size(); i++) 
		{
			BloodupVector.erase(BloodupVector.begin() + i);
		}
		BloodupVector.clear();

		for (int i = 0; i < BlooddownVector.size(); i++) 
		{
			BlooddownVector.erase(BlooddownVector.begin() + i);
		}
		BlooddownVector.clear();

		for (int i = 0; i < X2Vector.size(); i++) 
		{
			X2Vector.erase(X2Vector.begin() + i);
		}
		X2Vector.clear();
	}
	return 0;
}