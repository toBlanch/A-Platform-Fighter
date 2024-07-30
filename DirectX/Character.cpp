#include "Character.h"
#include "Game.h"
#include "Inputs.h"

void Character::ReduceTimer(int& cooldown)
{
	if (cooldown > 0) {
		cooldown--;
	}
}

void Character::UpdateCharacterMoves(Platform platforms[10], bool onlyProjectiles)
{
	for (int i = 0; i < MOVE_ARRAY_LENGTH; i++) { //For every move
		moveArray[i].CheckStatus(x, y, platforms); //Run the necesarry functions every frame
		if (moveArray[i].stats.isPlayerAttachedToIt && moveArray[i].startUpDuration < 0 && moveArray[i].activeDuration >= 0) { //If an active move attaches the player to it
			moveCharacterIsAttachedTo = i;
		}
	}
}

void Character::UpdateCharacterPosition(Inputs inputs, Platform Platforms[10])
{
	if (moveCharacterIsAttachedTo != -1) { //If the character is attached to a move
		vx = moveArray[moveCharacterIsAttachedTo].isFacingRight ? moveArray[moveCharacterIsAttachedTo].vx : -moveArray[moveCharacterIsAttachedTo].vx;
		vy = moveArray[moveCharacterIsAttachedTo].vy;

		if (moveArray[moveCharacterIsAttachedTo].vy < 0) {
			freeFallDuration = 30 / (5 * easyMode + 1);
		}
	}
	else if (stun == 0) {
		//Left and Right
		if (inputs.left && inputs.right) {
			if (inputsHeld.left) { //If left was previously held, press right
				inputs.left = false;
				inputsHeld.left = true; //Ensure this happens if left is still held
				inputsHeld.right = false;
			}
			else { //If right or nothing was previously held, go left
				inputs.right = false;
				inputsHeld.right = true; //Ensure this happens if left is still held
				inputsHeld.left = false;
			}
		}
		else {
			inputsHeld.left = inputs.left;
			inputsHeld.right = inputs.right;
		}
		if (inputs.left) { //If you're holding left
			vx -= acceleration; //Increase left velocity
			if (vx < -speed) { //If you're over terminal velocity
				vx = -speed; //Go to terminal velocity
			}
			if (onStage) {
				facingRight = false;
			}
		}
		else if (inputs.right) { //If you're holding right
			vx += acceleration; //Increase right velocity
			if (vx > speed) { //If you're over terminal velocity
				vx = speed; //Go to terminal velocity
			}
			if (onStage) {
				facingRight = true;
			}
		}
		else { //If not moving left or right
			if (abs(vx) < acceleration / 2) { //If decreasing speed would make you move right
				vx = 0; //Set it to 0
			}
			else {
				if (vx > 0) { //If moving right
					vx -= acceleration / 2; //Decrease speed
				}
				if (vx < 0) { //If moving left
					vx += acceleration / 2; //Decrease speed
				}
			}
		}

		//Jumping
		if (inputs.jump) { //If you're not holding jump
			if (onStage) { //If on stage and jump key is held
				if (vy >= 0) { //If not already rising
					vy = -characterStats[characterID].groundJumpHeight; //Start jumping
					inputsHeld.jump = true; //Jump key is held
				}
			}
			else if (doubleJump > 0 && !inputsHeld.jump) { //If off stage, jumping, you have a double jump and the jump key is held
				inputsHeld.jump = true; //Set jump key held to true
				fastFalling = false; //Stop fast falling
				doubleJump -= 1; //Remove one double jump
				if (easyMode) {
					vy = -characterStats[characterID].groundJumpHeight; //Start jumping (easy mode)
				}
				else {
					vy = -characterStats[characterID].aerialJumpHeight; //Start jumping (Hard Mode)
				}
			}
		}

		if (!(invincibilityCooldown > 0 && invincibility > 0)) { //If not currently dodging
			if (inputs.down && !onStage && !inputsHeld.down && !easyMode) { //If down key is held (only in Hard Mode)
				fastFalling = true; //Start fast falling
			}
			if (fastFalling) {
				if (vy < characterStats[characterID].maxFallSpeed * 2) { //If not at terminal velocity
					vy += characterStats[characterID].fallAcceleration * 2; //Increase falling speed
					if (vy > characterStats[characterID].maxFallSpeed * 2) { //If over terminal velocity
						vy = characterStats[characterID].maxFallSpeed * 2; //Set to terminal velocity
					}
				}
			}
			else {
				if (vy < characterStats[characterID].maxFallSpeed) {//If not at terminal velocity
					vy += characterStats[characterID].fallAcceleration; //Increase falling speed
					if (vy > characterStats[characterID].maxFallSpeed) { //If over terminal velocity
						vy = characterStats[characterID].maxFallSpeed; //Set to terminal velocity
					}
				}
			}
		}
	}

	if (moveDuration > 0 && onStage) { //If using a grounded move
		if (x + vx < Platforms[platformOn].x0 - characterStats[characterID].width) { //If falling out the left side
			vx = Platforms[platformOn].x0 - characterStats[characterID].width - x; //Put back on the stage
		}
		if (x > Platforms[platformOn].x1) { //If falling off the right side
			vx = Platforms[platformOn].x1 - x; //Put back on the stage
		}
	}
	isCollidingWithStage(Platforms, speed, characterStats[characterID].maxFallSpeed, inputs.down);

	x += vx; //Increase X by speed
	y += vy; //Increase Y by speed
}

void Character::isCollidingWithStage(Platform Platforms[10], float horizontalSpeed, float verticalSpeed, bool down)
{
	bool onPlatform = false;
	for (int i = 0; i < 10; i++) {
		onPlatform = IsOnStage(Platforms[i], verticalSpeed, down, i) || onPlatform;
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
	float predictedx = x + vx;
	float predictedy = y + vy;

	if (predictedx + characterStats[characterID].width >= platform.x0 && predictedx <= platform.x1 && //If X coordinate is over the stage
		predictedy + characterStats[characterID].height >= platform.y0 && predictedy + characterStats[characterID].height <= platform.y0 + vy * 2 //If Y coordinate is level with the stage
		&& vy >= 0
		&& !(!platform.isSolid && down)) {

		if (stun > 0 || vy > characterStats[characterID].maxFallSpeed * 2) {
			vy = -1 * vy - ((float)platform.y0 - characterStats[characterID].height - y); //Stop clipping
		}
		else {
			vy = (float)platform.y0 - characterStats[characterID].height - y; //Stop clipping
		}
		if (invincibility != 0 && moveDuration != 0 && !onStage && !hitDuringDodge) { //If dashing into the ground
			invincibilityCooldown = 0;
			invincibility = 0;
			moveDuration = 0;
		}
		platformOn = i;
		return true;
	}
	return false;
}

bool Character::ClippingIntoStageFromLeft(Platform platform, float speed)
{
	float predictedx = x + vx;
	float predictedy = y + vy;

	if (predictedy + characterStats[characterID].height > platform.y0 && predictedy <= platform.y1 && predictedx + characterStats[characterID].width > platform.x0 && predictedx + characterStats[characterID].width <= platform.x0 + vx) {
		if (stun > 0 || vx > speed * 2) {
			vx = -1 * vx - (vx = float(platform.x0 - characterStats[characterID].width) - x);
		}
		else {
			vx = float(platform.x0 - characterStats[characterID].width) - x; //Stop clipping
		}
		return true;
	}
	return false;
}

bool Character::ClippingIntoStageFromRight(Platform platform, float speed)
{
	float predictedx = x + vx;
	float predictedy = y + vy;

	if (predictedy + characterStats[characterID].height > platform.y0 && predictedy <= platform.y1 && predictedx >= platform.x1 + vx && predictedx < platform.x1) {
		if (stun > 0 || -vx > speed * 2) {
			vx = -1 * vx - (float)platform.x1 - x;
		}
		else {
			vx = (float)platform.x1 - x; //Stop clipping
		}
		return true;
	}
	return false;
}

bool Character::ClippingIntoStageFromBottom(Platform platform, float speed)
{
	float predictedx = x + vx;
	float predictedy = y + vy;

	if (predictedx + characterStats[characterID].width > platform.x0 && predictedx < platform.x1 && predictedy >= platform.y1 + vy && predictedy <= platform.y1) {
		if (stun > 0 || -vy > speed * 2) {
			vy = -1 * vy - ((float)platform.y1 - y);
		}
		else {
			vy = (float)platform.y1 - y; //Stop clipping
		}
		return true;
	}
	return false;
}

Character::Character(CharacterTemplate rCharacterTemplates[9])
{
	characterStats = rCharacterTemplates;
}

void Character::ChangeCharacterID(bool isIncreasing, CharacterTemplate characterTemplates)
{
	if (isIncreasing) {
		if (characterID < 8) {
			characterID++;
		}
	}
	else {
		if (characterID > 0) {
			characterID--;
		}
	}

}

void Character::UpdateCharacter(Inputs inputs, Platform platforms[10]) {
	bool dodgePressed = inputs.dodge; //Because dodge gets disabled when moveDuration != 0 I need an accurate measure of if dodge is pressed
	moveCharacterIsAttachedTo = -1;
	UpdateCharacterMoves(platforms, false);

	if (stun == 0) { //If not in stun
		//If on stage
		for (int i = 0; i < 10; i++) {
			if (IsOnStage(platforms[i], characterStats[characterID].maxFallSpeed, inputs.down, i)) {
				doubleJump = characterStats[characterID].maxDoubleJump + easyMode; //Refresh double jumps
				fastFalling = false; //Stop fast falling
				acceleration = characterStats[characterID].walkAcceleration; //Sets acceleration to grounded acceleration
				speed = characterStats[characterID].maxWalkSpeed; //Sets speed to grounded speed
				onStage = true; //Confirm that you're on stage
				groundTouchedAfterDodging = true;
				break;
			}
			else { //If you're not on stage
				if (easyMode) {
					acceleration = characterStats[characterID].walkAcceleration; //Sets acceleration to aerial acceleration
					speed = characterStats[characterID].maxWalkSpeed; //Sets speed to aerial speed
				}
				else {
					acceleration = characterStats[characterID].aerialAcceleration; //Sets acceleration to aerial acceleration
					speed = characterStats[characterID].maxAerialSpeed; //Sets speed to aerial speed
				}
				onStage = false; //Confirm you're not on stage

			}
		}

		if (moveDuration > 0) { //If using a move
			inputs.left = false;
			inputs.right = false;
			inputs.up = false;
			inputs.jump = false;
			inputs.light = false;
			inputs.heavy = false;
			inputs.special = false;
			inputs.dodge = false; //Disable all player inputs apart from down
			moveDuration--;
		}
		else if (freeFallDuration > 0) {
			if (!onStage) {
				freeFallDuration = 30 / (5 * easyMode + 1); //So normally 30 and 30/6=5 in easy mode
			}
			inputs.down = false;
			inputs.jump = false;
			inputs.light = false;
			inputs.heavy = false;
			inputs.special = false;
			inputs.dodge = false;
			freeFallDuration--;
			speed = speed / 2;
			acceleration = acceleration / 4;
		}
	}

	UpdateCharacterPosition(inputs, platforms);

	for (int i = 0; i < MOVE_ARRAY_LENGTH; i++) {
		if (moveArray[i].activeDuration < 0) {
			int freeMoveSlots = 0;
			for (int j = 0; j < MOVE_ARRAY_LENGTH; j++) {
				freeMoveSlots += moveArray[j].activeDuration < 0; //If a move has no active duration 
			}
			if (inputs.special && (freeMoveSlots >= 2 || inputs.up)) { //If using a special attack AND less than 4 of the 5 move slots are taken up or it's a recovery move
				if (inputs.right) {
					facingRight = true;
				}
				else if (inputs.left) {
					facingRight = false;
				}
				if (inputs.up && !easyMode) { //If doing a move upwards (only in Hard Mode)
					moveArray[i].Activate(characterStats[characterID].width, facingRight, characterStats[characterID].upSpecial);  //Initialise the move
					moveDuration = moveArray[i].startUpDuration + moveArray[i].IsActiveDuration() + moveArray[i].endLagDuration; //Set the player lag
				}
				else if (inputs.down && !easyMode) { //If doing a move downwards (only in Hard Mode)
					moveArray[i].Activate(characterStats[characterID].width, facingRight, characterStats[characterID].downSpecial);  //Initialise the move
					moveDuration = moveArray[i].startUpDuration + moveArray[i].IsActiveDuration() + moveArray[i].endLagDuration; //Set the player lag
				}
				else { //If doing a move forwards
					moveArray[i].Activate(characterStats[characterID].width, facingRight, characterStats[characterID].forwardSpecial);  //Initialise the move
					moveDuration = moveArray[i].startUpDuration + moveArray[i].IsActiveDuration() + moveArray[i].endLagDuration; //Set the player lag
				}
			}
			else if (inputs.light && onStage) { //If using a light attack
				if (inputs.right) {
					facingRight = true;
				}
				else if (inputs.left) {
					facingRight = false;
				}
				if (inputs.up && !easyMode) { //If doing a move upwards (only in Hard Mode)
					moveArray[i].Activate(characterStats[characterID].width, facingRight, characterStats[characterID].upLight);  //Initialise the move
					moveDuration = moveArray[i].startUpDuration + moveArray[i].IsActiveDuration() + moveArray[i].endLagDuration; //Set the player lag
				}
				else if (inputs.down && !easyMode) { //If doing a move downwards (only in Hard Mode)
					moveArray[i].Activate(characterStats[characterID].width, facingRight, characterStats[characterID].downLight);  //Initialise the move
					moveDuration = moveArray[i].startUpDuration + moveArray[i].IsActiveDuration() + moveArray[i].endLagDuration; //Set the player lagdownHeavy
				}
				else { //If doing a move forwards
					moveArray[i].Activate(characterStats[characterID].width, facingRight, characterStats[characterID].forwardLight);  //Initialise the move
					moveDuration = moveArray[i].startUpDuration + moveArray[i].IsActiveDuration() + moveArray[i].endLagDuration; //Set the player lag
				}
			}
			else if (inputs.heavy && onStage) { //If using a heavy attack
				if (inputs.right) {
					facingRight = true;
				}
				else if (inputs.left) {
					facingRight = false;
				}
				if (inputs.up && !easyMode) { //If doing a move upwards (only in Hard Mode)
					moveArray[i].Activate(characterStats[characterID].width, facingRight, characterStats[characterID].upHeavy);  //Initialise the move
					moveDuration = moveArray[i].startUpDuration + moveArray[i].IsActiveDuration() + moveArray[i].endLagDuration; //Set the player lag
				}
				else if (inputs.down && !easyMode) { //If doing a move downwards (only in Hard Mode)
					moveArray[i].Activate(characterStats[characterID].width, facingRight, characterStats[characterID].downHeavy);  //Initialise the move
					moveDuration = moveArray[i].startUpDuration + moveArray[i].IsActiveDuration() + moveArray[i].endLagDuration; //Set the player lag
				}
				else { //If doing a move forwards
					moveArray[i].Activate(characterStats[characterID].width, facingRight, characterStats[characterID].forwardHeavy);  //Initialise the move
					moveDuration = moveArray[i].startUpDuration + moveArray[i].IsActiveDuration() + moveArray[i].endLagDuration; //Set the player lag
				}
			}
			else if (inputs.light || inputs.heavy) { //If using an aerial attack
				if (inputs.up && !easyMode) { //If doing a move upwards (only in Hard Mode)
					if (inputs.right) {
						facingRight = true;
					}
					else if (inputs.left) {
						facingRight = false;
					}
					moveArray[i].Activate(characterStats[characterID].width, facingRight, characterStats[characterID].upAerial);  //Initialise the move
					moveDuration = moveArray[i].startUpDuration + moveArray[i].IsActiveDuration() + moveArray[i].endLagDuration; //Set the player lag
				}
				else if (inputs.down && !easyMode) { //If doing a move downwards (only in Hard Mode)
					if (inputs.right) {
						facingRight = true;
					}
					else if (inputs.left) {
						facingRight = false;
					}
					moveArray[i].Activate(characterStats[characterID].width, facingRight, characterStats[characterID].downAerial);  //Initialise the move
					moveDuration = moveArray[i].startUpDuration + moveArray[i].IsActiveDuration() + moveArray[i].endLagDuration; //Set the player lag
				}
				else if ((facingRight && inputs.left) || (!facingRight && inputs.right)) { //If doing a move backwards
					moveArray[i].Activate(characterStats[characterID].width, facingRight, characterStats[characterID].backAerial);  //Initialise the move
					moveDuration = moveArray[i].startUpDuration + moveArray[i].IsActiveDuration() + moveArray[i].endLagDuration; //Set the player lag
				}
				else { //If doing a move forwards
					moveArray[i].Activate(characterStats[characterID].width, facingRight, characterStats[characterID].forwardAerial);  //Initialise the move
					moveDuration = moveArray[i].startUpDuration + moveArray[i].IsActiveDuration() + moveArray[i].endLagDuration; //Set the player lag
				}
			}
			break;
		}
	}
	if (inputs.dodge && invincibilityCooldown == 0 && !inputsHeld.dodge && moveDuration == 0 && groundTouchedAfterDodging && !easyMode) { //If dodging (only in Hard Mode)
		if (inputs.left) { //If holding left
			facingRight = false; //Face left
			vx = -speed; //Make the character move left
		}
		else if (inputs.right) { //If holding right
			facingRight = true; //Face right
			vx = speed; //Make the character move right
		}
		else { //If not holding left or right
			vx = 0; //Reset your horizontal momentum
		}
		if (!onStage) {
			if (inputs.up) { //If holding up
				vy = -characterStats[characterID].maxFallSpeed / characterStats[characterID].weight / characterStats[characterID].weight; //Make the character move u
			}
			else if (inputs.down) { //If holding down
				vy = characterStats[characterID].maxFallSpeed / characterStats[characterID].weight / characterStats[characterID].weight; //Make the character move down
			}
			else { //If not holding up or down
				vy = 0; //Reset your vertical momentum
			}
		}

		hitDuringDodge = false;
		invincibility = 20;
		moveDuration = 30 * characterStats[characterID].weight; //The heavier you are, the more lag you have
		invincibilityCooldown = 120 * characterStats[characterID].weight + invincibility; //The heavier you are, the longer you have to wait before dodging again
		groundTouchedAfterDodging = false; //You have to touch the ground before dodging again
	}
	ReduceTimer(stun);
	ReduceTimer(invincibility);
	ReduceTimer(invincibilityCooldown);
	inputsHeld = Inputs(inputsHeld.left, inputsHeld.right, inputsHeld.up, inputs.down, inputs.jump, inputsHeld.light, inputsHeld.heavy, inputsHeld.special, dodgePressed);
}

bool Character::IsAlive(int screenWidth, int screenHeight, int leniancy)
{
	if (x + characterStats[characterID].width < 0 - leniancy ||
		x > screenWidth + leniancy ||
		(y + characterStats[characterID].height < 0 - leniancy && stun > 0) ||
		y > screenHeight + leniancy
		) {
		lives--;
		vx = 0;
		vy = 0;
		playerPercentage = 0;
		stun = 0;
		moveDuration = 0;
		invincibilityCooldown = 0;
		for (int i = 0; i < MOVE_ARRAY_LENGTH; i++) {
			moveArray[i].EndMove();
		}
		if (lives > 0) {
			y = 500 - characterStats[characterID].height;
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

void Character::UpdateMoveCollision(Character& opposingPlayer)
{
	for (int i = 0; i < MOVE_ARRAY_LENGTH; i++) {
		if (!moveArray[i].hasHit && moveArray[i].activeDuration > 0 && moveArray[i].startUpDuration < 0) { //If the move has an active hitbox
			for (int j = 0; j <= 4; j++) {
				for (int k = 0; k <= 4; k++) {
					if (moveArray[i].x + moveArray[i].additionalX + moveArray[i].stats.width / 4 * j >= opposingPlayer.x && //If the X coordinate is greater than the player's
						moveArray[i].x + moveArray[i].additionalX + moveArray[i].stats.width / 4 * j <= opposingPlayer.x + opposingPlayer.characterStats[characterID].width && //If the x coordinate is less than the player's plus their characterStats[characterID].width
						moveArray[i].y + moveArray[i].stats.additionalY + moveArray[i].stats.height / 4 * k >= opposingPlayer.y && //If the Y coordniate is greater than the player's
						moveArray[i].y + moveArray[i].stats.additionalY + moveArray[i].stats.height / 4 * k <= opposingPlayer.y + opposingPlayer.characterStats[characterID].height //If the y coordinate is les than the player's plus their characterStats[characterID].height
						) { //If inside the player's coordinates
						if (moveArray[i].stats.disappearOnHit) {
							moveArray[i].activeDuration = 0; //Disable
						}
						else {
							moveArray[i].hasHit = true; //Stop the move from hitting again
						}
						opposingPlayer.IsHit(moveArray[i]);
						return; //The move has hit
					}
				}
			}
		}
	}
}

void Character::IsHit(Move moveHitWith) {
	if (invincibility == 0) {
		stun = moveHitWith.stats.stunDuration;
		if (easyMode) {
			stun = (int)((float)stun * 2 / 3); // stun is 2/3rds in easy mode
		}
		playerPercentage += moveHitWith.stats.damage;
		if (playerPercentage >= 100) {
			playerPercentage = 99.9;
		}
		vx = (moveHitWith.stats.fixedX + moveHitWith.stats.scalarX * playerPercentage / 100) / characterStats[characterID].weight * (1 + easyMode); //Doubled in easy mode
		if (!moveHitWith.isFacingRight) {
			vx = -vx;
		}
		vy = (moveHitWith.stats.fixedY + moveHitWith.stats.scalarY * playerPercentage / 100) / characterStats[characterID].weight * (1 + easyMode); //Doubled in easy mode
		moveDuration = 0;
		freeFallDuration = 0;
		for (int i = 0; i < MOVE_ARRAY_LENGTH; i++) {
			moveArray[i].PlayerIsHit();
		}
		inputsHeld.jump = false;
		inputsHeld.down = false;
	}
	else {
		if (moveDuration != 0) { //Ensures wavedashes cannot be performed if hit during the dodge
			hitDuringDodge = true;
		}
	}
}

void Character::Restart()
{
	lives = 3;
	for (int i = 0; i < MOVE_ARRAY_LENGTH; i++) {
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

Move Character::GetMove(int moveID)
{
	return moveArray[moveID];
}
