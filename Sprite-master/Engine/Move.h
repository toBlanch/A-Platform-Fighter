#pragma once

class Move {
public:
	void CheckStatus(int xReferral, int yReferral);
	void Activate(int xReferral, int yReferral, int moveID, bool isFacingRight);
	bool Draw();
	void EndMove();
	bool IsMoveColliding(int Player2x, int Player2y, int Player2width, int Player2height);
	void PlayerIsHit();
	bool hasHit = false;
	int x=0;
	int y=0;
	int additionalX = 0;
	int additionalY = 0;
	int width=0;
	int height=0;
	int stunDuration=0;
	int scalarX=0;
	int scalarY=0;
	int fixedX=0;
	int fixedY=0;
	int vx = 0;
	int vy = 0;
	int damage=0;
	int startUpDuration = 0;
	int activeDuration = 0;
	int endLagDuration = 0;
	int playerWidth = 100;
private:
	bool isAttachedToPlayer=true;
};