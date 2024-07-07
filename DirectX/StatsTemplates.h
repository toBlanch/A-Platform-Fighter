#pragma once
struct MoveTemplate {
	int additionalXRight = 0;
	int additionalY = 0;
	int width = 0;
	int height = 0;
	int stunDuration = 0;
	float scalarX = 0;
	float scalarY = 0;
	float fixedX = 0;
	float fixedY = 0;
	float initialVx = 0;
	float initialVy = 0;
	float accelerationX = 0;
	float accelerationY = 0;
	float damage = 0;
	int initialStartUpDuration = 0;
	int initialActiveDuration = 0;
	int initialEndLagDuration = 0;
	bool isAttachedToPlayer = true;
	bool isPlayerAttachedToIt = false;
	bool disappearOnHit = false;
	int r = 0;
	int g = 0;
	int b = 0;

	MoveTemplate(int rAdditionalXRight = 0,int rAdditionalY = 0,int rWidth = 0,int rHeight = 0,int rStunDuration = 0, float rScalarX = 0,float rScalarY = 0,float rFixedX = 0,float rFixedY = 0,float rInitialVx = 0, float rInitialVy = 0, float rAccelerationX = 0,float rAccelerationY = 0,float rDamage = 0,int rInitialStartUpDuration = 0,int rInitialActiveDuration = 0,int rInitialEndLagDuration = 0,bool rIsAttachedToPlayer = 0,bool rIsPlayerAttachedToIt = 0,bool rDisappearOnHit = 0, int rR = 255, int rG = 255, int rB = 255){
		additionalXRight = rAdditionalXRight;
		additionalY = rAdditionalY;
		width = rWidth;
		height = rHeight;
		stunDuration = rInitialStartUpDuration;
		scalarX = rScalarX;
		scalarY = rScalarY;
		fixedX = rFixedX;
		fixedY = rFixedY;
		initialVx = rInitialVx;
		initialVy = rInitialVy;
		accelerationX = rAccelerationX;
		accelerationY = rAccelerationY;
		damage = rDamage;
		initialStartUpDuration = rInitialStartUpDuration;
		initialActiveDuration = rInitialActiveDuration;
		initialEndLagDuration = rInitialEndLagDuration;
		isAttachedToPlayer = rIsAttachedToPlayer;
		disappearOnHit = rDisappearOnHit;
		r = rR;
		g = rG;
		b = rB;
	}
};