#pragma once

class Move {
public:
	void CheckStatus(int xReferral, int yReferral);
	bool IsAvailable();
	int StartUp(int move);
	int Duration(int move);
	int EndLag(int move);
	void Activate(int xReferral, int yReferral, bool isAttachedToPlayerReferral);
	bool Draw();
	void EndMove();
	bool IsMoveColliding(int Player2x, int Player2y, int Player2width, int Player2height);
	int x=0;
	int y=0;
	int width=0;
	int height=0;
	int stunDuration=0;
	int scalarX=0;
	int scalarY=0;
	int fixedX=0;
	int fixedY=0;
	int damage=0;
private:
	int startUpDuration=0;
	int activeDuration=0;
	bool isPlayer1 = true;
	bool isAttachedToPlayer=0;
};