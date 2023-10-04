#pragma once

class AI {
public:
	void Update(int player2x, int player2y, int player2Width, int player2Height, int x, int y, int width, int height, bool canDodge, int vy, int doubleJump, int stageX0, int stageY0, int stageX1, int stageY1, float moveType, int opponentPercent);
	bool left = false;
	bool right = false;
	bool down = false;
	bool up = false;
	bool jump = false;
	bool light = false;
	bool heavy = false;
	bool special = false;
	bool dodge = false;
private:
	void Recover(int x, int y, int width, int vy, bool canDodge, int doubleJump, int stageX0, int stageY0, int stageX1, int stageY1);
	bool ShouldUseMove(int player2x, int player2y, int player2Width, int player2Height, int x, int y, int width, int height, int doubleJump, float moveType, int stageX0, int stageY0, int stageX1, int stageY1, int opponentPercent);
	void GeneralMovement(int player2x, int player2y, int x, int y, int vy, int doubleJump, float moveType);
};