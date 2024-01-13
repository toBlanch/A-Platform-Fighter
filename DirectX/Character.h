#pragma once
#include "Move.h"
#include <vector>

class Character {
public:
	void UpdateCharacter(bool left, bool right, bool up, bool down, bool jump, bool light, bool heavy, bool special, bool dodge, int stageX0, int stageY0, int stageX1, int stageY1);
	bool IsOnStage(int stageX0, int stageY0, int stageX1, int stageY1);
	bool ClippingIntoStageFromLeft(int stageX0, int stageY0, int stageX1, int stageY1);
	bool ClippingIntoStageFromRight(int stageX0, int stageY0, int stageX1, int stageY1);
	bool ClippingIntoStageFromBottom(int stageX0, int stageY0, int stageX1, int stageY1);
	bool IsAlive(int screenWidth, int screenHeight, int leniancy);
	bool MoveDraw(int move);
	bool IsMoveColliding(float player2x, float player2y, int Player2Width, int Player2Height);
	int MoveX0(int move);
	int MoveY0(int move);
	int MoveX1(int move);
	int MoveY1(int move);
	int MoveR(int move);
	int MoveG(int move);
	int MoveB(int move);
	int MoveThatHitStun();
	float MoveThatHitDamage();
	float MoveThatHitScalarX();
	float MoveThatHitScalarY();
	float MoveThatHitFixedX();
	float MoveThatHitFixedY();
	void Initialise(std::vector<float>& parameters, int stageX0Referral, int stageY0Referral, int stageX1Referral, int stageY1Referral);
	void IsHit(int stunReferral, float damageReferral, int fixedXReferral, int fixedYReferral, int scalarXReferral, int scalarYReferral);
	void Restart();
	void OnlyProjectiles(int stageX0, int stageY0, int stageX1, int stageY1);
	int lives = 3;
	float x = 0;
	float y = 0;
	int width = 100;
	int height = 100;
	int moveDuration = 0;
	float playerPercentage = 0;
	int stun = 0;
	bool facingRight = true;
	int invincibility = 0;
	int freeFallDuration = 0;
	int invincibilityCooldown = 0;
	float vx = 0;
	float vy = 0;
	float speed = 0;
	float acceleration = 0;
	int doubleJump = 0;
	int moveArrayLength = 0;
	bool easyMode = false;
private:
	float walkSpeed = 0;
	float aerialSpeed = 0;
	float walkAcceleration = 0;
	float aerialAcceleration = 0;
	float groundJumpHeight = 0;
	float aerialJumpHeight = 0;
	float fallAcceleration = 0;
	float fallSpeed = 0;
	float weight = 0;
	int maxDoubleJump = 0;
	int moveThatHit = 0;
	bool onStage = false;
	bool jumpKeyHeld = false;
	bool fastFalling = false;
	bool downHeld = false;
	bool groundTouchedAfterDodging = false;
	bool rightHeld = false;
	bool rightPriority = false;
	Move moveArray[5];

	int forwardLightAdditionalX = 0;
	int forwardLightAdditionalY = 0;
	int forwardLightWidth = 0;
	int forwardLightHeight = 0;
	float forwardLightStunDuration = 0;
	float forwardLightScalarX = 0;
	float forwardLightScalarY = 0;
	float forwardLightFixedX = 0;
	float forwardLightFixedY = 0;
	float forwardLightVx = 0;
	float forwardLightVy = 0;
	float forwardLightAccelerationx = 0;
	float forwardLightAccelerationy = 0;
	float forwardLightDamage = 0;
	int forwardLightStartUpDuration = 0;
	int forwardLightActiveDuration = 0;
	int forwardLightEndLagDuration = 0;
	bool forwardLightIsAttachedToPlayer = false;
	bool forwardLightIsPlayerAttachedToIt = false;
	bool forwardLightDisappearOnHit = false;

	int upLightAdditionalX = 0;
	int upLightAdditionalY = 0;
	int upLightWidth = 0;
	int upLightHeight = 0;
	float upLightStunDuration = 0;
	float upLightScalarX = 0;
	float upLightScalarY = 0;
	float upLightFixedX = 0;
	float upLightFixedY = 0;
	float upLightVx = 0;
	float upLightVy = 0;
	float upLightAccelerationx = 0;
	float upLightAccelerationy = 0;
	float upLightDamage = 0;
	int upLightStartUpDuration = 0;
	int upLightActiveDuration = 0;
	int upLightEndLagDuration = 0;
	bool upLightIsAttachedToPlayer = false;
	bool upLightIsPlayerAttachedToIt = false;
	bool upLightDisappearOnHit = false;

	int downLightAdditionalX = 0;
	int downLightAdditionalY = 0;
	int downLightWidth = 0;
	int downLightHeight = 0;
	float downLightStunDuration = 0;
	float downLightScalarX = 0;
	float downLightScalarY = 0;
	float downLightFixedX = 0;
	float downLightFixedY = 0;
	float downLightVx = 0;
	float downLightVy = 0;
	float downLightAccelerationx = 0;
	float downLightAccelerationy = 0;
	float downLightDamage = 0;
	int downLightStartUpDuration = 0;
	int downLightActiveDuration = 0;
	int downLightEndLagDuration = 0;
	bool downLightIsAttachedToPlayer = false;
	bool downLightIsPlayerAttachedToIt = false;
	bool downLightDisappearOnHit = false;

	int forwardHeavyAdditionalX = 0;
	int forwardHeavyAdditionalY = 0;
	int forwardHeavyWidth = 0;
	int forwardHeavyHeight = 0;
	float forwardHeavyStunDuration = 0;
	float forwardHeavyScalarX = 0;
	float forwardHeavyScalarY = 0;
	float forwardHeavyFixedX = 0;
	float forwardHeavyFixedY = 0;
	float forwardHeavyVx = 0;
	float forwardHeavyVy = 0;
	float forwardHeavyAccelerationx = 0;
	float forwardHeavyAccelerationy = 0;
	float forwardHeavyDamage = 0;
	int forwardHeavyStartUpDuration = 0;
	int forwardHeavyActiveDuration = 0;
	int forwardHeavyEndLagDuration = 0;
	bool forwardHeavyIsAttachedToPlayer = false;
	bool forwardHeavyIsPlayerAttachedToIt = false;
	bool forwardHeavyDisappearOnHit = false;

	int upHeavyAdditionalX = 0;
	int upHeavyAdditionalY = 0;
	int upHeavyWidth = 0;
	int upHeavyHeight = 0;
	float upHeavyStunDuration = 0;
	float upHeavyScalarX = 0;
	float upHeavyScalarY = 0;
	float upHeavyFixedX = 0;
	float upHeavyFixedY = 0;
	float upHeavyVx = 0;
	float upHeavyVy = 0;
	float upHeavyAccelerationx = 0;
	float upHeavyAccelerationy = 0;
	float upHeavyDamage = 0;
	int upHeavyStartUpDuration = 0;
	int upHeavyActiveDuration = 0;
	int upHeavyEndLagDuration = 0;
	bool upHeavyIsAttachedToPlayer = false;
	bool upHeavyIsPlayerAttachedToIt = false;
	bool upHeavyDisappearOnHit = false;

	int downHeavyAdditionalX = 0;
	int downHeavyAdditionalY = 0;
	int downHeavyWidth = 0;
	int downHeavyHeight = 0;
	float downHeavyStunDuration = 0;
	float downHeavyScalarX = 0;
	float downHeavyScalarY = 0;
	float downHeavyFixedX = 0;
	float downHeavyFixedY = 0;
	float downHeavyVx = 0;
	float downHeavyVy = 0;
	float downHeavyAccelerationx = 0;
	float downHeavyAccelerationy = 0;
	float downHeavyDamage = 0;
	int downHeavyStartUpDuration = 0;
	int downHeavyActiveDuration = 0;
	int downHeavyEndLagDuration = 0;
	bool downHeavyIsAttachedToPlayer = false;
	bool downHeavyIsPlayerAttachedToIt = false;
	bool downHeavyDisappearOnHit = false;

	int forwardAerialAdditionalX = 0;
	int forwardAerialAdditionalY = 0;
	int forwardAerialWidth = 0;
	int forwardAerialHeight = 0;
	float forwardAerialStunDuration = 0;
	float forwardAerialScalarX = 0;
	float forwardAerialScalarY = 0;
	float forwardAerialFixedX = 0;
	float forwardAerialFixedY = 0;
	float forwardAerialVx = 0;
	float forwardAerialVy = 0;
	float forwardAerialAccelerationx = 0;
	float forwardAerialAccelerationy = 0;
	float forwardAerialDamage = 0;
	int forwardAerialStartUpDuration = 0;
	int forwardAerialActiveDuration = 0;
	int forwardAerialEndLagDuration = 0;
	bool forwardAerialIsAttachedToPlayer = false;
	bool forwardAerialIsPlayerAttachedToIt = false;
	bool forwardAerialDisappearOnHit = false;

	int backAerialAdditionalX = 0;
	int backAerialAdditionalY = 0;
	int backAerialWidth = 0;
	int backAerialHeight = 0;
	float backAerialStunDuration = 0;
	float backAerialScalarX = 0;
	float backAerialScalarY = 0;
	float backAerialFixedX = 0;
	float backAerialFixedY = 0;
	float backAerialVx = 0;
	float backAerialVy = 0;
	float backAerialAccelerationx = 0;
	float backAerialAccelerationy = 0;
	float backAerialDamage = 0;
	int backAerialStartUpDuration = 0;
	int backAerialActiveDuration = 0;
	int backAerialEndLagDuration = 0;
	bool backAerialIsAttachedToPlayer = false;
	bool backAerialIsPlayerAttachedToIt = false;
	bool backAerialDisappearOnHit = false;

	int upAerialAdditionalX = 0;
	int upAerialAdditionalY = 0;
	int upAerialWidth = 0;
	int upAerialHeight = 0;
	float upAerialStunDuration = 0;
	float upAerialScalarX = 0;
	float upAerialScalarY = 0;
	float upAerialFixedX = 0;
	float upAerialFixedY = 0;
	float upAerialVx = 0;
	float upAerialVy = 0;
	float upAerialAccelerationx = 0;
	float upAerialAccelerationy = 0;
	float upAerialDamage = 0;
	int upAerialStartUpDuration = 0;
	int upAerialActiveDuration = 0;
	int upAerialEndLagDuration = 0;
	bool upAerialIsAttachedToPlayer = false;
	bool upAerialIsPlayerAttachedToIt = false;
	bool upAerialDisappearOnHit = false;

	int downAerialAdditionalX = 0;
	int downAerialAdditionalY = 0;
	int downAerialWidth = 0;
	int downAerialHeight = 0;
	float downAerialStunDuration = 0;
	float downAerialScalarX = 0;
	float downAerialScalarY = 0;
	float downAerialFixedX = 0;
	float downAerialFixedY = 0;
	float downAerialVx = 0;
	float downAerialVy = 0;
	float downAerialAccelerationx = 0;
	float downAerialAccelerationy = 0;
	float downAerialDamage = 0;
	int downAerialStartUpDuration = 0;
	int downAerialActiveDuration = 0;
	int downAerialEndLagDuration = 0;
	bool downAerialIsAttachedToPlayer = false;
	bool downAerialIsPlayerAttachedToIt = false;
	bool downAerialDisappearOnHit = false;

	int forwardSpecialAdditionalX = 0;
	int forwardSpecialAdditionalY = 0;
	int forwardSpecialWidth = 0;
	int forwardSpecialHeight = 0;
	float forwardSpecialStunDuration = 0;
	float forwardSpecialScalarX = 0;
	float forwardSpecialScalarY = 0;
	float forwardSpecialFixedX = 0;
	float forwardSpecialFixedY = 0;
	float forwardSpecialVx = 0;
	float forwardSpecialVy = 0;
	float forwardSpecialAccelerationx = 0;
	float forwardSpecialAccelerationy = 0;
	float forwardSpecialDamage = 0;
	int forwardSpecialStartUpDuration = 0;
	int forwardSpecialActiveDuration = 0;
	int forwardSpecialEndLagDuration = 0;
	bool forwardSpecialIsAttachedToPlayer = false;
	bool forwardSpecialIsPlayerAttachedToIt = false;
	bool forwardSpecialDisappearOnHit = false;

	int upSpecialAdditionalX = 0;
	int upSpecialAdditionalY = 0;
	int upSpecialWidth = 0;
	int upSpecialHeight = 0;
	float upSpecialStunDuration = 0;
	float upSpecialScalarX = 0;
	float upSpecialScalarY = 0;
	float upSpecialFixedX = 0;
	float upSpecialFixedY = 0;
	float upSpecialVx = 0;
	float upSpecialVy = 0;
	float upSpecialAccelerationx = 0;
	float upSpecialAccelerationy = 0;
	float upSpecialDamage = 0;
	int upSpecialStartUpDuration = 0;
	int upSpecialActiveDuration = 0;
	int upSpecialEndLagDuration = 0;
	bool upSpecialIsAttachedToPlayer = false;
	bool upSpecialIsPlayerAttachedToIt = false;
	bool upSpecialDisappearOnHit = false;

	int downSpecialAdditionalX = 0;
	int downSpecialAdditionalY = 0;
	int downSpecialWidth = 0;
	int downSpecialHeight = 0;
	float downSpecialStunDuration = 0;
	float downSpecialScalarX = 0;
	float downSpecialScalarY = 0;
	float downSpecialFixedX = 0;
	float downSpecialFixedY = 0;
	float downSpecialVx = 0;
	float downSpecialVy = 0;
	float downSpecialAccelerationx = 0;
	float downSpecialAccelerationy = 0;
	float downSpecialDamage = 0;
	int downSpecialStartUpDuration = 0;
	int downSpecialActiveDuration = 0;
	int downSpecialEndLagDuration = 0;
	bool downSpecialIsAttachedToPlayer = false;
	bool downSpecialIsPlayerAttachedToIt = false;
	bool downSpecialDisappearOnHit = false;

	int forwardLightR = 0;
	int forwardLightG = 0;
	int forwardLightB = 0;
	int upLightR = 0;
	int upLightG = 0;
	int upLightB = 0;
	int downLightR = 0;
	int downLightG = 0;
	int downLightB = 0;
	int forwardHeavyR = 0;
	int forwardHeavyG = 0;
	int forwardHeavyB = 0;
	int upHeavyR = 0;
	int upHeavyG = 0;
	int upHeavyB = 0;
	int downHeavyR = 0;
	int downHeavyG = 0;
	int downHeavyB = 0;
	int forwardAerialR = 0;
	int forwardAerialG = 0;
	int forwardAerialB = 0;
	int backAerialR = 0;
	int backAerialG = 0;
	int backAerialB = 0;
	int upAerialR = 0;
	int upAerialG = 0;
	int upAerialB = 0;
	int downAerialR = 0;
	int downAerialG = 0;
	int downAerialB = 0;
	int forwardSpecialR = 0;
	int forwardSpecialG = 0;
	int forwardSpecialB = 0;
	int upSpecialR = 0;
	int upSpecialG = 0;
	int upSpecialB = 0;
	int downSpecialR = 0;
	int downSpecialG = 0;
	int downSpecialB = 0;
};