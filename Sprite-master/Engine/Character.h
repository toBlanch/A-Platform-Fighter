#pragma once

class Character {
public:
	void UpdateCharacter(bool left, bool right, bool down, bool jump);
	bool IsOnStage();
	float x = 800;
	float y = 0;
	float vx = 0;
	float vy = 0;
	int width = 100;
	int height = 100;
	int walkSpeed = 10;
	int acceleration = 1;
	int groundJumpHeight = 30;
	int aerialJumpHeight = 25;
	int fallAcceleration = 1;
	int fallSpeed = 1;
	int doubleJump = 1;
	int maxDoubleJump = 1;
	bool onStage = false;
	bool jumpKeyHeld = false;
	bool fastFalling = false;
};