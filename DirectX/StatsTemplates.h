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

	MoveTemplate(int rAdditionalXRight = 0, int rAdditionalY = 0, int rWidth = 0, int rHeight = 0, int rStunDuration = 0, float rScalarX = 0, float rScalarY = 0, float rFixedX = 0, float rFixedY = 0, float rInitialVx = 0, float rInitialVy = 0, float rAccelerationX = 0, float rAccelerationY = 0, float rDamage = 0, int rInitialStartUpDuration = 0, int rInitialActiveDuration = 0, int rInitialEndLagDuration = 0, bool rIsAttachedToPlayer = 0, bool rIsPlayerAttachedToIt = 0, bool rDisappearOnHit = 0, int rR = 255, int rG = 255, int rB = 255) {
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
		isPlayerAttachedToIt = rIsPlayerAttachedToIt;
		disappearOnHit = rDisappearOnHit;
		r = rR;
		g = rG;
		b = rB;
	}
};

struct CharacterTemplate {
	int width = 100;
	int height = 100;
	float maxWalkSpeed = 0;
	float maxAerialSpeed = 0;
	float walkAcceleration = 0;
	float aerialAcceleration = 0;
	float groundJumpHeight = 0;
	float aerialJumpHeight = 0;
	float fallAcceleration = 0;
	float maxFallSpeed = 0;
	float weight = 0;
	int maxDoubleJump = 0;

	MoveTemplate forwardLight;
	MoveTemplate upLight;
	MoveTemplate downLight;
	MoveTemplate forwardHeavy;
	MoveTemplate upHeavy;
	MoveTemplate downHeavy;
	MoveTemplate forwardAerial;
	MoveTemplate backAerial;
	MoveTemplate upAerial;
	MoveTemplate downAerial;
	MoveTemplate forwardSpecial;
	MoveTemplate upSpecial;
	MoveTemplate downSpecial;

	CharacterTemplate(int rWidth = 0, int rHeight = 0, float rMaxWalkSpeed = 0, float rMaxAerialSpeed = 0, float rMaxAerialAcceleration = 0, float rMaxWalkAcceleration = 0, float rGroundJumpHeight = 0, float rAerialJumpHeight = 0, float rFallAcceleration = 0, float rMaxFallSpeed = 0, float rWeight = 0, int rMaxDoubleJump = 0, MoveTemplate rForwardLight = 0, MoveTemplate rUpLight = 0, MoveTemplate rDownLight = 0, MoveTemplate rForwardHeavy = 0, MoveTemplate rUpHeavy = 0, MoveTemplate rDownHeavy = 0, MoveTemplate rForwardAerial = 0, MoveTemplate rBackAerial = 0, MoveTemplate rUpAerial = 0, MoveTemplate rDownAerial = 0, MoveTemplate rForwardSpecial = 0, MoveTemplate rUpSpecial = 0, MoveTemplate rDownSpecial = 0) {
		width = rWidth;
		height = rHeight;
		maxWalkSpeed = rMaxWalkSpeed;
		maxAerialSpeed = rMaxAerialSpeed;
		walkAcceleration = rMaxWalkAcceleration;
		aerialAcceleration = rMaxAerialAcceleration;
		groundJumpHeight = rGroundJumpHeight;
		aerialJumpHeight = rAerialJumpHeight;
		fallAcceleration = rFallAcceleration;
		maxFallSpeed = rMaxFallSpeed;
		weight = rWeight;
		maxDoubleJump = rMaxDoubleJump;

		forwardLight = rForwardLight;
		upLight = rUpLight;
		downLight = rDownLight;
		forwardHeavy = rForwardHeavy;
		upHeavy = rUpHeavy;
		downHeavy = rDownHeavy;
		forwardAerial = rForwardAerial;
		backAerial = rBackAerial;
		upAerial = rUpAerial;
		downAerial = rDownAerial;
		forwardSpecial = rForwardSpecial;
		upSpecial = rUpSpecial;
		downSpecial = rDownSpecial;
	}
};