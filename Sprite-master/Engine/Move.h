#pragma once

class Move {
public:
	void CheckStatus(int xReferral, int yReferral);
	void Activate(bool isFacingRight, int xReferral, int yReferral, int additionalXReferral, int additionalYReferral, int widthReferral, int heightReferral, float stunDurationReferral, float scalarXReferral, float scalarYReferral, float fixedXReferral, float fixedYReferral, float vxReferral, float vyReferral, float damageReferral, float startUpDurationReferral, float activeDurationReferral, float endLagDurationReferral, bool isAttachedToPlayerReferral, bool dissapearOnHitReferral);
	bool Draw();
	void EndMove();
	bool IsMoveColliding(int Player2x, int Player2y, int Player2width, int Player2height);
	void PlayerIsHit();
	int IsActiveDuration();
	bool hasHit = false;
	int x, y, additionalX, additionalY, width, height, stunDuration, scalarX, scalarY, fixedX, fixedY, vx, vy, damage, startUpDuration, endLagDuration = 0;
	 
	int activeDuration = 0;
	int playerWidth = 100;

private:
	bool isAttachedToPlayer=true;
	bool dissapearOnHit = false;
};