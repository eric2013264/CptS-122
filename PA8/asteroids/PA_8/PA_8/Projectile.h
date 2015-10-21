//
// Projectile.h
// ConsoleApplication1
//
// Created by Eliot Ascaso, Eric Chen, and Trevor Mozingo on 11/25/2014
// Copyright (c) 2014 eliotascaso, ericchen, and trevormozingo. All rights reserved.
//

/*
Description >>>
>>> BULLETS SHOT BY THE PAWN
*/

#pragma once

#include "GameObject.h"

class Projectile : public GameObject {										//BULLET IS A GAMEOBJECT SO INHERITS FROM GAMEOBJECT
public:
	Projectile();															//DEFAULT CONSTRUCTOR
	Projectile::Projectile(float xPos, float yPos, float side, float rot);	//CONSTRUCTOR
	~Projectile();															//DESTRUCTOR
	void GameObjectMove();													//OBJECT WILL TRAVERSE THROUGH SPACE
};


