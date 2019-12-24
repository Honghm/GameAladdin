#pragma once
#include"GameObject.h"
#include "Item.h"
#define REDROCK_ANI_BEGIN 0
#define REDROCK_ANI_END  8
class RedRock :public Item
{
private:
	int width;
	int height;
public:
	RedRock(float X, float Y, int W, int H, int ST);
	void Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects = NULL);
	void  Render(Camera* camera);
	void  GetBoundingBox(float &l, float &t, float &r, float &b);
	~RedRock();

};
