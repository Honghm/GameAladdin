#pragma once
#define GHOST_SPEED_X 0.05f
#define GHOST_GRAVITY 0.005f

#define GHOST_BBOX_WIDTH 20
#define GHOST_BBOX_HEIGHT 50

#define GHOST_ANI_RUNNING_BEGIN 0
#define GHOST_ANI_RUNNING_END 19

#include "Enemy.h"
#include "debug.h"
#include <math.h>
#include "Weapon.h"
#include "Bone.h"
#include "Player.h"
class Ghost : public Enemy
{
	float borderLeft, borderRight;
	bool isFinish;
	vector<Bone*> mBone;
public:
	Ghost(int direction, float X, float Y, float BorderLeft, float BorderRight, int status);
	virtual ~Ghost();
	virtual void Update(DWORD dt, float xAladdin, float yAladdin, int dAladdin, Player*Aladdin);
	virtual void Render(Camera *camera);
	virtual void GetBoundingBox(float &left, float &top, float &right, float &bottom);
	virtual void GetActiveBoundingBox(float &left, float &top, float &right, float &bottom, int id);
	virtual void SetStatus(int s);
	bool GetIsAttacking() { return isAttacking; }
	void CollisionWithAladdin(Player* Aladdin);
};

