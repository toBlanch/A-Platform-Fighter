#include "Character.h"
#include "Game.h"

void Character::UpdateCharacter(bool left, bool right, bool down, bool up, bool jump, bool light, bool heavy, bool special, int stageX0, int stageY0, int stageX1, int stageY1) {
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
			facingRight = false;
		}
		if (right) { //If you're holding right
			vx += acceleration; //Increase right velocity
			if (vx > speed) { //If you're over terminal velocity
				vx = speed; //Go to terminal velocity
			}
			facingRight = true;
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
		
		if (down && !onStage) { //If down key is held
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
				y = stageY0 - height; //Reset y to on stage
			}
		}
		else { //If off stage
			if (y + height >= stageY0 && y <= stageY1 && x + width > stageX0 && x + width <= stageX0 + speed) { //If clipping into stage from the left
				x = stageX0 - width; //Stop clipping
			}
			else if (y + height >= stageY0 && y <= stageY1 && x >= stageX1 - speed && x < stageX1) { //If clipping into stage from right
				x = stageX1; //Stop clipping
			}
			else if(x + width > stageX0 && x < stageX1 && y >= stageY0 - 2 * fallSpeed && y <= stageY1) {
				y = stageY1; //Stop clipping
			}
		}
		if (light && onStage) {
			if (Move1.activeDuration == 0) {
				if (up) {
					Move1.Activate(facingRight, x, y, upLightAdditionalX, upLightAdditionalY, upLightWidth, upLightHeight, upLightStunDuration, upLightScalarX, upLightScalarY, upLightFixedX, upLightFixedY, upLightVx, upLightVy, upLightDamage, upLightStartUpDuration, upLightActiveDuration, upLightEndLagDuration, upLightIsAttachedToPlayer, upLightDissapearOnHit);
					moveDuration = upLightStartUpDuration + Move1.IsActiveDuration() + upLightEndLagDuration;
				}
				else if (down) {
					Move1.Activate(facingRight, x, y, downLightAdditionalX, downLightAdditionalY, downLightWidth, downLightHeight, downLightStunDuration, downLightScalarX, downLightScalarY, downLightFixedX, downLightFixedY, downLightVx, downLightVy, downLightDamage, downLightStartUpDuration, downLightActiveDuration, downLightEndLagDuration, downLightIsAttachedToPlayer, downLightDissapearOnHit);
					moveDuration = downLightStartUpDuration + Move1.IsActiveDuration() + downLightEndLagDuration;
				}
				else{
					Move1.Activate(facingRight, x, y, forwardLightAdditionalX, forwardLightAdditionalY, forwardLightWidth, forwardLightHeight, forwardLightStunDuration, forwardLightScalarX, forwardLightScalarY, forwardLightFixedX, forwardLightFixedY, forwardLightVx, forwardLightVy, forwardLightDamage, forwardLightStartUpDuration, forwardLightActiveDuration, forwardLightEndLagDuration, forwardLightIsAttachedToPlayer, forwardLightDissapearOnHit);
					moveDuration = forwardLightStartUpDuration + Move1.IsActiveDuration() + forwardLightEndLagDuration;
				}
			}
			else if (Move2.activeDuration == 0) {
				if (up) {
					Move2.Activate(facingRight, x, y, upLightAdditionalX, upLightAdditionalY, upLightWidth, upLightHeight, upLightStunDuration, upLightScalarX, upLightScalarY, upLightFixedX, upLightFixedY, upLightVx, upLightVy, upLightDamage, upLightStartUpDuration, upLightActiveDuration, upLightEndLagDuration, upLightIsAttachedToPlayer, upLightDissapearOnHit);
					moveDuration = upLightStartUpDuration + Move2.IsActiveDuration() + upLightEndLagDuration;
				}
				else if (down) {
					Move2.Activate(facingRight, x, y, downLightAdditionalX, downLightAdditionalY, downLightWidth, downLightHeight, downLightStunDuration, downLightScalarX, downLightScalarY, downLightFixedX, downLightFixedY, downLightVx, downLightVy, downLightDamage, downLightStartUpDuration, downLightActiveDuration, downLightEndLagDuration, downLightIsAttachedToPlayer, downLightDissapearOnHit);
					moveDuration = downLightStartUpDuration + Move2.IsActiveDuration() + downLightEndLagDuration;
				}
				else {
					Move2.Activate(facingRight, x, y, forwardLightAdditionalX, forwardLightAdditionalY, forwardLightWidth, forwardLightHeight, forwardLightStunDuration, forwardLightScalarX, forwardLightScalarY, forwardLightFixedX, forwardLightFixedY, forwardLightVx, forwardLightVy, forwardLightDamage, forwardLightStartUpDuration, forwardLightActiveDuration, forwardLightEndLagDuration, forwardLightIsAttachedToPlayer, forwardLightDissapearOnHit);
					moveDuration = forwardLightStartUpDuration + Move2.IsActiveDuration() + forwardLightEndLagDuration;
				}
			}
			else if (Move3.activeDuration == 0) {
				if (up) {
					Move3.Activate(facingRight, x, y, upLightAdditionalX, upLightAdditionalY, upLightWidth, upLightHeight, upLightStunDuration, upLightScalarX, upLightScalarY, upLightFixedX, upLightFixedY, upLightVx, upLightVy, upLightDamage, upLightStartUpDuration, upLightActiveDuration, upLightEndLagDuration, upLightIsAttachedToPlayer, upLightDissapearOnHit);
					moveDuration = upLightStartUpDuration + Move3.IsActiveDuration() + upLightEndLagDuration;
				}
				else if (down) {
					Move3.Activate(facingRight, x, y, downLightAdditionalX, downLightAdditionalY, downLightWidth, downLightHeight, downLightStunDuration, downLightScalarX, downLightScalarY, downLightFixedX, downLightFixedY, downLightVx, downLightVy, downLightDamage, downLightStartUpDuration, downLightActiveDuration, downLightEndLagDuration, downLightIsAttachedToPlayer, downLightDissapearOnHit);
					moveDuration = downLightStartUpDuration + Move3.IsActiveDuration() + downLightEndLagDuration;
				}
				else{
					Move3.Activate(facingRight, x, y, forwardLightAdditionalX, forwardLightAdditionalY, forwardLightWidth, forwardLightHeight, forwardLightStunDuration, forwardLightScalarX, forwardLightScalarY, forwardLightFixedX, forwardLightFixedY, forwardLightVx, forwardLightVy, forwardLightDamage, forwardLightStartUpDuration, forwardLightActiveDuration, forwardLightEndLagDuration, forwardLightIsAttachedToPlayer, forwardLightDissapearOnHit);
					moveDuration = forwardLightStartUpDuration + Move3.IsActiveDuration() + forwardLightEndLagDuration;
				}
			}
			else if (Move4.activeDuration == 0) {
				if (up) {
					Move4.Activate(facingRight, x, y, upLightAdditionalX, upLightAdditionalY, upLightWidth, upLightHeight, upLightStunDuration, upLightScalarX, upLightScalarY, upLightFixedX, upLightFixedY, upLightVx, upLightVy, upLightDamage, upLightStartUpDuration, upLightActiveDuration, upLightEndLagDuration, upLightIsAttachedToPlayer, upLightDissapearOnHit);
					moveDuration = upLightStartUpDuration + Move4.IsActiveDuration() + upLightEndLagDuration;
				}
				else if (down) {
					Move4.Activate(facingRight, x, y, downLightAdditionalX, downLightAdditionalY, downLightWidth, downLightHeight, downLightStunDuration, downLightScalarX, downLightScalarY, downLightFixedX, downLightFixedY, downLightVx, downLightVy, downLightDamage, downLightStartUpDuration, downLightActiveDuration, downLightEndLagDuration, downLightIsAttachedToPlayer, downLightDissapearOnHit);
					moveDuration = downLightStartUpDuration + Move4.IsActiveDuration() + downLightEndLagDuration;
				}
				else {
					Move4.Activate(facingRight, x, y, forwardLightAdditionalX, forwardLightAdditionalY, forwardLightWidth, forwardLightHeight, forwardLightStunDuration, forwardLightScalarX, forwardLightScalarY, forwardLightFixedX, forwardLightFixedY, forwardLightVx, forwardLightVy, forwardLightDamage, forwardLightStartUpDuration, forwardLightActiveDuration, forwardLightEndLagDuration, forwardLightIsAttachedToPlayer, forwardLightDissapearOnHit);
					moveDuration = forwardLightStartUpDuration + Move4.IsActiveDuration() + forwardLightEndLagDuration;
				}
			}
			else if (Move5.activeDuration == 0) {
				if (up) {
					Move5.Activate(facingRight, x, y, upLightAdditionalX, upLightAdditionalY, upLightWidth, upLightHeight, upLightStunDuration, upLightScalarX, upLightScalarY, upLightFixedX, upLightFixedY, upLightVx, upLightVy, upLightDamage, upLightStartUpDuration, upLightActiveDuration, upLightEndLagDuration, upLightIsAttachedToPlayer, upLightDissapearOnHit);
					moveDuration = upLightStartUpDuration + Move5.IsActiveDuration() + upLightEndLagDuration;
				}
				else if (down) {
					Move5.Activate(facingRight, x, y, downLightAdditionalX, downLightAdditionalY, downLightWidth, downLightHeight, downLightStunDuration, downLightScalarX, downLightScalarY, downLightFixedX, downLightFixedY, downLightVx, downLightVy, downLightDamage, downLightStartUpDuration, downLightActiveDuration, downLightEndLagDuration, downLightIsAttachedToPlayer, downLightDissapearOnHit);
					moveDuration = downLightStartUpDuration + Move5.IsActiveDuration() + downLightEndLagDuration;
				}
				else{
					Move5.Activate(facingRight, x, y, forwardLightAdditionalX, forwardLightAdditionalY, forwardLightWidth, forwardLightHeight, forwardLightStunDuration, forwardLightScalarX, forwardLightScalarY, forwardLightFixedX, forwardLightFixedY, forwardLightVx, forwardLightVy, forwardLightDamage, forwardLightStartUpDuration, forwardLightActiveDuration, forwardLightEndLagDuration, forwardLightIsAttachedToPlayer, forwardLightDissapearOnHit);
					moveDuration = forwardLightStartUpDuration + Move5.IsActiveDuration() + forwardLightEndLagDuration;
				}
			}
		}
		else if (heavy && onStage) {
			if (Move1.activeDuration == 0) {
				if (up) {
					Move1.Activate(facingRight, x, y, upHeavyAdditionalX, upHeavyAdditionalY, upHeavyWidth, upHeavyHeight, upHeavyStunDuration, upHeavyScalarX, upHeavyScalarY, upHeavyFixedX, upHeavyFixedY, upHeavyVx, upHeavyVy, upHeavyDamage, upHeavyStartUpDuration, upHeavyActiveDuration, upHeavyEndLagDuration, upHeavyIsAttachedToPlayer, upHeavyDissapearOnHit);
					moveDuration = upHeavyStartUpDuration + Move1.IsActiveDuration() + upHeavyEndLagDuration;
				}
				else if (down) {
					Move1.Activate(facingRight, x, y, downHeavyAdditionalX, downHeavyAdditionalY, downHeavyWidth, downHeavyHeight, downHeavyStunDuration, downHeavyScalarX, downHeavyScalarY, downHeavyFixedX, downHeavyFixedY, downHeavyVx, downHeavyVy, downHeavyDamage, downHeavyStartUpDuration, downHeavyActiveDuration, downHeavyEndLagDuration, downHeavyIsAttachedToPlayer, downHeavyDissapearOnHit);
					moveDuration = downHeavyStartUpDuration + Move1.IsActiveDuration() + downHeavyEndLagDuration;
				}
				else {
					Move1.Activate(facingRight, x, y, forwardHeavyAdditionalX, forwardHeavyAdditionalY, forwardHeavyWidth, forwardHeavyHeight, forwardHeavyStunDuration, forwardHeavyScalarX, forwardHeavyScalarY, forwardHeavyFixedX, forwardHeavyFixedY, forwardHeavyVx, forwardHeavyVy, forwardHeavyDamage, forwardHeavyStartUpDuration, forwardHeavyActiveDuration, forwardHeavyEndLagDuration, forwardHeavyIsAttachedToPlayer, forwardHeavyDissapearOnHit);
					moveDuration = forwardHeavyStartUpDuration + Move1.IsActiveDuration() + forwardHeavyEndLagDuration;
				}
			}
			else if (Move2.activeDuration == 0) {
				if (up) {
					Move2.Activate(facingRight, x, y, upHeavyAdditionalX, upHeavyAdditionalY, upHeavyWidth, upHeavyHeight, upHeavyStunDuration, upHeavyScalarX, upHeavyScalarY, upHeavyFixedX, upHeavyFixedY, upHeavyVx, upHeavyVy, upHeavyDamage, upHeavyStartUpDuration, upHeavyActiveDuration, upHeavyEndLagDuration, upHeavyIsAttachedToPlayer, upHeavyDissapearOnHit);
					moveDuration = upHeavyStartUpDuration + Move2.IsActiveDuration() + upHeavyEndLagDuration;
				}
				else if (down) {
					Move2.Activate(facingRight, x, y, downHeavyAdditionalX, downHeavyAdditionalY, downHeavyWidth, downHeavyHeight, downHeavyStunDuration, downHeavyScalarX, downHeavyScalarY, downHeavyFixedX, downHeavyFixedY, downHeavyVx, downHeavyVy, downHeavyDamage, downHeavyStartUpDuration, downHeavyActiveDuration, downHeavyEndLagDuration, downHeavyIsAttachedToPlayer, downHeavyDissapearOnHit);
					moveDuration = downHeavyStartUpDuration + Move2.IsActiveDuration() + downHeavyEndLagDuration;
				}
				else {
					Move2.Activate(facingRight, x, y, forwardHeavyAdditionalX, forwardHeavyAdditionalY, forwardHeavyWidth, forwardHeavyHeight, forwardHeavyStunDuration, forwardHeavyScalarX, forwardHeavyScalarY, forwardHeavyFixedX, forwardHeavyFixedY, forwardHeavyVx, forwardHeavyVy, forwardHeavyDamage, forwardHeavyStartUpDuration, forwardHeavyActiveDuration, forwardHeavyEndLagDuration, forwardHeavyIsAttachedToPlayer, forwardHeavyDissapearOnHit);
					moveDuration = forwardHeavyStartUpDuration + Move2.IsActiveDuration() + forwardHeavyEndLagDuration;
				}
			}
			else if (Move3.activeDuration == 0) {
				if (up) {
					Move3.Activate(facingRight, x, y, upHeavyAdditionalX, upHeavyAdditionalY, upHeavyWidth, upHeavyHeight, upHeavyStunDuration, upHeavyScalarX, upHeavyScalarY, upHeavyFixedX, upHeavyFixedY, upHeavyVx, upHeavyVy, upHeavyDamage, upHeavyStartUpDuration, upHeavyActiveDuration, upHeavyEndLagDuration, upHeavyIsAttachedToPlayer, upHeavyDissapearOnHit);
					moveDuration = upHeavyStartUpDuration + Move3.IsActiveDuration() + upHeavyEndLagDuration;
				}
				else if (down) {
					Move3.Activate(facingRight, x, y, downHeavyAdditionalX, downHeavyAdditionalY, downHeavyWidth, downHeavyHeight, downHeavyStunDuration, downHeavyScalarX, downHeavyScalarY, downHeavyFixedX, downHeavyFixedY, downHeavyVx, downHeavyVy, downHeavyDamage, downHeavyStartUpDuration, downHeavyActiveDuration, downHeavyEndLagDuration, downHeavyIsAttachedToPlayer, downHeavyDissapearOnHit);
					moveDuration = downHeavyStartUpDuration + Move3.IsActiveDuration() + downHeavyEndLagDuration;
				}
				else {
					Move3.Activate(facingRight, x, y, forwardHeavyAdditionalX, forwardHeavyAdditionalY, forwardHeavyWidth, forwardHeavyHeight, forwardHeavyStunDuration, forwardHeavyScalarX, forwardHeavyScalarY, forwardHeavyFixedX, forwardHeavyFixedY, forwardHeavyVx, forwardHeavyVy, forwardHeavyDamage, forwardHeavyStartUpDuration, forwardHeavyActiveDuration, forwardHeavyEndLagDuration, forwardHeavyIsAttachedToPlayer, forwardHeavyDissapearOnHit);
					moveDuration = forwardHeavyStartUpDuration + Move3.IsActiveDuration() + forwardHeavyEndLagDuration;
				}
			}
			else if (Move4.activeDuration == 0) {
				if (up) {
					Move4.Activate(facingRight, x, y, upHeavyAdditionalX, upHeavyAdditionalY, upHeavyWidth, upHeavyHeight, upHeavyStunDuration, upHeavyScalarX, upHeavyScalarY, upHeavyFixedX, upHeavyFixedY, upHeavyVx, upHeavyVy, upHeavyDamage, upHeavyStartUpDuration, upHeavyActiveDuration, upHeavyEndLagDuration, upHeavyIsAttachedToPlayer, upHeavyDissapearOnHit);
					moveDuration = upHeavyStartUpDuration + Move4.IsActiveDuration() + upHeavyEndLagDuration;
				}
				else if (down) {
					Move4.Activate(facingRight, x, y, downHeavyAdditionalX, downHeavyAdditionalY, downHeavyWidth, downHeavyHeight, downHeavyStunDuration, downHeavyScalarX, downHeavyScalarY, downHeavyFixedX, downHeavyFixedY, downHeavyVx, downHeavyVy, downHeavyDamage, downHeavyStartUpDuration, downHeavyActiveDuration, downHeavyEndLagDuration, downHeavyIsAttachedToPlayer, downHeavyDissapearOnHit);
					moveDuration = downHeavyStartUpDuration + Move4.IsActiveDuration() + downHeavyEndLagDuration;
				}
				else {
					Move4.Activate(facingRight, x, y, forwardHeavyAdditionalX, forwardHeavyAdditionalY, forwardHeavyWidth, forwardHeavyHeight, forwardHeavyStunDuration, forwardHeavyScalarX, forwardHeavyScalarY, forwardHeavyFixedX, forwardHeavyFixedY, forwardHeavyVx, forwardHeavyVy, forwardHeavyDamage, forwardHeavyStartUpDuration, forwardHeavyActiveDuration, forwardHeavyEndLagDuration, forwardHeavyIsAttachedToPlayer, forwardHeavyDissapearOnHit);
					moveDuration = forwardHeavyStartUpDuration + Move4.IsActiveDuration() + forwardHeavyEndLagDuration;
				}
			}
			else if (Move5.activeDuration == 0) {
				if (up) {
					Move5.Activate(facingRight, x, y, upHeavyAdditionalX, upHeavyAdditionalY, upHeavyWidth, upHeavyHeight, upHeavyStunDuration, upHeavyScalarX, upHeavyScalarY, upHeavyFixedX, upHeavyFixedY, upHeavyVx, upHeavyVy, upHeavyDamage, upHeavyStartUpDuration, upHeavyActiveDuration, upHeavyEndLagDuration, upHeavyIsAttachedToPlayer, upHeavyDissapearOnHit);
					moveDuration = upHeavyStartUpDuration + Move5.IsActiveDuration() + upHeavyEndLagDuration;
				}
				else if (down) {
					Move5.Activate(facingRight, x, y, downHeavyAdditionalX, downHeavyAdditionalY, downHeavyWidth, downHeavyHeight, downHeavyStunDuration, downHeavyScalarX, downHeavyScalarY, downHeavyFixedX, downHeavyFixedY, downHeavyVx, downHeavyVy, downHeavyDamage, downHeavyStartUpDuration, downHeavyActiveDuration, downHeavyEndLagDuration, downHeavyIsAttachedToPlayer, downHeavyDissapearOnHit);
					moveDuration = downHeavyStartUpDuration + Move5.IsActiveDuration() + downHeavyEndLagDuration;
				}
				else {
					Move5.Activate(facingRight, x, y, forwardHeavyAdditionalX, forwardHeavyAdditionalY, forwardHeavyWidth, forwardHeavyHeight, forwardHeavyStunDuration, forwardHeavyScalarX, forwardHeavyScalarY, forwardHeavyFixedX, forwardHeavyFixedY, forwardHeavyVx, forwardHeavyVy, forwardHeavyDamage, forwardHeavyStartUpDuration, forwardHeavyActiveDuration, forwardHeavyEndLagDuration, forwardHeavyIsAttachedToPlayer, forwardHeavyDissapearOnHit);
					moveDuration = forwardHeavyStartUpDuration + Move5.IsActiveDuration() + forwardHeavyEndLagDuration;
				}
			}
		}
		else if ((light || heavy) && !onStage) {
			if (Move1.activeDuration == 0) {
				if (up) {
					Move1.Activate(facingRight, x, y, upAerialAdditionalX, upAerialAdditionalY, upAerialWidth, upAerialHeight, upAerialStunDuration, upAerialScalarX, upAerialScalarY, upAerialFixedX, upAerialFixedY, upAerialVx, upAerialVy, upAerialDamage, upAerialStartUpDuration, upAerialActiveDuration, upAerialEndLagDuration, upAerialIsAttachedToPlayer, upAerialDissapearOnHit);
					moveDuration = upAerialStartUpDuration + Move1.IsActiveDuration() + upAerialEndLagDuration;
				}
				else if (down) {
					Move1.Activate(facingRight, x, y, downAerialAdditionalX, downAerialAdditionalY, downAerialWidth, downAerialHeight, downAerialStunDuration, downAerialScalarX, downAerialScalarY, downAerialFixedX, downAerialFixedY, downAerialVx, downAerialVy, downAerialDamage, downAerialStartUpDuration, downAerialActiveDuration, downAerialEndLagDuration, downAerialIsAttachedToPlayer, downAerialDissapearOnHit);
					moveDuration = downAerialStartUpDuration + Move1.IsActiveDuration() + downAerialEndLagDuration;
				}
				else {
					Move1.Activate(facingRight, x, y, forwardAerialAdditionalX, forwardAerialAdditionalY, forwardAerialWidth, forwardAerialHeight, forwardAerialStunDuration, forwardAerialScalarX, forwardAerialScalarY, forwardAerialFixedX, forwardAerialFixedY, forwardAerialVx, forwardAerialVy, forwardAerialDamage, forwardAerialStartUpDuration, forwardAerialActiveDuration, forwardAerialEndLagDuration, forwardAerialIsAttachedToPlayer, forwardAerialDissapearOnHit);
					moveDuration = forwardAerialStartUpDuration + Move1.IsActiveDuration() + forwardAerialEndLagDuration;
				}
			}
			else if (Move2.activeDuration == 0) {
				if (up) {
					Move2.Activate(facingRight, x, y, upAerialAdditionalX, upAerialAdditionalY, upAerialWidth, upAerialHeight, upAerialStunDuration, upAerialScalarX, upAerialScalarY, upAerialFixedX, upAerialFixedY, upAerialVx, upAerialVy, upAerialDamage, upAerialStartUpDuration, upAerialActiveDuration, upAerialEndLagDuration, upAerialIsAttachedToPlayer, upAerialDissapearOnHit);
					moveDuration = upAerialStartUpDuration + Move2.IsActiveDuration() + upAerialEndLagDuration;
				}
				else if (down) {
					Move2.Activate(facingRight, x, y, downAerialAdditionalX, downAerialAdditionalY, downAerialWidth, downAerialHeight, downAerialStunDuration, downAerialScalarX, downAerialScalarY, downAerialFixedX, downAerialFixedY, downAerialVx, downAerialVy, downAerialDamage, downAerialStartUpDuration, downAerialActiveDuration, downAerialEndLagDuration, downAerialIsAttachedToPlayer, downAerialDissapearOnHit);
					moveDuration = downAerialStartUpDuration + Move2.IsActiveDuration() + downAerialEndLagDuration;
				}
				else {
					Move2.Activate(facingRight, x, y, forwardAerialAdditionalX, forwardAerialAdditionalY, forwardAerialWidth, forwardAerialHeight, forwardAerialStunDuration, forwardAerialScalarX, forwardAerialScalarY, forwardAerialFixedX, forwardAerialFixedY, forwardAerialVx, forwardAerialVy, forwardAerialDamage, forwardAerialStartUpDuration, forwardAerialActiveDuration, forwardAerialEndLagDuration, forwardAerialIsAttachedToPlayer, forwardAerialDissapearOnHit);
					moveDuration = forwardAerialStartUpDuration + Move2.IsActiveDuration() + forwardAerialEndLagDuration;
				}
			}
			else if (Move3.activeDuration == 0) {
				if (up) {
					Move3.Activate(facingRight, x, y, upAerialAdditionalX, upAerialAdditionalY, upAerialWidth, upAerialHeight, upAerialStunDuration, upAerialScalarX, upAerialScalarY, upAerialFixedX, upAerialFixedY, upAerialVx, upAerialVy, upAerialDamage, upAerialStartUpDuration, upAerialActiveDuration, upAerialEndLagDuration, upAerialIsAttachedToPlayer, upAerialDissapearOnHit);
					moveDuration = upAerialStartUpDuration + Move3.IsActiveDuration() + upAerialEndLagDuration;
				}
				else if (down) {
					Move3.Activate(facingRight, x, y, downAerialAdditionalX, downAerialAdditionalY, downAerialWidth, downAerialHeight, downAerialStunDuration, downAerialScalarX, downAerialScalarY, downAerialFixedX, downAerialFixedY, downAerialVx, downAerialVy, downAerialDamage, downAerialStartUpDuration, downAerialActiveDuration, downAerialEndLagDuration, downAerialIsAttachedToPlayer, downAerialDissapearOnHit);
					moveDuration = downAerialStartUpDuration + Move3.IsActiveDuration() + downAerialEndLagDuration;
				}
				else {
					Move3.Activate(facingRight, x, y, forwardAerialAdditionalX, forwardAerialAdditionalY, forwardAerialWidth, forwardAerialHeight, forwardAerialStunDuration, forwardAerialScalarX, forwardAerialScalarY, forwardAerialFixedX, forwardAerialFixedY, forwardAerialVx, forwardAerialVy, forwardAerialDamage, forwardAerialStartUpDuration, forwardAerialActiveDuration, forwardAerialEndLagDuration, forwardAerialIsAttachedToPlayer, forwardAerialDissapearOnHit);
					moveDuration = forwardAerialStartUpDuration + Move3.IsActiveDuration() + forwardAerialEndLagDuration;
				}
			}
			else if (Move4.activeDuration == 0) {
				if (up) {
					Move4.Activate(facingRight, x, y, upAerialAdditionalX, upAerialAdditionalY, upAerialWidth, upAerialHeight, upAerialStunDuration, upAerialScalarX, upAerialScalarY, upAerialFixedX, upAerialFixedY, upAerialVx, upAerialVy, upAerialDamage, upAerialStartUpDuration, upAerialActiveDuration, upAerialEndLagDuration, upAerialIsAttachedToPlayer, upAerialDissapearOnHit);
					moveDuration = upAerialStartUpDuration + Move4.IsActiveDuration() + upAerialEndLagDuration;
				}
				else if (down) {
					Move4.Activate(facingRight, x, y, downAerialAdditionalX, downAerialAdditionalY, downAerialWidth, downAerialHeight, downAerialStunDuration, downAerialScalarX, downAerialScalarY, downAerialFixedX, downAerialFixedY, downAerialVx, downAerialVy, downAerialDamage, downAerialStartUpDuration, downAerialActiveDuration, downAerialEndLagDuration, downAerialIsAttachedToPlayer, downAerialDissapearOnHit);
					moveDuration = downAerialStartUpDuration + Move4.IsActiveDuration() + downAerialEndLagDuration;
				}
				else {
					Move4.Activate(facingRight, x, y, forwardAerialAdditionalX, forwardAerialAdditionalY, forwardAerialWidth, forwardAerialHeight, forwardAerialStunDuration, forwardAerialScalarX, forwardAerialScalarY, forwardAerialFixedX, forwardAerialFixedY, forwardAerialVx, forwardAerialVy, forwardAerialDamage, forwardAerialStartUpDuration, forwardAerialActiveDuration, forwardAerialEndLagDuration, forwardAerialIsAttachedToPlayer, forwardAerialDissapearOnHit);
					moveDuration = forwardAerialStartUpDuration + Move4.IsActiveDuration() + forwardAerialEndLagDuration;
				}
			}
			else if (Move5.activeDuration == 0) {
				if (up) {
					Move5.Activate(facingRight, x, y, upAerialAdditionalX, upAerialAdditionalY, upAerialWidth, upAerialHeight, upAerialStunDuration, upAerialScalarX, upAerialScalarY, upAerialFixedX, upAerialFixedY, upAerialVx, upAerialVy, upAerialDamage, upAerialStartUpDuration, upAerialActiveDuration, upAerialEndLagDuration, upAerialIsAttachedToPlayer, upAerialDissapearOnHit);
					moveDuration = upAerialStartUpDuration + Move5.IsActiveDuration() + upAerialEndLagDuration;
				}
				else if (down) {
					Move5.Activate(facingRight, x, y, downAerialAdditionalX, downAerialAdditionalY, downAerialWidth, downAerialHeight, downAerialStunDuration, downAerialScalarX, downAerialScalarY, downAerialFixedX, downAerialFixedY, downAerialVx, downAerialVy, downAerialDamage, downAerialStartUpDuration, downAerialActiveDuration, downAerialEndLagDuration, downAerialIsAttachedToPlayer, downAerialDissapearOnHit);
					moveDuration = downAerialStartUpDuration + Move5.IsActiveDuration() + downAerialEndLagDuration;
				}
				else {
					Move5.Activate(facingRight, x, y, forwardAerialAdditionalX, forwardAerialAdditionalY, forwardAerialWidth, forwardAerialHeight, forwardAerialStunDuration, forwardAerialScalarX, forwardAerialScalarY, forwardAerialFixedX, forwardAerialFixedY, forwardAerialVx, forwardAerialVy, forwardAerialDamage, forwardAerialStartUpDuration, forwardAerialActiveDuration, forwardAerialEndLagDuration, forwardAerialIsAttachedToPlayer, forwardAerialDissapearOnHit);
					moveDuration = forwardAerialStartUpDuration + Move5.IsActiveDuration() + forwardAerialEndLagDuration;
				}
			}
		}
		else if (special) {
			if (Move1.activeDuration == 0) {
				if (up) {
					Move1.Activate(facingRight, x, y, upSpecialAdditionalX, upSpecialAdditionalY, upSpecialWidth, upSpecialHeight, upSpecialStunDuration, upSpecialScalarX, upSpecialScalarY, upSpecialFixedX, upSpecialFixedY, upSpecialVx, upSpecialVy, upSpecialDamage, upSpecialStartUpDuration, upSpecialActiveDuration, upSpecialEndLagDuration, upSpecialIsAttachedToPlayer, upSpecialDissapearOnHit);
					moveDuration = upSpecialStartUpDuration + Move1.IsActiveDuration() + upSpecialEndLagDuration;
				}
				else if (down) {
					Move1.Activate(facingRight, x, y, downSpecialAdditionalX, downSpecialAdditionalY, downSpecialWidth, downSpecialHeight, downSpecialStunDuration, downSpecialScalarX, downSpecialScalarY, downSpecialFixedX, downSpecialFixedY, downSpecialVx, downSpecialVy, downSpecialDamage, downSpecialStartUpDuration, downSpecialActiveDuration, downSpecialEndLagDuration, downSpecialIsAttachedToPlayer, downSpecialDissapearOnHit);
					moveDuration = downSpecialStartUpDuration + Move1.IsActiveDuration() + downSpecialEndLagDuration;
				}
				else {
					Move1.Activate(facingRight, x, y, forwardSpecialAdditionalX, forwardSpecialAdditionalY, forwardSpecialWidth, forwardSpecialHeight, forwardSpecialStunDuration, forwardSpecialScalarX, forwardSpecialScalarY, forwardSpecialFixedX, forwardSpecialFixedY, forwardSpecialVx, forwardSpecialVy, forwardSpecialDamage, forwardSpecialStartUpDuration, forwardSpecialActiveDuration, forwardSpecialEndLagDuration, forwardSpecialIsAttachedToPlayer, forwardSpecialDissapearOnHit);
					moveDuration = forwardSpecialStartUpDuration + Move1.IsActiveDuration() + forwardSpecialEndLagDuration;
				}
			}
			else if (Move2.activeDuration == 0) {
				if (up) {
					Move2.Activate(facingRight, x, y, upSpecialAdditionalX, upSpecialAdditionalY, upSpecialWidth, upSpecialHeight, upSpecialStunDuration, upSpecialScalarX, upSpecialScalarY, upSpecialFixedX, upSpecialFixedY, upSpecialVx, upSpecialVy, upSpecialDamage, upSpecialStartUpDuration, upSpecialActiveDuration, upSpecialEndLagDuration, upSpecialIsAttachedToPlayer, upSpecialDissapearOnHit);
					moveDuration = upSpecialStartUpDuration + Move2.IsActiveDuration() + upSpecialEndLagDuration;
				}
				else if (down) {
					Move2.Activate(facingRight, x, y, downSpecialAdditionalX, downSpecialAdditionalY, downSpecialWidth, downSpecialHeight, downSpecialStunDuration, downSpecialScalarX, downSpecialScalarY, downSpecialFixedX, downSpecialFixedY, downSpecialVx, downSpecialVy, downSpecialDamage, downSpecialStartUpDuration, downSpecialActiveDuration, downSpecialEndLagDuration, downSpecialIsAttachedToPlayer, downSpecialDissapearOnHit);
					moveDuration = downSpecialStartUpDuration + Move2.IsActiveDuration() + downSpecialEndLagDuration;
				}
				else {
					Move2.Activate(facingRight, x, y, forwardSpecialAdditionalX, forwardSpecialAdditionalY, forwardSpecialWidth, forwardSpecialHeight, forwardSpecialStunDuration, forwardSpecialScalarX, forwardSpecialScalarY, forwardSpecialFixedX, forwardSpecialFixedY, forwardSpecialVx, forwardSpecialVy, forwardSpecialDamage, forwardSpecialStartUpDuration, forwardSpecialActiveDuration, forwardSpecialEndLagDuration, forwardSpecialIsAttachedToPlayer, forwardSpecialDissapearOnHit);
					moveDuration = forwardSpecialStartUpDuration + Move2.IsActiveDuration() + forwardSpecialEndLagDuration;
				}
			}
			else if (Move3.activeDuration == 0) {
				if (up) {
					Move3.Activate(facingRight, x, y, upSpecialAdditionalX, upSpecialAdditionalY, upSpecialWidth, upSpecialHeight, upSpecialStunDuration, upSpecialScalarX, upSpecialScalarY, upSpecialFixedX, upSpecialFixedY, upSpecialVx, upSpecialVy, upSpecialDamage, upSpecialStartUpDuration, upSpecialActiveDuration, upSpecialEndLagDuration, upSpecialIsAttachedToPlayer, upSpecialDissapearOnHit);
					moveDuration = upSpecialStartUpDuration + Move3.IsActiveDuration() + upSpecialEndLagDuration;
				}
				else if (down) {
					Move3.Activate(facingRight, x, y, downSpecialAdditionalX, downSpecialAdditionalY, downSpecialWidth, downSpecialHeight, downSpecialStunDuration, downSpecialScalarX, downSpecialScalarY, downSpecialFixedX, downSpecialFixedY, downSpecialVx, downSpecialVy, downSpecialDamage, downSpecialStartUpDuration, downSpecialActiveDuration, downSpecialEndLagDuration, downSpecialIsAttachedToPlayer, downSpecialDissapearOnHit);
					moveDuration = downSpecialStartUpDuration + Move3.IsActiveDuration() + downSpecialEndLagDuration;
				}
				else {
					Move3.Activate(facingRight, x, y, forwardSpecialAdditionalX, forwardSpecialAdditionalY, forwardSpecialWidth, forwardSpecialHeight, forwardSpecialStunDuration, forwardSpecialScalarX, forwardSpecialScalarY, forwardSpecialFixedX, forwardSpecialFixedY, forwardSpecialVx, forwardSpecialVy, forwardSpecialDamage, forwardSpecialStartUpDuration, forwardSpecialActiveDuration, forwardSpecialEndLagDuration, forwardSpecialIsAttachedToPlayer, forwardSpecialDissapearOnHit);
					moveDuration = forwardSpecialStartUpDuration + Move3.IsActiveDuration() + forwardSpecialEndLagDuration;
				}
			}
			else if (Move4.activeDuration == 0) {
				if (up) {
					Move4.Activate(facingRight, x, y, upSpecialAdditionalX, upSpecialAdditionalY, upSpecialWidth, upSpecialHeight, upSpecialStunDuration, upSpecialScalarX, upSpecialScalarY, upSpecialFixedX, upSpecialFixedY, upSpecialVx, upSpecialVy, upSpecialDamage, upSpecialStartUpDuration, upSpecialActiveDuration, upSpecialEndLagDuration, upSpecialIsAttachedToPlayer, upSpecialDissapearOnHit);
					moveDuration = upSpecialStartUpDuration + Move4.IsActiveDuration() + upSpecialEndLagDuration;
				}
				else if (down) {
					Move4.Activate(facingRight, x, y, downSpecialAdditionalX, downSpecialAdditionalY, downSpecialWidth, downSpecialHeight, downSpecialStunDuration, downSpecialScalarX, downSpecialScalarY, downSpecialFixedX, downSpecialFixedY, downSpecialVx, downSpecialVy, downSpecialDamage, downSpecialStartUpDuration, downSpecialActiveDuration, downSpecialEndLagDuration, downSpecialIsAttachedToPlayer, downSpecialDissapearOnHit);
					moveDuration = downSpecialStartUpDuration + Move4.IsActiveDuration() + downSpecialEndLagDuration;
				}
				else {
					Move4.Activate(facingRight, x, y, forwardSpecialAdditionalX, forwardSpecialAdditionalY, forwardSpecialWidth, forwardSpecialHeight, forwardSpecialStunDuration, forwardSpecialScalarX, forwardSpecialScalarY, forwardSpecialFixedX, forwardSpecialFixedY, forwardSpecialVx, forwardSpecialVy, forwardSpecialDamage, forwardSpecialStartUpDuration, forwardSpecialActiveDuration, forwardSpecialEndLagDuration, forwardSpecialIsAttachedToPlayer, forwardSpecialDissapearOnHit);
					moveDuration = forwardSpecialStartUpDuration + Move4.IsActiveDuration() + forwardSpecialEndLagDuration;
				}
			}
			else if (Move5.activeDuration == 0) {
				if (up) {
					Move5.Activate(facingRight, x, y, upSpecialAdditionalX, upSpecialAdditionalY, upSpecialWidth, upSpecialHeight, upSpecialStunDuration, upSpecialScalarX, upSpecialScalarY, upSpecialFixedX, upSpecialFixedY, upSpecialVx, upSpecialVy, upSpecialDamage, upSpecialStartUpDuration, upSpecialActiveDuration, upSpecialEndLagDuration, upSpecialIsAttachedToPlayer, upSpecialDissapearOnHit);
					moveDuration = upSpecialStartUpDuration + Move5.IsActiveDuration() + upSpecialEndLagDuration;
				}
				else if (down) {
					Move5.Activate(facingRight, x, y, downSpecialAdditionalX, downSpecialAdditionalY, downSpecialWidth, downSpecialHeight, downSpecialStunDuration, downSpecialScalarX, downSpecialScalarY, downSpecialFixedX, downSpecialFixedY, downSpecialVx, downSpecialVy, downSpecialDamage, downSpecialStartUpDuration, downSpecialActiveDuration, downSpecialEndLagDuration, downSpecialIsAttachedToPlayer, downSpecialDissapearOnHit);
					moveDuration = downSpecialStartUpDuration + Move5.IsActiveDuration() + downSpecialEndLagDuration;
				}
				else {
					Move5.Activate(facingRight, x, y, forwardSpecialAdditionalX, forwardSpecialAdditionalY, forwardSpecialWidth, forwardSpecialHeight, forwardSpecialStunDuration, forwardSpecialScalarX, forwardSpecialScalarY, forwardSpecialFixedX, forwardSpecialFixedY, forwardSpecialVx, forwardSpecialVy, forwardSpecialDamage, forwardSpecialStartUpDuration, forwardSpecialActiveDuration, forwardSpecialEndLagDuration, forwardSpecialIsAttachedToPlayer, forwardSpecialDissapearOnHit);
					moveDuration = forwardSpecialStartUpDuration + Move5.IsActiveDuration() + forwardSpecialEndLagDuration;
				}
			}
		}
		Move1.CheckStatus(x, y);
		Move2.CheckStatus(x, y);
		Move3.CheckStatus(x, y);
		Move4.CheckStatus(x, y);
		Move5.CheckStatus(x, y);
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
		(y+height < 0 - leniancy && stun>0) ||
		y > stageHeight + leniancy
		) {
		lives--;
		vx = 0;
		vy = 0;
		playerPercentage = 0;
		Move1.EndMove();
		Move2.EndMove();
		Move3.EndMove();
		Move4.EndMove();
		Move5.EndMove();
		if (lives > 0) {
			y = 500-height;
			x = stageWidth / 2;
			return true;
		}
		else {
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
	if (move == 2) {
		return Move2.Draw();
	}
	if (move == 3) {
		return Move3.Draw();
	}
	if (move == 4) {
		return Move4.Draw();
	}
	if (move == 5) {
		return Move5.Draw();
	}
	return false;
}

bool Character::IsMoveColliding(int Player2x, int Player2y, int Player2width, int Player2height)
{
	if (Move1.IsMoveColliding(Player2x, Player2y, Player2width, Player2height)) {
		moveThatHit = 1;
		return true;
	}
	if (Move2.IsMoveColliding(Player2x, Player2y, Player2width, Player2height)) {
		moveThatHit = 2;
		return true;
	}
	if (Move3.IsMoveColliding(Player2x, Player2y, Player2width, Player2height)) {
		moveThatHit = 3;
		return true;
	}
	if (Move4.IsMoveColliding(Player2x, Player2y, Player2width, Player2height)) {
		moveThatHit = 4;
		return true;
	}
	if (Move5.IsMoveColliding(Player2x, Player2y, Player2width, Player2height)) {
		moveThatHit = 5;
		return true;
	}
	return false;
}

int Character::MoveX0(int move)
{
	if (move == 1) {
		return Move1.x + Move1.additionalX;
	}
	if (move == 2) {
		return Move2.x + Move2.additionalX;
	}
	if (move == 3) {
		return Move3.x + Move3.additionalX;
	}
	if (move == 4) {
		return Move4.x + Move4.additionalX;
	}
	if (move == 5) {
		return Move5.x + Move5.additionalX;
	}
	return 0;
}

int Character::MoveY0(int move)
{
	if (move == 1) {
		return Move1.y + Move1.additionalY;
	}
	if (move == 2) {
		return Move2.y + Move2.additionalY;
	}
	if (move == 3) {
		return Move3.y + Move3.additionalY;
	}
	if (move == 4) {
		return Move4.y + Move4.additionalY;
	}
	if (move == 5) {
		return Move5.y + Move5.additionalY;
	}
	return 0;
}

int Character::MoveX1(int move)
{
	if (move == 1) {
		return Move1.x + Move1.additionalX + Move1.width;
	}
	if (move == 2) {
		return Move2.x + Move2.additionalX + Move2.width;
	}
	if (move == 3) {
		return Move3.x + Move3.additionalX + Move3.width;
	}
	if (move == 4) {
		return Move4.x + Move4.additionalX + Move4.width;
	}
	if (move == 5) {
		return Move5.x + Move5.additionalX + Move5.width;
	}
	return 0;
}

int Character::MoveY1(int move)
{
	if (move == 1) {
		return Move1.y + Move1.height + Move1.additionalY;
	}
	if (move == 2) {
		return Move2.y + Move2.height + Move2.additionalY;
	}
	if (move == 3) {
		return Move3.y + Move3.height + Move3.additionalY;
	}
	if (move == 4) {
		return Move4.y + Move4.height + Move4.additionalY;
	}
	if (move == 5) {
		return Move5.y + Move5.height + Move5.additionalY;
	}
	return 0;
}

int Character::MoveThatHitStun()
{
	if (moveThatHit == 1) {
		return Move1.stunDuration;
	}
	if (moveThatHit == 2) {
		return Move2.stunDuration;
	}
	if (moveThatHit == 3) {
		return Move3.stunDuration;
	}
	if (moveThatHit == 4) {
		return Move4.stunDuration;
	}
	if (moveThatHit == 5) {
		return Move5.stunDuration;
	}
	return 0;
}

int Character::MoveThatHitDamage()
{
	if (moveThatHit == 1) {
		return Move1.damage;
	}
	if (moveThatHit == 2) {
		return Move2.damage;
	}
	if (moveThatHit == 3) {
		return Move3.damage;
	}
	if (moveThatHit == 4) {
		return Move4.damage;
	}
	if (moveThatHit == 5) {
		return Move5.damage;
	}
	return 0;
}

int Character::MoveThatHitScalarX()
{
	if (moveThatHit == 1) {
		return Move1.scalarX;
	}
	if (moveThatHit == 2) {
		return Move2.scalarX;
	}
	if (moveThatHit == 3) {
		return Move3.scalarX;
	}
	if (moveThatHit == 4) {
		return Move4.scalarX;
	}
	if (moveThatHit == 5) {
		return Move5.scalarX;
	}
	return 0;
}

int Character::MoveThatHitScalarY()
{
	if (moveThatHit == 1) {
		return Move1.scalarY;
	}
	if (moveThatHit == 2) {
		return Move2.scalarY;
	}
	if (moveThatHit == 3) {
		return Move3.scalarY;
	}
	if (moveThatHit == 4) {
		return Move4.scalarY;
	}
	if (moveThatHit == 5) {
		return Move5.scalarY;
	}
	return 0;
}

int Character::MoveThatHitFixedX()
{
	if (moveThatHit == 1) {
		return Move1.fixedX;
	}
	if (moveThatHit == 2) {
		return Move2.fixedX;
	}
	if (moveThatHit == 3) {
		return Move3.fixedX;
	}
	if (moveThatHit == 4) {
		return Move4.fixedX;
	}
	if (moveThatHit == 5) {
		return Move5.fixedX;
	}
	return 0;
}

int Character::MoveThatHitFixedY()
{
	if (moveThatHit == 1) {
		return Move1.fixedY;
	}
	if (moveThatHit == 2) {
		return Move2.fixedY;
	}
	if (moveThatHit == 3) {
		return Move3.fixedY;
	}
	if (moveThatHit == 4) {
		return Move4.fixedY;
	}
	if (moveThatHit == 5) {
		return Move5.fixedY;
	}
	return 0;
}


void Character::Initialise(int xReferral, int yReferral, int livesReferral, int widthReferral, int heightReferral, float walkSpeedReferral, float aerialSpeedReferral, float aerialAccelerationReferral, float walkAccelerationReferral, float groundJumpHeightReferral, float aerialJumpHeightReferral, float fallAccelerationReferral, float fallSpeedReferral, float weightReferral, int maxDoubleJumpReferral, int forwardLightAdditionalXReferral, int forwardLightAdditionalYReferral, int forwardLightWidthReferral, int forwardLightHeightReferral, float forwardLightStunDurationReferral, float forwardLightScalarXReferral, float forwardLightScalarYReferral, float forwardLightFixedXReferral, float forwardLightFixedYReferral, float forwardLightVxReferral, float forwardLightVyReferral, float forwardLightDamageReferral, float forwardLightStartUpDurationReferral, float forwardLightActiveDurationReferral, float forwardLightEndLagDurationReferral, bool forwardLightIsAttachedToPlayerReferral, bool forwardLightDissapearOnHitReferral, int upLightAdditionalXReferral, int upLightAdditionalYReferral, int upLightWidthReferral, int upLightHeightReferral, float upLightStunDurationReferral, float upLightScalarXReferral, float upLightScalarYReferral, float upLightFixedXReferral, float upLightFixedYReferral, float upLightVxReferral, float upLightVyReferral, float upLightDamageReferral, float upLightStartUpDurationReferral, float upLightActiveDurationReferral, float upLightEndLagDurationReferral, bool upLightIsAttachedToPlayerReferral, bool upLightDissapearOnHitReferral, int downLightAdditionalXReferral, int downLightAdditionalYReferral, int downLightWidthReferral, int downLightHeightReferral, float downLightStunDurationReferral, float downLightScalarXReferral, float downLightScalarYReferral, float downLightFixedXReferral, float downLightFixedYReferral, float downLightVxReferral, float downLightVyReferral, float downLightDamageReferral, float downLightStartUpDurationReferral, float downLightActiveDurationReferral, float downLightEndLagDurationReferral, bool downLightIsAttachedToPlayerReferral, bool downLightDissapearOnHitReferral, int forwardHeavyAdditionalXReferral, int forwardHeavyAdditionalYReferral, int forwardHeavyWidthReferral, int forwardHeavyHeightReferral, float forwardHeavyStunDurationReferral, float forwardHeavyScalarXReferral, float forwardHeavyScalarYReferral, float forwardHeavyFixedXReferral, float forwardHeavyFixedYReferral, float forwardHeavyVxReferral, float forwardHeavyVyReferral, float forwardHeavyDamageReferral, float forwardHeavyStartUpDurationReferral, float forwardHeavyActiveDurationReferral, float forwardHeavyEndLagDurationReferral, bool forwardHeavyIsAttachedToPlayerReferral, bool forwardHeavyDissapearOnHitReferral, int upHeavyAdditionalXReferral, int upHeavyAdditionalYReferral, int upHeavyWidthReferral, int upHeavyHeightReferral, float upHeavyStunDurationReferral, float upHeavyScalarXReferral, float upHeavyScalarYReferral, float upHeavyFixedXReferral, float upHeavyFixedYReferral, float upHeavyVxReferral, float upHeavyVyReferral, float upHeavyDamageReferral, float upHeavyStartUpDurationReferral, float upHeavyActiveDurationReferral, float upHeavyEndLagDurationReferral, bool upHeavyIsAttachedToPlayerReferral, bool upHeavyDissapearOnHitReferral, int downHeavyAdditionalXReferral, int downHeavyAdditionalYReferral, int downHeavyWidthReferral, int downHeavyHeightReferral, float downHeavyStunDurationReferral, float downHeavyScalarXReferral, float downHeavyScalarYReferral, float downHeavyFixedXReferral, float downHeavyFixedYReferral, float downHeavyVxReferral, float downHeavyVyReferral, float downHeavyDamageReferral, float downHeavyStartUpDurationReferral, float downHeavyActiveDurationReferral, float downHeavyEndLagDurationReferral, bool downHeavyIsAttachedToPlayerReferral, bool downHeavyDissapearOnHitReferral, int forwardAerialAdditionalXReferral, int forwardAerialAdditionalYReferral, int forwardAerialWidthReferral, int forwardAerialHeightReferral, float forwardAerialStunDurationReferral, float forwardAerialScalarXReferral, float forwardAerialScalarYReferral, float forwardAerialFixedXReferral, float forwardAerialFixedYReferral, float forwardAerialVxReferral, float forwardAerialVyReferral, float forwardAerialDamageReferral, float forwardAerialStartUpDurationReferral, float forwardAerialActiveDurationReferral, float forwardAerialEndLagDurationReferral, bool forwardAerialIsAttachedToPlayerReferral, bool forwardAerialDissapearOnHitReferral, int backAerialAdditionalXReferral, int backAerialAdditionalYReferral, int backAerialWidthReferral, int backAerialHeightReferral, float backAerialStunDurationReferral, float backAerialScalarXReferral, float backAerialScalarYReferral, float backAerialFixedXReferral, float backAerialFixedYReferral, float backAerialVxReferral, float backAerialVyReferral, float backAerialDamageReferral, float backAerialStartUpDurationReferral, float backAerialActiveDurationReferral, float backAerialEndLagDurationReferral, bool backAerialIsAttachedToPlayerReferral, bool backAerialDissapearOnHitReferral, int upAerialAdditionalXReferral, int upAerialAdditionalYReferral, int upAerialWidthReferral, int upAerialHeightReferral, float upAerialStunDurationReferral, float upAerialScalarXReferral, float upAerialScalarYReferral, float upAerialFixedXReferral, float upAerialFixedYReferral, float upAerialVxReferral, float upAerialVyReferral, float upAerialDamageReferral, float upAerialStartUpDurationReferral, float upAerialActiveDurationReferral, float upAerialEndLagDurationReferral, bool upAerialIsAttachedToPlayerReferral, bool upAerialDissapearOnHitReferral, int downAerialAdditionalXReferral, int downAerialAdditionalYReferral, int downAerialWidthReferral, int downAerialHeightReferral, float downAerialStunDurationReferral, float downAerialScalarXReferral, float downAerialScalarYReferral, float downAerialFixedXReferral, float downAerialFixedYReferral, float downAerialVxReferral, float downAerialVyReferral, float downAerialDamageReferral, float downAerialStartUpDurationReferral, float downAerialActiveDurationReferral, float downAerialEndLagDurationReferral, bool downAerialIsAttachedToPlayerReferral, bool downAerialDissapearOnHitReferral, int forwardSpecialAdditionalXReferral, int forwardSpecialAdditionalYReferral, int forwardSpecialWidthReferral, int forwardSpecialHeightReferral, float forwardSpecialStunDurationReferral, float forwardSpecialScalarXReferral, float forwardSpecialScalarYReferral, float forwardSpecialFixedXReferral, float forwardSpecialFixedYReferral, float forwardSpecialVxReferral, float forwardSpecialVyReferral, float forwardSpecialDamageReferral, float forwardSpecialStartUpDurationReferral, float forwardSpecialActiveDurationReferral, float forwardSpecialEndLagDurationReferral, bool forwardSpecialIsAttachedToPlayerReferral, bool forwardSpecialDissapearOnHitReferral, int upSpecialAdditionalXReferral, int upSpecialAdditionalYReferral, int upSpecialWidthReferral, int upSpecialHeightReferral, float upSpecialStunDurationReferral, float upSpecialScalarXReferral, float upSpecialScalarYReferral, float upSpecialFixedXReferral, float upSpecialFixedYReferral, float upSpecialVxReferral, float upSpecialVyReferral, float upSpecialDamageReferral, float upSpecialStartUpDurationReferral, float upSpecialActiveDurationReferral, float upSpecialEndLagDurationReferral, bool upSpecialIsAttachedToPlayerReferral, bool upSpecialDissapearOnHitReferral, int downSpecialAdditionalXReferral, int downSpecialAdditionalYReferral, int downSpecialWidthReferral, int downSpecialHeightReferral, float downSpecialStunDurationReferral, float downSpecialScalarXReferral, float downSpecialScalarYReferral, float downSpecialFixedXReferral, float downSpecialFixedYReferral, float downSpecialVxReferral, float downSpecialVyReferral, float downSpecialDamageReferral, float downSpecialStartUpDurationReferral, float downSpecialActiveDurationReferral, float downSpecialEndLagDurationReferral, bool downSpecialIsAttachedToPlayerReferral, bool downSpecialDissapearOnHitReferral) {
	x = xReferral;
	y = yReferral;
	vx = 0;
	vy = 0;
	lives = livesReferral;
	width = widthReferral;
	height = heightReferral;
	walkSpeed = walkSpeedReferral;
	aerialSpeed = aerialSpeedReferral;
	aerialAcceleration = aerialAccelerationReferral;
	walkAcceleration = walkAccelerationReferral;
	groundJumpHeight = groundJumpHeightReferral;
	aerialJumpHeight = aerialJumpHeightReferral;
	fallAcceleration = fallAccelerationReferral;
	fallSpeed = fallSpeedReferral;
	maxDoubleJump = maxDoubleJumpReferral;
	doubleJump = maxDoubleJump;

	forwardLightAdditionalX = forwardLightAdditionalXReferral;
	forwardLightAdditionalY = forwardLightAdditionalYReferral;
	forwardLightWidth = forwardLightWidthReferral;
	forwardLightHeight = forwardLightHeightReferral;
	forwardLightStunDuration = forwardLightStunDurationReferral;
	forwardLightScalarX = forwardLightScalarXReferral;
	forwardLightScalarY = forwardLightScalarYReferral;
	forwardLightFixedX = forwardLightFixedXReferral;
	forwardLightFixedY = forwardLightFixedYReferral;
	forwardLightVx = forwardLightVxReferral;
	forwardLightVy = forwardLightVyReferral;
	forwardLightDamage = forwardLightDamageReferral;
	forwardLightStartUpDuration = forwardLightStartUpDurationReferral;
	forwardLightActiveDuration = forwardLightActiveDurationReferral;
	forwardLightEndLagDuration = forwardLightEndLagDurationReferral;
	forwardLightIsAttachedToPlayer = forwardLightIsAttachedToPlayerReferral;
	forwardLightDissapearOnHit = forwardLightDissapearOnHitReferral;

	upLightAdditionalX = upLightAdditionalXReferral;
	upLightAdditionalY = upLightAdditionalYReferral;
	upLightWidth = upLightWidthReferral;
	upLightHeight = upLightHeightReferral;
	upLightStunDuration = upLightStunDurationReferral;
	upLightScalarX = upLightScalarXReferral;
	upLightScalarY = upLightScalarYReferral;
	upLightFixedX = upLightFixedXReferral;
	upLightFixedY = upLightFixedYReferral;
	upLightVx = upLightVxReferral;
	upLightVy = upLightVyReferral;
	upLightDamage = upLightDamageReferral;
	upLightStartUpDuration = upLightStartUpDurationReferral;
	upLightActiveDuration = upLightActiveDurationReferral;
	upLightEndLagDuration = upLightEndLagDurationReferral;
	upLightIsAttachedToPlayer = upLightIsAttachedToPlayerReferral;
	upLightDissapearOnHit = upLightDissapearOnHitReferral;

	downLightAdditionalX = downLightAdditionalXReferral;
	downLightAdditionalY = downLightAdditionalYReferral;
	downLightWidth = downLightWidthReferral;
	downLightHeight = downLightHeightReferral;
	downLightStunDuration = downLightStunDurationReferral;
	downLightScalarX = downLightScalarXReferral;
	downLightScalarY = downLightScalarYReferral;
	downLightFixedX = downLightFixedXReferral;
	downLightFixedY = downLightFixedYReferral;
	downLightVx = downLightVxReferral;
	downLightVy = downLightVyReferral;
	downLightDamage = downLightDamageReferral;
	downLightStartUpDuration = downLightStartUpDurationReferral;
	downLightActiveDuration = downLightActiveDurationReferral;
	downLightEndLagDuration = downLightEndLagDurationReferral;
	downLightIsAttachedToPlayer = downLightIsAttachedToPlayerReferral;
	downLightDissapearOnHit = downLightDissapearOnHitReferral;

	forwardHeavyAdditionalX = forwardHeavyAdditionalXReferral;
	forwardHeavyAdditionalY = forwardHeavyAdditionalYReferral;
	forwardHeavyWidth = forwardHeavyWidthReferral;
	forwardHeavyHeight = forwardHeavyHeightReferral;
	forwardHeavyStunDuration = forwardHeavyStunDurationReferral;
	forwardHeavyScalarX = forwardHeavyScalarXReferral;
	forwardHeavyScalarY = forwardHeavyScalarYReferral;
	forwardHeavyFixedX = forwardHeavyFixedXReferral;
	forwardHeavyFixedY = forwardHeavyFixedYReferral;
	forwardHeavyVx = forwardHeavyVxReferral;
	forwardHeavyVy = forwardHeavyVyReferral;
	forwardHeavyDamage = forwardHeavyDamageReferral;
	forwardHeavyStartUpDuration = forwardHeavyStartUpDurationReferral;
	forwardHeavyActiveDuration = forwardHeavyActiveDurationReferral;
	forwardHeavyEndLagDuration = forwardHeavyEndLagDurationReferral;
	forwardHeavyIsAttachedToPlayer = forwardHeavyIsAttachedToPlayerReferral;
	forwardHeavyDissapearOnHit = forwardHeavyDissapearOnHitReferral;

	upHeavyAdditionalX = upHeavyAdditionalXReferral;
	upHeavyAdditionalY = upHeavyAdditionalYReferral;
	upHeavyWidth = upHeavyWidthReferral;
	upHeavyHeight = upHeavyHeightReferral;
	upHeavyStunDuration = upHeavyStunDurationReferral;
	upHeavyScalarX = upHeavyScalarXReferral;
	upHeavyScalarY = upHeavyScalarYReferral;
	upHeavyFixedX = upHeavyFixedXReferral;
	upHeavyFixedY = upHeavyFixedYReferral;
	upHeavyVx = upHeavyVxReferral;
	upHeavyVy = upHeavyVyReferral;
	upHeavyDamage = upHeavyDamageReferral;
	upHeavyStartUpDuration = upHeavyStartUpDurationReferral;
	upHeavyActiveDuration = upHeavyActiveDurationReferral;
	upHeavyEndLagDuration = upHeavyEndLagDurationReferral;
	upHeavyIsAttachedToPlayer = upHeavyIsAttachedToPlayerReferral;
	upHeavyDissapearOnHit = upHeavyDissapearOnHitReferral;

	downHeavyAdditionalX = downHeavyAdditionalXReferral;
	downHeavyAdditionalY = downHeavyAdditionalYReferral;
	downHeavyWidth = downHeavyWidthReferral;
	downHeavyHeight = downHeavyHeightReferral;
	downHeavyStunDuration = downHeavyStunDurationReferral;
	downHeavyScalarX = downHeavyScalarXReferral;
	downHeavyScalarY = downHeavyScalarYReferral;
	downHeavyFixedX = downHeavyFixedXReferral;
	downHeavyFixedY = downHeavyFixedYReferral;
	downHeavyVx = downHeavyVxReferral;
	downHeavyVy = downHeavyVyReferral;
	downHeavyDamage = downHeavyDamageReferral;
	downHeavyStartUpDuration = downHeavyStartUpDurationReferral;
	downHeavyActiveDuration = downHeavyActiveDurationReferral;
	downHeavyEndLagDuration = downHeavyEndLagDurationReferral;
	downHeavyIsAttachedToPlayer = downHeavyIsAttachedToPlayerReferral;
	downHeavyDissapearOnHit = downHeavyDissapearOnHitReferral;

	forwardAerialAdditionalX = forwardAerialAdditionalXReferral;
	forwardAerialAdditionalY = forwardAerialAdditionalYReferral;
	forwardAerialWidth = forwardAerialWidthReferral;
	forwardAerialHeight = forwardAerialHeightReferral;
	forwardAerialStunDuration = forwardAerialStunDurationReferral;
	forwardAerialScalarX = forwardAerialScalarXReferral;
	forwardAerialScalarY = forwardAerialScalarYReferral;
	forwardAerialFixedX = forwardAerialFixedXReferral;
	forwardAerialFixedY = forwardAerialFixedYReferral;
	forwardAerialVx = forwardAerialVxReferral;
	forwardAerialVy = forwardAerialVyReferral;
	forwardAerialDamage = forwardAerialDamageReferral;
	forwardAerialStartUpDuration = forwardAerialStartUpDurationReferral;
	forwardAerialActiveDuration = forwardAerialActiveDurationReferral;
	forwardAerialEndLagDuration = forwardAerialEndLagDurationReferral;
	forwardAerialIsAttachedToPlayer = forwardAerialIsAttachedToPlayerReferral;
	forwardAerialDissapearOnHit = forwardAerialDissapearOnHitReferral;

	backAerialAdditionalX = backAerialAdditionalXReferral;
	backAerialAdditionalY = backAerialAdditionalYReferral;
	backAerialWidth = backAerialWidthReferral;
	backAerialHeight = backAerialHeightReferral;
	backAerialStunDuration = backAerialStunDurationReferral;
	backAerialScalarX = backAerialScalarXReferral;
	backAerialScalarY = backAerialScalarYReferral;
	backAerialFixedX = backAerialFixedXReferral;
	backAerialFixedY = backAerialFixedYReferral;
	backAerialVx = backAerialVxReferral;
	backAerialVy = backAerialVyReferral;
	backAerialDamage = backAerialDamageReferral;
	backAerialStartUpDuration = backAerialStartUpDurationReferral;
	backAerialActiveDuration = backAerialActiveDurationReferral;
	backAerialEndLagDuration = backAerialEndLagDurationReferral;
	backAerialIsAttachedToPlayer = backAerialIsAttachedToPlayerReferral;
	backAerialDissapearOnHit = backAerialDissapearOnHitReferral;

	upAerialAdditionalX = upAerialAdditionalXReferral;
	upAerialAdditionalY = upAerialAdditionalYReferral;
	upAerialWidth = upAerialWidthReferral;
	upAerialHeight = upAerialHeightReferral;
	upAerialStunDuration = upAerialStunDurationReferral;
	upAerialScalarX = upAerialScalarXReferral;
	upAerialScalarY = upAerialScalarYReferral;
	upAerialFixedX = upAerialFixedXReferral;
	upAerialFixedY = upAerialFixedYReferral;
	upAerialVx = upAerialVxReferral;
	upAerialVy = upAerialVyReferral;
	upAerialDamage = upAerialDamageReferral;
	upAerialStartUpDuration = upAerialStartUpDurationReferral;
	upAerialActiveDuration = upAerialActiveDurationReferral;
	upAerialEndLagDuration = upAerialEndLagDurationReferral;
	upAerialIsAttachedToPlayer = upAerialIsAttachedToPlayerReferral;
	upAerialDissapearOnHit = upAerialDissapearOnHitReferral;

	downAerialAdditionalX = downAerialAdditionalXReferral;
	downAerialAdditionalY = downAerialAdditionalYReferral;
	downAerialWidth = downAerialWidthReferral;
	downAerialHeight = downAerialHeightReferral;
	downAerialStunDuration = downAerialStunDurationReferral;
	downAerialScalarX = downAerialScalarXReferral;
	downAerialScalarY = downAerialScalarYReferral;
	downAerialFixedX = downAerialFixedXReferral;
	downAerialFixedY = downAerialFixedYReferral;
	downAerialVx = downAerialVxReferral;
	downAerialVy = downAerialVyReferral;
	downAerialDamage = downAerialDamageReferral;
	downAerialStartUpDuration = downAerialStartUpDurationReferral;
	downAerialActiveDuration = downAerialActiveDurationReferral;
	downAerialEndLagDuration = downAerialEndLagDurationReferral;
	downAerialIsAttachedToPlayer = downAerialIsAttachedToPlayerReferral;
	downAerialDissapearOnHit = downAerialDissapearOnHitReferral;

	forwardSpecialAdditionalX = forwardSpecialAdditionalXReferral;
	forwardSpecialAdditionalY = forwardSpecialAdditionalYReferral;
	forwardSpecialWidth = forwardSpecialWidthReferral;
	forwardSpecialHeight = forwardSpecialHeightReferral;
	forwardSpecialStunDuration = forwardSpecialStunDurationReferral;
	forwardSpecialScalarX = forwardSpecialScalarXReferral;
	forwardSpecialScalarY = forwardSpecialScalarYReferral;
	forwardSpecialFixedX = forwardSpecialFixedXReferral;
	forwardSpecialFixedY = forwardSpecialFixedYReferral;
	forwardSpecialVx = forwardSpecialVxReferral;
	forwardSpecialVy = forwardSpecialVyReferral;
	forwardSpecialDamage = forwardSpecialDamageReferral;
	forwardSpecialStartUpDuration = forwardSpecialStartUpDurationReferral;
	forwardSpecialActiveDuration = forwardSpecialActiveDurationReferral;
	forwardSpecialEndLagDuration = forwardSpecialEndLagDurationReferral;
	forwardSpecialIsAttachedToPlayer = forwardSpecialIsAttachedToPlayerReferral;
	forwardSpecialDissapearOnHit = forwardSpecialDissapearOnHitReferral;

	upSpecialAdditionalX = upSpecialAdditionalXReferral;
	upSpecialAdditionalY = upSpecialAdditionalYReferral;
	upSpecialWidth = upSpecialWidthReferral;
	upSpecialHeight = upSpecialHeightReferral;
	upSpecialStunDuration = upSpecialStunDurationReferral;
	upSpecialScalarX = upSpecialScalarXReferral;
	upSpecialScalarY = upSpecialScalarYReferral;
	upSpecialFixedX = upSpecialFixedXReferral;
	upSpecialFixedY = upSpecialFixedYReferral;
	upSpecialVx = upSpecialVxReferral;
	upSpecialVy = upSpecialVyReferral;
	upSpecialDamage = upSpecialDamageReferral;
	upSpecialStartUpDuration = upSpecialStartUpDurationReferral;
	upSpecialActiveDuration = upSpecialActiveDurationReferral;
	upSpecialEndLagDuration = upSpecialEndLagDurationReferral;
	upSpecialIsAttachedToPlayer = upSpecialIsAttachedToPlayerReferral;
	upSpecialDissapearOnHit = upSpecialDissapearOnHitReferral;

	downSpecialAdditionalX = downSpecialAdditionalXReferral;
	downSpecialAdditionalY = downSpecialAdditionalYReferral;
	downSpecialWidth = downSpecialWidthReferral;
	downSpecialHeight = downSpecialHeightReferral;
	downSpecialStunDuration = downSpecialStunDurationReferral;
	downSpecialScalarX = downSpecialScalarXReferral;
	downSpecialScalarY = downSpecialScalarYReferral;
	downSpecialFixedX = downSpecialFixedXReferral;
	downSpecialFixedY = downSpecialFixedYReferral;
	downSpecialVx = downSpecialVxReferral;
	downSpecialVy = downSpecialVyReferral;
	downSpecialDamage = downSpecialDamageReferral;
	downSpecialStartUpDuration = downSpecialStartUpDurationReferral;
	downSpecialActiveDuration = downSpecialActiveDurationReferral;
	downSpecialEndLagDuration = downSpecialEndLagDurationReferral;
	downSpecialIsAttachedToPlayer = downSpecialIsAttachedToPlayerReferral;
	downSpecialDissapearOnHit = downSpecialDissapearOnHitReferral;
}

void Character::IsHit(int stunReferral, int damage, int fixedX, int fixedY, int scalarX, int scalarY)
{
	stun = stunReferral;
	playerPercentage = playerPercentage + damage;
	vx = fixedX + scalarX * playerPercentage / 100;
	vy = fixedY + scalarY * playerPercentage / 100;
	moveDuration = 0;
	Move1.PlayerIsHit();
	Move2.PlayerIsHit();
	Move3.PlayerIsHit();
	Move4.PlayerIsHit();
	Move5.PlayerIsHit();
}
