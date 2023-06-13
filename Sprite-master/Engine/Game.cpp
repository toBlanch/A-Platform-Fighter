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

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
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
	if (Player1.IsAlive(gfx.ScreenWidth, gfx.ScreenHeight, leniancy) && Player2.IsAlive(gfx.ScreenWidth, gfx.ScreenHeight, leniancy)) {//If both players are alive
		Player1.UpdateCharacter(wnd.kbd.KeyIsPressed(VK_LEFT), wnd.kbd.KeyIsPressed(VK_RIGHT), wnd.kbd.KeyIsPressed(VK_DOWN), wnd.kbd.KeyIsPressed(0x4C), wnd.kbd.KeyIsPressed(0x4B), wnd.kbd.KeyIsPressed(0x4F), wnd.kbd.KeyIsPressed(VK_OEM_1), stageX0, stageY0, stageX1, stageY1);
		Player2.UpdateCharacter(wnd.kbd.KeyIsPressed(0x41), wnd.kbd.KeyIsPressed(0x44), wnd.kbd.KeyIsPressed(0x53), wnd.kbd.KeyIsPressed(0x47), wnd.kbd.KeyIsPressed(0x46), wnd.kbd.KeyIsPressed(0x54), wnd.kbd.KeyIsPressed(0x48), stageX0, stageY0, stageX1, stageY1);
		if (Player1.IsMoveColliding(Player2.x, Player2.y, Player2.width, Player2.height)) {
			Player2.IsHit(Player1.MoveThatHitStun(), Player1.MoveThatHitDamage(), Player1.MoveThatHitFixedX(), Player1.MoveThatHitFixedY(), Player1.MoveThatHitScalarX(), Player1.MoveThatHitScalarY());
		}
		if (Player2.IsMoveColliding(Player1.x, Player1.y, Player1.width, Player1.height)) {
			Player1.IsHit(Player2.MoveThatHitStun(), Player2.MoveThatHitDamage(), Player2.MoveThatHitFixedX(), Player2.MoveThatHitFixedY(), Player2.MoveThatHitScalarX(), Player2.MoveThatHitScalarY());
		}
	}
	else{
		Player1.x = 500;
		Player1.y = 500;
		Player2.x = 800;
		Player2.y = 500;
		Player1.lives = 3;
		Player2.lives = 3;
	}
}

void Game::ComposeFrame()
{
	gfx.DrawRect(stageX0, stageY0, stageX1, stageY1, 255,0,0); //Stage
	if (Player1.moveDuration > 0) {
		gfx.DrawSprite(Player1.x, Player1.y, circleMove, SpriteEffect::Copy{}, !Player1.facingRight);
	}
	else {
		gfx.DrawSprite(Player1.x, Player1.y, circleIdle, SpriteEffect::Copy{}, !Player1.facingRight);
	}
	if (Player2.moveDuration > 0) {
		gfx.DrawSprite(Player2.x, Player2.y, aMove, SpriteEffect::Copy{}, !Player2.facingRight);
	}
	else {
		gfx.DrawSprite(Player2.x, Player2.y, aIdle, SpriteEffect::Copy{}, !Player2.facingRight);
	}
	if (Player1.MoveDraw(1)) {
		gfx.DrawRect(Player1.MoveX0(1), Player1.MoveY0(1), Player1.MoveX1(1), Player1.MoveY1(1), 255,255,255);
	}
	if (Player2.MoveDraw(1)) {
		gfx.DrawRect(Player2.MoveX0(1), Player2.MoveY0(1), Player2.MoveX1(1), Player2.MoveY1(1), 255,255,255);
	}
}
