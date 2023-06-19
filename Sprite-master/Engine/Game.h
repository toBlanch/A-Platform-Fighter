/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.h																				  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "Surface.h"
#include "Character.h"
#include "Move.h"

class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel();
	/********************************/
	/*  User Functions              */
	/********************************/
private:
	MainWindow& wnd;
	Graphics gfx;
	/********************************/
	/*  User Variables              */
	int stageX0 = 500;
	int stageY0 = 700;
	int stageX1 = 1420;
	int stageY1 = 880;
	int leniancy = 0;
	int player1CharacterID = 1;
	int player2CharacterID = 2;
	int previousWinner = 0;
	int timeUntilStart = 0;
	int timeGoIsDisplayed = 0;
	bool startMenu = true;
	bool paused = false;
	bool enterOrEscapeHeld = false;
	bool qHeld = false;
	bool eHeld = false;
	bool iHeld = false;
	bool pHeld = false;
	Surface player1Idle = { "Images\\CircleIdle.bmp" };
	Surface player1Move = { "Images\\CircleIdle.bmp" };
	Surface player2Idle = { "Images\\CircleIdle.bmp" };
	Surface player2Move = { "Images\\CircleIdle.bmp" };
	Surface lightningIdle = { "Images\\LightningIdle.bmp" };
	Surface lightningMove = { "Images\\LightningMove.bmp" };
	Surface circleIdle = { "Images\\CircleIdle.bmp" };
	Surface circleMove = { "Images\\CircleMove.bmp" };
	Surface aIdle = { "Images\\aIdle.bmp" };
	Surface aMove = { "Images\\aMove.bmp" };
	Surface dogIdle = { "Images\\DogIdle.bmp" };
	Surface dogMove = { "Images\\DogMove.bmp" };
	Surface chickenIdle = { "Images\\ChickenIdle.bmp" };
	Surface chickenMove = { "Images\\ChickenMove.bmp" };
	Surface rockIdle = { "Images\\RockIdle.bmp" };
	Surface rockMove = { "Images\\RockMove.bmp" };
	Surface trollIdle = { "Images\\TrollIdle.bmp" };
	Surface trollMove = { "Images\\TrollMove.bmp" };
	Surface bigBIdle = { "Images\\BigBIdle.bmp" };
	Surface bigBMove = { "Images\\BigBMove.bmp" };
	Surface cycling = { "Images\\Cycling.bmp" };
	Surface controls1 = { "Images\\Player1Controls.bmp" };
	Surface controls2 = { "Images\\Player2Controls.bmp" };
	Surface three = {"Images\\Three.bmp"};
	Surface two = { "Images\\Two.bmp" };
	Surface one = { "Images\\One.bmp" };
	Surface go = { "Images\\Go.bmp" };
	Surface pauseMenu = { "Images\\Pause Menu.bmp" };
	Surface player1Win = { "Images\\Player1Win.bmp" };
	Surface player2Win = { "Images\\Player2Win.bmp" };
	Character Player1;
	Character Player2;
	/********************************/
};