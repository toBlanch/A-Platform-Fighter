#pragma once
#include "Move.h"

class Character {
public:
	void UpdateCharacter(bool left, bool right, bool down, bool jump, bool light, bool heavy, bool special, int stageX0, int stageY0, int stageX1, int stageY1);
	bool IsAlive(int stageWidth, int stageHeight, int leniancy);
	bool MoveDraw(int move);
	bool IsMoveColliding(int Player2x, int Player2y, int Player2width, int Player2height);
	int MoveX0(int move);
	int MoveY0(int move);
	int MoveX1(int move);
	int MoveY1(int move);
	int MoveThatHitStun();
	int MoveThatHitDamage();
	int MoveThatHitScalarX();
	int MoveThatHitScalarY();
	int MoveThatHitFixedX();
	int MoveThatHitFixedY();
	void IsHit(int stunReferral, int damage, int fixedX, int fixedY, int scalarX, int scalarY);
	int lives = 3;
	float x = 800;
	float y = 0;
	int width = 100;
	int height = 100;
	int moveDuration = 0;
	int playerPercentage = 0;
	int stun = 0;
private:
	float vx = 0;
	float vy = 0;
	float speed = 0;
	float walkSpeed = 10;
	float aerialSpeed = 10;
	float acceleration = 0;
	float walkAcceleration = 1;
	float aerialAcceleration = 1;
	float groundJumpHeight = 30;
	float aerialJumpHeight = 25;
	float fallAcceleration = 1;
	float fallSpeed = 10;
	int doubleJump = 2;
	int maxDoubleJump = 2;
	bool onStage = false;
	bool jumpKeyHeld = false;
	bool fastFalling = false;
	bool isInStun = false;
	int moveThatHit=0;
	Move Move1;
	Move Move2;
	Move Move3;
	Move Move4;
	Move Move5;
};