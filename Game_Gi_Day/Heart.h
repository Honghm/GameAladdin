#pragma once
#include"GameObject.h"
#include "Item.h"
#define HEART_ANI_BEGIN 0
#define HEART_ANI_END  2
class Heart :public Item
{
private:
	int width;
	int height;
public:
	Heart(float X, float Y, int W, int H, int ST);
	void Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects = NULL);
	void  Render(Camera* camera);
	void  GetBoundingBox(float &l, float &t, float &r, float &b);
	~Heart();

};
