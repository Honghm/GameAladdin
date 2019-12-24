#pragma once
#include"GameObject.h"
#include "Item.h"
#define TAO_ANI_BEGIN 0
#define TAO_ANI_END  5
class Tao :public Item
{
private:
	int width;
	int height;
public:
	Tao(float X, float Y, int W, int H, int ST);
	void Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects = NULL);
	void  Render(Camera* camera);
	void  GetBoundingBox(float &l, float &t, float &r, float &b);
	~Tao();

};
