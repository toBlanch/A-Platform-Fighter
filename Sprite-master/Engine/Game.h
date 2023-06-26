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

class Game
{
public:
	Game(class MainWindow& wnd);
	Game(const Game&) = delete;
	Game& operator=(const Game&) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel();
	/********************************/
	/*  User Functions              */
	/********************************/

private:
	MainWindow& wnd;
	Graphics gfx;
	/********************************/
	/*  User Variables              */
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
	bool startMenu = true;
	bool paused = false;
	bool enterOrEscapeHeld = false;
	bool qHeld = false;
	bool eHeld = false;
	bool iHeld = false;
	bool pHeld = false;

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

	Surface cycling = { "Images\\Cycling.bmp" };
	Surface controls1 = { "Images\\Player1Controls.bmp" };
	Surface controls2 = { "Images\\Player2Controls.bmp" };
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
	Surface pauseMenu = { "Images\\Pause Menu.bmp" };
	Surface player1Win = { "Images\\Player1Win.bmp" };
	Surface player2Win = { "Images\\Player2Win.bmp" };
	Character Player1;
	Character Player2;
	/********************************/
	std::vector<std::vector<float>> parameters = {
	{ //CharacterCircle
		100, //parameters[0]Width
		100, //parameters[1]Height
		10, //parameters[2]WalkSpeed
		10, //parameters[3]AerialSpeed
		1, //parameters[4]AerialAcceleration
		1, //parameters[5]WalkAcceleration
		20, //parameters[6]GronudedJumpHeight
		25, //parameters[7]AerialJumpHeight
		1, //parameters[8]FallAcceleration
		10, //parameters[9]FallSpeed
		1, //parameters[10]Weight
		2, //parameters[11]DoubleJumps

		50, //parameters[12]Forward Light Additional x
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

		50, //parameters[32]Up Light Additional x
		0, //parameters[33]Up Light Additional y
		50, //parameters[34]Up Light Width
		10, //parameters[35]Up Light Height
		40, //parameters[36]Up Light Stun Duration
		5, //parameters[37]Up Light Scalar X
		-5, //parameters[38]Up Light Scalar y
		3, //parameters[39]Up Light Fixed x
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

		50, //parameters[52]Down Light Additional x
		0, //parameters[53]Down Light Additional y
		50, //parameters[54]Down Light Width
		10, //parameters[55]Down Light Height
		40, //parameters[56]Down Light Stun Duration
		5, //parameters[57]Down Light Scalar X
		-5, //parameters[58]Down Light Scalar y
		3, //parameters[59]Down Light Fixed x
		-3, //parameters[60]Down Light Fixed y
		0, //parameters[61]Down Light vx
		0, //parameters[62]Down Light vy
		0, //parameters[63]Acceleration x
		0, //parameters[64]Acceleration y
		10, //parameters[65]Down Light Damage
		10, //parameters[66]Down Light Start Up Duraiton
		30, //parameters[67]Down Light Active Duration
		10, //parameters[68]Down Light End Lag Duration
		1, //parameters[69]Down Light Is Attached To Player
		0, //parameters[70] Is Player Attached To It
		0, //parameters[71]Down Light Disappear On Hit

		50, //parameters[72]Forward Heavy Additional x
		0, //parameters[73]Forward Heavy Additional y
		50, //parameters[74]Forward Heavy Width
		10, //parameters[75]Forward Heavy Height
		40, //parameters[76]Forward Heavy Stun Duration
		5, //parameters[77]Forward Heavy Scalar X
		-5, //parameters[78]Forward Heavy Scalar y
		3, //parameters[79]Forward Heavy Fixed x
		-3, //parameters[80]Forward Heavy Fixed y
		0, //parameters[81]Forward Heavy vx
		0, //parameters[82]Forward Heavy vy
		0, //parameters[83]Acceleration x
		0, //parameters[84]Acceleration y
		10, //parameters[85]Forward Heavy Damage
		10, //parameters[86]Forward Heavy Start Up Duraiton
		30, //parameters[87]Forward Heavy Active Duration
		10, //parameters[88]Forward Heavy End Lag Duration
		1, //parameters[89]Forward Heavy Is Attached To Player
		0, //parameters[90] Is Player Attached To It
		0, //parameters[91]Forward Heavy Disappear On Hit

		50, //parameters[92]Up Heavy Additional x
		0, //parameters[93]Up Heavy Additional y
		50, //parameters[94]Up Heavy Width
		10, //parameters[95]Up Heavy Height
		40, //parameters[96]Up Heavy Stun Duration
		5, //parameters[97]Up Heavy Scalar X
		-5, //parameters[98]Up Heavy Scalar y
		3, //parameters[99]Up Heavy Fixed x
		-3, //parameters[100]Up Heavy Fixed y
		0, //parameters[101]Up Heavy vx
		0, //parameters[102]Up Heavy vy
		0, //parameters[103]Acceleration x
		0, //parameters[104]Acceleration y
		10, //parameters[105]Up Heavy Damage
		10, //parameters[106]Up Heavy Start Up Duraiton
		30, //parameters[107]Up Heavy Active Duration
		10, //parameters[108]Up Heavy End Lag Duration
		1, //parameters[109]Up Heavy Is Attached To Player
		0, //parameters[110] Is Player Attached To It
		0, //parameters[111]Up Heavy Disappear On Hit

		50, //parameters[112]Down Heavy Additional x
		0, //parameters[113]Down Heavy Additional y
		50, //parameters[114]Down Heavy Width
		10, //parameters[115]Down Heavy Height
		40, //parameters[116]Down Heavy Stun Duration
		5, //parameters[117]Down Heavy Scalar X
		-5, //parameters[118]Down Heavy Scalar y
		3, //parameters[119]Down Heavy Fixed x
		-3, //parameters[120]Down Heavy Fixed y
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

		50, //parameters[132]Forward Aerial Additional x
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

		50, //parameters[152]Back Aerial Additional x
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
		0, //parameters[173]Up Aerial Additional y
		50, //parameters[174]Up Aerial Width
		10, //parameters[175]Up Aerial Height
		40, //parameters[176]Up Aerial Stun Duration
		5, //parameters[177]Up Aerial Scalar X
		-5, //parameters[178]Up Aerial Scalar y
		3, //parameters[179]Up Aerial Fixed x
		-3, //parameters[180]Up Aerial Fixed y
		0, //parameters[181]Up Aerial vx
		0, //parameters[182]Up Aerial vy
		0, //parameters[183]Acceleration x
		0, //parameters[184]Acceleration y
		10, //parameters[185]Up Aerial Damage
		10, //parameters[186]Up Aerial Start Up Duraiton
		30, //parameters[187]Up Aerial Active Duration
		10, //parameters[188]Up Aerial End Lag Duration
		1, //parameters[189]Up Aerial Is Attached To Player
		0, //parameters[190] Is Player Attached To It
		0, //parameters[191]Up Aerial Disappear On Hit

		50, //parameters[192]Down Aerial Additional x
		0, //parameters[193]Down Aerial Additional y
		50, //parameters[194]Down Aerial Width
		10, //parameters[195]Down Aerial Height
		40, //parameters[196]Down Aerial Stun Duration
		5, //parameters[197]Down Aerial Scalar X
		-5, //parameters[198]Down Aerial Scalar y
		3, //parameters[199]Down Aerial Fixed x
		-3, //parameters[200]Down Aerial Fixed y
		0, //parameters[201]Down Aerial vx
		0, //parameters[202]Down Aerial vy
		0, //parameters[203]Acceleration x
		0, //parameters[204]Acceleration y
		10, //parameters[205]Down Aerial Damage
		10, //parameters[206]Down Aerial Start Up Duraiton
		30, //parameters[207]Down Aerial Active Duration
		10, //parameters[208]Down Aerial End Lag Duration
		1, //parameters[209]Down Aerial Is Attached To Player
		0, //parameters[210] Is Player Attached To It
		0, //parameters[211]Down Aerial Disappear On Hit

		100, //parameters[212]Forward Special Additional x
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
		-1, //parameters[258]Down Special Scalar y
		3, //parameters[259]Down Special Fixed x
		-3, //parameters[260]Down Special Fixed y
		2, //parameters[261]Down Special vx
		0.5, //parameters[262]Down Special vy
		0, //parameters[263]Acceleration x
		0, //parameters[264]Acceleration y
		5, //parameters[265]Down Special Damage
		10, //parameters[266]Down Special Start Up Duraiton
		300, //parameters[267]Down Special Active Duration
		50, //parameters[268]Down Special End Lag Duration
		0, //parameters[269]Down Special Is Attached To Player
		1, //parameters[270] Is Player Attached To It
		0, //parameters[271]Down Special Disappear On Hit    

		0, //parameters[272]
		255, //parameters[273]
		255, //parameters[274]
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
	{ //Charactera
		100, //parameters[0]Width
		100, //parameters[1]Height
		10, //parameters[2]WalkSpeed
		10, //parameters[3]AerialSpeed
		1, //parameters[4]AerialAcceleration
		1, //parameters[5]WalkAcceleration
		20, //parameters[6]GronudedJumpHeight
		25, //parameters[7]AerialJumpHeight
		1, //parameters[8]FallAcceleration
		10, //parameters[9]FallSpeed
		1, //parameters[10]Weight
		2, //parameters[11]DoubleJumps

		50, //parameters[12]Forward Light Additional x
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

		50, //parameters[32]Up Light Additional x
		0, //parameters[33]Up Light Additional y
		50, //parameters[34]Up Light Width
		10, //parameters[35]Up Light Height
		40, //parameters[36]Up Light Stun Duration
		5, //parameters[37]Up Light Scalar X
		-5, //parameters[38]Up Light Scalar y
		3, //parameters[39]Up Light Fixed x
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

		50, //parameters[52]Down Light Additional x
		0, //parameters[53]Down Light Additional y
		50, //parameters[54]Down Light Width
		10, //parameters[55]Down Light Height
		40, //parameters[56]Down Light Stun Duration
		5, //parameters[57]Down Light Scalar X
		-5, //parameters[58]Down Light Scalar y
		3, //parameters[59]Down Light Fixed x
		-3, //parameters[60]Down Light Fixed y
		0, //parameters[61]Down Light vx
		0, //parameters[62]Down Light vy
		0, //parameters[63]Acceleration x
		0, //parameters[64]Acceleration y
		10, //parameters[65]Down Light Damage
		10, //parameters[66]Down Light Start Up Duraiton
		30, //parameters[67]Down Light Active Duration
		10, //parameters[68]Down Light End Lag Duration
		1, //parameters[69]Down Light Is Attached To Player
		0, //parameters[70] Is Player Attached To It
		0, //parameters[71]Down Light Disappear On Hit

		50, //parameters[72]Forward Heavy Additional x
		0, //parameters[73]Forward Heavy Additional y
		50, //parameters[74]Forward Heavy Width
		10, //parameters[75]Forward Heavy Height
		40, //parameters[76]Forward Heavy Stun Duration
		5, //parameters[77]Forward Heavy Scalar X
		-5, //parameters[78]Forward Heavy Scalar y
		3, //parameters[79]Forward Heavy Fixed x
		-3, //parameters[80]Forward Heavy Fixed y
		0, //parameters[81]Forward Heavy vx
		0, //parameters[82]Forward Heavy vy
		0, //parameters[83]Acceleration x
		0, //parameters[84]Acceleration y
		10, //parameters[85]Forward Heavy Damage
		10, //parameters[86]Forward Heavy Start Up Duraiton
		30, //parameters[87]Forward Heavy Active Duration
		10, //parameters[88]Forward Heavy End Lag Duration
		1, //parameters[89]Forward Heavy Is Attached To Player
		0, //parameters[90] Is Player Attached To It
		0, //parameters[91]Forward Heavy Disappear On Hit

		50, //parameters[92]Up Heavy Additional x
		0, //parameters[93]Up Heavy Additional y
		50, //parameters[94]Up Heavy Width
		10, //parameters[95]Up Heavy Height
		40, //parameters[96]Up Heavy Stun Duration
		5, //parameters[97]Up Heavy Scalar X
		-5, //parameters[98]Up Heavy Scalar y
		3, //parameters[99]Up Heavy Fixed x
		-3, //parameters[100]Up Heavy Fixed y
		0, //parameters[101]Up Heavy vx
		0, //parameters[102]Up Heavy vy
		0, //parameters[103]Acceleration x
		0, //parameters[104]Acceleration y
		10, //parameters[105]Up Heavy Damage
		10, //parameters[106]Up Heavy Start Up Duraiton
		30, //parameters[107]Up Heavy Active Duration
		10, //parameters[108]Up Heavy End Lag Duration
		1, //parameters[109]Up Heavy Is Attached To Player
		0, //parameters[110] Is Player Attached To It
		0, //parameters[111]Up Heavy Disappear On Hit

		50, //parameters[112]Down Heavy Additional x
		0, //parameters[113]Down Heavy Additional y
		50, //parameters[114]Down Heavy Width
		10, //parameters[115]Down Heavy Height
		40, //parameters[116]Down Heavy Stun Duration
		5, //parameters[117]Down Heavy Scalar X
		-5, //parameters[118]Down Heavy Scalar y
		3, //parameters[119]Down Heavy Fixed x
		-3, //parameters[120]Down Heavy Fixed y
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

		50, //parameters[132]Forward Aerial Additional x
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

		50, //parameters[152]Back Aerial Additional x
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
		0, //parameters[173]Up Aerial Additional y
		50, //parameters[174]Up Aerial Width
		10, //parameters[175]Up Aerial Height
		40, //parameters[176]Up Aerial Stun Duration
		5, //parameters[177]Up Aerial Scalar X
		-5, //parameters[178]Up Aerial Scalar y
		3, //parameters[179]Up Aerial Fixed x
		-3, //parameters[180]Up Aerial Fixed y
		0, //parameters[181]Up Aerial vx
		0, //parameters[182]Up Aerial vy
		0, //parameters[183]Acceleration x
		0, //parameters[184]Acceleration y
		10, //parameters[185]Up Aerial Damage
		10, //parameters[186]Up Aerial Start Up Duraiton
		30, //parameters[187]Up Aerial Active Duration
		10, //parameters[188]Up Aerial End Lag Duration
		1, //parameters[189]Up Aerial Is Attached To Player
		0, //parameters[190] Is Player Attached To It
		0, //parameters[191]Up Aerial Disappear On Hit

		50, //parameters[192]Down Aerial Additional x
		0, //parameters[193]Down Aerial Additional y
		50, //parameters[194]Down Aerial Width
		10, //parameters[195]Down Aerial Height
		40, //parameters[196]Down Aerial Stun Duration
		5, //parameters[197]Down Aerial Scalar X
		-5, //parameters[198]Down Aerial Scalar y
		3, //parameters[199]Down Aerial Fixed x
		-3, //parameters[200]Down Aerial Fixed y
		0, //parameters[201]Down Aerial vx
		0, //parameters[202]Down Aerial vy
		0, //parameters[203]Acceleration x
		0, //parameters[204]Acceleration y
		10, //parameters[205]Down Aerial Damage
		10, //parameters[206]Down Aerial Start Up Duraiton
		30, //parameters[207]Down Aerial Active Duration
		10, //parameters[208]Down Aerial End Lag Duration
		1, //parameters[209]Down Aerial Is Attached To Player
		0, //parameters[210] Is Player Attached To It
		0, //parameters[211]Down Aerial Disappear On Hit

		100, //parameters[212]Forward Special Additional x
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
		0, //parameters[244]Acceleration y
		5, //parameters[245]Up Special Damage
		10, //parameters[246]Up Special Start Up Duraiton
		300, //parameters[247]Up Special Active Duration
		50, //parameters[248]Up Special End Lag Duration
		0, //parameters[249]Up Special Is Attached To Player
		0, //parameters[250] Is Player Attached To It
		1, //parameters[251]Up Special Disappear On Hit

		100, //parameters[252]Down Special Additional x
		0, //parameters[253]Down Special Additional y
		50, //parameters[254]Down Special Width
		10, //parameters[255]Down Special Height
		20, //parameters[256]Down Special Stun Duration
		15, //parameters[257]Down Special Scalar X
		-1, //parameters[258]Down Special Scalar y
		3, //parameters[259]Down Special Fixed x
		-3, //parameters[260]Down Special Fixed y
		2, //parameters[261]Down Special vx
		0.5, //parameters[262]Down Special vy
		0, //parameters[263]Acceleration x
		0, //parameters[264]Acceleration y
		5, //parameters[265]Down Special Damage
		10, //parameters[266]Down Special Start Up Duraiton
		300, //parameters[267]Down Special Active Duration
		50, //parameters[268]Down Special End Lag Duration
		0, //parameters[269]Down Special Is Attached To Player
		0, //parameters[270] Is Player Attached To It
		1, //parameters[271]Down Special Disappear On Hit     
		255, //parameters[272]
		255, //parameters[273]
		255, //parameters[274]
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
	{ //CharacterLightning
		60, //parameters[0]Width
		200, //parameters[1]Height
		10, //parameters[2]WalkSpeed
		10, //parameters[3]AerialSpeed
		1, //parameters[4]AerialAcceleration
		1, //parameters[5]WalkAcceleration
		20, //parameters[6]GronudedJumpHeight
		25, //parameters[7]AerialJumpHeight
		1, //parameters[8]FallAcceleration
		10, //parameters[9]FallSpeed
		1, //parameters[10]Weight
		2, //parameters[11]DoubleJumps

		50, //parameters[12]Forward Light Additional x
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

		50, //parameters[32]Up Light Additional x
		0, //parameters[33]Up Light Additional y
		50, //parameters[34]Up Light Width
		10, //parameters[35]Up Light Height
		40, //parameters[36]Up Light Stun Duration
		5, //parameters[37]Up Light Scalar X
		-5, //parameters[38]Up Light Scalar y
		3, //parameters[39]Up Light Fixed x
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

		50, //parameters[52]Down Light Additional x
		0, //parameters[53]Down Light Additional y
		50, //parameters[54]Down Light Width
		10, //parameters[55]Down Light Height
		40, //parameters[56]Down Light Stun Duration
		5, //parameters[57]Down Light Scalar X
		-5, //parameters[58]Down Light Scalar y
		3, //parameters[59]Down Light Fixed x
		-3, //parameters[60]Down Light Fixed y
		0, //parameters[61]Down Light vx
		0, //parameters[62]Down Light vy
		0, //parameters[63]Acceleration x
		0, //parameters[64]Acceleration y
		10, //parameters[65]Down Light Damage
		10, //parameters[66]Down Light Start Up Duraiton
		30, //parameters[67]Down Light Active Duration
		10, //parameters[68]Down Light End Lag Duration
		1, //parameters[69]Down Light Is Attached To Player
		0, //parameters[70] Is Player Attached To It
		0, //parameters[71]Down Light Disappear On Hit

		50, //parameters[72]Forward Heavy Additional x
		0, //parameters[73]Forward Heavy Additional y
		50, //parameters[74]Forward Heavy Width
		10, //parameters[75]Forward Heavy Height
		40, //parameters[76]Forward Heavy Stun Duration
		5, //parameters[77]Forward Heavy Scalar X
		-5, //parameters[78]Forward Heavy Scalar y
		3, //parameters[79]Forward Heavy Fixed x
		-3, //parameters[80]Forward Heavy Fixed y
		0, //parameters[81]Forward Heavy vx
		0, //parameters[82]Forward Heavy vy
		0, //parameters[83]Acceleration x
		0, //parameters[84]Acceleration y
		10, //parameters[85]Forward Heavy Damage
		10, //parameters[86]Forward Heavy Start Up Duraiton
		30, //parameters[87]Forward Heavy Active Duration
		10, //parameters[88]Forward Heavy End Lag Duration
		1, //parameters[89]Forward Heavy Is Attached To Player
		0, //parameters[90] Is Player Attached To It
		0, //parameters[91]Forward Heavy Disappear On Hit

		50, //parameters[92]Up Heavy Additional x
		0, //parameters[93]Up Heavy Additional y
		50, //parameters[94]Up Heavy Width
		10, //parameters[95]Up Heavy Height
		40, //parameters[96]Up Heavy Stun Duration
		5, //parameters[97]Up Heavy Scalar X
		-5, //parameters[98]Up Heavy Scalar y
		3, //parameters[99]Up Heavy Fixed x
		-3, //parameters[100]Up Heavy Fixed y
		0, //parameters[101]Up Heavy vx
		0, //parameters[102]Up Heavy vy
		0, //parameters[103]Acceleration x
		0, //parameters[104]Acceleration y
		10, //parameters[105]Up Heavy Damage
		10, //parameters[106]Up Heavy Start Up Duraiton
		30, //parameters[107]Up Heavy Active Duration
		10, //parameters[108]Up Heavy End Lag Duration
		1, //parameters[109]Up Heavy Is Attached To Player
		0, //parameters[110] Is Player Attached To It
		0, //parameters[111]Up Heavy Disappear On Hit

		50, //parameters[112]Down Heavy Additional x
		0, //parameters[113]Down Heavy Additional y
		50, //parameters[114]Down Heavy Width
		10, //parameters[115]Down Heavy Height
		40, //parameters[116]Down Heavy Stun Duration
		5, //parameters[117]Down Heavy Scalar X
		-5, //parameters[118]Down Heavy Scalar y
		3, //parameters[119]Down Heavy Fixed x
		-3, //parameters[120]Down Heavy Fixed y
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

		50, //parameters[132]Forward Aerial Additional x
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

		50, //parameters[152]Back Aerial Additional x
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
		0, //parameters[173]Up Aerial Additional y
		50, //parameters[174]Up Aerial Width
		10, //parameters[175]Up Aerial Height
		40, //parameters[176]Up Aerial Stun Duration
		5, //parameters[177]Up Aerial Scalar X
		-5, //parameters[178]Up Aerial Scalar y
		3, //parameters[179]Up Aerial Fixed x
		-3, //parameters[180]Up Aerial Fixed y
		0, //parameters[181]Up Aerial vx
		0, //parameters[182]Up Aerial vy
		0, //parameters[183]Acceleration x
		0, //parameters[184]Acceleration y
		10, //parameters[185]Up Aerial Damage
		10, //parameters[186]Up Aerial Start Up Duraiton
		30, //parameters[187]Up Aerial Active Duration
		10, //parameters[188]Up Aerial End Lag Duration
		1, //parameters[189]Up Aerial Is Attached To Player
		0, //parameters[190] Is Player Attached To It
		0, //parameters[191]Up Aerial Disappear On Hit

		50, //parameters[192]Down Aerial Additional x
		0, //parameters[193]Down Aerial Additional y
		50, //parameters[194]Down Aerial Width
		10, //parameters[195]Down Aerial Height
		40, //parameters[196]Down Aerial Stun Duration
		5, //parameters[197]Down Aerial Scalar X
		-5, //parameters[198]Down Aerial Scalar y
		3, //parameters[199]Down Aerial Fixed x
		-3, //parameters[200]Down Aerial Fixed y
		0, //parameters[201]Down Aerial vx
		0, //parameters[202]Down Aerial vy
		0, //parameters[203]Acceleration x
		0, //parameters[204]Acceleration y
		10, //parameters[205]Down Aerial Damage
		10, //parameters[206]Down Aerial Start Up Duraiton
		30, //parameters[207]Down Aerial Active Duration
		10, //parameters[208]Down Aerial End Lag Duration
		1, //parameters[209]Down Aerial Is Attached To Player
		0, //parameters[210] Is Player Attached To It
		0, //parameters[211]Down Aerial Disappear On Hit

		100, //parameters[212]Forward Special Additional x
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
		0, //parameters[244]Acceleration y
		5, //parameters[245]Up Special Damage
		10, //parameters[246]Up Special Start Up Duraiton
		300, //parameters[247]Up Special Active Duration
		50, //parameters[248]Up Special End Lag Duration
		0, //parameters[249]Up Special Is Attached To Player
		0, //parameters[250] Is Player Attached To It
		1, //parameters[251]Up Special Disappear On Hit

		100, //parameters[252]Down Special Additional x
		0, //parameters[253]Down Special Additional y
		50, //parameters[254]Down Special Width
		10, //parameters[255]Down Special Height
		20, //parameters[256]Down Special Stun Duration
		15, //parameters[257]Down Special Scalar X
		-1, //parameters[258]Down Special Scalar y
		3, //parameters[259]Down Special Fixed x
		-3, //parameters[260]Down Special Fixed y
		2, //parameters[261]Down Special vx
		0.5, //parameters[262]Down Special vy
		0, //parameters[263]Acceleration x
		0, //parameters[264]Acceleration y
		5, //parameters[265]Down Special Damage
		10, //parameters[266]Down Special Start Up Duraiton
		300, //parameters[267]Down Special Active Duration
		50, //parameters[268]Down Special End Lag Duration
		0, //parameters[269]Down Special Is Attached To Player
		0, //parameters[270] Is Player Attached To It
		1, //parameters[271]Down Special Disappear On Hit    
		0, //parameters[272]
		0, //parameters[273]
		0, //parameters[274]
		0, //parameters[275]
		0, //parameters[276]
		0, //parameters[277]
		0, //parameters[278]
		0, //parameters[279]
		0, //parameters[280]
		0, //parameters[281]
		0, //parameters[282]
		0, //parameters[283]
		0, //parameters[284]
		0, //parameters[285]
		0, //parameters[286]
		0, //parameters[287]
		0, //parameters[288]
		0, //parameters[289]
		0, //parameters[290]
		0, //parameters[291]
		0, //parameters[292]
		0, //parameters[293]
		0, //parameters[294]
		0, //parameters[295]
		0, //parameters[296]
		0, //parameters[297]
		0, //parameters[298]
		0, //parameters[299]
		0, //parameters[300]
		0, //parameters[301]
		0, //parameters[302]
		0, //parameters[303]
		0, //parameters[304]
		0, //parameters[305]
		0, //parameters[306]
		0, //parameters[307]
		0, //parameters[308]
		0, //parameters[309]
		0 //parameters[310]  
	},
	{ //CharacterDog
		70, //parameters[0]Width
		40, //parameters[1]Height
		10, //parameters[2]WalkSpeed
		10, //parameters[3]AerialSpeed
		1, //parameters[4]AerialAcceleration
		1, //parameters[5]WalkAcceleration
		20, //parameters[6]GronudedJumpHeight
		25, //parameters[7]AerialJumpHeight
		1, //parameters[8]FallAcceleration
		10, //parameters[9]FallSpeed
		1, //parameters[10]Weight
		2, //parameters[11]DoubleJumps

		50, //parameters[12]Forward Light Additional x
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

		50, //parameters[32]Up Light Additional x
		0, //parameters[33]Up Light Additional y
		50, //parameters[34]Up Light Width
		10, //parameters[35]Up Light Height
		40, //parameters[36]Up Light Stun Duration
		5, //parameters[37]Up Light Scalar X
		-5, //parameters[38]Up Light Scalar y
		3, //parameters[39]Up Light Fixed x
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

		50, //parameters[52]Down Light Additional x
		0, //parameters[53]Down Light Additional y
		50, //parameters[54]Down Light Width
		10, //parameters[55]Down Light Height
		40, //parameters[56]Down Light Stun Duration
		5, //parameters[57]Down Light Scalar X
		-5, //parameters[58]Down Light Scalar y
		3, //parameters[59]Down Light Fixed x
		-3, //parameters[60]Down Light Fixed y
		0, //parameters[61]Down Light vx
		0, //parameters[62]Down Light vy
		0, //parameters[63]Acceleration x
		0, //parameters[64]Acceleration y
		10, //parameters[65]Down Light Damage
		10, //parameters[66]Down Light Start Up Duraiton
		30, //parameters[67]Down Light Active Duration
		10, //parameters[68]Down Light End Lag Duration
		1, //parameters[69]Down Light Is Attached To Player
		0, //parameters[70] Is Player Attached To It
		0, //parameters[71]Down Light Disappear On Hit

		50, //parameters[72]Forward Heavy Additional x
		0, //parameters[73]Forward Heavy Additional y
		50, //parameters[74]Forward Heavy Width
		10, //parameters[75]Forward Heavy Height
		40, //parameters[76]Forward Heavy Stun Duration
		5, //parameters[77]Forward Heavy Scalar X
		-5, //parameters[78]Forward Heavy Scalar y
		3, //parameters[79]Forward Heavy Fixed x
		-3, //parameters[80]Forward Heavy Fixed y
		0, //parameters[81]Forward Heavy vx
		0, //parameters[82]Forward Heavy vy
		0, //parameters[83]Acceleration x
		0, //parameters[84]Acceleration y
		10, //parameters[85]Forward Heavy Damage
		10, //parameters[86]Forward Heavy Start Up Duraiton
		30, //parameters[87]Forward Heavy Active Duration
		10, //parameters[88]Forward Heavy End Lag Duration
		1, //parameters[89]Forward Heavy Is Attached To Player
		0, //parameters[90] Is Player Attached To It
		0, //parameters[91]Forward Heavy Disappear On Hit

		50, //parameters[92]Up Heavy Additional x
		0, //parameters[93]Up Heavy Additional y
		50, //parameters[94]Up Heavy Width
		10, //parameters[95]Up Heavy Height
		40, //parameters[96]Up Heavy Stun Duration
		5, //parameters[97]Up Heavy Scalar X
		-5, //parameters[98]Up Heavy Scalar y
		3, //parameters[99]Up Heavy Fixed x
		-3, //parameters[100]Up Heavy Fixed y
		0, //parameters[101]Up Heavy vx
		0, //parameters[102]Up Heavy vy
		0, //parameters[103]Acceleration x
		0, //parameters[104]Acceleration y
		10, //parameters[105]Up Heavy Damage
		10, //parameters[106]Up Heavy Start Up Duraiton
		30, //parameters[107]Up Heavy Active Duration
		10, //parameters[108]Up Heavy End Lag Duration
		1, //parameters[109]Up Heavy Is Attached To Player
		0, //parameters[110] Is Player Attached To It
		0, //parameters[111]Up Heavy Disappear On Hit

		50, //parameters[112]Down Heavy Additional x
		0, //parameters[113]Down Heavy Additional y
		50, //parameters[114]Down Heavy Width
		10, //parameters[115]Down Heavy Height
		40, //parameters[116]Down Heavy Stun Duration
		5, //parameters[117]Down Heavy Scalar X
		-5, //parameters[118]Down Heavy Scalar y
		3, //parameters[119]Down Heavy Fixed x
		-3, //parameters[120]Down Heavy Fixed y
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

		50, //parameters[132]Forward Aerial Additional x
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

		50, //parameters[152]Back Aerial Additional x
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
		0, //parameters[173]Up Aerial Additional y
		50, //parameters[174]Up Aerial Width
		10, //parameters[175]Up Aerial Height
		40, //parameters[176]Up Aerial Stun Duration
		5, //parameters[177]Up Aerial Scalar X
		-5, //parameters[178]Up Aerial Scalar y
		3, //parameters[179]Up Aerial Fixed x
		-3, //parameters[180]Up Aerial Fixed y
		0, //parameters[181]Up Aerial vx
		0, //parameters[182]Up Aerial vy
		0, //parameters[183]Acceleration x
		0, //parameters[184]Acceleration y
		10, //parameters[185]Up Aerial Damage
		10, //parameters[186]Up Aerial Start Up Duraiton
		30, //parameters[187]Up Aerial Active Duration
		10, //parameters[188]Up Aerial End Lag Duration
		1, //parameters[189]Up Aerial Is Attached To Player
		0, //parameters[190] Is Player Attached To It
		0, //parameters[191]Up Aerial Disappear On Hit

		50, //parameters[192]Down Aerial Additional x
		0, //parameters[193]Down Aerial Additional y
		50, //parameters[194]Down Aerial Width
		10, //parameters[195]Down Aerial Height
		40, //parameters[196]Down Aerial Stun Duration
		5, //parameters[197]Down Aerial Scalar X
		-5, //parameters[198]Down Aerial Scalar y
		3, //parameters[199]Down Aerial Fixed x
		-3, //parameters[200]Down Aerial Fixed y
		0, //parameters[201]Down Aerial vx
		0, //parameters[202]Down Aerial vy
		0, //parameters[203]Acceleration x
		0, //parameters[204]Acceleration y
		10, //parameters[205]Down Aerial Damage
		10, //parameters[206]Down Aerial Start Up Duraiton
		30, //parameters[207]Down Aerial Active Duration
		10, //parameters[208]Down Aerial End Lag Duration
		1, //parameters[209]Down Aerial Is Attached To Player
		0, //parameters[210] Is Player Attached To It
		0, //parameters[211]Down Aerial Disappear On Hit

		100, //parameters[212]Forward Special Additional x
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
		0, //parameters[244]Acceleration y
		5, //parameters[245]Up Special Damage
		10, //parameters[246]Up Special Start Up Duraiton
		300, //parameters[247]Up Special Active Duration
		50, //parameters[248]Up Special End Lag Duration
		0, //parameters[249]Up Special Is Attached To Player
		0, //parameters[250] Is Player Attached To It
		1, //parameters[251]Up Special Disappear On Hit

		100, //parameters[252]Down Special Additional x
		0, //parameters[253]Down Special Additional y
		50, //parameters[254]Down Special Width
		10, //parameters[255]Down Special Height
		20, //parameters[256]Down Special Stun Duration
		15, //parameters[257]Down Special Scalar X
		-1, //parameters[258]Down Special Scalar y
		3, //parameters[259]Down Special Fixed x
		-3, //parameters[260]Down Special Fixed y
		2, //parameters[261]Down Special vx
		0.5, //parameters[262]Down Special vy
		0, //parameters[263]Acceleration x
		0, //parameters[264]Acceleration y
		5, //parameters[265]Down Special Damage
		10, //parameters[266]Down Special Start Up Duraiton
		300, //parameters[267]Down Special Active Duration
		50, //parameters[268]Down Special End Lag Duration
		0, //parameters[269]Down Special Is Attached To Player
		0, //parameters[270] Is Player Attached To It
		1, //parameters[271]Down Special Disappear On Hit      
		0, //parameters[272]
		0, //parameters[273]
		0, //parameters[274]
		0, //parameters[275]
		0, //parameters[276]
		0, //parameters[277]
		0, //parameters[278]
		0, //parameters[279]
		0, //parameters[280]
		0, //parameters[281]
		0, //parameters[282]
		0, //parameters[283]
		0, //parameters[284]
		0, //parameters[285]
		0, //parameters[286]
		0, //parameters[287]
		0, //parameters[288]
		0, //parameters[289]
		0, //parameters[290]
		0, //parameters[291]
		0, //parameters[292]
		0, //parameters[293]
		0, //parameters[294]
		0, //parameters[295]
		0, //parameters[296]
		0, //parameters[297]
		0, //parameters[298]
		0, //parameters[299]
		0, //parameters[300]
		0, //parameters[301]
		0, //parameters[302]
		0, //parameters[303]
		0, //parameters[304]
		0, //parameters[305]
		0, //parameters[306]
		0, //parameters[307]
		0, //parameters[308]
		0, //parameters[309]
		0 //parameters[310]
	},
	{ //CharacterChicken
		150, //parameters[0]Width
		150, //parameters[1]Height
		10, //parameters[2]WalkSpeed
		10, //parameters[3]AerialSpeed
		1, //parameters[4]AerialAcceleration
		1, //parameters[5]WalkAcceleration
		20, //parameters[6]GronudedJumpHeight
		25, //parameters[7]AerialJumpHeight
		1, //parameters[8]FallAcceleration
		10, //parameters[9]FallSpeed
		1, //parameters[10]Weight
		2, //parameters[11]DoubleJumps

		50, //parameters[12]Forward Light Additional x
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

		50, //parameters[32]Up Light Additional x
		0, //parameters[33]Up Light Additional y
		50, //parameters[34]Up Light Width
		10, //parameters[35]Up Light Height
		40, //parameters[36]Up Light Stun Duration
		5, //parameters[37]Up Light Scalar X
		-5, //parameters[38]Up Light Scalar y
		3, //parameters[39]Up Light Fixed x
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

		50, //parameters[52]Down Light Additional x
		0, //parameters[53]Down Light Additional y
		50, //parameters[54]Down Light Width
		10, //parameters[55]Down Light Height
		40, //parameters[56]Down Light Stun Duration
		5, //parameters[57]Down Light Scalar X
		-5, //parameters[58]Down Light Scalar y
		3, //parameters[59]Down Light Fixed x
		-3, //parameters[60]Down Light Fixed y
		0, //parameters[61]Down Light vx
		0, //parameters[62]Down Light vy
		0, //parameters[63]Acceleration x
		0, //parameters[64]Acceleration y
		10, //parameters[65]Down Light Damage
		10, //parameters[66]Down Light Start Up Duraiton
		30, //parameters[67]Down Light Active Duration
		10, //parameters[68]Down Light End Lag Duration
		1, //parameters[69]Down Light Is Attached To Player
		0, //parameters[70] Is Player Attached To It
		0, //parameters[71]Down Light Disappear On Hit

		50, //parameters[72]Forward Heavy Additional x
		0, //parameters[73]Forward Heavy Additional y
		50, //parameters[74]Forward Heavy Width
		10, //parameters[75]Forward Heavy Height
		40, //parameters[76]Forward Heavy Stun Duration
		5, //parameters[77]Forward Heavy Scalar X
		-5, //parameters[78]Forward Heavy Scalar y
		3, //parameters[79]Forward Heavy Fixed x
		-3, //parameters[80]Forward Heavy Fixed y
		0, //parameters[81]Forward Heavy vx
		0, //parameters[82]Forward Heavy vy
		0, //parameters[83]Acceleration x
		0, //parameters[84]Acceleration y
		10, //parameters[85]Forward Heavy Damage
		10, //parameters[86]Forward Heavy Start Up Duraiton
		30, //parameters[87]Forward Heavy Active Duration
		10, //parameters[88]Forward Heavy End Lag Duration
		1, //parameters[89]Forward Heavy Is Attached To Player
		0, //parameters[90] Is Player Attached To It
		0, //parameters[91]Forward Heavy Disappear On Hit

		50, //parameters[92]Up Heavy Additional x
		0, //parameters[93]Up Heavy Additional y
		50, //parameters[94]Up Heavy Width
		10, //parameters[95]Up Heavy Height
		40, //parameters[96]Up Heavy Stun Duration
		5, //parameters[97]Up Heavy Scalar X
		-5, //parameters[98]Up Heavy Scalar y
		3, //parameters[99]Up Heavy Fixed x
		-3, //parameters[100]Up Heavy Fixed y
		0, //parameters[101]Up Heavy vx
		0, //parameters[102]Up Heavy vy
		0, //parameters[103]Acceleration x
		0, //parameters[104]Acceleration y
		10, //parameters[105]Up Heavy Damage
		10, //parameters[106]Up Heavy Start Up Duraiton
		30, //parameters[107]Up Heavy Active Duration
		10, //parameters[108]Up Heavy End Lag Duration
		1, //parameters[109]Up Heavy Is Attached To Player
		0, //parameters[110] Is Player Attached To It
		0, //parameters[111]Up Heavy Disappear On Hit

		50, //parameters[112]Down Heavy Additional x
		0, //parameters[113]Down Heavy Additional y
		50, //parameters[114]Down Heavy Width
		10, //parameters[115]Down Heavy Height
		40, //parameters[116]Down Heavy Stun Duration
		5, //parameters[117]Down Heavy Scalar X
		-5, //parameters[118]Down Heavy Scalar y
		3, //parameters[119]Down Heavy Fixed x
		-3, //parameters[120]Down Heavy Fixed y
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

		50, //parameters[132]Forward Aerial Additional x
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

		50, //parameters[152]Back Aerial Additional x
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
		0, //parameters[173]Up Aerial Additional y
		50, //parameters[174]Up Aerial Width
		10, //parameters[175]Up Aerial Height
		40, //parameters[176]Up Aerial Stun Duration
		5, //parameters[177]Up Aerial Scalar X
		-5, //parameters[178]Up Aerial Scalar y
		3, //parameters[179]Up Aerial Fixed x
		-3, //parameters[180]Up Aerial Fixed y
		0, //parameters[181]Up Aerial vx
		0, //parameters[182]Up Aerial vy
		0, //parameters[183]Acceleration x
		0, //parameters[184]Acceleration y
		10, //parameters[185]Up Aerial Damage
		10, //parameters[186]Up Aerial Start Up Duraiton
		30, //parameters[187]Up Aerial Active Duration
		10, //parameters[188]Up Aerial End Lag Duration
		1, //parameters[189]Up Aerial Is Attached To Player
		0, //parameters[190] Is Player Attached To It
		0, //parameters[191]Up Aerial Disappear On Hit

		50, //parameters[192]Down Aerial Additional x
		0, //parameters[193]Down Aerial Additional y
		50, //parameters[194]Down Aerial Width
		10, //parameters[195]Down Aerial Height
		40, //parameters[196]Down Aerial Stun Duration
		5, //parameters[197]Down Aerial Scalar X
		-5, //parameters[198]Down Aerial Scalar y
		3, //parameters[199]Down Aerial Fixed x
		-3, //parameters[200]Down Aerial Fixed y
		0, //parameters[201]Down Aerial vx
		0, //parameters[202]Down Aerial vy
		0, //parameters[203]Acceleration x
		0, //parameters[204]Acceleration y
		10, //parameters[205]Down Aerial Damage
		10, //parameters[206]Down Aerial Start Up Duraiton
		30, //parameters[207]Down Aerial Active Duration
		10, //parameters[208]Down Aerial End Lag Duration
		1, //parameters[209]Down Aerial Is Attached To Player
		0, //parameters[210] Is Player Attached To It
		0, //parameters[211]Down Aerial Disappear On Hit

		100, //parameters[212]Forward Special Additional x
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
		0, //parameters[244]Acceleration y
		5, //parameters[245]Up Special Damage
		10, //parameters[246]Up Special Start Up Duraiton
		300, //parameters[247]Up Special Active Duration
		50, //parameters[248]Up Special End Lag Duration
		0, //parameters[249]Up Special Is Attached To Player
		0, //parameters[250] Is Player Attached To It
		1, //parameters[251]Up Special Disappear On Hit

		100, //parameters[252]Down Special Additional x
		0, //parameters[253]Down Special Additional y
		50, //parameters[254]Down Special Width
		10, //parameters[255]Down Special Height
		20, //parameters[256]Down Special Stun Duration
		15, //parameters[257]Down Special Scalar X
		-1, //parameters[258]Down Special Scalar y
		3, //parameters[259]Down Special Fixed x
		-3, //parameters[260]Down Special Fixed y
		2, //parameters[261]Down Special vx
		0.5, //parameters[262]Down Special vy
		0, //parameters[263]Acceleration x
		0, //parameters[264]Acceleration y
		5, //parameters[265]Down Special Damage
		10, //parameters[266]Down Special Start Up Duraiton
		300, //parameters[267]Down Special Active Duration
		50, //parameters[268]Down Special End Lag Duration
		0, //parameters[269]Down Special Is Attached To Player
		0, //parameters[270] Is Player Attached To It
		1, //parameters[271]Down Special Disappear On Hit      
		0, //parameters[272]
		0, //parameters[273]
		0, //parameters[274]
		0, //parameters[275]
		0, //parameters[276]
		0, //parameters[277]
		0, //parameters[278]
		0, //parameters[279]
		0, //parameters[280]
		0, //parameters[281]
		0, //parameters[282]
		0, //parameters[283]
		0, //parameters[284]
		0, //parameters[285]
		0, //parameters[286]
		0, //parameters[287]
		0, //parameters[288]
		0, //parameters[289]
		0, //parameters[290]
		0, //parameters[291]
		0, //parameters[292]
		0, //parameters[293]
		0, //parameters[294]
		0, //parameters[295]
		0, //parameters[296]
		0, //parameters[297]
		0, //parameters[298]
		0, //parameters[299]
		0, //parameters[300]
		0, //parameters[301]
		0, //parameters[302]
		0, //parameters[303]
		0, //parameters[304]
		0, //parameters[305]
		0, //parameters[306]
		0, //parameters[307]
		0, //parameters[308]
		0, //parameters[309]
		0 //parameters[310]
	},
	{ //CharacterRock
		100, //parameters[0]Width
		100, //parameters[1]Height
		10, //parameters[2]WalkSpeed
		10, //parameters[3]AerialSpeed
		1, //parameters[4]AerialAcceleration
		1, //parameters[5]WalkAcceleration
		20, //parameters[6]GronudedJumpHeight
		25, //parameters[7]AerialJumpHeight
		1, //parameters[8]FallAcceleration
		10, //parameters[9]FallSpeed
		1, //parameters[10]Weight
		2, //parameters[11]DoubleJumps

		50, //parameters[12]Forward Light Additional x
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

		50, //parameters[32]Up Light Additional x
		0, //parameters[33]Up Light Additional y
		50, //parameters[34]Up Light Width
		10, //parameters[35]Up Light Height
		40, //parameters[36]Up Light Stun Duration
		5, //parameters[37]Up Light Scalar X
		-5, //parameters[38]Up Light Scalar y
		3, //parameters[39]Up Light Fixed x
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

		50, //parameters[52]Down Light Additional x
		0, //parameters[53]Down Light Additional y
		50, //parameters[54]Down Light Width
		10, //parameters[55]Down Light Height
		40, //parameters[56]Down Light Stun Duration
		5, //parameters[57]Down Light Scalar X
		-5, //parameters[58]Down Light Scalar y
		3, //parameters[59]Down Light Fixed x
		-3, //parameters[60]Down Light Fixed y
		0, //parameters[61]Down Light vx
		0, //parameters[62]Down Light vy
		0, //parameters[63]Acceleration x
		0, //parameters[64]Acceleration y
		10, //parameters[65]Down Light Damage
		10, //parameters[66]Down Light Start Up Duraiton
		30, //parameters[67]Down Light Active Duration
		10, //parameters[68]Down Light End Lag Duration
		1, //parameters[69]Down Light Is Attached To Player
		0, //parameters[70] Is Player Attached To It
		0, //parameters[71]Down Light Disappear On Hit

		50, //parameters[72]Forward Heavy Additional x
		0, //parameters[73]Forward Heavy Additional y
		50, //parameters[74]Forward Heavy Width
		10, //parameters[75]Forward Heavy Height
		40, //parameters[76]Forward Heavy Stun Duration
		5, //parameters[77]Forward Heavy Scalar X
		-5, //parameters[78]Forward Heavy Scalar y
		3, //parameters[79]Forward Heavy Fixed x
		-3, //parameters[80]Forward Heavy Fixed y
		0, //parameters[81]Forward Heavy vx
		0, //parameters[82]Forward Heavy vy
		0, //parameters[83]Acceleration x
		0, //parameters[84]Acceleration y
		10, //parameters[85]Forward Heavy Damage
		10, //parameters[86]Forward Heavy Start Up Duraiton
		30, //parameters[87]Forward Heavy Active Duration
		10, //parameters[88]Forward Heavy End Lag Duration
		1, //parameters[89]Forward Heavy Is Attached To Player
		0, //parameters[90] Is Player Attached To It
		0, //parameters[91]Forward Heavy Disappear On Hit

		50, //parameters[92]Up Heavy Additional x
		0, //parameters[93]Up Heavy Additional y
		50, //parameters[94]Up Heavy Width
		10, //parameters[95]Up Heavy Height
		40, //parameters[96]Up Heavy Stun Duration
		5, //parameters[97]Up Heavy Scalar X
		-5, //parameters[98]Up Heavy Scalar y
		3, //parameters[99]Up Heavy Fixed x
		-3, //parameters[100]Up Heavy Fixed y
		0, //parameters[101]Up Heavy vx
		0, //parameters[102]Up Heavy vy
		0, //parameters[103]Acceleration x
		0, //parameters[104]Acceleration y
		10, //parameters[105]Up Heavy Damage
		10, //parameters[106]Up Heavy Start Up Duraiton
		30, //parameters[107]Up Heavy Active Duration
		10, //parameters[108]Up Heavy End Lag Duration
		1, //parameters[109]Up Heavy Is Attached To Player
		0, //parameters[110] Is Player Attached To It
		0, //parameters[111]Up Heavy Disappear On Hit

		50, //parameters[112]Down Heavy Additional x
		0, //parameters[113]Down Heavy Additional y
		50, //parameters[114]Down Heavy Width
		10, //parameters[115]Down Heavy Height
		40, //parameters[116]Down Heavy Stun Duration
		5, //parameters[117]Down Heavy Scalar X
		-5, //parameters[118]Down Heavy Scalar y
		3, //parameters[119]Down Heavy Fixed x
		-3, //parameters[120]Down Heavy Fixed y
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

		50, //parameters[132]Forward Aerial Additional x
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

		50, //parameters[152]Back Aerial Additional x
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
		0, //parameters[173]Up Aerial Additional y
		50, //parameters[174]Up Aerial Width
		10, //parameters[175]Up Aerial Height
		40, //parameters[176]Up Aerial Stun Duration
		5, //parameters[177]Up Aerial Scalar X
		-5, //parameters[178]Up Aerial Scalar y
		3, //parameters[179]Up Aerial Fixed x
		-3, //parameters[180]Up Aerial Fixed y
		0, //parameters[181]Up Aerial vx
		0, //parameters[182]Up Aerial vy
		0, //parameters[183]Acceleration x
		0, //parameters[184]Acceleration y
		10, //parameters[185]Up Aerial Damage
		10, //parameters[186]Up Aerial Start Up Duraiton
		30, //parameters[187]Up Aerial Active Duration
		10, //parameters[188]Up Aerial End Lag Duration
		1, //parameters[189]Up Aerial Is Attached To Player
		0, //parameters[190] Is Player Attached To It
		0, //parameters[191]Up Aerial Disappear On Hit

		50, //parameters[192]Down Aerial Additional x
		0, //parameters[193]Down Aerial Additional y
		50, //parameters[194]Down Aerial Width
		10, //parameters[195]Down Aerial Height
		40, //parameters[196]Down Aerial Stun Duration
		5, //parameters[197]Down Aerial Scalar X
		-5, //parameters[198]Down Aerial Scalar y
		3, //parameters[199]Down Aerial Fixed x
		-3, //parameters[200]Down Aerial Fixed y
		0, //parameters[201]Down Aerial vx
		0, //parameters[202]Down Aerial vy
		0, //parameters[203]Acceleration x
		0, //parameters[204]Acceleration y
		10, //parameters[205]Down Aerial Damage
		10, //parameters[206]Down Aerial Start Up Duraiton
		30, //parameters[207]Down Aerial Active Duration
		10, //parameters[208]Down Aerial End Lag Duration
		1, //parameters[209]Down Aerial Is Attached To Player
		0, //parameters[210] Is Player Attached To It
		0, //parameters[211]Down Aerial Disappear On Hit

		100, //parameters[212]Forward Special Additional x
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
		0, //parameters[244]Acceleration y
		5, //parameters[245]Up Special Damage
		10, //parameters[246]Up Special Start Up Duraiton
		300, //parameters[247]Up Special Active Duration
		50, //parameters[248]Up Special End Lag Duration
		0, //parameters[249]Up Special Is Attached To Player
		0, //parameters[250] Is Player Attached To It
		1, //parameters[251]Up Special Disappear On Hit

		100, //parameters[252]Down Special Additional x
		0, //parameters[253]Down Special Additional y
		50, //parameters[254]Down Special Width
		10, //parameters[255]Down Special Height
		20, //parameters[256]Down Special Stun Duration
		15, //parameters[257]Down Special Scalar X
		-1, //parameters[258]Down Special Scalar y
		3, //parameters[259]Down Special Fixed x
		-3, //parameters[260]Down Special Fixed y
		2, //parameters[261]Down Special vx
		0.5, //parameters[262]Down Special vy
		0, //parameters[263]Acceleration x
		0, //parameters[264]Acceleration y
		5, //parameters[265]Down Special Damage
		10, //parameters[266]Down Special Start Up Duraiton
		300, //parameters[267]Down Special Active Duration
		50, //parameters[268]Down Special End Lag Duration
		0, //parameters[269]Down Special Is Attached To Player
		0, //parameters[270] Is Player Attached To It
		1, //parameters[271]Down Special Disappear On Hit      
		0, //parameters[272]
		0, //parameters[273]
		0, //parameters[274]
		0, //parameters[275]
		0, //parameters[276]
		0, //parameters[277]
		0, //parameters[278]
		0, //parameters[279]
		0, //parameters[280]
		0, //parameters[281]
		0, //parameters[282]
		0, //parameters[283]
		0, //parameters[284]
		0, //parameters[285]
		0, //parameters[286]
		0, //parameters[287]
		0, //parameters[288]
		0, //parameters[289]
		0, //parameters[290]
		0, //parameters[291]
		0, //parameters[292]
		0, //parameters[293]
		0, //parameters[294]
		0, //parameters[295]
		0, //parameters[296]
		0, //parameters[297]
		0, //parameters[298]
		0, //parameters[299]
		0, //parameters[300]
		0, //parameters[301]
		0, //parameters[302]
		0, //parameters[303]
		0, //parameters[304]
		0, //parameters[305]
		0, //parameters[306]
		0, //parameters[307]
		0, //parameters[308]
		0, //parameters[309]
		0 //parameters[310]
	},
	{ //CharacterTroll
		100, //parameters[0]Width
		100, //parameters[1]Height
		10, //parameters[2]WalkSpeed
		10, //parameters[3]AerialSpeed
		1, //parameters[4]AerialAcceleration
		1, //parameters[5]WalkAcceleration
		20, //parameters[6]GronudedJumpHeight
		25, //parameters[7]AerialJumpHeight
		1, //parameters[8]FallAcceleration
		10, //parameters[9]FallSpeed
		1, //parameters[10]Weight
		2, //parameters[11]DoubleJumps

		50, //parameters[12]Forward Light Additional x
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

		50, //parameters[32]Up Light Additional x
		0, //parameters[33]Up Light Additional y
		50, //parameters[34]Up Light Width
		10, //parameters[35]Up Light Height
		40, //parameters[36]Up Light Stun Duration
		5, //parameters[37]Up Light Scalar X
		-5, //parameters[38]Up Light Scalar y
		3, //parameters[39]Up Light Fixed x
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

		50, //parameters[52]Down Light Additional x
		0, //parameters[53]Down Light Additional y
		50, //parameters[54]Down Light Width
		10, //parameters[55]Down Light Height
		40, //parameters[56]Down Light Stun Duration
		5, //parameters[57]Down Light Scalar X
		-5, //parameters[58]Down Light Scalar y
		3, //parameters[59]Down Light Fixed x
		-3, //parameters[60]Down Light Fixed y
		0, //parameters[61]Down Light vx
		0, //parameters[62]Down Light vy
		0, //parameters[63]Acceleration x
		0, //parameters[64]Acceleration y
		10, //parameters[65]Down Light Damage
		10, //parameters[66]Down Light Start Up Duraiton
		30, //parameters[67]Down Light Active Duration
		10, //parameters[68]Down Light End Lag Duration
		1, //parameters[69]Down Light Is Attached To Player
		0, //parameters[70] Is Player Attached To It
		0, //parameters[71]Down Light Disappear On Hit

		50, //parameters[72]Forward Heavy Additional x
		0, //parameters[73]Forward Heavy Additional y
		50, //parameters[74]Forward Heavy Width
		10, //parameters[75]Forward Heavy Height
		40, //parameters[76]Forward Heavy Stun Duration
		5, //parameters[77]Forward Heavy Scalar X
		-5, //parameters[78]Forward Heavy Scalar y
		3, //parameters[79]Forward Heavy Fixed x
		-3, //parameters[80]Forward Heavy Fixed y
		0, //parameters[81]Forward Heavy vx
		0, //parameters[82]Forward Heavy vy
		0, //parameters[83]Acceleration x
		0, //parameters[84]Acceleration y
		10, //parameters[85]Forward Heavy Damage
		10, //parameters[86]Forward Heavy Start Up Duraiton
		30, //parameters[87]Forward Heavy Active Duration
		10, //parameters[88]Forward Heavy End Lag Duration
		1, //parameters[89]Forward Heavy Is Attached To Player
		0, //parameters[90] Is Player Attached To It
		0, //parameters[91]Forward Heavy Disappear On Hit

		50, //parameters[92]Up Heavy Additional x
		0, //parameters[93]Up Heavy Additional y
		50, //parameters[94]Up Heavy Width
		10, //parameters[95]Up Heavy Height
		40, //parameters[96]Up Heavy Stun Duration
		5, //parameters[97]Up Heavy Scalar X
		-5, //parameters[98]Up Heavy Scalar y
		3, //parameters[99]Up Heavy Fixed x
		-3, //parameters[100]Up Heavy Fixed y
		0, //parameters[101]Up Heavy vx
		0, //parameters[102]Up Heavy vy
		0, //parameters[103]Acceleration x
		0, //parameters[104]Acceleration y
		10, //parameters[105]Up Heavy Damage
		10, //parameters[106]Up Heavy Start Up Duraiton
		30, //parameters[107]Up Heavy Active Duration
		10, //parameters[108]Up Heavy End Lag Duration
		1, //parameters[109]Up Heavy Is Attached To Player
		0, //parameters[110] Is Player Attached To It
		0, //parameters[111]Up Heavy Disappear On Hit

		50, //parameters[112]Down Heavy Additional x
		0, //parameters[113]Down Heavy Additional y
		50, //parameters[114]Down Heavy Width
		10, //parameters[115]Down Heavy Height
		40, //parameters[116]Down Heavy Stun Duration
		5, //parameters[117]Down Heavy Scalar X
		-5, //parameters[118]Down Heavy Scalar y
		3, //parameters[119]Down Heavy Fixed x
		-3, //parameters[120]Down Heavy Fixed y
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

		50, //parameters[132]Forward Aerial Additional x
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

		50, //parameters[152]Back Aerial Additional x
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
		0, //parameters[173]Up Aerial Additional y
		50, //parameters[174]Up Aerial Width
		10, //parameters[175]Up Aerial Height
		40, //parameters[176]Up Aerial Stun Duration
		5, //parameters[177]Up Aerial Scalar X
		-5, //parameters[178]Up Aerial Scalar y
		3, //parameters[179]Up Aerial Fixed x
		-3, //parameters[180]Up Aerial Fixed y
		0, //parameters[181]Up Aerial vx
		0, //parameters[182]Up Aerial vy
		0, //parameters[183]Acceleration x
		0, //parameters[184]Acceleration y
		10, //parameters[185]Up Aerial Damage
		10, //parameters[186]Up Aerial Start Up Duraiton
		30, //parameters[187]Up Aerial Active Duration
		10, //parameters[188]Up Aerial End Lag Duration
		1, //parameters[189]Up Aerial Is Attached To Player
		0, //parameters[190] Is Player Attached To It
		0, //parameters[191]Up Aerial Disappear On Hit

		50, //parameters[192]Down Aerial Additional x
		0, //parameters[193]Down Aerial Additional y
		50, //parameters[194]Down Aerial Width
		10, //parameters[195]Down Aerial Height
		40, //parameters[196]Down Aerial Stun Duration
		5, //parameters[197]Down Aerial Scalar X
		-5, //parameters[198]Down Aerial Scalar y
		3, //parameters[199]Down Aerial Fixed x
		-3, //parameters[200]Down Aerial Fixed y
		0, //parameters[201]Down Aerial vx
		0, //parameters[202]Down Aerial vy
		0, //parameters[203]Acceleration x
		0, //parameters[204]Acceleration y
		10, //parameters[205]Down Aerial Damage
		10, //parameters[206]Down Aerial Start Up Duraiton
		30, //parameters[207]Down Aerial Active Duration
		10, //parameters[208]Down Aerial End Lag Duration
		1, //parameters[209]Down Aerial Is Attached To Player
		0, //parameters[210] Is Player Attached To It
		0, //parameters[211]Down Aerial Disappear On Hit

		100, //parameters[212]Forward Special Additional x
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
		0, //parameters[244]Acceleration y
		5, //parameters[245]Up Special Damage
		10, //parameters[246]Up Special Start Up Duraiton
		300, //parameters[247]Up Special Active Duration
		50, //parameters[248]Up Special End Lag Duration
		0, //parameters[249]Up Special Is Attached To Player
		0, //parameters[250] Is Player Attached To It
		1, //parameters[251]Up Special Disappear On Hit

		100, //parameters[252]Down Special Additional x
		0, //parameters[253]Down Special Additional y
		50, //parameters[254]Down Special Width
		10, //parameters[255]Down Special Height
		20, //parameters[256]Down Special Stun Duration
		15, //parameters[257]Down Special Scalar X
		-1, //parameters[258]Down Special Scalar y
		3, //parameters[259]Down Special Fixed x
		-3, //parameters[260]Down Special Fixed y
		2, //parameters[261]Down Special vx
		0.5, //parameters[262]Down Special vy
		0, //parameters[263]Acceleration x
		0, //parameters[264]Acceleration y
		5, //parameters[265]Down Special Damage
		10, //parameters[266]Down Special Start Up Duraiton
		300, //parameters[267]Down Special Active Duration
		50, //parameters[268]Down Special End Lag Duration
		0, //parameters[269]Down Special Is Attached To Player
		0, //parameters[270] Is Player Attached To It
		1, //parameters[271]Down Special Disappear On Hit      
		0, //parameters[272]
		0, //parameters[273]
		0, //parameters[274]
		0, //parameters[275]
		0, //parameters[276]
		0, //parameters[277]
		0, //parameters[278]
		0, //parameters[279]
		0, //parameters[280]
		0, //parameters[281]
		0, //parameters[282]
		0, //parameters[283]
		0, //parameters[284]
		0, //parameters[285]
		0, //parameters[286]
		0, //parameters[287]
		0, //parameters[288]
		0, //parameters[289]
		0, //parameters[290]
		0, //parameters[291]
		0, //parameters[292]
		0, //parameters[293]
		0, //parameters[294]
		0, //parameters[295]
		0, //parameters[296]
		0, //parameters[297]
		0, //parameters[298]
		0, //parameters[299]
		0, //parameters[300]
		0, //parameters[301]
		0, //parameters[302]
		0, //parameters[303]
		0, //parameters[304]
		0, //parameters[305]
		0, //parameters[306]
		0, //parameters[307]
		0, //parameters[308]
		0, //parameters[309]
		0 //parameters[310]
	},
	{ //CharacterBigB
		89, //parameters[0]Width
		102, //parameters[1]Height
		10, //parameters[2]WalkSpeed
		10, //parameters[3]AerialSpeed
		1, //parameters[4]AerialAcceleration
		1, //parameters[5]WalkAcceleration
		20, //parameters[6]GronudedJumpHeight
		25, //parameters[7]AerialJumpHeight
		1, //parameters[8]FallAcceleration
		10, //parameters[9]FallSpeed
		1, //parameters[10]Weight
		2, //parameters[11]DoubleJumps

		50, //parameters[12]Forward Light Additional x
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

		50, //parameters[32]Up Light Additional x
		0, //parameters[33]Up Light Additional y
		50, //parameters[34]Up Light Width
		10, //parameters[35]Up Light Height
		40, //parameters[36]Up Light Stun Duration
		5, //parameters[37]Up Light Scalar X
		-5, //parameters[38]Up Light Scalar y
		3, //parameters[39]Up Light Fixed x
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

		50, //parameters[52]Down Light Additional x
		0, //parameters[53]Down Light Additional y
		50, //parameters[54]Down Light Width
		10, //parameters[55]Down Light Height
		40, //parameters[56]Down Light Stun Duration
		5, //parameters[57]Down Light Scalar X
		-5, //parameters[58]Down Light Scalar y
		3, //parameters[59]Down Light Fixed x
		-3, //parameters[60]Down Light Fixed y
		0, //parameters[61]Down Light vx
		0, //parameters[62]Down Light vy
		0, //parameters[63]Acceleration x
		0, //parameters[64]Acceleration y
		10, //parameters[65]Down Light Damage
		10, //parameters[66]Down Light Start Up Duraiton
		30, //parameters[67]Down Light Active Duration
		10, //parameters[68]Down Light End Lag Duration
		1, //parameters[69]Down Light Is Attached To Player
		0, //parameters[70] Is Player Attached To It
		0, //parameters[71]Down Light Disappear On Hit

		50, //parameters[72]Forward Heavy Additional x
		0, //parameters[73]Forward Heavy Additional y
		50, //parameters[74]Forward Heavy Width
		10, //parameters[75]Forward Heavy Height
		40, //parameters[76]Forward Heavy Stun Duration
		5, //parameters[77]Forward Heavy Scalar X
		-5, //parameters[78]Forward Heavy Scalar y
		3, //parameters[79]Forward Heavy Fixed x
		-3, //parameters[80]Forward Heavy Fixed y
		0, //parameters[81]Forward Heavy vx
		0, //parameters[82]Forward Heavy vy
		0, //parameters[83]Acceleration x
		0, //parameters[84]Acceleration y
		10, //parameters[85]Forward Heavy Damage
		10, //parameters[86]Forward Heavy Start Up Duraiton
		30, //parameters[87]Forward Heavy Active Duration
		10, //parameters[88]Forward Heavy End Lag Duration
		1, //parameters[89]Forward Heavy Is Attached To Player
		0, //parameters[90] Is Player Attached To It
		0, //parameters[91]Forward Heavy Disappear On Hit

		50, //parameters[92]Up Heavy Additional x
		0, //parameters[93]Up Heavy Additional y
		50, //parameters[94]Up Heavy Width
		10, //parameters[95]Up Heavy Height
		40, //parameters[96]Up Heavy Stun Duration
		5, //parameters[97]Up Heavy Scalar X
		-5, //parameters[98]Up Heavy Scalar y
		3, //parameters[99]Up Heavy Fixed x
		-3, //parameters[100]Up Heavy Fixed y
		0, //parameters[101]Up Heavy vx
		0, //parameters[102]Up Heavy vy
		0, //parameters[103]Acceleration x
		0, //parameters[104]Acceleration y
		10, //parameters[105]Up Heavy Damage
		10, //parameters[106]Up Heavy Start Up Duraiton
		30, //parameters[107]Up Heavy Active Duration
		10, //parameters[108]Up Heavy End Lag Duration
		1, //parameters[109]Up Heavy Is Attached To Player
		0, //parameters[110] Is Player Attached To It
		0, //parameters[111]Up Heavy Disappear On Hit

		50, //parameters[112]Down Heavy Additional x
		0, //parameters[113]Down Heavy Additional y
		50, //parameters[114]Down Heavy Width
		10, //parameters[115]Down Heavy Height
		40, //parameters[116]Down Heavy Stun Duration
		5, //parameters[117]Down Heavy Scalar X
		-5, //parameters[118]Down Heavy Scalar y
		3, //parameters[119]Down Heavy Fixed x
		-3, //parameters[120]Down Heavy Fixed y
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

		50, //parameters[132]Forward Aerial Additional x
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

		50, //parameters[152]Back Aerial Additional x
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
		0, //parameters[173]Up Aerial Additional y
		50, //parameters[174]Up Aerial Width
		10, //parameters[175]Up Aerial Height
		40, //parameters[176]Up Aerial Stun Duration
		5, //parameters[177]Up Aerial Scalar X
		-5, //parameters[178]Up Aerial Scalar y
		3, //parameters[179]Up Aerial Fixed x
		-3, //parameters[180]Up Aerial Fixed y
		0, //parameters[181]Up Aerial vx
		0, //parameters[182]Up Aerial vy
		0, //parameters[183]Acceleration x
		0, //parameters[184]Acceleration y
		10, //parameters[185]Up Aerial Damage
		10, //parameters[186]Up Aerial Start Up Duraiton
		30, //parameters[187]Up Aerial Active Duration
		10, //parameters[188]Up Aerial End Lag Duration
		1, //parameters[189]Up Aerial Is Attached To Player
		0, //parameters[190] Is Player Attached To It
		0, //parameters[191]Up Aerial Disappear On Hit

		50, //parameters[192]Down Aerial Additional x
		0, //parameters[193]Down Aerial Additional y
		50, //parameters[194]Down Aerial Width
		10, //parameters[195]Down Aerial Height
		40, //parameters[196]Down Aerial Stun Duration
		5, //parameters[197]Down Aerial Scalar X
		-5, //parameters[198]Down Aerial Scalar y
		3, //parameters[199]Down Aerial Fixed x
		-3, //parameters[200]Down Aerial Fixed y
		0, //parameters[201]Down Aerial vx
		0, //parameters[202]Down Aerial vy
		0, //parameters[203]Acceleration x
		0, //parameters[204]Acceleration y
		10, //parameters[205]Down Aerial Damage
		10, //parameters[206]Down Aerial Start Up Duraiton
		30, //parameters[207]Down Aerial Active Duration
		10, //parameters[208]Down Aerial End Lag Duration
		1, //parameters[209]Down Aerial Is Attached To Player
		0, //parameters[210] Is Player Attached To It
		0, //parameters[211]Down Aerial Disappear On Hit

		100, //parameters[212]Forward Special Additional x
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
		0, //parameters[244]Acceleration y
		5, //parameters[245]Up Special Damage
		10, //parameters[246]Up Special Start Up Duraiton
		300, //parameters[247]Up Special Active Duration
		50, //parameters[248]Up Special End Lag Duration
		0, //parameters[249]Up Special Is Attached To Player
		0, //parameters[250] Is Player Attached To It
		1, //parameters[251]Up Special Disappear On Hit

		100, //parameters[252]Down Special Additional x
		0, //parameters[253]Down Special Additional y
		50, //parameters[254]Down Special Width
		10, //parameters[255]Down Special Height
		20, //parameters[256]Down Special Stun Duration
		15, //parameters[257]Down Special Scalar X
		-1, //parameters[258]Down Special Scalar y
		3, //parameters[259]Down Special Fixed x
		-3, //parameters[260]Down Special Fixed y
		2, //parameters[261]Down Special vx
		0.5, //parameters[262]Down Special vy
		0, //parameters[263]Acceleration x
		0, //parameters[264]Acceleration y
		5, //parameters[265]Down Special Damage
		10, //parameters[266]Down Special Start Up Duraiton
		300, //parameters[267]Down Special Active Duration
		50, //parameters[268]Down Special End Lag Duration
		0, //parameters[269]Down Special Is Attached To Player
		0, //parameters[270] Is Player Attached To It
		1, //parameters[271]Down Special Disappear On Hit    
		0, //parameters[272]
		0, //parameters[273]
		0, //parameters[274]
		0, //parameters[275]
		0, //parameters[276]
		0, //parameters[277]
		0, //parameters[278]
		0, //parameters[279]
		0, //parameters[280]
		0, //parameters[281]
		0, //parameters[282]
		0, //parameters[283]
		0, //parameters[284]
		0, //parameters[285]
		0, //parameters[286]
		0, //parameters[287]
		0, //parameters[288]
		0, //parameters[289]
		0, //parameters[290]
		0, //parameters[291]
		0, //parameters[292]
		0, //parameters[293]
		0, //parameters[294]
		0, //parameters[295]
		0, //parameters[296]
		0, //parameters[297]
		0, //parameters[298]
		0, //parameters[299]
		0, //parameters[300]
		0, //parameters[301]
		0, //parameters[302]
		0, //parameters[303]
		0, //parameters[304]
		0, //parameters[305]
		0, //parameters[306]
		0, //parameters[307]
		0, //parameters[308]
		0, //parameters[309]
		0 //parameters[310]  
	} };
};