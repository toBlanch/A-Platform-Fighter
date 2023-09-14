#include "Move.h"

void Move::CheckStatus(float xReferral, float yReferral, int stageX0, int stageY0, int stageX1, int stageY1)
{
	if (startUpDuration > 0) { //If not active yet
		startUpDuration--; //Decrease the time until it starts
	}
	else if (activeDuration > 0) { //If move is active
		activeDuration--; //Decrease the time until the move ends
		vx += accelerationx;
		vy += accelerationy;

		x += vx;
		y += vy;

		if (isPlayerAttachedToIt) {
			x = xReferral + vx;
			y = yReferral + vy;
		}
		else if (!isAttachedToPlayer) {
			bool xOnStage = x + additionalX + width > stageX0 && x + additionalX < stageX1;
			bool yOnStage = y + additionalY + height >= stageY0 && y + additionalY <= stageY1;

			if (yOnStage && x + additionalX + width > stageX0 && x + additionalX + width <= stageX0 + vx) { //If clipping into stage from the left
				x = float(stageX0) - width - additionalX; //Stop clipping
			}
			else if (yOnStage && x + additionalX >= stageX1 + vx && x + additionalX < stageX1) { //If clipping into stage from right
				x = (float)stageX1 - additionalX; //Stop clipping
			}

			if (xOnStage && y + additionalY + height >= stageY0 && y + additionalY + height <= stageY0 + vy) {
				y = (float)stageY0 - height - additionalY; //Stop clipping
			}
			else if (xOnStage && y + additionalY >= stageY1 - vy && y + additionalY <= stageY1) {
				y = (float)stageY1 - additionalY; //Stop clipping
			}
		}
	}

	if (isAttachedToPlayer || startUpDuration > 0) { //If the move is activating or if attached to the player
		x = xReferral; //Set the X coordinate to the player's
		y = yReferral; //Set the Y coordinate to the player's

		bool xOnStage = x + additionalX + width > stageX0 && x + additionalX < stageX1;
		bool yOnStage = y + additionalY + height >= stageY0 && y + additionalY <= stageY1;

		if (yOnStage && x + additionalX + width > stageX0 && x + additionalX + width <= stageX0 + additionalX) { //If clipping into stage from the left
			x = float(stageX0) - width - additionalX; //Stop clipping
		}
		else if (yOnStage && x + additionalX >= stageX1 + additionalX && x + additionalX < stageX1) { //If clipping into stage from right
			x = (float)stageX1 - additionalX; //Stop clipping
		}

		if (xOnStage && y + additionalY + height >= stageY0 && y + additionalY + height <= stageY0 + additionalY) {
			y = (float)stageY0 - height - additionalY; //Stop clipping
		}
		else if (xOnStage && y + additionalY >= stageY1 - additionalY && y + additionalY <= stageY1) {
			y = (float)stageY1 - additionalY; //Stop clipping
		}
	}
}

void Move::Activate(int playerWidthReferral, int playerHeightReferral, bool isFacingRight, int additionalXReferral, int additionalYReferral, int widthReferral, int heightReferral, float stunDurationReferral, float scalarXReferral, float scalarYReferral, float fixedXReferral, float fixedYReferral, float vxReferral, float vyReferral, float accelerationxReferral, float accelerationyReferral, float damageReferral, float startUpDurationReferral, float activeDurationReferral, float endLagDurationReferral, bool isAttachedToPlayerReferral, bool isPlayerAttachedToItReferral, bool disappearOnHitReferral, int rReferral, int gReferral, int bReferral, int player2WidthReferral, int player2HeightReferral)
{
	//Refer variables 
	hasHit = false;
	additionalX = additionalXReferral;
	additionalY = additionalYReferral;
	width = widthReferral;
	height = heightReferral;
	stunDuration = stunDurationReferral;
	scalarX = scalarXReferral;
	scalarY = scalarYReferral;
	fixedX = fixedXReferral;
	fixedY = fixedYReferral;
	vx = vxReferral;
	vy = vyReferral;
	accelerationx = accelerationxReferral;
	accelerationy = accelerationyReferral;
	damage = damageReferral;
	startUpDuration = startUpDurationReferral;
	activeDuration = activeDurationReferral;
	endLagDuration = endLagDurationReferral;
	isAttachedToPlayer = isAttachedToPlayerReferral;
	isPlayerAttachedToIt = isPlayerAttachedToItReferral;
	disappearOnHit = disappearOnHitReferral;

	if (!isFacingRight) { //If facing left
		additionalX = additionalX * -1 + playerWidthReferral - width; //Flip the additional value left
		fixedX *= -1; //Flip the fixed horizontal knockback
		scalarX *= -1; //Fix the scalar horizontal knockback
		vx *= -1; //Flip thehorizontal movement
		accelerationx *= -1; //Flip the horizontal acceleration
	}
	r = rReferral;
	g = gReferral;
	b = bReferral;

	xCoordinates[0] = 0;
	xCoordinates[1] = width; //Sets the maximum possible coordinate to every value that can obtain it
	xCoordinates[2] = width; //Sets the maximum possible coordinate to every value that can obtain it
	xCoordinates[3] = width; //Sets the maximum possible coordinate to every value that can obtain it
	for (int i = 1; i * player2WidthReferral < width; i++) { //For every coordinate that fits inside the player's width
		xCoordinates[i] = i * player2WidthReferral; //Add that coordinate to an array
	}
	yCoordinates[0] = 0;
	yCoordinates[1] = height; //Sets the maximum possible coordinate to every value that can obtain it
	yCoordinates[2] = height; //Sets the maximum possible coordinate to every value that can obtain it
	yCoordinates[3] = height; //Sets the maximum possible coordinate to every value that can obtain it
	for (int i = 1; i * player2HeightReferral < height; i++) { //For every coordinate that fits inside the player's height
		yCoordinates[i] = i * player2HeightReferral; //Add that coordinate to an array
	}
}

bool Move::Draw()
{
	return activeDuration > 0 && startUpDuration == 0; //If the move is active and not starting up
}

void Move::EndMove()
{
	activeDuration = 0; //Disable the move
	startUpDuration = 0; //Remove the startup
	isPlayerAttachedToIt = false;
}

bool Move::IsMoveColliding(float Player2x, float Player2y, int Player2width, int Player2height)
{
	if (!hasHit && activeDuration > 0 && startUpDuration == 0) { //If the move has an active hitbox
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (x + additionalX + xCoordinates[i] >= Player2x && //If the X coordinate is greater than the player's
					x + additionalX + xCoordinates[i] <= Player2x + Player2width && //If the x coordinate is less than the player's plus their width
					y + additionalY + yCoordinates[j] >= Player2y && //If the Y coordniate is greater than the player's
					y + additionalY + yCoordinates[j] <= Player2y + Player2height //If the y coordinate is les than the player's plus their height
					) { //If inside the player's coordinates
					hasHit = true; //Stop the fucntion from running again
					if (disappearOnHit) {
						activeDuration = 1; //Disable
					}
					return true; //The move has hit
				}
			}
		}
	}
	return false; //The move has not hit
}

void Move::PlayerIsHit()
{
	if (isAttachedToPlayer || isPlayerAttachedToIt) { //If the move is dependant on the player
		startUpDuration = 0; //Disable it
		activeDuration = 0; //Disable it
	}
}

int Move::IsActiveDuration()
{
	if (isAttachedToPlayer || isPlayerAttachedToIt) { //If the move's active duration is the same as the player's
		return activeDuration; //Return the true active duration
	}
	return 0; //Return nothing to keep active duration of the move and player separate
}
