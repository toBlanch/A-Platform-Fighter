#include "Game.h"
#include <random>
#include <windows.h>
#include <gdiplus.h>
using namespace Gdiplus;
#include <objidl.h>
#pragma comment(lib, "Winmm.lib")


Game::Game(HDC& hdc)
	:
	gfx(hdc),
	//creditsVisual(L"Credits Menu.bmp"),
	//startVisual(L"Start Menu.bmp"),
	aiWarning(L"AI Warning.bmp"),
	player1Win(L"Player1Win.bmp"),
	player2Win(L"Player2Win.bmp"),
	//pauseVisual(L"Pause Menu.bmp"),
	startThree(L"StartThree.bmp"),
	startTwo(L"StartTwo.bmp"),
	startOne(L"StartOne.bmp"),
	go(L"Go.bmp")
	//circleIdle(L"Circle Idle.bmp"),
	//circleMove(L"Circle Move.bmp"),
	//circleHit(L"Circle Hit.bmp"),
	//circleLives(L"Circle Lives.bmp"),
	//idle()
	/*
	MainMenuTheme(L"MainMenuTheme.wav", 0.0f, 200.0f),
	HitSound(L"hit.wav"),
	CreditsTheme(L"Credits.wav", 0.0f, 225.0f),
	BattleTheme0(L"Battle Theme 0.wav", 0.0f, 236.0f),
	BattleTheme1(L"Battle Theme 1.wav", 0.0f, 232.0f),
	BattleTheme2(L"Battle Theme 2.wav", 0.0f, 147.0f),
	BattleTheme3(L"Battle Theme 3.wav", 0.0f, 159.0f),*/
{
	std::mt19937 rng;
	std::uniform_real_distribution<float> musicDist(0, 3.9);
	std::uniform_real_distribution<float> aiMoveDist(0, 3.9);

	//Initialise idle sprites
	idle[0] = L"CircleIdle.bmp";
	idle[1] = L"aIdle.bmp";
	idle[2] = L"SigmaMonkeyOfDoomIdle.bmp";
	idle[3] = L"DogIdle.bmp";
	idle[4] = L"ChickenIdle.bmp";
	idle[5] = L"RockIdle.bmp";
	idle[6] = L"TrollIdle.bmp";
	idle[7] = L"BigBIdle.bmp";

	//Initialise move sprites
	move[0] = L"Circlemove.bmp";
	move[1] = L"aMove.bmp";
	move[2] = L"SigmaMonkeyOfDoomMove.bmp";
	move[3] = L"DogMove.bmp";
	move[4] = L"ChickenMove.bmp";
	move[5] = L"RockMove.bmp";
	move[6] = L"TrollMove.bmp";
	move[7] = L"BigBMove.bmp";

	//Initialise hit sprites
	hit[0] = L"CircleHit.bmp";
	hit[1] = L"aHit.bmp";
	hit[2] = L"SigmaMonkeyOfDoomHit.bmp";
	hit[3] = L"DogHit.bmp";
	hit[4] = L"ChickenHit.bmp";
	hit[5] = L"RockHit.bmp";
	hit[6] = L"TrollHit.bmp";
	hit[7] = L"BigBHit.bmp";

	//Initialise lives sprites
	lives[0] = L"CircleLivesIcon.bmp";
	lives[1] = L"aLivesIcon.bmp";
	lives[2] = L"SigmaMonkeyOfDoomLivesIcon.bmp";
	lives[3] = L"DogLivesIcon.bmp";
	lives[4] = L"ChickenLivesIcon.bmp";
	lives[5] = L"RockLivesIcon.bmp";
	lives[6] = L"TrollLivesIcon.bmp";
	lives[7] = L"BigBLivesIcon.bmp";
}

void Game::Go(int clientX, int clientY)
{
	gfx.PassClientDimensions(clientX, clientY);
	GameState();
	ComposeFrame();
}

void Game::GameState()
{
	if (credits) {
		if ((GetKeyState(0x0D) & 0x8000 || GetKeyState(0x1B) & 0x8000 && !enterOrEscapeHeld) || (GetKeyState(0x20) & 0x8000 && !spaceHeld)) {
			credits = false;
			//CreditsTheme.StopAll();
		}
	}
	else if (startMenu) {
		StartMenu();
	}
	else if (!paused && timeUntilStart > 0) { //If the game is starting
		timeUntilStart--; //Reduce time until the game starts
	}
	else {
		GameLoop();
	}
	enterOrEscapeHeld = GetKeyState(0x0D) & 0x8000 || GetKeyState(0x1B) & 0x8000; //If enter or escape is held set it to true, otherwise set it to false
	//spaceHeld = GetKeyState(0x20) & 0x8000;
}

void Game::StartMenu()
{
	if (GetKeyState(0xA2) & 0x8000 && GetKeyState(0x20) & 0x8000) {
		abort();
	}
	else if (GetKeyState(0x20) & 0x8000 && !spaceHeld) {
		credits = true; 
		PlaySound(NULL, NULL, 0);
		mainMenuThemeIsPlaying = false;
		PlaySound(L"Credits.wav", NULL, SND_ASYNC | SND_FILENAME);
	}
	else {
		if (!mainMenuThemeIsPlaying) {
			PlaySound(L"MainMenuTheme.wav", NULL, SND_ASYNC | SND_FILENAME);
			mainMenuThemeIsPlaying = true;
		}
		if (GetKeyState(0x45) & 0x8000 && player1CharacterID < 7 && !eHeld) { //If Player 1 wants to increase their character ID
			player1CharacterID++; //Increase it
		}
		if (GetKeyState(0x51) & 0x8000 && player1CharacterID > 0 && !qHeld) { //If Player 1 wants to decrease their character ID
			player1CharacterID--; //Decrease it
		}
		if (GetKeyState(0x50) & 0x8000 && player2CharacterID < 7 && !pHeld) { //If Player 2 wants to increase their character ID
			player2CharacterID++; //Incerase it
		}
		if (GetKeyState(0x49) & 0x8000 && player2CharacterID > 0 && !iHeld) { //If Player 2 wants to decrease their character ID
			player2CharacterID--; //Decrease it
		}

		if (GetKeyState(0x09) & 0x8000 && !tabHeld) {
			AISelected = !AISelected;
		}

		qHeld = GetKeyState(0x51) & 0x8000; //If q is held set it to true, otherwise set it to false
		eHeld = GetKeyState(0x45) & 0x8000; //If e is held set it to true, otherwise set it to false
		iHeld = GetKeyState(0x49) & 0x8000; //If i is held set it to true, otherwise set it to false
		pHeld = GetKeyState(0x50) & 0x8000; //If p is held set it to true, otherwise set it to false
		tabHeld = GetKeyState(0x09) & 0x8000;

		if ((GetKeyState(0x0D) & 0x8000 || GetKeyState(0x1B) & 0x8000) && !enterOrEscapeHeld) { //If the game is starting
			startMenu = false; //Disable the start menu
			GameStart();
			//player1Idle = idle[player1CharacterID]; //Set player 1s idle animation
			//player1Move = move[player1CharacterID]; //Set player 1s move animation
			//player1Hit = hit[player1CharacterID]; //Set player 1s hit animation
			//player1LivesIcon = lives[player1CharacterID]; //Set player 1s lives icon
			Player1.Initialise(parameters[player1CharacterID], stageX0, stageY0, stageX1, stageY1); //Set player 1s variables


			//player2Idle = idle[player2CharacterID]; //Set player 1s idle animation
			//player2Move = move[player2CharacterID]; //Set player 1s move animation
			//player2Hit = hit[player2CharacterID]; //Set player 1s hit animation
			//player2LivesIcon = lives[player2CharacterID]; //Set player 2s lives icon
			Player2.Initialise(parameters[player2CharacterID], stageX0, stageY0, stageX1, stageY1); //Set player 1s variables
		}
	}
}

void Game::StartBattleTheme()
{
	PlaySound(NULL, NULL, 0);
	mainMenuThemeIsPlaying = false;
	int battleMusic = musicDist(rng);
	if (battleMusic == 0) {
		PlaySound(L"Battle Theme 0.wav", NULL, SND_ASYNC | SND_FILENAME);
	}
	else if (battleMusic == 1) {
		PlaySound(L"Battle Theme 1.wav", NULL, SND_ASYNC | SND_FILENAME);
	}
	else if (battleMusic == 2) {
		PlaySound(L"Battle Theme 2.wav", NULL, SND_ASYNC | SND_FILENAME);
	}
	else {
		PlaySound(L"Battle Theme 3.wav", NULL, SND_ASYNC | SND_FILENAME);
	}
}

void Game::GameLoop()
{
	if (paused) {
		if (GetKeyState(0xA2) & 0x8000 && !enterOrEscapeHeld && (GetKeyState(0x0D) & 0x8000 || GetKeyState(0x1B) & 0x8000)) {
			paused = false;
			startMenu = true; //Enable the start menu
			PlaySound(NULL, NULL, 0);
			previousWinner = 0;
		}
		else if (GetKeyState(0xA2) & 0x8000 && GetKeyState(0x52) & 0x8000) { //If the game should be restarted
			GameStart();
		}
		else if (!enterOrEscapeHeld && (GetKeyState(0x0D) & 0x8000 || GetKeyState(0x1B) & 0x8000)) { //If the pause button is pressd
			paused = false; //Unpause the game
		}
	}
	else if (timer == 0) {
		GameEnd();
	}
	else if (Player1.IsAlive(1920, 1080, leniancy) && Player2.IsAlive(1920, 1080, leniancy)) {//If both players are alive
		timer--;
		if (hitStun > 0) {
			hitStun--;
			Player1.OnlyProjectiles(stageX0, stageY0, stageX1, stageY1);
			Player2.OnlyProjectiles(stageX0, stageY0, stageX1, stageY1);
		}
		else {
			if (enterOrEscapeHeld == false && (GetKeyState(0x0D) & 0x8000 || GetKeyState(0x1B) & 0x8000)) { //If the pause button is pressed
				timeUntilStart = 180; //Initialise the countdown
				timeGoIsDisplayed = 60; //Initialise go
				paused = true; //Pause the game
			}

			if (timeGoIsDisplayed > 0) { //If go should be displayed
				timeGoIsDisplayed--; //Reduce the time go should be displayed
			}

			//Update models
			Player1.UpdateCharacter(GetKeyState(0x41) & 0x8000, GetKeyState(0x44) & 0x8000, GetKeyState(0x53) & 0x8000, GetKeyState(0x57) & 0x8000, GetKeyState(0x47) & 0x8000, GetKeyState(0x46) & 0x8000, GetKeyState(0x54) & 0x8000, GetKeyState(0x48) & 0x8000, GetKeyState(0xA0) & 0x8000, Player2.width, Player2.height, stageX0, stageY0, stageX1, stageY1);
			if (AISelected) {
				int aiSelectedMove = 12 + (int)aiMoveDist(rng);
				ArtifialFriend.Update(Player1.x, Player1.y, Player1.width, Player1.height, Player2.x, Player2.y, Player2.width, Player2.height, Player2.invincibilityCooldown == 0, Player2.vy, Player2.doubleJump, stageX0, stageY0, stageX1, stageY1, aiMoveDist(rng));
				Player2.UpdateCharacter(ArtifialFriend.left, ArtifialFriend.right, ArtifialFriend.down, ArtifialFriend.up, ArtifialFriend.jump, ArtifialFriend.light, ArtifialFriend.heavy, ArtifialFriend.special, ArtifialFriend.dodge, Player1.width, Player1.height, stageX0, stageY0, stageX1, stageY1);
			}
			else {
				Player2.UpdateCharacter(GetKeyState(0x25) & 0x8000, GetKeyState(0x27) & 0x8000, GetKeyState(0x28) & 0x8000, GetKeyState(0x26) & 0x8000, GetKeyState(0x4C) & 0x8000, GetKeyState(0x4B) & 0x8000, GetKeyState(0x4F) & 0x8000, GetKeyState(0xBA) & 0x8000, GetKeyState(0x4E) & 0x8000, Player1.width, Player1.height, stageX0, stageY0, stageX1, stageY1);
			}

		}
		if (Player1.IsMoveColliding(Player2.x, Player2.y, Player2.width, Player2.height)) { //Is player 1 hitting any move
			//mciSendStringA("open \"hit.mp3\" type mpegvideo alias hit", NULL, 0, NULL);
			//mciSendStringA("play hit", NULL, 0, NULL);
			PlaySound(L"hit.wav", NULL, SND_ASYNC | SND_FILENAME);
			hitStun = Player1.MoveThatHitDamage() * 2; //Hit stun activation
			Player2.IsHit(Player1.MoveThatHitStun(), Player1.MoveThatHitDamage(), Player1.MoveThatHitFixedX(), Player1.MoveThatHitFixedY(), Player1.MoveThatHitScalarX(), Player1.MoveThatHitScalarY()); //Register that player 2 has been hit
		}
		if (Player2.IsMoveColliding(Player1.x, Player1.y, Player1.width, Player1.height)) { //Is player 2 hitting any move
			//mciSendStringA("open \"hit.mp3\" type mpegvideo alias hit", NULL, 0, NULL);
			//mciSendStringA("play hit", NULL, 0, NULL);
			PlaySound(L"hit.wav", NULL, SND_ASYNC | SND_FILENAME);
			hitStun = Player2.MoveThatHitDamage() * 2; //Hit stun activation
			Player1.IsHit(Player2.MoveThatHitStun(), Player2.MoveThatHitDamage(), Player2.MoveThatHitFixedX(), Player2.MoveThatHitFixedY(), Player2.MoveThatHitScalarX(), Player2.MoveThatHitScalarY()); //Register that player 1 has been hit
		}
	}
	else {
		GameEnd();
	}
}

void Game::GameStart()
{
	timer = 10 * 60 * 60 - 1;
	StartBattleTheme();
	Player1.x = 1920 / 4 + 100; //Set player 1s starting position
	Player1.facingRight = true;
	Player1.Restart();
	Player2.x = 1920 / 4 * 3 - Player2.width - 100; //Set player 2s starting position
	Player2.facingRight = false;
	Player2.Restart();
	timeUntilStart = 180;
	timeGoIsDisplayed = 60;
	paused = false;
}

void Game::GameEnd()
{
	startMenu = true; //Enable the start menu
	//BattleTheme0.StopAll();
	//BattleTheme1.StopAll();
	//BattleTheme2.StopAll();
	//BattleTheme3.StopAll();
	if (Player2.lives < Player1.lives || (Player1.lives == Player2.lives && Player1.playerPercentage < Player2.playerPercentage)) { //Set the previous winner
		previousWinner = 1;
	}
	else if (Player1.lives < Player2.lives || (Player1.lives == Player2.lives && Player2.playerPercentage < Player1.playerPercentage)) {
		previousWinner = 2;
	}
	else {
		previousWinner = 0;
	}
}

void Game::ComposeFrame()
{
	gfx.Clear();
	if (credits) {
		/*
		Song credits:
		Post-Adventure Tea Party, Zane Little, Free Music Archive, CC BY-NC
		Terrible song in 100 bpm, Lundstroem, Free Music Archive ,CC BY-NC
		All Star, Beat Mekanik, Free Music Archive, CC BY-NC
		Sinister Abode, Zane Little, Free Music Archive, CC BY-NC
		The March Of The Dragon Hunters, Kathrin Klimek, Free Music Archive, CC BY-NC
		Regeneration, Audioezout, Free Music Archive, CC BY-NC

		Character Credits:
		Slot 1 (Circle), Original
		Slot 2 (a), Sprites designed and drawn by Henry Exworthy
		Slot 3 (Sigma Monkey of Doom), Sprites designed and drawn by anonymous
		Slot 4 (Dog), Visual concept by Max Sullivan
		Slot 5 (Chicken), Visual concept by Elliot Ody, Moveset design by anonymous
		Slot 6 (Rock), Concept by Joshua Thorpe
		Slot 7 (Troll), Sprites designed and drawn by Arthur
		Slot 8 (Big B), Sprites designed and drawn by Elliot Ody, Moveset design by Elliot Ody

		Coding:
		Original framework - https://github.com/planetchili/chili_framework
		GDI+ model - https://learn.microsoft.com/en-us/windows/win32/gdiplus/-gdiplus-gdi-start
		DirectX model - https://youtube.com/playlist?list=PLKK11Ligqitij8r6hd6tfqqesh3T_xWJA&si=0ODR_FpQVGcQTN7k
		*/

		//gfx.DrawSprite(0, 0, creditsVisual, false);
	}
	else if (startMenu) {
		//Player 1 controls
		gfx.DrawTextW(134, 524, L"Player 1:");
		gfx.DrawTextW(134, 564, L"Move with WASD");
		gfx.DrawTextW(134, 604, L"Jump with G");
		gfx.DrawTextW(134, 644, L"Light attack with F");
		gfx.DrawTextW(134, 684, L"Heavy attack with T");
		gfx.DrawTextW(134, 724, L"Special attack with H");
		gfx.DrawTextW(134, 764, L"Dodge with left shift");

		//Player 2 controls
		gfx.DrawTextW(1398, 524, L"Player 2:");
		gfx.DrawTextW(1398, 564, L"Move with arrow keys");
		gfx.DrawTextW(1398, 604, L"Jump with L");
		gfx.DrawTextW(1398, 644, L"Light attack with K");
		gfx.DrawTextW(1398, 684, L"Heavy attack with O");
		gfx.DrawTextW(1398, 724, L"Special attack with ;");
		gfx.DrawTextW(1398, 764, L"Dodge with N");

		//Credits
		gfx.DrawTextW(490, 880, L"Press space to see the credits");
		gfx.DrawTextW(490, 940, L"Press alt+f4 to close the game");

		gfx.DrawTextW(134, 644, L"Light attack with F");
		gfx.DrawTextW(134, 684, L"Heavy attack with T");
		gfx.DrawTextW(134, 724, L"Special attack with H");
		gfx.DrawTextW(134, 764, L"Dodge with left shift");

		gfx.DrawTextW(600, 90, L"Press Q and E to switch characters");
		gfx.DrawTextW(900, 90, L"Press I and P to switch characters");

		//gfx.DrawSprite(0, 0, startVisual, false); //Displays the visual for the start menu

		if (AISelected) {
			gfx.DrawSprite(1600, 100, aiWarning, false);
		}

		if (previousWinner == 1) { //If Player 1 won the last match
			gfx.DrawSprite(1920 / 2 - 250, 500, player1Win, false); //Dislpay a sprite that shows this
		}
		else if (previousWinner == 2) { //If player 2 won the last match
			gfx.DrawSprite(1920 / 2 - 250, 500, player2Win, false); //Dislpay a sprite that shows this
		}

		Image idlePlayer1(idle[player1CharacterID].c_str());
		gfx.DrawSprite(1920 / 4, 100, idlePlayer1, false); //Draws an appropriate sprite based on character ID in the start menu
		Image idlePlayer2(idle[player2CharacterID].c_str());
		gfx.DrawSprite(1920 / 4 * 3, 100, idlePlayer2, true); //Draws an appropriate sprite based on character ID in the start menu
	}
	else {
		if (paused) {
			gfx.DrawTextW(0, 0, L"Press ctrl+r to restart the battle");
			gfx.DrawTextW(0, 0, L"Press ctrl+enter/esc to go to the main menu");
			gfx.DrawTextW(880, 200, L"Paused");
			gfx.DrawTextW(0, 0, L"");
			gfx.DrawTextW(0, 0, L"");
			gfx.DrawTextW(0, 0, L"");
			gfx.DrawTextW(0, 0, L"");

			//Player 1 controls
			gfx.DrawTextW(134, 524, L"Player 1:");
			gfx.DrawTextW(134, 564, L"Move with WASD");
			gfx.DrawTextW(134, 604, L"Jump with G");
			gfx.DrawTextW(134, 644, L"Light attack with F");
			gfx.DrawTextW(134, 684, L"Heavy attack with T");
			gfx.DrawTextW(134, 724, L"Special attack with H");
			gfx.DrawTextW(134, 764, L"Dodge with left shift");

			//Player 2 controls
			gfx.DrawTextW(1398, 524, L"Player 2:");
			gfx.DrawTextW(1398, 564, L"Move with arrow keys");
			gfx.DrawTextW(1398, 604, L"Jump with L");
			gfx.DrawTextW(1398, 644, L"Light attack with K");
			gfx.DrawTextW(1398, 684, L"Heavy attack with O");
			gfx.DrawTextW(1398, 724, L"Special attack with ;");
			gfx.DrawTextW(1398, 764, L"Dodge with N");

			//gfx.DrawSprite(0, 0, pauseVisual, false); //Display the pause menu

			if (Player1.lives == Player2.lives && Player1.playerPercentage == Player2.playerPercentage) { //If both players are even
				gfx.DrawRect(1920 / 2 - Player1.width - 1, 99, 1920 / 2 + 1, 100 + Player1.height + 1, 255, 199, 0); //Player 1 border
				Image player1PauseMenu(idle[player1CharacterID].c_str());
				gfx.DrawSprite(1920 / 2 - Player1.width, 100, player1PauseMenu, false); //Display player 1 at the top of the screen
				gfx.DrawRect(1920 / 2, 99, 1920 / 2 + Player2.width + 1, 100 + Player2.height + 1, 255, 199, 0); //Player 2 border
				Image player2PauseMenu(idle[player2CharacterID].c_str());
				gfx.DrawSprite(1920 / 2, 100, player2PauseMenu, false); //Display player 2 at the top of the screen
			}
			else if (Player1.lives > Player2.lives || (Player1.lives == Player2.lives && Player1.playerPercentage < Player2.playerPercentage)) {
				gfx.DrawRect(1920 / 4 - 1, 349, 1920 / 4 + Player1.width + 1, 351 + Player1.height, 255, 199, 0); //Player 1 border
				Image player1PauseMenu(idle[player1CharacterID].c_str());
				gfx.DrawSprite(1920 / 4, 350, player1PauseMenu, false); //Display player 1 on the left side
				gfx.DrawRect(1920 / 4 * 3 - 1, 349, 1920 / 4 * 3 + Player2.width + 1, 351 + Player2.height, 255, 199, 0); //Player 2 border
				Image player2PauseMenu(hit[player2CharacterID].c_str());
				gfx.DrawSprite(1920 / 4 * 3, 350, player2PauseMenu, false); //Display player 2 on the right side
			}
			else {
				gfx.DrawRect(1920 / 4 - 1, 349, 1920 / 4 + Player2.width + 1, 351 + Player2.height, 255, 199, 0); //Player 1 border
				Image player2PauseMenu(idle[player2CharacterID].c_str());
				gfx.DrawSprite(1920 / 4, 350, player2PauseMenu, false); //Display player 2 on the left side
				gfx.DrawRect(1920 / 4 * 3 - 1, 349, 1920 / 4 * 3 + Player1.width + 1, 351 + Player1.height, 255, 199, 0); //Player 2 border
				Image player1PauseMenu(hit[player1CharacterID].c_str());
				gfx.DrawSprite(1920 / 4 * 3, 350, player1PauseMenu, false); //Display player 1 on the right side
			}
		}

		else if (timeUntilStart > 120) { //If you should display 3
			gfx.DrawSprite(1920 / 2 - 150, 1080 / 4 - 150, startThree, false); //Display 3
		}
		else if (timeUntilStart > 60) { //If you should display 2
			gfx.DrawSprite(1920 / 2 - 150, 1080 / 4 - 150, startTwo, false); //Display 2
		}
		else if (timeUntilStart > 0) { //If you should display 1
			gfx.DrawSprite(1920 / 2 - 150, 1080 / 4 - 150, startOne, false); //Display 1
		}
		else if (timeGoIsDisplayed > 0) { //If you should display go
			gfx.DrawSprite(1920 / 2 - 150, 1080 / 4 - 150, go, false); //Display go
		}

		gfx.DrawRect(stageX0, stageY0, stageX1, stageY1, 255, 0, 0); //Stage

		gfx.DrawTextW(1920 / 4, 900, std::to_wstring(Player1.playerPercentage));
		gfx.DrawTextW(1920 / 4 * 3, 900, std::to_wstring(Player2.playerPercentage));

		if (AISelected) {
			gfx.DrawSprite(1920 / 4 * 3 + 120, 900, aiWarning, false);
		}

		if (Player1.invincibility > 0) { //If player 1 has invincibility
			gfx.DrawRect(Player1.x - 1, Player1.y - 1, Player1.x + Player1.width + 1, Player1.y + Player1.height + 1, 0, 237, 255); //Give them a border
		}
		if (Player2.invincibility > 0) { //If player 2 has invincibility
			gfx.DrawRect(Player2.x - 1, Player2.y - 1, Player2.x + Player2.width + 1, Player2.y + Player2.height + 1, 0, 237, 255); //Give them a border
		}

		if (Player1.moveDuration > 0 || Player1.freeFallDuration > 0) { //If Player 1 is using a move
			Image player1Sprite(move[player1CharacterID].c_str());
			gfx.DrawSprite(Player1.x, Player1.y, player1Sprite, !Player1.facingRight); //Display normal animation
		}
		else if (Player1.stun > 0) { //If player 1 is in stun
			Image player1Sprite(hit[player1CharacterID].c_str());
			gfx.DrawSprite(Player1.x, Player1.y, player1Sprite, !Player1.facingRight); //Display normal animation
		}
		else {
			Image player1Sprite(idle[player1CharacterID].c_str());
			gfx.DrawSprite(Player1.x, Player1.y, player1Sprite, !Player1.facingRight); //Display normal animation
		}

		if (Player2.moveDuration > 0 || Player2.freeFallDuration > 0) { //If Player 1 is using a move
			Image Player2Sprite(move[player2CharacterID].c_str());
			gfx.DrawSprite(Player2.x, Player2.y, Player2Sprite, !Player2.facingRight); //Display normal animation
		}
		else if (Player2.stun > 0) { //If player 1 is in stun
			Image Player2Sprite(hit[player2CharacterID].c_str());
			gfx.DrawSprite(Player2.x, Player2.y, Player2Sprite, !Player2.facingRight); //Display normal animation
		}
		else {
			Image Player2Sprite(idle[player2CharacterID].c_str());
			gfx.DrawSprite(Player2.x, Player2.y, Player2Sprite, !Player2.facingRight); //Display normal animation
		}


		for (int i = 0; i < 5; i++) { //For every move
			if (Player1.MoveDraw(i)) { //If it can be drawn
				gfx.DrawRect(Player1.MoveX0(i), Player1.MoveY0(i), Player1.MoveX1(i), Player1.MoveY1(i), Player1.MoveR(i), Player1.MoveG(i), Player1.MoveB(i)); //Draw it
			}
			if (Player2.MoveDraw(i)) { //If it can be drawn
				gfx.DrawRect(Player2.MoveX0(i), Player2.MoveY0(i), Player2.MoveX1(i), Player2.MoveY1(i), Player2.MoveR(i), Player2.MoveG(i), Player2.MoveB(i)); //Draw it
			}
		}
		
		gfx.DrawTextW(1920 / 2 - 15, 85, std::to_wstring((int)timer / 60));
	}
}