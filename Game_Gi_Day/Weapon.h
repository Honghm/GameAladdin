#pragma once

#include "define.h"
#include "Camera.h"
#include "Texture.h"
#include "Sprite.h" 
#include "GameObject.h"
#include "Effect.h"
#include "Item.h"
#include "Enemy.h"
#include "Brick.h"


class Weapon : public GameObject
{
	static Weapon * _Instance;
protected:
	int status;
	bool isFinish;
	DWORD LastTimeAttack;// Thời điểm tấn công cuối cùng
public:
	Weapon();
	~Weapon();
	bool isAttacked;
	int GetDirection();
	void SetDirection(int Direction);
	virtual void Attack(float X, float Y, int Direction, int st);
	virtual void SelectFrame(int state);
	virtual void GetBoundingBox(float &left, float &top, float &right, float &bottom);
	virtual void Render(Camera *camera);
	virtual void UpdatePositionFitCharacter();
	virtual void RenderIcon(float X, float Y) = 0;
	virtual bool ableCollision(GameObject* obj);
	virtual bool CollisionWithBrick(vector<LPGAMEOBJECT> *coObjects);
	bool GetFinish();
	int GetStatus();
	virtual void SetStatus(int s);
	void SetFinish(bool b);

	DWORD GetLastTimeAttack();
};


