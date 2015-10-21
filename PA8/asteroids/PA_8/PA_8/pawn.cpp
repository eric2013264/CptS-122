//
// pawn.cpp
// ConsoleApplication1
//
// Created by Eliot Ascaso, Eric Chen, and Trevor Mozingo on 11/25/2014
// Copyright (c) 2014 eliotascaso, ericchen, and trevormozingo. All rights reserved.
//

/*
Description >>>
>>> SEE HEADER FILE
*/

#include "Pawn.h"

Pawn::Pawn() {																			//PAWN CONSTRUCTOR
	_texture.loadFromFile("Pawn.png");													//SET UP PAWN/SPACECHIP IMAGE ***IMAGE CITATION -> []
	_sprite.setTexture(_texture);														//SET IMAGE TO SPRITE
	_t.loadFromFile("thrust.png");
	_thrust.setTexture(_t);
	_thrust.setOrigin(210.0f, 853.0f);
	_thrust.setScale(0.2f, 0.2f);
	_sprite.setScale(0.2f, 0.2f);														//RESIZE
	_xCoordinate = (float)((rand() % 1100) + 100.0f);									//SET RANDOM SPAWN LOCATION FOR SPACESHIP
	_yCoordinate = (float)((rand() % 600) + 100.0f);									//SET RANDOM SPAWN LOCATION FOR SPACESHIP (FOLLOWS SIZE OF SCREEN)
	_rotation = (float)(rand() % 360 + 0.0f);											//SET INITIAL ROTATION ANGLE
	_sprite.setOrigin(196.0f, 169.0f);													//SET TRANSFORMATION ORIGIN TO CENTER OF SPACESHIP (EG ROTATES AROUND CENTER NOT TOP LEFT CORNER OF IMAGE)
	_sprite.setPosition(_xCoordinate, _yCoordinate);									//SPAWN POSITION
	_fireOption = 0;
	_thrust.setPosition(_xCoordinate, _yCoordinate);
	_sprite.rotate(_rotation);															//SPAWN ROTATION ANGLE
	_thrust.rotate(_rotation + 180.0f);
	_gunOption = 0;																		//0 = LEFT GUN 1 = RIGHT GUN. THESE SWITCH WHILE HOLDING SPACEBAR 
	_livesRemaining = 4;
	_points = 0;
}
Pawn::~Pawn() {}																		//DESTRUCTOR

void Pawn::GameObjectMove(sf::RenderWindow& source) {
	_yCoordinate -= (float)(cos(_rotation * PI / 180.0));								//VECTOR ADDITION FOR DIRECTION OF MOVEMENT
	_xCoordinate += (float)(sin(_rotation * PI / 180.0));								//VECTOR ADDITION FOR DIRECTION OF MOVEMENT
	if (_yCoordinate > 750) {															//SCREEN BOUNDARIES
		_yCoordinate = 0.0f;															//PORTAL TO OPOSITE SIDE OF WINDOW TO KEEP SPACESHIP IN VIEW
	}
	if (_yCoordinate < 0) {																//SCREEN BOUNDARIES
		_yCoordinate = 750.0f;															//PORTAL TO OPOSITE SIDE OF WINDOW TO KEEP SPACESHIP IN VIEW
	}
	if (_xCoordinate > 1250) {															//SCREEN BOUNDARIES
		_xCoordinate = 0.0f;															//PORTAL TO OPOSITE SIDE OF WINDOW TO KEEP SPACESHIP IN VIEW
	}
	if (_xCoordinate < 0) {																//SCREEN BOUNDARIES
		_xCoordinate = 1250.0f;															//PORTAL TO OPOSITE SIDE OF WINDOW TO KEEP SPACESHIP IN VIEW
	}

	if (_fireOption == 0) {
		_thrust.setScale(0.2f, 0.2f);
		_fireOption = 1;
	}
	else {
		_thrust.setScale(0.2f, 0.21f);
		_fireOption = 0;
		
	}





	_sprite.setPosition(_xCoordinate, _yCoordinate);									//SET NEW POSITION
	_thrust.setPosition(_xCoordinate, _yCoordinate);
	source.draw(_thrust);
}

void Pawn::GameObjectRotateLeft() {														//ROTATE OBJECT TO THE LEFT WHEN LEFT BUTTON HELD
	_rotation--;
	_sprite.rotate(-1.0f);
	_thrust.rotate(-1.0f);
}

void Pawn::GameObjectRotateRight() {													//ROTATE OBJECT TO THE RIGHT
	_rotation++;
	_sprite.rotate(1.0f);
	_thrust.rotate(1.0f);
}

void Pawn::PawnShoot(std::vector<Projectile> &_bullets, Projectile &_bullet) {
	if (_gunOption == 0) {
		_bullets.push_back(_bullet);													//PUT BULLET INTO VECTOR
		_gunOption = 1;																	//SWITCH TO RIGHT GUN FOR NEXT SHOT
	}
	else {
		_bullets.push_back(_bullet);													//PUT BULLET INTO VECTOR
		_gunOption = 0;																	//SWITCH TO RIGHT GUN FOR NEXT SHOT
	}
}

void Pawn::PawnShootDisplay(sf::RenderWindow& source, std::vector<Projectile> &_bullets) {
	for (int i = 0; (float)i < _bullets.size(); i++) {									//LOOPS THROUGH THE VECTOR ARRAY TO DISPLAY ALL THE BULLETS
		_bullets[i].GameObjectMove();													//FOR THE BULLETS IN VECTOR ARRAY, MOVE THEM
		_bullets[i].GameObjectDisplay(source);											//DISPLAY THE BULLSTS
		if (_bullets[i].GameObjectGetXCord() > 1250 || _bullets[i].GameObjectGetXCord() < -50 || _bullets[i].GameObjectGetYCord() > 750 || _bullets[i].GameObjectGetYCord() < -50) {
			_bullets.erase(_bullets.begin() + i);										//http://stackoverflow.com/questions/4442477/remove-ith-item-from-c-stdvector
		}																				//IF BULLETS GO OUT OF SCOPE DELETE THE FROM VECTOR AND DEALOCATE THEM FROM MEMORY
	}
}

int Pawn::GetGunOption() {																//LEFT AND RIGHT GUNS SWITCH THROUGHT RUN TIME WHILE HOLDING SHOOT BUTTON
	return _gunOption;
}

void Pawn::PawnDied() {
	_livesRemaining--;
}

void Pawn::AddPoint() {
	_points++;

	std::cout << _points << std::endl;
	
}

int Pawn::GetLives() {
	return _livesRemaining;
}

int Pawn::GetPoints() {
	return _points;
}

