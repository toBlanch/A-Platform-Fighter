#include "Move.h"

void Move::CheckStatus(float xReferral, float yReferral, Platform Platforms[10])
{
	startUpDuration--; //Decrease the time until it starts
	if (startUpDuration < 0) {
		activeDuration--;
		if (activeDuration >= 0) { //If move is active
			vx += stats.accelerationX;
			vy += stats.accelerationY;

			x += isFacingRight ? vx : -vx;
			y += vy;

			if (stats.isPlayerAttachedToIt) {
				x = xReferral + (isFacingRight ? vx : -vx);
				y = yReferral + vy;
			}
			else if (!stats.isAttachedToPlayer) {
				for (int i = 0; i < 10; i++) {
					if (Platforms[i].isSolid) {
						int stageX0 = Platforms[i].x0;
						int stageX1 = Platforms[i].x1;
						int stageY0 = Platforms[i].y0;
						int stageY1 = Platforms[i].y1;
						bool xOnStage = x + additionalX + stats.width > stageX0 && x + additionalX < stageX1;
						bool yOnStage = y + stats.additionalY + stats.height >= stageY0 && y + stats.additionalY <= stageY1;

						if (yOnStage && x + additionalX + stats.width > stageX0 && x + additionalX + stats.width <= stageX0 + (isFacingRight ? vx : -vx)) { //If clipping into stage from the left
							x = float(stageX0) - stats.width - additionalX; //Stop clipping
						}
						else if (yOnStage && x + additionalX >= stageX1 + (isFacingRight ? vx : -vx) && x + additionalX < stageX1) { //If clipping into stage from right
							x = (float)stageX1 - additionalX; //Stop clipping
						}

						if (xOnStage && y + stats.additionalY + stats.height >= stageY0 && y + stats.additionalY + stats.height <= stageY0 + vy) {
							y = (float)stageY0 - stats.height - stats.additionalY; //Stop clipping
						}
						else if (xOnStage && y + stats.additionalY >= stageY1 - vy && y + stats.additionalY <= stageY1) {
							y = (float)stageY1 - stats.additionalY; //Stop clipping
						}
					}
				}
			}
		}

	}

	if (stats.isAttachedToPlayer || startUpDuration >= 0) { //If the move is attached to the player or activating 
		x = xReferral; //Set the X coordinate to the player's
		y = yReferral; //Set the Y coordinate to the player's
	}
}

void Move::Activate(int playerWidthReferral, bool rIsFacingRight, MoveTemplate rStats)
{
	//Refer variables 
	hasHit = false;

	stats = rStats;
	isFacingRight = rIsFacingRight;
	vx = stats.initialVx;
	vy = stats.initialVy;
	startUpDuration = stats.initialStartUpDuration;
	activeDuration = stats.initialActiveDuration;
	endLagDuration = stats.initialEndLagDuration;

	if (isFacingRight) {
		additionalX = stats.additionalXRight;
	}
	else {
		additionalX = stats.additionalXRight * -1 + playerWidthReferral - stats.width; //Flip the additional value left
	}
}

void Move::EndMove()
{
	activeDuration = -1; //Disable the move
	startUpDuration = -1; //Remove the startup
	stats = 0; //Removes some factors such as IsPlayerAttachedToIt that will still be used
}

void Move::PlayerIsHit()
{
	if (stats.isAttachedToPlayer || stats.isPlayerAttachedToIt) { //If the move is dependant on the player
		EndMove();
	}
}

int Move::IsActiveDuration()
{
	if (stats.isAttachedToPlayer || stats.isPlayerAttachedToIt) { //If the move's active duration is the same as the player's
		return activeDuration; //Return the true active duration
	}
	return 0; //Return nothing to keep active duration of the move and player separate
}
