#include "Game.h"
#include <windows.h>


Game::Game(Graphics* gfx)
	:
	randomDist(0, 39),
	rng( rd( ) )
{
	this->gfx = gfx;

	//Load menu sprites
	aiWarning = new SpriteSheet(L"AI Warning.bmp", gfx);
	creditsVisual = new SpriteSheet(L"Credits Menu.bmp", gfx);
	startVisual = new SpriteSheet(L"Start Menu.bmp", gfx);
	player1Win = new SpriteSheet(L"Player1Win.bmp", gfx);
	player2Win = new SpriteSheet(L"Player2Win.bmp", gfx);
	pauseVisual = new SpriteSheet(L"Pause Menu.bmp", gfx);
	startThree = new SpriteSheet(L"StartThree.bmp", gfx);
	startTwo = new SpriteSheet(L"StartTwo.bmp", gfx);
	startOne = new SpriteSheet(L"StartOne.bmp", gfx);
	go = new SpriteSheet(L"Go.bmp", gfx);

	//Initialise numbers
	numbers[0] = new SpriteSheet(L"0.bmp", gfx);
	numbers[1] = new SpriteSheet(L"1.bmp", gfx);
	numbers[2] = new SpriteSheet(L"2.bmp", gfx);
	numbers[3] = new SpriteSheet(L"3.bmp", gfx);
	numbers[4] = new SpriteSheet(L"4.bmp", gfx);
	numbers[5] = new SpriteSheet(L"5.bmp", gfx);
	numbers[6] = new SpriteSheet(L"6.bmp", gfx);
	numbers[7] = new SpriteSheet(L"7.bmp", gfx);
	numbers[8] = new SpriteSheet(L"8.bmp", gfx);
	numbers[9] = new SpriteSheet(L"9.bmp", gfx);

	//Initialise idle sprites
	idleParameters[0] = L"CircleIdle.bmp";
	idleParameters[1] = L"aIdle.bmp";
	idleParameters[2] = L"SigmaMonkeyOfDoomIdle.bmp";
	idleParameters[3] = L"DogIdle.bmp";
	idleParameters[4] = L"ChickenIdle.bmp";
	idleParameters[5] = L"RockIdle.bmp";
	idleParameters[6] = L"TrollIdle.bmp";
	idleParameters[7] = L"BigBIdle.bmp";
	idleParameters[8] = L"Random.bmp";

	//Initialise move sprites
	moveParameters[0] = L"Circlemove.bmp";
	moveParameters[1] = L"aMove.bmp";
	moveParameters[2] = L"SigmaMonkeyOfDoomMove.bmp";
	moveParameters[3] = L"DogMove.bmp";
	moveParameters[4] = L"ChickenMove.bmp";
	moveParameters[5] = L"RockMove.bmp";
	moveParameters[6] = L"TrollMove.bmp";
	moveParameters[7] = L"BigBMove.bmp";

	//Initialise hit sprites
	hitParameters[0] = L"CircleHit.bmp";
	hitParameters[1] = L"aHit.bmp";
	hitParameters[2] = L"SigmaMonkeyOfDoomHit.bmp";
	hitParameters[3] = L"DogHit.bmp";
	hitParameters[4] = L"ChickenHit.bmp";
	hitParameters[5] = L"RockHit.bmp";
	hitParameters[6] = L"TrollHit.bmp";
	hitParameters[7] = L"BigBHit.bmp";

	//Initialise lives sprites
	livesIconParameters[0] = L"CircleLivesIcon.bmp";
	livesIconParameters[1] = L"aLivesIcon.bmp";
	livesIconParameters[2] = L"SigmaMonkeyOfDoomLivesIcon.bmp";
	livesIconParameters[3] = L"DogLivesIcon.bmp";
	livesIconParameters[4] = L"ChickenLivesIcon.bmp";
	livesIconParameters[5] = L"RockLivesIcon.bmp";
	livesIconParameters[6] = L"TrollLivesIcon.bmp";
	livesIconParameters[7] = L"BigBLivesIcon.bmp";

	//Initialise sounds
	mciSendStringA("open \"hit.avi\" type mpegvideo alias hit", NULL, 0, NULL);
	mciSendStringA("open \"Credits.wav\" type mpegvideo alias Credits", NULL, 0, NULL);
	mciSendStringA("open \"MainMenuTheme.wav\" type mpegvideo alias MainMenu", NULL, 0, NULL);

	//Play starting music
	mciSendStringA("play MainMenu repeat", NULL, 0, NULL);

	//Initialise menu idle sprites
	player1Idle = new SpriteSheet(idleParameters[player1CharacterID], gfx); //Set player 1s idle animation
	player2Idle = new SpriteSheet(idleParameters[player2CharacterID], gfx); //Set player 1s idle animation
}

void Game::Go()
{
	GameState();
	ComposeFrame();
}

void Game::GameState()
{
	if (credits) {
		if ((gfx->ifFocus() && GetKeyState(0x0D) & 0x8000 || gfx->ifFocus() && GetKeyState(0x1B) & 0x8000 && !enterOrEscapeHeld) || (gfx->ifFocus() && GetKeyState(0x20) & 0x8000 && !spaceHeld)) {
			credits = false;
			mciSendStringA("stop Credits", NULL, 0, NULL);
			mciSendStringA("play MainMenu from 0 repeat", NULL, 0, NULL);
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
	enterOrEscapeHeld = gfx->ifFocus() && GetKeyState(0x0D) & 0x8000 || gfx->ifFocus() && GetKeyState(0x1B) & 0x8000; //If enter or escape is held set it to true, otherwise set it to false
	spaceHeld = gfx->ifFocus() && GetKeyState(0x20) & 0x8000;
}

void Game::StartMenu()
{
	if (gfx->ifFocus() && GetKeyState(0xA2) & 0x8000 && gfx->ifFocus() && GetKeyState(0x20) & 0x8000 && !spaceHeld) {
		gfx->Fullscreen();
	}
	else if (gfx->ifFocus() && GetKeyState(0x20) & 0x8000 && !spaceHeld) {
		credits = true;
		mciSendStringA("stop MainMenu", NULL, 0, NULL);
		mciSendStringA("play Credits from 0 repeat", NULL, 0, NULL);
	}
	else {
		if (gfx->ifFocus() && GetKeyState(0x45) & 0x8000 && player1CharacterID < 8 && !eHeld) { //If Player 1 wants to increase their character ID
			player1CharacterID++; //Increase it
			player1Idle -> ~SpriteSheet();
			player1Idle = new SpriteSheet(idleParameters[player1CharacterID], gfx); //Set player 1s idle animation
		}
		if (gfx->ifFocus() && GetKeyState(0x51) & 0x8000 && player1CharacterID > 0 && !qHeld) { //If Player 1 wants to decrease their character ID
			player1CharacterID--; //Decrease it
			player1Idle -> ~SpriteSheet();
			player1Idle = new SpriteSheet(idleParameters[player1CharacterID], gfx); //Set player 1s idle animation
		}
		if (gfx->ifFocus() && GetKeyState(0x50) & 0x8000 && player2CharacterID < 8 && !pHeld) { //If Player 2 wants to increase their character ID
			player2CharacterID++; //Incerase it
			player2Idle -> ~SpriteSheet();
			player2Idle = new SpriteSheet(idleParameters[player2CharacterID], gfx); //Set player 1s idle animation
		}
		if (gfx->ifFocus() && GetKeyState(0x49) & 0x8000 && player2CharacterID > 0 && !iHeld) { //If Player 2 wants to decrease their character ID
			player2CharacterID--; //Decrease it
			player2Idle -> ~SpriteSheet();
			player2Idle = new SpriteSheet(idleParameters[player2CharacterID], gfx); //Set player 1s idle animation
		}

		if (gfx->ifFocus() && GetKeyState(0x09) & 0x8000 && !tabHeld) {
			AISelected = !AISelected;
		}

		qHeld = gfx->ifFocus() && GetKeyState(0x51) & 0x8000; //If q is held set it to true, otherwise set it to false
		eHeld = gfx->ifFocus() && GetKeyState(0x45) & 0x8000; //If e is held set it to true, otherwise set it to false
		iHeld = gfx->ifFocus() && GetKeyState(0x49) & 0x8000; //If i is held set it to true, otherwise set it to false
		pHeld = gfx->ifFocus() && GetKeyState(0x50) & 0x8000; //If p is held set it to true, otherwise set it to false
		tabHeld = gfx->ifFocus() && GetKeyState(0x09) & 0x8000;

		if ((gfx->ifFocus() && GetKeyState(0x0D) & 0x8000 || gfx->ifFocus() && GetKeyState(0x1B) & 0x8000) && !enterOrEscapeHeld) { //If the game is starting
			startMenu = false; //Disable the start menu
			GameStart();
			if (player1CharacterID == 8) {
				player1CharacterID = 1 + (float)randomDist(rng) * 6.9f / 39;
				player1Idle = new SpriteSheet(idleParameters[player1CharacterID], gfx); //Set player 1s idle animation
			}
			player1Move = new SpriteSheet(moveParameters[player1CharacterID], gfx); //Set player 1s move animation
			player1Hit = new SpriteSheet(hitParameters[player1CharacterID], gfx); //Set player 1s hit animation
			player1LivesIcon = new SpriteSheet(livesIconParameters[player1CharacterID], gfx); //Set player 2s lives icon
			Player1.Initialise(parameters[player1CharacterID], stageX0, stageY0, stageX1, stageY1); //Set player 1s variables

			if (player2CharacterID == 8) {
				player2CharacterID = 1 + (float)randomDist(rng) * 6.9f / 39;
				player2Idle = new SpriteSheet(idleParameters[player2CharacterID], gfx); //Set player 1s idle animation
			}
			player2Move = new SpriteSheet(moveParameters[player2CharacterID], gfx); //Set player 1s move animation
			player2Hit = new SpriteSheet(hitParameters[player2CharacterID], gfx); //Set player 1s hit animation
			player2LivesIcon = new SpriteSheet(livesIconParameters[player2CharacterID], gfx); //Set player 2s lives icon
			Player2.Initialise(parameters[player2CharacterID], stageX0, stageY0, stageX1, stageY1); //Set player 1s variables
		}
	}
}

void Game::StartBattleTheme()
{
	mciSendStringA("stop MainMenu", NULL, 0, NULL);
	mciSendStringA("stop BattleTheme", NULL, 0, NULL);
	mciSendStringA("close BattleTheme", NULL, 0, NULL);
	int battleMusic = randomDist(rng);
	if (battleMusic <= 10) {
		mciSendStringA("open \"Battle Theme 0.wav\" type mpegvideo alias BattleTheme", NULL, 0, NULL);
	}
	else if (battleMusic <= 20) {
		mciSendStringA("open \"Battle Theme 1.wav\" type mpegvideo alias BattleTheme", NULL, 0, NULL);
	}
	else if (battleMusic <= 30) {
		mciSendStringA("open \"Battle Theme 2.wav\" type mpegvideo alias BattleTheme", NULL, 0, NULL);
	}
	else {
		mciSendStringA("open \"Battle Theme 3.wav\" type mpegvideo alias BattleTheme", NULL, 0, NULL);
	}
	mciSendStringA("play BattleTheme from 0 repeat", NULL, 0, NULL);
}

void Game::GameLoop()
{
	if (paused) {
		if (gfx->ifFocus() && GetKeyState(0xA2) & 0x8000 && !enterOrEscapeHeld && (gfx->ifFocus() && GetKeyState(0x0D) & 0x8000 || gfx->ifFocus() && GetKeyState(0x1B) & 0x8000)) {
			paused = false;
			GameEnd();
			previousWinner = 0;
			mciSendStringA("stop BattleTheme0", NULL, 0, NULL);
			mciSendStringA("stop BattleTheme1", NULL, 0, NULL);
			mciSendStringA("stop BattleTheme2", NULL, 0, NULL);
			mciSendStringA("stop BattleTheme3", NULL, 0, NULL);
			mciSendStringA("play MainMenu from 0 repeat", NULL, 0, NULL);
		}
		else if (gfx->ifFocus() && GetKeyState(0xA2) & 0x8000 && gfx->ifFocus() && GetKeyState(0x52) & 0x8000) { //If the game should be restarted
			GameStart();
		}
		else if (!enterOrEscapeHeld && (gfx->ifFocus() && GetKeyState(0x0D) & 0x8000 || gfx->ifFocus() && GetKeyState(0x1B) & 0x8000)) { //If the pause button is pressd
			paused = false; //Unpause the game
		}
	}
	else if (timer == 0) {
		GameEnd();
	}
	else if (Player1.IsAlive(1920, 1080, leniancy) && Player2.IsAlive(1920, 1080, leniancy)) {//If both players are alive
		timer--;
		if (enterOrEscapeHeld == false && (gfx->ifFocus() && GetKeyState(0x0D) & 0x8000 || gfx->ifFocus() && GetKeyState(0x1B) & 0x8000)) { //If the pause button is pressed
			timeUntilStart = 180; //Initialise the countdown
			timeGoIsDisplayed = 60; //Initialise go
			paused = true; //Pause the game
		}

		if (timeGoIsDisplayed > 0) { //If go should be displayed
			timeGoIsDisplayed--; //Reduce the time go should be displayed
		}

		//Update models
		Player1.UpdateCharacter(gfx->ifFocus() && GetKeyState(0x41) & 0x8000, gfx->ifFocus() && GetKeyState(0x44) & 0x8000, gfx->ifFocus() && GetKeyState(0x53) & 0x8000, gfx->ifFocus() && GetKeyState(0x57) & 0x8000, gfx->ifFocus() && GetKeyState(0x47) & 0x8000, gfx->ifFocus() && GetKeyState(0x46) & 0x8000, gfx->ifFocus() && GetKeyState(0x54) & 0x8000, gfx->ifFocus() && GetKeyState(0x48) & 0x8000, gfx->ifFocus() && GetKeyState(0xA0) & 0x8000, Player2.width, Player2.height, stageX0, stageY0, stageX1, stageY1);
		if (AISelected) {
			ArtifialFriend.Update(Player1.x, Player1.y, Player1.width, Player1.height, Player2.x, Player2.y, Player2.width, Player2.height, Player2.invincibilityCooldown == 0, Player2.vy, Player2.doubleJump, stageX0, stageY0, stageX1, stageY1, randomDist(rng), Player1.playerPercentage);
			Player2.UpdateCharacter(ArtifialFriend.left, ArtifialFriend.right, ArtifialFriend.down, ArtifialFriend.up, ArtifialFriend.jump, ArtifialFriend.light, ArtifialFriend.heavy, ArtifialFriend.special, ArtifialFriend.dodge, Player1.width, Player1.height, stageX0, stageY0, stageX1, stageY1);
		}
		else {
			Player2.UpdateCharacter(gfx->ifFocus() && GetKeyState(0x25) & 0x8000, gfx->ifFocus() && GetKeyState(0x27) & 0x8000, gfx->ifFocus() && GetKeyState(0x28) & 0x8000, gfx->ifFocus() && GetKeyState(0x26) & 0x8000, gfx->ifFocus() && GetKeyState(0x4C) & 0x8000, gfx->ifFocus() && GetKeyState(0x4B) & 0x8000, gfx->ifFocus() && GetKeyState(0x4F) & 0x8000, gfx->ifFocus() && GetKeyState(0xBA) & 0x8000, gfx->ifFocus() && GetKeyState(0x4E) & 0x8000, Player1.width, Player1.height, stageX0, stageY0, stageX1, stageY1);
		}
		if (Player1.IsMoveColliding(Player2.x, Player2.y, Player2.width, Player2.height)) { //Is player 1 hitting any move
			std::string soundString = "set hit speed " + std::to_string(2100 - 100 * (int)Player1.MoveThatHitDamage());
			mciSendStringA(soundString.c_str(), NULL, 0, NULL);
			mciSendStringA("play hit from 0", NULL, 0, NULL);
			Player2.IsHit(Player1.MoveThatHitStun(), Player1.MoveThatHitDamage(), Player1.MoveThatHitFixedX(), Player1.MoveThatHitFixedY(), Player1.MoveThatHitScalarX(), Player1.MoveThatHitScalarY()); //Register that player 2 has been hit
		}
		if (Player2.IsMoveColliding(Player1.x, Player1.y, Player1.width, Player1.height)) { //Is player 2 hitting any move
			std::string soundString = "set hit speed " + std::to_string(2100 - 100 * (int)Player2.MoveThatHitDamage());
			mciSendStringA(soundString.c_str(), NULL, 0, NULL);
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
	mciSendStringA("pause BattleTheme", NULL, 0, NULL);
	mciSendStringA("close BattleTheme", NULL, 0, NULL);
	mciSendStringA("play MainMenu from 0 repeat", NULL, 0, NULL);
	player1Hit -> ~SpriteSheet();
	player2Hit -> ~SpriteSheet();
	player1Move -> ~SpriteSheet();
	player2Move -> ~SpriteSheet();
	player1LivesIcon -> ~SpriteSheet();
	player2LivesIcon -> ~SpriteSheet();
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
	gfx->BeginDraw();
	gfx->ClearScreen(0, 0, 0);
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
		creditsVisual->Draw(0, 0, false);
	}
	else if (startMenu) {
		startVisual->Draw(0, 0, false); //Displays the visual for the start menu

		if (AISelected) {
			aiWarning->Draw(1600, 100, false);
		}

		if (previousWinner == 1) { //If Player 1 won the last match
			player1Win->Draw(1920 / 2 - 250, 500, false); //Dislpay a sprite that shows this
		}
		else if (previousWinner == 2) { //If player 2 won the last match
			player2Win->Draw(1920 / 2 - 250, 500, false); //Dislpay a sprite that shows this
		}

		player1Idle->Draw(1920 / 4, 100, false); //Draws an appropriate sprite based on character ID in the start menu
		player2Idle->Draw(1920 / 4 * 3, 100, player2CharacterID!=8); //Draws an appropriate sprite based on character ID in the start menu
	}
	else {
		if (paused) {
			pauseVisual->Draw(0, 0, false); //Display the pause menu

			if (Player1.lives == Player2.lives && Player1.playerPercentage == Player2.playerPercentage) { //If both players are even
				gfx->DrawRectFill(1920 / 2 - Player1.width - 1, 99, 1920 / 2 + 1, 100 + Player1.height + 1, 255, 199, 0, 1); //Player 1 border
				player1Idle->Draw(1920 / 2 - Player1.width, 100, false); //Display player 1 at the top of the screen
				gfx->DrawRectFill(1920 / 2, 99, 1920 / 2 + Player2.width + 1, 100 + Player2.height + 1, 255, 199, 0, 1); //Player 2 border
				player2Idle->Draw(1920 / 2, 100, false); //Display player 2 at the top of the screen
			}
			else if (Player1.lives > Player2.lives || (Player1.lives == Player2.lives && Player1.playerPercentage < Player2.playerPercentage)) {
				gfx->DrawRectFill(1920 / 4 - 1, 349, 1920 / 4 + Player1.width + 1, 351 + Player1.height, 255, 199, 0, 1); //Player 1 border
				player1Idle->Draw(1920 / 4, 350, false); //Display player 1 on the left side
				gfx->DrawRectFill(1920 / 4 * 3 - 1, 349, 1920 / 4 * 3 + Player2.width + 1, 351 + Player2.height, 255, 199, 0, 1); //Player 2 border
				player2Hit->Draw(1920 / 4 * 3, 350, false); //Display player 2 on the right side
			}
			else {
				gfx->DrawRectFill(1920 / 4 - 1, 349, 1920 / 4 + Player2.width + 1, 351 + Player2.height, 255, 199, 0, 1); //Player 1 border
				player2Idle->Draw(1920 / 4, 350, false); //Display player 2 on the left side
				gfx->DrawRectFill(1920 / 4 * 3 - 1, 349, 1920 / 4 * 3 + Player1.width + 1, 351 + Player1.height, 255, 199, 0, 1); //Player 2 border
				player1Hit->Draw(1920 / 4 * 3, 350, false); //Display player 1 on the right side
			}
		}

		else if (timeUntilStart > 120) { //If you should display 3
			startThree->Draw(1920 / 2 - 150, 1080 / 4 - 150, false); //Display 3
		}
		else if (timeUntilStart > 60) { //If you should display 2
			startTwo->Draw(1920 / 2 - 150, 1080 / 4 - 150, false); //Display 2
		}
		else if (timeUntilStart > 0) { //If you should display 1
			startOne->Draw(1920 / 2 - 150, 1080 / 4 - 150, false); //Display 1
		}
		else if (timeGoIsDisplayed > 0) { //If you should display go
			go->Draw(1920 / 2 - 150, 1080 / 4 - 150, false); //Display go
		}

		gfx->DrawRectThin(stageX0, stageY0, stageX1, stageY1, 255, 0, 0, 1); //Stage

		numbers[((int)Player1.playerPercentage - (int)Player1.playerPercentage % 10) / 10]->Draw(1920 / 4, 900, false); //Player 1 percent
		numbers[(int)Player1.playerPercentage % 10]->Draw(1920 / 4 + 30, 900, false); //Player 1 percent
		gfx->DrawRectFill(1920 / 4 + 64, 939, 1920 / 4 + 66, 941, 255, 255, 255, 1); //Decimal point
		numbers[(int)(Player1.playerPercentage * 10) % 10]->Draw(1920 / 4 + 70, 900, false); //Player 1 percent
		for (int i = 0; i < Player1.lives; i++) {
			player1LivesIcon->Draw(1920 / 4 + i * 30, 950, false); //Player 1 lives icon
		}
		for (int i = 0; i < Player2.lives; i++) {
			player2LivesIcon->Draw(1920 / 4 * 3 + i * 30, 950, false); //Player 2 lives icon
		}

		numbers[((int)Player2.playerPercentage - (int)Player2.playerPercentage % 10) / 10]->Draw(1920 / 4 * 3, 900, false); //Player 2 percent
		numbers[(int)Player2.playerPercentage % 10]->Draw(1920 / 4 * 3 + 30, 900, false); //Player 2 percent
		gfx->DrawRectFill(1920 / 4 * 3 + 64, 939, 1920 * 3 / 4 + 66, 941, 255, 255, 255, 1); //Decimal point
		numbers[(int)(Player2.playerPercentage * 10) % 10]->Draw(1920 / 4 * 3 + 70, 900, false); //Player 2 percent

		if (AISelected) {
			aiWarning->Draw(1920 / 4 * 3, 980, false);
		}

		if (Player1.invincibility > 0) { //If player 1 has invincibility
			gfx->DrawRectThin(Player1.x - 1, Player1.y - 1, Player1.x + Player1.width + 1, Player1.y + Player1.height + 1, 0, 237, 255, 1); //Give them a border
		}
		if (Player2.invincibility > 0) { //If player 2 has invincibility
			gfx->DrawRectThin(Player2.x - 1, Player2.y - 1, Player2.x + Player2.width + 1, Player2.y + Player2.height + 1, 0, 237, 255, 1); //Give them a border
		}

		if (Player1.moveDuration > 0 || Player1.freeFallDuration > 0) { //If Player 1 is using a move
			player1Move->Draw(Player1.x, Player1.y, !Player1.facingRight); //Display normal animation
		}
		else if (Player1.stun > 0) { //If player 1 is in stun
			player1Hit->Draw(Player1.x, Player1.y, !Player1.facingRight); //Display normal animation
		}
		else {
			player1Idle->Draw(Player1.x, Player1.y, !Player1.facingRight); //Display normal animation
		}

		if (Player2.moveDuration > 0 || Player2.freeFallDuration > 0) { //If Player 2 is using a move
			player2Move->Draw(Player2.x, Player2.y, !Player2.facingRight); //Display normal animation
		}
		else if (Player2.stun > 0) { //If player 2 is in stun
			player2Hit->Draw(Player2.x, Player2.y, !Player2.facingRight); //Display normal animation
		}
		else {
			player2Idle->Draw(Player2.x, Player2.y, !Player2.facingRight); //Display normal animation
		}


		for (int i = 0; i < 5; i++) { //For every move
			if (Player1.MoveDraw(i)) { //If it can be drawn
				gfx->DrawRectFill(Player1.MoveX0(i), Player1.MoveY0(i), Player1.MoveX1(i), Player1.MoveY1(i), Player1.MoveR(i), Player1.MoveG(i), Player1.MoveB(i), 1); //Draw it
			}
			if (Player2.MoveDraw(i)) { //If it can be drawn
				gfx->DrawRectFill(Player2.MoveX0(i), Player2.MoveY0(i), Player2.MoveX1(i), Player2.MoveY1(i), Player2.MoveR(i), Player2.MoveG(i), Player2.MoveB(i), 1); //Draw it
			}
		}

		numbers[(int)(timer / 60 / 60)]->Draw(1920 / 2 - 50, 50, false); //Time in minutes
		gfx->DrawRectFill(1920 / 2 - 20, 70, 1920 / 2 - 15, 75, 255, 255, 255, 1); //Colon
		gfx->DrawRectFill(1920 / 2 - 20, 95, 1920 / 2 - 15, 100, 255, 255, 255, 1); //Colon
		numbers[(int)((timer / 60 % 60 - timer / 60 % 10) / 10)]->Draw(1920 / 2, 50, false); //Time in tens
		numbers[(int)(timer / 60 % 10)]->Draw(1920 / 2 + 50, 50, false); //Time in seconds
	}

	gfx->EndDraw();
}