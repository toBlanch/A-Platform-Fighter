#include "Character.h"

void Character::UpdateCharacter(bool left, bool right, bool down, bool jump, int stageX0, int stageY0, int stageX1, int stageY1) {
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
	if (!left&&!right) { //If not moving left or right
		if (vx > 0) { //If moving right
			if (vx < acceleration) { //If decreasing speed would make you move left
				vx = 0; //Set it to 0
			}
			else {
				vx -= acceleration; //Decrease speed
			}
		}
		if (vx < 0) { //If moving left
			if (vx < -acceleration) { //If decreasing speed would make you move right
				vx = 0; //Set it to 0
			}
			else {
				vx += acceleration; //Decrease speed
			}
		}
	}

	//Jumping
	if (jump == false) { //If you're not holding jump
		jumpKeyHeld = false; //Confirm you're not holding jump
	}
	else if (onStage) { //If on stage and jump key is held
		vy = -groundJumpHeight; //Start jumping
		jumpKeyHeld = true; //Jump key is held
	}
	else if (doubleJump > 0 && !jumpKeyHeld) { //If off stage, jumping, you have a double jump and the jump key is held
		jumpKeyHeld = true; //Set jump key held to true
		fastFalling = false; //Stop fast falling
		doubleJump-=1; //Remove one double jump
		vy = -aerialJumpHeight; //Start jumping
	}


	if (down) { //If down key is held
		fastFalling = true; //Start fast falling
	}
	if (fastFalling) { 
		if (vy < fallSpeed*2) { //If not at terminal velocity
			vy += fallAcceleration*2; //Increase falling speed
			if (vy > fallSpeed*2) { //If over terminal velocity
				vy = fallSpeed*2; //Set to terminal velocity
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
		if (y + height >= stageY0  && y <= stageY1 && x + width > stageX0 && x + width <= stageX0 + speed) { //If clipping into stage from the left
			x = stageX0 - width; //Stop clipping
		}
		else if (y + height >= stageY0 && y <= stageY1 && x >= stageX1 - speed && x < stageX1) { //If clipping into stage from right
			x = stageX1; //Stop clipping
		}
		else if (x + width > stageX0 + speed && x + speed < stageX1 - speed && y > stageY1 - fallSpeed * 2 && y < stageY1) { //If clipping into stage from bottom
			y = stageY1; //Stop clipping
		}
	}
}
