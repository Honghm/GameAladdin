#pragma once
#include"TextureManager.h"
#include"Sprite.h"
#define ANI_NUMBER_0 0
#define ANI_NUMBER_1 1
#define ANI_NUMBER_2 2
#define ANI_NUMBER_3 3
#define ANI_NUMBER_4 4
#define ANI_NUMBER_5 5
#define ANI_NUMBER_6 6
#define ANI_NUMBER_7 7
#define ANI_NUMBER_8 8
#define ANI_NUMBER_9 9
class Font
{
	static Font * _instance;
	CTexture *texture;
	CSprite *sprite;
public:
	Font();
	~Font();
	static Font * GetInstance();
	void Render(float x, float y, const string & s);
	void Set(int left, int top, int right, int bottom);
};
