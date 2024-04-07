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

	Inputs(bool rleft, bool rright, bool rup, bool rdown, bool rjump, bool rlight, bool rheavy, bool rspecial, bool rdodge) {
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