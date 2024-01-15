#pragma once
#include "Platform.h"
#include <windows.h>

class Stage
{
public:
	Stage(Platform cPlatforms[10], LPCSTR cLoadMusic) {
		for (int i = 0; i < 10; i++) {
			Platforms[i] = cPlatforms[i];
		}
		loadMusic = cLoadMusic;
	};
	Platform Platforms[10] = {
		Platform(0,0,0,0,false,false,0,0,0),
		Platform(0,0,0,0,false,false,0,0,0),
		Platform(0,0,0,0,false,false,0,0,0),
		Platform(0,0,0,0,false,false,0,0,0),
		Platform(0,0,0,0,false,false,0,0,0),
		Platform(0,0,0,0,false,false,0,0,0),
		Platform(0,0,0,0,false,false,0,0,0),
		Platform(0,0,0,0,false,false,0,0,0),
		Platform(0,0,0,0,false,false,0,0,0),
		Platform(0,0,0,0,false,false,0,0,0)
	};
	LPCSTR loadMusic = "open \"Battle Theme 0.wav\" type mpegvideo alias BattleTheme";
};