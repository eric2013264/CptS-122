//
// gamePlay.cpp
// ConsoleApplication1
//
// Created by Eliot Ascaso, Eric Chen, and Trevor Mozingo on 11/25/2014
// Copyright (c) 2014 eliotascaso, ericchen, and trevormozingo. All rights reserved.
//

/*
Description >>>
>>> SEE HEADER FILE
*/

#include "GamePlay.h"

GamePlay::GamePlay() {										//THIS WILL INITIALIZE EVERYTHING
	_run = true;
	_window.create(sf::VideoMode(1200, 700), "ASTEROIDS");
	//_personalLocal = sf::IpAddress::getLocalAddress();	//NETWORKING NOT READY
	_game = true;
}

void GamePlay::GamePlayExecute() {
	int _points = 0;
	int i = 0, count = 0;
	int play = 0;
	int play2 = 0;
	int n1=0,n2=0,n3=0,n4=0,n5=0;
	int temp =0;
	sf::Sprite _space, _number,_number0,_number2,_number3,_number4,_number5,_number6,_number7,_number8,_number9, _number10,_number00,_number20,_number30,_number40,_number50,_number60,_number70,_number80,_number90, _number100,_number000,_number200,_number300,_number400,_number500,_number600,_number700,_number800,_number900;
	sf::Texture _spc,_0, _1,_2,_3,_4,_5,_6,_7,_8,_9,_00,_10,_20,_30,_40,_50,_60,_70,_80,_90,_000,_100,_200,_300,_400,_500,_600,_700,_800,_900;
	////////////////////////////////////////////////////
	
	
	////////////////////////////////////////////////////SOUNDS

	sf::SoundBuffer buffer;
	sf::SoundBuffer buffer2;
	sf::SoundBuffer buffer3;
	sf::SoundBuffer buffer4;
	sf::SoundBuffer buffer5;
	sf::SoundBuffer buffer6;

	buffer6.loadFromFile("pew1.wav");
	buffer5.loadFromFile("engine1.wav");
	buffer4.loadFromFile("lose.wav");
	buffer3.loadFromFile("Destroy.wav");
	buffer2.loadFromFile("engine.wav");
	buffer.loadFromFile("pew.wav");

	sf::Sound sound, sound2, sound3, sound4, sound5, sound6;
	
	sound.setBuffer(buffer);
	sound2.setBuffer(buffer2);
	sound3.setBuffer(buffer3);
	sound4.setBuffer(buffer4);
	sound5.setBuffer(buffer5);
	sound6.setBuffer(buffer6);

	sound5.setPitch(0.5f);
	sound6.setPitch(0.5f);
	///////////////////////////////////////////////////
	

	_spc.loadFromFile("space.jpg");
	_space.setTexture(_spc);
	_space.setPosition(0.0f, 0.0f);
	
	_0.loadFromFile("zero.png");
	_1.loadFromFile("one.png");
	_2.loadFromFile("two.png");
	_3.loadFromFile("three.png");
	_4.loadFromFile("four.png");
	_5.loadFromFile("five.png");
	_6.loadFromFile("six.png");
	_7.loadFromFile("seven.png");
	_8.loadFromFile("eight.png");
	_9.loadFromFile("nine.png");
	///////////////////////////////
	_00.loadFromFile("zero.png");
	_10.loadFromFile("one.png");
	_20.loadFromFile("two.png");
	_30.loadFromFile("three.png");
	_40.loadFromFile("four.png");
	_50.loadFromFile("five.png");
	_60.loadFromFile("six.png");
	_70.loadFromFile("seven.png");
	_80.loadFromFile("eight.png");
	_90.loadFromFile("nine.png");
	///////////////////////////////
	_000.loadFromFile("zero.png");
	_100.loadFromFile("one.png");
	_200.loadFromFile("two.png");
	_300.loadFromFile("three.png");
	_400.loadFromFile("four.png");
	_500.loadFromFile("five.png");
	_600.loadFromFile("six.png");
	_700.loadFromFile("seven.png");
	_800.loadFromFile("eight.png");
	_900.loadFromFile("nine.png");
	///////////////////////////////
	_number0.setTexture(_0);
	_number.setTexture(_1);
	_number2.setTexture(_2);
	_number3.setTexture(_3);
	_number4.setTexture(_4);
	_number5.setTexture(_5);
	_number6.setTexture(_6);
	_number7.setTexture(_7);
	_number8.setTexture(_8);
	_number9.setTexture(_9);
	////////////////////////////
	_number00.setTexture(_00);
	_number10.setTexture(_10);
	_number20.setTexture(_20);
	_number30.setTexture(_30);
	_number40.setTexture(_40);
	_number50.setTexture(_50);
	_number60.setTexture(_60);
	_number70.setTexture(_70);
	_number80.setTexture(_80);
	_number90.setTexture(_90);
	///////////////////////////
	_number000.setTexture(_000);
	_number100.setTexture(_100);
	_number200.setTexture(_200);
	_number300.setTexture(_300);
	_number400.setTexture(_400);
	_number500.setTexture(_500);
	_number600.setTexture(_600);
	_number700.setTexture(_700);
	_number800.setTexture(_800);
	_number900.setTexture(_900);
	////////////////////////////
	_number.setPosition(890.0f, -20.0f);
	_number0.setPosition(890.0f, -20.0f);
	_number2.setPosition(890.0f, -20.0f);
	_number3.setPosition(890.0f, -20.0f);
	_number4.setPosition(890.0f, -20.0f);
	_number5.setPosition(890.0f, -20.0f);
	_number6.setPosition(890.0f, -20.0f);
	_number7.setPosition(890.0f, -20.0f);
	_number8.setPosition(890.0f, -20.0f);
	_number9.setPosition(890.0f, -20.0f);
	///////////////////////////////////
	_number10.setPosition(640.0f, -20.0f);
	_number00.setPosition(640.0f, -20.0f);
	_number20.setPosition(640.0f, -20.0f);
	_number30.setPosition(640.0f, -20.0f);
	_number40.setPosition(640.0f, -20.0f);
	_number50.setPosition(640.0f, -20.0f);
	_number60.setPosition(640.0f, -20.0f);
	_number70.setPosition(640.0f, -20.0f);
	_number80.setPosition(640.0f, -20.0f);
	_number90.setPosition(640.0f, -20.0f);
	///////////////////////////////////
	_number100.setPosition(390.0f, -20.0f);
	_number000.setPosition(390.0f, -20.0f);
	_number200.setPosition(390.0f, -20.0f);
	_number300.setPosition(390.0f, -20.0f);
	_number400.setPosition(390.0f, -20.0f);
	_number500.setPosition(390.0f, -20.0f);
	_number600.setPosition(390.0f, -20.0f);
	_number700.setPosition(390.0f, -20.0f);
	_number800.setPosition(390.0f, -20.0f);
	_number900.setPosition(390.0f, -20.0f);
	//////////////////////////////////////////////////
	while (_run == true) {
		Menu menu;											//MENU
		_option = menu.Start(_window);
		if (_option == 1) {									 //SINGLE PLAYER
			int speed = 1000;
			_window.close();
			_window.create(sf::VideoMode(1200, 700), "ASTEROIDS");
			Pawn _player;									//SELF AND MULTIPLAYER SPACESHIPS
			std::vector<Projectile> _bulletsPlayer;			//DYNAMIC ARRAYS VECTOR USAGE-----> https://www.youtube.com/watch?v=Cq1h1KPoGBU
			std::vector<Asteroid> _asteroids;				//DYNAMIC ARRAY OF ASTEROIDS
			sf::Clock _clock, _clock2, _clock3;				//TIMERS
			sf::Time _time, _time2, _time3;					//TIMERS
			
			sf::Music music2;
			if(!music2.openFromFile("game.ogg"))
			{
			std::cout << "couldnt open game music";
			}
			music2.setVolume(100);
			music2.play();

//////////////////////////////////////////////////////////SINGLE PLAYER LOOP////////////////////////////////////////////////////////////////////////////////////////////////////
			while (_game == true && (_player.GetLives() > 0)) {
				
					

								
								if (n1 == 0){   
									_window.draw(_space);
									_window.draw(_number0);}
								if (n1 == 1){  
									_window.draw(_space);
									_window.draw(_number);}
								if (n1 == 2){  
									_window.draw(_space);
									_window.draw(_number2);}
								if (n1 == 3){  
									_window.draw(_space);
									_window.draw(_number3);}
								if (n1 == 4){  
									_window.draw(_space);
									_window.draw(_number4);}
								if (n1 == 5){  
									_window.draw(_space);
									_window.draw(_number5);}
								if (n1 == 6){  
									_window.draw(_space);
									_window.draw(_number6);}
								if (n1 == 7){  
									_window.draw(_space);
									_window.draw(_number7);}
								if (n1 == 8){  
									_window.draw(_space);
									_window.draw(_number8);}
								if (n1 == 9){  
									_window.draw(_space);
									_window.draw(_number9);}
								//////////////////
								if (n2 == 0){ _window.draw(_number00);}
								if (n2 == 1){ _window.draw(_number10);}
								if (n2 == 2){ _window.draw(_number20);}
								if (n2 == 3){ _window.draw(_number30);}
								if (n2 == 4){ _window.draw(_number40);}
								if (n2 == 5){ _window.draw(_number50);}
								if (n2 == 6){ _window.draw(_number60);}
								if (n2 == 7){ _window.draw(_number70);}
								if (n2 == 8){ _window.draw(_number80);}
								if (n2 == 9){ _window.draw(_number90);}
								//////////////////
								if (n3 == 0){ _window.draw(_number000);}
								if (n3 == 1){ _window.draw(_number100);}
								if (n3 == 2){ _window.draw(_number200);}
								if (n3 == 3){ _window.draw(_number300);}
								if (n3 == 4){ _window.draw(_number400);}
								if (n3 == 5){ _window.draw(_number500);}
								if (n3 == 6){ _window.draw(_number600);}
								if (n3 == 7){ _window.draw(_number700);}
								if (n3 == 8){ _window.draw(_number800);}
								if (n3 == 9){ _window.draw(_number900);}
								//////////////////
								temp = _points;
								n1 = temp%10;
								temp /= 10;
								n2 = temp%10;
								temp/= 10;
								n3 = temp%10;
								temp /= 10;
								n4 = temp%10;
								temp /= 10;
								n5 = temp%10;
								
								//std::cout <<"\nn1:"<< n1 << "\n" << n2 << "\n" << n3 << "\n" << n4 << "\n" << n5;
				if (play ==1 && sound2.getStatus() != sf::Sound::Status::Playing) 
				{
					sound2.play();
				}
				if (play == 0) {
					sound2.stop();
				}
				Projectile _bullet(_player.GameObjectGetXCord(), _player.GameObjectGetYCord(), _player.GetGunOption(), _player.GameObjectGetRot());
				Asteroid _asteroid;
				_time = _clock.getElapsedTime();
				_time2 = _clock2.getElapsedTime();
				_time3 = _clock3.getElapsedTime();
				if (_time.asMilliseconds() > 0.5) {
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
						play = 1;
						_player.GameObjectMove(_window);
					}
					if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
					{
						play = 0;
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
						_player.GameObjectRotateLeft();
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
						
						_window.close();
						std::cout << "have nice day\n";
						return;
						
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
						_player.GameObjectRotateRight();
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
						if (_time2.asMilliseconds() > 300.0) {
							sound.play();
							_player.PawnShoot(_bulletsPlayer, _bullet);
							_clock2.restart();
						}
					}	
					for (int i = 0; i < _asteroids.size(); i++) {
						_asteroids[i].GameObjectDisplay(_window);
						_asteroids[i].GameObjectMove();
						if (_asteroids[i].GameObjectGetXCord() > 1250 || _asteroids[i].GameObjectGetXCord() < -50 || _asteroids[i].GameObjectGetYCord() < -50 || _asteroids[i].GameObjectGetYCord() > 1250) {
							
							_asteroids.erase(_asteroids.begin() + i);
							count--;
						}
						if (((abs(_asteroids[i].GameObjectGetXCord() - _player.GameObjectGetXCord())) < 35) && ((abs(_asteroids[i].GameObjectGetYCord() - _player.GameObjectGetYCord())) < 35)) {
							sound3.play();
							_asteroids.erase(_asteroids.begin() + i);
							count--;
							
							_player.PawnDied();
							
						}
						for (int ii = 0; ii < _bulletsPlayer.size(); ii++) {
							if ((abs(_bulletsPlayer[ii].GameObjectGetXCord() - _asteroids[i].GameObjectGetXCord()) < 35) && (abs(_bulletsPlayer[ii].GameObjectGetYCord() - _asteroids[i].GameObjectGetYCord()) < 35)) {
								_bulletsPlayer.erase(_bulletsPlayer.begin() + ii);
								sound3.play();
								_asteroids.erase(_asteroids.begin() + i);
								count--;
								_points ++;
								_player.AddPoint();
							}
						}
					}
					if (_time3.asSeconds() > 1.0f && count < 6) {
						_asteroids.push_back(_asteroid);
						_clock3.restart();
						count++;
					}
					_clock.restart();
				}
				_player.GameObjectDisplay(_window);
				_player.PawnShootDisplay(_window, _bulletsPlayer);
				_window.display();
				_window.clear();
			}
			std::cout << "Score:" << _points << "\n";
			_points = 0;
			sound4.play();
//////////////////////////////////////////////////////////SINGLE PLAYER LOOP////////////////////////////////////////////////////////////////////////////////////////////////////
		}

		if (_option == 2) { // NETWORKING NOT YET READY
			/*
			*******************************************TESTING CODE FOR NETWORKING NOT YET READY >>> WILL CONNECT TO CLIENT BUT CRASHES WHEN SENDING DATA
			sf::Packet packet;
			std::string data;
			_window.close();
			while (_socket.bind(portServer) != sf::Socket::Done) {
			_socket.bind(portServer);
			}
			std::cout << "UDP SOCKET WAS BOUND TO PORT: " << portServer << " SUCCESSFULLY" << std::endl;
			std::cout << "SERVER ADDRESS >>> " << _personalLocal << std::endl;
			std::cout << "WAITING FOR CLIENT..." << std::endl;
			_socket.receive(packet, _clientLocal, _clientPort);
			std::cout << "CLIENT CONNECTED SUCCESSFULLY" << std::endl;
			packet << data;
			_socket.send(packet, _clientLocal, _clientPort);
			_socket.setBlocking(false);
			packet.~Packet();
			//_window.create(sf::VideoMode(1200, 700), "ASTEROIDS");
			while (_game == true) {

			sf::Packet packetOut, packetIn;
			std::string strangOut, strangIn;
			std::cout << "<- ";
			std::cin >> strangOut;
			prevData = strangOut;
			packetOut << strangOut;
			_socket.send(packetOut, _clientLocal, _clientPort);
			packetOut.clear();
			_socket.receive(packetIn, _clientLocal, _clientPort);
			packetIn >> strangIn;

			if (prevData != strangIn) {
			std::cout << "->" << strangIn << std::endl;
			}
			packetIn.clear();
			}
			*/
		}
		if (_option == 3) { // NETWORKING NOT YET READY
			/*
			***************************TESTING CODE FOR NETWORKING 
			>>> STATUS, WILL CONNECT TO CLIENT BUT CRASHES WHEN DATA SENT
			****************************************************************

			sf::Packet packet;
			std::string data;
			data = "PING";
			_window.close();
			while (_socket.bind(sf::Socket::AnyPort) != sf::Socket::Done) {
				_socket.bind(sf::Socket::AnyPort);
			}
			std::cout << "UDP SOCKET WAS BOUND TO PORT: " << _socket.getLocalPort() << " SUCCESSFULLY" << std::endl;
			std::cout << "ENTER SERVER ADDRESS >>> ";
			std::cin >> _serverLocal;
			std::cout << "WAITING FOR SERVER..." << std::endl;
			packet << data;
			_socket.send(packet, _serverLocal, portServer);
			_socket.receive(packet, _serverLocal, _serverPort);
			packet >> data;
			std::cout << "CONNECTED TO SERVER SUCCESSFULLY" << std::endl;
			_socket.setBlocking(false);
			packet.~Packet();
			//_window.create(sf::VideoMode(1200, 700), "ASTEROIDS");
			while (_game == true) {

				sf::Packet packetOut, packetIn;
				std::string strangOut, strangIn;
				std::cout << "<- ";
				std::cin >> strangOut;
				prevData = strangOut;
				packetOut << strangOut;
				_socket.send(packetOut, _serverLocal, _serverPort);
				packetOut.clear();
				_socket.receive(packetIn, _serverLocal, _serverPort);
				packetIn >> strangIn;
				
				if (prevData != strangIn) {
					std::cout << "->" << strangIn << std::endl;
				}
				packetIn.clear();
			}
			*/
		}
		if (_option == 4) { //SHARED SCREEN MULTIPLAYER
			int speed = 1000;
			_window.close();
			_window.create(sf::VideoMode(1200, 700), "ASTEROIDS");
			Pawn _player, _friend;										//SELF AND MULTIPLAYER SPACESHIPS
			std::vector<Projectile> _bulletsPlayer, _bulletsFriend;		//DYNAMIC ARRAYS VECTOR USAGE-----> https://www.youtube.com/watch?v=Cq1h1KPoGBU
			std::vector<Asteroid> _asteroids;							//DYNAMIC ARRAY OF ASTEROIDS
			sf::Clock _clock, _clock2, _clock3, _clock4;				//TIMERS
			sf::Time _time, _time2, _time3, _time4;						//TIMERS
			
			sf::Music music2;
			
	
			if(!music2.openFromFile("game.ogg"))
			{
			std::cout << "couldnt open game music";
			}
			
			music2.setVolume(100);
			music2.play();
//////////////////////////////////////////////////////////MULTIPLE PLAYER LOOP////////////////////////////////////////////////////////////////////////////////////////////////////
			while (_game == true && (_player.GetLives() > 0) && (_friend.GetLives() > 0)) {
								
								if (n1 == 0){   
									_window.draw(_space);
									_window.draw(_number0);}
								if (n1 == 1){  
									_window.draw(_space);
									_window.draw(_number);}
								if (n1 == 2){  
									_window.draw(_space);
									_window.draw(_number2);}
								if (n1 == 3){  
									_window.draw(_space);
									_window.draw(_number3);}
								if (n1 == 4){  
									_window.draw(_space);
									_window.draw(_number4);}
								if (n1 == 5){  
									_window.draw(_space);
									_window.draw(_number5);}
								if (n1 == 6){  
									_window.draw(_space);
									_window.draw(_number6);}
								if (n1 == 7){  
									_window.draw(_space);
									_window.draw(_number7);}
								if (n1 == 8){  
									_window.draw(_space);
									_window.draw(_number8);}
								if (n1 == 9){  
									_window.draw(_space);
									_window.draw(_number9);}
								//////////////////
								if (n2 == 0){ _window.draw(_number00);}
								if (n2 == 1){ _window.draw(_number10);}
								if (n2 == 2){ _window.draw(_number20);}
								if (n2 == 3){ _window.draw(_number30);}
								if (n2 == 4){ _window.draw(_number40);}
								if (n2 == 5){ _window.draw(_number50);}
								if (n2 == 6){ _window.draw(_number60);}
								if (n2 == 7){ _window.draw(_number70);}
								if (n2 == 8){ _window.draw(_number80);}
								if (n2 == 9){ _window.draw(_number90);}
								//////////////////
								if (n3 == 0){ _window.draw(_number000);}
								if (n3 == 1){ _window.draw(_number100);}
								if (n3 == 2){ _window.draw(_number200);}
								if (n3 == 3){ _window.draw(_number300);}
								if (n3 == 4){ _window.draw(_number400);}
								if (n3 == 5){ _window.draw(_number500);}
								if (n3 == 6){ _window.draw(_number600);}
								if (n3 == 7){ _window.draw(_number700);}
								if (n3 == 8){ _window.draw(_number800);}
								if (n3 == 9){ _window.draw(_number900);}
								//////////////////
								temp = _points;
								n1 = temp%10;
								temp /= 10;
								n2 = temp%10;
								temp/= 10;
								n3 = temp%10;
								temp /= 10;
								n4 = temp%10;
								temp /= 10;
								n5 = temp%10;
								//std::cout <<"\nn1:"<< n1 << "\n" << n2 << "\n" << n3 << "\n" << n4 << "\n" << n5;
				Projectile _bullet(_player.GameObjectGetXCord(), _player.GameObjectGetYCord(), _player.GetGunOption(), _player.GameObjectGetRot());
				Projectile _bulletfriend(_friend.GameObjectGetXCord(), _friend.GameObjectGetYCord(), _friend.GetGunOption(), _friend.GameObjectGetRot());
				Asteroid _asteroid;
				_time = _clock.getElapsedTime();
				_time2 = _clock2.getElapsedTime();
				_time3 = _clock3.getElapsedTime();
				_time4 = _clock4.getElapsedTime();

				if (play ==1 && sound2.getStatus() != sf::Sound::Status::Playing) 
				{
					sound2.play();
				}
				if (play == 0)
				{
					sound2.stop();
				}
				if (play2 ==1 && sound5.getStatus() != sf::Sound::Status::Playing) 
				{
					sound5.play();
				}
				if (play2 == 0)
				{
					sound5.stop();
				}
				if (_time.asMilliseconds() > 1) {

					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
						
						play = 1;
						_player.GameObjectMove(_window);
					}
					if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
						
						play = 0;
						
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
						_player.GameObjectRotateLeft();
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
						_player.GameObjectRotateRight();
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
						if (_time2.asMilliseconds() > 300.0) {
							sound.play();
							_player.PawnShoot(_bulletsPlayer, _bullet);
							_clock2.restart();
						}
					}
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
						
						_window.close();
						std::cout << "have nice day\n";
						return;
						
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
						_friend.GameObjectMove(_window);
						play2 = 1;
					}
					if (!sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
						play2 = 0;
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
						_friend.GameObjectRotateLeft();
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
						_friend.GameObjectRotateRight();
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
						if (_time4.asMilliseconds() > 300.0) {
							sound6.play();
							_friend.PawnShoot(_bulletsFriend, _bulletfriend);
							_clock4.restart();
						}
					}
					for (int i = 0; i < _asteroids.size(); i++) {
						_asteroids[i].GameObjectDisplay(_window);
						_asteroids[i].GameObjectMove();
						if (_asteroids[i].GameObjectGetXCord() > 1250 || _asteroids[i].GameObjectGetXCord() < -50 || _asteroids[i].GameObjectGetYCord() < -50 || _asteroids[i].GameObjectGetYCord() > 1250) {
							_asteroids.erase(_asteroids.begin() + i);
							count--;
						}
						if (((abs(_asteroids[i].GameObjectGetXCord() - _player.GameObjectGetXCord())) < 35) && ((abs(_asteroids[i].GameObjectGetYCord() - _player.GameObjectGetYCord())) < 35)) {
							_asteroids.erase(_asteroids.begin() + i);
							count--;
							sound3.play();
						
							_player.PawnDied();
						}
						for (int ii = 0; ii < _bulletsPlayer.size(); ii++) {
							if ((abs(_bulletsPlayer[ii].GameObjectGetXCord() - _asteroids[i].GameObjectGetXCord()) < 35) && (abs(_bulletsPlayer[ii].GameObjectGetYCord() - _asteroids[i].GameObjectGetYCord()) < 35)) {
								_bulletsPlayer.erase(_bulletsPlayer.begin() + ii);
								_asteroids.erase(_asteroids.begin() + i);
								count--;
								_points++;
								sound3.play();
								_player.AddPoint();
							}
						}
					}
					for (int i = 0; i < _asteroids.size(); i++) {
						_asteroids[i].GameObjectDisplay(_window);
						_asteroids[i].GameObjectMove();
						if (_asteroids[i].GameObjectGetXCord() > 1250 || _asteroids[i].GameObjectGetXCord() < -50 || _asteroids[i].GameObjectGetYCord() < -50 || _asteroids[i].GameObjectGetYCord() > 1250) {
							_asteroids.erase(_asteroids.begin() + i);
							count--;
						}
						if (((abs(_asteroids[i].GameObjectGetXCord() - _friend.GameObjectGetXCord())) < 35) && ((abs(_asteroids[i].GameObjectGetYCord() - _friend.GameObjectGetYCord())) < 35)) {
							_asteroids.erase(_asteroids.begin() + i);
							count--;
							sound3.play();
							_friend.PawnDied();
						}
						for (int ii = 0; ii < _bulletsFriend.size(); ii++) {
							if ((abs(_bulletsFriend[ii].GameObjectGetXCord() - _asteroids[i].GameObjectGetXCord()) < 35) && (abs(_bulletsFriend[ii].GameObjectGetYCord() - _asteroids[i].GameObjectGetYCord()) < 35)) {
								_bulletsFriend.erase(_bulletsFriend.begin() + ii);
								_asteroids.erase(_asteroids.begin() + i);
								count--;
								_points++;
								sound3.play();
								_friend.AddPoint();
							}
						}
					}
					if (_time3.asSeconds() > 1.0f) {
						_asteroids.push_back(_asteroid);
						_clock3.restart();
						count++;
					}
					_clock.restart();
				}
				_player.GameObjectDisplay(_window);
				_player.PawnShootDisplay(_window, _bulletsPlayer);
				_friend.GameObjectDisplay(_window);
				_friend.PawnShootDisplay(_window, _bulletsFriend);
				_window.display();
				_window.clear();
			}
			std::cout << "Score:" << _points << "\n";
			_points = 0;
			sound4.play();
//////////////////////////////////////////////////////////MULTIPLE PLAYER LOOP////////////////////////////////////////////////////////////////////////////////////////////////////
		}
		if(_option == 5) {
			_window.close();
			_window.create(sf::VideoMode(1200, 700), "ASTEROIDS");
			while (_game == true) {
				sf::Sprite _instruction;
				sf::Texture _instruct;
				_instruct.loadFromFile("inform.png");
				_instruction.setTexture(_instruct);
				_instruction.setPosition(0.0f, 0.0f);
				_window.draw(_instruction);
				_window.display();
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
					_game = false;
					_option = 0;
				}
			}
			_game = true;
		}
		if (_option == 6) {
			_run = false;
			_window.close();
		}
		_option = 0;
	}
}