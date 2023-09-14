#pragma once

#include <wincodec.h>
#include "Graphics.h"

class SpriteSheet
{
	Graphics* gfx;
	ID2D1Bitmap* bmp;
	ID2D1Bitmap* bmpFlip;
public:
	SpriteSheet(LPCWSTR filename, Graphics* graphics);
	~SpriteSheet();

	void Draw(int x0, int y0, bool flip);
};