#pragma once
#pragma once
#define BAT_SPEED_X 0.5f
#define BAT_SPEED_Y 0.5f
#define BAT_GRAVITY 0.005f

#define BAT_BBOX_WIDTH 10
#define BAT_BBOX_HEIGHT 10

#define BAT_ANI_RUNNING_BEGIN 0
#define BAT_ANI_RUNNING_END 11
#include "Enemy.h"
#include "debug.h"
#include <math.h>
class Bat : public Enemy
{
	float borderLeft, borderRight;
	float backupOx, backupOy;
	int di = 0;
	float Ox, Oy;
	
public:
	Bat(int direction, float X, float Y, float BorderLeft, float BorderRight, int status);
	virtual ~Bat();
	virtual void Update(DWORD dt, float xAladdin, float yAladdin, int dAladdin, vector<LPGAMEOBJECT> *coObjects = NULL);
	virtual void Render(Camera *camera);
	virtual void GetBoundingBox(float &left, float &top, float &right, float &bottom);
	virtual void GetActiveBoundingBox(float &left, float &top, float &right, float &bottom, int id);
	virtual void SetStatus(int s);
	bool GetIsAttacking() { return isAttacking; }
	void Move(float &x, float &y, int st);
	bool GetFlag() { return flag; }
	void SetFlag(bool a) { this->flag = a; }
};

