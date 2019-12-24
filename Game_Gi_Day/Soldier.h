#pragma once
#define SOLDIER_SPEED_X 0.05f
#define SOLDIER_GRAVITY 0.005f

#define SOLDIER_BBOX_WIDTH 20
#define SOLDIER_BBOX_HEIGHT 50

#define SOLDIER_ANI_RUNNING_BEGIN 0
#define SOLDIER_ANI_RUNNING_END 7
#define SOLDIER_ANI_ATTACK_BEGIN 8
#define SOLDIER_ANI_ATTACK_END 15


#include "Enemy.h"
#include "debug.h"
#include <math.h>
class Soldier : public Enemy
{
	float borderLeft, borderRight;
public:
	Soldier(int direction, float X, float Y, float BorderLeft, float BorderRight, int status);
	virtual ~Soldier();
	virtual void Update(DWORD dt, float xAladdin, float yAladdin, int dAladdin, vector<LPGAMEOBJECT> *coObjects = NULL);
	virtual void Render(Camera *camera);
	virtual void GetBoundingBox(float &left, float &top, float &right, float &bottom);
	virtual void GetActiveBoundingBox(float &left, float &top, float &right, float &bottom, int id);
	virtual void SetStatus(int s);
	bool GetIsAttacking() { return isAttacking; }
};

