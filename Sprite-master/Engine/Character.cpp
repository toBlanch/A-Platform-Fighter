#include "Character.h"

void Character::UpdateCharacter(bool left, bool right, bool down, bool jump) {
	onStage = IsOnStage();
	if (jump == false) {
		jumpKeyHeld = false;
	}

	if (left&&vx>-walkSpeed) {
		vx -= acceleration;
	}
	if (right&&vx<walkSpeed) {
		vx += acceleration;
	}
	if (!left&&!right) {
		if (vx > 0) {
			if (vx < acceleration) {
				vx = 0;
			}
			else {
				vx -= acceleration;
			}
		}
		if (vx < 0) {
			if (vx < -acceleration) {
				vx = 0;
			}
			else {
				vx += acceleration;
			}
		}
	}
	if (onStage) {
		if (jump) {
			vy = -groundJumpHeight;
			jumpKeyHeld = true;
		}
	}
	else if (jump && doubleJump > 0 && jumpKeyHeld == false) {
		fastFalling = false;
		doubleJump-=1;
		vy = -aerialJumpHeight;
	}
	else {
		if (down) {
			fastFalling = true;
		}
		if (fastFalling) {
			if (vy < fallSpeed*2) {
				vy += fallAcceleration*2;
			}
		}
		else {
			if (vy < fallSpeed) {
				vy += fallAcceleration;
			}
		}
	}
	x += vx;
	y += vy;
}

bool Character::IsOnStage()
{
	if (x+width > 500 && x < 1420 && y+height > 800 && y < 980) {
		y = 800-width;
		doubleJump = maxDoubleJump;
		fastFalling = false;
		return true;
	}
	else {
		return false;
	}
}