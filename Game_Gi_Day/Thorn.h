#pragma once
#include"GameObject.h"
#define THORN_ANI_BEGIN_1 0
#define THORN_ANI_END_1  5
#define THORN_ANI_BEGIN_2 6
#define THORN_ANI_END_2  11
class Thorn :public GameObject
{
private:
	int width;
	int height;
	int state;
public:
	Thorn(float X, float Y, int W, int H, int ST);
	void Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects = NULL);
	void  Render(Camera* camera);
	void  GetBoundingBox(float &l, float &t, float &r, float &b);
	~Thorn();

};

