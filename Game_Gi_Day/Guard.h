#pragma once

#define GUARD_SPEED_X 0.07f
#define GUARD_GRAVITY 0.005f

#define GUARD_BBOX_WIDTH 50
#define GUARD_BBOX_HEIGHT 60

#define GUARD_ANI_RUNNING_BEGIN 12
#define GUARD_ANI_RUNNING_END 20
#define GUARD_ANI_AROUSE_BEGIN 0
#define GUARD_ANI_AROUSE_END 12
#define GUARD_ANI_ATTACK1_BEGIN 21
#define GUARD_ANI_ATTACK1_END 24
#define GUARD_ANI_ATTACK2_BEGIN 25
#define GUARD_ANI_ATTACK2_END 33

#include "Enemy.h"
#include "debug.h"
#include <math.h>
#include "Player.h"
class Guard : public Enemy
{
	float borderLeft, borderRight;
	int dem = 0;
	bool isCollisionWithAladdin;
	//bool isAttacking;
public:
	Guard(int direction, float X, float Y, float BorderLeft, float BorderRight, int status);
	virtual ~Guard();
	virtual void Update(DWORD dt,Player* Aladdin);
	virtual void Render(Camera *camera);
	virtual void GetBoundingBox(float &left, float &top, float &right, float &bottom);
	virtual void GetActiveBoundingBox(float &left, float &top, float &right, float &bottom, int id);
	virtual void SetStatus(int s);
	bool GetIsAttacking() { return isAttacking; }
};