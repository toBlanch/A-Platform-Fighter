#include "Move.h"

void Move::CheckStatus(float xReferral, float yReferral)
{
	if (startUpDuration > 0) { //If not active yet
		startUpDuration--; //Decrease the time until it starts
	}
	else if (activeDuration > 0) { //If move is active
		activeDuration--; //Decrease the time until the move ends
		vx += accelerationx;
		vy += accelerationy;
		x += vx; //Increase the X coordinate
		y += vy; //Increase the Y coordinate
	}
	if (isAttachedToPlayer || startUpDuration > 0) { //If the move is activating or if attached to the player
		x = xReferral + playerWidth / 2; //Set the x coordinate to half way through the player
		y = yReferral; //Set the Y coordinate to the player's
	}
}

void Move::Activate(int playerWidthReferral, bool isFacingRight, int additionalXReferral, int additionalYReferral, int widthReferral, int heightReferral, float stunDurationReferral, float scalarXReferral, float scalarYReferral, float fixedXReferral, float fixedYReferral, float vxReferral, float vyReferral, float accelerationxReferral, float accelerationyReferral, float damageReferral, float startUpDurationReferral, float activeDurationReferral, float endLagDurationReferral, bool isAttachedToPlayerReferral, bool isPlayerAttachedToItReferral, bool disappearOnHitReferral, int rReferral, int gReferral, int bReferral)
{
	//Refer variables 
	hasHit = false;
	playerWidth = playerWidthReferral;
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
		additionalX = additionalX*-1-width; //Flip the additional value left
		fixedX *= -1; //Flip the fixed horizontal knockback
		scalarX *= -1; //Fix the scalar horizontal knockback
		vx *= -1; //Flip thehorizontal movement
		accelerationx *= -1; //Flip the horizontal acceleration
	}
	r = rReferral;
	g = gReferral;
	b = bReferral;
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
		for (int i = y + additionalY; i < y + height + additionalY; i++) { //For every Y coordinate
			for (int j = x + additionalX; j < x + width + additionalX; j++) { //For every X coordinate
				if (i > Player2y && i<Player2y + Player2height && j>Player2x && j < Player2x + Player2width) { //If in the player's coordinates
					if (disappearOnHit) { //If the move should disappear after hitting an opponent
						activeDuration = 0; //Disable the move
					}
					hasHit = true; //Make the function not run again
					return true; //The move has hit
				}
			}
		}
	}
	return false; //The move has not hit
}

void Move::PlayerIsHit()
{
	if (isAttachedToPlayer) { //If the move is dependant on the player
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
