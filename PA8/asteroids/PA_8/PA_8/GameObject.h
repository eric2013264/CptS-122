//
// GameObject.h
// ConsoleApplication1
//
// Created by Eliot Ascaso, Eric Chen, and Trevor Mozingo on 11/25/2014
// Copyright (c) 2014 eliotascaso, ericchen, and trevormozingo. All rights reserved.
//

/*
Description >>>
>>> VISIBLE OBJECTS PRESENT IN GAMESCAPE
>>> GAME OBJECT WILL CONTAIN DATA SUCH AS SPAWN LOCATION, CURRENT LOCATION WITHIN GAMESCAPE, AND MOVEMENT APPLICATIONS
*/

#pragma once

#include "Header.h"

class GameObject {
public:

	void GameObjectDisplay(sf::RenderWindow& source);
	virtual void GameObjectRotateLeft();					//OBJECT WILL ROTATE COUNTERCLOCKWISE
	virtual void GameObjectRotateRight();					//OBJECT WILL ROTATE CLOCKWISE
	virtual void GameObjectMove();							//OBJECT WILL TRAVERSE THROUGH SPACE
	float GameObjectGetXCord();								//GET XCOORDINATES OF GAME OBJECT
	float GameObjectGetYCord();								//GET YCORDCOORDINATES OF OBJECT
	float GameObjectGetRot();								//GET ROTATION OF GAME OBJECT

	void GameObjectSetXCord(float source);					//SET X CORD
	void GameObjectSetYCord(float source);					//SET Y CORD
	void GameObjectSetRot(float source);					//SET ROT

	void synchronize(float xCord, float yCord, float rot);	//KEEPS SERVER AND CLIENT OBJECTS IN SYNC

protected:
	float _xCoordinate, _yCoordinate, _rotation;			//THESE ARE THE CORDINATES OF THE CENTROID FOR EACH OBJECT IN THE GAMESPACE
	sf::Texture _texture;									//THIS WILL BE THE OBJECT MESH
	sf::Sprite _sprite;										//THIS WILL CREATE IN WINDOW OBJECT
};


