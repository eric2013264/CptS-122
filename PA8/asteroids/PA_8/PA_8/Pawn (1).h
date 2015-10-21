//
// Pawn.h
// ConsoleApplication1
//
// Created by Eliot Ascaso, Eric Chen, and Trevor Mozingo on 11/25/2014
// Copyright (c) 2014 eliotascaso, ericchen, and trevormozingo. All rights reserved.
//

/*
Description >>>
>>> PAWN WILL SERVE AS USER OBJECT 
>>> PAWN WILL HAVE BASIC MOVEMENT FUNCTIONALITY RESULTING FROM KEYBOARD EVENTS
>>> 
*/

#pragma once

#include "Header.h"
#include "GameObject.h"
#include "Projectile.h"

class Pawn : public GameObject {															//PAWN IS A GAMEOJBECT SO INHERITS FROM GAME OBJECT
public:
	Pawn();																					//PAWN CONSTRUCTOR
	~Pawn();																				//PAWN DESTRUCTOR
	void GameObjectRotateLeft();															//OBJECT WILL ROTATE COUNTERCLOCKWISE
	void GameObjectRotateRight();															//OBJECT WILL ROTATE CLOCKWISE
	void GameObjectMove(sf::RenderWindow& source);																	//OBJECT WILL TRAVERSE THROUGH SPACE
	

	int GetGunOption();																		//LEFT OR RIGHT GUN?
	void PawnShoot(std::vector<Projectile> &_bullets, Projectile &_bullet);					//SHOOT PROJECTILES
	void PawnShootDisplay(sf::RenderWindow& source, std::vector<Projectile> &_bullets);		//DISPLAY ALL SHOT BULLETS

	void PawnDied();
	void AddPoint();
	int GetLives();
	int GetPoints();

private:
	int _points, _livesRemaining, _gunOption, _fireOption;									//POINTS EARNED, LIVES REMAINING FOR PLAYER, LEFT OR RIGHT GUN
	sf::Sprite _thrust;
	sf::Texture _t;
};