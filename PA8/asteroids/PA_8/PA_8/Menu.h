//
// Menu.h
// ConsoleApplication1
//
// Created by Eliot Ascaso, Eric Chen, and Trevor Mozingo on 11/25/2014
// Copyright (c) 2014 eliotascaso, ericchen, and trevormozingo. All rights reserved.
//

/*
Description >>>
>>> WILL PROVIDE GUI MENU BEFORE AND GAME RUNTIME
*/

#pragma once

#include "Header.h"

class Menu {	//https://www.youtube.com/watch?v=4Vg9d1pjL20
public:
	Menu();
	~Menu();
	int Start(sf::RenderWindow& source);
private: 
	sf::Sprite _instruction,_instructionT,_Menu,_ofallon,_singlePlayerReg, _hostReg, _joinReg, _quitReg, _singlePlayerTouch, _hostTouch, _joinTouch, _quitTouch, _quittoReg, _quittoTouch, _resumeReg, _resumeTouch, _multiReg, _multiTouch;
	sf::Texture _In,_InT, _Mn, _ofall, _sPR, _hR, _jR, _qR, _sPT, _hT, _jT, _qT, _qTR, _qTT, _rR, _rT, _mR, _mT;
	bool _run;
	int _selected;
	sf::Time _time;
	sf::Clock _clock;
};