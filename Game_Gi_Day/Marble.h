#pragma once
#include"GameObject.h"
#define Marble_ANI_BEGIN_1 0
#define Marble_ANI_END_1  28
#define Marble_ANI_BEGIN_2 30
#define Marble_ANI_END_2  58
class Marble :public GameObject
{
private:
	int width;
	int height;
	int status;
	int state;
public:
	Marble(float X, float Y, int W, int H, int ST);
	void Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects = NULL);
	void  Render(Camera* camera);
	void  GetBoundingBox(float &l, float &t, float &r, float &b);

	~Marble();

};

