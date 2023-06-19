/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
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
#include "MainWindow.h"
#include "Game.h"
#include <random>
#include "SpriteEffect.h"

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd)
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	if (startMenu) {
		if (wnd.kbd.KeyIsPressed(0x45) && player1CharacterID < 6 && !eHeld) {
			player1CharacterID++;
		}
		if (wnd.kbd.KeyIsPressed(0x51) && player1CharacterID > 1 && !qHeld) {
			player1CharacterID--;
		}
		if (wnd.kbd.KeyIsPressed(0x50) && player2CharacterID < 6 && !pHeld) {
			player2CharacterID++;
		}
		if (wnd.kbd.KeyIsPressed(0x49) && player2CharacterID > 1 && !iHeld) {
			player2CharacterID--;
		}

		qHeld = wnd.kbd.KeyIsPressed(0x51);
		eHeld = wnd.kbd.KeyIsPressed(0x45);
		iHeld = wnd.kbd.KeyIsPressed(0x49);
		pHeld = wnd.kbd.KeyIsPressed(0x50);

		if (wnd.kbd.KeyIsPressed(VK_RETURN) || wnd.kbd.KeyIsPressed(VK_ESCAPE)) {
			startMenu = false;
			if (player1CharacterID == 1) {
				player1Idle = circleIdle;
				player1Move = circleMove;
				Player1.Initialise(
					gfx.ScreenWidth / 4, //x
					100, //y
					3, //Lives
					100, //Width
					100, //Height
					10, //WalkSpeed
					10, //AerialSpeed
					1, //AerialAcceleration
					1, //WalkAcceleration
					20, //GronudedJumpHeight
					25, //AerialJumpHeight
					1, //FallAcceleration
					10, //FallSpeed
					1, //Weight
					2, //DoubleJumps

					50, //Forward Light Additional x
					0, //Forward Light Additional y
					50, //Forward Light Width
					10, //Forward Light Height
					40, //Forward Light Stun Duration
					5, //Forward Light Scalar X
					-5, //Forward Light Scalar y
					3, //Forward Light Fixed x
					-3, //Forward Light Fixed y
					0, //Forward Light vx
					0, //Forward Light vy
					10, //Forward Light Damage
					10, //Forward Light Start Up Duraiton
					30, //Forward Light Active Duration
					10, //Forward Light End Lag Duration
					true, //Forward Light Is Attached To Player
					false, //Forward Light Dissapear On Hit

					0, //Up Light Additional x
					-10, //Up Light Additional y
					50, //Up Light Width
					10, //Up Light Height
					40, //Up Light Stun Duration
					5, //Up Light Scalar X
					-5, //Up Light Scalar y
					3, //Up Light Fixed x
					-3, //Up Light Fixed y
					0, //Up Light vx
					0, //Up Light vy
					10, //Up Light Damage
					10, //Up Light Start Up Duraiton
					30, //Up Light Active Duration
					10, //Up Light End Lag Duration
					true, //Up Light Is Attached To Player
					false, //Up Light Dissapear On Hit

					0, //Down Light Additional x
					-10, //Down Light Additional y
					50, //Down Light Width
					10, //Down Light Height
					40, //Down Light Stun Duration
					5, //Down Light Scalar X
					-5, //Down Light Scalar y
					3, //Down Light Fixed x
					-3, //Down Light Fixed y
					0, //Down Light vx
					0, //Down Light vy
					10, //Down Light Damage
					10, //Down Light Start Up Duraiton
					30, //Down Light Active Duration
					10, //Down Light End Lag Duration
					true, //Down Light Is Attached To Player
					false, //Down Light Dissapear On Hit

					50, //Forward Heavy Additional x
					50, //Forward Heavy Additional y
					120, //Forward Heavy Width
					50, //Forward Heavy Height
					40, //Forward Heavy Stun Duration
					20, //Forward Heavy Scalar X
					-5, //Forward Heavy Scalar y
					5, //Forward Heavy Fixed x
					-5, //Forward Heavy Fixed y
					0, //Forward Heavy vx
					0, //Forward Heavy vy
					20, //Forward Heavy Damage
					30, //Forward Heavy Start Up Duraiton
					20, //Forward Heavy Active Duration
					60, //Forward Heavy End Lag Duration
					true, //Forward Heavy Is Attached To Player
					false, //Forward Heavy Dissapear On Hit

					50, //Up Heavy Additional x
					50, //Up Heavy Additional y
					120, //Up Heavy Width
					50, //Up Heavy Height
					40, //Up Heavy Stun Duration
					20, //Up Heavy Scalar X
					-5, //Up Heavy Scalar y
					5, //Up Heavy Fixed x
					-5, //Up Heavy Fixed y
					0, //Up Heavy vx
					0, //Up Heavy vy
					20, //Up Heavy Damage
					30, //Up Heavy Start Up Duraiton
					20, //Up Heavy Active Duration
					60, //Up Heavy End Lag Duration
					true, //Up Heavy Is Attached To Player
					false, //Up Heavy Dissapear On Hit

					50, //Down Heavy Additional x
					50, //Down Heavy Additional y
					120, //Down Heavy Width
					50, //Down Heavy Height
					40, //Down Heavy Stun Duration
					20, //Down Heavy Scalar X
					-5, //Down Heavy Scalar y
					5, //Down Heavy Fixed x
					-5, //Down Heavy Fixed y
					0, //Down Heavy vx
					0, //Down Heavy vy
					20, //Down Heavy Damage
					30, //Down Heavy Start Up Duraiton
					20, //Down Heavy Active Duration
					60, //Down Heavy End Lag Duration
					true, //Down Heavy Is Attached To Player
					false, //Down Heavy Dissapear On Hit

					50, //Forward Aerial Additional x
					0, //Forward Aerial Additional y
					50, //Forward Aerial Width
					10, //Forward Aerial Height
					40, //Forward Aerial Stun Duration
					5, //Forward Aerial Scalar X
					-5, //Forward Aerial Scalar y
					3, //Forward Aerial Fixed x
					-3, //Forward Aerial Fixed y
					0, //Forward Aerial vx
					0, //Forward Aerial vy
					10, //Forward Aerial Damage
					10, //Forward Aerial Start Up Duraiton
					30, //Forward Aerial Active Duration
					10, //Forward Aerial End Lag Duration
					true, //Forward Aerial Is Attached To Player
					false, //Forward Aerial Dissapear On Hit

					50, //Back Aerial Additional x
					0, //Back Aerial Additional y
					50, //Back Aerial Width
					10, //Back Aerial Height
					40, //Back Aerial Stun Duration
					5, //Back Aerial Scalar X
					-5, //Back Aerial Scalar y
					3, //Back Aerial Fixed x
					-3, //Back Aerial Fixed y
					0, //Back Aerial vx
					0, //Back Aerial vy
					10, //Back Aerial Damage
					10, //Back Aerial Start Up Duraiton
					30, //Back Aerial Active Duration
					10, //Back Aerial End Lag Duration
					true, //Back Aerial Is Attached To Player
					false, //Back Aerial Dissapear On Hit

					50, //Up Aerial Additional x
					0, //Up Aerial Additional y
					50, //Up Aerial Width
					10, //Up Aerial Height
					40, //Up Aerial Stun Duration
					5, //Up Aerial Scalar X
					-5, //Up Aerial Scalar y
					3, //Up Aerial Fixed x
					-3, //Up Aerial Fixed y
					0, //Up Aerial vx
					0, //Up Aerial vy
					10, //Up Aerial Damage
					10, //Up Aerial Start Up Duraiton
					30, //Up Aerial Active Duration
					10, //Up Aerial End Lag Duration
					true, //Up Aerial Is Attached To Player
					false, //Up Aerial Dissapear On Hit

					50, //Down Aerial Additional x
					0, //Down Aerial Additional y
					50, //Down Aerial Width
					10, //Down Aerial Height
					40, //Down Aerial Stun Duration
					5, //Down Aerial Scalar X
					-5, //Down Aerial Scalar y
					3, //Down Aerial Fixed x
					-3, //Down Aerial Fixed y
					0, //Down Aerial vx
					0, //Down Aerial vy
					10, //Down Aerial Damage
					10, //Down Aerial Start Up Duraiton
					30, //Down Aerial Active Duration
					10, //Down Aerial End Lag Duration
					true, //Down Aerial Is Attached To Player
					false, //Down Aerial Dissapear On Hit

					100, //Forward Special Additional x
					0, //Forward Special Additional y
					50, //Forward Special Width
					10, //Forward Special Height
					20, //Forward Special Stun Duration
					15, //Forward Special Scalar X
					-1, //Forward Special Scalar y
					3, //Forward Special Fixed x
					-3, //Forward Special Fixed y
					2, //Forward Special vx
					0.5, //Forward Special vy
					5, //Forward Special Damage
					10, //Forward Special Start Up Duraiton
					300, //Forward Special Active Duration
					50, //Forward Special End Lag Duration
					false, //Forward Special Is Attached To Player
					true, //Forward Special Dissapear On Hit

					100, //Up Special Additional x
					0, //Up Special Additional y
					50, //Up Special Width
					10, //Up Special Height
					20, //Up Special Stun Duration
					15, //Up Special Scalar X
					-1, //Up Special Scalar y
					3, //Up Special Fixed x
					-3, //Up Special Fixed y
					2, //Up Special vx
					0.5, //Up Special vy
					5, //Up Special Damage
					10, //Up Special Start Up Duraiton
					300, //Up Special Active Duration
					50, //Up Special End Lag Duration
					false, //Up Special Is Attached To Player
					true, //Up Special Dissapear On Hit

					100, //Down Special Additional x
					0, //Down Special Additional y
					50, //Down Special Width
					10, //Down Special Height
					20, //Down Special Stun Duration
					15, //Down Special Scalar X
					-1, //Down Special Scalar y
					3, //Down Special Fixed x
					-3, //Down Special Fixed y
					2, //Down Special vx
					0.5, //Down Special vy
					5, //Down Special Damage
					10, //Down Special Start Up Duraiton
					300, //Down Special Active Duration
					50, //Down Special End Lag Duration
					false, //Down Special Is Attached To Player
					true //Down Special Dissapear On Hit
				);
			}
			else if (player1CharacterID == 2) {
				player1Idle = aIdle;
				player1Move = aMove;
				Player1.Initialise(
					gfx.ScreenWidth / 4, //x
					100, //y
					3, //Lives
					100, //Width
					100, //Height
					10, //WalkSpeed
					10, //AerialSpeed
					1, //AerialAcceleration
					1, //WalkAcceleration
					20, //GronudedJumpHeight
					25, //AerialJumpHeight
					1, //FallAcceleration
					10, //FallSpeed
					1, //Weight
					2, //DoubleJumps

					50, //Forward Light Additional x
					0, //Forward Light Additional y
					50, //Forward Light Width
					10, //Forward Light Height
					40, //Forward Light Stun Duration
					5, //Forward Light Scalar X
					-5, //Forward Light Scalar y
					3, //Forward Light Fixed x
					-3, //Forward Light Fixed y
					0, //Forward Light vx
					0, //Forward Light vy
					10, //Forward Light Damage
					10, //Forward Light Start Up Duraiton
					30, //Forward Light Active Duration
					10, //Forward Light End Lag Duration
					true, //Forward Light Is Attached To Player
					false, //Forward Light Dissapear On Hit

					50, //Up Light Additional x
					0, //Up Light Additional y
					50, //Up Light Width
					10, //Up Light Height
					40, //Up Light Stun Duration
					5, //Up Light Scalar X
					-5, //Up Light Scalar y
					3, //Up Light Fixed x
					-3, //Up Light Fixed y
					0, //Up Light vx
					0, //Up Light vy
					10, //Up Light Damage
					10, //Up Light Start Up Duraiton
					30, //Up Light Active Duration
					10, //Up Light End Lag Duration
					true, //Up Light Is Attached To Player
					false, //Up Light Dissapear On Hit

					50, //Down Light Additional x
					0, //Down Light Additional y
					50, //Down Light Width
					10, //Down Light Height
					40, //Down Light Stun Duration
					5, //Down Light Scalar X
					-5, //Down Light Scalar y
					3, //Down Light Fixed x
					-3, //Down Light Fixed y
					0, //Down Light vx
					0, //Down Light vy
					10, //Down Light Damage
					10, //Down Light Start Up Duraiton
					30, //Down Light Active Duration
					10, //Down Light End Lag Duration
					true, //Down Light Is Attached To Player
					false, //Down Light Dissapear On Hit

					50, //Forward Heavy Additional x
					50, //Forward Heavy Additional y
					120, //Forward Heavy Width
					50, //Forward Heavy Height
					40, //Forward Heavy Stun Duration
					20, //Forward Heavy Scalar X
					-5, //Forward Heavy Scalar y
					5, //Forward Heavy Fixed x
					-5, //Forward Heavy Fixed y
					0, //Forward Heavy vx
					0, //Forward Heavy vy
					20, //Forward Heavy Damage
					30, //Forward Heavy Start Up Duraiton
					20, //Forward Heavy Active Duration
					60, //Forward Heavy End Lag Duration
					true, //Forward Heavy Is Attached To Player
					false, //Forward Heavy Dissapear On Hit

					50, //Up Heavy Additional x
					50, //Up Heavy Additional y
					120, //Up Heavy Width
					50, //Up Heavy Height
					40, //Up Heavy Stun Duration
					20, //Up Heavy Scalar X
					-5, //Up Heavy Scalar y
					5, //Up Heavy Fixed x
					-5, //Up Heavy Fixed y
					0, //Up Heavy vx
					0, //Up Heavy vy
					20, //Up Heavy Damage
					30, //Up Heavy Start Up Duraiton
					20, //Up Heavy Active Duration
					60, //Up Heavy End Lag Duration
					true, //Up Heavy Is Attached To Player
					false, //Up Heavy Dissapear On Hit

					50, //Down Heavy Additional x
					50, //Down Heavy Additional y
					120, //Down Heavy Width
					50, //Down Heavy Height
					40, //Down Heavy Stun Duration
					20, //Down Heavy Scalar X
					-5, //Down Heavy Scalar y
					5, //Down Heavy Fixed x
					-5, //Down Heavy Fixed y
					0, //Down Heavy vx
					0, //Down Heavy vy
					20, //Down Heavy Damage
					30, //Down Heavy Start Up Duraiton
					20, //Down Heavy Active Duration
					60, //Down Heavy End Lag Duration
					true, //Down Heavy Is Attached To Player
					false, //Down Heavy Dissapear On Hit

					50, //Forward Aerial Additional x
					0, //Forward Aerial Additional y
					50, //Forward Aerial Width
					10, //Forward Aerial Height
					40, //Forward Aerial Stun Duration
					5, //Forward Aerial Scalar X
					-5, //Forward Aerial Scalar y
					3, //Forward Aerial Fixed x
					-3, //Forward Aerial Fixed y
					0, //Forward Aerial vx
					0, //Forward Aerial vy
					10, //Forward Aerial Damage
					10, //Forward Aerial Start Up Duraiton
					30, //Forward Aerial Active Duration
					10, //Forward Aerial End Lag Duration
					true, //Forward Aerial Is Attached To Player
					false, //Forward Aerial Dissapear On Hit

					50, //Back Aerial Additional x
					0, //Back Aerial Additional y
					50, //Back Aerial Width
					10, //Back Aerial Height
					40, //Back Aerial Stun Duration
					5, //Back Aerial Scalar X
					-5, //Back Aerial Scalar y
					3, //Back Aerial Fixed x
					-3, //Back Aerial Fixed y
					0, //Back Aerial vx
					0, //Back Aerial vy
					10, //Back Aerial Damage
					10, //Back Aerial Start Up Duraiton
					30, //Back Aerial Active Duration
					10, //Back Aerial End Lag Duration
					true, //Back Aerial Is Attached To Player
					false, //Back Aerial Dissapear On Hit

					50, //Up Aerial Additional x
					0, //Up Aerial Additional y
					50, //Up Aerial Width
					10, //Up Aerial Height
					40, //Up Aerial Stun Duration
					5, //Up Aerial Scalar X
					-5, //Up Aerial Scalar y
					3, //Up Aerial Fixed x
					-3, //Up Aerial Fixed y
					0, //Up Aerial vx
					0, //Up Aerial vy
					10, //Up Aerial Damage
					10, //Up Aerial Start Up Duraiton
					30, //Up Aerial Active Duration
					10, //Up Aerial End Lag Duration
					true, //Up Aerial Is Attached To Player
					false, //Up Aerial Dissapear On Hit

					50, //Down Aerial Additional x
					0, //Down Aerial Additional y
					50, //Down Aerial Width
					10, //Down Aerial Height
					40, //Down Aerial Stun Duration
					5, //Down Aerial Scalar X
					-5, //Down Aerial Scalar y
					3, //Down Aerial Fixed x
					-3, //Down Aerial Fixed y
					0, //Down Aerial vx
					0, //Down Aerial vy
					10, //Down Aerial Damage
					10, //Down Aerial Start Up Duraiton
					30, //Down Aerial Active Duration
					10, //Down Aerial End Lag Duration
					true, //Down Aerial Is Attached To Player
					false, //Down Aerial Dissapear On Hit

					100, //Forward Special Additional x
					0, //Forward Special Additional y
					50, //Forward Special Width
					10, //Forward Special Height
					20, //Forward Special Stun Duration
					15, //Forward Special Scalar X
					-1, //Forward Special Scalar y
					3, //Forward Special Fixed x
					-3, //Forward Special Fixed y
					2, //Forward Special vx
					0.5, //Forward Special vy
					5, //Forward Special Damage
					10, //Forward Special Start Up Duraiton
					300, //Forward Special Active Duration
					50, //Forward Special End Lag Duration
					false, //Forward Special Is Attached To Player
					true, //Forward Special Dissapear On Hit

					100, //Up Special Additional x
					0, //Up Special Additional y
					50, //Up Special Width
					10, //Up Special Height
					20, //Up Special Stun Duration
					15, //Up Special Scalar X
					-1, //Up Special Scalar y
					3, //Up Special Fixed x
					-3, //Up Special Fixed y
					2, //Up Special vx
					0.5, //Up Special vy
					5, //Up Special Damage
					10, //Up Special Start Up Duraiton
					300, //Up Special Active Duration
					50, //Up Special End Lag Duration
					false, //Up Special Is Attached To Player
					true, //Up Special Dissapear On Hit

					100, //Down Special Additional x
					0, //Down Special Additional y
					50, //Down Special Width
					10, //Down Special Height
					20, //Down Special Stun Duration
					15, //Down Special Scalar X
					-1, //Down Special Scalar y
					3, //Down Special Fixed x
					-3, //Down Special Fixed y
					2, //Down Special vx
					0.5, //Down Special vy
					5, //Down Special Damage
					10, //Down Special Start Up Duraiton
					300, //Down Special Active Duration
					50, //Down Special End Lag Duration
					false, //Down Special Is Attached To Player
					true //Down Special Dissapear On Hit
				);
			}
			else if (player1CharacterID == 3) {
				player1Idle = lightningIdle;
				player1Move = lightningMove;
				Player1.Initialise(
					gfx.ScreenWidth / 4, //x
					100, //y
					3, //Lives
					60, //Width
					200, //Height
					10, //WalkSpeed
					10, //AerialSpeed
					1, //AerialAcceleration
					1, //WalkAcceleration
					20, //GronudedJumpHeight
					25, //AerialJumpHeight
					1, //FallAcceleration
					10, //FallSpeed
					1, //Weight
					2, //DoubleJumps

					50, //Forward Light Additional x
					0, //Forward Light Additional y
					50, //Forward Light Width
					10, //Forward Light Height
					40, //Forward Light Stun Duration
					5, //Forward Light Scalar X
					-5, //Forward Light Scalar y
					3, //Forward Light Fixed x
					-3, //Forward Light Fixed y
					0, //Forward Light vx
					0, //Forward Light vy
					10, //Forward Light Damage
					10, //Forward Light Start Up Duraiton
					30, //Forward Light Active Duration
					10, //Forward Light End Lag Duration
					true, //Forward Light Is Attached To Player
					false, //Forward Light Dissapear On Hit

					50, //Up Light Additional x
					0, //Up Light Additional y
					50, //Up Light Width
					10, //Up Light Height
					40, //Up Light Stun Duration
					5, //Up Light Scalar X
					-5, //Up Light Scalar y
					3, //Up Light Fixed x
					-3, //Up Light Fixed y
					0, //Up Light vx
					0, //Up Light vy
					10, //Up Light Damage
					10, //Up Light Start Up Duraiton
					30, //Up Light Active Duration
					10, //Up Light End Lag Duration
					true, //Up Light Is Attached To Player
					false, //Up Light Dissapear On Hit

					50, //Down Light Additional x
					0, //Down Light Additional y
					50, //Down Light Width
					10, //Down Light Height
					40, //Down Light Stun Duration
					5, //Down Light Scalar X
					-5, //Down Light Scalar y
					3, //Down Light Fixed x
					-3, //Down Light Fixed y
					0, //Down Light vx
					0, //Down Light vy
					10, //Down Light Damage
					10, //Down Light Start Up Duraiton
					30, //Down Light Active Duration
					10, //Down Light End Lag Duration
					true, //Down Light Is Attached To Player
					false, //Down Light Dissapear On Hit

					50, //Forward Heavy Additional x
					50, //Forward Heavy Additional y
					120, //Forward Heavy Width
					50, //Forward Heavy Height
					40, //Forward Heavy Stun Duration
					20, //Forward Heavy Scalar X
					-5, //Forward Heavy Scalar y
					5, //Forward Heavy Fixed x
					-5, //Forward Heavy Fixed y
					0, //Forward Heavy vx
					0, //Forward Heavy vy
					20, //Forward Heavy Damage
					30, //Forward Heavy Start Up Duraiton
					20, //Forward Heavy Active Duration
					60, //Forward Heavy End Lag Duration
					true, //Forward Heavy Is Attached To Player
					false, //Forward Heavy Dissapear On Hit

					50, //Up Heavy Additional x
					50, //Up Heavy Additional y
					120, //Up Heavy Width
					50, //Up Heavy Height
					40, //Up Heavy Stun Duration
					20, //Up Heavy Scalar X
					-5, //Up Heavy Scalar y
					5, //Up Heavy Fixed x
					-5, //Up Heavy Fixed y
					0, //Up Heavy vx
					0, //Up Heavy vy
					20, //Up Heavy Damage
					30, //Up Heavy Start Up Duraiton
					20, //Up Heavy Active Duration
					60, //Up Heavy End Lag Duration
					true, //Up Heavy Is Attached To Player
					false, //Up Heavy Dissapear On Hit

					50, //Down Heavy Additional x
					50, //Down Heavy Additional y
					120, //Down Heavy Width
					50, //Down Heavy Height
					40, //Down Heavy Stun Duration
					20, //Down Heavy Scalar X
					-5, //Down Heavy Scalar y
					5, //Down Heavy Fixed x
					-5, //Down Heavy Fixed y
					0, //Down Heavy vx
					0, //Down Heavy vy
					20, //Down Heavy Damage
					30, //Down Heavy Start Up Duraiton
					20, //Down Heavy Active Duration
					60, //Down Heavy End Lag Duration
					true, //Down Heavy Is Attached To Player
					false, //Down Heavy Dissapear On Hit

					50, //Forward Aerial Additional x
					0, //Forward Aerial Additional y
					50, //Forward Aerial Width
					10, //Forward Aerial Height
					40, //Forward Aerial Stun Duration
					5, //Forward Aerial Scalar X
					-5, //Forward Aerial Scalar y
					3, //Forward Aerial Fixed x
					-3, //Forward Aerial Fixed y
					0, //Forward Aerial vx
					0, //Forward Aerial vy
					10, //Forward Aerial Damage
					10, //Forward Aerial Start Up Duraiton
					30, //Forward Aerial Active Duration
					10, //Forward Aerial End Lag Duration
					true, //Forward Aerial Is Attached To Player
					false, //Forward Aerial Dissapear On Hit

					50, //Back Aerial Additional x
					0, //Back Aerial Additional y
					50, //Back Aerial Width
					10, //Back Aerial Height
					40, //Back Aerial Stun Duration
					5, //Back Aerial Scalar X
					-5, //Back Aerial Scalar y
					3, //Back Aerial Fixed x
					-3, //Back Aerial Fixed y
					0, //Back Aerial vx
					0, //Back Aerial vy
					10, //Back Aerial Damage
					10, //Back Aerial Start Up Duraiton
					30, //Back Aerial Active Duration
					10, //Back Aerial End Lag Duration
					true, //Back Aerial Is Attached To Player
					false, //Back Aerial Dissapear On Hit

					50, //Up Aerial Additional x
					0, //Up Aerial Additional y
					50, //Up Aerial Width
					10, //Up Aerial Height
					40, //Up Aerial Stun Duration
					5, //Up Aerial Scalar X
					-5, //Up Aerial Scalar y
					3, //Up Aerial Fixed x
					-3, //Up Aerial Fixed y
					0, //Up Aerial vx
					0, //Up Aerial vy
					10, //Up Aerial Damage
					10, //Up Aerial Start Up Duraiton
					30, //Up Aerial Active Duration
					10, //Up Aerial End Lag Duration
					true, //Up Aerial Is Attached To Player
					false, //Up Aerial Dissapear On Hit

					50, //Down Aerial Additional x
					0, //Down Aerial Additional y
					50, //Down Aerial Width
					10, //Down Aerial Height
					40, //Down Aerial Stun Duration
					5, //Down Aerial Scalar X
					-5, //Down Aerial Scalar y
					3, //Down Aerial Fixed x
					-3, //Down Aerial Fixed y
					0, //Down Aerial vx
					0, //Down Aerial vy
					10, //Down Aerial Damage
					10, //Down Aerial Start Up Duraiton
					30, //Down Aerial Active Duration
					10, //Down Aerial End Lag Duration
					true, //Down Aerial Is Attached To Player
					false, //Down Aerial Dissapear On Hit

					100, //Forward Special Additional x
					0, //Forward Special Additional y
					50, //Forward Special Width
					10, //Forward Special Height
					20, //Forward Special Stun Duration
					15, //Forward Special Scalar X
					-1, //Forward Special Scalar y
					3, //Forward Special Fixed x
					-3, //Forward Special Fixed y
					2, //Forward Special vx
					0.5, //Forward Special vy
					5, //Forward Special Damage
					10, //Forward Special Start Up Duraiton
					300, //Forward Special Active Duration
					50, //Forward Special End Lag Duration
					false, //Forward Special Is Attached To Player
					true, //Forward Special Dissapear On Hit

					100, //Up Special Additional x
					0, //Up Special Additional y
					50, //Up Special Width
					10, //Up Special Height
					20, //Up Special Stun Duration
					15, //Up Special Scalar X
					-1, //Up Special Scalar y
					3, //Up Special Fixed x
					-3, //Up Special Fixed y
					2, //Up Special vx
					0.5, //Up Special vy
					5, //Up Special Damage
					10, //Up Special Start Up Duraiton
					300, //Up Special Active Duration
					50, //Up Special End Lag Duration
					false, //Up Special Is Attached To Player
					true, //Up Special Dissapear On Hit

					100, //Down Special Additional x
					0, //Down Special Additional y
					50, //Down Special Width
					10, //Down Special Height
					20, //Down Special Stun Duration
					15, //Down Special Scalar X
					-1, //Down Special Scalar y
					3, //Down Special Fixed x
					-3, //Down Special Fixed y
					2, //Down Special vx
					0.5, //Down Special vy
					5, //Down Special Damage
					10, //Down Special Start Up Duraiton
					300, //Down Special Active Duration
					50, //Down Special End Lag Duration
					false, //Down Special Is Attached To Player
					true //Down Special Dissapear On Hit
				);
			}
			else if (player1CharacterID == 4) {
				player1Idle = dogIdle;
				player1Move = dogMove;
				Player1.Initialise(
					gfx.ScreenWidth / 4, //x
					0, //y
					3, //Lives
					60, //Width
					40, //Height
					10, //WalkSpeed
					10, //AerialSpeed
					1, //AerialAcceleration
					1, //WalkAcceleration
					20, //GronudedJumpHeight
					25, //AerialJumpHeight
					1, //FallAcceleration
					10, //FallSpeed
					1, //Weight
					2, //DoubleJumps

					50, //Forward Light Additional x
					0, //Forward Light Additional y
					50, //Forward Light Width
					10, //Forward Light Height
					40, //Forward Light Stun Duration
					5, //Forward Light Scalar X
					-5, //Forward Light Scalar y
					3, //Forward Light Fixed x
					-3, //Forward Light Fixed y
					0, //Forward Light vx
					0, //Forward Light vy
					10, //Forward Light Damage
					10, //Forward Light Start Up Duraiton
					30, //Forward Light Active Duration
					10, //Forward Light End Lag Duration
					true, //Forward Light Is Attached To Player
					false, //Forward Light Dissapear On Hit

					50, //Up Light Additional x
					0, //Up Light Additional y
					50, //Up Light Width
					10, //Up Light Height
					40, //Up Light Stun Duration
					5, //Up Light Scalar X
					-5, //Up Light Scalar y
					3, //Up Light Fixed x
					-3, //Up Light Fixed y
					0, //Up Light vx
					0, //Up Light vy
					10, //Up Light Damage
					10, //Up Light Start Up Duraiton
					30, //Up Light Active Duration
					10, //Up Light End Lag Duration
					true, //Up Light Is Attached To Player
					false, //Up Light Dissapear On Hit

					50, //Down Light Additional x
					0, //Down Light Additional y
					50, //Down Light Width
					10, //Down Light Height
					40, //Down Light Stun Duration
					5, //Down Light Scalar X
					-5, //Down Light Scalar y
					3, //Down Light Fixed x
					-3, //Down Light Fixed y
					0, //Down Light vx
					0, //Down Light vy
					10, //Down Light Damage
					10, //Down Light Start Up Duraiton
					30, //Down Light Active Duration
					10, //Down Light End Lag Duration
					true, //Down Light Is Attached To Player
					false, //Down Light Dissapear On Hit

					50, //Forward Heavy Additional x
					50, //Forward Heavy Additional y
					120, //Forward Heavy Width
					50, //Forward Heavy Height
					40, //Forward Heavy Stun Duration
					20, //Forward Heavy Scalar X
					-5, //Forward Heavy Scalar y
					5, //Forward Heavy Fixed x
					-5, //Forward Heavy Fixed y
					0, //Forward Heavy vx
					0, //Forward Heavy vy
					20, //Forward Heavy Damage
					30, //Forward Heavy Start Up Duraiton
					20, //Forward Heavy Active Duration
					60, //Forward Heavy End Lag Duration
					true, //Forward Heavy Is Attached To Player
					false, //Forward Heavy Dissapear On Hit

					50, //Up Heavy Additional x
					50, //Up Heavy Additional y
					120, //Up Heavy Width
					50, //Up Heavy Height
					40, //Up Heavy Stun Duration
					20, //Up Heavy Scalar X
					-5, //Up Heavy Scalar y
					5, //Up Heavy Fixed x
					-5, //Up Heavy Fixed y
					0, //Up Heavy vx
					0, //Up Heavy vy
					20, //Up Heavy Damage
					30, //Up Heavy Start Up Duraiton
					20, //Up Heavy Active Duration
					60, //Up Heavy End Lag Duration
					true, //Up Heavy Is Attached To Player
					false, //Up Heavy Dissapear On Hit

					50, //Down Heavy Additional x
					50, //Down Heavy Additional y
					120, //Down Heavy Width
					50, //Down Heavy Height
					40, //Down Heavy Stun Duration
					20, //Down Heavy Scalar X
					-5, //Down Heavy Scalar y
					5, //Down Heavy Fixed x
					-5, //Down Heavy Fixed y
					0, //Down Heavy vx
					0, //Down Heavy vy
					20, //Down Heavy Damage
					30, //Down Heavy Start Up Duraiton
					20, //Down Heavy Active Duration
					60, //Down Heavy End Lag Duration
					true, //Down Heavy Is Attached To Player
					false, //Down Heavy Dissapear On Hit

					50, //Forward Aerial Additional x
					0, //Forward Aerial Additional y
					50, //Forward Aerial Width
					10, //Forward Aerial Height
					40, //Forward Aerial Stun Duration
					5, //Forward Aerial Scalar X
					-5, //Forward Aerial Scalar y
					3, //Forward Aerial Fixed x
					-3, //Forward Aerial Fixed y
					0, //Forward Aerial vx
					0, //Forward Aerial vy
					10, //Forward Aerial Damage
					10, //Forward Aerial Start Up Duraiton
					30, //Forward Aerial Active Duration
					10, //Forward Aerial End Lag Duration
					true, //Forward Aerial Is Attached To Player
					false, //Forward Aerial Dissapear On Hit

					50, //Back Aerial Additional x
					0, //Back Aerial Additional y
					50, //Back Aerial Width
					10, //Back Aerial Height
					40, //Back Aerial Stun Duration
					5, //Back Aerial Scalar X
					-5, //Back Aerial Scalar y
					3, //Back Aerial Fixed x
					-3, //Back Aerial Fixed y
					0, //Back Aerial vx
					0, //Back Aerial vy
					10, //Back Aerial Damage
					10, //Back Aerial Start Up Duraiton
					30, //Back Aerial Active Duration
					10, //Back Aerial End Lag Duration
					true, //Back Aerial Is Attached To Player
					false, //Back Aerial Dissapear On Hit

					50, //Up Aerial Additional x
					0, //Up Aerial Additional y
					50, //Up Aerial Width
					10, //Up Aerial Height
					40, //Up Aerial Stun Duration
					5, //Up Aerial Scalar X
					-5, //Up Aerial Scalar y
					3, //Up Aerial Fixed x
					-3, //Up Aerial Fixed y
					0, //Up Aerial vx
					0, //Up Aerial vy
					10, //Up Aerial Damage
					10, //Up Aerial Start Up Duraiton
					30, //Up Aerial Active Duration
					10, //Up Aerial End Lag Duration
					true, //Up Aerial Is Attached To Player
					false, //Up Aerial Dissapear On Hit

					50, //Down Aerial Additional x
					0, //Down Aerial Additional y
					50, //Down Aerial Width
					10, //Down Aerial Height
					40, //Down Aerial Stun Duration
					5, //Down Aerial Scalar X
					-5, //Down Aerial Scalar y
					3, //Down Aerial Fixed x
					-3, //Down Aerial Fixed y
					0, //Down Aerial vx
					0, //Down Aerial vy
					10, //Down Aerial Damage
					10, //Down Aerial Start Up Duraiton
					30, //Down Aerial Active Duration
					10, //Down Aerial End Lag Duration
					true, //Down Aerial Is Attached To Player
					false, //Down Aerial Dissapear On Hit

					100, //Forward Special Additional x
					0, //Forward Special Additional y
					50, //Forward Special Width
					10, //Forward Special Height
					20, //Forward Special Stun Duration
					15, //Forward Special Scalar X
					-1, //Forward Special Scalar y
					3, //Forward Special Fixed x
					-3, //Forward Special Fixed y
					2, //Forward Special vx
					0.5, //Forward Special vy
					5, //Forward Special Damage
					10, //Forward Special Start Up Duraiton
					300, //Forward Special Active Duration
					50, //Forward Special End Lag Duration
					false, //Forward Special Is Attached To Player
					true, //Forward Special Dissapear On Hit

					100, //Up Special Additional x
					0, //Up Special Additional y
					50, //Up Special Width
					10, //Up Special Height
					20, //Up Special Stun Duration
					15, //Up Special Scalar X
					-1, //Up Special Scalar y
					3, //Up Special Fixed x
					-3, //Up Special Fixed y
					2, //Up Special vx
					0.5, //Up Special vy
					5, //Up Special Damage
					10, //Up Special Start Up Duraiton
					300, //Up Special Active Duration
					50, //Up Special End Lag Duration
					false, //Up Special Is Attached To Player
					true, //Up Special Dissapear On Hit

					100, //Down Special Additional x
					0, //Down Special Additional y
					50, //Down Special Width
					10, //Down Special Height
					20, //Down Special Stun Duration
					15, //Down Special Scalar X
					-1, //Down Special Scalar y
					3, //Down Special Fixed x
					-3, //Down Special Fixed y
					2, //Down Special vx
					0.5, //Down Special vy
					5, //Down Special Damage
					10, //Down Special Start Up Duraiton
					300, //Down Special Active Duration
					50, //Down Special End Lag Duration
					false, //Down Special Is Attached To Player
					true //Down Special Dissapear On Hit
				);
			}
			else if (player1CharacterID == 5) {
				player1Idle = chickenIdle;
				player1Move = chickenMove;
				Player1.Initialise(
					gfx.ScreenWidth / 4, //x
					100, //y
					3, //Lives
					150, //Width
					150, //Height
					10, //WalkSpeed
					10, //AerialSpeed
					1, //AerialAcceleration
					1, //WalkAcceleration
					20, //GronudedJumpHeight
					25, //AerialJumpHeight
					1, //FallAcceleration
					10, //FallSpeed
					1, //Weight
					2, //DoubleJumps

					50, //Forward Light Additional x
					0, //Forward Light Additional y
					50, //Forward Light Width
					10, //Forward Light Height
					40, //Forward Light Stun Duration
					5, //Forward Light Scalar X
					-5, //Forward Light Scalar y
					3, //Forward Light Fixed x
					-3, //Forward Light Fixed y
					0, //Forward Light vx
					0, //Forward Light vy
					10, //Forward Light Damage
					10, //Forward Light Start Up Duraiton
					30, //Forward Light Active Duration
					10, //Forward Light End Lag Duration
					true, //Forward Light Is Attached To Player
					false, //Forward Light Dissapear On Hit

					50, //Up Light Additional x
					0, //Up Light Additional y
					50, //Up Light Width
					10, //Up Light Height
					40, //Up Light Stun Duration
					5, //Up Light Scalar X
					-5, //Up Light Scalar y
					3, //Up Light Fixed x
					-3, //Up Light Fixed y
					0, //Up Light vx
					0, //Up Light vy
					10, //Up Light Damage
					10, //Up Light Start Up Duraiton
					30, //Up Light Active Duration
					10, //Up Light End Lag Duration
					true, //Up Light Is Attached To Player
					false, //Up Light Dissapear On Hit

					50, //Down Light Additional x
					0, //Down Light Additional y
					50, //Down Light Width
					10, //Down Light Height
					40, //Down Light Stun Duration
					5, //Down Light Scalar X
					-5, //Down Light Scalar y
					3, //Down Light Fixed x
					-3, //Down Light Fixed y
					0, //Down Light vx
					0, //Down Light vy
					10, //Down Light Damage
					10, //Down Light Start Up Duraiton
					30, //Down Light Active Duration
					10, //Down Light End Lag Duration
					true, //Down Light Is Attached To Player
					false, //Down Light Dissapear On Hit

					50, //Forward Heavy Additional x
					50, //Forward Heavy Additional y
					120, //Forward Heavy Width
					50, //Forward Heavy Height
					40, //Forward Heavy Stun Duration
					20, //Forward Heavy Scalar X
					-5, //Forward Heavy Scalar y
					5, //Forward Heavy Fixed x
					-5, //Forward Heavy Fixed y
					0, //Forward Heavy vx
					0, //Forward Heavy vy
					20, //Forward Heavy Damage
					30, //Forward Heavy Start Up Duraiton
					20, //Forward Heavy Active Duration
					60, //Forward Heavy End Lag Duration
					true, //Forward Heavy Is Attached To Player
					false, //Forward Heavy Dissapear On Hit

					50, //Up Heavy Additional x
					50, //Up Heavy Additional y
					120, //Up Heavy Width
					50, //Up Heavy Height
					40, //Up Heavy Stun Duration
					20, //Up Heavy Scalar X
					-5, //Up Heavy Scalar y
					5, //Up Heavy Fixed x
					-5, //Up Heavy Fixed y
					0, //Up Heavy vx
					0, //Up Heavy vy
					20, //Up Heavy Damage
					30, //Up Heavy Start Up Duraiton
					20, //Up Heavy Active Duration
					60, //Up Heavy End Lag Duration
					true, //Up Heavy Is Attached To Player
					false, //Up Heavy Dissapear On Hit

					50, //Down Heavy Additional x
					50, //Down Heavy Additional y
					120, //Down Heavy Width
					50, //Down Heavy Height
					40, //Down Heavy Stun Duration
					20, //Down Heavy Scalar X
					-5, //Down Heavy Scalar y
					5, //Down Heavy Fixed x
					-5, //Down Heavy Fixed y
					0, //Down Heavy vx
					0, //Down Heavy vy
					20, //Down Heavy Damage
					30, //Down Heavy Start Up Duraiton
					20, //Down Heavy Active Duration
					60, //Down Heavy End Lag Duration
					true, //Down Heavy Is Attached To Player
					false, //Down Heavy Dissapear On Hit

					50, //Forward Aerial Additional x
					0, //Forward Aerial Additional y
					50, //Forward Aerial Width
					10, //Forward Aerial Height
					40, //Forward Aerial Stun Duration
					5, //Forward Aerial Scalar X
					-5, //Forward Aerial Scalar y
					3, //Forward Aerial Fixed x
					-3, //Forward Aerial Fixed y
					0, //Forward Aerial vx
					0, //Forward Aerial vy
					10, //Forward Aerial Damage
					10, //Forward Aerial Start Up Duraiton
					30, //Forward Aerial Active Duration
					10, //Forward Aerial End Lag Duration
					true, //Forward Aerial Is Attached To Player
					false, //Forward Aerial Dissapear On Hit

					50, //Back Aerial Additional x
					0, //Back Aerial Additional y
					50, //Back Aerial Width
					10, //Back Aerial Height
					40, //Back Aerial Stun Duration
					5, //Back Aerial Scalar X
					-5, //Back Aerial Scalar y
					3, //Back Aerial Fixed x
					-3, //Back Aerial Fixed y
					0, //Back Aerial vx
					0, //Back Aerial vy
					10, //Back Aerial Damage
					10, //Back Aerial Start Up Duraiton
					30, //Back Aerial Active Duration
					10, //Back Aerial End Lag Duration
					true, //Back Aerial Is Attached To Player
					false, //Back Aerial Dissapear On Hit

					50, //Up Aerial Additional x
					0, //Up Aerial Additional y
					50, //Up Aerial Width
					10, //Up Aerial Height
					40, //Up Aerial Stun Duration
					5, //Up Aerial Scalar X
					-5, //Up Aerial Scalar y
					3, //Up Aerial Fixed x
					-3, //Up Aerial Fixed y
					0, //Up Aerial vx
					0, //Up Aerial vy
					10, //Up Aerial Damage
					10, //Up Aerial Start Up Duraiton
					30, //Up Aerial Active Duration
					10, //Up Aerial End Lag Duration
					true, //Up Aerial Is Attached To Player
					false, //Up Aerial Dissapear On Hit

					50, //Down Aerial Additional x
					0, //Down Aerial Additional y
					50, //Down Aerial Width
					10, //Down Aerial Height
					40, //Down Aerial Stun Duration
					5, //Down Aerial Scalar X
					-5, //Down Aerial Scalar y
					3, //Down Aerial Fixed x
					-3, //Down Aerial Fixed y
					0, //Down Aerial vx
					0, //Down Aerial vy
					10, //Down Aerial Damage
					10, //Down Aerial Start Up Duraiton
					30, //Down Aerial Active Duration
					10, //Down Aerial End Lag Duration
					true, //Down Aerial Is Attached To Player
					false, //Down Aerial Dissapear On Hit

					100, //Forward Special Additional x
					0, //Forward Special Additional y
					50, //Forward Special Width
					10, //Forward Special Height
					20, //Forward Special Stun Duration
					15, //Forward Special Scalar X
					-1, //Forward Special Scalar y
					3, //Forward Special Fixed x
					-3, //Forward Special Fixed y
					2, //Forward Special vx
					0.5, //Forward Special vy
					5, //Forward Special Damage
					10, //Forward Special Start Up Duraiton
					300, //Forward Special Active Duration
					50, //Forward Special End Lag Duration
					false, //Forward Special Is Attached To Player
					true, //Forward Special Dissapear On Hit

					100, //Up Special Additional x
					0, //Up Special Additional y
					50, //Up Special Width
					10, //Up Special Height
					20, //Up Special Stun Duration
					15, //Up Special Scalar X
					-1, //Up Special Scalar y
					3, //Up Special Fixed x
					-3, //Up Special Fixed y
					2, //Up Special vx
					0.5, //Up Special vy
					5, //Up Special Damage
					10, //Up Special Start Up Duraiton
					300, //Up Special Active Duration
					50, //Up Special End Lag Duration
					false, //Up Special Is Attached To Player
					true, //Up Special Dissapear On Hit

					100, //Down Special Additional x
					0, //Down Special Additional y
					50, //Down Special Width
					10, //Down Special Height
					20, //Down Special Stun Duration
					15, //Down Special Scalar X
					-1, //Down Special Scalar y
					3, //Down Special Fixed x
					-3, //Down Special Fixed y
					2, //Down Special vx
					0.5, //Down Special vy
					5, //Down Special Damage
					10, //Down Special Start Up Duraiton
					300, //Down Special Active Duration
					50, //Down Special End Lag Duration
					false, //Down Special Is Attached To Player
					true //Down Special Dissapear On Hit
				);
			}
			else if (player1CharacterID == 6) {
				player1Idle = rockIdle;
				player1Move = rockMove;
				Player1.Initialise(
					gfx.ScreenWidth / 4, //x
					100, //y
					3, //Lives
					100, //Width
					100, //Height
					10, //WalkSpeed
					10, //AerialSpeed
					1, //AerialAcceleration
					1, //WalkAcceleration
					20, //GronudedJumpHeight
					25, //AerialJumpHeight
					1, //FallAcceleration
					10, //FallSpeed
					1, //Weight
					2, //DoubleJumps

					50, //Forward Light Additional x
					0, //Forward Light Additional y
					50, //Forward Light Width
					10, //Forward Light Height
					40, //Forward Light Stun Duration
					5, //Forward Light Scalar X
					-5, //Forward Light Scalar y
					3, //Forward Light Fixed x
					-3, //Forward Light Fixed y
					0, //Forward Light vx
					0, //Forward Light vy
					10, //Forward Light Damage
					10, //Forward Light Start Up Duraiton
					30, //Forward Light Active Duration
					10, //Forward Light End Lag Duration
					true, //Forward Light Is Attached To Player
					false, //Forward Light Dissapear On Hit

					50, //Up Light Additional x
					0, //Up Light Additional y
					50, //Up Light Width
					10, //Up Light Height
					40, //Up Light Stun Duration
					5, //Up Light Scalar X
					-5, //Up Light Scalar y
					3, //Up Light Fixed x
					-3, //Up Light Fixed y
					0, //Up Light vx
					0, //Up Light vy
					10, //Up Light Damage
					10, //Up Light Start Up Duraiton
					30, //Up Light Active Duration
					10, //Up Light End Lag Duration
					true, //Up Light Is Attached To Player
					false, //Up Light Dissapear On Hit

					50, //Down Light Additional x
					0, //Down Light Additional y
					50, //Down Light Width
					10, //Down Light Height
					40, //Down Light Stun Duration
					5, //Down Light Scalar X
					-5, //Down Light Scalar y
					3, //Down Light Fixed x
					-3, //Down Light Fixed y
					0, //Down Light vx
					0, //Down Light vy
					10, //Down Light Damage
					10, //Down Light Start Up Duraiton
					30, //Down Light Active Duration
					10, //Down Light End Lag Duration
					true, //Down Light Is Attached To Player
					false, //Down Light Dissapear On Hit

					50, //Forward Heavy Additional x
					50, //Forward Heavy Additional y
					120, //Forward Heavy Width
					50, //Forward Heavy Height
					40, //Forward Heavy Stun Duration
					20, //Forward Heavy Scalar X
					-5, //Forward Heavy Scalar y
					5, //Forward Heavy Fixed x
					-5, //Forward Heavy Fixed y
					0, //Forward Heavy vx
					0, //Forward Heavy vy
					20, //Forward Heavy Damage
					30, //Forward Heavy Start Up Duraiton
					20, //Forward Heavy Active Duration
					60, //Forward Heavy End Lag Duration
					true, //Forward Heavy Is Attached To Player
					false, //Forward Heavy Dissapear On Hit

					50, //Up Heavy Additional x
					50, //Up Heavy Additional y
					120, //Up Heavy Width
					50, //Up Heavy Height
					40, //Up Heavy Stun Duration
					20, //Up Heavy Scalar X
					-5, //Up Heavy Scalar y
					5, //Up Heavy Fixed x
					-5, //Up Heavy Fixed y
					0, //Up Heavy vx
					0, //Up Heavy vy
					20, //Up Heavy Damage
					30, //Up Heavy Start Up Duraiton
					20, //Up Heavy Active Duration
					60, //Up Heavy End Lag Duration
					true, //Up Heavy Is Attached To Player
					false, //Up Heavy Dissapear On Hit

					50, //Down Heavy Additional x
					50, //Down Heavy Additional y
					120, //Down Heavy Width
					50, //Down Heavy Height
					40, //Down Heavy Stun Duration
					20, //Down Heavy Scalar X
					-5, //Down Heavy Scalar y
					5, //Down Heavy Fixed x
					-5, //Down Heavy Fixed y
					0, //Down Heavy vx
					0, //Down Heavy vy
					20, //Down Heavy Damage
					30, //Down Heavy Start Up Duraiton
					20, //Down Heavy Active Duration
					60, //Down Heavy End Lag Duration
					true, //Down Heavy Is Attached To Player
					false, //Down Heavy Dissapear On Hit

					50, //Forward Aerial Additional x
					0, //Forward Aerial Additional y
					50, //Forward Aerial Width
					10, //Forward Aerial Height
					40, //Forward Aerial Stun Duration
					5, //Forward Aerial Scalar X
					-5, //Forward Aerial Scalar y
					3, //Forward Aerial Fixed x
					-3, //Forward Aerial Fixed y
					0, //Forward Aerial vx
					0, //Forward Aerial vy
					10, //Forward Aerial Damage
					10, //Forward Aerial Start Up Duraiton
					30, //Forward Aerial Active Duration
					10, //Forward Aerial End Lag Duration
					true, //Forward Aerial Is Attached To Player
					false, //Forward Aerial Dissapear On Hit

					50, //Back Aerial Additional x
					0, //Back Aerial Additional y
					50, //Back Aerial Width
					10, //Back Aerial Height
					40, //Back Aerial Stun Duration
					5, //Back Aerial Scalar X
					-5, //Back Aerial Scalar y
					3, //Back Aerial Fixed x
					-3, //Back Aerial Fixed y
					0, //Back Aerial vx
					0, //Back Aerial vy
					10, //Back Aerial Damage
					10, //Back Aerial Start Up Duraiton
					30, //Back Aerial Active Duration
					10, //Back Aerial End Lag Duration
					true, //Back Aerial Is Attached To Player
					false, //Back Aerial Dissapear On Hit

					50, //Up Aerial Additional x
					0, //Up Aerial Additional y
					50, //Up Aerial Width
					10, //Up Aerial Height
					40, //Up Aerial Stun Duration
					5, //Up Aerial Scalar X
					-5, //Up Aerial Scalar y
					3, //Up Aerial Fixed x
					-3, //Up Aerial Fixed y
					0, //Up Aerial vx
					0, //Up Aerial vy
					10, //Up Aerial Damage
					10, //Up Aerial Start Up Duraiton
					30, //Up Aerial Active Duration
					10, //Up Aerial End Lag Duration
					true, //Up Aerial Is Attached To Player
					false, //Up Aerial Dissapear On Hit

					50, //Down Aerial Additional x
					0, //Down Aerial Additional y
					50, //Down Aerial Width
					10, //Down Aerial Height
					40, //Down Aerial Stun Duration
					5, //Down Aerial Scalar X
					-5, //Down Aerial Scalar y
					3, //Down Aerial Fixed x
					-3, //Down Aerial Fixed y
					0, //Down Aerial vx
					0, //Down Aerial vy
					10, //Down Aerial Damage
					10, //Down Aerial Start Up Duraiton
					30, //Down Aerial Active Duration
					10, //Down Aerial End Lag Duration
					true, //Down Aerial Is Attached To Player
					false, //Down Aerial Dissapear On Hit

					100, //Forward Special Additional x
					0, //Forward Special Additional y
					50, //Forward Special Width
					10, //Forward Special Height
					20, //Forward Special Stun Duration
					15, //Forward Special Scalar X
					-1, //Forward Special Scalar y
					3, //Forward Special Fixed x
					-3, //Forward Special Fixed y
					2, //Forward Special vx
					0.5, //Forward Special vy
					5, //Forward Special Damage
					10, //Forward Special Start Up Duraiton
					300, //Forward Special Active Duration
					50, //Forward Special End Lag Duration
					false, //Forward Special Is Attached To Player
					true, //Forward Special Dissapear On Hit

					100, //Up Special Additional x
					0, //Up Special Additional y
					50, //Up Special Width
					10, //Up Special Height
					20, //Up Special Stun Duration
					15, //Up Special Scalar X
					-1, //Up Special Scalar y
					3, //Up Special Fixed x
					-3, //Up Special Fixed y
					2, //Up Special vx
					0.5, //Up Special vy
					5, //Up Special Damage
					10, //Up Special Start Up Duraiton
					300, //Up Special Active Duration
					50, //Up Special End Lag Duration
					false, //Up Special Is Attached To Player
					true, //Up Special Dissapear On Hit

					100, //Down Special Additional x
					0, //Down Special Additional y
					50, //Down Special Width
					10, //Down Special Height
					20, //Down Special Stun Duration
					15, //Down Special Scalar X
					-1, //Down Special Scalar y
					3, //Down Special Fixed x
					-3, //Down Special Fixed y
					2, //Down Special vx
					0.5, //Down Special vy
					5, //Down Special Damage
					10, //Down Special Start Up Duraiton
					300, //Down Special Active Duration
					50, //Down Special End Lag Duration
					false, //Down Special Is Attached To Player
					true //Down Special Dissapear On Hit
				);
			}

			if (player2CharacterID == 1) {
				player2Idle = circleIdle;
				player2Move = circleMove;
				Player2.Initialise(
					800, //x
					100, //y
					3, //Lives
					100, //Width
					100, //Height
					10, //WalkSpeed
					10, //AerialSpeed
					1, //AerialAcceleration
					1, //WalkAcceleration
					20, //GronudedJumpHeight
					25, //AerialJumpHeight
					1, //FallAcceleration
					10, //FallSpeed
					1, //Weight
					2, //DoubleJumps

					50, //Forward Light Additional x
					0, //Forward Light Additional y
					50, //Forward Light Width
					10, //Forward Light Height
					40, //Forward Light Stun Duration
					5, //Forward Light Scalar X
					-5, //Forward Light Scalar y
					3, //Forward Light Fixed x
					-3, //Forward Light Fixed y
					0, //Forward Light vx
					0, //Forward Light vy
					10, //Forward Light Damage
					10, //Forward Light Start Up Duraiton
					30, //Forward Light Active Duration
					10, //Forward Light End Lag Duration
					true, //Forward Light Is Attached To Player
					false, //Forward Light Dissapear On Hit

					50, //Up Light Additional x
					0, //Up Light Additional y
					50, //Up Light Width
					10, //Up Light Height
					40, //Up Light Stun Duration
					5, //Up Light Scalar X
					-5, //Up Light Scalar y
					3, //Up Light Fixed x
					-3, //Up Light Fixed y
					0, //Up Light vx
					0, //Up Light vy
					10, //Up Light Damage
					10, //Up Light Start Up Duraiton
					30, //Up Light Active Duration
					10, //Up Light End Lag Duration
					true, //Up Light Is Attached To Player
					false, //Up Light Dissapear On Hit

					50, //Down Light Additional x
					0, //Down Light Additional y
					50, //Down Light Width
					10, //Down Light Height
					40, //Down Light Stun Duration
					5, //Down Light Scalar X
					-5, //Down Light Scalar y
					3, //Down Light Fixed x
					-3, //Down Light Fixed y
					0, //Down Light vx
					0, //Down Light vy
					10, //Down Light Damage
					10, //Down Light Start Up Duraiton
					30, //Down Light Active Duration
					10, //Down Light End Lag Duration
					true, //Down Light Is Attached To Player
					false, //Down Light Dissapear On Hit

					50, //Forward Heavy Additional x
					50, //Forward Heavy Additional y
					120, //Forward Heavy Width
					50, //Forward Heavy Height
					40, //Forward Heavy Stun Duration
					20, //Forward Heavy Scalar X
					-5, //Forward Heavy Scalar y
					5, //Forward Heavy Fixed x
					-5, //Forward Heavy Fixed y
					0, //Forward Heavy vx
					0, //Forward Heavy vy
					20, //Forward Heavy Damage
					30, //Forward Heavy Start Up Duraiton
					20, //Forward Heavy Active Duration
					60, //Forward Heavy End Lag Duration
					true, //Forward Heavy Is Attached To Player
					false, //Forward Heavy Dissapear On Hit

					50, //Up Heavy Additional x
					50, //Up Heavy Additional y
					120, //Up Heavy Width
					50, //Up Heavy Height
					40, //Up Heavy Stun Duration
					20, //Up Heavy Scalar X
					-5, //Up Heavy Scalar y
					5, //Up Heavy Fixed x
					-5, //Up Heavy Fixed y
					0, //Up Heavy vx
					0, //Up Heavy vy
					20, //Up Heavy Damage
					30, //Up Heavy Start Up Duraiton
					20, //Up Heavy Active Duration
					60, //Up Heavy End Lag Duration
					true, //Up Heavy Is Attached To Player
					false, //Up Heavy Dissapear On Hit

					50, //Down Heavy Additional x
					50, //Down Heavy Additional y
					120, //Down Heavy Width
					50, //Down Heavy Height
					40, //Down Heavy Stun Duration
					20, //Down Heavy Scalar X
					-5, //Down Heavy Scalar y
					5, //Down Heavy Fixed x
					-5, //Down Heavy Fixed y
					0, //Down Heavy vx
					0, //Down Heavy vy
					20, //Down Heavy Damage
					30, //Down Heavy Start Up Duraiton
					20, //Down Heavy Active Duration
					60, //Down Heavy End Lag Duration
					true, //Down Heavy Is Attached To Player
					false, //Down Heavy Dissapear On Hit

					50, //Forward Aerial Additional x
					0, //Forward Aerial Additional y
					50, //Forward Aerial Width
					10, //Forward Aerial Height
					40, //Forward Aerial Stun Duration
					5, //Forward Aerial Scalar X
					-5, //Forward Aerial Scalar y
					3, //Forward Aerial Fixed x
					-3, //Forward Aerial Fixed y
					0, //Forward Aerial vx
					0, //Forward Aerial vy
					10, //Forward Aerial Damage
					10, //Forward Aerial Start Up Duraiton
					30, //Forward Aerial Active Duration
					10, //Forward Aerial End Lag Duration
					true, //Forward Aerial Is Attached To Player
					false, //Forward Aerial Dissapear On Hit

					50, //Back Aerial Additional x
					0, //Back Aerial Additional y
					50, //Back Aerial Width
					10, //Back Aerial Height
					40, //Back Aerial Stun Duration
					5, //Back Aerial Scalar X
					-5, //Back Aerial Scalar y
					3, //Back Aerial Fixed x
					-3, //Back Aerial Fixed y
					0, //Back Aerial vx
					0, //Back Aerial vy
					10, //Back Aerial Damage
					10, //Back Aerial Start Up Duraiton
					30, //Back Aerial Active Duration
					10, //Back Aerial End Lag Duration
					true, //Back Aerial Is Attached To Player
					false, //Back Aerial Dissapear On Hit

					50, //Up Aerial Additional x
					0, //Up Aerial Additional y
					50, //Up Aerial Width
					10, //Up Aerial Height
					40, //Up Aerial Stun Duration
					5, //Up Aerial Scalar X
					-5, //Up Aerial Scalar y
					3, //Up Aerial Fixed x
					-3, //Up Aerial Fixed y
					0, //Up Aerial vx
					0, //Up Aerial vy
					10, //Up Aerial Damage
					10, //Up Aerial Start Up Duraiton
					30, //Up Aerial Active Duration
					10, //Up Aerial End Lag Duration
					true, //Up Aerial Is Attached To Player
					false, //Up Aerial Dissapear On Hit

					50, //Down Aerial Additional x
					0, //Down Aerial Additional y
					50, //Down Aerial Width
					10, //Down Aerial Height
					40, //Down Aerial Stun Duration
					5, //Down Aerial Scalar X
					-5, //Down Aerial Scalar y
					3, //Down Aerial Fixed x
					-3, //Down Aerial Fixed y
					0, //Down Aerial vx
					0, //Down Aerial vy
					10, //Down Aerial Damage
					10, //Down Aerial Start Up Duraiton
					30, //Down Aerial Active Duration
					10, //Down Aerial End Lag Duration
					true, //Down Aerial Is Attached To Player
					false, //Down Aerial Dissapear On Hit

					100, //Forward Special Additional x
					0, //Forward Special Additional y
					50, //Forward Special Width
					10, //Forward Special Height
					20, //Forward Special Stun Duration
					15, //Forward Special Scalar X
					-1, //Forward Special Scalar y
					3, //Forward Special Fixed x
					-3, //Forward Special Fixed y
					2, //Forward Special vx
					0.5, //Forward Special vy
					5, //Forward Special Damage
					10, //Forward Special Start Up Duraiton
					300, //Forward Special Active Duration
					50, //Forward Special End Lag Duration
					false, //Forward Special Is Attached To Player
					true, //Forward Special Dissapear On Hit

					100, //Up Special Additional x
					0, //Up Special Additional y
					50, //Up Special Width
					10, //Up Special Height
					20, //Up Special Stun Duration
					15, //Up Special Scalar X
					-1, //Up Special Scalar y
					3, //Up Special Fixed x
					-3, //Up Special Fixed y
					2, //Up Special vx
					0.5, //Up Special vy
					5, //Up Special Damage
					10, //Up Special Start Up Duraiton
					300, //Up Special Active Duration
					50, //Up Special End Lag Duration
					false, //Up Special Is Attached To Player
					true, //Up Special Dissapear On Hit

					100, //Down Special Additional x
					0, //Down Special Additional y
					50, //Down Special Width
					10, //Down Special Height
					20, //Down Special Stun Duration
					15, //Down Special Scalar X
					-1, //Down Special Scalar y
					3, //Down Special Fixed x
					-3, //Down Special Fixed y
					2, //Down Special vx
					0.5, //Down Special vy
					5, //Down Special Damage
					10, //Down Special Start Up Duraiton
					300, //Down Special Active Duration
					50, //Down Special End Lag Duration
					false, //Down Special Is Attached To Player
					true //Down Special Dissapear On Hit
				);
			}
			else if (player2CharacterID == 2) {
				player2Idle = aIdle;
				player2Move = aMove;
				Player2.Initialise(
					800, //x
					100, //y
					3, //Lives
					100, //Width
					100, //Height
					10, //WalkSpeed
					10, //AerialSpeed
					1, //AerialAcceleration
					1, //WalkAcceleration
					20, //GronudedJumpHeight
					25, //AerialJumpHeight
					1, //FallAcceleration
					10, //FallSpeed
					1, //Weight
					2, //DoubleJumps

					50, //Forward Light Additional x
					0, //Forward Light Additional y
					50, //Forward Light Width
					10, //Forward Light Height
					40, //Forward Light Stun Duration
					5, //Forward Light Scalar X
					-5, //Forward Light Scalar y
					3, //Forward Light Fixed x
					-3, //Forward Light Fixed y
					0, //Forward Light vx
					0, //Forward Light vy
					10, //Forward Light Damage
					10, //Forward Light Start Up Duraiton
					30, //Forward Light Active Duration
					10, //Forward Light End Lag Duration
					true, //Forward Light Is Attached To Player
					false, //Forward Light Dissapear On Hit

					50, //Up Light Additional x
					0, //Up Light Additional y
					50, //Up Light Width
					10, //Up Light Height
					40, //Up Light Stun Duration
					5, //Up Light Scalar X
					-5, //Up Light Scalar y
					3, //Up Light Fixed x
					-3, //Up Light Fixed y
					0, //Up Light vx
					0, //Up Light vy
					10, //Up Light Damage
					10, //Up Light Start Up Duraiton
					30, //Up Light Active Duration
					10, //Up Light End Lag Duration
					true, //Up Light Is Attached To Player
					false, //Up Light Dissapear On Hit

					50, //Down Light Additional x
					0, //Down Light Additional y
					50, //Down Light Width
					10, //Down Light Height
					40, //Down Light Stun Duration
					5, //Down Light Scalar X
					-5, //Down Light Scalar y
					3, //Down Light Fixed x
					-3, //Down Light Fixed y
					0, //Down Light vx
					0, //Down Light vy
					10, //Down Light Damage
					10, //Down Light Start Up Duraiton
					30, //Down Light Active Duration
					10, //Down Light End Lag Duration
					true, //Down Light Is Attached To Player
					false, //Down Light Dissapear On Hit

					50, //Forward Heavy Additional x
					50, //Forward Heavy Additional y
					120, //Forward Heavy Width
					50, //Forward Heavy Height
					40, //Forward Heavy Stun Duration
					20, //Forward Heavy Scalar X
					-5, //Forward Heavy Scalar y
					5, //Forward Heavy Fixed x
					-5, //Forward Heavy Fixed y
					0, //Forward Heavy vx
					0, //Forward Heavy vy
					20, //Forward Heavy Damage
					30, //Forward Heavy Start Up Duraiton
					20, //Forward Heavy Active Duration
					60, //Forward Heavy End Lag Duration
					true, //Forward Heavy Is Attached To Player
					false, //Forward Heavy Dissapear On Hit

					50, //Up Heavy Additional x
					50, //Up Heavy Additional y
					120, //Up Heavy Width
					50, //Up Heavy Height
					40, //Up Heavy Stun Duration
					20, //Up Heavy Scalar X
					-5, //Up Heavy Scalar y
					5, //Up Heavy Fixed x
					-5, //Up Heavy Fixed y
					0, //Up Heavy vx
					0, //Up Heavy vy
					20, //Up Heavy Damage
					30, //Up Heavy Start Up Duraiton
					20, //Up Heavy Active Duration
					60, //Up Heavy End Lag Duration
					true, //Up Heavy Is Attached To Player
					false, //Up Heavy Dissapear On Hit

					50, //Down Heavy Additional x
					50, //Down Heavy Additional y
					120, //Down Heavy Width
					50, //Down Heavy Height
					40, //Down Heavy Stun Duration
					20, //Down Heavy Scalar X
					-5, //Down Heavy Scalar y
					5, //Down Heavy Fixed x
					-5, //Down Heavy Fixed y
					0, //Down Heavy vx
					0, //Down Heavy vy
					20, //Down Heavy Damage
					30, //Down Heavy Start Up Duraiton
					20, //Down Heavy Active Duration
					60, //Down Heavy End Lag Duration
					true, //Down Heavy Is Attached To Player
					false, //Down Heavy Dissapear On Hit

					50, //Forward Aerial Additional x
					0, //Forward Aerial Additional y
					50, //Forward Aerial Width
					10, //Forward Aerial Height
					40, //Forward Aerial Stun Duration
					5, //Forward Aerial Scalar X
					-5, //Forward Aerial Scalar y
					3, //Forward Aerial Fixed x
					-3, //Forward Aerial Fixed y
					0, //Forward Aerial vx
					0, //Forward Aerial vy
					10, //Forward Aerial Damage
					10, //Forward Aerial Start Up Duraiton
					30, //Forward Aerial Active Duration
					10, //Forward Aerial End Lag Duration
					true, //Forward Aerial Is Attached To Player
					false, //Forward Aerial Dissapear On Hit

					50, //Back Aerial Additional x
					0, //Back Aerial Additional y
					50, //Back Aerial Width
					10, //Back Aerial Height
					40, //Back Aerial Stun Duration
					5, //Back Aerial Scalar X
					-5, //Back Aerial Scalar y
					3, //Back Aerial Fixed x
					-3, //Back Aerial Fixed y
					0, //Back Aerial vx
					0, //Back Aerial vy
					10, //Back Aerial Damage
					10, //Back Aerial Start Up Duraiton
					30, //Back Aerial Active Duration
					10, //Back Aerial End Lag Duration
					true, //Back Aerial Is Attached To Player
					false, //Back Aerial Dissapear On Hit

					50, //Up Aerial Additional x
					0, //Up Aerial Additional y
					50, //Up Aerial Width
					10, //Up Aerial Height
					40, //Up Aerial Stun Duration
					5, //Up Aerial Scalar X
					-5, //Up Aerial Scalar y
					3, //Up Aerial Fixed x
					-3, //Up Aerial Fixed y
					0, //Up Aerial vx
					0, //Up Aerial vy
					10, //Up Aerial Damage
					10, //Up Aerial Start Up Duraiton
					30, //Up Aerial Active Duration
					10, //Up Aerial End Lag Duration
					true, //Up Aerial Is Attached To Player
					false, //Up Aerial Dissapear On Hit

					50, //Down Aerial Additional x
					0, //Down Aerial Additional y
					50, //Down Aerial Width
					10, //Down Aerial Height
					40, //Down Aerial Stun Duration
					5, //Down Aerial Scalar X
					-5, //Down Aerial Scalar y
					3, //Down Aerial Fixed x
					-3, //Down Aerial Fixed y
					0, //Down Aerial vx
					0, //Down Aerial vy
					10, //Down Aerial Damage
					10, //Down Aerial Start Up Duraiton
					30, //Down Aerial Active Duration
					10, //Down Aerial End Lag Duration
					true, //Down Aerial Is Attached To Player
					false, //Down Aerial Dissapear On Hit

					100, //Forward Special Additional x
					0, //Forward Special Additional y
					50, //Forward Special Width
					10, //Forward Special Height
					20, //Forward Special Stun Duration
					15, //Forward Special Scalar X
					-1, //Forward Special Scalar y
					3, //Forward Special Fixed x
					-3, //Forward Special Fixed y
					2, //Forward Special vx
					0.5, //Forward Special vy
					5, //Forward Special Damage
					10, //Forward Special Start Up Duraiton
					300, //Forward Special Active Duration
					50, //Forward Special End Lag Duration
					false, //Forward Special Is Attached To Player
					true, //Forward Special Dissapear On Hit

					100, //Up Special Additional x
					0, //Up Special Additional y
					50, //Up Special Width
					10, //Up Special Height
					20, //Up Special Stun Duration
					15, //Up Special Scalar X
					-1, //Up Special Scalar y
					3, //Up Special Fixed x
					-3, //Up Special Fixed y
					2, //Up Special vx
					0.5, //Up Special vy
					5, //Up Special Damage
					10, //Up Special Start Up Duraiton
					300, //Up Special Active Duration
					50, //Up Special End Lag Duration
					false, //Up Special Is Attached To Player
					true, //Up Special Dissapear On Hit

					100, //Down Special Additional x
					0, //Down Special Additional y
					50, //Down Special Width
					10, //Down Special Height
					20, //Down Special Stun Duration
					15, //Down Special Scalar X
					-1, //Down Special Scalar y
					3, //Down Special Fixed x
					-3, //Down Special Fixed y
					2, //Down Special vx
					0.5, //Down Special vy
					5, //Down Special Damage
					10, //Down Special Start Up Duraiton
					300, //Down Special Active Duration
					50, //Down Special End Lag Duration
					false, //Down Special Is Attached To Player
					true //Down Special Dissapear On Hit
				);
			}
			else if (player2CharacterID == 3) {
				player2Idle = lightningIdle;
				player2Move = lightningMove;
				Player2.Initialise(
					800, //x
					100, //y
					3, //Lives
					60, //Width
					200, //Height
					10, //WalkSpeed
					10, //AerialSpeed
					1, //AerialAcceleration
					1, //WalkAcceleration
					20, //GronudedJumpHeight
					25, //AerialJumpHeight
					1, //FallAcceleration
					10, //FallSpeed
					1, //Weight
					2, //DoubleJumps

					50, //Forward Light Additional x
					0, //Forward Light Additional y
					50, //Forward Light Width
					10, //Forward Light Height
					40, //Forward Light Stun Duration
					5, //Forward Light Scalar X
					-5, //Forward Light Scalar y
					3, //Forward Light Fixed x
					-3, //Forward Light Fixed y
					0, //Forward Light vx
					0, //Forward Light vy
					10, //Forward Light Damage
					10, //Forward Light Start Up Duraiton
					30, //Forward Light Active Duration
					10, //Forward Light End Lag Duration
					true, //Forward Light Is Attached To Player
					false, //Forward Light Dissapear On Hit

					50, //Up Light Additional x
					0, //Up Light Additional y
					50, //Up Light Width
					10, //Up Light Height
					40, //Up Light Stun Duration
					5, //Up Light Scalar X
					-5, //Up Light Scalar y
					3, //Up Light Fixed x
					-3, //Up Light Fixed y
					0, //Up Light vx
					0, //Up Light vy
					10, //Up Light Damage
					10, //Up Light Start Up Duraiton
					30, //Up Light Active Duration
					10, //Up Light End Lag Duration
					true, //Up Light Is Attached To Player
					false, //Up Light Dissapear On Hit

					50, //Down Light Additional x
					0, //Down Light Additional y
					50, //Down Light Width
					10, //Down Light Height
					40, //Down Light Stun Duration
					5, //Down Light Scalar X
					-5, //Down Light Scalar y
					3, //Down Light Fixed x
					-3, //Down Light Fixed y
					0, //Down Light vx
					0, //Down Light vy
					10, //Down Light Damage
					10, //Down Light Start Up Duraiton
					30, //Down Light Active Duration
					10, //Down Light End Lag Duration
					true, //Down Light Is Attached To Player
					false, //Down Light Dissapear On Hit

					50, //Forward Heavy Additional x
					50, //Forward Heavy Additional y
					120, //Forward Heavy Width
					50, //Forward Heavy Height
					40, //Forward Heavy Stun Duration
					20, //Forward Heavy Scalar X
					-5, //Forward Heavy Scalar y
					5, //Forward Heavy Fixed x
					-5, //Forward Heavy Fixed y
					0, //Forward Heavy vx
					0, //Forward Heavy vy
					20, //Forward Heavy Damage
					30, //Forward Heavy Start Up Duraiton
					20, //Forward Heavy Active Duration
					60, //Forward Heavy End Lag Duration
					true, //Forward Heavy Is Attached To Player
					false, //Forward Heavy Dissapear On Hit

					50, //Up Heavy Additional x
					50, //Up Heavy Additional y
					120, //Up Heavy Width
					50, //Up Heavy Height
					40, //Up Heavy Stun Duration
					20, //Up Heavy Scalar X
					-5, //Up Heavy Scalar y
					5, //Up Heavy Fixed x
					-5, //Up Heavy Fixed y
					0, //Up Heavy vx
					0, //Up Heavy vy
					20, //Up Heavy Damage
					30, //Up Heavy Start Up Duraiton
					20, //Up Heavy Active Duration
					60, //Up Heavy End Lag Duration
					true, //Up Heavy Is Attached To Player
					false, //Up Heavy Dissapear On Hit

					50, //Down Heavy Additional x
					50, //Down Heavy Additional y
					120, //Down Heavy Width
					50, //Down Heavy Height
					40, //Down Heavy Stun Duration
					20, //Down Heavy Scalar X
					-5, //Down Heavy Scalar y
					5, //Down Heavy Fixed x
					-5, //Down Heavy Fixed y
					0, //Down Heavy vx
					0, //Down Heavy vy
					20, //Down Heavy Damage
					30, //Down Heavy Start Up Duraiton
					20, //Down Heavy Active Duration
					60, //Down Heavy End Lag Duration
					true, //Down Heavy Is Attached To Player
					false, //Down Heavy Dissapear On Hit

					50, //Forward Aerial Additional x
					0, //Forward Aerial Additional y
					50, //Forward Aerial Width
					10, //Forward Aerial Height
					40, //Forward Aerial Stun Duration
					5, //Forward Aerial Scalar X
					-5, //Forward Aerial Scalar y
					3, //Forward Aerial Fixed x
					-3, //Forward Aerial Fixed y
					0, //Forward Aerial vx
					0, //Forward Aerial vy
					10, //Forward Aerial Damage
					10, //Forward Aerial Start Up Duraiton
					30, //Forward Aerial Active Duration
					10, //Forward Aerial End Lag Duration
					true, //Forward Aerial Is Attached To Player
					false, //Forward Aerial Dissapear On Hit

					50, //Back Aerial Additional x
					0, //Back Aerial Additional y
					50, //Back Aerial Width
					10, //Back Aerial Height
					40, //Back Aerial Stun Duration
					5, //Back Aerial Scalar X
					-5, //Back Aerial Scalar y
					3, //Back Aerial Fixed x
					-3, //Back Aerial Fixed y
					0, //Back Aerial vx
					0, //Back Aerial vy
					10, //Back Aerial Damage
					10, //Back Aerial Start Up Duraiton
					30, //Back Aerial Active Duration
					10, //Back Aerial End Lag Duration
					true, //Back Aerial Is Attached To Player
					false, //Back Aerial Dissapear On Hit

					50, //Up Aerial Additional x
					0, //Up Aerial Additional y
					50, //Up Aerial Width
					10, //Up Aerial Height
					40, //Up Aerial Stun Duration
					5, //Up Aerial Scalar X
					-5, //Up Aerial Scalar y
					3, //Up Aerial Fixed x
					-3, //Up Aerial Fixed y
					0, //Up Aerial vx
					0, //Up Aerial vy
					10, //Up Aerial Damage
					10, //Up Aerial Start Up Duraiton
					30, //Up Aerial Active Duration
					10, //Up Aerial End Lag Duration
					true, //Up Aerial Is Attached To Player
					false, //Up Aerial Dissapear On Hit

					50, //Down Aerial Additional x
					0, //Down Aerial Additional y
					50, //Down Aerial Width
					10, //Down Aerial Height
					40, //Down Aerial Stun Duration
					5, //Down Aerial Scalar X
					-5, //Down Aerial Scalar y
					3, //Down Aerial Fixed x
					-3, //Down Aerial Fixed y
					0, //Down Aerial vx
					0, //Down Aerial vy
					10, //Down Aerial Damage
					10, //Down Aerial Start Up Duraiton
					30, //Down Aerial Active Duration
					10, //Down Aerial End Lag Duration
					true, //Down Aerial Is Attached To Player
					false, //Down Aerial Dissapear On Hit

					100, //Forward Special Additional x
					0, //Forward Special Additional y
					50, //Forward Special Width
					10, //Forward Special Height
					20, //Forward Special Stun Duration
					15, //Forward Special Scalar X
					-1, //Forward Special Scalar y
					3, //Forward Special Fixed x
					-3, //Forward Special Fixed y
					2, //Forward Special vx
					0.5, //Forward Special vy
					5, //Forward Special Damage
					10, //Forward Special Start Up Duraiton
					300, //Forward Special Active Duration
					50, //Forward Special End Lag Duration
					false, //Forward Special Is Attached To Player
					true, //Forward Special Dissapear On Hit

					100, //Up Special Additional x
					0, //Up Special Additional y
					50, //Up Special Width
					10, //Up Special Height
					20, //Up Special Stun Duration
					15, //Up Special Scalar X
					-1, //Up Special Scalar y
					3, //Up Special Fixed x
					-3, //Up Special Fixed y
					2, //Up Special vx
					0.5, //Up Special vy
					5, //Up Special Damage
					10, //Up Special Start Up Duraiton
					300, //Up Special Active Duration
					50, //Up Special End Lag Duration
					false, //Up Special Is Attached To Player
					true, //Up Special Dissapear On Hit

					100, //Down Special Additional x
					0, //Down Special Additional y
					50, //Down Special Width
					10, //Down Special Height
					20, //Down Special Stun Duration
					15, //Down Special Scalar X
					-1, //Down Special Scalar y
					3, //Down Special Fixed x
					-3, //Down Special Fixed y
					2, //Down Special vx
					0.5, //Down Special vy
					5, //Down Special Damage
					10, //Down Special Start Up Duraiton
					300, //Down Special Active Duration
					50, //Down Special End Lag Duration
					false, //Down Special Is Attached To Player
					true //Down Special Dissapear On Hit
				);
			}
			else if (player2CharacterID == 4) {
				player2Idle = dogIdle;
				player2Move = dogMove;
				Player2.Initialise(
					800, //x
					100, //y
					3, //Lives
					60, //Width
					40, //Height
					10, //WalkSpeed
					10, //AerialSpeed
					1, //AerialAcceleration
					1, //WalkAcceleration
					20, //GronudedJumpHeight
					25, //AerialJumpHeight
					1, //FallAcceleration
					10, //FallSpeed
					1, //Weight
					2, //DoubleJumps

					50, //Forward Light Additional x
					0, //Forward Light Additional y
					50, //Forward Light Width
					10, //Forward Light Height
					40, //Forward Light Stun Duration
					5, //Forward Light Scalar X
					-5, //Forward Light Scalar y
					3, //Forward Light Fixed x
					-3, //Forward Light Fixed y
					0, //Forward Light vx
					0, //Forward Light vy
					10, //Forward Light Damage
					10, //Forward Light Start Up Duraiton
					30, //Forward Light Active Duration
					10, //Forward Light End Lag Duration
					true, //Forward Light Is Attached To Player
					false, //Forward Light Dissapear On Hit

					50, //Up Light Additional x
					0, //Up Light Additional y
					50, //Up Light Width
					10, //Up Light Height
					40, //Up Light Stun Duration
					5, //Up Light Scalar X
					-5, //Up Light Scalar y
					3, //Up Light Fixed x
					-3, //Up Light Fixed y
					0, //Up Light vx
					0, //Up Light vy
					10, //Up Light Damage
					10, //Up Light Start Up Duraiton
					30, //Up Light Active Duration
					10, //Up Light End Lag Duration
					true, //Up Light Is Attached To Player
					false, //Up Light Dissapear On Hit

					50, //Down Light Additional x
					0, //Down Light Additional y
					50, //Down Light Width
					10, //Down Light Height
					40, //Down Light Stun Duration
					5, //Down Light Scalar X
					-5, //Down Light Scalar y
					3, //Down Light Fixed x
					-3, //Down Light Fixed y
					0, //Down Light vx
					0, //Down Light vy
					10, //Down Light Damage
					10, //Down Light Start Up Duraiton
					30, //Down Light Active Duration
					10, //Down Light End Lag Duration
					true, //Down Light Is Attached To Player
					false, //Down Light Dissapear On Hit

					50, //Forward Heavy Additional x
					50, //Forward Heavy Additional y
					120, //Forward Heavy Width
					50, //Forward Heavy Height
					40, //Forward Heavy Stun Duration
					20, //Forward Heavy Scalar X
					-5, //Forward Heavy Scalar y
					5, //Forward Heavy Fixed x
					-5, //Forward Heavy Fixed y
					0, //Forward Heavy vx
					0, //Forward Heavy vy
					20, //Forward Heavy Damage
					30, //Forward Heavy Start Up Duraiton
					20, //Forward Heavy Active Duration
					60, //Forward Heavy End Lag Duration
					true, //Forward Heavy Is Attached To Player
					false, //Forward Heavy Dissapear On Hit

					50, //Up Heavy Additional x
					50, //Up Heavy Additional y
					120, //Up Heavy Width
					50, //Up Heavy Height
					40, //Up Heavy Stun Duration
					20, //Up Heavy Scalar X
					-5, //Up Heavy Scalar y
					5, //Up Heavy Fixed x
					-5, //Up Heavy Fixed y
					0, //Up Heavy vx
					0, //Up Heavy vy
					20, //Up Heavy Damage
					30, //Up Heavy Start Up Duraiton
					20, //Up Heavy Active Duration
					60, //Up Heavy End Lag Duration
					true, //Up Heavy Is Attached To Player
					false, //Up Heavy Dissapear On Hit

					50, //Down Heavy Additional x
					50, //Down Heavy Additional y
					120, //Down Heavy Width
					50, //Down Heavy Height
					40, //Down Heavy Stun Duration
					20, //Down Heavy Scalar X
					-5, //Down Heavy Scalar y
					5, //Down Heavy Fixed x
					-5, //Down Heavy Fixed y
					0, //Down Heavy vx
					0, //Down Heavy vy
					20, //Down Heavy Damage
					30, //Down Heavy Start Up Duraiton
					20, //Down Heavy Active Duration
					60, //Down Heavy End Lag Duration
					true, //Down Heavy Is Attached To Player
					false, //Down Heavy Dissapear On Hit

					50, //Forward Aerial Additional x
					0, //Forward Aerial Additional y
					50, //Forward Aerial Width
					10, //Forward Aerial Height
					40, //Forward Aerial Stun Duration
					5, //Forward Aerial Scalar X
					-5, //Forward Aerial Scalar y
					3, //Forward Aerial Fixed x
					-3, //Forward Aerial Fixed y
					0, //Forward Aerial vx
					0, //Forward Aerial vy
					10, //Forward Aerial Damage
					10, //Forward Aerial Start Up Duraiton
					30, //Forward Aerial Active Duration
					10, //Forward Aerial End Lag Duration
					true, //Forward Aerial Is Attached To Player
					false, //Forward Aerial Dissapear On Hit

					50, //Back Aerial Additional x
					0, //Back Aerial Additional y
					50, //Back Aerial Width
					10, //Back Aerial Height
					40, //Back Aerial Stun Duration
					5, //Back Aerial Scalar X
					-5, //Back Aerial Scalar y
					3, //Back Aerial Fixed x
					-3, //Back Aerial Fixed y
					0, //Back Aerial vx
					0, //Back Aerial vy
					10, //Back Aerial Damage
					10, //Back Aerial Start Up Duraiton
					30, //Back Aerial Active Duration
					10, //Back Aerial End Lag Duration
					true, //Back Aerial Is Attached To Player
					false, //Back Aerial Dissapear On Hit

					50, //Up Aerial Additional x
					0, //Up Aerial Additional y
					50, //Up Aerial Width
					10, //Up Aerial Height
					40, //Up Aerial Stun Duration
					5, //Up Aerial Scalar X
					-5, //Up Aerial Scalar y
					3, //Up Aerial Fixed x
					-3, //Up Aerial Fixed y
					0, //Up Aerial vx
					0, //Up Aerial vy
					10, //Up Aerial Damage
					10, //Up Aerial Start Up Duraiton
					30, //Up Aerial Active Duration
					10, //Up Aerial End Lag Duration
					true, //Up Aerial Is Attached To Player
					false, //Up Aerial Dissapear On Hit

					50, //Down Aerial Additional x
					0, //Down Aerial Additional y
					50, //Down Aerial Width
					10, //Down Aerial Height
					40, //Down Aerial Stun Duration
					5, //Down Aerial Scalar X
					-5, //Down Aerial Scalar y
					3, //Down Aerial Fixed x
					-3, //Down Aerial Fixed y
					0, //Down Aerial vx
					0, //Down Aerial vy
					10, //Down Aerial Damage
					10, //Down Aerial Start Up Duraiton
					30, //Down Aerial Active Duration
					10, //Down Aerial End Lag Duration
					true, //Down Aerial Is Attached To Player
					false, //Down Aerial Dissapear On Hit

					100, //Forward Special Additional x
					0, //Forward Special Additional y
					50, //Forward Special Width
					10, //Forward Special Height
					20, //Forward Special Stun Duration
					15, //Forward Special Scalar X
					-1, //Forward Special Scalar y
					3, //Forward Special Fixed x
					-3, //Forward Special Fixed y
					2, //Forward Special vx
					0.5, //Forward Special vy
					5, //Forward Special Damage
					10, //Forward Special Start Up Duraiton
					300, //Forward Special Active Duration
					50, //Forward Special End Lag Duration
					false, //Forward Special Is Attached To Player
					true, //Forward Special Dissapear On Hit

					100, //Up Special Additional x
					0, //Up Special Additional y
					50, //Up Special Width
					10, //Up Special Height
					20, //Up Special Stun Duration
					15, //Up Special Scalar X
					-1, //Up Special Scalar y
					3, //Up Special Fixed x
					-3, //Up Special Fixed y
					2, //Up Special vx
					0.5, //Up Special vy
					5, //Up Special Damage
					10, //Up Special Start Up Duraiton
					300, //Up Special Active Duration
					50, //Up Special End Lag Duration
					false, //Up Special Is Attached To Player
					true, //Up Special Dissapear On Hit

					100, //Down Special Additional x
					0, //Down Special Additional y
					50, //Down Special Width
					10, //Down Special Height
					20, //Down Special Stun Duration
					15, //Down Special Scalar X
					-1, //Down Special Scalar y
					3, //Down Special Fixed x
					-3, //Down Special Fixed y
					2, //Down Special vx
					0.5, //Down Special vy
					5, //Down Special Damage
					10, //Down Special Start Up Duraiton
					300, //Down Special Active Duration
					50, //Down Special End Lag Duration
					false, //Down Special Is Attached To Player
					true //Down Special Dissapear On Hit
				);
			}
			else if (player1CharacterID == 5) {
				player2Idle = chickenIdle;
				player2Move = chickenMove;
				Player2.Initialise(
					800, //x
					100, //y
					3, //Lives
					150, //Width
					150, //Height
					10, //WalkSpeed
					10, //AerialSpeed
					1, //AerialAcceleration
					1, //WalkAcceleration
					20, //GronudedJumpHeight
					25, //AerialJumpHeight
					1, //FallAcceleration
					10, //FallSpeed
					1, //Weight
					2, //DoubleJumps

					50, //Forward Light Additional x
					0, //Forward Light Additional y
					50, //Forward Light Width
					10, //Forward Light Height
					40, //Forward Light Stun Duration
					5, //Forward Light Scalar X
					-5, //Forward Light Scalar y
					3, //Forward Light Fixed x
					-3, //Forward Light Fixed y
					0, //Forward Light vx
					0, //Forward Light vy
					10, //Forward Light Damage
					10, //Forward Light Start Up Duraiton
					30, //Forward Light Active Duration
					10, //Forward Light End Lag Duration
					true, //Forward Light Is Attached To Player
					false, //Forward Light Dissapear On Hit

					50, //Up Light Additional x
					0, //Up Light Additional y
					50, //Up Light Width
					10, //Up Light Height
					40, //Up Light Stun Duration
					5, //Up Light Scalar X
					-5, //Up Light Scalar y
					3, //Up Light Fixed x
					-3, //Up Light Fixed y
					0, //Up Light vx
					0, //Up Light vy
					10, //Up Light Damage
					10, //Up Light Start Up Duraiton
					30, //Up Light Active Duration
					10, //Up Light End Lag Duration
					true, //Up Light Is Attached To Player
					false, //Up Light Dissapear On Hit

					50, //Down Light Additional x
					0, //Down Light Additional y
					50, //Down Light Width
					10, //Down Light Height
					40, //Down Light Stun Duration
					5, //Down Light Scalar X
					-5, //Down Light Scalar y
					3, //Down Light Fixed x
					-3, //Down Light Fixed y
					0, //Down Light vx
					0, //Down Light vy
					10, //Down Light Damage
					10, //Down Light Start Up Duraiton
					30, //Down Light Active Duration
					10, //Down Light End Lag Duration
					true, //Down Light Is Attached To Player
					false, //Down Light Dissapear On Hit

					50, //Forward Heavy Additional x
					50, //Forward Heavy Additional y
					120, //Forward Heavy Width
					50, //Forward Heavy Height
					40, //Forward Heavy Stun Duration
					20, //Forward Heavy Scalar X
					-5, //Forward Heavy Scalar y
					5, //Forward Heavy Fixed x
					-5, //Forward Heavy Fixed y
					0, //Forward Heavy vx
					0, //Forward Heavy vy
					20, //Forward Heavy Damage
					30, //Forward Heavy Start Up Duraiton
					20, //Forward Heavy Active Duration
					60, //Forward Heavy End Lag Duration
					true, //Forward Heavy Is Attached To Player
					false, //Forward Heavy Dissapear On Hit

					50, //Up Heavy Additional x
					50, //Up Heavy Additional y
					120, //Up Heavy Width
					50, //Up Heavy Height
					40, //Up Heavy Stun Duration
					20, //Up Heavy Scalar X
					-5, //Up Heavy Scalar y
					5, //Up Heavy Fixed x
					-5, //Up Heavy Fixed y
					0, //Up Heavy vx
					0, //Up Heavy vy
					20, //Up Heavy Damage
					30, //Up Heavy Start Up Duraiton
					20, //Up Heavy Active Duration
					60, //Up Heavy End Lag Duration
					true, //Up Heavy Is Attached To Player
					false, //Up Heavy Dissapear On Hit

					50, //Down Heavy Additional x
					50, //Down Heavy Additional y
					120, //Down Heavy Width
					50, //Down Heavy Height
					40, //Down Heavy Stun Duration
					20, //Down Heavy Scalar X
					-5, //Down Heavy Scalar y
					5, //Down Heavy Fixed x
					-5, //Down Heavy Fixed y
					0, //Down Heavy vx
					0, //Down Heavy vy
					20, //Down Heavy Damage
					30, //Down Heavy Start Up Duraiton
					20, //Down Heavy Active Duration
					60, //Down Heavy End Lag Duration
					true, //Down Heavy Is Attached To Player
					false, //Down Heavy Dissapear On Hit

					50, //Forward Aerial Additional x
					0, //Forward Aerial Additional y
					50, //Forward Aerial Width
					10, //Forward Aerial Height
					40, //Forward Aerial Stun Duration
					5, //Forward Aerial Scalar X
					-5, //Forward Aerial Scalar y
					3, //Forward Aerial Fixed x
					-3, //Forward Aerial Fixed y
					0, //Forward Aerial vx
					0, //Forward Aerial vy
					10, //Forward Aerial Damage
					10, //Forward Aerial Start Up Duraiton
					30, //Forward Aerial Active Duration
					10, //Forward Aerial End Lag Duration
					true, //Forward Aerial Is Attached To Player
					false, //Forward Aerial Dissapear On Hit

					50, //Back Aerial Additional x
					0, //Back Aerial Additional y
					50, //Back Aerial Width
					10, //Back Aerial Height
					40, //Back Aerial Stun Duration
					5, //Back Aerial Scalar X
					-5, //Back Aerial Scalar y
					3, //Back Aerial Fixed x
					-3, //Back Aerial Fixed y
					0, //Back Aerial vx
					0, //Back Aerial vy
					10, //Back Aerial Damage
					10, //Back Aerial Start Up Duraiton
					30, //Back Aerial Active Duration
					10, //Back Aerial End Lag Duration
					true, //Back Aerial Is Attached To Player
					false, //Back Aerial Dissapear On Hit

					50, //Up Aerial Additional x
					0, //Up Aerial Additional y
					50, //Up Aerial Width
					10, //Up Aerial Height
					40, //Up Aerial Stun Duration
					5, //Up Aerial Scalar X
					-5, //Up Aerial Scalar y
					3, //Up Aerial Fixed x
					-3, //Up Aerial Fixed y
					0, //Up Aerial vx
					0, //Up Aerial vy
					10, //Up Aerial Damage
					10, //Up Aerial Start Up Duraiton
					30, //Up Aerial Active Duration
					10, //Up Aerial End Lag Duration
					true, //Up Aerial Is Attached To Player
					false, //Up Aerial Dissapear On Hit

					50, //Down Aerial Additional x
					0, //Down Aerial Additional y
					50, //Down Aerial Width
					10, //Down Aerial Height
					40, //Down Aerial Stun Duration
					5, //Down Aerial Scalar X
					-5, //Down Aerial Scalar y
					3, //Down Aerial Fixed x
					-3, //Down Aerial Fixed y
					0, //Down Aerial vx
					0, //Down Aerial vy
					10, //Down Aerial Damage
					10, //Down Aerial Start Up Duraiton
					30, //Down Aerial Active Duration
					10, //Down Aerial End Lag Duration
					true, //Down Aerial Is Attached To Player
					false, //Down Aerial Dissapear On Hit

					100, //Forward Special Additional x
					0, //Forward Special Additional y
					50, //Forward Special Width
					10, //Forward Special Height
					20, //Forward Special Stun Duration
					15, //Forward Special Scalar X
					-1, //Forward Special Scalar y
					3, //Forward Special Fixed x
					-3, //Forward Special Fixed y
					2, //Forward Special vx
					0.5, //Forward Special vy
					5, //Forward Special Damage
					10, //Forward Special Start Up Duraiton
					300, //Forward Special Active Duration
					50, //Forward Special End Lag Duration
					false, //Forward Special Is Attached To Player
					true, //Forward Special Dissapear On Hit

					100, //Up Special Additional x
					0, //Up Special Additional y
					50, //Up Special Width
					10, //Up Special Height
					20, //Up Special Stun Duration
					15, //Up Special Scalar X
					-1, //Up Special Scalar y
					3, //Up Special Fixed x
					-3, //Up Special Fixed y
					2, //Up Special vx
					0.5, //Up Special vy
					5, //Up Special Damage
					10, //Up Special Start Up Duraiton
					300, //Up Special Active Duration
					50, //Up Special End Lag Duration
					false, //Up Special Is Attached To Player
					true, //Up Special Dissapear On Hit

					100, //Down Special Additional x
					0, //Down Special Additional y
					50, //Down Special Width
					10, //Down Special Height
					20, //Down Special Stun Duration
					15, //Down Special Scalar X
					-1, //Down Special Scalar y
					3, //Down Special Fixed x
					-3, //Down Special Fixed y
					2, //Down Special vx
					0.5, //Down Special vy
					5, //Down Special Damage
					10, //Down Special Start Up Duraiton
					300, //Down Special Active Duration
					50, //Down Special End Lag Duration
					false, //Down Special Is Attached To Player
					true //Down Special Dissapear On Hit
				);
			}
			else if (player2CharacterID == 6) {
				player2Idle = rockIdle;
				player2Move = rockMove;
				Player2.Initialise(
					gfx.ScreenWidth / 4, //x
					100, //y
					3, //Lives
					100, //Width
					100, //Height
					10, //WalkSpeed
					10, //AerialSpeed
					1, //AerialAcceleration
					1, //WalkAcceleration
					20, //GronudedJumpHeight
					25, //AerialJumpHeight
					1, //FallAcceleration
					10, //FallSpeed
					1, //Weight
					2, //DoubleJumps

					50, //Forward Light Additional x
					0, //Forward Light Additional y
					50, //Forward Light Width
					10, //Forward Light Height
					40, //Forward Light Stun Duration
					5, //Forward Light Scalar X
					-5, //Forward Light Scalar y
					3, //Forward Light Fixed x
					-3, //Forward Light Fixed y
					0, //Forward Light vx
					0, //Forward Light vy
					10, //Forward Light Damage
					10, //Forward Light Start Up Duraiton
					30, //Forward Light Active Duration
					10, //Forward Light End Lag Duration
					true, //Forward Light Is Attached To Player
					false, //Forward Light Dissapear On Hit

					50, //Up Light Additional x
					0, //Up Light Additional y
					50, //Up Light Width
					10, //Up Light Height
					40, //Up Light Stun Duration
					5, //Up Light Scalar X
					-5, //Up Light Scalar y
					3, //Up Light Fixed x
					-3, //Up Light Fixed y
					0, //Up Light vx
					0, //Up Light vy
					10, //Up Light Damage
					10, //Up Light Start Up Duraiton
					30, //Up Light Active Duration
					10, //Up Light End Lag Duration
					true, //Up Light Is Attached To Player
					false, //Up Light Dissapear On Hit

					50, //Down Light Additional x
					0, //Down Light Additional y
					50, //Down Light Width
					10, //Down Light Height
					40, //Down Light Stun Duration
					5, //Down Light Scalar X
					-5, //Down Light Scalar y
					3, //Down Light Fixed x
					-3, //Down Light Fixed y
					0, //Down Light vx
					0, //Down Light vy
					10, //Down Light Damage
					10, //Down Light Start Up Duraiton
					30, //Down Light Active Duration
					10, //Down Light End Lag Duration
					true, //Down Light Is Attached To Player
					false, //Down Light Dissapear On Hit

					50, //Forward Heavy Additional x
					50, //Forward Heavy Additional y
					120, //Forward Heavy Width
					50, //Forward Heavy Height
					40, //Forward Heavy Stun Duration
					20, //Forward Heavy Scalar X
					-5, //Forward Heavy Scalar y
					5, //Forward Heavy Fixed x
					-5, //Forward Heavy Fixed y
					0, //Forward Heavy vx
					0, //Forward Heavy vy
					20, //Forward Heavy Damage
					30, //Forward Heavy Start Up Duraiton
					20, //Forward Heavy Active Duration
					60, //Forward Heavy End Lag Duration
					true, //Forward Heavy Is Attached To Player
					false, //Forward Heavy Dissapear On Hit

					50, //Up Heavy Additional x
					50, //Up Heavy Additional y
					120, //Up Heavy Width
					50, //Up Heavy Height
					40, //Up Heavy Stun Duration
					20, //Up Heavy Scalar X
					-5, //Up Heavy Scalar y
					5, //Up Heavy Fixed x
					-5, //Up Heavy Fixed y
					0, //Up Heavy vx
					0, //Up Heavy vy
					20, //Up Heavy Damage
					30, //Up Heavy Start Up Duraiton
					20, //Up Heavy Active Duration
					60, //Up Heavy End Lag Duration
					true, //Up Heavy Is Attached To Player
					false, //Up Heavy Dissapear On Hit

					50, //Down Heavy Additional x
					50, //Down Heavy Additional y
					120, //Down Heavy Width
					50, //Down Heavy Height
					40, //Down Heavy Stun Duration
					20, //Down Heavy Scalar X
					-5, //Down Heavy Scalar y
					5, //Down Heavy Fixed x
					-5, //Down Heavy Fixed y
					0, //Down Heavy vx
					0, //Down Heavy vy
					20, //Down Heavy Damage
					30, //Down Heavy Start Up Duraiton
					20, //Down Heavy Active Duration
					60, //Down Heavy End Lag Duration
					true, //Down Heavy Is Attached To Player
					false, //Down Heavy Dissapear On Hit

					50, //Forward Aerial Additional x
					0, //Forward Aerial Additional y
					50, //Forward Aerial Width
					10, //Forward Aerial Height
					40, //Forward Aerial Stun Duration
					5, //Forward Aerial Scalar X
					-5, //Forward Aerial Scalar y
					3, //Forward Aerial Fixed x
					-3, //Forward Aerial Fixed y
					0, //Forward Aerial vx
					0, //Forward Aerial vy
					10, //Forward Aerial Damage
					10, //Forward Aerial Start Up Duraiton
					30, //Forward Aerial Active Duration
					10, //Forward Aerial End Lag Duration
					true, //Forward Aerial Is Attached To Player
					false, //Forward Aerial Dissapear On Hit

					50, //Back Aerial Additional x
					0, //Back Aerial Additional y
					50, //Back Aerial Width
					10, //Back Aerial Height
					40, //Back Aerial Stun Duration
					5, //Back Aerial Scalar X
					-5, //Back Aerial Scalar y
					3, //Back Aerial Fixed x
					-3, //Back Aerial Fixed y
					0, //Back Aerial vx
					0, //Back Aerial vy
					10, //Back Aerial Damage
					10, //Back Aerial Start Up Duraiton
					30, //Back Aerial Active Duration
					10, //Back Aerial End Lag Duration
					true, //Back Aerial Is Attached To Player
					false, //Back Aerial Dissapear On Hit

					50, //Up Aerial Additional x
					0, //Up Aerial Additional y
					50, //Up Aerial Width
					10, //Up Aerial Height
					40, //Up Aerial Stun Duration
					5, //Up Aerial Scalar X
					-5, //Up Aerial Scalar y
					3, //Up Aerial Fixed x
					-3, //Up Aerial Fixed y
					0, //Up Aerial vx
					0, //Up Aerial vy
					10, //Up Aerial Damage
					10, //Up Aerial Start Up Duraiton
					30, //Up Aerial Active Duration
					10, //Up Aerial End Lag Duration
					true, //Up Aerial Is Attached To Player
					false, //Up Aerial Dissapear On Hit

					50, //Down Aerial Additional x
					0, //Down Aerial Additional y
					50, //Down Aerial Width
					10, //Down Aerial Height
					40, //Down Aerial Stun Duration
					5, //Down Aerial Scalar X
					-5, //Down Aerial Scalar y
					3, //Down Aerial Fixed x
					-3, //Down Aerial Fixed y
					0, //Down Aerial vx
					0, //Down Aerial vy
					10, //Down Aerial Damage
					10, //Down Aerial Start Up Duraiton
					30, //Down Aerial Active Duration
					10, //Down Aerial End Lag Duration
					true, //Down Aerial Is Attached To Player
					false, //Down Aerial Dissapear On Hit

					100, //Forward Special Additional x
					0, //Forward Special Additional y
					50, //Forward Special Width
					10, //Forward Special Height
					20, //Forward Special Stun Duration
					15, //Forward Special Scalar X
					-1, //Forward Special Scalar y
					3, //Forward Special Fixed x
					-3, //Forward Special Fixed y
					2, //Forward Special vx
					0.5, //Forward Special vy
					5, //Forward Special Damage
					10, //Forward Special Start Up Duraiton
					300, //Forward Special Active Duration
					50, //Forward Special End Lag Duration
					false, //Forward Special Is Attached To Player
					true, //Forward Special Dissapear On Hit

					100, //Up Special Additional x
					0, //Up Special Additional y
					50, //Up Special Width
					10, //Up Special Height
					20, //Up Special Stun Duration
					15, //Up Special Scalar X
					-1, //Up Special Scalar y
					3, //Up Special Fixed x
					-3, //Up Special Fixed y
					2, //Up Special vx
					0.5, //Up Special vy
					5, //Up Special Damage
					10, //Up Special Start Up Duraiton
					300, //Up Special Active Duration
					50, //Up Special End Lag Duration
					false, //Up Special Is Attached To Player
					true, //Up Special Dissapear On Hit

					100, //Down Special Additional x
					0, //Down Special Additional y
					50, //Down Special Width
					10, //Down Special Height
					20, //Down Special Stun Duration
					15, //Down Special Scalar X
					-1, //Down Special Scalar y
					3, //Down Special Fixed x
					-3, //Down Special Fixed y
					2, //Down Special vx
					0.5, //Down Special vy
					5, //Down Special Damage
					10, //Down Special Start Up Duraiton
					300, //Down Special Active Duration
					50, //Down Special End Lag Duration
					false, //Down Special Is Attached To Player
					true //Down Special Dissapear On Hit
				);
			}
			timeUntilStart = 180;
			timeGoIsDisplayed = 60;
		}
	}
	else if (!paused && timeUntilStart > 0) {
		timeUntilStart--;
	}
	else {
		if (paused) {
			if (enterOrEscapeHeld == false && (wnd.kbd.KeyIsPressed(VK_RETURN) || wnd.kbd.KeyIsPressed(VK_ESCAPE))) {
				paused = false;
			}
		}
		else if (Player1.IsAlive(gfx.ScreenWidth, gfx.ScreenHeight, leniancy) && Player2.IsAlive(gfx.ScreenWidth, gfx.ScreenHeight, leniancy)) {//If both players are alive
			if (enterOrEscapeHeld == false && (wnd.kbd.KeyIsPressed(VK_RETURN) || wnd.kbd.KeyIsPressed(VK_ESCAPE))) {
				timeUntilStart = 180;
				timeGoIsDisplayed = 60;
				paused = true;
			}
			if (timeGoIsDisplayed > 0) {
				timeGoIsDisplayed--;
			}
			//Update models
			Player1.UpdateCharacter(wnd.kbd.KeyIsPressed(0x41), wnd.kbd.KeyIsPressed(0x44), wnd.kbd.KeyIsPressed(0x53), wnd.kbd.KeyIsPressed(0x57), wnd.kbd.KeyIsPressed(0x47), wnd.kbd.KeyIsPressed(0x46), wnd.kbd.KeyIsPressed(0x54), wnd.kbd.KeyIsPressed(0x48), stageX0, stageY0, stageX1, stageY1);
			Player2.UpdateCharacter(wnd.kbd.KeyIsPressed(VK_LEFT), wnd.kbd.KeyIsPressed(VK_RIGHT), wnd.kbd.KeyIsPressed(VK_DOWN), wnd.kbd.KeyIsPressed(VK_UP), wnd.kbd.KeyIsPressed(0x4C), wnd.kbd.KeyIsPressed(0x4B), wnd.kbd.KeyIsPressed(0x4F), wnd.kbd.KeyIsPressed(VK_OEM_1), stageX0, stageY0, stageX1, stageY1);

			if (Player1.IsMoveColliding(Player2.x, Player2.y, Player2.width, Player2.height)) { //Is player 1 hitting any move
				Player2.IsHit(Player1.MoveThatHitStun(), Player1.MoveThatHitDamage(), Player1.MoveThatHitFixedX(), Player1.MoveThatHitFixedY(), Player1.MoveThatHitScalarX(), Player1.MoveThatHitScalarY());
			}
			if (Player2.IsMoveColliding(Player1.x, Player1.y, Player1.width, Player1.height)) { //Is player 2 hitting any move
				Player1.IsHit(Player2.MoveThatHitStun(), Player2.MoveThatHitDamage(), Player2.MoveThatHitFixedX(), Player2.MoveThatHitFixedY(), Player2.MoveThatHitScalarX(), Player2.MoveThatHitScalarY());
			}
		}
		else {
			startMenu = true;
			if (Player1.lives == 0) {
				previousWinner = 2;
			}
			else {
				previousWinner = 1;
			}
		}
	}
	enterOrEscapeHeld = wnd.kbd.KeyIsPressed(VK_RETURN) || wnd.kbd.KeyIsPressed(VK_ESCAPE);
}

void Game::ComposeFrame()
{
	if (startMenu) {
		gfx.DrawSprite(gfx.ScreenWidth / 2 - 200, 100, cycling, SpriteEffect::Copy{}, false);
		gfx.DrawSprite(gfx.ScreenWidth / 4 - 200, 400, controls1, SpriteEffect::Copy{}, false);
		gfx.DrawSprite(gfx.ScreenWidth / 4 * 3 - 200, 400, controls2, SpriteEffect::Copy{}, false);

		if (previousWinner == 1) {
			gfx.DrawSprite(gfx.ScreenWidth / 2 - 250, 500, player1Win, SpriteEffect::Copy{}, false);
		}
		else if (previousWinner == 2) {
			gfx.DrawSprite(gfx.ScreenWidth / 2 - 250, 500, player2Win, SpriteEffect::Copy{}, false);
		}

		if (player1CharacterID == 1) {
			gfx.DrawSprite(gfx.ScreenWidth / 4, 100, circleIdle, SpriteEffect::Copy{}, false);
		}
		else if (player1CharacterID == 2) {
			gfx.DrawSprite(gfx.ScreenWidth / 4, 100, aIdle, SpriteEffect::Copy{}, false);
		}
		else if (player1CharacterID == 3) {
			gfx.DrawSprite(gfx.ScreenWidth / 4, 100, lightningIdle, SpriteEffect::Copy{}, true);
		}
		else if (player1CharacterID == 4) {
			gfx.DrawSprite(gfx.ScreenWidth / 4, 100, dogIdle, SpriteEffect::Copy{}, true);
		}
		else if (player1CharacterID == 5) {
			gfx.DrawSprite(gfx.ScreenWidth / 4, 100, chickenIdle, SpriteEffect::Copy{}, true);
		}
		else if (player1CharacterID == 6) {
			gfx.DrawSprite(gfx.ScreenWidth / 4, 100, rockIdle, SpriteEffect::Copy{}, true);
		}


		if (player2CharacterID == 1) {
			gfx.DrawSprite(gfx.ScreenWidth / 4 * 3, 100, circleIdle, SpriteEffect::Copy{}, true);
		}
		else if (player2CharacterID == 2) {
			gfx.DrawSprite(gfx.ScreenWidth / 4 * 3, 100, aIdle, SpriteEffect::Copy{}, true);
		}
		else if (player2CharacterID == 3) {
			gfx.DrawSprite(gfx.ScreenWidth / 4 * 3, 100, lightningIdle, SpriteEffect::Copy{}, true);
		}
		else if (player2CharacterID == 4) {
			gfx.DrawSprite(gfx.ScreenWidth / 4 * 3, 100, dogIdle, SpriteEffect::Copy{}, true);
		}
		else if (player2CharacterID == 5) {
			gfx.DrawSprite(gfx.ScreenWidth / 4 * 3, 100, chickenIdle, SpriteEffect::Copy{}, true);
		}
		else if (player2CharacterID == 6) {
			gfx.DrawSprite(gfx.ScreenWidth / 4 * 3, 100, rockIdle, SpriteEffect::Copy{}, true);
		}
	}
	else {
		if (paused) {
			gfx.DrawSprite(0, 0, pauseMenu, SpriteEffect::Copy{}, false);
			if (Player1.lives == Player2.lives && Player1.playerPercentage == Player2.playerPercentage) {
				gfx.DrawRect(gfx.ScreenWidth / 2 - Player1.width - 1, 99, gfx.ScreenWidth / 2 + 1, 100 + Player1.height + 1, 255, 199, 0);
				gfx.DrawSprite(gfx.ScreenWidth / 2 - Player1.width, 100, player1Idle, SpriteEffect::Copy{}, false);
				gfx.DrawRect(gfx.ScreenWidth / 2, 99, gfx.ScreenWidth / 2 + Player2.width + 1, 100 + Player2.height + 1, 255, 199, 0);
				gfx.DrawSprite(gfx.ScreenWidth / 2, 100, player2Idle, SpriteEffect::Copy{}, false);
			}
			else if (Player1.lives > Player2.lives || (Player1.lives == Player2.lives && Player1.playerPercentage < Player2.playerPercentage)) {
				gfx.DrawRect(gfx.ScreenWidth / 4 - 1, 349, gfx.ScreenWidth / 4 + Player1.width + 1, 351 + Player1.height, 255, 199, 0);
				gfx.DrawSprite(gfx.ScreenWidth / 4, 350, player1Idle, SpriteEffect::Copy{}, false);
				gfx.DrawRect(gfx.ScreenWidth / 4 * 3 - 1, 349, gfx.ScreenWidth / 4 * 3 + Player2.width + 1, 351 + Player2.height, 255, 199, 0);
				gfx.DrawSprite(gfx.ScreenWidth / 4 * 3, 350, player2Move, SpriteEffect::Copy{}, false);
			}
			else {
				gfx.DrawRect(gfx.ScreenWidth / 4 - 1, 349, gfx.ScreenWidth / 4 + Player2.width + 1, 351 + Player2.height, 255, 199, 0);
				gfx.DrawSprite(gfx.ScreenWidth / 4, 350, player2Idle, SpriteEffect::Copy{}, false);
				gfx.DrawRect(gfx.ScreenWidth / 4 * 3 - 1, 349, gfx.ScreenWidth / 4 * 3 + Player1.width + 1, 351 + Player1.height, 255, 199, 0);
				gfx.DrawSprite(gfx.ScreenWidth / 4 * 3, 350, player1Move, SpriteEffect::Copy{}, false);
			}
		}
		else if (timeUntilStart > 120) {
			gfx.DrawSprite(gfx.ScreenWidth / 2 - 150, gfx.ScreenHeight / 4 - 150, three, SpriteEffect::Copy{}, false);
		}
		else if (timeUntilStart > 60) {
			gfx.DrawSprite(gfx.ScreenWidth / 2 - 150, gfx.ScreenHeight / 4 - 150, two, SpriteEffect::Copy{}, false);
		}
		else if (timeUntilStart > 0) {
			gfx.DrawSprite(gfx.ScreenWidth / 2 - 150, gfx.ScreenHeight / 4 - 150, one, SpriteEffect::Copy{}, false);
		}
		else if (timeGoIsDisplayed > 0) {
			gfx.DrawSprite(gfx.ScreenWidth / 2 - 150, gfx.ScreenHeight / 4 - 150, go, SpriteEffect::Copy{}, false);
		}
		gfx.DrawRect(stageX0, stageY0, stageX1, stageY1, 255, 0, 0); //Stage

		if (Player1.moveDuration > 0) {//If Player 1 is using a move
			gfx.DrawSprite(Player1.x, Player1.y, player1Move, SpriteEffect::Copy{}, !Player1.facingRight);
		}
		else {
			gfx.DrawSprite(Player1.x, Player1.y, player1Idle, SpriteEffect::Copy{}, !Player1.facingRight);
		}
		if (Player2.moveDuration > 0) { //If Player 2 is using a move
			gfx.DrawSprite(Player2.x, Player2.y, player2Move, SpriteEffect::Copy{}, !Player2.facingRight);
		}
		else {
			gfx.DrawSprite(Player2.x, Player2.y, player2Idle, SpriteEffect::Copy{}, !Player2.facingRight);
		}

		if (Player1.MoveDraw(1)) {
			gfx.DrawRect(Player1.MoveX0(1), Player1.MoveY0(1), Player1.MoveX1(1), Player1.MoveY1(1), 255, 255, 255);
		}
		if (Player1.MoveDraw(2)) {
			gfx.DrawRect(Player1.MoveX0(2), Player1.MoveY0(2), Player1.MoveX1(2), Player1.MoveY1(2), 255, 255, 255);
		}
		if (Player1.MoveDraw(3)) {
			gfx.DrawRect(Player1.MoveX0(3), Player1.MoveY0(3), Player1.MoveX1(3), Player1.MoveY1(3), 255, 255, 255);
		}
		if (Player1.MoveDraw(4)) {
			gfx.DrawRect(Player1.MoveX0(4), Player1.MoveY0(4), Player1.MoveX1(4), Player1.MoveY1(4), 255, 255, 255);
		}
		if (Player1.MoveDraw(5)) {
			gfx.DrawRect(Player1.MoveX0(5), Player1.MoveY0(5), Player1.MoveX1(5), Player1.MoveY1(5), 255, 255, 255);
		}

		if (Player2.MoveDraw(1)) {
			gfx.DrawRect(Player2.MoveX0(1), Player2.MoveY0(1), Player2.MoveX1(1), Player2.MoveY1(1), 255, 255, 255);
		}
		if (Player2.MoveDraw(2)) {
			gfx.DrawRect(Player2.MoveX0(2), Player2.MoveY0(2), Player2.MoveX1(2), Player2.MoveY1(2), 255, 255, 255);
		}
		if (Player2.MoveDraw(3)) {
			gfx.DrawRect(Player2.MoveX0(3), Player2.MoveY0(3), Player2.MoveX1(3), Player2.MoveY1(3), 255, 255, 255);
		}
		if (Player2.MoveDraw(4)) {
			gfx.DrawRect(Player2.MoveX0(4), Player2.MoveY0(4), Player2.MoveX1(4), Player2.MoveY1(4), 255, 255, 255);
		}
		if (Player2.MoveDraw(5)) {
			gfx.DrawRect(Player2.MoveX0(5), Player2.MoveY0(5), Player2.MoveX1(5), Player2.MoveY1(5), 255, 255, 255);
		}
	}
}
