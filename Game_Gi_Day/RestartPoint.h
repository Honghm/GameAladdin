#pragma once
#include"GameObject.h"
#include "Item.h"
#define RESTARTPOINT_ANI_BEGIN 0
#define RESTARTPOINT_ANI_END  9
class RestartPoint :public Item
{
private:
	int width;
	int height;
public:
	RestartPoint(float X, float Y, int W, int H, int ST);
	void Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects = NULL);
	void  Render(Camera* camera);
	void  GetBoundingBox(float &l, float &t, float &r, float &b);
	~RestartPoint();

};