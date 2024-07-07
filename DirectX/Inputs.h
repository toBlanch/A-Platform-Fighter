#pragma once

struct Inputs {
	//enum class horizontalEnum{none, left, right};
	//enum verticalEnum{none, up, down};
	//enum actionEnum{none, jump, light, heavy, special, dodge};

	//horizontalEnum horizontal = static_cast<horizontalEnum>(0);
	//verticalEnum vertical = 0;
	//actionEnum action = 0;

	bool left = false;
	bool right = false;
	bool up = false;
	bool down = false;
	bool jump = false;
	bool light = false;
	bool heavy = false;
	bool special = false;
	bool dodge = false;

	Inputs(bool rleft = false, bool rright = false, bool rup = false, bool rdown = false, bool rjump = false, bool rlight = false, bool rheavy = false, bool rspecial = false, bool rdodge = false) {
		left = rleft;
		right = rright;
		up = rup;
		down = rdown;
		jump = rjump;
		light = rlight;
		heavy = rheavy;
		special = rspecial;
		dodge = rdodge;
	}
};

enum singleInput{leftInput, rightInput, upInput, downInput,jumpInput,lightInput,heavyInput,specialInput,dodgeInput};

struct InputChange {
	singleInput input = leftInput;
	int frame = 0;
	InputChange(singleInput rInput, int rFrame) {
		input = rInput;
		frame = rFrame;
	}
};