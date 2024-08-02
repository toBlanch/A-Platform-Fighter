#pragma once

#include "Character.h"
#include "Move.h"
#include "AI.h"
#include "Graphics.h"
#include "SpriteSheet.h"
#include <vector>
#include <random>
#include <string>
#include <Xinput.h>
#include "Platform.h"
#include "Stage.h"
#include <list>

class Game
{
public:
	Game(Graphics* gfx);
	Game(const Game&) = delete;
	Game& operator=(const Game&) = delete;
	void Go();
private:
	void ComposeFrame();
	void GameState();
	/********************************/
	/*  User Functions              */
	/********************************/
	void menuTransition();
	void StartMenu();
	void StageSelectionMenu();
	void StartBattleTheme();
	void GameLoop();
	void GameStart();
	void GameEnd();
	int* ShrinkToCoordinates(float x0, float y0, float x1, float y1, int screenx0, int screeny0, int screenx1, int screeny1);
	wstring DamageToWString(float damage);
	wstring TimeToWString(int time);
	void UpdateCharacterSprites(Character& character);

private:
	/********************************/
	/*  User Variables              */
	Graphics* gfx;
	std::mt19937 rng;
	std::random_device rd;
	std::uniform_int_distribution<int> randomDist;

	int stageSelected = -1;
	int leniancy = 0;
	int previousWinner = 0;
	int timeUntilStart = 0;
	int timeGoIsDisplayed = 0;
	int timer = 0;

	enum menuStateEnum { mainMenu, credits, stageSelect, game };
	menuStateEnum menuState = mainMenu;
	bool paused = false;

	bool enterOrEscapeHeld = false;
	bool spaceHeld = false;
	bool tabHeld = false;
	bool backspaceHeld = false;
	bool clickHeld = GetKeyState(0x01);
	bool shiftHeld = false;

	bool easyMode;

	POINT clickPosition;

	IDWriteTextFormat* menuText;

	Inputs p1PreviousInputs;
	Inputs p2PreviousInputs;
	int gameFrame = 0;
	Inputs* p1Inputs;
	list<InputChange> p1InputChanges;
	Inputs* p2Inputs;
	list<InputChange> p2InputChanges;

	SpriteSheet* easyModeWarning;
	SpriteSheet* aiWarning;
	SpriteSheet* creditsVisual;
	SpriteSheet* startVisual;
	SpriteSheet* player1Win;
	SpriteSheet* player2Win;
	SpriteSheet* pauseVisual;
	SpriteSheet* startThree;
	SpriteSheet* startTwo;
	SpriteSheet* startOne;
	SpriteSheet* go;

	AI ArtifialFriend;

	Platform Platforms0[10] = {
		Platform(480,700,1440,880,true,false,255,0,0),
		Platform(0,0,0,0,false,false,0,0,0),
		Platform(0,0,0,0,false,false,0,0,0),
		Platform(0,0,0,0,false,false,0,0,0),
		Platform(0,0,0,0,false,false,0,0,0),
		Platform(0,0,0,0,false,false,0,0,0),
		Platform(0,0,0,0,false,false,0,0,0),
		Platform(0,0,0,0,false,false,0,0,0),
		Platform(0,0,0,0,false,false,0,0,0),
		Platform(0,0,0,0,false,false,0,0,0)
	};
	Platform Platforms1[10] = {
		Platform(480,700,1440,880,true,false,255,0,0),
		Platform(500,500,800,600,false,false,255,255,0),
		Platform(800,500,1100,600,true,false,255,255,255),
		Platform(0,0,0,0,false,false,0,0,0),
		Platform(0,0,0,0,false,false,0,0,0),
		Platform(0,0,0,0,false,false,0,0,0),
		Platform(0,0,0,0,false,false,0,0,0),
		Platform(0,0,0,0,false,false,0,0,0),
		Platform(0,0,0,0,false,false,0,0,0),
		Platform(0,0,0,0,false,false,0,0,0)
	};
	Platform Platforms2[10] = {
		Platform(672,900,1248,1080,true,false,255,255,255),
		Platform(313,670,767,680,false,true,255,255,255),
		Platform(1153,670,1607,680,false,true,255,255,255),
		Platform(0,0,0,0,false,false,0,0,0),
		Platform(0,0,0,0,false,false,0,0,0),
		Platform(0,0,0,0,false,false,0,0,0),
		Platform(0,0,0,0,false,false,0,0,0),
		Platform(0,0,0,0,false,false,0,0,0),
		Platform(0,0,0,0,false,false,0,0,0),
		Platform(0,0,0,0,false,false,0,0,0)
	};
	Platform Platforms3[10] = {
		Platform(480,700,1440,880,true,false,255,0,0),
		Platform(500,500,800,600,false,false,255,255,0),
		Platform(800,500,1100,600,true,false,255,255,255),
		Platform(0,0,0,0,false,false,0,0,0),
		Platform(0,0,0,0,false,false,0,0,0),
		Platform(0,0,0,0,false,false,0,0,0),
		Platform(0,0,0,0,false,false,0,0,0),
		Platform(0,0,0,0,false,false,0,0,0),
		Platform(0,0,0,0,false,false,0,0,0),
		Platform(0,0,0,0,false,false,0,0,0)
	};
	Platform Platforms4[10] = {
		Platform(480,700,1440,880,true,false,255,0,0),
		Platform(500,500,800,600,false,false,255,255,0),
		Platform(800,500,1100,600,true,false,255,255,255),
		Platform(0,0,0,0,false,false,0,0,0),
		Platform(0,0,0,0,false,false,0,0,0),
		Platform(0,0,0,0,false,false,0,0,0),
		Platform(0,0,0,0,false,false,0,0,0),
		Platform(0,0,0,0,false,false,0,0,0),
		Platform(0,0,0,0,false,false,0,0,0),
		Platform(0,0,0,0,false,false,0,0,0)
	};
	Platform Platforms5[10] = {
		Platform(480,700,1440,880,true,false,255,0,0),
		Platform(500,500,800,600,false,false,255,255,0),
		Platform(800,500,1100,600,true,false,255,255,255),
		Platform(0,0,0,0,false,false,0,0,0),
		Platform(0,0,0,0,false,false,0,0,0),
		Platform(0,0,0,0,false,false,0,0,0),
		Platform(0,0,0,0,false,false,0,0,0),
		Platform(0,0,0,0,false,false,0,0,0),
		Platform(0,0,0,0,false,false,0,0,0),
		Platform(0,0,0,0,false,false,0,0,0)
	};
	Platform Platforms6[10] = {
		Platform(480,700,1440,880,true,false,255,0,0),
		Platform(500,500,800,600,false,false,255,255,0),
		Platform(800,500,1100,600,true,false,255,255,255),
		Platform(0,0,0,0,false,false,0,0,0),
		Platform(0,0,0,0,false,false,0,0,0),
		Platform(0,0,0,0,false,false,0,0,0),
		Platform(0,0,0,0,false,false,0,0,0),
		Platform(0,0,0,0,false,false,0,0,0),
		Platform(0,0,0,0,false,false,0,0,0),
		Platform(0,0,0,0,false,false,0,0,0)
	};
	Platform Platforms7[10] = {
		Platform(480,700,1440,880,true,false,255,0,0),
		Platform(500,500,800,600,false,false,255,255,0),
		Platform(800,500,1100,600,true,false,255,255,255),
		Platform(0,0,0,0,false,false,0,0,0),
		Platform(0,0,0,0,false,false,0,0,0),
		Platform(0,0,0,0,false,false,0,0,0),
		Platform(0,0,0,0,false,false,0,0,0),
		Platform(0,0,0,0,false,false,0,0,0),
		Platform(0,0,0,0,false,false,0,0,0),
		Platform(0,0,0,0,false,false,0,0,0)
	};
	Platform Platforms8[10] = {
		Platform(480,700,1440,880,true,false,255,0,0),
		Platform(500,500,800,600,false,false,255,255,0),
		Platform(800,500,1100,600,true,false,255,255,255),
		Platform(0,0,0,0,false,false,0,0,0),
		Platform(0,0,0,0,false,false,0,0,0),
		Platform(0,0,0,0,false,false,0,0,0),
		Platform(0,0,0,0,false,false,0,0,0),
		Platform(0,0,0,0,false,false,0,0,0),
		Platform(0,0,0,0,false,false,0,0,0),
		Platform(0,0,0,0,false,false,0,0,0)
	};
	Stage Stages[9] = {
		Stage(Platforms0, "open \"Battle Theme 0.wav\" type mpegvideo alias BattleTheme", 1920 / 4 + 100, 700),
		Stage(Platforms1, "open \"Battle Theme 1.wav\" type mpegvideo alias BattleTheme", 1920 / 4 + 100, 700),
		Stage(Platforms2, "open \"Battle Theme 2.wav\" type mpegvideo alias BattleTheme", 1920 / 4 + 200, 900),
		Stage(Platforms3, "open \"Battle Theme 3.wav\" type mpegvideo alias BattleTheme", 1920 / 4 + 100, 700),
		Stage(Platforms4, "open \"Battle Theme 4.wav\" type mpegvideo alias BattleTheme", 1920 / 4 + 100, 700),
		Stage(Platforms5, "open \"Battle Theme 5.wav\" type mpegvideo alias BattleTheme", 1920 / 4 + 100, 700),
		Stage(Platforms6, "open \"Battle Theme 6.wav\" type mpegvideo alias BattleTheme", 1920 / 4 + 100, 700),
		Stage(Platforms7, "open \"Battle Theme 7.wav\" type mpegvideo alias BattleTheme", 1920 / 4 + 100, 700),
		Stage(Platforms8, "open \"Battle Theme 8.wav\" type mpegvideo alias BattleTheme", 1920 / 4 + 100, 700)
	};

	CharacterTemplate characterTemplates[9] = {
		//Circle
		CharacterTemplate(
			L"CircleIdle.bmp",
			L"CircleMove.bmp",
			L"CircleHit.bmp",
			L"CircleLivesIcon.bmp",
			L"CircleDesc.bmp",
			100, 100, 10, 10, 1, 1, 20, 25, 1, 10, 0.9, 2,
			MoveTemplate(100, 0, 50, 10, 40, 5, -5, 3, -3, 0, 0, 0, 0, 10, 10, 30, 10, 1, 0, 0),
			MoveTemplate(100, 0, 20, 20, 15, 1, -5, 2, -3, 0, 0, 0, 0, 6, 4, 30, 10, 1, 0, 0),
			MoveTemplate(0, 90, 100, 10, 50, 0, 4, 5, 0, 0, 0, 0, 0, 0.1, 1, 10, 30, 1, 0, 0),
			MoveTemplate(100, 0, 50, 10, 80, 10, -4, 3.5, -3.5, 0, 0, 0, 0, 20, 40, 60, 20, 1, 0, 0),
			MoveTemplate(50, -10, 50, 10, 40, 1, -8, 1, -4, 0, 0, 0, 0, 25, 10, 30, 30, 1, 0, 0),
			MoveTemplate(100, 90, 50, 10, 20, 0, -1, 7, -1, 0, 0, 0, 0, 10, 10, 30, 10, 1, 0, 0),
			MoveTemplate(100, 0, 50, 10, 40, 5, -5, 3, -3, 0, 0, 0, 0, 10, 10, 30, 10, 1, 0, 0),
			MoveTemplate(-50, 0, 50, 10, 40, 5, -5, 3, -3, 0, 0, 0, 0, 10, 10, 30, 10, 1, 0, 0),
			MoveTemplate(50, -10, 50, 10, 40, 1, 5, 1, 3, 0, 0, 0, 0, 5.3, 5, 20, 25, 1, 0, 0),
			MoveTemplate(50, 110, 60, 10, 25, -4, -5, -1, -3, 0, 0, 0, 0, 5.3, 3, 20, 15, 1, 0, 0),
			MoveTemplate(150, 0, 50, 10, 20, 1, -1, 3, -3, 2, 0.5, 0, 0, 5, 10, 300, 50, 0, 0, 1),
			MoveTemplate(100, 0, 50, 10, 20, 15, -1, 3, -3, 2, 0.5, 0, -0.1, 5, 5, 50, 30, 0, 1, 0),
			MoveTemplate(100, 0, 50, 10, 20, 15, -5, 3, -3, 2, 0, 0, 0, 5, 10, 300, 0, 0, 1, 0)
		),
		//a
		CharacterTemplate(
			L"aIdle.bmp",
			L"aMove.bmp",
			L"aHit.bmp",
			L"aLivesIcon.bmp",
			L"aDesc.bmp",
			100, 100, 7, 13, 1.5, 1.5, 35, 25, 1, 5, 0.75, 1,
			MoveTemplate(100, 60, 35, 10, 40, 3, -2, 7, -1, 0, 0, 0, 0, 6, 3, 20, 27, 1, 0, 0),
			MoveTemplate(0, -3, 100, 5, 30, 1, -7, 1, -2, 0, 0, 0, 0, 4, 4, 30, 21, 1, 0, 0),
			MoveTemplate(100, 95, 70, 3, 20, 0.1, -0.5, 7, -0.5, 0, 0, 0, 0, 13, 12, 15, 20, 1, 0, 0),
			MoveTemplate(90, 25, 40, 50, 40, 1, -6, 0, -3, 0, 0, 0, 0, 12.3, 21, 10, 20, 1, 0, 0),
			MoveTemplate(30, -50, 40, 52, 40, 1, -12, 0, -6, 0, 0, 0, 0, 15, 25, 40, 15, 1, 0, 0),
			MoveTemplate(-20, 70, 140, 30, 40, 2, -15, 0, -3, 0, -5, 0, 0, 12.5, 10, 30, 60, 1, 0, 0),
			MoveTemplate(90, 30, 35, 40, 40, 5, -5, 3, -3, 0, 0, 0, 0, 10, 7, 40, 25, 1, 0, 0),
			MoveTemplate(-50, 50, 50, 10, 20, -8, -1, -2, -3, 0, -7, 0, 0, 7.3, 6, 30, 10, 1, 0, 0),
			MoveTemplate(70, 0, 60, 30, 30, 0, -2, 1, -1, 0, 0, 0, 0, 4, 5, 30, 20, 1, 0, 0),
			MoveTemplate(50, 100, 10, 10, 20, 1, 5, 1, 3, 0, 4, 0, 0.15, 13.7, 10, 70, 40, 0, 0, 0),
			MoveTemplate(100, 0, 40, 100, 20, 0, 0, 3, -1, 6, 0, -0.5, 0, 0.5, 30, 30, 30, 0, 1, 0),
			MoveTemplate(30, -20, 40, 20, 20, 1, -9, 0, -3, 0, -3, 0, -0.3, 5, 5, 43, 40, 0, 1, 0),
			MoveTemplate(50, 0, 70, 100, 20, 9, -1, 3, 3, 2, 11, 0.25, -0.15, 9.3, 10, 50, 10, 0, 1, 0)
		),
		//Sigma Monkey Of Doom
		CharacterTemplate(
			L"SigmaMonkeyOfDoomIdle.bmp",
			L"SigmaMonkeyOfDoomMove.bmp",
			L"SigmaMonkeyOfDoomHit.bmp",
			L"SigmaMonkeyOfDoomLivesIcon.bmp",
			L"SigmaMonkeyOfDoomDesc.bmp",
			63, 100, 13, 7, 0.1, 1.5, 5, 10.4, 0.1, 7, 0.74, 1,
			MoveTemplate(63, 40, 20, 10, 40, 2, -7, 1, -2, 0, 0, 0, 0, 7, 6, 23, 9, 1, 0, 0),
			MoveTemplate(10, -10, 43, 10, 20, 2, -5, 3, -3, 0, 0, 0, 0, 7, 10, 13, 16, 1, 0, 0),
			MoveTemplate(43, 80, 40, 20, 32, 1, -5, 1, -2, 0, 0, 0, 0, 3.4, 5, 5, 5, 1, 0, 0),
			MoveTemplate(53, 0, 40, 10, 40, 13, -5, 4, -3, 3, 0, 0.05, 0, 20, 20, 30, 30, 0, 1, 0),
			MoveTemplate(10, -20, 43, 30, 40, 1, -10, 1, -3, 0, 0, 0, 0, 9.6, 23, 30, 10, 1, 0, 0),
			MoveTemplate(0, 90, 63, 10, 30, 12, -5, 5, -3, 0, 0, 0, 0, 14.3, 15, 17, 23, 1, 0, 0),
			MoveTemplate(53, 40, 70, 20, 40, 7, -4, 2, -1, 0, 0, 0, 0, 11.2, 10, 30, 10, 1, 0, 0),
			MoveTemplate(-40, 50, 50, 20, 20, -2.5, -2.5, -1.5, -1.5, 0, 0, 0, 0, 4, 10, 15, 10, 1, 0, 0),
			MoveTemplate(10, -30, 43, 30, 15, 2, -7, 3, -7, 0, 0, 0, 0, 6, 6, 12, 6, 1, 0, 0),
			MoveTemplate(20, 100, 23, 30, 30, 2, 12, 1, 6, 0, 0, 0, 0, 18, 20, 30, 15, 1, 0, 0),
			MoveTemplate(53, 30, 30, 40, 10, 3, -1, 6, -3, 4, -8, 0, 0.2, 5, 10, 60, 0, 0, 1, 0),
			MoveTemplate(53, 30, 30, 40, 10, 3, -1, 6, -3, 1.5, 6, 0, -0.2, 5, 5, 80, 50, 0, 1, 0),
			MoveTemplate(73, 40, 30, 10, 50, 15, -1, 3, -3, 2, 0.5, 0, 0.01, 5, 10, 200, 50, 0, 0, 1)
		),
		//Dog
		CharacterTemplate(
			L"DogIdle.bmp",
			L"DogMove.bmp",
			L"DogHit.bmp",
			L"DogLivesIcon.bmp",
			L"DogDesc.bmp",
			70, 40, 9, 4, 4, 3, 25, -20, 1, 7, 1.1, 0,
			MoveTemplate(70, 15, 20, 10, 20, 6, 1, 6, 0, 0, 0, 0, 0, 7, 3, 10, 20, 1, 0, 0),
			MoveTemplate(60, -20, 15, 40, 30, 2, -5, 1, -3, 0, 0, 0, 0, 10, 7, 30, 10, 1, 0, 0),
			MoveTemplate(70, 95, 50, 5, 30, 0, 0, -0.3, -1, 0, 0, 0, 0, 4, 5, 30, 15, 1, 0, 0),
			MoveTemplate(70, 10, 30, 20, 40, 15, -4, 3, 0, 0, 0, 0, 0, 16.1, 13, 23, 35, 1, 0, 0),
			MoveTemplate(15, -20, 40, 20, 30, 3, -13, 2, -4, 1, -10, 0, 0.7, 16.4, 14, 30, 0, 0, 1, 0),
			MoveTemplate(60, 20, 30, 15, 25, 8, -4, 4, -1, 5, 0, -0.35, 0, 17, 10, 30, 10, 0, 1, 0),
			MoveTemplate(60, 10, 20, 20, 25, 1, 20, 3, 2, 0, 0, 0, 0, 9.9, 9, 25, 13, 1, 0, 0),
			MoveTemplate(-20, 25, 30, 10, 15, -8, -2, -2, -3, 0, 0, 0, 0, 6.2, 15, 20, 15, 1, 0, 0),
			MoveTemplate(35, 10, 20, 15, 13, 1, -5, 2, -3, 0, 0, 0, 0, 4.6, 3, 30, 10, 1, 0, 0),
			MoveTemplate(50, 35, 30, 10, 26, 3, -3, 1, -1, 0, 0, 0, 0, 7.8, 6, 24, 10, 1, 0, 0),
			MoveTemplate(70, 0, 20, 40, 24, 15, -1, 3, -3, 0, 4, 2, 0, 5, 5, 15, 35, 0, 1, 0),
			MoveTemplate(0, -30, 10, 40, 20, 5, -7, 3, -3, 2, -20, 0, 0, 5, 5, 10, 10, 0, 1, 1),
			MoveTemplate(-10, -10, 90, 60, 20, 7, -3, 2, -1, 6, 0, 0, 0, 5, 10, 100, 10, 0, 1, 1)
		),
		//Chicken
		CharacterTemplate(
			L"ChickenIdle.bmp",
			L"ChickenMove.bmp",
			L"ChickenHit.bmp",
			L"ChickenLivesIcon.bmp",
			L"ChickenDesc.bmp",
			150, 150, 7, 4, 4, 0.2, 30, 23, 1.78, 6, 1.1, 5,
			MoveTemplate(150, 65, 30, 20, 15, 4, -5, 1.35, 3, 7, 0, 0, 0.1, 7.8, 14, 100, 30, 0, 0, 1),
			MoveTemplate(50, 10, 50, 10, 30, 2, -1, 3, -3, 0, -7.5, 0, 0.2, 13.5, 10, 70, 25, 0, 0, 1),
			MoveTemplate(140, 140, 20, 10, 40, 8, -2, 5, -1, 1, 2, 0, 0, 10, 10, 300, 9.7, 0, 0, 1),
			MoveTemplate(150, 0, 10, 150, 30, 17, -2, 3, -1, 1, 0, 0, 0, 25, 25, 200, 50, 0, 0, 1),
			MoveTemplate(0, 0, 150, 10, 30, 2, -17, 1, -3, 0, -1, 0, 0, 14, 25, 200, 50, 0, 0, 1),
			MoveTemplate(65, 0, 10, 100, 40, 1, -5, 1, -3, 0, 0, 0, -0.3, 26, 12, 100, 25, 0, 0, 1),
			MoveTemplate(130, 55, 30, 40, 15, 3, 1, 3, 1, 4, 0, 0, 0.3, 10, 10, 30, 43, 0, 0, 1),
			MoveTemplate(-20, 130, 30, 20, 17, -5, -1, -3, -7, -3, -5, 0, 0.2, 10, 10, 30, 10, 0, 0, 1),
			MoveTemplate(130, 0, 40, 13, 14, -7, -2, -3, -1, 3, 3, -0.1, -0.3, 13, 10, 60, 20, 0, 0, 1),
			MoveTemplate(75, 75, 75, 75, 23, 2, 7, 3, 5, 0, 0, 0, 0, 13, 16, 30, 7, 1, 0, 0),
			MoveTemplate(150, 70, 300, 10, 40, 0, 0, -5, -1, 2, 0.5, 0, 0, 5, 13, 1, 20, 1, 0, 0),
			MoveTemplate(130, 0, 40, 13, 14, 2, -2, 6, -2, 3, 3, -0.1, -0.3, 5, 5, 50, 10, 0, 1, 0),
			MoveTemplate(0, 149, 5, 5, 15, 1, -1, 1, -1, 0, 0, 0, 0, 5, 0, 1000, 14, 0, 0, 1)
		),
		//Rock
		CharacterTemplate(
			L"RockIdle.bmp",
			L"RockMove.bmp",
			L"RockHit.bmp",
			L"RockLivesIcon.bmp",
			L"RockDesc.bmp",
			130, 100, 3, 10, 1, 1, 10, 10, 1, 30, 1.4, 1,
			MoveTemplate(100, 0, 50, 10, 40, 5, -5, 3, -3, 1, 0, -0.1, 0, 14.2, 17, 40, 10, 0, 1, 0),
			MoveTemplate(70, -30, 50, 30, 40, 4, -5, 1, -3, -2.5, 0, 0, 0, 11.2, 15, 30, 30, 0, 1, 0),
			MoveTemplate(100, 90, 50, 10, 60, 0.5, -1, 1, -2, 0, 0, 0, 0, 6, 13, 10, 20, 1, 0, 0),
			MoveTemplate(0, 0, 150, 100, 50, 10, -2, 7, -3, 5, 0, -0.03, 0, 10, 25, 100, 25, 0, 1, 0),
			MoveTemplate(20, 0, 90, 10, 70, 4, -5, 1, -3, 0, -3, 0, 0, 10, 10, 30, 10, 0, 1, 0),
			MoveTemplate(20, 80, 90, 20, 80, 4, 7, 4, 3, 0, -28, 0, 2.5, 17.5, 15, 25, 20, 0, 1, 0),
			MoveTemplate(100, 30, 30, 40, 40, 5, -2, 3, -1.5, 0, 0, 0, 0, 2, 10, 10, 10, 1, 0, 0),
			MoveTemplate(10, 90, 10, 10, 50, -5, -2, -5, -1.5, 0, 0, 0, 0, 23, 10, 10, 10, 1, 0, 0),
			MoveTemplate(20, -10, 90, 10, 20, 1, -5, 2, -3, 0, 0, 0, 0, 7.2, 16, 19, 10, 1, 0, 0),
			MoveTemplate(20, 90, 90, 10, 20, 5, 15, 3, 3, 0, -0.1, 0, 10, 10, 10, 8, 10, 0, 1, 0),
			MoveTemplate(130, 45, 10, 10, 10, 4, -0.5, 3, -1.5, 1, -1, 0, 0.015, 5, 10, 300, 35, 0, 0, 0),
			MoveTemplate(30, 50, 100, 50, 30, 1, 15, 1, 3, 3, -50, 0.02, 2.5, 5, 5, 70, 50, 0, 1, 0),
			MoveTemplate(130, 0, 1, 5, 5, 1, 0, 0, 0, 2, 0, 0, 0, 0.1, 5, 2000, 10, 0, 0, 1)
		),
		//Troll
		CharacterTemplate(
			L"TrollIdle.bmp",
			L"TrollMove.bmp",
			L"TrollHit.bmp",
			L"TrollLivesIcon.bmp",
			L"TrollDesc.bmp",
			92, 66, 17, 13, 1.25, 0.75, 28, 33, 1.25, 15, 0.81, 2,
			MoveTemplate(31, 28, 50, 30, 25, 2, -3, 1, -1, 0, 0, 0, 0, 4.6, 2, 14, 15, 1, 0, 0),
			MoveTemplate(52, 0, 48, 20, 15, 1, -1, 3, -6, 0, 0, 0, 0, 10, 5, 30, 8, 1, 0, 0),
			MoveTemplate(0, 51, 91, 10, 30, 0, 4, 5, 0, 0, 0, 0, 0, 0.1, 1, 10, 10, 1, 0, 0),
			MoveTemplate(61, 15, 30, 30, 35, 17, -7, 5, -2, 0, 0, 0, 0, 13.5, 13, 17, 20, 1, 0, 0),
			MoveTemplate(5, 0, 50, 4, 37, 7, -19, 2, -2, 0, 0, 0, 0, 15.2, 18, 30, 10, 1, 0, 0),
			MoveTemplate(51, 43, 40, 20, 31, 10, -10, 3, -5, 7, 0, 0, 0, 17.1, 19, 25, 20, 1, 0, 0),
			MoveTemplate(61, 20, 30, 30, 25, 5, 8, 2, 3, 0, 0, 0, 0, 7.1, 6, 11, 11, 1, 0, 0),
			MoveTemplate(0, 10, 30, 40, 40, -3, -1, -5, -1, 0, 0, 0, 0, 8.6, 9, 23, 14, 1, 0, 0),
			MoveTemplate(10, 0, 71, 4, 17, 1, -3, 1, -3, 0, 0, 0, 0, 6.3, 2, 17, 8, 1, 0, 0),
			MoveTemplate(0, 90, 91, 10, 30, 0, 4, 5, 0, 0, 0, 0, 0, 4.7, 10, 10, 10, 1, 0, 0),
			MoveTemplate(0, 0, 91, 63, 33, 13, -1, 3, -3, 800, 0, -400, 0, 15, 10, 2, 50, 0, 1, 0),
			MoveTemplate(71, 0, 20, 61, 26, 4, -13, 1, -3, 3, -10, 0, -0.4, 5, 3, 17, 20, 0, 1, 0),
			MoveTemplate(50, 15, 10, 1, 120, 0, 0, 0, 0, 10, 0, 0, 0, 0, 16, 6, 29, 0, 0, 1)
		),
		//Big B
		CharacterTemplate(
			L"BigBIdle.bmp",
			L"BigBMove.bmp",
			L"BigBHit.bmp",
			L"BigBLivesIcon.bmp",
			L"BigBDesc.bmp",
			89, 102, 3, 5, 10, 2, 30, 26, 1.75, 10, 1.55, 1,
			MoveTemplate(89, 0, 89, 102, 24, 6, 1, 3, 1, 0, 0, 0, 0, 5.3, 12, 30, 30, 1, 0, 0),
			MoveTemplate(39, -100, 2, 106, 30, 2, -12, 1, -10, 0, 0, 0, 0, 1, 14, 35, 11, 1, 0, 0),
			MoveTemplate(66, 90, 40, 12, 50, 0, -5, 0, -3, 0, 0, 0, 0, 20, 10, 30, 40, 1, 0, 0),
			MoveTemplate(89, 40, 100, 20, 27, 16, -6, 2, -3, 0, 0, 0, 0, 15.7, 16, 30, 19, 1, 0, 0),
			MoveTemplate(10, -10, 69, 20, 34, 0, -3, 0, -3, 0, 0, 0, 0, 3, 6, 18, 20, 1, 0, 0),
			MoveTemplate(10, 82, 69, 20, 34, 1, -5, 1, -3, 0, 0, 0, 0, 3, 6, 18, 20, 1, 0, 0),
			MoveTemplate(79, 20, 30, 30, 34, 1, -5, 2, -3, 10, 0, 0, 0, 3.1, 10, 30, 15, 0, 1, 0),
			MoveTemplate(-100, 67, 110, 30, 19, -10, -5, -3, -3, 0, 0, 0, 0, 7.6, 5, 10, 23, 1, 0, 0),
			MoveTemplate(39, -100, 2, 106, 30, 2, -8, 1, -10, 0, 0, 0, 0, 1, 14, 35, 11, 1, 0, 0),
			MoveTemplate(10, 82, 69, 20, 50, 1, 5, 1, 3, 0, -1, 0, 0.3, 5.9, 5, 50, 30, 0, 1, 0),
			MoveTemplate(10, -10, 40, 60, 5, 20, 5, 5, -3, 2, 0.5, 0.1, 0, 15.2, 20, 50, 30, 1, 1, 0),
			MoveTemplate(10, 0, 69, 30, 30, 0, 0, 6, -3, 5, -1, 0, 0, 0, 5, 50, 20, 0, 1, 0),
			MoveTemplate(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -20, 0, 0, 0, 10, 10, 20, 0, 1, 0)
		),
		//Random
		CharacterTemplate(
			L"Random.bmp",
			L"CircleMove.bmp",
			L"CircleHit.bmp",
			L"CircleLivesIcon.bmp",
			L"Random.bmp",
			36, //Width
			88 //Height
		)
	};

	Character Player1;
	Character Player2;
}; 