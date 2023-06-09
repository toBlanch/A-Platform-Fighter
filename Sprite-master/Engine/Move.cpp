#include "Move.h"

void Move::CheckStatus(int xReferral, int yReferral)
{
	if (startUpDuration > 0) {
		startUpDuration--;
	}
	if (activeDuration > 0&&startUpDuration==0) {
		activeDuration--;
		if (isAttachedToPlayer) {
			if (isPlayer1) {
				x = xReferral;
				y = yReferral;
			}
		}
		//IsCollidingWithPlayer()
	}
}

bool Move::IsAvailable()
{
	if (activeDuration == 0) {
		return true;
	}
}

int Move::StartUp(int move)
{
	return startUpDuration;
}

int Move::Duration(int move)
{
	return activeDuration;
}

int Move::EndLag(int move)
{
	return 50;
}

void Move::Activate(int xReferral, int yReferral, bool isAttachedToPlayerReferral)
{
	x = xReferral;
	y = yReferral;
	isAttachedToPlayer = isAttachedToPlayerReferral;
	startUpDuration = 10;
	activeDuration = 30;
	stunDuration = 20;
	width = 50;
	height = 10;
	fixedX = 3;
	fixedY = -3;
	scalarX = 10;
	scalarY = -10;
	damage = 10;
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
	if (activeDuration > 0) {
		for (int i = y; i < y + height; i++) {
			for (int j = x; j < x + width; j++) {
				if (i > Player2y && i<Player2y + Player2height && j>Player2x && j < Player2x + Player2width) {
					return true;
				}
			}
		}
	}
	return false;
}
