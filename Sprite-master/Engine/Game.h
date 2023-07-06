/******************************************************************************************
 *	Chili DirectX Framework Version 16.07.20											  *
 *	Game.h																				  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "Surface.h"
#include "Character.h"
#include "Move.h"
#include <vector>
#include <winnt.h>
#include "Sound.h"
#include "SoundEffect.h"

class Game
{
public:
	Game(class MainWindow& wnd);
	Game(const Game&) = delete;
	Game& operator=(const Game&) = delete;
	void Go();
private:
	void ComposeFrame();
	void GameState();
	/********************************/
	/*  User Functions              */
	/********************************/
	void StartMenu();
	void StartBattleTheme();
	void GameLoop();
	void Restart();

private:
	MainWindow& wnd;
	Graphics gfx;
	/********************************/
	/*  User Variables              */
	std::random_device rd;
	std::mt19937 rng;
	std::uniform_real_distribution<float> musicDist;
	int stageX0 = 480;
	int stageY0 = 700;
	int stageX1 = 1440;
	int stageY1 = 880;
	int leniancy = 0;
	int player1CharacterID = 0;
	int player2CharacterID = 1;
	int previousWinner = 0;
	int timeUntilStart = 0;
	int timeGoIsDisplayed = 0;
	int timer = 0;
	bool credits = false;
	bool startMenu = true;
	bool paused = false;
	bool enterOrEscapeHeld = false;
	bool qHeld = false;
	bool eHeld = false;
	bool iHeld = false;
	bool pHeld = false;
	int hitStun = 0;
	bool mainMenuThemeIsPlaying = false;

	Surface player1Idle = { "Images\\CircleIdle.bmp" };
	Surface player1Move = { "Images\\CircleIdle.bmp" };
	Surface player1Hit = { "Images\\CircleIdle.bmp" };
	Surface player1LivesIcon = { "Images\\CircleLivesIcon.bmp" };

	Surface player2Idle = { "Images\\CircleIdle.bmp" };
	Surface player2Move = { "Images\\CircleIdle.bmp" };
	Surface player2Hit = { "Images\\CircleIdle.bmp" };
	Surface player2LivesIcon = { "Images\\CircleLivesIcon.bmp" };

	Surface idle[8];
	Surface move[8];
	Surface hit[8];
	Surface lives[8];

	Surface startThree = { "Images\\StartThree.bmp" };
	Surface startTwo = { "Images\\StartTwo.bmp" };
	Surface startOne = { "Images\\StartOne.bmp" };
	Surface go = { "Images\\Go.bmp" };
	Surface numbers[10];
	Surface zero = { "Images\\0.bmp" };
	Surface one = { "Images\\1.bmp" };
	Surface two = { "Images\\2.bmp" };
	Surface three = { "Images\\3.bmp" };
	Surface four = { "Images\\4.bmp" };
	Surface five = { "Images\\5.bmp" };
	Surface six = { "Images\\6.bmp" };
	Surface seven = { "Images\\7.bmp" };
	Surface eight = { "Images\\8.bmp" };
	Surface nine = { "Images\\9.bmp" };
	Surface startVisual = { "Images\\Start Menu.bmp" };
	Surface mapSelectVisual = { "Images\\Map Select Menu.bmp" };
	Surface pauseVisual = { "Images\\Pause Menu.bmp" };
	Surface creditsVisual = { "Images\\Credits Menu.bmp" };
	Surface player1Win = { "Images\\Player1Win.bmp" };
	Surface player2Win = { "Images\\Player2Win.bmp" };
	Sound MainMenuTheme;
	Sound HitSound;
	Sound CreditsTheme;
	Sound BattleTheme0;
	Sound BattleTheme1;
	Sound BattleTheme2;
	Sound BattleTheme3;
	Character Player1;
	Character Player2;
	/********************************/
	std::vector<std::vector<float>> parameters = {
	//Circle
	{
		100, //parameters[0]Width
		100, //parameters[1]Height
		10, //parameters[2]WalkSpeed
		10, //parameters[3]AerialSpeed
		1, //parameters[4]AerialAcceleration
		1, //parameters[5]WalkAcceleration
		20, //parameters[6]GroundedJumpHeight
		25, //parameters[7]AerialJumpHeight
		1, //parameters[8]FallAcceleration
		10, //parameters[9]FallSpeed
		1, //parameters[10]Weight
		2, //parameters[11]DoubleJumps

		100, //parameters[12]Forward Light Additional x
		0, //parameters[13]Forward Light Additional y
		50, //parameters[14]Forward Light Width
		10, //parameters[15]Forward Light Height
		40, //parameters[16]Forward Light Stun Duration
		5, //parameters[17]Forward Light Scalar X
		-5, //parameters[18]Forward Light Scalar y
		3, //parameters[19]Forward Light Fixed x
		-3, //parameters[20]Forward Light Fixed y
		0, //parameters[21]Forward Light vx
		0, //parameters[22]Forward Light vy
		0, //parameters[23]Acceleration x
		0, //parameters[24]Acceleration y
		10, //parameters[25]Forward Light Damage
		10, //parameters[26]Forward Light Start Up Duraiton
		30, //parameters[27]Forward Light Active Duration
		10, //parameters[28]Forward Light End Lag Duration
		1, //parameters[29]Forward Light Is Attached To Player
		0, //parameters[30] Is Player Attached To It
		0, //parameters[31]Forward Light Disappear On Hit

		100, //parameters[32]Up Light Additional x
		0, //parameters[33]Up Light Additional y
		20, //parameters[34]Up Light Width
		20, //parameters[35]Up Light Height
		15, //parameters[36]Up Light Stun Duration
		1, //parameters[37]Up Light Scalar X
		-5, //parameters[38]Up Light Scalar y
		2, //parameters[39]Up Light Fixed x
		-3, //parameters[40]Up Light Fixed y
		0, //parameters[41]Up Light vx
		0, //parameters[42]Up Light vy
		0, //parameters[43]Acceleration x
		0, //parameters[44]Acceleration y
		6, //parameters[45]Up Light Damage
		10, //parameters[46]Up Light Start Up Duraiton
		30, //parameters[47]Up Light Active Duration
		10, //parameters[48]Up Light End Lag Duration
		1, //parameters[49]Up Light Is Attached To Player
		0, //parameters[50] Is Player Attached To It
		0, //parameters[51]Up Light Disappear On Hit

		0, //parameters[52]Down Light Additional x
		90, //parameters[53]Down Light Additional y
		100, //parameters[54]Down Light Width
		10, //parameters[55]Down Light Height
		50, //parameters[56]Down Light Stun Duration
		0, //parameters[57]Down Light Scalar X
		4, //parameters[58]Down Light Scalar y
		5, //parameters[59]Down Light Fixed x
		0, //parameters[60]Down Light Fixed y
		0, //parameters[61]Down Light vx
		0, //parameters[62]Down Light vy
		0, //parameters[63]Acceleration x
		0, //parameters[64]Acceleration y
		0.1, //parameters[65]Down Light Damage
		10, //parameters[66]Down Light Start Up Duraiton
		10, //parameters[67]Down Light Active Duration
		30, //parameters[68]Down Light End Lag Duration
		1, //parameters[69]Down Light Is Attached To Player
		0, //parameters[70] Is Player Attached To It
		0, //parameters[71]Down Light Disappear On Hit

		100, //parameters[72]Forward Heavy Additional x
		0, //parameters[73]Forward Heavy Additional y
		50, //parameters[74]Forward Heavy Width
		10, //parameters[75]Forward Heavy Height
		80, //parameters[76]Forward Heavy Stun Duration
		6, //parameters[77]Forward Heavy Scalar X
		-6, //parameters[78]Forward Heavy Scalar y
		3.5, //parameters[79]Forward Heavy Fixed x
		-3.5, //parameters[80]Forward Heavy Fixed y
		0, //parameters[81]Forward Heavy vx
		0, //parameters[82]Forward Heavy vy
		0, //parameters[83]Acceleration x
		0, //parameters[84]Acceleration y
		20, //parameters[85]Forward Heavy Damage
		40, //parameters[86]Forward Heavy Start Up Duraiton
		60, //parameters[87]Forward Heavy Active Duration
		20, //parameters[88]Forward Heavy End Lag Duration
		1, //parameters[89]Forward Heavy Is Attached To Player
		0, //parameters[90] Is Player Attached To It
		0, //parameters[91]Forward Heavy Disappear On Hit

		50, //parameters[92]Up Heavy Additional x
		-10, //parameters[93]Up Heavy Additional y
		50, //parameters[94]Up Heavy Width
		10, //parameters[95]Up Heavy Height
		40, //parameters[96]Up Heavy Stun Duration
		1, //parameters[97]Up Heavy Scalar X
		-1, //parameters[98]Up Heavy Scalar y
		1, //parameters[99]Up Heavy Fixed x
		-4, //parameters[100]Up Heavy Fixed y
		0, //parameters[101]Up Heavy vx
		0, //parameters[102]Up Heavy vy
		0, //parameters[103]Acceleration x
		0, //parameters[104]Acceleration y
		25, //parameters[105]Up Heavy Damage
		10, //parameters[106]Up Heavy Start Up Duraiton
		30, //parameters[107]Up Heavy Active Duration
		30, //parameters[108]Up Heavy End Lag Duration
		1, //parameters[109]Up Heavy Is Attached To Player
		0, //parameters[110] Is Player Attached To It
		0, //parameters[111]Up Heavy Disappear On Hit

		100, //parameters[112]Down Heavy Additional x
		90, //parameters[113]Down Heavy Additional y
		50, //parameters[114]Down Heavy Width
		10, //parameters[115]Down Heavy Height
		20, //parameters[116]Down Heavy Stun Duration
		0, //parameters[117]Down Heavy Scalar X
		-1, //parameters[118]Down Heavy Scalar y
		7, //parameters[119]Down Heavy Fixed x
		-1, //parameters[120]Down Heavy Fixed y
		0, //parameters[121]Down Heavy vx
		0, //parameters[122]Down Heavy vy
		0, //parameters[123]Acceleration x
		0, //parameters[124]Acceleration y
		10, //parameters[125]Down Heavy Damage
		10, //parameters[126]Down Heavy Start Up Duraiton
		30, //parameters[127]Down Heavy Active Duration
		10, //parameters[128]Down Heavy End Lag Duration
		1, //parameters[129]Down Heavy Is Attached To Player
		0, //parameters[130] Is Player Attached To It
		0, //parameters[131]Down Heavy Disappear On Hit

		100, //parameters[132]Forward Aerial Additional x
		0, //parameters[133]Forward Aerial Additional y
		50, //parameters[134]Forward Aerial Width
		10, //parameters[135]Forward Aerial Height
		40, //parameters[136]Forward Aerial Stun Duration
		5, //parameters[137]Forward Aerial Scalar X
		-5, //parameters[138]Forward Aerial Scalar y
		3, //parameters[139]Forward Aerial Fixed x
		-3, //parameters[140]Forward Aerial Fixed y
		0, //parameters[141]Forward Aerial vx
		0, //parameters[142]Forward Aerial vy
		0, //parameters[143]Acceleration x
		0, //parameters[144]Acceleration y
		10, //parameters[145]Forward Aerial Damage
		10, //parameters[146]Forward Aerial Start Up Duraiton
		30, //parameters[147]Forward Aerial Active Duration
		10, //parameters[148]Forward Aerial End Lag Duration
		1, //parameters[149]Forward Aerial Is Attached To Player
		0, //parameters[150] Is Player Attached To It
		0, //parameters[151]Forward Aerial Disappear On Hit

		-50, //parameters[152]Back Aerial Additional x
		0, //parameters[153]Back Aerial Additional y
		50, //parameters[154]Back Aerial Width
		10, //parameters[155]Back Aerial Height
		40, //parameters[156]Back Aerial Stun Duration
		5, //parameters[157]Back Aerial Scalar X
		-5, //parameters[158]Back Aerial Scalar y
		3, //parameters[159]Back Aerial Fixed x
		-3, //parameters[160]Back Aerial Fixed y
		0, //parameters[161]Back Aerial vx
		0, //parameters[162]Back Aerial vy
		0, //parameters[163]Acceleration x
		0, //parameters[164]Acceleration y
		10, //parameters[165]Back Aerial Damage
		10, //parameters[166]Back Aerial Start Up Duraiton
		30, //parameters[167]Back Aerial Active Duration
		10, //parameters[168]Back Aerial End Lag Duration
		1, //parameters[169]Back Aerial Is Attached To Player
		0, //parameters[170] Is Player Attached To It
		0, //parameters[171]Back Aerial Disappear On Hit

		50, //parameters[172]Up Aerial Additional x
		-10, //parameters[173]Up Aerial Additional y
		50, //parameters[174]Up Aerial Width
		10, //parameters[175]Up Aerial Height
		40, //parameters[176]Up Aerial Stun Duration
		1, //parameters[177]Up Aerial Scalar X
		5, //parameters[178]Up Aerial Scalar y
		1, //parameters[179]Up Aerial Fixed x
		3, //parameters[180]Up Aerial Fixed y
		0, //parameters[181]Up Aerial vx
		0, //parameters[182]Up Aerial vy
		0, //parameters[183]Acceleration x
		0, //parameters[184]Acceleration y
		5.3, //parameters[185]Up Aerial Damage
		15, //parameters[186]Up Aerial Start Up Duraiton
		20, //parameters[187]Up Aerial Active Duration
		25, //parameters[188]Up Aerial End Lag Duration
		1, //parameters[189]Up Aerial Is Attached To Player
		0, //parameters[190] Is Player Attached To It
		0, //parameters[191]Up Aerial Disappear On Hit

		50, //parameters[192]Down Aerial Additional x
		110, //parameters[193]Down Aerial Additional y
		50, //parameters[194]Down Aerial Width
		10, //parameters[195]Down Aerial Height
		40, //parameters[196]Down Aerial Stun Duration
		0, //parameters[197]Down Aerial Scalar X
		-5, //parameters[198]Down Aerial Scalar y
		0, //parameters[199]Down Aerial Fixed x
		-3, //parameters[200]Down Aerial Fixed y
		0, //parameters[201]Down Aerial vx
		0, //parameters[202]Down Aerial vy
		0, //parameters[203]Acceleration x
		0, //parameters[204]Acceleration y
		5.3, //parameters[205]Down Aerial Damage
		25, //parameters[206]Down Aerial Start Up Duraiton
		20, //parameters[207]Down Aerial Active Duration
		15, //parameters[208]Down Aerial End Lag Duration
		1, //parameters[209]Down Aerial Is Attached To Player
		0, //parameters[210] Is Player Attached To It
		0, //parameters[211]Down Aerial Disappear On Hit

		150, //parameters[212]Forward Special Additional x
		0, //parameters[213]Forward Special Additional y
		50, //parameters[214]Forward Special Width
		10, //parameters[215]Forward Special Height
		20, //parameters[216]Forward Special Stun Duration
		15, //parameters[217]Forward Special Scalar X
		-1, //parameters[218]Forward Special Scalar y
		3, //parameters[219]Forward Special Fixed x
		-3, //parameters[220]Forward Special Fixed y
		2, //parameters[221]Forward Special vx
		0.5, //parameters[222]Forward Special vy
		0, //parameters[223]Acceleration x
		0, //parameters[224]Acceleration y
		5, //parameters[225]Forward Special Damage
		10, //parameters[226]Forward Special Start Up Duraiton
		300, //parameters[227]Forward Special Active Duration
		50, //parameters[228]Forward Special End Lag Duration
		0, //parameters[229]Forward Special Is Attached To Player
		0, //parameters[230] Is Player Attached To It
		1, //parameters[231]Forward Special Disappear On Hit

		100, //parameters[232]Up Special Additional x
		0, //parameters[233]Up Special Additional y
		50, //parameters[234]Up Special Width
		10, //parameters[235]Up Special Height
		20, //parameters[236]Up Special Stun Duration
		15, //parameters[237]Up Special Scalar X
		-1, //parameters[238]Up Special Scalar y
		3, //parameters[239]Up Special Fixed x
		-3, //parameters[240]Up Special Fixed y
		2, //parameters[241]Up Special vx
		0.5, //parameters[242]Up Special vy
		0, //parameters[243]Acceleration x
		-0.1, //parameters[244]Acceleration y
		5, //parameters[245]Up Special Damage
		10, //parameters[246]Up Special Start Up Duraiton
		50, //parameters[247]Up Special Active Duration
		30, //parameters[248]Up Special End Lag Duration
		0, //parameters[249]Up Special Is Attached To Player
		1, //parameters[250] Is Player Attached To It
		0, //parameters[251]Up Special Disappear On Hit

		100, //parameters[252]Down Special Additional x
		0, //parameters[253]Down Special Additional y
		50, //parameters[254]Down Special Width
		10, //parameters[255]Down Special Height
		20, //parameters[256]Down Special Stun Duration
		15, //parameters[257]Down Special Scalar X
		-5, //parameters[258]Down Special Scalar y
		3, //parameters[259]Down Special Fixed x
		-3, //parameters[260]Down Special Fixed y
		2, //parameters[261]Down Special vx
		0, //parameters[262]Down Special vy
		0, //parameters[263]Acceleration x
		0, //parameters[264]Acceleration y
		5, //parameters[265]Down Special Damage
		10, //parameters[266]Down Special Start Up Duraiton
		300, //parameters[267]Down Special Active Duration
		20, //parameters[268]Down Special End Lag Duration
		0, //parameters[269]Down Special Is Attached To Player
		1, //parameters[270] Is Player Attached To It
		0, //parameters[271]Down Special Disappear On Hit    

		0, //parameters[272]Forward Light R
		255, //parameters[273]Forward Light G
		255, //parameters[274]Forward Light B
		255, //parameters[275]
		255, //parameters[276]
		255, //parameters[277]
		255, //parameters[278]
		255, //parameters[279]
		255, //parameters[280]
		255, //parameters[281]
		255, //parameters[282]
		255, //parameters[283]
		255, //parameters[284]
		255, //parameters[285]
		255, //parameters[286]
		255, //parameters[287]
		255, //parameters[288]
		255, //parameters[289]
		255, //parameters[290]
		255, //parameters[291]
		255, //parameters[292]
		255, //parameters[293]
		255, //parameters[294]
		255, //parameters[295]
		255, //parameters[296]
		255, //parameters[297]
		255, //parameters[298]
		255, //parameters[299]
		255, //parameters[300]
		255, //parameters[301]
		255, //parameters[302]
		255, //parameters[303]
		255, //parameters[304]
		255, //parameters[305]
		255, //parameters[306]
		255, //parameters[307]
		255, //parameters[308]
		255, //parameters[309]
		255 //parameters[310]
	},
	//a
	{
		100, //parameters[0]Width
		100, //parameters[1]Height
		7, //parameters[2]WalkSpeed
		13, //parameters[3]AerialSpeed
		1.5, //parameters[4]AerialAcceleration
		1.5, //parameters[5]WalkAcceleration
		35, //parameters[6]GroundedJumpHeight
		25, //parameters[7]AerialJumpHeight
		1, //parameters[8]FallAcceleration
		5, //parameters[9]FallSpeed
		0.85, //parameters[10]Weight
		1, //parameters[11]DoubleJumps

		100, //parameters[12]Forward Light Additional x
		60, //parameters[13]Forward Light Additional y
		35, //parameters[14]Forward Light Width
		10, //parameters[15]Forward Light Height
		40, //parameters[16]Forward Light Stun Duration
		2, //parameters[17]Forward Light Scalar X
		-2, //parameters[18]Forward Light Scalar y
		7, //parameters[19]Forward Light Fixed x
		-1, //parameters[20]Forward Light Fixed y
		0, //parameters[21]Forward Light vx
		0, //parameters[22]Forward Light vy
		0, //parameters[23]Acceleration x
		0, //parameters[24]Acceleration y
		6, //parameters[25]Forward Light Damage
		10, //parameters[26]Forward Light Start Up Duraiton
		30, //parameters[27]Forward Light Active Duration
		20, //parameters[28]Forward Light End Lag Duration
		1, //parameters[29]Forward Light Is Attached To Player
		0, //parameters[30] Is Player Attached To It
		0, //parameters[31]Forward Light Disappear On Hit

		0, //parameters[32]Up Light Additional x
		-3, //parameters[33]Up Light Additional y
		100, //parameters[34]Up Light Width
		5, //parameters[35]Up Light Height
		20, //parameters[36]Up Light Stun Duration
		1, //parameters[37]Up Light Scalar X
		-6, //parameters[38]Up Light Scalar y
		1, //parameters[39]Up Light Fixed x
		-2, //parameters[40]Up Light Fixed y
		0, //parameters[41]Up Light vx
		0, //parameters[42]Up Light vy
		0, //parameters[43]Acceleration x
		0, //parameters[44]Acceleration y
		4, //parameters[45]Up Light Damage
		10, //parameters[46]Up Light Start Up Duraiton
		30, //parameters[47]Up Light Active Duration
		15, //parameters[48]Up Light End Lag Duration
		1, //parameters[49]Up Light Is Attached To Player
		0, //parameters[50] Is Player Attached To It
		0, //parameters[51]Up Light Disappear On Hit

		100, //parameters[52]Down Light Additional x
		95, //parameters[53]Down Light Additional y
		70, //parameters[54]Down Light Width
		3, //parameters[55]Down Light Height
		20, //parameters[56]Down Light Stun Duration
		0.1, //parameters[57]Down Light Scalar X
		-0.5, //parameters[58]Down Light Scalar y
		7, //parameters[59]Down Light Fixed x
		-0.5, //parameters[60]Down Light Fixed y
		0, //parameters[61]Down Light vx
		0, //parameters[62]Down Light vy
		0, //parameters[63]Acceleration x
		0, //parameters[64]Acceleration y
		7, //parameters[65]Down Light Damage
		20, //parameters[66]Down Light Start Up Duraiton
		15, //parameters[67]Down Light Active Duration
		20, //parameters[68]Down Light End Lag Duration
		1, //parameters[69]Down Light Is Attached To Player
		0, //parameters[70] Is Player Attached To It
		0, //parameters[71]Down Light Disappear On Hit

		90, //parameters[72]Forward Heavy Additional x
		25, //parameters[73]Forward Heavy Additional y
		40, //parameters[74]Forward Heavy Width
		50, //parameters[75]Forward Heavy Height
		40, //parameters[76]Forward Heavy Stun Duration
		1, //parameters[77]Forward Heavy Scalar X
		-5, //parameters[78]Forward Heavy Scalar y
		0, //parameters[79]Forward Heavy Fixed x
		-3, //parameters[80]Forward Heavy Fixed y
		0, //parameters[81]Forward Heavy vx
		0, //parameters[82]Forward Heavy vy
		0, //parameters[83]Acceleration x
		0, //parameters[84]Acceleration y
		12.3, //parameters[85]Forward Heavy Damage
		21, //parameters[86]Forward Heavy Start Up Duraiton
		10, //parameters[87]Forward Heavy Active Duration
		20, //parameters[88]Forward Heavy End Lag Duration
		1, //parameters[89]Forward Heavy Is Attached To Player
		0, //parameters[90] Is Player Attached To It
		0, //parameters[91]Forward Heavy Disappear On Hit

		30, //parameters[92]Up Heavy Additional x
		-50, //parameters[93]Up Heavy Additional y
		40, //parameters[94]Up Heavy Width
		52, //parameters[95]Up Heavy Height
		40, //parameters[96]Up Heavy Stun Duration
		1, //parameters[97]Up Heavy Scalar X
		-2, //parameters[98]Up Heavy Scalar y
		0, //parameters[99]Up Heavy Fixed x
		-6, //parameters[100]Up Heavy Fixed y
		0, //parameters[101]Up Heavy vx
		0, //parameters[102]Up Heavy vy
		0, //parameters[103]Acceleration x
		0, //parameters[104]Acceleration y
		15, //parameters[105]Up Heavy Damage
		25, //parameters[106]Up Heavy Start Up Duraiton
		40, //parameters[107]Up Heavy Active Duration
		15, //parameters[108]Up Heavy End Lag Duration
		1, //parameters[109]Up Heavy Is Attached To Player
		0, //parameters[110] Is Player Attached To It
		0, //parameters[111]Up Heavy Disappear On Hit

		-20, //parameters[112]Down Heavy Additional x
		70, //parameters[113]Down Heavy Additional y
		140, //parameters[114]Down Heavy Width
		30, //parameters[115]Down Heavy Height
		40, //parameters[116]Down Heavy Stun Duration
		2, //parameters[117]Down Heavy Scalar X
		-15, //parameters[118]Down Heavy Scalar y
		0, //parameters[119]Down Heavy Fixed x
		-3, //parameters[120]Down Heavy Fixed y
		0, //parameters[121]Down Heavy vx
		0, //parameters[122]Down Heavy vy
		0, //parameters[123]Acceleration x
		0, //parameters[124]Acceleration y
		12.5, //parameters[125]Down Heavy Damage
		10, //parameters[126]Down Heavy Start Up Duraiton
		30, //parameters[127]Down Heavy Active Duration
		60, //parameters[128]Down Heavy End Lag Duration
		1, //parameters[129]Down Heavy Is Attached To Player
		0, //parameters[130] Is Player Attached To It
		0, //parameters[131]Down Heavy Disappear On Hit

		90, //parameters[132]Forward Aerial Additional x
		30, //parameters[133]Forward Aerial Additional y
		35, //parameters[134]Forward Aerial Width
		40, //parameters[135]Forward Aerial Height
		40, //parameters[136]Forward Aerial Stun Duration
		5, //parameters[137]Forward Aerial Scalar X
		-5, //parameters[138]Forward Aerial Scalar y
		3, //parameters[139]Forward Aerial Fixed x
		-3, //parameters[140]Forward Aerial Fixed y
		0, //parameters[141]Forward Aerial vx
		0, //parameters[142]Forward Aerial vy
		0, //parameters[143]Acceleration x
		0, //parameters[144]Acceleration y
		10, //parameters[145]Forward Aerial Damage
		10, //parameters[146]Forward Aerial Start Up Duraiton
		40, //parameters[147]Forward Aerial Active Duration
		25, //parameters[148]Forward Aerial End Lag Duration
		1, //parameters[149]Forward Aerial Is Attached To Player
		0, //parameters[150] Is Player Attached To It
		0, //parameters[151]Forward Aerial Disappear On Hit

		-50, //parameters[152]Back Aerial Additional x
		50, //parameters[153]Back Aerial Additional y
		50, //parameters[154]Back Aerial Width
		10, //parameters[155]Back Aerial Height
		20, //parameters[156]Back Aerial Stun Duration
		0, //parameters[157]Back Aerial Scalar X
		-1, //parameters[158]Back Aerial Scalar y
		-2, //parameters[159]Back Aerial Fixed x
		-3, //parameters[160]Back Aerial Fixed y
		0, //parameters[161]Back Aerial vx
		0, //parameters[162]Back Aerial vy
		0, //parameters[163]Acceleration x
		0, //parameters[164]Acceleration y
		10, //parameters[165]Back Aerial Damage
		10, //parameters[166]Back Aerial Start Up Duraiton
		30, //parameters[167]Back Aerial Active Duration
		10, //parameters[168]Back Aerial End Lag Duration
		1, //parameters[169]Back Aerial Is Attached To Player
		0, //parameters[170] Is Player Attached To It
		0, //parameters[171]Back Aerial Disappear On Hit

		70, //parameters[172]Up Aerial Additional x
		0, //parameters[173]Up Aerial Additional y
		60, //parameters[174]Up Aerial Width
		30, //parameters[175]Up Aerial Height
		30, //parameters[176]Up Aerial Stun Duration
		0, //parameters[177]Up Aerial Scalar X
		-2, //parameters[178]Up Aerial Scalar y
		1, //parameters[179]Up Aerial Fixed x
		-1, //parameters[180]Up Aerial Fixed y
		0, //parameters[181]Up Aerial vx
		0, //parameters[182]Up Aerial vy
		0, //parameters[183]Acceleration x
		0, //parameters[184]Acceleration y
		4, //parameters[185]Up Aerial Damage
		5, //parameters[186]Up Aerial Start Up Duraiton
		30, //parameters[187]Up Aerial Active Duration
		20, //parameters[188]Up Aerial End Lag Duration
		1, //parameters[189]Up Aerial Is Attached To Player
		0, //parameters[190] Is Player Attached To It
		0, //parameters[191]Up Aerial Disappear On Hit

		50, //parameters[192]Down Aerial Additional x
		100, //parameters[193]Down Aerial Additional y
		10, //parameters[194]Down Aerial Width
		50, //parameters[195]Down Aerial Height
		20, //parameters[196]Down Aerial Stun Duration
		1, //parameters[197]Down Aerial Scalar X
		5, //parameters[198]Down Aerial Scalar y
		1, //parameters[199]Down Aerial Fixed x
		3, //parameters[200]Down Aerial Fixed y
		0, //parameters[201]Down Aerial vx
		4, //parameters[202]Down Aerial vy
		0, //parameters[203]Acceleration x
		0.15, //parameters[204]Acceleration y
		13.7, //parameters[205]Down Aerial Damage
		10, //parameters[206]Down Aerial Start Up Duraiton
		70, //parameters[207]Down Aerial Active Duration
		50, //parameters[208]Down Aerial End Lag Duration
		0, //parameters[209]Down Aerial Is Attached To Player
		0, //parameters[210] Is Player Attached To It
		0, //parameters[211]Down Aerial Disappear On Hit

		100, //parameters[212]Forward Special Additional x
		0, //parameters[213]Forward Special Additional y
		40, //parameters[214]Forward Special Width
		100, //parameters[215]Forward Special Height
		20, //parameters[216]Forward Special Stun Duration
		0, //parameters[217]Forward Special Scalar X
		0, //parameters[218]Forward Special Scalar y
		3, //parameters[219]Forward Special Fixed x
		-1, //parameters[220]Forward Special Fixed y
		6, //parameters[221]Forward Special vx
		0, //parameters[222]Forward Special vy
		-0.5, //parameters[223]Acceleration x
		0, //parameters[224]Acceleration y
		0.5, //parameters[225]Forward Special Damage
		30, //parameters[226]Forward Special Start Up Duraiton
		30, //parameters[227]Forward Special Active Duration
		30, //parameters[228]Forward Special End Lag Duration
		0, //parameters[229]Forward Special Is Attached To Player
		1, //parameters[230] Is Player Attached To It
		0, //parameters[231]Forward Special Disappear On Hit

		30, //parameters[232]Up Special Additional x
		-20, //parameters[233]Up Special Additional y
		40, //parameters[234]Up Special Width
		20, //parameters[235]Up Special Height
		20, //parameters[236]Up Special Stun Duration
		1, //parameters[237]Up Special Scalar X
		-9, //parameters[238]Up Special Scalar y
		0, //parameters[239]Up Special Fixed x
		-3, //parameters[240]Up Special Fixed y
		0, //parameters[241]Up Special vx
		-3, //parameters[242]Up Special vy
		0, //parameters[243]Acceleration x
		-0.3, //parameters[244]Acceleration y
		5, //parameters[245]Up Special Damage
		10, //parameters[246]Up Special Start Up Duraiton
		43, //parameters[247]Up Special Active Duration
		40, //parameters[248]Up Special End Lag Duration
		0, //parameters[249]Up Special Is Attached To Player
		1, //parameters[250] Is Player Attached To It
		0, //parameters[251]Up Special Disappear On Hit

		50, //parameters[252]Down Special Additional x
		0, //parameters[253]Down Special Additional y
		70, //parameters[254]Down Special Width
		100, //parameters[255]Down Special Height
		20, //parameters[256]Down Special Stun Duration
		9, //parameters[257]Down Special Scalar X
		-1, //parameters[258]Down Special Scalar y
		3, //parameters[259]Down Special Fixed x
		3, //parameters[260]Down Special Fixed y
		2, //parameters[261]Down Special vx
		11, //parameters[262]Down Special vy
		0.25, //parameters[263]Acceleration x
		-0.15, //parameters[264]Acceleration y
		9.3, //parameters[265]Down Special Damage
		10, //parameters[266]Down Special Start Up Duraiton
		50, //parameters[267]Down Special Active Duration
		10, //parameters[268]Down Special End Lag Duration
		0, //parameters[269]Down Special Is Attached To Player
		1, //parameters[270] Is Player Attached To It
		0, //parameters[271]Down Special Disappear On Hit     
		255, //parameters[272]Forward Light R
		255, //parameters[273]Forward Light G
		255, //parameters[274]Forward Light B
		255, //parameters[275]
		255, //parameters[276]
		255, //parameters[277]
		255, //parameters[278]
		255, //parameters[279]
		255, //parameters[280]
		255, //parameters[281]
		255, //parameters[282]
		255, //parameters[283]
		255, //parameters[284]
		255, //parameters[285]
		255, //parameters[286]
		255, //parameters[287]
		255, //parameters[288]
		255, //parameters[289]
		255, //parameters[290]
		255, //parameters[291]
		255, //parameters[292]
		255, //parameters[293]
		255, //parameters[294]
		255, //parameters[295]
		255, //parameters[296]
		255, //parameters[297]
		255, //parameters[298]
		255, //parameters[299]
		255, //parameters[300]
		255, //parameters[301]
		255, //parameters[302]
		255, //parameters[303]
		255, //parameters[304]
		255, //parameters[305]
		255, //parameters[306]
		255, //parameters[307]
		255, //parameters[308]
		255, //parameters[309]
		255 //parameters[310] 
	}, 
	//Sigma Monkey Of Doom
	{
		63, //parameters[0]Width
		100, //parameters[1]Height
		13, //parameters[2]WalkSpeed
		7, //parameters[3]AerialSpeed
		0.1, //parameters[4]AerialAcceleration
		1.5, //parameters[5]WalkAcceleration
		5, //parameters[6]GroundedJumpHeight
		10.4, //parameters[7]AerialJumpHeight
		0.1, //parameters[8]FallAcceleration
		7, //parameters[9]FallSpeed
		0.84, //parameters[10]Weight
		1, //parameters[11]DoubleJumps

		63, //parameters[12]Forward Light Additional x
		40, //parameters[13]Forward Light Additional y
		20, //parameters[14]Forward Light Width
		10, //parameters[15]Forward Light Height
		40, //parameters[16]Forward Light Stun Duration
		2, //parameters[17]Forward Light Scalar X
		-7, //parameters[18]Forward Light Scalar y
		1, //parameters[19]Forward Light Fixed x
		-2, //parameters[20]Forward Light Fixed y
		0, //parameters[21]Forward Light vx
		0, //parameters[22]Forward Light vy
		0, //parameters[23]Acceleration x
		0, //parameters[24]Acceleration y
		7, //parameters[25]Forward Light Damage
		6, //parameters[26]Forward Light Start Up Duraiton
		23, //parameters[27]Forward Light Active Duration
		9, //parameters[28]Forward Light End Lag Duration
		1, //parameters[29]Forward Light Is Attached To Player
		0, //parameters[30] Is Player Attached To It
		0, //parameters[31]Forward Light Disappear On Hit

		10, //parameters[32]Up Light Additional x
		-10, //parameters[33]Up Light Additional y
		43, //parameters[34]Up Light Width
		10, //parameters[35]Up Light Height
		13, //parameters[36]Up Light Stun Duration
		2, //parameters[37]Up Light Scalar X
		-5, //parameters[38]Up Light Scalar y
		3, //parameters[39]Up Light Fixed x
		-3, //parameters[40]Up Light Fixed y
		0, //parameters[41]Up Light vx
		0, //parameters[42]Up Light vy
		0, //parameters[43]Acceleration x
		0, //parameters[44]Acceleration y
		7, //parameters[45]Up Light Damage
		10, //parameters[46]Up Light Start Up Duraiton
		13, //parameters[47]Up Light Active Duration
		16, //parameters[48]Up Light End Lag Duration
		1, //parameters[49]Up Light Is Attached To Player
		0, //parameters[50] Is Player Attached To It
		0, //parameters[51]Up Light Disappear On Hit

		43, //parameters[52]Down Light Additional x
		80, //parameters[53]Down Light Additional y
		40, //parameters[54]Down Light Width
		20, //parameters[55]Down Light Height
		32, //parameters[56]Down Light Stun Duration
		1, //parameters[57]Down Light Scalar X
		-5, //parameters[58]Down Light Scalar y
		1, //parameters[59]Down Light Fixed x
		-2, //parameters[60]Down Light Fixed y
		0, //parameters[61]Down Light vx
		0, //parameters[62]Down Light vy
		0, //parameters[63]Acceleration x
		0, //parameters[64]Acceleration y
		3.4, //parameters[65]Down Light Damage
		5, //parameters[66]Down Light Start Up Duraiton
		5, //parameters[67]Down Light Active Duration
		5, //parameters[68]Down Light End Lag Duration
		1, //parameters[69]Down Light Is Attached To Player
		0, //parameters[70] Is Player Attached To It
		0, //parameters[71]Down Light Disappear On Hit

		53, //parameters[72]Forward Heavy Additional x
		0, //parameters[73]Forward Heavy Additional y
		40, //parameters[74]Forward Heavy Width
		10, //parameters[75]Forward Heavy Height
		40, //parameters[76]Forward Heavy Stun Duration
		13, //parameters[77]Forward Heavy Scalar X
		-5, //parameters[78]Forward Heavy Scalar y
		3, //parameters[79]Forward Heavy Fixed x
		-3, //parameters[80]Forward Heavy Fixed y
		3, //parameters[81]Forward Heavy vx
		0, //parameters[82]Forward Heavy vy
		0.05, //parameters[83]Acceleration x
		0, //parameters[84]Acceleration y
		20, //parameters[85]Forward Heavy Damage
		20, //parameters[86]Forward Heavy Start Up Duraiton
		30, //parameters[87]Forward Heavy Active Duration
		30, //parameters[88]Forward Heavy End Lag Duration
		0, //parameters[89]Forward Heavy Is Attached To Player
		1, //parameters[90] Is Player Attached To It
		0, //parameters[91]Forward Heavy Disappear On Hit

		10, //parameters[92]Up Heavy Additional x
		-20, //parameters[93]Up Heavy Additional y
		43, //parameters[94]Up Heavy Width
		30, //parameters[95]Up Heavy Height
		40, //parameters[96]Up Heavy Stun Duration
		1, //parameters[97]Up Heavy Scalar X
		-8, //parameters[98]Up Heavy Scalar y
		1, //parameters[99]Up Heavy Fixed x
		-3, //parameters[100]Up Heavy Fixed y
		0, //parameters[101]Up Heavy vx
		0, //parameters[102]Up Heavy vy
		0, //parameters[103]Acceleration x
		0, //parameters[104]Acceleration y
		9.6, //parameters[105]Up Heavy Damage
		23, //parameters[106]Up Heavy Start Up Duraiton
		30, //parameters[107]Up Heavy Active Duration
		10, //parameters[108]Up Heavy End Lag Duration
		1, //parameters[109]Up Heavy Is Attached To Player
		0, //parameters[110] Is Player Attached To It
		0, //parameters[111]Up Heavy Disappear On Hit

		0, //parameters[112]Down Heavy Additional x
		90, //parameters[113]Down Heavy Additional y
		63, //parameters[114]Down Heavy Width
		10, //parameters[115]Down Heavy Height
		30, //parameters[116]Down Heavy Stun Duration
		9, //parameters[117]Down Heavy Scalar X
		-5, //parameters[118]Down Heavy Scalar y
		5, //parameters[119]Down Heavy Fixed x
		-3, //parameters[120]Down Heavy Fixed y
		0, //parameters[121]Down Heavy vx
		0, //parameters[122]Down Heavy vy
		0, //parameters[123]Acceleration x
		0, //parameters[124]Acceleration y
		14.3, //parameters[125]Down Heavy Damage
		15, //parameters[126]Down Heavy Start Up Duraiton
		17, //parameters[127]Down Heavy Active Duration
		23, //parameters[128]Down Heavy End Lag Duration
		1, //parameters[129]Down Heavy Is Attached To Player
		0, //parameters[130] Is Player Attached To It
		0, //parameters[131]Down Heavy Disappear On Hit

		53, //parameters[132]Forward Aerial Additional x
		40, //parameters[133]Forward Aerial Additional y
		70, //parameters[134]Forward Aerial Width
		20, //parameters[135]Forward Aerial Height
		40, //parameters[136]Forward Aerial Stun Duration
		3, //parameters[137]Forward Aerial Scalar X
		-4, //parameters[138]Forward Aerial Scalar y
		2, //parameters[139]Forward Aerial Fixed x
		-1, //parameters[140]Forward Aerial Fixed y
		0, //parameters[141]Forward Aerial vx
		0, //parameters[142]Forward Aerial vy
		0, //parameters[143]Acceleration x
		0, //parameters[144]Acceleration y
		11.2, //parameters[145]Forward Aerial Damage
		10, //parameters[146]Forward Aerial Start Up Duraiton
		30, //parameters[147]Forward Aerial Active Duration
		10, //parameters[148]Forward Aerial End Lag Duration
		1, //parameters[149]Forward Aerial Is Attached To Player
		0, //parameters[150] Is Player Attached To It
		0, //parameters[151]Forward Aerial Disappear On Hit

		-40, //parameters[152]Back Aerial Additional x
		50, //parameters[153]Back Aerial Additional y
		50, //parameters[154]Back Aerial Width
		20, //parameters[155]Back Aerial Height
		20, //parameters[156]Back Aerial Stun Duration
		-2.5, //parameters[157]Back Aerial Scalar X
		-2.5, //parameters[158]Back Aerial Scalar y
		-1.5, //parameters[159]Back Aerial Fixed x
		-1.5, //parameters[160]Back Aerial Fixed y
		0, //parameters[161]Back Aerial vx
		0, //parameters[162]Back Aerial vy
		0, //parameters[163]Acceleration x
		0, //parameters[164]Acceleration y
		4, //parameters[165]Back Aerial Damage
		10, //parameters[166]Back Aerial Start Up Duraiton
		15, //parameters[167]Back Aerial Active Duration
		10, //parameters[168]Back Aerial End Lag Duration
		1, //parameters[169]Back Aerial Is Attached To Player
		0, //parameters[170] Is Player Attached To It
		0, //parameters[171]Back Aerial Disappear On Hit

		10, //parameters[172]Up Aerial Additional x
		-30, //parameters[173]Up Aerial Additional y
		43, //parameters[174]Up Aerial Width
		30, //parameters[175]Up Aerial Height
		11, //parameters[176]Up Aerial Stun Duration
		2, //parameters[177]Up Aerial Scalar X
		-3, //parameters[178]Up Aerial Scalar y
		3, //parameters[179]Up Aerial Fixed x
		-9, //parameters[180]Up Aerial Fixed y
		0, //parameters[181]Up Aerial vx
		0, //parameters[182]Up Aerial vy
		0, //parameters[183]Acceleration x
		0, //parameters[184]Acceleration y
		6, //parameters[185]Up Aerial Damage
		6, //parameters[186]Up Aerial Start Up Duraiton
		12, //parameters[187]Up Aerial Active Duration
		6, //parameters[188]Up Aerial End Lag Duration
		1, //parameters[189]Up Aerial Is Attached To Player
		0, //parameters[190] Is Player Attached To It
		0, //parameters[191]Up Aerial Disappear On Hit

		20, //parameters[192]Down Aerial Additional x
		100, //parameters[193]Down Aerial Additional y
		23, //parameters[194]Down Aerial Width
		30, //parameters[195]Down Aerial Height
		30, //parameters[196]Down Aerial Stun Duration
		2, //parameters[197]Down Aerial Scalar X
		7, //parameters[198]Down Aerial Scalar y
		1, //parameters[199]Down Aerial Fixed x
		6, //parameters[200]Down Aerial Fixed y
		0, //parameters[201]Down Aerial vx
		0, //parameters[202]Down Aerial vy
		0, //parameters[203]Acceleration x
		0, //parameters[204]Acceleration y
		18, //parameters[205]Down Aerial Damage
		20, //parameters[206]Down Aerial Start Up Duraiton
		30, //parameters[207]Down Aerial Active Duration
		15, //parameters[208]Down Aerial End Lag Duration
		1, //parameters[209]Down Aerial Is Attached To Player
		0, //parameters[210] Is Player Attached To It
		0, //parameters[211]Down Aerial Disappear On Hit

		53, //parameters[212]Forward Special Additional x
		30, //parameters[213]Forward Special Additional y
		30, //parameters[214]Forward Special Width
		40, //parameters[215]Forward Special Height
		10, //parameters[216]Forward Special Stun Duration
		3, //parameters[217]Forward Special Scalar X
		-1, //parameters[218]Forward Special Scalar y
		6, //parameters[219]Forward Special Fixed x
		-3, //parameters[220]Forward Special Fixed y
		4, //parameters[221]Forward Special vx
		-8, //parameters[222]Forward Special vy
		0, //parameters[223]Acceleration x
		0.2, //parameters[224]Acceleration y
		5, //parameters[225]Forward Special Damage
		10, //parameters[226]Forward Special Start Up Duraiton
		60, //parameters[227]Forward Special Active Duration
		0, //parameters[228]Forward Special End Lag Duration
		0, //parameters[229]Forward Special Is Attached To Player
		1, //parameters[230] Is Player Attached To It
		0, //parameters[231]Forward Special Disappear On Hit

		53, //parameters[232]Up Special Additional x
		30, //parameters[233]Up Special Additional y
		30, //parameters[234]Up Special Width
		40, //parameters[235]Up Special Height
		10, //parameters[236]Up Special Stun Duration
		3, //parameters[237]Up Special Scalar X
		-1, //parameters[238]Up Special Scalar y
		6, //parameters[239]Up Special Fixed x
		-3, //parameters[240]Up Special Fixed y
		1.5, //parameters[241]Up Special vx
		6, //parameters[242]Up Special vy
		0, //parameters[243]Acceleration x
		-0.2, //parameters[244]Acceleration y
		5, //parameters[245]Up Special Damage
		10, //parameters[246]Up Special Start Up Duraiton
		80, //parameters[247]Up Special Active Duration
		50, //parameters[248]Up Special End Lag Duration
		0, //parameters[249]Up Special Is Attached To Player
		1, //parameters[250] Is Player Attached To It
		0, //parameters[251]Up Special Disappear On Hit

		73, //parameters[252]Down Special Additional x
		40, //parameters[253]Down Special Additional y
		20, //parameters[254]Down Special Width
		20, //parameters[255]Down Special Height
		50, //parameters[256]Down Special Stun Duration
		15, //parameters[257]Down Special Scalar X
		-1, //parameters[258]Down Special Scalar y
		3, //parameters[259]Down Special Fixed x
		-3, //parameters[260]Down Special Fixed y
		2, //parameters[261]Down Special vx
		0.5, //parameters[262]Down Special vy
		0, //parameters[263]Acceleration x
		0.01, //parameters[264]Acceleration y
		5, //parameters[265]Down Special Damage
		10, //parameters[266]Down Special Start Up Duraiton
		200, //parameters[267]Down Special Active Duration
		50, //parameters[268]Down Special End Lag Duration
		0, //parameters[269]Down Special Is Attached To Player
		0, //parameters[270] Is Player Attached To It
		1, //parameters[271]Down Special Disappear On Hit    
		255, //parameters[272]Forward Light R
		255, //parameters[273]Forward Light G
		255, //parameters[274]Forward Light B
		255, //parameters[275]
		255, //parameters[276]
		255, //parameters[277]
		255, //parameters[278]
		255, //parameters[279]
		255, //parameters[280]
		255, //parameters[281]
		255, //parameters[282]
		255, //parameters[283]
		255, //parameters[284]
		255, //parameters[285]
		255, //parameters[286]
		255, //parameters[287]
		255, //parameters[288]
		255, //parameters[289]
		255, //parameters[290]
		255, //parameters[291]
		255, //parameters[292]
		255, //parameters[293]
		255, //parameters[294]
		255, //parameters[295]
		255, //parameters[296]
		255, //parameters[297]
		255, //parameters[298]
		255, //parameters[299]
		255, //parameters[300]
		255, //parameters[301]
		255, //parameters[302]
		255, //parameters[303]
		255, //parameters[304]
		255, //parameters[305]
		255, //parameters[306]
		255, //parameters[307]
		255, //parameters[308]
		255, //parameters[309]
		255 //parameters[310]  
	}, 
	//Dog MAKE DOWN SPECIAL
	{
		70, //parameters[0]Width
		40, //parameters[1]Height
		9, //parameters[2]WalkSpeed
		4, //parameters[3]AerialSpeed
		4, //parameters[4]AerialAcceleration
		3, //parameters[5]WalkAcceleration
		20, //parameters[6]GroundedJumpHeight
		25, //parameters[7]AerialJumpHeight
		1, //parameters[8]FallAcceleration
		7, //parameters[9]FallSpeed
		1.2, //parameters[10]Weight
		0, //parameters[11]DoubleJumps

		70, //parameters[12]Forward Light Additional x
		15, //parameters[13]Forward Light Additional y
		20, //parameters[14]Forward Light Width
		10, //parameters[15]Forward Light Height
		20, //parameters[16]Forward Light Stun Duration
		6, //parameters[17]Forward Light Scalar X
		1, //parameters[18]Forward Light Scalar y
		6, //parameters[19]Forward Light Fixed x
		0, //parameters[20]Forward Light Fixed y
		0, //parameters[21]Forward Light vx
		0, //parameters[22]Forward Light vy
		0, //parameters[23]Acceleration x
		0, //parameters[24]Acceleration y
		7, //parameters[25]Forward Light Damage
		3, //parameters[26]Forward Light Start Up Duraiton
		10, //parameters[27]Forward Light Active Duration
		20, //parameters[28]Forward Light End Lag Duration
		1, //parameters[29]Forward Light Is Attached To Player
		0, //parameters[30] Is Player Attached To It
		0, //parameters[31]Forward Light Disappear On Hit

		60, //parameters[32]Up Light Additional x
		-20, //parameters[33]Up Light Additional y
		15, //parameters[34]Up Light Width
		40, //parameters[35]Up Light Height
		30, //parameters[36]Up Light Stun Duration
		2, //parameters[37]Up Light Scalar X
		-5, //parameters[38]Up Light Scalar y
		1, //parameters[39]Up Light Fixed x
		-3, //parameters[40]Up Light Fixed y
		0, //parameters[41]Up Light vx
		0, //parameters[42]Up Light vy
		0, //parameters[43]Acceleration x
		0, //parameters[44]Acceleration y
		10, //parameters[45]Up Light Damage
		10, //parameters[46]Up Light Start Up Duraiton
		30, //parameters[47]Up Light Active Duration
		10, //parameters[48]Up Light End Lag Duration
		1, //parameters[49]Up Light Is Attached To Player
		0, //parameters[50] Is Player Attached To It
		0, //parameters[51]Up Light Disappear On Hit

		70, //parameters[52]Down Light Additional x
		95, //parameters[53]Down Light Additional y
		50, //parameters[54]Down Light Width
		5, //parameters[55]Down Light Height
		30, //parameters[56]Down Light Stun Duration
		0, //parameters[57]Down Light Scalar X
		0, //parameters[58]Down Light Scalar y
		-0.3, //parameters[59]Down Light Fixed x
		-1, //parameters[60]Down Light Fixed y
		0, //parameters[61]Down Light vx
		0, //parameters[62]Down Light vy
		0, //parameters[63]Acceleration x
		0, //parameters[64]Acceleration y
		4, //parameters[65]Down Light Damage
		10, //parameters[66]Down Light Start Up Duraiton
		30, //parameters[67]Down Light Active Duration
		15, //parameters[68]Down Light End Lag Duration
		1, //parameters[69]Down Light Is Attached To Player
		0, //parameters[70] Is Player Attached To It
		0, //parameters[71]Down Light Disappear On Hit

		70, //parameters[72]Forward Heavy Additional x
		10, //parameters[73]Forward Heavy Additional y
		30, //parameters[74]Forward Heavy Width
		20, //parameters[75]Forward Heavy Height
		40, //parameters[76]Forward Heavy Stun Duration
		13, //parameters[77]Forward Heavy Scalar X
		-4, //parameters[78]Forward Heavy Scalar y
		3, //parameters[79]Forward Heavy Fixed x
		0, //parameters[80]Forward Heavy Fixed y
		0, //parameters[81]Forward Heavy vx
		0, //parameters[82]Forward Heavy vy
		0, //parameters[83]Acceleration x
		0, //parameters[84]Acceleration y
		16.1, //parameters[85]Forward Heavy Damage
		13, //parameters[86]Forward Heavy Start Up Duraiton
		23, //parameters[87]Forward Heavy Active Duration
		35, //parameters[88]Forward Heavy End Lag Duration
		1, //parameters[89]Forward Heavy Is Attached To Player
		0, //parameters[90] Is Player Attached To It
		0, //parameters[91]Forward Heavy Disappear On Hit

		15, //parameters[92]Up Heavy Additional x
		-20, //parameters[93]Up Heavy Additional y
		40, //parameters[94]Up Heavy Width
		20, //parameters[95]Up Heavy Height
		30, //parameters[96]Up Heavy Stun Duration
		3, //parameters[97]Up Heavy Scalar X
		-5, //parameters[98]Up Heavy Scalar y
		2, //parameters[99]Up Heavy Fixed x
		-4, //parameters[100]Up Heavy Fixed y
		1, //parameters[101]Up Heavy vx
		-10, //parameters[102]Up Heavy vy
		0, //parameters[103]Acceleration x
		0.7, //parameters[104]Acceleration y
		16.4, //parameters[105]Up Heavy Damage
		14, //parameters[106]Up Heavy Start Up Duraiton
		30, //parameters[107]Up Heavy Active Duration
		0, //parameters[108]Up Heavy End Lag Duration
		0, //parameters[109]Up Heavy Is Attached To Player
		1, //parameters[110] Is Player Attached To It
		0, //parameters[111]Up Heavy Disappear On Hit

		60, //parameters[112]Down Heavy Additional x
		20, //parameters[113]Down Heavy Additional y
		30, //parameters[114]Down Heavy Width
		15, //parameters[115]Down Heavy Height
		25, //parameters[116]Down Heavy Stun Duration
		8, //parameters[117]Down Heavy Scalar X
		-4, //parameters[118]Down Heavy Scalar y
		4, //parameters[119]Down Heavy Fixed x
		-1, //parameters[120]Down Heavy Fixed y
		5, //parameters[121]Down Heavy vx
		0, //parameters[122]Down Heavy vy
		-0.35, //parameters[123]Acceleration x
		0, //parameters[124]Acceleration y
		13, //parameters[125]Down Heavy Damage
		10, //parameters[126]Down Heavy Start Up Duraiton
		30, //parameters[127]Down Heavy Active Duration
		10, //parameters[128]Down Heavy End Lag Duration
		0, //parameters[129]Down Heavy Is Attached To Player
		1, //parameters[130] Is Player Attached To It
		0, //parameters[131]Down Heavy Disappear On Hit

		60, //parameters[132]Forward Aerial Additional x
		10, //parameters[133]Forward Aerial Additional y
		20, //parameters[134]Forward Aerial Width
		20, //parameters[135]Forward Aerial Height
		25, //parameters[136]Forward Aerial Stun Duration
		1, //parameters[137]Forward Aerial Scalar X
		15, //parameters[138]Forward Aerial Scalar y
		3, //parameters[139]Forward Aerial Fixed x
		2, //parameters[140]Forward Aerial Fixed y
		0, //parameters[141]Forward Aerial vx
		0, //parameters[142]Forward Aerial vy
		0, //parameters[143]Acceleration x
		0, //parameters[144]Acceleration y
		9.9, //parameters[145]Forward Aerial Damage
		12, //parameters[146]Forward Aerial Start Up Duraiton
		25, //parameters[147]Forward Aerial Active Duration
		13, //parameters[148]Forward Aerial End Lag Duration
		1, //parameters[149]Forward Aerial Is Attached To Player
		0, //parameters[150] Is Player Attached To It
		0, //parameters[151]Forward Aerial Disappear On Hit

		-20, //parameters[152]Back Aerial Additional x
		25, //parameters[153]Back Aerial Additional y
		30, //parameters[154]Back Aerial Width
		10, //parameters[155]Back Aerial Height
		15, //parameters[156]Back Aerial Stun Duration
		-8, //parameters[157]Back Aerial Scalar X
		-2, //parameters[158]Back Aerial Scalar y
		-2, //parameters[159]Back Aerial Fixed x
		-3, //parameters[160]Back Aerial Fixed y
		0, //parameters[161]Back Aerial vx
		0, //parameters[162]Back Aerial vy
		0, //parameters[163]Acceleration x
		0, //parameters[164]Acceleration y
		6.2, //parameters[165]Back Aerial Damage
		15, //parameters[166]Back Aerial Start Up Duraiton
		20, //parameters[167]Back Aerial Active Duration
		15, //parameters[168]Back Aerial End Lag Duration
		1, //parameters[169]Back Aerial Is Attached To Player
		0, //parameters[170] Is Player Attached To It
		0, //parameters[171]Back Aerial Disappear On Hit

		35, //parameters[172]Up Aerial Additional x
		10, //parameters[173]Up Aerial Additional y
		20, //parameters[174]Up Aerial Width
		15, //parameters[175]Up Aerial Height
		10, //parameters[176]Up Aerial Stun Duration
		1, //parameters[177]Up Aerial Scalar X
		-5, //parameters[178]Up Aerial Scalar y
		2, //parameters[179]Up Aerial Fixed x
		-3, //parameters[180]Up Aerial Fixed y
		0, //parameters[181]Up Aerial vx
		0, //parameters[182]Up Aerial vy
		0, //parameters[183]Acceleration x
		0, //parameters[184]Acceleration y
		4.6, //parameters[185]Up Aerial Damage
		10, //parameters[186]Up Aerial Start Up Duraiton
		30, //parameters[187]Up Aerial Active Duration
		7, //parameters[188]Up Aerial End Lag Duration
		1, //parameters[189]Up Aerial Is Attached To Player
		0, //parameters[190] Is Player Attached To It
		0, //parameters[191]Up Aerial Disappear On Hit

		50, //parameters[192]Down Aerial Additional x
		35, //parameters[193]Down Aerial Additional y
		30, //parameters[194]Down Aerial Width
		10, //parameters[195]Down Aerial Height
		26, //parameters[196]Down Aerial Stun Duration
		3, //parameters[197]Down Aerial Scalar X
		-3, //parameters[198]Down Aerial Scalar y
		1, //parameters[199]Down Aerial Fixed x
		-1, //parameters[200]Down Aerial Fixed y
		0, //parameters[201]Down Aerial vx
		0, //parameters[202]Down Aerial vy
		0, //parameters[203]Acceleration x
		0, //parameters[204]Acceleration y
		7.8, //parameters[205]Down Aerial Damage
		15, //parameters[206]Down Aerial Start Up Duraiton
		24, //parameters[207]Down Aerial Active Duration
		10, //parameters[208]Down Aerial End Lag Duration
		1, //parameters[209]Down Aerial Is Attached To Player
		0, //parameters[210] Is Player Attached To It
		0, //parameters[211]Down Aerial Disappear On Hit

		70, //parameters[212]Forward Special Additional x
		0, //parameters[213]Forward Special Additional y
		20, //parameters[214]Forward Special Width
		40, //parameters[215]Forward Special Height
		24, //parameters[216]Forward Special Stun Duration
		15, //parameters[217]Forward Special Scalar X
		-1, //parameters[218]Forward Special Scalar y
		3, //parameters[219]Forward Special Fixed x
		-3, //parameters[220]Forward Special Fixed y
		0, //parameters[221]Forward Special vx
		4, //parameters[222]Forward Special vy
		2, //parameters[223]Acceleration x
		0, //parameters[224]Acceleration y
		5, //parameters[225]Forward Special Damage
		5, //parameters[226]Forward Special Start Up Duraiton
		15, //parameters[227]Forward Special Active Duration
		30, //parameters[228]Forward Special End Lag Duration
		0, //parameters[229]Forward Special Is Attached To Player
		1, //parameters[230] Is Player Attached To It
		0, //parameters[231]Forward Special Disappear On Hit

		0, //parameters[232]Up Special Additional x
		-30, //parameters[233]Up Special Additional y
		10, //parameters[234]Up Special Width
		40, //parameters[235]Up Special Height
		20, //parameters[236]Up Special Stun Duration
		5, //parameters[237]Up Special Scalar X
		-7, //parameters[238]Up Special Scalar y
		3, //parameters[239]Up Special Fixed x
		-3, //parameters[240]Up Special Fixed y
		2, //parameters[241]Up Special vx
		-20, //parameters[242]Up Special vy
		0, //parameters[243]Acceleration x
		0, //parameters[244]Acceleration y
		5, //parameters[245]Up Special Damage
		10, //parameters[246]Up Special Start Up Duraiton
		5, //parameters[247]Up Special Active Duration
		10, //parameters[248]Up Special End Lag Duration
		0, //parameters[249]Up Special Is Attached To Player
		1, //parameters[250] Is Player Attached To It
		1, //parameters[251]Up Special Disappear On Hit

		-10, //parameters[252]Down Special Additional x
		-10, //parameters[253]Down Special Additional y
		90, //parameters[254]Down Special Width
		60, //parameters[255]Down Special Height
		20, //parameters[256]Down Special Stun Duration
		7, //parameters[257]Down Special Scalar X
		-3, //parameters[258]Down Special Scalar y
		2, //parameters[259]Down Special Fixed x
		-1, //parameters[260]Down Special Fixed y
		6, //parameters[261]Down Special vx
		0, //parameters[262]Down Special vy
		0, //parameters[263]Acceleration x
		0, //parameters[264]Acceleration y
		5, //parameters[265]Down Special Damage
		10, //parameters[266]Down Special Start Up Duraiton
		100, //parameters[267]Down Special Active Duration
		10, //parameters[268]Down Special End Lag Duration
		0, //parameters[269]Down Special Is Attached To Player
		1, //parameters[270] Is Player Attached To It
		1, //parameters[271]Down Special Disappear On Hit      
		255, //parameters[272]Forward Light R
		255, //parameters[273]Forward Light G
		255, //parameters[274]Forward Light B
		255, //parameters[275]
		255, //parameters[276]
		255, //parameters[277]
		255, //parameters[278]
		255, //parameters[279]
		255, //parameters[280]
		255, //parameters[281]
		255, //parameters[282]
		255, //parameters[283]
		255, //parameters[284]
		255, //parameters[285]
		255, //parameters[286]
		255, //parameters[287]
		255, //parameters[288]
		255, //parameters[289]
		255, //parameters[290]
		255, //parameters[291]
		255, //parameters[292]
		255, //parameters[293]
		255, //parameters[294]
		255, //parameters[295]
		255, //parameters[296]
		255, //parameters[297]
		255, //parameters[298]
		255, //parameters[299]
		255, //parameters[300]
		255, //parameters[301]
		255, //parameters[302]
		255, //parameters[303]
		255, //parameters[304]
		50, //parameters[305]
		50, //parameters[306]
		50, //parameters[307]
		255, //parameters[308]
		255, //parameters[309]
		255 //parameters[310]
	}, 
	//Chicken
	{
		150, //parameters[0]Width
		150, //parameters[1]Height
		7, //parameters[2]WalkSpeed
		4, //parameters[3]AerialSpeed
		4, //parameters[4]AerialAcceleration
		0.2, //parameters[5]WalkAcceleration
		30, //parameters[6]GroundedJumpHeight
		23, //parameters[7]AerialJumpHeight
		1.78, //parameters[8]FallAcceleration
		6, //parameters[9]FallSpeed
		1.2, //parameters[10]Weight
		2, //parameters[11]DoubleJumps

		150, //parameters[12]Forward Light Additional x
		65, //parameters[13]Forward Light Additional y
		30, //parameters[14]Forward Light Width
		20, //parameters[15]Forward Light Height
		15, //parameters[16]Forward Light Stun Duration
		4, //parameters[17]Forward Light Scalar X
		-5, //parameters[18]Forward Light Scalar y
		1.35, //parameters[19]Forward Light Fixed x
		3, //parameters[20]Forward Light Fixed y
		7, //parameters[21]Forward Light vx
		0, //parameters[22]Forward Light vy
		0, //parameters[23]Acceleration x
		0.1, //parameters[24]Acceleration y
		7.8, //parameters[25]Forward Light Damage
		14, //parameters[26]Forward Light Start Up Duraiton
		100, //parameters[27]Forward Light Active Duration
		30, //parameters[28]Forward Light End Lag Duration
		0, //parameters[29]Forward Light Is Attached To Player
		0, //parameters[30] Is Player Attached To It
		1, //parameters[31]Forward Light Disappear On Hit

		50, //parameters[32]Up Light Additional x
		10, //parameters[33]Up Light Additional y
		50, //parameters[34]Up Light Width
		10, //parameters[35]Up Light Height
		30, //parameters[36]Up Light Stun Duration
		2, //parameters[37]Up Light Scalar X
		-1, //parameters[38]Up Light Scalar y
		3, //parameters[39]Up Light Fixed x
		-3, //parameters[40]Up Light Fixed y
		0, //parameters[41]Up Light vx
		-7.5, //parameters[42]Up Light vy
		0, //parameters[43]Acceleration x
		0.2, //parameters[44]Acceleration y
		13.5, //parameters[45]Up Light Damage
		10, //parameters[46]Up Light Start Up Duraiton
		70, //parameters[47]Up Light Active Duration
		25, //parameters[48]Up Light End Lag Duration
		0, //parameters[49]Up Light Is Attached To Player
		0, //parameters[50] Is Player Attached To It
		1, //parameters[51]Up Light Disappear On Hit

		140, //parameters[52]Down Light Additional x
		140, //parameters[53]Down Light Additional y
		20, //parameters[54]Down Light Width
		10, //parameters[55]Down Light Height
		40, //parameters[56]Down Light Stun Duration
		8, //parameters[57]Down Light Scalar X
		-2, //parameters[58]Down Light Scalar y
		5, //parameters[59]Down Light Fixed x
		-1, //parameters[60]Down Light Fixed y
		1, //parameters[61]Down Light vx
		2, //parameters[62]Down Light vy
		0, //parameters[63]Acceleration x
		0, //parameters[64]Acceleration y
		10, //parameters[65]Down Light Damage
		10, //parameters[66]Down Light Start Up Duraiton
		300, //parameters[67]Down Light Active Duration
		9.7, //parameters[68]Down Light End Lag Duration
		0, //parameters[69]Down Light Is Attached To Player
		0, //parameters[70] Is Player Attached To It
		1, //parameters[71]Down Light Disappear On Hit

		150, //parameters[72]Forward Heavy Additional x
		0, //parameters[73]Forward Heavy Additional y
		10, //parameters[74]Forward Heavy Width
		150, //parameters[75]Forward Heavy Height
		30, //parameters[76]Forward Heavy Stun Duration
		17, //parameters[77]Forward Heavy Scalar X
		-2, //parameters[78]Forward Heavy Scalar y
		3, //parameters[79]Forward Heavy Fixed x
		-1, //parameters[80]Forward Heavy Fixed y
		1, //parameters[81]Forward Heavy vx
		0, //parameters[82]Forward Heavy vy
		0, //parameters[83]Acceleration x
		0, //parameters[84]Acceleration y
		25, //parameters[85]Forward Heavy Damage
		25, //parameters[86]Forward Heavy Start Up Duraiton
		200, //parameters[87]Forward Heavy Active Duration
		50, //parameters[88]Forward Heavy End Lag Duration
		0, //parameters[89]Forward Heavy Is Attached To Player
		0, //parameters[90] Is Player Attached To It
		1, //parameters[91]Forward Heavy Disappear On Hit

		0, //parameters[92]Up Heavy Additional x
		0, //parameters[93]Up Heavy Additional y
		150, //parameters[94]Up Heavy Width
		10, //parameters[95]Up Heavy Height
		30, //parameters[96]Up Heavy Stun Duration
		2, //parameters[97]Up Heavy Scalar X
		-17, //parameters[98]Up Heavy Scalar y
		1, //parameters[99]Up Heavy Fixed x
		-3, //parameters[100]Up Heavy Fixed y
		0, //parameters[101]Up Heavy vx
		-1, //parameters[102]Up Heavy vy
		0, //parameters[103]Acceleration x
		0, //parameters[104]Acceleration y
		14, //parameters[105]Up Heavy Damage
		25, //parameters[106]Up Heavy Start Up Duraiton
		200, //parameters[107]Up Heavy Active Duration
		50, //parameters[108]Up Heavy End Lag Duration
		0, //parameters[109]Up Heavy Is Attached To Player
		0, //parameters[110] Is Player Attached To It
		1, //parameters[111]Up Heavy Disappear On Hit

		65, //parameters[112]Down Heavy Additional x
		0, //parameters[113]Down Heavy Additional y
		10, //parameters[114]Down Heavy Width
		100, //parameters[115]Down Heavy Height
		40, //parameters[116]Down Heavy Stun Duration
		1, //parameters[117]Down Heavy Scalar X
		-5, //parameters[118]Down Heavy Scalar y
		1, //parameters[119]Down Heavy Fixed x
		-3, //parameters[120]Down Heavy Fixed y
		0, //parameters[121]Down Heavy vx
		0, //parameters[122]Down Heavy vy
		0, //parameters[123]Acceleration x
		-0.3, //parameters[124]Acceleration y
		26, //parameters[125]Down Heavy Damage
		12, //parameters[126]Down Heavy Start Up Duraiton
		100, //parameters[127]Down Heavy Active Duration
		25, //parameters[128]Down Heavy End Lag Duration
		0, //parameters[129]Down Heavy Is Attached To Player
		0, //parameters[130] Is Player Attached To It
		1, //parameters[131]Down Heavy Disappear On Hit

		130, //parameters[132]Forward Aerial Additional x
		55, //parameters[133]Forward Aerial Additional y
		30, //parameters[134]Forward Aerial Width
		40, //parameters[135]Forward Aerial Height
		15, //parameters[136]Forward Aerial Stun Duration
		3, //parameters[137]Forward Aerial Scalar X
		1, //parameters[138]Forward Aerial Scalar y
		3, //parameters[139]Forward Aerial Fixed x
		1, //parameters[140]Forward Aerial Fixed y
		4, //parameters[141]Forward Aerial vx
		0, //parameters[142]Forward Aerial vy
		0, //parameters[143]Acceleration x
		0.3, //parameters[144]Acceleration y
		10, //parameters[145]Forward Aerial Damage
		10, //parameters[146]Forward Aerial Start Up Duraiton
		30, //parameters[147]Forward Aerial Active Duration
		43, //parameters[148]Forward Aerial End Lag Duration
		0, //parameters[149]Forward Aerial Is Attached To Player
		0, //parameters[150] Is Player Attached To It
		1, //parameters[151]Forward Aerial Disappear On Hit

		-20, //parameters[152]Back Aerial Additional x
		130, //parameters[153]Back Aerial Additional y
		30, //parameters[154]Back Aerial Width
		20, //parameters[155]Back Aerial Height
		17, //parameters[156]Back Aerial Stun Duration
		-5, //parameters[157]Back Aerial Scalar X
		-1, //parameters[158]Back Aerial Scalar y
		-3, //parameters[159]Back Aerial Fixed x
		-7, //parameters[160]Back Aerial Fixed y
		-3, //parameters[161]Back Aerial vx
		-5, //parameters[162]Back Aerial vy
		0, //parameters[163]Acceleration x
		0.2, //parameters[164]Acceleration y
		10, //parameters[165]Back Aerial Damage
		10, //parameters[166]Back Aerial Start Up Duraiton
		30, //parameters[167]Back Aerial Active Duration
		10, //parameters[168]Back Aerial End Lag Duration
		0, //parameters[169]Back Aerial Is Attached To Player
		0, //parameters[170] Is Player Attached To It
		1, //parameters[171]Back Aerial Disappear On Hit

		130, //parameters[172]Up Aerial Additional x
		0, //parameters[173]Up Aerial Additional y
		40, //parameters[174]Up Aerial Width
		13, //parameters[175]Up Aerial Height
		14, //parameters[176]Up Aerial Stun Duration
		-7, //parameters[177]Up Aerial Scalar X
		-2, //parameters[178]Up Aerial Scalar y
		-3, //parameters[179]Up Aerial Fixed x
		-1, //parameters[180]Up Aerial Fixed y
		3, //parameters[181]Up Aerial vx
		3, //parameters[182]Up Aerial vy
		-0.1, //parameters[183]Acceleration x
		-0.3, //parameters[184]Acceleration y
		13, //parameters[185]Up Aerial Damage
		10, //parameters[186]Up Aerial Start Up Duraiton
		60, //parameters[187]Up Aerial Active Duration
		20, //parameters[188]Up Aerial End Lag Duration
		0, //parameters[189]Up Aerial Is Attached To Player
		0, //parameters[190] Is Player Attached To It
		1, //parameters[191]Up Aerial Disappear On Hit

		75, //parameters[192]Down Aerial Additional x
		75, //parameters[193]Down Aerial Additional y
		75, //parameters[194]Down Aerial Width
		75, //parameters[195]Down Aerial Height
		23, //parameters[196]Down Aerial Stun Duration
		2, //parameters[197]Down Aerial Scalar X
		7, //parameters[198]Down Aerial Scalar y
		3, //parameters[199]Down Aerial Fixed x
		5, //parameters[200]Down Aerial Fixed y
		0, //parameters[201]Down Aerial vx
		0, //parameters[202]Down Aerial vy
		0, //parameters[203]Acceleration x
		0, //parameters[204]Acceleration y
		13, //parameters[205]Down Aerial Damage
		16, //parameters[206]Down Aerial Start Up Duraiton
		30, //parameters[207]Down Aerial Active Duration
		7, //parameters[208]Down Aerial End Lag Duration
		1, //parameters[209]Down Aerial Is Attached To Player
		0, //parameters[210] Is Player Attached To It
		0, //parameters[211]Down Aerial Disappear On Hit

		150, //parameters[212]Forward Special Additional x
		70, //parameters[213]Forward Special Additional y
		300, //parameters[214]Forward Special Width
		10, //parameters[215]Forward Special Height
		40, //parameters[216]Forward Special Stun Duration
		0, //parameters[217]Forward Special Scalar X
		0, //parameters[218]Forward Special Scalar y
		-5, //parameters[219]Forward Special Fixed x
		-1, //parameters[220]Forward Special Fixed y
		2, //parameters[221]Forward Special vx
		0.5, //parameters[222]Forward Special vy
		0, //parameters[223]Acceleration x
		0, //parameters[224]Acceleration y
		5, //parameters[225]Forward Special Damage
		13, //parameters[226]Forward Special Start Up Duraiton
		1, //parameters[227]Forward Special Active Duration
		20, //parameters[228]Forward Special End Lag Duration
		1, //parameters[229]Forward Special Is Attached To Player
		0, //parameters[230] Is Player Attached To It
		0, //parameters[231]Forward Special Disappear On Hit

		130, //parameters[232]Up Special Additional x
		0, //parameters[233]Up Special Additional y
		40, //parameters[234]Up Special Width
		13, //parameters[235]Up Special Height
		14, //parameters[236]Up Special Stun Duration
		2, //parameters[237]Up Special Scalar X
		-2, //parameters[238]Up Special Scalar y
		6, //parameters[239]Up Special Fixed x
		-2, //parameters[240]Up Special Fixed y
		3, //parameters[241]Up Special vx
		3, //parameters[242]Up Special vy
		-0.1, //parameters[243]Acceleration x
		-0.3, //parameters[244]Acceleration y
		5, //parameters[245]Up Special Damage
		10, //parameters[246]Up Special Start Up Duraiton
		50, //parameters[247]Up Special Active Duration
		10, //parameters[248]Up Special End Lag Duration
		0, //parameters[249]Up Special Is Attached To Player
		1, //parameters[250] Is Player Attached To It
		0, //parameters[251]Up Special Disappear On Hit

		0, //parameters[252]Down Special Additional x
		149, //parameters[253]Down Special Additional y
		5, //parameters[254]Down Special Width
		5, //parameters[255]Down Special Height
		15, //parameters[256]Down Special Stun Duration
		1, //parameters[257]Down Special Scalar X
		-1, //parameters[258]Down Special Scalar y
		1, //parameters[259]Down Special Fixed x
		-1, //parameters[260]Down Special Fixed y
		0, //parameters[261]Down Special vx
		0, //parameters[262]Down Special vy
		0, //parameters[263]Acceleration x
		0, //parameters[264]Acceleration y
		5, //parameters[265]Down Special Damage
		0, //parameters[266]Down Special Start Up Duraiton
		1000, //parameters[267]Down Special Active Duration
		14, //parameters[268]Down Special End Lag Duration
		0, //parameters[269]Down Special Is Attached To Player
		0, //parameters[270] Is Player Attached To It
		1, //parameters[271]Down Special Disappear On Hit      
		255, //parameters[272]Forward Light R
		255, //parameters[273]Forward Light G
		255, //parameters[274]Forward Light B
		255, //parameters[275]
		255, //parameters[276]
		255, //parameters[277]
		255, //parameters[278]
		255, //parameters[279]
		255, //parameters[280]
		255, //parameters[281]
		255, //parameters[282]
		255, //parameters[283]
		255, //parameters[284]
		255, //parameters[285]
		255, //parameters[286]
		255, //parameters[287]
		255, //parameters[288]
		255, //parameters[289]
		255, //parameters[290]
		255, //parameters[291]
		255, //parameters[292]
		255, //parameters[293]
		255, //parameters[294]
		255, //parameters[295]
		255, //parameters[296]
		255, //parameters[297]
		255, //parameters[298]
		255, //parameters[299]
		255, //parameters[300]
		255, //parameters[301]
		255, //parameters[302]
		255, //parameters[303]
		255, //parameters[304]
		255, //parameters[305]
		255, //parameters[306]
		255, //parameters[307]
		255, //parameters[308]
		0, //parameters[309]
		255 //parameters[310]
	}, 
	//Rock
	{
		130, //parameters[0]Width
		100, //parameters[1]Height
		3, //parameters[2]WalkSpeed
		10, //parameters[3]AerialSpeed
		1, //parameters[4]AerialAcceleration
		1, //parameters[5]WalkAcceleration
		10, //parameters[6]GroundedJumpHeight
		10, //parameters[7]AerialJumpHeight
		1, //parameters[8]FallAcceleration
		30, //parameters[9]FallSpeed
		1.5, //parameters[10]Weight
		1, //parameters[11]DoubleJumps

		100, //parameters[12]Forward Light Additional x
		0, //parameters[13]Forward Light Additional y
		50, //parameters[14]Forward Light Width
		10, //parameters[15]Forward Light Height
		40, //parameters[16]Forward Light Stun Duration
		5, //parameters[17]Forward Light Scalar X
		-5, //parameters[18]Forward Light Scalar y
		3, //parameters[19]Forward Light Fixed x
		-3, //parameters[20]Forward Light Fixed y
		1, //parameters[21]Forward Light vx
		0, //parameters[22]Forward Light vy
		-0.1, //parameters[23]Acceleration x
		0, //parameters[24]Acceleration y
		14.2, //parameters[25]Forward Light Damage
		17, //parameters[26]Forward Light Start Up Duraiton
		40, //parameters[27]Forward Light Active Duration
		10, //parameters[28]Forward Light End Lag Duration
		0, //parameters[29]Forward Light Is Attached To Player
		1, //parameters[30] Is Player Attached To It
		0, //parameters[31]Forward Light Disappear On Hit

		70, //parameters[32]Up Light Additional x
		-30, //parameters[33]Up Light Additional y
		50, //parameters[34]Up Light Width
		30, //parameters[35]Up Light Height
		40, //parameters[36]Up Light Stun Duration
		4, //parameters[37]Up Light Scalar X
		-5, //parameters[38]Up Light Scalar y
		1, //parameters[39]Up Light Fixed x
		-3, //parameters[40]Up Light Fixed y
		-2.5, //parameters[41]Up Light vx
		0, //parameters[42]Up Light vy
		0, //parameters[43]Acceleration x
		0, //parameters[44]Acceleration y
		11.2, //parameters[45]Up Light Damage
		15, //parameters[46]Up Light Start Up Duraiton
		30, //parameters[47]Up Light Active Duration
		30, //parameters[48]Up Light End Lag Duration
		0, //parameters[49]Up Light Is Attached To Player
		1, //parameters[50] Is Player Attached To It
		0, //parameters[51]Up Light Disappear On Hit

		100, //parameters[52]Down Light Additional x
		90, //parameters[53]Down Light Additional y
		50, //parameters[54]Down Light Width
		10, //parameters[55]Down Light Height
		60, //parameters[56]Down Light Stun Duration
		0.5, //parameters[57]Down Light Scalar X
		-1, //parameters[58]Down Light Scalar y
		1, //parameters[59]Down Light Fixed x
		-2, //parameters[60]Down Light Fixed y
		0, //parameters[61]Down Light vx
		0, //parameters[62]Down Light vy
		0, //parameters[63]Acceleration x
		0, //parameters[64]Acceleration y
		6, //parameters[65]Down Light Damage
		23, //parameters[66]Down Light Start Up Duraiton
		10, //parameters[67]Down Light Active Duration
		20, //parameters[68]Down Light End Lag Duration
		1, //parameters[69]Down Light Is Attached To Player
		0, //parameters[70] Is Player Attached To It
		0, //parameters[71]Down Light Disappear On Hit

		0, //parameters[72]Forward Heavy Additional x
		0, //parameters[73]Forward Heavy Additional y
		150, //parameters[74]Forward Heavy Width
		100, //parameters[75]Forward Heavy Height
		20, //parameters[76]Forward Heavy Stun Duration
		13, //parameters[77]Forward Heavy Scalar X
		-2, //parameters[78]Forward Heavy Scalar y
		3, //parameters[79]Forward Heavy Fixed x
		-3, //parameters[80]Forward Heavy Fixed y
		5, //parameters[81]Forward Heavy vx
		0, //parameters[82]Forward Heavy vy
		-0.03, //parameters[83]Acceleration x
		0, //parameters[84]Acceleration y
		10, //parameters[85]Forward Heavy Damage
		25, //parameters[86]Forward Heavy Start Up Duraiton
		100, //parameters[87]Forward Heavy Active Duration
		25, //parameters[88]Forward Heavy End Lag Duration
		0, //parameters[89]Forward Heavy Is Attached To Player
		1, //parameters[90] Is Player Attached To It
		0, //parameters[91]Forward Heavy Disappear On Hit

		20, //parameters[92]Up Heavy Additional x
		0, //parameters[93]Up Heavy Additional y
		90, //parameters[94]Up Heavy Width
		10, //parameters[95]Up Heavy Height
		40, //parameters[96]Up Heavy Stun Duration
		4, //parameters[97]Up Heavy Scalar X
		-5, //parameters[98]Up Heavy Scalar y
		1, //parameters[99]Up Heavy Fixed x
		-3, //parameters[100]Up Heavy Fixed y
		0, //parameters[101]Up Heavy vx
		-3, //parameters[102]Up Heavy vy
		0, //parameters[103]Acceleration x
		0, //parameters[104]Acceleration y
		10, //parameters[105]Up Heavy Damage
		10, //parameters[106]Up Heavy Start Up Duraiton
		30, //parameters[107]Up Heavy Active Duration
		10, //parameters[108]Up Heavy End Lag Duration
		0, //parameters[109]Up Heavy Is Attached To Player
		1, //parameters[110] Is Player Attached To It
		0, //parameters[111]Up Heavy Disappear On Hit

		20, //parameters[112]Down Heavy Additional x
		80, //parameters[113]Down Heavy Additional y
		90, //parameters[114]Down Heavy Width
		20, //parameters[115]Down Heavy Height
		23, //parameters[116]Down Heavy Stun Duration
		4, //parameters[117]Down Heavy Scalar X
		3, //parameters[118]Down Heavy Scalar y
		4, //parameters[119]Down Heavy Fixed x
		3, //parameters[120]Down Heavy Fixed y
		0, //parameters[121]Down Heavy vx
		-28, //parameters[122]Down Heavy vy
		0, //parameters[123]Acceleration x
		2.5, //parameters[124]Acceleration y
		17.5, //parameters[125]Down Heavy Damage
		15, //parameters[126]Down Heavy Start Up Duraiton
		25, //parameters[127]Down Heavy Active Duration
		20, //parameters[128]Down Heavy End Lag Duration
		0, //parameters[129]Down Heavy Is Attached To Player
		1, //parameters[130] Is Player Attached To It
		0, //parameters[131]Down Heavy Disappear On Hit

		100, //parameters[132]Forward Aerial Additional x
		30, //parameters[133]Forward Aerial Additional y
		30, //parameters[134]Forward Aerial Width
		40, //parameters[135]Forward Aerial Height
		40, //parameters[136]Forward Aerial Stun Duration
		5, //parameters[137]Forward Aerial Scalar X
		-2, //parameters[138]Forward Aerial Scalar y
		3, //parameters[139]Forward Aerial Fixed x
		-1.5, //parameters[140]Forward Aerial Fixed y
		0, //parameters[141]Forward Aerial vx
		0, //parameters[142]Forward Aerial vy
		0, //parameters[143]Acceleration x
		0, //parameters[144]Acceleration y
		2, //parameters[145]Forward Aerial Damage
		10, //parameters[146]Forward Aerial Start Up Duraiton
		10, //parameters[147]Forward Aerial Active Duration
		10, //parameters[148]Forward Aerial End Lag Duration
		1, //parameters[149]Forward Aerial Is Attached To Player
		0, //parameters[150] Is Player Attached To It
		0, //parameters[151]Forward Aerial Disappear On Hit

		10, //parameters[152]Back Aerial Additional x
		90, //parameters[153]Back Aerial Additional y
		10, //parameters[154]Back Aerial Width
		10, //parameters[155]Back Aerial Height
		50, //parameters[156]Back Aerial Stun Duration
		-5, //parameters[157]Back Aerial Scalar X
		-2, //parameters[158]Back Aerial Scalar y
		-3, //parameters[159]Back Aerial Fixed x
		-1.5, //parameters[160]Back Aerial Fixed y
		0, //parameters[161]Back Aerial vx
		0, //parameters[162]Back Aerial vy
		0, //parameters[163]Acceleration x
		0, //parameters[164]Acceleration y
		23, //parameters[165]Back Aerial Damage
		10, //parameters[166]Back Aerial Start Up Duraiton
		10, //parameters[167]Back Aerial Active Duration
		10, //parameters[168]Back Aerial End Lag Duration
		1, //parameters[169]Back Aerial Is Attached To Player
		0, //parameters[170] Is Player Attached To It
		0, //parameters[171]Back Aerial Disappear On Hit

		20, //parameters[172]Up Aerial Additional x
		-10, //parameters[173]Up Aerial Additional y
		90, //parameters[174]Up Aerial Width
		10, //parameters[175]Up Aerial Height
		20, //parameters[176]Up Aerial Stun Duration
		1, //parameters[177]Up Aerial Scalar X
		-5, //parameters[178]Up Aerial Scalar y
		2, //parameters[179]Up Aerial Fixed x
		-3, //parameters[180]Up Aerial Fixed y
		0, //parameters[181]Up Aerial vx
		0, //parameters[182]Up Aerial vy
		0, //parameters[183]Acceleration x
		0, //parameters[184]Acceleration y
		7.2, //parameters[185]Up Aerial Damage
		16, //parameters[186]Up Aerial Start Up Duraiton
		19, //parameters[187]Up Aerial Active Duration
		10, //parameters[188]Up Aerial End Lag Duration
		1, //parameters[189]Up Aerial Is Attached To Player
		0, //parameters[190] Is Player Attached To It
		0, //parameters[191]Up Aerial Disappear On Hit

		20, //parameters[192]Down Aerial Additional x
		90, //parameters[193]Down Aerial Additional y
		90, //parameters[194]Down Aerial Width
		10, //parameters[195]Down Aerial Height
		20, //parameters[196]Down Aerial Stun Duration
		5, //parameters[197]Down Aerial Scalar X
		15, //parameters[198]Down Aerial Scalar y
		3, //parameters[199]Down Aerial Fixed x
		3, //parameters[200]Down Aerial Fixed y
		0, //parameters[201]Down Aerial vx
		-0.1, //parameters[202]Down Aerial vy
		0, //parameters[203]Acceleration x
		10, //parameters[204]Acceleration y
		10, //parameters[205]Down Aerial Damage
		10, //parameters[206]Down Aerial Start Up Duraiton
		8, //parameters[207]Down Aerial Active Duration
		10, //parameters[208]Down Aerial End Lag Duration
		0, //parameters[209]Down Aerial Is Attached To Player
		1, //parameters[210] Is Player Attached To It
		0, //parameters[211]Down Aerial Disappear On Hit

		130, //parameters[212]Forward Special Additional x
		45, //parameters[213]Forward Special Additional y
		10, //parameters[214]Forward Special Width
		10, //parameters[215]Forward Special Height
		10, //parameters[216]Forward Special Stun Duration
		4, //parameters[217]Forward Special Scalar X
		-0.5, //parameters[218]Forward Special Scalar y
		3, //parameters[219]Forward Special Fixed x
		-1.5, //parameters[220]Forward Special Fixed y
		1, //parameters[221]Forward Special vx
		-1, //parameters[222]Forward Special vy
		0, //parameters[223]Acceleration x
		0.015, //parameters[224]Acceleration y
		5, //parameters[225]Forward Special Damage
		10, //parameters[226]Forward Special Start Up Duraiton
		300, //parameters[227]Forward Special Active Duration
		35, //parameters[228]Forward Special End Lag Duration
		0, //parameters[229]Forward Special Is Attached To Player
		0, //parameters[230] Is Player Attached To It
		0, //parameters[231]Forward Special Disappear On Hit

		30, //parameters[232]Up Special Additional x
		50, //parameters[233]Up Special Additional y
		100, //parameters[234]Up Special Width
		50, //parameters[235]Up Special Height
		30, //parameters[236]Up Special Stun Duration
		1, //parameters[237]Up Special Scalar X
		10, //parameters[238]Up Special Scalar y
		1, //parameters[239]Up Special Fixed x
		3, //parameters[240]Up Special Fixed y
		3, //parameters[241]Up Special vx
		-50, //parameters[242]Up Special vy
		0.02, //parameters[243]Acceleration x
		2.5, //parameters[244]Acceleration y
		5, //parameters[245]Up Special Damage
		10, //parameters[246]Up Special Start Up Duraiton
		70, //parameters[247]Up Special Active Duration
		50, //parameters[248]Up Special End Lag Duration
		0, //parameters[249]Up Special Is Attached To Player
		1, //parameters[250] Is Player Attached To It
		0, //parameters[251]Up Special Disappear On Hit

		130, //parameters[252]Down Special Additional x
		0, //parameters[253]Down Special Additional y
		1, //parameters[254]Down Special Width
		5, //parameters[255]Down Special Height
		5, //parameters[256]Down Special Stun Duration
		1, //parameters[257]Down Special Scalar X
		0, //parameters[258]Down Special Scalar y
		0, //parameters[259]Down Special Fixed x
		0, //parameters[260]Down Special Fixed y
		2, //parameters[261]Down Special vx
		0, //parameters[262]Down Special vy
		0, //parameters[263]Acceleration x
		0, //parameters[264]Acceleration y
		0.1, //parameters[265]Down Special Damage
		5, //parameters[266]Down Special Start Up Duraiton
		2000, //parameters[267]Down Special Active Duration
		10, //parameters[268]Down Special End Lag Duration
		0, //parameters[269]Down Special Is Attached To Player
		0, //parameters[270] Is Player Attached To It
		1, //parameters[271]Down Special Disappear On Hit      
		255, //parameters[272]Forward Light R
		255, //parameters[273]Forward Light G
		255, //parameters[274]Forward Light B
		255, //parameters[275]
		255, //parameters[276]
		255, //parameters[277]
		255, //parameters[278]
		255, //parameters[279]
		255, //parameters[280]
		255, //parameters[281]
		255, //parameters[282]
		255, //parameters[283]
		255, //parameters[284]
		255, //parameters[285]
		255, //parameters[286]
		255, //parameters[287]
		255, //parameters[288]
		255, //parameters[289]
		255, //parameters[290]
		255, //parameters[291]
		255, //parameters[292]
		255, //parameters[293]
		255, //parameters[294]
		255, //parameters[295]
		255, //parameters[296]
		255, //parameters[297]
		255, //parameters[298]
		255, //parameters[299]
		255, //parameters[300]
		255, //parameters[301]
		255, //parameters[302]
		255, //parameters[303]
		255, //parameters[304]
		255, //parameters[305]
		255, //parameters[306]
		255, //parameters[307]
		255, //parameters[308]
		255, //parameters[309]
		255, //parameters[310]
	}, 
	//Troll
	{
		92, //parameters[0]Width
		66, //parameters[1]Height
		17, //parameters[2]WalkSpeed
		13, //parameters[3]AerialSpeed
		1.25, //parameters[4]AerialAcceleration
		0.75, //parameters[5]WalkAcceleration
		28, //parameters[6]GroundedJumpHeight
		33, //parameters[7]AerialJumpHeight
		1.25, //parameters[8]FallAcceleration
		15, //parameters[9]FallSpeed
		0.91, //parameters[10]Weight
		2, //parameters[11]DoubleJumps

		31, //parameters[12]Forward Light Additional x
		28, //parameters[13]Forward Light Additional y
		50, //parameters[14]Forward Light Width
		30, //parameters[15]Forward Light Height
		25, //parameters[16]Forward Light Stun Duration
		2, //parameters[17]Forward Light Scalar X
		0, //parameters[18]Forward Light Scalar y
		1, //parameters[19]Forward Light Fixed x
		-1, //parameters[20]Forward Light Fixed y
		0, //parameters[21]Forward Light vx
		0, //parameters[22]Forward Light vy
		0, //parameters[23]Acceleration x
		0, //parameters[24]Acceleration y
		8.6, //parameters[25]Forward Light Damage
		8, //parameters[26]Forward Light Start Up Duraiton
		14, //parameters[27]Forward Light Active Duration
		15, //parameters[28]Forward Light End Lag Duration
		1, //parameters[29]Forward Light Is Attached To Player
		0, //parameters[30] Is Player Attached To It
		0, //parameters[31]Forward Light Disappear On Hit

		52, //parameters[32]Up Light Additional x
		0, //parameters[33]Up Light Additional y
		48, //parameters[34]Up Light Width
		20, //parameters[35]Up Light Height
		15, //parameters[36]Up Light Stun Duration
		1, //parameters[37]Up Light Scalar X
		-1, //parameters[38]Up Light Scalar y
		3, //parameters[39]Up Light Fixed x
		-6, //parameters[40]Up Light Fixed y
		0, //parameters[41]Up Light vx
		0, //parameters[42]Up Light vy
		0, //parameters[43]Acceleration x
		0, //parameters[44]Acceleration y
		10, //parameters[45]Up Light Damage
		10, //parameters[46]Up Light Start Up Duraiton
		30, //parameters[47]Up Light Active Duration
		8, //parameters[48]Up Light End Lag Duration
		1, //parameters[49]Up Light Is Attached To Player
		0, //parameters[50] Is Player Attached To It
		0, //parameters[51]Up Light Disappear On Hit

		0, //parameters[52]Down Light Additional x
		51, //parameters[53]Down Light Additional y
		91, //parameters[54]Down Light Width
		10, //parameters[55]Down Light Height
		30, //parameters[56]Down Light Stun Duration
		0, //parameters[57]Down Light Scalar X
		4, //parameters[58]Down Light Scalar y
		5, //parameters[59]Down Light Fixed x
		0, //parameters[60]Down Light Fixed y
		0, //parameters[61]Down Light vx
		0, //parameters[62]Down Light vy
		0, //parameters[63]Acceleration x
		0, //parameters[64]Acceleration y
		0.1, //parameters[65]Down Light Damage
		10, //parameters[66]Down Light Start Up Duraiton
		10, //parameters[67]Down Light Active Duration
		10, //parameters[68]Down Light End Lag Duration
		1, //parameters[69]Down Light Is Attached To Player
		0, //parameters[70] Is Player Attached To It
		0, //parameters[71]Down Light Disappear On Hit

		61, //parameters[72]Forward Heavy Additional x
		15, //parameters[73]Forward Heavy Additional y
		30, //parameters[74]Forward Heavy Width
		30, //parameters[75]Forward Heavy Height
		35, //parameters[76]Forward Heavy Stun Duration
		17, //parameters[77]Forward Heavy Scalar X
		-7, //parameters[78]Forward Heavy Scalar y
		3, //parameters[79]Forward Heavy Fixed x
		-2, //parameters[80]Forward Heavy Fixed y
		0, //parameters[81]Forward Heavy vx
		0, //parameters[82]Forward Heavy vy
		0, //parameters[83]Acceleration x
		0, //parameters[84]Acceleration y
		13.5, //parameters[85]Forward Heavy Damage
		13, //parameters[86]Forward Heavy Start Up Duraiton
		17, //parameters[87]Forward Heavy Active Duration
		20, //parameters[88]Forward Heavy End Lag Duration
		1, //parameters[89]Forward Heavy Is Attached To Player
		0, //parameters[90] Is Player Attached To It
		0, //parameters[91]Forward Heavy Disappear On Hit

		5, //parameters[92]Up Heavy Additional x
		0, //parameters[93]Up Heavy Additional y
		50, //parameters[94]Up Heavy Width
		4, //parameters[95]Up Heavy Height
		27, //parameters[96]Up Heavy Stun Duration
		7, //parameters[97]Up Heavy Scalar X
		-15, //parameters[98]Up Heavy Scalar y
		2, //parameters[99]Up Heavy Fixed x
		-2, //parameters[100]Up Heavy Fixed y
		0, //parameters[101]Up Heavy vx
		0, //parameters[102]Up Heavy vy
		0, //parameters[103]Acceleration x
		0, //parameters[104]Acceleration y
		15.2, //parameters[105]Up Heavy Damage
		18, //parameters[106]Up Heavy Start Up Duraiton
		30, //parameters[107]Up Heavy Active Duration
		10, //parameters[108]Up Heavy End Lag Duration
		1, //parameters[109]Up Heavy Is Attached To Player
		0, //parameters[110] Is Player Attached To It
		0, //parameters[111]Up Heavy Disappear On Hit

		51, //parameters[112]Down Heavy Additional x
		43, //parameters[113]Down Heavy Additional y
		40, //parameters[114]Down Heavy Width
		20, //parameters[115]Down Heavy Height
		31, //parameters[116]Down Heavy Stun Duration
		10, //parameters[117]Down Heavy Scalar X
		-10, //parameters[118]Down Heavy Scalar y
		5, //parameters[119]Down Heavy Fixed x
		-5, //parameters[120]Down Heavy Fixed y
		0, //parameters[121]Down Heavy vx
		0, //parameters[122]Down Heavy vy
		0, //parameters[123]Acceleration x
		0, //parameters[124]Acceleration y
		17.1, //parameters[125]Down Heavy Damage
		19, //parameters[126]Down Heavy Start Up Duraiton
		25, //parameters[127]Down Heavy Active Duration
		20, //parameters[128]Down Heavy End Lag Duration
		1, //parameters[129]Down Heavy Is Attached To Player
		0, //parameters[130] Is Player Attached To It
		0, //parameters[131]Down Heavy Disappear On Hit

		61, //parameters[132]Forward Aerial Additional x
		20, //parameters[133]Forward Aerial Additional y
		30, //parameters[134]Forward Aerial Width
		30, //parameters[135]Forward Aerial Height
		25, //parameters[136]Forward Aerial Stun Duration
		5, //parameters[137]Forward Aerial Scalar X
		8, //parameters[138]Forward Aerial Scalar y
		2, //parameters[139]Forward Aerial Fixed x
		3, //parameters[140]Forward Aerial Fixed y
		0, //parameters[141]Forward Aerial vx
		0, //parameters[142]Forward Aerial vy
		0, //parameters[143]Acceleration x
		0, //parameters[144]Acceleration y
		7.1, //parameters[145]Forward Aerial Damage
		11, //parameters[146]Forward Aerial Start Up Duraiton
		11, //parameters[147]Forward Aerial Active Duration
		11, //parameters[148]Forward Aerial End Lag Duration
		1, //parameters[149]Forward Aerial Is Attached To Player
		0, //parameters[150] Is Player Attached To It
		0, //parameters[151]Forward Aerial Disappear On Hit

		0, //parameters[152]Back Aerial Additional x
		10, //parameters[153]Back Aerial Additional y
		30, //parameters[154]Back Aerial Width
		40, //parameters[155]Back Aerial Height
		40, //parameters[156]Back Aerial Stun Duration
		-3, //parameters[157]Back Aerial Scalar X
		-1, //parameters[158]Back Aerial Scalar y
		-5, //parameters[159]Back Aerial Fixed x
		-1, //parameters[160]Back Aerial Fixed y
		0, //parameters[161]Back Aerial vx
		0, //parameters[162]Back Aerial vy
		0, //parameters[163]Acceleration x
		0, //parameters[164]Acceleration y
		8.6, //parameters[165]Back Aerial Damage
		17, //parameters[166]Back Aerial Start Up Duraiton
		23, //parameters[167]Back Aerial Active Duration
		14, //parameters[168]Back Aerial End Lag Duration
		1, //parameters[169]Back Aerial Is Attached To Player
		0, //parameters[170] Is Player Attached To It
		0, //parameters[171]Back Aerial Disappear On Hit

		10, //parameters[172]Up Aerial Additional x
		0, //parameters[173]Up Aerial Additional y
		71, //parameters[174]Up Aerial Width
		4, //parameters[175]Up Aerial Height
		17, //parameters[176]Up Aerial Stun Duration
		1, //parameters[177]Up Aerial Scalar X
		-3, //parameters[178]Up Aerial Scalar y
		1, //parameters[179]Up Aerial Fixed x
		-3, //parameters[180]Up Aerial Fixed y
		0, //parameters[181]Up Aerial vx
		0, //parameters[182]Up Aerial vy
		0, //parameters[183]Acceleration x
		0, //parameters[184]Acceleration y
		6.3, //parameters[185]Up Aerial Damage
		7, //parameters[186]Up Aerial Start Up Duraiton
		17, //parameters[187]Up Aerial Active Duration
		8, //parameters[188]Up Aerial End Lag Duration
		1, //parameters[189]Up Aerial Is Attached To Player
		0, //parameters[190] Is Player Attached To It
		0, //parameters[191]Up Aerial Disappear On Hit

		0, //parameters[192]Down Aerial Additional x
		90, //parameters[193]Down Aerial Additional y
		91, //parameters[194]Down Aerial Width
		10, //parameters[195]Down Aerial Height
		30, //parameters[196]Down Aerial Stun Duration
		0, //parameters[197]Down Aerial Scalar X
		4, //parameters[198]Down Aerial Scalar y
		5, //parameters[199]Down Aerial Fixed x
		0, //parameters[200]Down Aerial Fixed y
		0, //parameters[201]Down Aerial vx
		0, //parameters[202]Down Aerial vy
		0, //parameters[203]Acceleration x
		0, //parameters[204]Acceleration y
		0.1, //parameters[205]Down Aerial Damage
		10, //parameters[206]Down Aerial Start Up Duraiton
		10, //parameters[207]Down Aerial Active Duration
		10, //parameters[208]Down Aerial End Lag Duration
		1, //parameters[209]Down Aerial Is Attached To Player
		0, //parameters[210] Is Player Attached To It
		0, //parameters[211]Down Aerial Disappear On Hit

		0, //parameters[212]Forward Special Additional x
		0, //parameters[213]Forward Special Additional y
		91, //parameters[214]Forward Special Width
		63, //parameters[215]Forward Special Height
		33, //parameters[216]Forward Special Stun Duration
		13, //parameters[217]Forward Special Scalar X
		-1, //parameters[218]Forward Special Scalar y
		3, //parameters[219]Forward Special Fixed x
		-3, //parameters[220]Forward Special Fixed y
		400, //parameters[221]Forward Special vx
		0, //parameters[222]Forward Special vy
		-400, //parameters[223]Acceleration x
		0, //parameters[224]Acceleration y
		15, //parameters[225]Forward Special Damage
		10, //parameters[226]Forward Special Start Up Duraiton
		2, //parameters[227]Forward Special Active Duration
		50, //parameters[228]Forward Special End Lag Duration
		0, //parameters[229]Forward Special Is Attached To Player
		1, //parameters[230] Is Player Attached To It
		0, //parameters[231]Forward Special Disappear On Hit

		71, //parameters[232]Up Special Additional x
		0, //parameters[233]Up Special Additional y
		20, //parameters[234]Up Special Width
		61, //parameters[235]Up Special Height
		26, //parameters[236]Up Special Stun Duration
		4, //parameters[237]Up Special Scalar X
		-13, //parameters[238]Up Special Scalar y
		1, //parameters[239]Up Special Fixed x
		-3, //parameters[240]Up Special Fixed y
		3, //parameters[241]Up Special vx
		-10, //parameters[242]Up Special vy
		0, //parameters[243]Acceleration x
		-0.4, //parameters[244]Acceleration y
		5, //parameters[245]Up Special Damage
		6, //parameters[246]Up Special Start Up Duraiton
		17, //parameters[247]Up Special Active Duration
		20, //parameters[248]Up Special End Lag Duration
		0, //parameters[249]Up Special Is Attached To Player
		1, //parameters[250] Is Player Attached To It
		0, //parameters[251]Up Special Disappear On Hit

		50, //parameters[252]Down Special Additional x
		15, //parameters[253]Down Special Additional y
		10, //parameters[254]Down Special Width
		1, //parameters[255]Down Special Height
		120, //parameters[256]Down Special Stun Duration
		0, //parameters[257]Down Special Scalar X
		0, //parameters[258]Down Special Scalar y
		0, //parameters[259]Down Special Fixed x
		0, //parameters[260]Down Special Fixed y
		10, //parameters[261]Down Special vx
		0, //parameters[262]Down Special vy
		0, //parameters[263]Acceleration x
		0, //parameters[264]Acceleration y
		0, //parameters[265]Down Special Damage
		16, //parameters[266]Down Special Start Up Duraiton
		6, //parameters[267]Down Special Active Duration
		29, //parameters[268]Down Special End Lag Duration
		0, //parameters[269]Down Special Is Attached To Player
		0, //parameters[270] Is Player Attached To It
		1, //parameters[271]Down Special Disappear On Hit      
		0, //parameters[272]Forward Light R
		0, //parameters[273]Forward Light G
		0, //parameters[274]Forward Light B
		255, //parameters[275]
		255, //parameters[276]
		255, //parameters[277]
		255, //parameters[278]
		255, //parameters[279]
		255, //parameters[280]
		255, //parameters[281]
		255, //parameters[282]
		255, //parameters[283]
		255, //parameters[284]
		255, //parameters[285]
		255, //parameters[286]
		255, //parameters[287]
		255, //parameters[288]
		255, //parameters[289]
		0, //parameters[290]
		255, //parameters[291]
		255, //parameters[292]
		255, //parameters[293]
		255, //parameters[294]
		255, //parameters[295]
		255, //parameters[296]
		255, //parameters[297]
		255, //parameters[298]
		255, //parameters[299]
		255, //parameters[300]
		255, //parameters[301]
		255, //parameters[302]
		255, //parameters[303]
		255, //parameters[304]
		255, //parameters[305]
		255, //parameters[306]
		255, //parameters[307]
		255, //parameters[308]
		255, //parameters[309]
		255 //parameters[310]
	}, 
	//Big B
	{
		89, //parameters[0]Width
		102, //parameters[1]Height
		3, //parameters[2]WalkSpeed
		5, //parameters[3]AerialSpeed
		10, //parameters[4]AerialAcceleration
		2, //parameters[5]WalkAcceleration
		30, //parameters[6]GroundedJumpHeight
		26, //parameters[7]AerialJumpHeight
		1.75, //parameters[8]FallAcceleration
		10, //parameters[9]FallSpeed
		1.5, //parameters[10]Weight
		1, //parameters[11]DoubleJumps

		89, //parameters[12]Forward Light Additional x
		0, //parameters[13]Forward Light Additional y
		89, //parameters[14]Forward Light Width
		102, //parameters[15]Forward Light Height
		24, //parameters[16]Forward Light Stun Duration
		6, //parameters[17]Forward Light Scalar X
		1, //parameters[18]Forward Light Scalar y
		3, //parameters[19]Forward Light Fixed x
		1, //parameters[20]Forward Light Fixed y
		0, //parameters[21]Forward Light vx
		0, //parameters[22]Forward Light vy
		0, //parameters[23]Acceleration x
		0, //parameters[24]Acceleration y
		5.3, //parameters[25]Forward Light Damage
		12, //parameters[26]Forward Light Start Up Duraiton
		30, //parameters[27]Forward Light Active Duration
		30, //parameters[28]Forward Light End Lag Duration
		1, //parameters[29]Forward Light Is Attached To Player
		0, //parameters[30] Is Player Attached To It
		0, //parameters[31]Forward Light Disappear On Hit

		39, //parameters[32]Up Light Additional x
		-100, //parameters[33]Up Light Additional y
		2, //parameters[34]Up Light Width
		106, //parameters[35]Up Light Height
		30, //parameters[36]Up Light Stun Duration
		2, //parameters[37]Up Light Scalar X
		-12, //parameters[38]Up Light Scalar y
		1, //parameters[39]Up Light Fixed x
		-10, //parameters[40]Up Light Fixed y
		0, //parameters[41]Up Light vx
		0, //parameters[42]Up Light vy
		0, //parameters[43]Acceleration x
		0, //parameters[44]Acceleration y
		1, //parameters[45]Up Light Damage
		14, //parameters[46]Up Light Start Up Duraiton
		35, //parameters[47]Up Light Active Duration
		11, //parameters[48]Up Light End Lag Duration
		1, //parameters[49]Up Light Is Attached To Player
		0, //parameters[50] Is Player Attached To It
		0, //parameters[51]Up Light Disappear On Hit

		66, //parameters[52]Down Light Additional x
		90, //parameters[53]Down Light Additional y
		40, //parameters[54]Down Light Width
		12, //parameters[55]Down Light Height
		50, //parameters[56]Down Light Stun Duration
		0, //parameters[57]Down Light Scalar X
		-5, //parameters[58]Down Light Scalar y
		0, //parameters[59]Down Light Fixed x
		-3, //parameters[60]Down Light Fixed y
		0, //parameters[61]Down Light vx
		0, //parameters[62]Down Light vy
		0, //parameters[63]Acceleration x
		0, //parameters[64]Acceleration y
		20, //parameters[65]Down Light Damage
		10, //parameters[66]Down Light Start Up Duraiton
		30, //parameters[67]Down Light Active Duration
		40, //parameters[68]Down Light End Lag Duration
		1, //parameters[69]Down Light Is Attached To Player
		0, //parameters[70] Is Player Attached To It
		0, //parameters[71]Down Light Disappear On Hit

		89, //parameters[72]Forward Heavy Additional x
		40, //parameters[73]Forward Heavy Additional y
		100, //parameters[74]Forward Heavy Width
		20, //parameters[75]Forward Heavy Height
		27, //parameters[76]Forward Heavy Stun Duration
		16, //parameters[77]Forward Heavy Scalar X
		-6, //parameters[78]Forward Heavy Scalar y
		2, //parameters[79]Forward Heavy Fixed x
		-3, //parameters[80]Forward Heavy Fixed y
		0, //parameters[81]Forward Heavy vx
		0, //parameters[82]Forward Heavy vy
		0, //parameters[83]Acceleration x
		0, //parameters[84]Acceleration y
		15.7, //parameters[85]Forward Heavy Damage
		16, //parameters[86]Forward Heavy Start Up Duraiton
		30, //parameters[87]Forward Heavy Active Duration
		19, //parameters[88]Forward Heavy End Lag Duration
		1, //parameters[89]Forward Heavy Is Attached To Player
		0, //parameters[90] Is Player Attached To It
		0, //parameters[91]Forward Heavy Disappear On Hit

		10, //parameters[92]Up Heavy Additional x
		-10, //parameters[93]Up Heavy Additional y
		69, //parameters[94]Up Heavy Width
		20, //parameters[95]Up Heavy Height
		34, //parameters[96]Up Heavy Stun Duration
		0, //parameters[97]Up Heavy Scalar X
		-3, //parameters[98]Up Heavy Scalar y
		0, //parameters[99]Up Heavy Fixed x
		-3, //parameters[100]Up Heavy Fixed y
		0, //parameters[101]Up Heavy vx
		0, //parameters[102]Up Heavy vy
		0, //parameters[103]Acceleration x
		0, //parameters[104]Acceleration y
		3, //parameters[105]Up Heavy Damage
		6, //parameters[106]Up Heavy Start Up Duraiton
		18, //parameters[107]Up Heavy Active Duration
		20, //parameters[108]Up Heavy End Lag Duration
		1, //parameters[109]Up Heavy Is Attached To Player
		0, //parameters[110] Is Player Attached To It
		0, //parameters[111]Up Heavy Disappear On Hit

		10, //parameters[112]Down Heavy Additional x
		82, //parameters[113]Down Heavy Additional y
		69, //parameters[114]Down Heavy Width
		20, //parameters[115]Down Heavy Height
		34, //parameters[116]Down Heavy Stun Duration
		1, //parameters[117]Down Heavy Scalar X
		-5, //parameters[118]Down Heavy Scalar y
		1, //parameters[119]Down Heavy Fixed x
		-3, //parameters[120]Down Heavy Fixed y
		0, //parameters[121]Down Heavy vx
		0, //parameters[122]Down Heavy vy
		0, //parameters[123]Acceleration x
		0, //parameters[124]Acceleration y
		3, //parameters[125]Down Heavy Damage
		6, //parameters[126]Down Heavy Start Up Duraiton
		18, //parameters[127]Down Heavy Active Duration
		20, //parameters[128]Down Heavy End Lag Duration
		1, //parameters[129]Down Heavy Is Attached To Player
		0, //parameters[130] Is Player Attached To It
		0, //parameters[131]Down Heavy Disappear On Hit

		79, //parameters[132]Forward Aerial Additional x
		20, //parameters[133]Forward Aerial Additional y
		30, //parameters[134]Forward Aerial Width
		30, //parameters[135]Forward Aerial Height
		34, //parameters[136]Forward Aerial Stun Duration
		1, //parameters[137]Forward Aerial Scalar X
		-5, //parameters[138]Forward Aerial Scalar y
		2, //parameters[139]Forward Aerial Fixed x
		-3, //parameters[140]Forward Aerial Fixed y
		10, //parameters[141]Forward Aerial vx
		0, //parameters[142]Forward Aerial vy
		0, //parameters[143]Acceleration x
		0, //parameters[144]Acceleration y
		3.1, //parameters[145]Forward Aerial Damage
		10, //parameters[146]Forward Aerial Start Up Duraiton
		30, //parameters[147]Forward Aerial Active Duration
		15, //parameters[148]Forward Aerial End Lag Duration
		0, //parameters[149]Forward Aerial Is Attached To Player
		1, //parameters[150] Is Player Attached To It
		0, //parameters[151]Forward Aerial Disappear On Hit

		-100, //parameters[152]Back Aerial Additional x
		67, //parameters[153]Back Aerial Additional y
		110, //parameters[154]Back Aerial Width
		30, //parameters[155]Back Aerial Height
		19, //parameters[156]Back Aerial Stun Duration
		-10, //parameters[157]Back Aerial Scalar X
		-5, //parameters[158]Back Aerial Scalar y
		-3, //parameters[159]Back Aerial Fixed x
		-3, //parameters[160]Back Aerial Fixed y
		0, //parameters[161]Back Aerial vx
		0, //parameters[162]Back Aerial vy
		0, //parameters[163]Acceleration x
		0, //parameters[164]Acceleration y
		7.6, //parameters[165]Back Aerial Damage
		5, //parameters[166]Back Aerial Start Up Duraiton
		10, //parameters[167]Back Aerial Active Duration
		23, //parameters[168]Back Aerial End Lag Duration
		1, //parameters[169]Back Aerial Is Attached To Player
		0, //parameters[170] Is Player Attached To It
		0, //parameters[171]Back Aerial Disappear On Hit

		39, //parameters[172]Up Aerial Additional x
		-100, //parameters[173]Up Aerial Additional y
		2, //parameters[174]Up Aerial Width
		106, //parameters[175]Up Aerial Height
		30, //parameters[176]Up Aerial Stun Duration
		2, //parameters[177]Up Aerial Scalar X
		-8, //parameters[178]Up Aerial Scalar y
		1, //parameters[179]Up Aerial Fixed x
		-10, //parameters[180]Up Aerial Fixed y
		0, //parameters[181]Up Aerial vx
		0, //parameters[182]Up Aerial vy
		0, //parameters[183]Acceleration x
		0, //parameters[184]Acceleration y
		1, //parameters[185]Up Aerial Damage
		14, //parameters[186]Up Aerial Start Up Duraiton
		35, //parameters[187]Up Aerial Active Duration
		11, //parameters[188]Up Aerial End Lag Duration
		1, //parameters[189]Up Aerial Is Attached To Player
		0, //parameters[190] Is Player Attached To It
		0, //parameters[191]Up Aerial Disappear On Hit

		10, //parameters[192]Down Aerial Additional x
		82, //parameters[193]Down Aerial Additional y
		69, //parameters[194]Down Aerial Width
		20, //parameters[195]Down Aerial Height
		50, //parameters[196]Down Aerial Stun Duration
		1, //parameters[197]Down Aerial Scalar X
		5, //parameters[198]Down Aerial Scalar y
		1, //parameters[199]Down Aerial Fixed x
		3, //parameters[200]Down Aerial Fixed y
		0, //parameters[201]Down Aerial vx
		-1, //parameters[202]Down Aerial vy
		0, //parameters[203]Acceleration x
		0.3, //parameters[204]Acceleration y
		5.9, //parameters[205]Down Aerial Damage
		5, //parameters[206]Down Aerial Start Up Duraiton
		50, //parameters[207]Down Aerial Active Duration
		30, //parameters[208]Down Aerial End Lag Duration
		0, //parameters[209]Down Aerial Is Attached To Player
		1, //parameters[210] Is Player Attached To It
		0, //parameters[211]Down Aerial Disappear On Hit

		10, //parameters[212]Forward Special Additional x
		-10, //parameters[213]Forward Special Additional y
		40, //parameters[214]Forward Special Width
		60, //parameters[215]Forward Special Height
		5, //parameters[216]Forward Special Stun Duration
		20, //parameters[217]Forward Special Scalar X
		5, //parameters[218]Forward Special Scalar y
		5, //parameters[219]Forward Special Fixed x
		-3, //parameters[220]Forward Special Fixed y
		2, //parameters[221]Forward Special vx
		0.5, //parameters[222]Forward Special vy
		0.1, //parameters[223]Acceleration x
		0, //parameters[224]Acceleration y
		15.2, //parameters[225]Forward Special Damage
		20, //parameters[226]Forward Special Start Up Duraiton
		50, //parameters[227]Forward Special Active Duration
		30, //parameters[228]Forward Special End Lag Duration
		1, //parameters[229]Forward Special Is Attached To Player
		1, //parameters[230] Is Player Attached To It
		0, //parameters[231]Forward Special Disappear On Hit

		10, //parameters[232]Up Special Additional x
		0, //parameters[233]Up Special Additional y
		69, //parameters[234]Up Special Width
		30, //parameters[235]Up Special Height
		30, //parameters[236]Up Special Stun Duration
		0, //parameters[237]Up Special Scalar X
		0, //parameters[238]Up Special Scalar y
		6, //parameters[239]Up Special Fixed x
		-3, //parameters[240]Up Special Fixed y
		5, //parameters[241]Up Special vx
		-1, //parameters[242]Up Special vy
		0, //parameters[243]Acceleration x
		0, //parameters[244]Acceleration y
		0, //parameters[245]Up Special Damage
		10, //parameters[246]Up Special Start Up Duraiton
		50, //parameters[247]Up Special Active Duration
		20, //parameters[248]Up Special End Lag Duration
		0, //parameters[249]Up Special Is Attached To Player
		1, //parameters[250] Is Player Attached To It
		0, //parameters[251]Up Special Disappear On Hit

		0, //parameters[252]Down Special Additional x
		0, //parameters[253]Down Special Additional y
		0, //parameters[254]Down Special Width
		0, //parameters[255]Down Special Height
		0, //parameters[256]Down Special Stun Duration
		0, //parameters[257]Down Special Scalar X
		0, //parameters[258]Down Special Scalar y
		0, //parameters[259]Down Special Fixed x
		0, //parameters[260]Down Special Fixed y
		0, //parameters[261]Down Special vx
		-20, //parameters[262]Down Special vy
		0, //parameters[263]Acceleration x
		0, //parameters[264]Acceleration y
		0, //parameters[265]Down Special Damage
		10, //parameters[266]Down Special Start Up Duraiton
		10, //parameters[267]Down Special Active Duration
		20, //parameters[268]Down Special End Lag Duration
		0, //parameters[269]Down Special Is Attached To Player
		1, //parameters[270] Is Player Attached To It
		0, //parameters[271]Down Special Disappear On Hit    
		255, //parameters[272]Forward Light R
		255, //parameters[273]Forward Light G
		255, //parameters[274]Forward Light B
		255, //parameters[275]
		255, //parameters[276]
		255, //parameters[277]
		255, //parameters[278]
		255, //parameters[279]
		255, //parameters[280]
		255, //parameters[281]
		255, //parameters[282]
		255, //parameters[283]
		255, //parameters[284]
		255, //parameters[285]
		255, //parameters[286]
		255, //parameters[287]
		255, //parameters[288]
		255, //parameters[289]
		255, //parameters[290]
		255, //parameters[291]
		255, //parameters[292]
		255, //parameters[293]
		255, //parameters[294]
		255, //parameters[295]
		255, //parameters[296]
		255, //parameters[297]
		255, //parameters[298]
		255, //parameters[299]
		255, //parameters[300]
		255, //parameters[301]
		255, //parameters[302]
		255, //parameters[303]
		255, //parameters[304]
		255, //parameters[305]
		255, //parameters[306]
		255, //parameters[307]
		255, //parameters[308]
		255, //parameters[309]
		255 //parameters[310]  
	}
	};
};