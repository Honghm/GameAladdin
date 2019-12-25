#pragma once

#define KATANA_STANDING_START 0
#define KATANA_STANDING_END 6
#define KATANA_SITTING_START 7
#define KATANA_SITTING_END 13
#define KATANA_JUMPING_START 0
#define KATANA_JUMPING_END 4
#define KATANA_RUNNING_START 14
#define KATANA_RUNNING_END 20
#define KATANA_CLIMBING_START 14
#define KATANA_CLIMBING_END 20
#include "Weapon.h"

class Katana : public Weapon
{
	int mState; //1: Đứng đánh, 2: Ngồi đánh, 3: Nhảy đánh, 4: Chạy đánh, 5: Leo đánh
public:
	Katana(float Vx, float Vy);
	~Katana();

	void Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects = NULL);
	void Render(Camera *camera);
	void GetBoundingBox(float &left, float &top, float &right, float &bottom);
	void Attack(float X, float Y, int , int st);
	bool ableCollision(GameObject* obj);
	void UpdatePositionFitCharacter();
	void RenderIcon(float X, float Y);
	void SetStatus(int s);
};


