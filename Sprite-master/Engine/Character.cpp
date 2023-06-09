#include "Character.h"
#include "Game.h"

void Character::UpdateCharacter(bool left, bool right, bool down, bool jump, bool light, bool heavy, bool special, int stageX0, int stageY0, int stageX1, int stageY1) {
	if (stun == 0) {
		//If on stage
		if (
			x + width >= stageX0 && x <= stageX1 && //If X coordinate is over the stage
			y + height >= stageY0 && y + height <= stageY0 + fallSpeed * 2 //If Y coordinate is level with the stage
			) {
			doubleJump = maxDoubleJump; //Refresh double jumps
			fastFalling = false; //Stop fast falling
			acceleration = walkAcceleration; //Sets acceleration to grounded acceleration
			speed = walkSpeed; //Sets speed to grounded speed
			onStage = true; //Confirm that you're on stage
		}
		else { //If you're not on stage
			acceleration = aerialAcceleration; //Sets acceleration to aerial acceleration
			speed = aerialSpeed; //Sets speed to aerial speed
			onStage = false; //Confirm you're not on stage
		}

		if (moveDuration > 0) { //If not using a move
			left = false;
			right = false;
			down = false;
			jump = false;
			light = false;
			heavy = false;
			special = false;
			moveDuration--;
		}
		//Left and Right
		if (left) { //If you're holding left
			vx -= acceleration; //Increase left velocity
			if (vx < -speed) { //If you're over terminal velocity
				vx = -speed; //Go to terminal velocity
			}
		}
		if (right) { //If you're holding right
			vx += acceleration; //Increase right velocity
			if (vx > speed) { //If you're over terminal velocity
				vx = speed; //Go to terminal velocity
			}
		}
		if (!left && !right) { //If not moving left or right
			if (vx > 0) { //If moving right
				if (vx < acceleration / 5) { //If decreasing speed would make you move left
					vx = 0; //Set it to 0
				}
				else {
					vx -= acceleration / 5; //Decrease speed
				}
			}
			if (vx < 0) { //If moving left
				if (vx > -acceleration / 5) { //If decreasing speed would make you move right
					vx = 0; //Set it to 0
				}
				else {
					vx += acceleration / 5; //Decrease speed
				}
			}
		}

		//Jumping
		if (jump == false) { //If you're not holding jump
			jumpKeyHeld = false; //Confirm you're not holding jump
		}
		else if (onStage) { //If on stage and jump key is held
			if (vy >= 0) { //If not already rising
				vy = -groundJumpHeight; //Start jumping
				jumpKeyHeld = true; //Jump key is held
			}
		}
		else if (doubleJump > 0 && !jumpKeyHeld) { //If off stage, jumping, you have a double jump and the jump key is held
			jumpKeyHeld = true; //Set jump key held to true
			fastFalling = false; //Stop fast falling
			doubleJump -= 1; //Remove one double jump
			vy = -aerialJumpHeight; //Start jumping
		}

		if (down) { //If down key is held
			fastFalling = true; //Start fast falling
		}
		if (fastFalling) {
			if (vy < fallSpeed * 2) { //If not at terminal velocity
				vy += fallAcceleration * 2; //Increase falling speed
				if (vy > fallSpeed * 2) { //If over terminal velocity
					vy = fallSpeed * 2; //Set to terminal velocity
				}
			}
		}
		else {
			if (vy < fallSpeed) {//If not at terminal velocity
				vy += fallAcceleration; //Increase falling speed
				if (vy > fallSpeed) { //If over terminal velocity
					vy = fallSpeed; //Set to terminal velocity
				}
			}
		}

		x += vx; //Increase X by speed
		y += vy; //Increase Y by speed

		if (onStage) {
			if (vy > 0) { //If falling
				y = stageY0 - width; //Reset y to on stage
			}
		}
		else { //If off stage
			if (y + height >= stageY0 && y <= stageY1 && x + width > stageX0 && x + width <= stageX0 + speed) { //If clipping floato stage from the left
				x = stageX0 - width; //Stop clipping
			}
			else if (y + height >= stageY0 && y <= stageY1 && x >= stageX1 - speed && x < stageX1) { //If clipping floato stage from right
				x = stageX1; //Stop clipping
			}
			else if (x + width > stageX0 + speed && x + speed < stageX1 - speed && y > stageY1 - fallSpeed * 2 && y < stageY1) { //If clipping floato stage from bottom
				y = stageY1; //Stop clipping
			}
		}
		if (special) {
			x = 500;
		}
		if (light) {
			Move1.Activate(x, y, true);
			moveDuration = Move1.StartUp(1) + Move1.Duration(1) + Move1.EndLag(1);
		}
		if (heavy) {
			Move1.Activate(x, y, false);
			moveDuration = Move1.StartUp(1) + Move1.Duration(1) + Move1.EndLag(1);
		}
		Move1.CheckStatus(x, y);
	}
	else {
		stun--;
		x += vx;
		y += vy;
	}
}

bool Character::IsAlive(int stageWidth, int stageHeight, int leniancy)
{
	if (x + width<0 - leniancy ||
		x>stageWidth + leniancy ||
		(y+height < 0 - leniancy && isInStun) ||
		y > stageHeight + leniancy
		) {
		lives--;
		if (lives > 0) {
			y = 500;
			x = stageWidth / 2;
			vx = 0;
			vy = 0;
			playerPercentage = 0;
			return true;
		}
		else {
			vx = 0;
			vy = 0;
			playerPercentage = 0;
			return false;
		}
	}
	return true;
}

bool Character::MoveDraw(int move)
{
	if (move == 1) {
		return Move1.Draw();
	}
	return false;
}

bool Character::IsMoveColliding(int Player2x, int Player2y, int Player2width, int Player2height)
{
	if (Move1.IsMoveColliding(Player2x, Player2y, Player2width, Player2height)) {
		moveThatHit = 1;
	return true;
	}
	return false;
}

int Character::MoveX0(int move)
{
	if (move == 1) {
		return Move1.x;
	}
	return 0;
}

int Character::MoveY0(int move)
{
	if (move == 1) {
		return Move1.y;
	}
	return 0;
}

int Character::MoveX1(int move)
{
	if (move == 1) {
		return Move1.x+Move1.width;
	}
	return 0;
}

int Character::MoveY1(int move)
{
	if (move == 1) {
		return Move1.y+Move1.height;
	}
	return 0;
}

int Character::MoveThatHitStun()
{
	if (moveThatHit == 1) {
		return Move1.stunDuration;
	}
	return 0;
}

int Character::MoveThatHitDamage()
{
	if (moveThatHit == 1) {
		return Move1.damage;
	}
	return 0;
}

int Character::MoveThatHitScalarX()
{
	if (moveThatHit == 1) {
		return Move1.scalarX;
	}
	return 0;
}

int Character::MoveThatHitScalarY()
{
	if (moveThatHit == 1) {
		return Move1.scalarY;
	}
	return 0;
}

int Character::MoveThatHitFixedX()
{
	if (moveThatHit == 1) {
		return Move1.fixedX;
	}
	return 0;
}

int Character::MoveThatHitFixedY()
{
	if (moveThatHit == 1) {
		return Move1.fixedY;
	}
	return 0;
}

void Character::IsHit(int stunReferral, int damage, int fixedX, int fixedY, int scalarX, int scalarY)
{
	stun = stunReferral;
	playerPercentage = playerPercentage + damage;
	vx = fixedX + scalarX * playerPercentage / 100;
	vy = fixedY + scalarY * playerPercentage / 100;
}
