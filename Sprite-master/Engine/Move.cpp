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

void Move::Activate(bool isFacingRight, int xReferral, int yReferral, int additionalXReferral, int additionalYReferral, int widthReferral, int heightReferral, float stunDurationReferral, float scalarXReferral, float scalarYReferral, float fixedXReferral, float fixedYReferral, float vxReferral, float vyReferral, float damageReferral, float startUpDurationReferral, float activeDurationReferral, float endLagDurationReferral, bool isAttachedToPlayerReferral, bool dissapearOnHitReferral)
{
	hasHit = false;
	x = xReferral + playerWidth / 2;
	y = yReferral;
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
	damage = damageReferral;
	startUpDuration = startUpDurationReferral;
	activeDuration = activeDurationReferral;
	endLagDuration = endLagDurationReferral;
	isAttachedToPlayer = isAttachedToPlayerReferral;
	dissapearOnHit = dissapearOnHitReferral;
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
					if (dissapearOnHit) {
						activeDuration = 0;
					}
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

int Move::IsActiveDuration()
{
	if (isAttachedToPlayer) {
		return activeDuration;
	}
	return 0;
}
