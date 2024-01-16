#include "Platform.h"

Platform::Platform(int cx0, int cy0, int cx1, int cy1, bool cisSolid, bool cisFilled, int cr, int cg, int cb) {
	x0 = cx0;
	y0 = cy0;
	x1 = cx1;
	y1 = cy1;
	isSolid = cisSolid;
	isFilled = cisFilled;
	r = cr;
	g = cg;
	b = cb;
}

