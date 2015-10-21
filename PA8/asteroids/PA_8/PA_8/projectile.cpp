//
// projectile.cpp
// ConsoleApplication1
//
// Created by Eliot Ascaso, Eric Chen, and Trevor Mozingo on 11/25/2014
// Copyright (c) 2014 eliotascaso, ericchen, and trevormozingo. All rights reserved.
//

/*
Description >>>
>>> SEE HEADER
*/

#include "Projectile.h"

Projectile::Projectile() {}											//DEFAULT CONSTRUCTOR

Projectile::~Projectile() {}										//DESTRUCTOR

Projectile::Projectile(float xPos, float yPos, float side, float rot) {
	_texture.loadFromFile("Projectile.png");						//LAZER BULLET IMAGE
	_sprite.setTexture(_texture);									//SET TEXTURE TO _SPRITE
	_sprite.setScale(1.0f, 0.5f);									//SET SIZE OF IMAGE
	_xCoordinate = xPos;											//REFERENCE POSITION OF SPACESHIP
	_yCoordinate = yPos;											//REFERENCE POSITION OF SPACESHIP
	_rotation = rot;												//REFERENCE ROTATION ANGLE OF SPACESHIP
	if (side == 0) {												//LEFT WEAPON
		_sprite.setOrigin(42.0f, 99.0f);							//SET ORGIN OF LAZER ROTATION (RESPECT TO SHIP CENTROID) FOR LEFT WEAPON
	}
	else {
		_sprite.setOrigin(21.0f, 99.0f);							//SET ORGIN OF LAZER ROTATION (RESPECT TO SHIP CENTROID) FOR RIGHT WEAPON
	}																//X=42 Y=99 LEFT & X=21 Y=99 RIGHT
	_sprite.setPosition(_xCoordinate, _yCoordinate);				//SET LAZER POSITIONS WITH RESPECT TO SPACE SHIP
	_sprite.rotate(_rotation);										//ROTATION ANGLE OF BULLETS IS THE SAME AS ROTATION ANGLE OF SHIP
}

void Projectile::GameObjectMove() {									//OBJECT WILL TRAVERSE THROUGH SPACE
	_yCoordinate -= 3.0f * (float)(cos(_rotation * PI / 180.0));	//VECTOR ADDITION FOR DIRECTION OF MOVEMENT
	_xCoordinate += 3.0f * (float)(sin(_rotation * PI / 180.0));	//VECTOR ADDITION FOR DIRECTION OF MOVEMENT
	_sprite.setPosition(_xCoordinate, _yCoordinate);				//SET BULLET POSITION
}
