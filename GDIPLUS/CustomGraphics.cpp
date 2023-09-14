#include "CustomGraphics.h"
#include <windows.h>
#include <objidl.h>
#include <gdiplus.h>
using namespace Gdiplus;
#pragma comment (lib,"Gdiplus.lib")
#include <string>

CustomGraphics::CustomGraphics(HDC& hdc)
    :
    graphics(hdc),
    brush(Color(255, 0, 0, 255)),
    fontFamily(L"Times New Roman")
{
}

void CustomGraphics::PassClientDimensions(int x, int y)
{
    clientX = x;
    clientY = y;
}

void CustomGraphics::DrawRect(int x0, int y0, int x1, int y1, int r, int g, int b)
{
    Pen rectColor(Color(r, g, b, 255), 1);
    RectF rectDimensions(clientX / 1920 * x0, clientY / 1080 * y0, clientX / 1920 * (x1 - x0), clientY / 1080 * (y1 - y0));
    graphics.DrawRectangle(&rectColor, rectDimensions);
}

void CustomGraphics::DrawText(float x, float y, std::wstring text)
{
    PointF      pointF(clientX / 1920 * x, clientY / 1080 * y);
    Font font(&fontFamily, clientX / 1920 * 24, FontStyleRegular, UnitPixel);
    graphics.DrawString(text.c_str(), -1, &font, pointF, &brush);
}

void CustomGraphics::DrawSprite(float x, float y, Image& image, bool flip)
{
    if(flip){
        Point destinationPoints[] = {
            Point(clientX / 1920 * (x + image.GetWidth()), clientY / 1080 * (y)), //Upper left
            Point(clientX / 1920 * (x), clientY / 1080 * (y)), //Upper right
            Point(clientX / 1920 * (x + image.GetWidth()), clientY / 1080 * (y + image.GetHeight())) //Lower left
        };
        graphics.DrawImage(&image, destinationPoints, 3);
    }
    else {
        Point destinationPoints[] = {
            Point(clientX / 1920 * (x), clientY / 1080 * (y)), //Upper left
            Point(clientX / 1920 * (x + image.GetWidth()), clientY / 1080 * (y)), //Upper right
            Point(clientX / 1920 * (x), clientY / 1080 * (y + image.GetHeight())) //Lower left
        };
        graphics.DrawImage(&image, destinationPoints, 3);
    }
}

void CustomGraphics::Clear()
{
    graphics.Clear(Color(255, 255, 255, 255));
}
