#pragma once
#include"TextureManager.h"
#include"HealthCol.h"
#include"Life.h"
#include"AppleFont.h"
#include"JewryRock.h"
#include"Font.h"
class Board
{
private:
	static Board* instance;
	HealthCol*health;
	Life*life;
	AppleFont* apple;
	JewryRock *jewryrock;
	Font*mfont;
	string FillNumber(string s, UINT MaxNumber);
public:
	Board();
	~Board();
	void Update(DWORD dt,int health,int life,int apple,int jewryrock);
	void Render(int numapple, int numjewryrock, int numpoint,int numlife);
	static Board *GetInstance;
};

