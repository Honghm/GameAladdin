#pragma once
#include"GameObject.h"
#include "Item.h"

class Continue:public Item
{
private:
	int width;
	int height;
public:
	Continue(float X, float Y, int W, int H, int ST);
	void Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects = NULL);
	void  Render(Camera* camera);
	void  GetBoundingBox(float &l, float &t, float &r, float &b);
	~Continue();

};
