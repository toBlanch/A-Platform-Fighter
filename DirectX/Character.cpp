#include "Character.h"
#include "Game.h"

void Character::UpdateCharacter(bool left, bool right, bool up, bool down, bool jump, bool light, bool heavy, bool special, bool dodge, Platform Platforms[10]) {
	dodgePressed = dodge;
	if (stun == 0) { //If not in stun
		//If on stage
		for (int i = 0; i < 10; i++) {
			if (IsOnStage(Platforms[i], fallSpeed, down, i)) {
				doubleJump = maxDoubleJump + easyMode; //Refresh double jumps
				fastFalling = false; //Stop fast falling
				acceleration = walkAcceleration; //Sets acceleration to grounded acceleration
				speed = walkSpeed; //Sets speed to grounded speed
				onStage = true; //Confirm that you're on stage
				break;
			}
			else { //If you're not on stage
				if (easyMode) {
					acceleration = walkAcceleration; //Sets acceleration to aerial acceleration
					speed = walkSpeed; //Sets speed to aerial speed
				}
				else {
					acceleration = aerialAcceleration; //Sets acceleration to aerial acceleration
					speed = aerialSpeed; //Sets speed to aerial speed
				}
				onStage = false; //Confirm you're not on stage
			}
		}

		if (moveDuration > 0) { //If using a move
			left = false;
			right = false;
			up = false;
			jump = false;
			light = false;
			heavy = false;
			special = false;
			dodge = false; //Disable all player inputs apart from down
			moveDuration--;
		}
		else if (freeFallDuration > 0) {
			if (!onStage) {
				freeFallDuration = 30 / (5*easyMode+1); //So normally 30 and 30/6=5 in easy mode
			}
			down = false;
			jump = false;
			light = false;
			heavy = false;
			special = false;
			dodge = false;
			freeFallDuration--;
			speed = speed / 2;
			acceleration = acceleration / 4;
		}

		if (invincibility > 0) { //If you have invincibility
			invincibility--; //Reduce the timer
			if (light || heavy || special) { //If you have invincibility and are using a move
				invincibility = 0; //Remove your invincivility
			}
		}
		else if (invincibilityCooldown > 0) { //If the player is unable to dodge
			invincibilityCooldown--; //Reduce the time until the player can dodge again
			if (onStage) {
				groundTouchedAfterDodging = true;
			}
			else if (invincibilityCooldown == 1 && !groundTouchedAfterDodging) {
				invincibilityCooldown = 2;
			}
		}


		//Left and Right
		if (rightPriority) {
			rightPriority = right && left;
		}
		else if (left && right && !rightHeld) {
			rightPriority = true;
		}
		if (left && !rightPriority) { //If you're holding left
			vx -= acceleration; //Increase left velocity
			if (vx < -speed) { //If you're over terminal velocity
				vx = -speed; //Go to terminal velocity
			}
			if (onStage) {
				facingRight = false;
			}
		}
		else if (right) { //If you're holding right
			vx += acceleration; //Increase right velocity
			if (vx > speed) { //If you're over terminal velocity
				vx = speed; //Go to terminal velocity
			}
			if (onStage) {
				facingRight = true;
			}
		}
		if (!left && !right) { //If not moving left or right
			if (vx > 0) { //If moving right
				if (vx < acceleration / 2) { //If decreasing speed would make you move left
					vx = 0; //Set it to 0
				}
				else {
					vx -= acceleration / 2; //Decrease speed
				}
			}
			if (vx < 0) { //If moving left
				if (vx > -acceleration / 2) { //If decreasing speed would make you move right
					vx = 0; //Set it to 0
				}
				else {
					vx += acceleration / 2; //Decrease speed
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
			if (easyMode) {
				vy = -groundJumpHeight; //Start jumping (easy mode)
			}
			else {
				vy = -aerialJumpHeight; //Start jumping (Hard Mode)
			}
		}
		if (!(invincibilityCooldown > 0 && invincibility > 0)) {
			if (down && !onStage && !downHeld && !easyMode) { //If down key is held (only in Hard Mode)
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
		}

		for (int i = 0; i < moveArrayLength; i++) { //For every move
			moveArray[i].CheckStatus(x, y, Platforms); //Run the necesarry functions every frame
			if (moveArray[i].isPlayerAttachedToIt && moveArray[i].startUpDuration < 0 && moveArray[i].activeDuration >= 0) { //If an active move attaches the player to it
				vx = moveArray[i].vx;
				vy = moveArray[i].vy;
				if (moveArray[i].vy < 0) {
					freeFallDuration = 30 / (5 * easyMode + 1);
				}
			}
		}

		x += vx; //Increase X by speed
		y += vy; //Increase Y by speed

		if (moveDuration > 0 && onStage) { //If using a grounded move
			if (x < Platforms[platformOn].x0 - width) { //If falling out the left side
				x = Platforms[platformOn].x0 - width; //Put back on the stage
				vx = 0;
			}
			if (x > Platforms[platformOn].x1) { //If falling off the right side
				x = Platforms[platformOn].x1; //Put back on the stage
				vx = 0;
			}
		}

		isCollidingWithStage(Platforms, speed, fallSpeed, down);

		if (special && (!moveArray[0].isAttachedToPlayer + !moveArray[1].isAttachedToPlayer + !moveArray[2].isAttachedToPlayer + !moveArray[3].isAttachedToPlayer + !moveArray[4].isAttachedToPlayer < 4 || up)) { //If using a special attack
			for (int i = 0; i < moveArrayLength; i++) {
				if (moveArray[i].activeDuration < 0) {
					if (right) {
						facingRight = true;
					}
					else if (left) {
						facingRight = false;
					}
					if (up && !easyMode) { //If doing a move upwards (only in Hard Mode)
						moveArray[i].Activate(width, height, facingRight, upSpecialAdditionalX, upSpecialAdditionalY, upSpecialWidth, upSpecialHeight, upSpecialStunDuration, upSpecialScalarX, upSpecialScalarY, upSpecialFixedX, upSpecialFixedY, upSpecialVx, upSpecialVy, upSpecialAccelerationx, upSpecialAccelerationy, upSpecialDamage, upSpecialStartUpDuration, upSpecialActiveDuration, upSpecialEndLagDuration, upSpecialIsAttachedToPlayer, upSpecialIsPlayerAttachedToIt, upSpecialDisappearOnHit, upSpecialR, upSpecialG, upSpecialB);  //Initialise the move
						moveDuration = upSpecialStartUpDuration + moveArray[i].IsActiveDuration() + upSpecialEndLagDuration; //Set the player lag
					}
					else if (down && !easyMode) { //If doing a move downwards (only in Hard Mode)
						moveArray[i].Activate(width, height, facingRight, downSpecialAdditionalX, downSpecialAdditionalY, downSpecialWidth, downSpecialHeight, downSpecialStunDuration, downSpecialScalarX, downSpecialScalarY, downSpecialFixedX, downSpecialFixedY, downSpecialVx, downSpecialVy, downSpecialAccelerationx, downSpecialAccelerationy, downSpecialDamage, downSpecialStartUpDuration, downSpecialActiveDuration, downSpecialEndLagDuration, downSpecialIsAttachedToPlayer, downSpecialIsPlayerAttachedToIt, downSpecialDisappearOnHit, downSpecialR, downSpecialG, downSpecialB);  //Initialise the move
						moveDuration = downSpecialStartUpDuration + moveArray[i].IsActiveDuration() + downSpecialEndLagDuration; //Set the player lag
					}
					else { //If doing a move forwards
						moveArray[i].Activate(width, height, facingRight, forwardSpecialAdditionalX, forwardSpecialAdditionalY, forwardSpecialWidth, forwardSpecialHeight, forwardSpecialStunDuration, forwardSpecialScalarX, forwardSpecialScalarY, forwardSpecialFixedX, forwardSpecialFixedY, forwardSpecialVx, forwardSpecialVy, forwardSpecialAccelerationx, forwardSpecialAccelerationy, forwardSpecialDamage, forwardSpecialStartUpDuration, forwardSpecialActiveDuration, forwardSpecialEndLagDuration, forwardSpecialIsAttachedToPlayer, forwardSpecialIsPlayerAttachedToIt, forwardSpecialDisappearOnHit, forwardSpecialR, forwardSpecialG, forwardSpecialB);  //Initialise the move
						moveDuration = forwardSpecialStartUpDuration + moveArray[i].IsActiveDuration() + forwardSpecialEndLagDuration; //Set the player lag
					}
					break; //End the loop
				}
			}
		}
		else if (light && onStage) { //If using a light attack
			for (int i = 0; i < moveArrayLength; i++) { //For each move
				if (moveArray[i].activeDuration < 0) {
					if (right) {
						facingRight = true;
					}
					else if (left) {
						facingRight = false;
					}
					if (up && !easyMode) { //If doing a move upwards (only in Hard Mode)
						moveArray[i].Activate(width, height, facingRight, upLightAdditionalX, upLightAdditionalY, upLightWidth, upLightHeight, upLightStunDuration, upLightScalarX, upLightScalarY, upLightFixedX, upLightFixedY, upLightVx, upLightVy, upLightAccelerationx, upLightAccelerationy, upLightDamage, upLightStartUpDuration, upLightActiveDuration, upLightEndLagDuration, upLightIsAttachedToPlayer, upLightIsPlayerAttachedToIt, upLightDisappearOnHit, upLightR, upLightG, upLightB);  //Initialise the move
						moveDuration = upLightStartUpDuration + moveArray[i].IsActiveDuration() + upLightEndLagDuration; //Set the player lag
					}
					else if (down && !easyMode) { //If doing a move downwards (only in Hard Mode)
						moveArray[i].Activate(width, height, facingRight, downLightAdditionalX, downLightAdditionalY, downLightWidth, downLightHeight, downLightStunDuration, downLightScalarX, downLightScalarY, downLightFixedX, downLightFixedY, downLightVx, downLightVy, downLightAccelerationx, downLightAccelerationy, downLightDamage, downLightStartUpDuration, downLightActiveDuration, downLightEndLagDuration, downLightIsAttachedToPlayer, downLightIsPlayerAttachedToIt, downLightDisappearOnHit, downLightR, downLightG, downLightB);  //Initialise the move
						moveDuration = downLightStartUpDuration + moveArray[i].IsActiveDuration() + downLightEndLagDuration; //Set the player lagdownHeavy
					}
					else { //If doing a move forwards
						moveArray[i].Activate(width, height, facingRight, forwardLightAdditionalX, forwardLightAdditionalY, forwardLightWidth, forwardLightHeight, forwardLightStunDuration, forwardLightScalarX, forwardLightScalarY, forwardLightFixedX, forwardLightFixedY, forwardLightVx, forwardLightVy, forwardLightAccelerationx, forwardLightAccelerationy, forwardLightDamage, forwardLightStartUpDuration, forwardLightActiveDuration, forwardLightEndLagDuration, forwardLightIsAttachedToPlayer, forwardLightIsPlayerAttachedToIt, forwardLightDisappearOnHit, forwardLightR, forwardLightG, forwardLightB);  //Initialise the move
						moveDuration = forwardLightStartUpDuration + moveArray[i].IsActiveDuration() + forwardLightEndLagDuration; //Set the player lag
					}
					break;
				}
			}
		}
		else if (heavy && onStage) { //If using a heavy attack
			for (int i = 0; i < moveArrayLength; i++) {
				if (moveArray[i].activeDuration < 0) {
					if (right) {
						facingRight = true;
					}
					else if (left) {
						facingRight = false;
					}
					if (up && !easyMode) { //If doing a move upwards (only in Hard Mode)
						moveArray[i].Activate(width, height, facingRight, upHeavyAdditionalX, upHeavyAdditionalY, upHeavyWidth, upHeavyHeight, upHeavyStunDuration, upHeavyScalarX, upHeavyScalarY, upHeavyFixedX, upHeavyFixedY, upHeavyVx, upHeavyVy, upHeavyAccelerationx, upHeavyAccelerationy, upHeavyDamage, upHeavyStartUpDuration, upHeavyActiveDuration, upHeavyEndLagDuration, upHeavyIsAttachedToPlayer, upHeavyIsPlayerAttachedToIt, upHeavyDisappearOnHit, upHeavyR, upHeavyG, upHeavyB);  //Initialise the move
						moveDuration = upHeavyStartUpDuration + moveArray[i].IsActiveDuration() + upHeavyEndLagDuration; //Set the player lag
					}
					else if (down && !easyMode) { //If doing a move downwards (only in Hard Mode)
						moveArray[i].Activate(width, height, facingRight, downHeavyAdditionalX, downHeavyAdditionalY, downHeavyWidth, downHeavyHeight, downHeavyStunDuration, downHeavyScalarX, downHeavyScalarY, downHeavyFixedX, downHeavyFixedY, downHeavyVx, downHeavyVy, downHeavyAccelerationx, downHeavyAccelerationy, downHeavyDamage, downHeavyStartUpDuration, downHeavyActiveDuration, downHeavyEndLagDuration, downHeavyIsAttachedToPlayer, downHeavyIsPlayerAttachedToIt, downHeavyDisappearOnHit, downHeavyR, downHeavyG, downHeavyB);  //Initialise the move
						moveDuration = downHeavyStartUpDuration + moveArray[i].IsActiveDuration() + downHeavyEndLagDuration; //Set the player lag
					}
					else { //If doing a move forwards
						moveArray[i].Activate(width, height, facingRight, forwardHeavyAdditionalX, forwardHeavyAdditionalY, forwardHeavyWidth, forwardHeavyHeight, forwardHeavyStunDuration, forwardHeavyScalarX, forwardHeavyScalarY, forwardHeavyFixedX, forwardHeavyFixedY, forwardHeavyVx, forwardHeavyVy, forwardHeavyAccelerationx, forwardHeavyAccelerationy, forwardHeavyDamage, forwardHeavyStartUpDuration, forwardHeavyActiveDuration, forwardHeavyEndLagDuration, forwardHeavyIsAttachedToPlayer, forwardHeavyIsPlayerAttachedToIt, forwardHeavyDisappearOnHit, forwardHeavyR, forwardHeavyG, forwardHeavyB);  //Initialise the move
						moveDuration = forwardHeavyStartUpDuration + moveArray[i].IsActiveDuration() + forwardHeavyEndLagDuration; //Set the player lag
					}
					break;
				}
			}
		}
		else if (light || heavy) { //If using an aerial attack
			for (int i = 0; i < moveArrayLength; i++) {
				if (moveArray[i].activeDuration < 0) {
					if (up && !easyMode) { //If doing a move upwards (only in Hard Mode)
						if (right) {
							facingRight = true;
						}
						else if (left) {
							facingRight = false;
						}
						moveArray[i].Activate(width, height, facingRight, upAerialAdditionalX, upAerialAdditionalY, upAerialWidth, upAerialHeight, upAerialStunDuration, upAerialScalarX, upAerialScalarY, upAerialFixedX, upAerialFixedY, upAerialVx, upAerialVy, upAerialAccelerationx, upAerialAccelerationy, upAerialDamage, upAerialStartUpDuration, upAerialActiveDuration, upAerialEndLagDuration, upAerialIsAttachedToPlayer, upAerialIsPlayerAttachedToIt, upAerialDisappearOnHit, upAerialR, upAerialG, upAerialB);  //Initialise the move
						moveDuration = upAerialStartUpDuration + moveArray[i].IsActiveDuration() + upAerialEndLagDuration; //Set the player lag
					}
					else if (down && !easyMode) { //If doing a move downwards (only in Hard Mode)
						if (right) {
							facingRight = true;
						}
						else if (left) {
							facingRight = false;
						}
						moveArray[i].Activate(width, height, facingRight, downAerialAdditionalX, downAerialAdditionalY, downAerialWidth, downAerialHeight, downAerialStunDuration, downAerialScalarX, downAerialScalarY, downAerialFixedX, downAerialFixedY, downAerialVx, downAerialVy, downAerialAccelerationx, downAerialAccelerationy, downAerialDamage, downAerialStartUpDuration, downAerialActiveDuration, downAerialEndLagDuration, downAerialIsAttachedToPlayer, downAerialIsPlayerAttachedToIt, downAerialDisappearOnHit, downAerialR, downAerialG, downAerialB);  //Initialise the move
						moveDuration = downAerialStartUpDuration + moveArray[i].IsActiveDuration() + downAerialEndLagDuration; //Set the player lag
					}
					else if ((facingRight && left) || (!facingRight && right)) { //If doing a move backwards
						moveArray[i].Activate(width, height, facingRight, backAerialAdditionalX, backAerialAdditionalY, backAerialWidth, backAerialHeight, backAerialStunDuration, backAerialScalarX, backAerialScalarY, backAerialFixedX, backAerialFixedY, backAerialVx, backAerialVy, backAerialAccelerationx, backAerialAccelerationy, backAerialDamage, backAerialStartUpDuration, backAerialActiveDuration, backAerialEndLagDuration, backAerialIsAttachedToPlayer, backAerialIsPlayerAttachedToIt, backAerialDisappearOnHit, backAerialR, backAerialG, backAerialB);  //Initialise the move
						moveDuration = forwardAerialStartUpDuration + moveArray[i].IsActiveDuration() + forwardAerialEndLagDuration; //Set the player lag
					}
					else { //If doing a move forwards
						moveArray[i].Activate(width, height, facingRight, forwardAerialAdditionalX, forwardAerialAdditionalY, forwardAerialWidth, forwardAerialHeight, forwardAerialStunDuration, forwardAerialScalarX, forwardAerialScalarY, forwardAerialFixedX, forwardAerialFixedY, forwardAerialVx, forwardAerialVy, forwardAerialAccelerationx, forwardAerialAccelerationy, forwardAerialDamage, forwardAerialStartUpDuration, forwardAerialActiveDuration, forwardAerialEndLagDuration, forwardAerialIsAttachedToPlayer, forwardAerialIsPlayerAttachedToIt, forwardAerialDisappearOnHit, forwardAerialR, forwardAerialG, forwardAerialB);  //Initialise the move
						moveDuration = forwardAerialStartUpDuration + moveArray[i].IsActiveDuration() + forwardAerialEndLagDuration; //Set the player lag
					}
					break;
				}
			}
		}
		else if (dodge && invincibilityCooldown == 0 && !dodgeHeld && !easyMode) { //If dodging (only in Hard Mode)
			if (left) { //If holding left
				facingRight = false; //Face left
				vx = -speed; //Make the character move left
			}
			else if (right) { //If holding right
				facingRight = true; //Face right
				vx = speed; //Make the character move right
			}
			else { //If not holding left or right
				vx = 0; //Reset your horizontal momentum
			}
			if (!onStage) {
				if (up) { //If holding up
					vy = -fallSpeed / weight / weight; //Make the character move u
				}
				else if (down) { //If holding down
					vy = fallSpeed / weight / weight; //Make the character move down
				}
				else { //If not holding up or down
					vy = 0; //Reset your vertical momentum
				}
			}

			hitDuringDodge = false;
			invincibility = 20;
			moveDuration = 30 * weight; //The heavier you are, the more lag you have
			invincibilityCooldown = 120 * weight; //The heavier you are, the longer you have to wait before dodging again
			groundTouchedAfterDodging = false; //You have to touch the ground before dodgnig again
		}
	}
	else {
		stun--;
		x += vx;
		y += vy;

		isCollidingWithStage(Platforms, aerialSpeed, fallSpeed, down);
		OnlyProjectiles(Platforms);
	}
	downHeld = down;
	rightHeld = right;
	dodgeHeld = dodgePressed;
}

void Character::isCollidingWithStage(Platform Platforms[10], float horizontalSpeed, float verticalSpeed, bool down)
{
	bool onPlatform = false;
	for (int i = 0; i < 10; i++) {
		onPlatform = IsOnStage(Platforms[i],verticalSpeed, down, i) || onPlatform;
		if (Platforms[i].isSolid) {
			ClippingIntoStageFromLeft(Platforms[i], horizontalSpeed);
			ClippingIntoStageFromRight(Platforms[i], horizontalSpeed);
			ClippingIntoStageFromBottom(Platforms[i], verticalSpeed);
		}
	}
	onStage = onPlatform;
}

bool Character::IsOnStage(Platform platform, float speed, bool down, int i)
{
	if (x + width >= platform.x0 && x <= platform.x1 && //If X coordinate is over the stage
		y + height >= platform.y0 && y + height <= platform.y0 + vy * 2 //If Y coordinate is level with the stage
		&& vy >= 0
		&& !(!platform.isSolid && down)) {
		y = (float)platform.y0 - height; //Stop clipping
		if (invincibility != 0 && moveDuration != 0 && !onStage && !hitDuringDodge) { //If dashing into the ground
			invincibilityCooldown = 0;
			invincibility = 0;
			moveDuration = 0;
		}
		if (stun > 0 || vy > fallSpeed * 2) {
			vy *= -1;
		}
		platformOn = i;
		return true;
	}
	return false;
}

bool Character::ClippingIntoStageFromLeft(Platform platform, float speed)
{
	if (y + height > platform.y0 && y <= platform.y1 && x + width > platform.x0 && x + width <= platform.x0 + vx) {
		x = float(platform.x0 - width); //Stop clipping
		if (stun > 0 || vx > speed * 2) {
			vx *= -1;
		}
		return true;
	}
	return false;
}

bool Character::ClippingIntoStageFromRight(Platform platform, float speed)
{
	if (y + height > platform.y0 && y <= platform.y1 && x >= platform.x1 + vx && x < platform.x1) {
		x = (float)platform.x1; //Stop clipping
		if (stun > 0 || -vx > speed * 2) {
			vx *= -1;
		}
		return true;
	}
	return false;
}

bool Character::ClippingIntoStageFromBottom(Platform platform, float speed)
{
	if (x + width > platform.x0 && x < platform.x1 && y >= platform.y1 + vy && y <= platform.y1) {
		y = (float)platform.y1; //Stop clipping
		if (stun > 0 || -vy > speed * 2) {
			vy *= -1;
		}
		return true;
	}
	return false;
}

bool Character::IsAlive(int screenWidth, int screenHeight, int leniancy)
{
	if (x + width < 0 - leniancy ||
		x > screenWidth + leniancy ||
		(y + height < 0 - leniancy && stun > 0) ||
		y > screenHeight + leniancy
		) {
		lives--;
		vx = 0;
		vy = 0;
		playerPercentage = 0;
		stun = 0;
		moveDuration = 0;
		invincibilityCooldown = 0;
		for (int i = 0; i < moveArrayLength; i++) {
			moveArray[i].EndMove();
		}
		if (lives > 0) {
			y = 500 - height;
			x = screenWidth / 2;
			if (!easyMode) {
				invincibility = 300;
			}
		}
		else {
			invincibility = 0;
			return false;
		}
	}
	return true;
}

bool Character::MoveDraw(int move)
{
	return moveArray[move].Draw();
}

bool Character::IsMoveColliding(float player2x, float player2y, int player2Width, int player2Height)
{
	for (int i = 0; i < moveArrayLength; i++) {
		if (moveArray[i].IsMoveColliding(player2x, player2y, player2Width, player2Height)) {
			moveThatHit = i;
			return true;
		}
	}
	return false;
}

int Character::MoveX0(int move)
{
	return moveArray[move].x + moveArray[move].additionalX;
}

int Character::MoveY0(int move)
{
	return moveArray[move].y + moveArray[move].additionalY;

}

int Character::MoveX1(int move)
{
	return moveArray[move].x + moveArray[move].additionalX + moveArray[move].width;
}

int Character::MoveY1(int move)
{
	return moveArray[move].y + moveArray[move].height + moveArray[move].additionalY;
}

int Character::MoveR(int move)
{
	return moveArray[move].r;
}

int Character::MoveG(int move)
{
	return moveArray[move].g;
}

int Character::MoveB(int move)
{
	return moveArray[move].b;
}

int Character::MoveThatHitStun()
{
	return moveArray[moveThatHit].stunDuration;
}

float Character::MoveThatHitDamage()
{
	return moveArray[moveThatHit].damage;
}

float Character::MoveThatHitScalarX()
{
	return moveArray[moveThatHit].scalarX;
}

float Character::MoveThatHitScalarY()
{
	return moveArray[moveThatHit].scalarY;
}

float Character::MoveThatHitFixedX()
{
	return moveArray[moveThatHit].fixedX;
}

float Character::MoveThatHitFixedY()
{
	if ((!moveArray[moveThatHit].isPlayerAttachedToIt || moveArray[moveThatHit].disappearOnHit) && moveArray[moveThatHit].isAttachedToPlayer) {
		moveDuration -= moveArray[moveThatHit].activeDuration;
		moveArray[moveThatHit].activeDuration = 1;
	}
	return moveArray[moveThatHit].fixedY;
}

void Character::Initialise(std::vector<float>& parameters) {
	width = (int)parameters[0];
	height = (int)parameters[1];
	walkSpeed = parameters[2];
	aerialSpeed = parameters[3];
	aerialAcceleration = parameters[4];
	walkAcceleration = parameters[5];
	groundJumpHeight = (int)parameters[6];
	aerialJumpHeight = (int)parameters[7];
	fallAcceleration = parameters[8];
	fallSpeed = parameters[9];
	weight = parameters[10];
	maxDoubleJump = parameters[11];

	forwardLightAdditionalX = (int)parameters[12];
	forwardLightAdditionalY = (int)parameters[13];
	forwardLightWidth = (int)parameters[14];
	forwardLightHeight = (int)parameters[15];
	forwardLightStunDuration = (int)parameters[16];
	forwardLightScalarX = parameters[17];
	forwardLightScalarY = parameters[18];
	forwardLightFixedX = parameters[19];
	forwardLightFixedY = parameters[20];
	forwardLightVx = parameters[21];
	forwardLightVy = parameters[22];
	forwardLightAccelerationx = parameters[23];
	forwardLightAccelerationy = parameters[24];
	forwardLightDamage = parameters[25];
	forwardLightStartUpDuration = (int)parameters[26];
	forwardLightActiveDuration = (int)parameters[27];
	forwardLightEndLagDuration = (int)parameters[28];
	forwardLightIsAttachedToPlayer = parameters[29];
	forwardLightIsPlayerAttachedToIt = parameters[30];
	forwardLightDisappearOnHit = parameters[31];

	upLightAdditionalX = (int)parameters[32];
	upLightAdditionalY = (int)parameters[33];
	upLightWidth = (int)parameters[34];
	upLightHeight = (int)parameters[35];
	upLightStunDuration = (int)parameters[36];
	upLightScalarX = parameters[37];
	upLightScalarY = parameters[38];
	upLightFixedX = parameters[39];
	upLightFixedY = parameters[40];
	upLightVx = parameters[41];
	upLightVy = parameters[42];
	upLightAccelerationx = parameters[43];
	upLightAccelerationy = parameters[44];
	upLightDamage = parameters[45];
	upLightStartUpDuration = (int)parameters[46];
	upLightActiveDuration = (int)parameters[47];
	upLightEndLagDuration = (int)parameters[48];
	upLightIsAttachedToPlayer = parameters[49];
	upLightIsPlayerAttachedToIt = parameters[50];
	upLightDisappearOnHit = parameters[51];

	downLightAdditionalX = (int)parameters[52];
	downLightAdditionalY = (int)parameters[53];
	downLightWidth = (int)parameters[54];
	downLightHeight = (int)parameters[55];
	downLightStunDuration = (int)parameters[56];
	downLightScalarX = parameters[57];
	downLightScalarY = parameters[58];
	downLightFixedX = parameters[59];
	downLightFixedY = parameters[60];
	downLightVx = parameters[61];
	downLightVy = parameters[62];
	downLightAccelerationx = parameters[63];
	downLightAccelerationy = parameters[64];
	downLightDamage = parameters[65];
	downLightStartUpDuration = (int)parameters[66];
	downLightActiveDuration = (int)parameters[67];
	downLightEndLagDuration = (int)parameters[68];
	downLightIsAttachedToPlayer = parameters[69];
	downLightIsPlayerAttachedToIt = parameters[70];
	downLightDisappearOnHit = parameters[71];

	forwardHeavyAdditionalX = (int)parameters[72];
	forwardHeavyAdditionalY = (int)parameters[73];
	forwardHeavyWidth = (int)parameters[74];
	forwardHeavyHeight = (int)parameters[75];
	forwardHeavyStunDuration = (int)parameters[76];
	forwardHeavyScalarX = parameters[77];
	forwardHeavyScalarY = parameters[78];
	forwardHeavyFixedX = parameters[79];
	forwardHeavyFixedY = parameters[80];
	forwardHeavyVx = parameters[81];
	forwardHeavyVy = parameters[82];
	forwardHeavyAccelerationx = parameters[83];
	forwardHeavyAccelerationy = parameters[84];
	forwardHeavyDamage = parameters[85];
	forwardHeavyStartUpDuration = (int)parameters[86];
	forwardHeavyActiveDuration = (int)parameters[87];
	forwardHeavyEndLagDuration = (int)parameters[88];
	forwardHeavyIsAttachedToPlayer = parameters[89];
	forwardHeavyIsPlayerAttachedToIt = parameters[90];
	forwardHeavyDisappearOnHit = parameters[91];

	upHeavyAdditionalX = (int)parameters[92];
	upHeavyAdditionalY = (int)parameters[93];
	upHeavyWidth = (int)parameters[94];
	upHeavyHeight = (int)parameters[95];
	upHeavyStunDuration = (int)parameters[96];
	upHeavyScalarX = parameters[97];
	upHeavyScalarY = parameters[98];
	upHeavyFixedX = parameters[99];
	upHeavyFixedY = parameters[100];
	upHeavyVx = parameters[101];
	upHeavyVy = parameters[102];
	upHeavyAccelerationx = parameters[103];
	upHeavyAccelerationy = parameters[104];
	upHeavyDamage = parameters[105];
	upHeavyStartUpDuration = (int)parameters[106];
	upHeavyActiveDuration = (int)parameters[107];
	upHeavyEndLagDuration = (int)parameters[108];
	upHeavyIsAttachedToPlayer = parameters[109];
	upHeavyIsPlayerAttachedToIt = parameters[110];
	upHeavyDisappearOnHit = parameters[111];

	downHeavyAdditionalX = (int)parameters[112];
	downHeavyAdditionalY = (int)parameters[113];
	downHeavyWidth = (int)parameters[114];
	downHeavyHeight = (int)parameters[115];
	downHeavyStunDuration = (int)parameters[116];
	downHeavyScalarX = parameters[117];
	downHeavyScalarY = parameters[118];
	downHeavyFixedX = parameters[119];
	downHeavyFixedY = parameters[120];
	downHeavyVx = parameters[121];
	downHeavyVy = parameters[122];
	downHeavyAccelerationx = parameters[123];
	downHeavyAccelerationy = parameters[124];
	downHeavyDamage = parameters[125];
	downHeavyStartUpDuration = (int)parameters[126];
	downHeavyActiveDuration = (int)parameters[127];
	downHeavyEndLagDuration = (int)parameters[128];
	downHeavyIsAttachedToPlayer = parameters[129];
	downHeavyIsPlayerAttachedToIt = parameters[130];
	downHeavyDisappearOnHit = parameters[131];

	forwardAerialAdditionalX = (int)parameters[132];
	forwardAerialAdditionalY = (int)parameters[133];
	forwardAerialWidth = (int)parameters[134];
	forwardAerialHeight = (int)parameters[135];
	forwardAerialStunDuration = (int)parameters[136];
	forwardAerialScalarX = parameters[137];
	forwardAerialScalarY = parameters[138];
	forwardAerialFixedX = parameters[139];
	forwardAerialFixedY = parameters[140];
	forwardAerialVx = parameters[141];
	forwardAerialVy = parameters[142];
	forwardAerialAccelerationx = parameters[143];
	forwardAerialAccelerationy = parameters[144];
	forwardAerialDamage = parameters[145];
	forwardAerialStartUpDuration = (int)parameters[146];
	forwardAerialActiveDuration = (int)parameters[147];
	forwardAerialEndLagDuration = (int)parameters[148];
	forwardAerialIsAttachedToPlayer = parameters[149];
	forwardAerialIsPlayerAttachedToIt = parameters[150];
	forwardAerialDisappearOnHit = parameters[151];

	backAerialAdditionalX = (int)parameters[152];
	backAerialAdditionalY = (int)parameters[153];
	backAerialWidth = (int)parameters[154];
	backAerialHeight = (int)parameters[155];
	backAerialStunDuration = (int)parameters[156];
	backAerialScalarX = parameters[157];
	backAerialScalarY = parameters[158];
	backAerialFixedX = parameters[159];
	backAerialFixedY = parameters[160];
	backAerialVx = parameters[161];
	backAerialVy = parameters[162];
	backAerialAccelerationx = parameters[163];
	backAerialAccelerationy = parameters[164];
	backAerialDamage = parameters[165];
	backAerialStartUpDuration = (int)parameters[166];
	backAerialActiveDuration = (int)parameters[167];
	backAerialEndLagDuration = (int)parameters[168];
	backAerialIsAttachedToPlayer = parameters[169];
	backAerialIsPlayerAttachedToIt = parameters[170];
	backAerialDisappearOnHit = parameters[171];

	upAerialAdditionalX = (int)parameters[172];
	upAerialAdditionalY = (int)parameters[173];
	upAerialWidth = (int)parameters[174];
	upAerialHeight = (int)parameters[175];
	upAerialStunDuration = (int)parameters[176];
	upAerialScalarX = parameters[177];
	upAerialScalarY = parameters[178];
	upAerialFixedX = parameters[179];
	upAerialFixedY = parameters[180];
	upAerialVx = parameters[181];
	upAerialVy = parameters[182];
	upAerialAccelerationx = parameters[183];
	upAerialAccelerationy = parameters[184];
	upAerialDamage = parameters[185];
	upAerialStartUpDuration = (int)parameters[186];
	upAerialActiveDuration = (int)parameters[187];
	upAerialEndLagDuration = (int)parameters[188];
	upAerialIsAttachedToPlayer = parameters[189];
	upAerialIsPlayerAttachedToIt = parameters[190];
	upAerialDisappearOnHit = parameters[191];

	downAerialAdditionalX = (int)parameters[192];
	downAerialAdditionalY = (int)parameters[193];
	downAerialWidth = (int)parameters[194];
	downAerialHeight = (int)parameters[195];
	downAerialStunDuration = (int)parameters[196];
	downAerialScalarX = parameters[197];
	downAerialScalarY = parameters[198];
	downAerialFixedX = parameters[199];
	downAerialFixedY = parameters[200];
	downAerialVx = parameters[201];
	downAerialVy = parameters[202];
	downAerialAccelerationx = parameters[203];
	downAerialAccelerationy = parameters[204];
	downAerialDamage = parameters[205];
	downAerialStartUpDuration = (int)parameters[206];
	downAerialActiveDuration = (int)parameters[207];
	downAerialEndLagDuration = (int)parameters[208];
	downAerialIsAttachedToPlayer = parameters[209];
	downAerialIsPlayerAttachedToIt = parameters[210];
	downAerialDisappearOnHit = parameters[211];

	forwardSpecialAdditionalX = (int)parameters[212];
	forwardSpecialAdditionalY = (int)parameters[213];
	forwardSpecialWidth = (int)parameters[214];
	forwardSpecialHeight = (int)parameters[215];
	forwardSpecialStunDuration = (int)parameters[216];
	forwardSpecialScalarX = parameters[217];
	forwardSpecialScalarY = parameters[218];
	forwardSpecialFixedX = parameters[219];
	forwardSpecialFixedY = parameters[220];
	forwardSpecialVx = parameters[221];
	forwardSpecialVy = parameters[222];
	forwardSpecialAccelerationx = parameters[223];
	forwardSpecialAccelerationy = parameters[224];
	forwardSpecialDamage = parameters[225];
	forwardSpecialStartUpDuration = (int)parameters[226];
	forwardSpecialActiveDuration = (int)parameters[227];
	forwardSpecialEndLagDuration = (int)parameters[228];
	forwardSpecialIsAttachedToPlayer = parameters[229];
	forwardSpecialIsPlayerAttachedToIt = parameters[230];
	forwardSpecialDisappearOnHit = parameters[231];

	upSpecialAdditionalX = (int)parameters[232];
	upSpecialAdditionalY = (int)parameters[233];
	upSpecialWidth = (int)parameters[234];
	upSpecialHeight = (int)parameters[235];
	upSpecialStunDuration = (int)parameters[236];
	upSpecialScalarX = parameters[237];
	upSpecialScalarY = parameters[238];
	upSpecialFixedX = parameters[239];
	upSpecialFixedY = parameters[240];
	upSpecialVx = parameters[241];
	upSpecialVy = parameters[242];
	upSpecialAccelerationx = parameters[243];
	upSpecialAccelerationy = parameters[244];
	upSpecialDamage = parameters[245];
	upSpecialStartUpDuration = (int)parameters[246];
	upSpecialActiveDuration = (int)parameters[247];
	upSpecialEndLagDuration = (int)parameters[248];
	upSpecialIsAttachedToPlayer = parameters[249];
	upSpecialIsPlayerAttachedToIt = parameters[250];
	upSpecialDisappearOnHit = parameters[251];

	downSpecialAdditionalX = (int)parameters[252];
	downSpecialAdditionalY = (int)parameters[253];
	downSpecialWidth = (int)parameters[254];
	downSpecialHeight = (int)parameters[255];
	downSpecialStunDuration = (int)parameters[256];
	downSpecialScalarX = parameters[257];
	downSpecialScalarY = parameters[258];
	downSpecialFixedX = parameters[259];
	downSpecialFixedY = parameters[260];
	downSpecialVx = parameters[261];
	downSpecialVy = parameters[262];
	downSpecialAccelerationx = parameters[263];
	downSpecialAccelerationy = parameters[264];
	downSpecialDamage = parameters[265];
	downSpecialStartUpDuration = (int)parameters[266];
	downSpecialActiveDuration = (int)parameters[267];
	downSpecialEndLagDuration = (int)parameters[268];
	downSpecialIsAttachedToPlayer = parameters[269];
	downSpecialIsPlayerAttachedToIt = parameters[270];
	downSpecialDisappearOnHit = parameters[271];
	forwardLightR = parameters[272];
	forwardLightG = parameters[273];
	forwardLightB = parameters[274];
	upLightR = parameters[275];
	upLightG = parameters[276];
	upLightB = parameters[277];
	downLightR = parameters[278];
	downLightG = parameters[279];
	downLightB = parameters[280];
	forwardHeavyR = parameters[281];
	forwardHeavyG = parameters[282];
	forwardHeavyB = parameters[283];
	upHeavyR = parameters[284];
	upHeavyG = parameters[285];
	upHeavyB = parameters[286];
	downHeavyR = parameters[287];
	downHeavyG = parameters[288];
	downHeavyB = parameters[289];
	forwardAerialR = parameters[290];
	forwardAerialG = parameters[291];
	forwardAerialB = parameters[292];
	backAerialR = parameters[293];
	backAerialG = parameters[294];
	backAerialB = parameters[295];
	upAerialR = parameters[296];
	upAerialG = parameters[297];
	upAerialB = parameters[298];
	downAerialR = parameters[299];
	downAerialG = parameters[300];
	downAerialB = parameters[301];
	forwardSpecialR = parameters[302];
	forwardSpecialG = parameters[303];
	forwardSpecialB = parameters[304];
	upSpecialR = parameters[305];
	upSpecialG = parameters[306];
	upSpecialB = parameters[307];
	downSpecialR = parameters[308];
	downSpecialG = parameters[309];
	downSpecialB = parameters[310];
	moveArrayLength = sizeof(moveArray) / sizeof(*moveArray);
	Restart();
}

void Character::IsHit(int stunReferral, float damageReferral, int fixedXReferral, int fixedYReferral, int scalarXReferral, int scalarYReferral) {
	if (invincibility == 0) {
		stun = stunReferral * 2 / (2 + easyMode); //2/3rds of the original value in easy mode
		playerPercentage += damageReferral;
		if (playerPercentage >= 100) {
			playerPercentage = 99.9;
		}
		vx = (fixedXReferral + scalarXReferral * playerPercentage / 100) / weight * (1 + easyMode); //Doubled in easy mode
		vy = (fixedYReferral + scalarYReferral * playerPercentage / 100) / weight * (1 + easyMode); //Doubled in easy mode
		moveDuration = 0;
		freeFallDuration = 0;
		for (int i = 0; i < moveArrayLength; i++) {
			moveArray[i].PlayerIsHit();
		}
		jumpKeyHeld = false;
		downHeld = false;
	}
	else {
		if (moveDuration != 0) { //This check does nothing currently but could save me in the future
			hitDuringDodge = true;
		}
	}
}

void Character::Restart()
{
	lives = 3;
	for (int i = 0; i < moveArrayLength; i++) {
		moveArray[i].EndMove();
	}
	vx = 0;
	vy = 0;
	moveDuration = 0;
	stun = 0;
	playerPercentage = 0;
	invincibility = 0;
	invincibilityCooldown = 0;
	freeFallDuration = 0;
	fastFalling = false;
}

void Character::OnlyProjectiles(Platform Platforms[10])
{
	for (int i = 0; i < moveArrayLength; i++) {
		moveArray[i].CheckStatus(x, y, Platforms);
	}
}