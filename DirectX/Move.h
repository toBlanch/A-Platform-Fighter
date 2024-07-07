#pragma once
#include "Platform.h"
#include "StatsTemplates.h"

class Move {
public:
	void CheckStatus(float xReferral, float yReferral, Platform Platforms[10]);
	void Activate(int playerWidthReferral, bool isFacingRight, MoveTemplate rStats);
	void EndMove();
	void PlayerIsHit();
	int IsActiveDuration();

	int x = 0;
	int y = 0;
	bool isFacingRight = false;
	bool hasHit = false;

	MoveTemplate stats;
	int additionalX = 0;
	int vx = 0;
	int vy = 0;
	int startUpDuration = 0;
	int activeDuration = 0;
	int endLagDuration = 0;
};