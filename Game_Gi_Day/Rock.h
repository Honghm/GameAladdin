#pragma once
#include"GameObject.h"
#define ROCK_ANI_BEGIN_1 0
#define ROCK_ANI_END_1  7
#define ROCK_ANI_BEGIN_2 8
#define ROCK_ANI_END_2  15
class Rock:public GameObject
{
private:
	int width;
	int height;
	int state;
public:
	Rock(float X,float Y,int W,int H,int ST);
	 void Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects = NULL);
	 void  Render(Camera* camera);
     void  GetBoundingBox(float &l, float &t, float &r, float &b);
	~Rock();

};

