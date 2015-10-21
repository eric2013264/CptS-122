//
// Asteroid.h
// ConsoleApplication1
//
// Created by Eliot Ascaso, Eric Chen, and Trevor Mozingo on 11/25/2014
// Copyright (c) 2014 eliotascaso, ericchen, and trevormozingo. All rights reserved.
//

/*
Description >>>
>>> ASTEROID CLASS INHERETING FROM GAMEOBJECT
>>> ASTEROID OBJECT WILL SERVE AS ENEMY IN ASTEROIDS GAME
>>> ASTEROIDS WILL SPAWN RANDOMLY IN GAME, MOVE ABOUT, & AND WILL INCREASE SPAWN TIME THROUGHOUT RUNTIME
>>> PAWN CLASS WILL SHOOT AT ASTEROID TO DESTROY IT AN GAIN POINTS
*/

#pragma once

#include "GameObject.h"

class Asteroid : public GameObject {	//ASTEROID IS A GAME OBJECT SO INHERITS FROM GAME OBJECT
public:
	Asteroid();							//ASTEROID CONSTRUCTOR
	~Asteroid();						//ASTEROID DESTRUCTOR
	void GameObjectMove();				//OBJECT WILL TRAVERSE THROUGH SPACE
};
