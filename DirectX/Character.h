#pragma once
#include "Move.h"
#include <vector>
#include "Platform.h"
#include "Inputs.h"
#include "StatsTemplates.h"

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
	void UpdateCharacter(Inputs inputs, Platform platforms[10]);
	bool IsAlive(int screenWidth, int screenHeight, int leniancy);
	void UpdateMoveCollision(Character &opposingPlayer);
	void Initialise(std::vector<float>& parameters);
	void IsHit(Move moveHitWith);
	void Restart();
	Move GetMove(int moveID);

	int lives = 3;
	float x = 0;
	float y = 0;
	int width = 100;
	int height = 100;
	int moveDuration = 0;
	float playerPercentage = 0;
	int stun = 0;
	bool facingRight = true;
	int invincibility = 0;
	int freeFallDuration = 0;
	int invincibilityCooldown = 0;
	float vx = 0;
	float vy = 0;
	float speed = 0;
	float acceleration = 0;
	int doubleJump = 0;
	int moveArrayLength = 0;
	bool easyMode = false;
	int moveThatHit = 0;
	bool aiSelected = false;
private:
	float walkSpeed = 0;
	float aerialSpeed = 0;
	float walkAcceleration = 0;
	float aerialAcceleration = 0;
	float groundJumpHeight = 0;
	float aerialJumpHeight = 0;
	float fallAcceleration = 0;
	float fallSpeed = 0;
	float weight = 0;
	int maxDoubleJump = 0;
	bool onStage = false;
	bool fastFalling = false;
	bool groundTouchedAfterDodging = false;
	bool hitDuringDodge = false; //Balances wavedashing
	int moveCharacterIsAttachedTo = -1;

	Inputs inputsHeld = Inputs(false, false, false, false, false, false, false, false, false);

	int platformOn = -1;
	Move moveArray[5];

	MoveTemplate forwardLight;

	MoveTemplate upLight;

	MoveTemplate downLight;

	MoveTemplate forwardHeavy;

	MoveTemplate upHeavy;

	MoveTemplate downHeavy;;

	MoveTemplate forwardAerial;

	MoveTemplate backAerial;

	MoveTemplate upAerial;

	MoveTemplate downAerial;

	MoveTemplate forwardSpecial;

	MoveTemplate upSpecial;

	MoveTemplate downSpecial;
};