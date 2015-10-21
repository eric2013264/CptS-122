//
// asteroid.cpp
// ConsoleApplication1
//
// Created by Eliot Ascaso, Eric Chen, and Trevor Mozingo on 11/25/2014
// Copyright (c) 2014 eliotascaso, ericchen, and trevormozingo. All rights reserved.
//

/*
Description >>>
>>> SEE HEADER FILE
*/

#include "Asteroid.h"

Asteroid::Asteroid() {
	_texture.loadFromFile("Asteroid.png");							//LOAD IMAGE
	_sprite.setTexture(_texture);									//SET IMAGE TO SPRITE
	_sprite.setScale(0.3f, 0.3f);									//SET SPRITE SIZE
	_xCoordinate =  (float)(rand() % 1100);							//SET RANDOM LOCATION
	_yCoordinate = (float)(rand() % 600);							//SET RANDOM LOCATION
	_rotation = (float)(rand() % 360);								//SET RANDOM ROTATION ANGLE
	_sprite.setOrigin(128.0f, 128.0f);								//MOVE TRANSFORMATION ORGIN
	_sprite.setRotation(_rotation);									//APPLY ROTATION TO ASTEROID
	_sprite.setPosition(_xCoordinate, _yCoordinate);				//APPLY LOCATION TO SPRITE
}

Asteroid::~Asteroid() {}											//DESTRUCTOR

void Asteroid::GameObjectMove() {									//OBJECT WILL TRAVERSE THROUGH SPACE
	_yCoordinate -= 0.25f * (float)(cos(_rotation * PI / 180.0));	//VECTOR ADDITION FOR DIRECTION OF MOVEMENT
	_xCoordinate += 0.25f * (float)(sin(_rotation * PI / 180.0));	//VECTOR ADDITION FOR DIRECTION OF MOVEMENT
	_sprite.setPosition(_xCoordinate, _yCoordinate);				//SET BULLET POSITION
} 