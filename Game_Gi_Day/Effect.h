#pragma once
#include "GameObject.h"
class Effect : public GameObject
{
private:
	bool isFinish;
	int state;
public:
	Effect(float X, float Y, int st, int state);
	~Effect();

	//virtual void GetBoundingBox(float &left, float &top, float &right, float &bottom);
	virtual void Update(DWORD dt);
	virtual void Render(Camera * camera);
	bool IsFinish() { return isFinish; };
	void UpdatePositionFitCharacter(int st);
};