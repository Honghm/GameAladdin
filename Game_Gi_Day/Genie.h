#pragma once
#include"GameObject.h"
#include "Item.h"
#define GENIE_ANI_BEGIN 0
#define GENIE_ANI_END  3
class Genie :public Item
{
private:
	int width;
	int height;
public:
	Genie(float X, float Y, int W, int H, int ST);
	void Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects = NULL);
	void  Render(Camera* camera);
	void  GetBoundingBox(float &l, float &t, float &r, float &b);
	~Genie();

};
