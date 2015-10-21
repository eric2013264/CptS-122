//
// GamePlay.h
// ConsoleApplication1
//
// Created by Eliot Ascaso, Eric Chen, and Trevor Mozingo on 11/25/2014
// Copyright (c) 2014 eliotascaso, ericchen, and trevormozingo. All rights reserved.
//

/*
Description >>>
>>> MAIN GAME CONTROLER
*/

#pragma once

#include "Header.h"
#include "Menu.h"
#include "Pawn.h"
#include "Asteroid.h"


class GamePlay {
public:
	GamePlay();
	void GamePlayExecute();
private:
	//NETWORKING NOT YET AVAILABLE
	//*********************************************CLIENT / SERVER CONNECTION APPLICATIONS********************
	/*sf::IpAddress _personalLocal, _clientLocal, _serverLocal;		//SELF EXPANATORY ---- FOR LOCAL CONNECTIONS ONLY / NOT OVER WWW
	sf::UdpSocket _socket, _socket2;								//CONNECTION ENDPOINTS O<---->O
	unsigned short _clientPort, _serverPort;						//PORT OF INCOMMING DATA
	std::string prevData;
	float prevInfo;*/
	//*********************************************GAME SPECIFIC APPLICATIONS*********************************
	bool _run, _game;
	sf::RenderWindow _window;
	int _option;

	
};