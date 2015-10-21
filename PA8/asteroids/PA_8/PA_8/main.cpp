//
// main.cpp
// ConsoleApplication1
//
// Created by Eliot Ascaso, Eric Chen, and Trevor Mozingo on 11/25/2014
// Copyright (c) 2014 eliotascaso, ericchen, and trevormozingo. All rights reserved.
//

/*
Description >>>
>>> PROGRAM LOOP
*/

#include "Header.h"
#include "GamePlay.h"

int main() {
	srand((unsigned int)time(NULL));
	GamePlay game;
	game.GamePlayExecute();
	return 0;
}