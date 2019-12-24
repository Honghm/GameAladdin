#ifndef _DEFINE_H__
#define _DEFINE_H__


#include <fstream> 
#include <string>
#include <stdio.h>
#include <Windows.h>  
#include <iostream>
#include <map>
#include <algorithm>
#include <d3dx9.h>
#include <stdlib.h>
#include <iomanip>
#include <d3d9.h>
#include <vector>
#include <iostream>



using namespace std;


#define COLOR_BLACK D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f)  
#define COLOR_KEY D3DXCOLOR(0.0f, 0.0f, 0.0f, 0.0f) 


#define SCREEN_WIDTH 650
#define SCREEN_HEIGHT 435
#define DEFAULT_CELL_WIDTH		584
#define DEFAULT_CELL_HEIGHT		280

#define IS_DEBUG_RENDER_BBOX isDebug_RenderBBox

#define MAX_FRAME_RATE 90

#define COLOR_BACKGROUND_DEFAULT D3DCOLOR_XRGB(0, 0, 0) // Màu đen
#define COLOR_1 D3DCOLOR_XRGB(243, 0, 200) // Màu đen
#define COLOR_2 D3DCOLOR_XRGB(0, 3, 189) // Màu đen
#define COLOR_3 D3DCOLOR_XRGB(255, 125, 34) // Màu đen
#define COLOR_4 D3DCOLOR_XRGB(193, 47, 0) // Màu đen



#define TIME_LIMIT_WAIT_RESET_GAME 300 // Thời gian chờ vẽ màn màu đen khi reset game

#define INACTIVE					1
#define ACTIVE						2
#define DEATH						3

extern D3DCOLOR D3DCOLOR_BACKGROUND; // màu nền game
extern D3DCOLOR C_1;
extern D3DCOLOR C_2;
extern D3DCOLOR C_3;
extern D3DCOLOR C_4;
extern  vector<D3DCOLOR> listColorScreen;

extern int isDebug_Untouchable;
extern int isDebug_RenderBBox;


// ID của Sprite, object
enum eType
{
	ALADDIN = 1,
	ALADDIN_TRANSPARENT = 2,
	//ALADDIN_DEADTH = 3,

	//Platform
	TAO = 35,
	ROCK = 38,
	THORN = 39,
	MARBLE = 40,
	REDROCK = 41,
	GENIE = 42,
	HEART = 43,
	COLUMN1 = 44,
	COLUMN2 = 45,
	COLUMN3 = 46,
	COLUMN4 = 47,
	HEARTCOL = 48,
	FACEALADDIN = 49,
	NUMBER=50,
	RESTARTPOINT=51,

	//ground
	BRICK = 21,
	BRICK_TRANSPARENT = 22,
	BUTTERFLY = 23,
	THEBIRD = 24,

	//map
	MAP1 = 101,
	MAP2 = 102,
	BACKGROUND = 103,

	//others
	RENDERBBOX = 110,
	OBJECT_HIDDEN = 111,
	OBJECT_CLIMB = 112,
	OBJECT_CLIMBUP = 113,
	OBJECT_PUSH = 114,

	// weapon
	WEAPON = 30,
	APPLE = 31,
	KATANA = 32,//katana ngồi đánh
	KATANA_1 = 33,//katana đứng đánh
	BONE = 34,

	//Enemy
	GUARD = 10,
	SOLDIER = 11,
	GHOST = 12,
	BAT = 13,

	//Boss
	BOSS = 200,
	BULLET = 201,
	BURN = 202,
	BURN_1 = 203,
	EFFECT_1 = 500,
	EFFECT_2 = 501,
	EFFECT_3 = 502,
	EFFECT_4 = 503,
};





typedef D3DXVECTOR3 GVector3;
typedef D3DXVECTOR2 GVector2;
#define VECTOR2ZERO GVector2(0.0f, 0.0f)





#define GAMEOVER_SELECT_CONTINUE 0
#define GAMEOVER_SELECT_END 1




#ifndef CHECK_OBJECT_IN_CAMERA // Kiểm tra GameObject có nằm trong camera ko?
#define CHECK_OBJECT_IN_CAMERA(obj) \
checkObjectInCamera(obj->GetX(), obj->GetY(), (float)obj->GetWidth(),  (float)obj->GetHeight())
#endif


#ifndef SAFE_DELETE
#define SAFE_DELETE(ptr) \
if(ptr) \
{\
	delete (ptr); \
	ptr = nullptr; \
} \

#endif

#endif 