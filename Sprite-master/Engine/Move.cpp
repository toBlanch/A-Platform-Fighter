#include "Move.h"

void Move::CheckStatus(int xReferral, int yReferral)
{
	if (startUpDuration > 0) {
		startUpDuration--;
	}
	else if (activeDuration > 0) {
		activeDuration--;
		if (isAttachedToPlayer) {
			x = xReferral + playerWidth / 2;
			y = yReferral;
		}
		else {
			x += vx;
			y += vy;
		}
	}
}

void Move::Activate(int xReferral, int yReferral, int moveID, bool isFacingRight)
{
	hasHit = false;
	if (moveID == 1) { //light
		x = xReferral+playerWidth/2;
		y = yReferral;
		additionalX = 50;
		additionalY = 0;
		vx = 0;
		vy = 0;
		isAttachedToPlayer = true;
		startUpDuration = 10;
		activeDuration = 30;
		endLagDuration = 10;
		stunDuration = 40;
		width = 50;
		height = 10;
		fixedX = 3;
		fixedY = -3;
		scalarX = 5;
		scalarY = -5;
		damage = 10;
	}
	else if(moveID == 2) { //special
		x = xReferral + playerWidth / 2;
		y = yReferral;
		additionalX = 100;
		additionalY = 0;
		vx = 10;
		vy = 0.5;
		isAttachedToPlayer = false;
		startUpDuration = 10;
		activeDuration = 80;
		endLagDuration = 10;
		stunDuration = 20;
		width = 50;
		height = 10;
		fixedX = 3;
		fixedY = -3;
		scalarX = 15;
		scalarY = -1;
		damage = 5;
	}
	else { //heavy
		x = xReferral + playerWidth / 2;
		y = yReferral;
		additionalX = 50;
		additionalY = 50;
		vx = 0;
		vy = 0;
		isAttachedToPlayer = true;
		startUpDuration = 30;
		activeDuration = 20;
		endLagDuration = 60;
		stunDuration = 40;
		width = 120;
		height = 50;
		fixedX = 5;
		fixedY = -5;
		scalarX = 20;
		scalarY = -5;
		damage = 20;
	}
	if (!isFacingRight) {
		additionalX = additionalX*-1-width;
		fixedX *= -1;
		scalarX *= -1;
		vx *= -1;
	}
}

bool Move::Draw()
{
	return activeDuration>0&&startUpDuration==0;
}

void Move::EndMove()
{
	activeDuration = 0;
	startUpDuration = 0;
}

bool Move::IsMoveColliding(int Player2x, int Player2y, int Player2width, int Player2height)
{
	if (!hasHit&&activeDuration > 0 && startUpDuration==0) {
		for (int i = y+additionalY; i < y + height+additionalY; i++) {
			for (int j = x+additionalX; j < x + width+additionalX; j++) {
				if (i > Player2y && i<Player2y + Player2height && j>Player2x && j < Player2x + Player2width) {
					hasHit = true;
					return true;
				}
			}
		}
	}
	return false;
}

void Move::PlayerIsHit()
{
	if (isAttachedToPlayer) {
		startUpDuration = 0;
		activeDuration = 0;
	}
}
