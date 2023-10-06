#include "Graphics.h"
#include <d2d1.h>
#include "SpriteSheet.h"
#include <Winuser.h>

Graphics::Graphics()
{
	factory = NULL;
	renderTarget = NULL;
	brush = NULL;
}

Graphics::~Graphics()
{
	if (factory) factory->Release();
	if (renderTarget) renderTarget->Release();
	if (brush) brush->Release();
}

bool Graphics::Init(HWND hwndReferral)
{
	hwnd = hwndReferral;
	HRESULT res = D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &factory);
	if (res != S_OK) return false;

	res = factory->CreateHwndRenderTarget(
		D2D1::RenderTargetProperties(),
		D2D1::HwndRenderTargetProperties(hwnd, D2D1::SizeU(1920, 1080)), //Initialised to scale 1920*1080
		&renderTarget
	);

	if (res != S_OK) return false;

	res = renderTarget->CreateSolidColorBrush(D2D1::ColorF(0, 0, 0, 1.0), &brush);

	if (res != S_OK) return false;
	return true;
}

ID2D1RenderTarget* Graphics::GetRenderTarget()
{
	return renderTarget;
}

void Graphics::BeginDraw()
{
	renderTarget->BeginDraw();
}

void Graphics::EndDraw()
{
	renderTarget->EndDraw();
}

void Graphics::ClearScreen(float r, float g, float b)
{
	renderTarget->Clear(D2D1::ColorF(r, g, b));
}

void Graphics::DrawCircle(float x, float y, float radius, float r, float g, float b, float a)
{
	brush->SetColor(D2D1::ColorF(r,g,b,a));

	renderTarget->DrawEllipse(D2D1::Ellipse(D2D1::Point2F(x, y), radius, radius), brush, 3.0f);
	
	//brush->Release();
}

void Graphics::DrawRectThin(float x0, float y0, float x1, float y1, float r, float g, float b, float a)
{
	brush->SetColor(D2D1::ColorF(r, g, b, a));

	renderTarget->DrawRectangle(D2D1::RectF(x0, y0, x1, y1), brush);
}

void Graphics::DrawRectFill(float x0, float y0, float x1, float y1, float r, float g, float b, float a)
{
	brush->SetColor(D2D1::ColorF(r/255, g/255, b/255, a));

	renderTarget->FillRectangle(D2D1::RectF(x0, y0, x1, y1), brush);
}

void Graphics::Fullscreen()
{
	if (fullscreen) {
		fullscreen = false;
		MoveWindow(hwnd, clientRect.left, clientRect.top, clientRect.right-clientRect.left, clientRect.bottom-clientRect.top, false);
		SetWindowLongPtr(hwnd, GWL_STYLE, WS_VISIBLE | WS_OVERLAPPEDWINDOW);
	}
	else {
		fullscreen = true;
		GetWindowRect(hwnd, &clientRect);

		SetWindowLongPtr(hwnd, GWL_STYLE, WS_VISIBLE | WS_POPUP);
		SetWindowPos(hwnd, HWND_TOP, 0, 0, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN), SWP_FRAMECHANGED);
	}
}

bool Graphics::ifFocus()
{
	return hwnd == GetFocus();
}

void Graphics::GetClickPosition(POINT* clickPosition)
{
	GetCursorPos(clickPosition);
	ScreenToClient(hwnd, clickPosition);
	RECT currentRect;
	GetWindowRect(hwnd, &currentRect);
	RECT clientRect;
	GetClientRect(hwnd, &clientRect);
	currentRect.top = currentRect.bottom - clientRect.bottom;

	clickPosition->x = clickPosition->x * 1920 / (clientRect.right);
	clickPosition->y = clickPosition->y * 1080 / (clientRect.bottom);
}
