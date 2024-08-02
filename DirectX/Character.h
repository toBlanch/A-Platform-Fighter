#pragma once
#include "Move.h"
#include <vector>
#include "Platform.h"
#include "Inputs.h"
#include "StatsTemplates.h"
#define MOVE_ARRAY_LENGTH 5

class Character {
	void ReduceTimer(int& cooldown);
	void UpdateCharacterMoves(Platform platforms[10], bool onlyProjectiles);
	void UpdateCharacterPosition(Inputs inputs, Platform Platforms[10]);
	void isCollidingWithStage(Platform Platforms[10], float horizontalSpeed, float verticalSpeed, bool down);
	bool IsOnStage(Platform platform, float speed, bool down, int i);
	bool ClippingIntoStageFromLeft(Platform platform, float speed);
	bool ClippingIntoStageFromRight(Platform platform, float speed);
	bool ClippingIntoStageFromBottom(Platform platform, float speed);
public:
	Character();
	Character(const CharacterTemplate rCharacterTemplates[9]);
	void ChangeCharacterID(bool isIncreasing, CharacterTemplate characterTemplates);
	void UpdateCharacter(Inputs inputs, Platform platforms[10]);
	bool IsAlive(int screenWidth, int screenHeight, int leniancy);
	void UpdateMoveCollision(Character &opposingPlayer);
	void IsHit(Move moveHitWith);
	void Restart();
	Move GetMove(int moveID);

	int characterID = 0;

	float x = 0;
	float y = 0;
	float vx = 0;
	float vy = 0;
	int doubleJump = 0;
	bool facingRight = true;
	float speed = 0;
	float acceleration = 0;

	int lives = 3;
	float playerPercentage = 0;
	int moveDuration = 0;
	int stun = 0;
	int freeFallDuration = 0;
	int invincibility = 0;
	int invincibilityCooldown = 0;

	bool easyMode = false;
	bool aiSelected = false;
private:
	//CharacterTemplate(&characterStats)[9];
	const CharacterTemplate* characterStats;

	bool onStage = false;
	bool fastFalling = false;
	bool groundTouchedAfterDodging = false;
	bool hitDuringDodge = false; //Balances wavedashing
	int moveCharacterIsAttachedTo = -1;

	Inputs inputsHeld = Inputs(false, false, false, false, false, false, false, false, false);

	int platformOn = -1;
	Move moveArray[MOVE_ARRAY_LENGTH];
};