#pragma once

class Character {
public:
	void UpdateCharacter(bool left, bool right, bool down, bool jump, int stageX0, int stageY0, int stageX1, int stageY1);
	float x = 800;
	float y = 0;
	float vx = 0;
	float vy = 0;
	int width = 100;
	int height = 100;
	int speed = 0;
	int walkSpeed = 5;
	int aerialSpeed = 10;
	int acceleration = 0;
	int walkAcceleration = 1;
	int aerialAcceleration = 2;
	int groundJumpHeight = 30;
	int aerialJumpHeight = 25;
	int fallAcceleration = 1;
	int fallSpeed = 10;
	int doubleJump = 2;
	int maxDoubleJump = 2;
	bool onStage = false;
	bool jumpKeyHeld = false;
	bool fastFalling = false;
};