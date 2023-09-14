#include <Windows.h>
#include "Graphics.h"
#include "Game.h"
#include <chrono>

Graphics* gfx;

LRESULT CALLBACK Wndproc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	if (uMsg == WM_DESTROY) {
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProcW(hwnd, uMsg, wParam, lParam);
}


int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE prevInstance, LPWSTR cmd, int nCmdShow) {
	WNDCLASSEX windowclass;
	ZeroMemory(&windowclass, sizeof(WNDCLASSEX));
	windowclass.cbSize = sizeof(WNDCLASSEX);
	windowclass.hbrBackground = (HBRUSH)COLOR_WINDOW;
	windowclass.hInstance = hInstance;
	windowclass.lpfnWndProc = Wndproc;
	windowclass.lpszClassName = L"MainWindow";
	windowclass.style = CS_HREDRAW | CS_VREDRAW;

	RegisterClassExW(&windowclass);

	HWND hwnd = CreateWindowEx(
		WS_EX_OVERLAPPEDWINDOW,
		L"MainWindow", //Class Name
		L"Awesome Fighter", //Window Name
		WS_OVERLAPPEDWINDOW, //Dw Style
		CW_USEDEFAULT, //x 
		CW_USEDEFAULT,  //y
		CW_USEDEFAULT, //Width
		CW_USEDEFAULT, //Height
		NULL, //Parent
		NULL, //Menu
		hInstance, //hInst
		NULL //Param
	);

	if (!hwnd) { //If the window won't display
		return -1; //Exit the program
	}

	gfx = new Graphics;

	if (!gfx->Init(hwnd)) { //If initialising graphics failed
		delete gfx;
		return -1; //Exit the program
	}

	

	ShowWindow(hwnd, nCmdShow); //Display the window

	MSG msg; //Get messages

    //Setup timer
	typedef std::chrono::high_resolution_clock hiresclock;

	//Initialise game
	Game game(gfx);

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
		else {
			//Handles clock
			static auto timer = hiresclock::now();
			auto milisec = (hiresclock::now() - timer).count() / 1000000;

			if (milisec > 1.0f / 60.0f * 1000)
			{
				//Manages timer
				timer = hiresclock::now();

				//Run game loop
				game.Go();
			}
		}
	}
	delete gfx;

	return 0;
}