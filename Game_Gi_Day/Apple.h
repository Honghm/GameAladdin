#pragma once
#include "Weapon.h"


#define APPLE_GRAVITY 0.0015f
#define APPLE_JUMP_GRAVITY 0.005f
class Apple:public Weapon
{
	
	int mState;
public:
	static Apple *Instance;
	Apple();
	virtual ~Apple();
	void Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects = NULL);
	void Attack(float X, float Y, int Direction, int st);
	void RenderIcon(float X, float Y);
	void UpdatePositionFitCharacter();
	void Render(Camera *camera);
	static Apple  *getInstance();
};

