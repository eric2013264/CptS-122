//
// gameObject.cpp
// ConsoleApplication1
//
// Created by Eliot Ascaso, Eric Chen, and Trevor Mozingo on 11/25/2014
// Copyright (c) 2014 eliotascaso, ericchen, and trevormozingo. All rights reserved.
//

/*
Description >>>
>>> SEE HEADER FILE
*/

#include "GameObject.h"

void GameObject::GameObjectDisplay(sf::RenderWindow& source) {	//DRAW SPRITE
	source.draw(_sprite);
}

float GameObject::GameObjectGetRot() {							//RETURN ROTATION ANGLE
	return _rotation;
}

float GameObject::GameObjectGetXCord() {						//RETURN XCOORDINATE
	return _xCoordinate;
}

float GameObject::GameObjectGetYCord() {						//RETURN YCOORDINATE
	return _yCoordinate;
}

void GameObject::GameObjectRotateLeft() {}						//OBJECT WILL ROTATE COUNTERCLOCKWISE
void GameObject::GameObjectRotateRight() {}						//OBJECT WILL ROTATE CLOCKWISE
void GameObject::GameObjectMove() {}							//OBJECT WILL TRAVERSE THROUGH SPACE

void GameObject::synchronize(float xCord, float yCord, float rot) { //KEEPS SERVER AND CLIENT GAMES IN SYNC
	_sprite.setPosition(xCord, yCord);
	_sprite.rotate(rot);
}

void GameObject::GameObjectSetXCord(float source) {
	_xCoordinate = source;
	_sprite.setPosition(_xCoordinate, _yCoordinate);
}

void GameObject::GameObjectSetYCord(float source) {
	_yCoordinate = source;
	_sprite.setPosition(_xCoordinate, _yCoordinate);
}

void GameObject::GameObjectSetRot(float source) {
	_rotation = source;
	_sprite.setRotation(_rotation);
}