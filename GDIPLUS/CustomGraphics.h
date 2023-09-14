#pragma once

#include <windows.h>
#include <objidl.h>
#include <gdiplus.h>
using namespace Gdiplus;
#pragma comment (lib,"Gdiplus.lib")
#include <string>

class CustomGraphics
{
public:
	CustomGraphics(HDC& hdc);
	void PassClientDimensions(int x, int y);
	void DrawRect(int x0, int y0, int x1, int y1, int r, int g ,int b);
	void DrawText(float x, float y, std::wstring text);
	void DrawSprite(float x, float y, Image& image, bool flip);
	void Clear();
	Graphics graphics;
	SolidBrush  brush;
	FontFamily  fontFamily;
	float clientX = 1920;
	float clientY = 1080;
};