#pragma once
#define BOSS_ANI_ATTACK_BEGIN 0
#define BOSS_ANI_ATTACK_END 7
#define BOSS_ANI_SNAKE_BEGIN 8
#define BOSS_ANI_SNAKE_END 20
#define BOSS_ANI_SNAKE_ATTACK_BEGIN 26
#define BOSS_ANI_SNAKE_ATTACK_END 36

#include "Enemy.h"
#include "debug.h"
#include <math.h>
#include "Bullet.h"
#include "Burn.h"
#include "Player.h"
class Boss : public Enemy
{
	float borderLeft, borderRight;
	vector<Bullet*>mBullet;
	vector<Burn*>mBurn;
	float max_X = 0, max_Y = 0;
	int Health;
	int state;
	bool isSnake;
	vector<Effect*> listEffect;
public:
	Boss(int direction, float X, float Y, int status);
	virtual ~Boss();
	virtual void Update(DWORD dt, float xAladdin, float yAladdin, int dAladdin, Player* Aladdin);
	virtual void Render(Camera *camera);
	virtual void GetBoundingBox(float &left, float &top, float &right, float &bottom);
	virtual void GetActiveBoundingBox(float &left, float &top, float &right, float &bottom, int id);
	virtual void SetStatus(int s);
	bool GetIsAttacking() { return isAttacking; }
	void SetHealth(int a) { Health = a; }
	int GetHealth() { return Health; }
	void SetState(int a);
	void CollisionWithAladdin(Player* Aladdin);
};

