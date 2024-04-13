#pragma once

#include <Windows.h>
#include <d2d1.h>
#include <dwrite.h>
#include <wincodec.h>
using namespace std;

class Graphics {
	ID2D1Factory* factory;
	ID2D1HwndRenderTarget* renderTarget;
	ID2D1SolidColorBrush* brush;
	IDWriteFactory* pDWriteFactory_;
	HWND hwnd;
	RECT clientRect;
	bool fullscreen = false;
public:
	Graphics();
	~Graphics();

	bool Init(HWND hwndReferral);

	ID2D1RenderTarget* GetRenderTarget();

	void BeginDraw();
	void EndDraw();

	void ClearScreen(float r, float g, float b);
	void DrawCircle(float x, float y, float Radius, float r, float g, float b, float a);
	void DrawRectThin(float x0, float y0, float x1, float y1, float r, float g, float b, float a);
	void DrawRectFill(float x0, float y0, float x1, float y1, float r, float g, float b, float a);
	void Fullscreen();
	bool ifFocus();
	void GetClickPosition(POINT* clickPosition);
	IDWriteTextFormat* CreateTextFormat(LPCWSTR fontFamily, float fontSize);
	void DrawText(LPCWSTR text, IDWriteTextFormat* pTextFormat_, int x0, int y0, int r, int g, int b, int a);
};