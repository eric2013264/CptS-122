//
// menu.cpp
// ConsoleApplication1
//
// Created by Eliot Ascaso, Eric Chen, and Trevor Mozingo on 11/25/2014
// Copyright (c) 2014 eliotascaso, ericchen, and trevormozingo. All rights reserved.
//

/*
Description >>>
>>> SEE HEADER FILE
*/

#include "Menu.h"

Menu::Menu() {
	
	_run = true;
	float a = 350.0;
	_selected = 0;
	
	_Mn.loadFromFile("menu.png");
	_Menu.setTexture(_Mn);
	_Menu.setPosition(0.0f, 0.0f);
	_Menu.setScale(2.3f, 2.3f);

	_ofall.loadFromFile("ofallon.png");
	_ofallon.setTexture(_ofall);
	_ofallon.setPosition(350.0f, 383.0f);


	_In.loadFromFile("instruction.png");
	_instruction.setTexture(_In);
	_instruction.setPosition(100.0f,300.0f);
	_instruction.setScale(0.4f, 0.4f);
	
	_InT.loadFromFile("instructiontouch.png");
	_instructionT.setTexture(_InT);
	_instructionT.setPosition(100.0f,300.0f);
	_instructionT.setScale(0.7f, 0.7f);

	_sPR.loadFromFile("singleNorm.png");
	_hR.loadFromFile("hostNorm.png");
	_jR.loadFromFile("joinNorm.png");
	_qR.loadFromFile("quitNorm.png");
	_sPT.loadFromFile("singleTouch.png");
	_hT.loadFromFile("hostTouch.png");
	_jT.loadFromFile("joinTouch.png");
	_qT.loadFromFile("quitTouch.png");
	_qTR.loadFromFile("quittoNorm.png");
	_qTT.loadFromFile("quittoTouch.png");
	_rR.loadFromFile("returnNorm.png");
	_rT.loadFromFile("returnTouch.png");
	_mR.loadFromFile("multiNorm.png");
	_mT.loadFromFile("multiTouch.png");

	_singlePlayerReg.setTexture(_sPR);
	_hostReg.setTexture(_hR);
	_joinReg.setTexture(_jR);
	_multiReg.setTexture(_mR);
	_quitReg.setTexture(_qR);
	_singlePlayerTouch.setTexture(_sPT);
	_hostTouch.setTexture(_hT);
	_joinTouch.setTexture(_jT);
	_multiTouch.setTexture(_mT);
	_quitTouch.setTexture(_qT);
	_quittoReg.setTexture(_qTR);
	_quittoTouch.setTexture(_qTT);
	_resumeReg.setTexture(_rR);
	_resumeTouch.setTexture(_rT);

	_singlePlayerReg.setPosition(100.0f, 100.0f);
	_hostReg.setPosition(100.0f, 150.0f);
	_joinReg.setPosition(100.0f, 200.0f);
	_multiReg.setPosition(100.0f, 250.0f);
	_quitReg.setPosition(100.0f, 350.0f);
	_singlePlayerTouch.setPosition(100.0f, 100.0f);
	_hostTouch.setPosition(100.0f, 150.0f);
	_joinTouch.setPosition(100.0f, 200.0f);
	_multiTouch.setPosition(100.0f, 250.0f);
	_quitTouch.setPosition(100.0f, 350.0f);
	_quittoReg.setPosition(100.0f, 150.0f);
	_quittoTouch.setPosition(100.0f, 150.0f);
	_resumeReg.setPosition(100.0f, 100.0f);
	_resumeTouch.setPosition(100.0f, 100.0f);

	_singlePlayerReg.setScale(0.5f, 0.5f);
	_hostReg.setScale(0.5f, 0.5f);
	_joinReg.setScale(0.5f, 0.5f);
	_multiReg.setScale(0.5f, 0.5f);
	_quitReg.setScale(0.5f, 0.5f);
	_singlePlayerTouch.setScale(0.5f, 0.5f);
	_hostTouch.setScale(0.5f, 0.5f);
	_joinTouch.setScale(0.5f, 0.5f);
	_multiTouch.setScale(0.5f, 0.5f);
	_quitTouch.setScale(0.5f, 0.5f);
	_quittoReg.setScale(0.5f, 0.5f);
	_quittoTouch.setScale(0.5f, 0.5f);
	_resumeReg.setScale(0.5f, 0.5f);
	_resumeTouch.setScale(0.5f, 0.5f);

}

Menu::~Menu() {}

int Menu::Start(sf::RenderWindow& source) {
	int i = 0;
	int temp = 0;
	int slower = 0;
	float a =-400.0;


	sf::Music music;
	if(!music.openFromFile("menu.wav"))
	{
		std::cout << "couldnt open menu music";
	}
		music.setVolume(100);
		music.play();


	while (_run == true) {
		
		_ofallon.setPosition(a, 383.0f);
		
		if (slower == 0)
		{
		a ++;
		
		}
		slower ++;
		if (slower == 20)
		{
			slower = 0;
		}
		if (a > 1590)
		{
			a = -500;
		}

		_time = _clock.getElapsedTime();
		source.clear();
		if (_time.asSeconds() > 0.10) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
				i++;
				if (i > 6) {
					i = 0;
				}
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
				i--;
				if (i < 0) {
					i = 6;
				}
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
				_run = false;
			}
			_clock.restart();
		}

		switch (i) {
		case(0) :
			source.draw(_Menu);
			source.draw(_singlePlayerReg);
			source.draw(_hostReg);
			source.draw(_joinReg);
			source.draw(_multiReg);
			source.draw(_quitReg);
			source.draw(_instruction);
			break;
		case(1):
			source.draw(_Menu);
			source.draw(_singlePlayerTouch);
			source.draw(_hostReg);
			source.draw(_joinReg);
			source.draw(_multiReg);
			source.draw(_quitReg);
			source.draw(_instruction);
			break;
		case (2):
			source.draw(_Menu);
			source.draw(_singlePlayerReg);
			source.draw(_hostTouch);
			source.draw(_joinReg);
			source.draw(_multiReg);
			source.draw(_quitReg);
			source.draw(_instruction);
			break;
		case (3):
			source.draw(_Menu);
			source.draw(_singlePlayerReg);
			source.draw(_hostReg);
			source.draw(_joinTouch);
			source.draw(_multiReg);
			source.draw(_quitReg);
			source.draw(_instruction);
			break;
		case (4):
			source.draw(_Menu);
			source.draw(_singlePlayerReg);
			source.draw(_hostReg);
			source.draw(_joinReg);
			source.draw(_multiTouch);
			source.draw(_quitReg);
			source.draw(_instruction);
			break;
		case (5) :
			source.draw(_Menu);
			source.draw(_singlePlayerReg);
			source.draw(_hostReg);
			source.draw(_joinReg);
			source.draw(_multiReg);
			source.draw(_quitReg);
			source.draw(_instructionT);
			break;
		case (6) :
			source.draw(_Menu);
			source.draw(_ofallon);
			source.draw(_singlePlayerReg);
			source.draw(_hostReg);
			source.draw(_joinReg);
			source.draw(_multiReg);
			source.draw(_quitTouch);
			source.draw(_instruction);
			break;
		}
		source.display();
	}
	_selected = i;
	source.clear();
	return _selected;
}

