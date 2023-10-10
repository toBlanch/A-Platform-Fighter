#pragma once

class Move {
public:
	void CheckStatus(float xReferral, float yReferral, int stageX0, int stageY0, int stageX1, int stageY1);
	void Activate(int playerWidthReferral, int playerHeightReferral, bool isFacingRight, int additionalXReferral, int additionalYReferral, int widthReferral, int heightReferral, float stunDurationReferral, float scalarXReferral, float scalarYReferral, float fixedXReferral, float fixedYReferral, float vxReferral, float vyReferral, float accelerationxReferral, float accelerationyReferral, float damageReferral, float startUpDurationReferral, float activeDurationReferral, float endLagDurationReferral, bool isAttachedToPlayerReferral, bool isPlayerAttachedToItReferral, bool disappearOnHitReferral, int rReferral, int gReferral, int bReferral);
	bool Draw();
	void EndMove();
	bool IsMoveColliding(float Player2x, float Player2y, int Player2width, int Player2height);
	void PlayerIsHit();
	int IsActiveDuration();
	int x = 0;
	int y = 0;
	int additionalX = 0;
	int additionalY = 0;
	int width = 0;
	int height = 0;
	int startUpDuration = 0;
	int endLagDuration = 0;
	float stunDuration = 0;
	float scalarX = 0;
	float scalarY = 0;
	float fixedX = 0;
	float fixedY = 0;
	float vx = 0;
	float vy = 0;
	float accelerationx = 0;
	float accelerationy = 0;
	float damage = 0;

	int activeDuration = 0;
	bool hasHit = false;
	bool isAttachedToPlayer = true;
	bool isPlayerAttachedToIt = false;
	bool disappearOnHit = false;

	int r = 0;
	int g = 0;
	int b = 0;
};