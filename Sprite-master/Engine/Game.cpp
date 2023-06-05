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
	Player1.UpdateCharacter(wnd.kbd.KeyIsPressed(VK_LEFT), wnd.kbd.KeyIsPressed(VK_RIGHT), wnd.kbd.KeyIsPressed(VK_DOWN), wnd.kbd.KeyIsPressed(0x4C));
	Player2.UpdateCharacter(wnd.kbd.KeyIsPressed(0x41), wnd.kbd.KeyIsPressed(0x44), wnd.kbd.KeyIsPressed(0x53), wnd.kbd.KeyIsPressed(0x47));
	if (wnd.kbd.KeyIsPressed(0x52)) {
		Player1.y = 500;
		Player2.y = 500;
	}
}

void Game::ComposeFrame()
{
	gfx.DrawRect(500, 800, 1420, 980, (255, 255, 255));
	gfx.DrawSprite(Player1.x, Player1.y, circle, SpriteEffect::Copy{});
	gfx.DrawSprite(Player2.x, Player2.y, a, SpriteEffect::Copy{});
}
