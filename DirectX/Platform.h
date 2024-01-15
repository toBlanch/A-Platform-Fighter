#pragma once

class Platform
{
public:
	int x0 = 0;
	int y0 = 0;
	int x1 = 0;
	int y1 = 0;
	bool isSolid = false;
	bool isFilled = false;
	int r = 0;
	int g = 0;
	int b = 0;
	Platform(int cx0, int cy0, int cx1, int cy1, bool cisSolid, bool cisFilled, int cr, int cg, int cb) {
		x0 = cx0;
		y0 = cy0;
		x1 = cx1;
		y1 = cy1;
		isSolid=cisSolid;
		isFilled = cisFilled;
		r=cr;
		g=cg;
		b=cb;
	}
private:
	//No functions so don't put anything here
};