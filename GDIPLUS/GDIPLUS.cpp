#include <windows.h>
#include <objidl.h>
#include <gdiplus.h>
using namespace Gdiplus;
#pragma comment (lib,"Gdiplus.lib")
#include <chrono>
#include <string>
#include "Game.h"

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, PSTR, INT iCmdShow)
{
    HWND                hWnd;
    MSG                 msg;
    WNDCLASS            wndClass;
    GdiplusStartupInput gdiplusStartupInput;
    ULONG_PTR           gdiplusToken;

    // Initialize GDI+.
    GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

    wndClass.style = CS_HREDRAW | CS_VREDRAW;
    wndClass.lpfnWndProc = WndProc;
    wndClass.cbClsExtra = 0;
    wndClass.cbWndExtra = 0;
    wndClass.hInstance = hInstance;
    wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    wndClass.lpszMenuName = NULL;
    wndClass.lpszClassName = TEXT("Awesome Platform Fighter");

    RegisterClass(&wndClass);

    hWnd = CreateWindow(
        TEXT("Awesome Platform Fighter"),   // window class name
        TEXT("Awesome Platform Fighter"),  // window caption
        WS_OVERLAPPEDWINDOW,      // window style
        CW_USEDEFAULT,            // initial x position
        CW_USEDEFAULT,            // initial y position
        CW_USEDEFAULT,            // initial x size
        CW_USEDEFAULT,            // initial y size
        NULL,                     // parent window handle
        NULL,                     // window menu handle
        hInstance,                // program instance handle
        NULL);                    // creation parameters
    ShowWindow(hWnd, iCmdShow);
    UpdateWindow(hWnd);

    //Setup timer
    std::string previousTime = std::to_string(time(NULL));
    typedef std::chrono::high_resolution_clock hiresclock;

    //Get the client's dimensinos
    RECT rc;
    GetClientRect(hWnd, &rc);

    //Temporarily set the client window to the maximum, this allows the maximum resolution to be used if fullscreened
    RECT desktop;
    const HWND hDesktop = GetDesktopWindow();
    // Set the size of the screen to the variable desktop
    GetWindowRect(hDesktop, &desktop);
    MoveWindow(hWnd, 0, 0, desktop.right, desktop.bottom, false);

    //Initialise with the client window at maximum
    PAINTSTRUCT ps;
    HDC hdc = BeginPaint(hWnd, &ps);
    Game game(hdc);

    //Return the client window to normal
    MoveWindow(hWnd, rc.left, rc.top, rc.right-rc.left, rc.bottom-rc.top, false);

    //Temporary code for FPS
    int frames = 0;
    int fps = 0;


    while (true)
    {
        //Handles client messages
        if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
        {
            if (msg.message == WM_QUIT) //<=== **** EDITED **** 
                break;
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }

        //Handles clock
        static auto timer = hiresclock::now();
        auto milisec = (hiresclock::now() - timer).count() / 1000000;

        if (milisec > 16.666666667)
        {
            //Manages timer
            timer = hiresclock::now();
            //Get client dimensions for Graphics
            GetClientRect(hWnd, &rc);
            //Main loop
            game.Go(rc.right, rc.bottom);


            frames++;
            if (previousTime != std::to_string(time(NULL))) {
                previousTime = std::to_string(time(NULL));
                fps = frames;
                frames = 0;
            }

            //FPS code
            TextOutA(hdc, 0, 0, "FPS:", 4);
            TextOutA(hdc, 30, 0, std::to_string(fps).c_str(), 3);
        }
    }
    EndPaint(hWnd, &ps);
    PostQuitMessage(0);
    GdiplusShutdown(gdiplusToken);
    return msg.wParam;
}  // WinMain

LRESULT CALLBACK WndProc(HWND hWnd, UINT message,
    WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_PAINT:
        return 0;
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
} // WndProc
