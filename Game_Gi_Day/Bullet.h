#pragma once
#include "GameObject.h"

class Bullet :public GameObject
{
	bool isFinish;

public:
	int status;
	Bullet(float x, float y);
	virtual ~Bullet();
	void Update(DWORD dt, float xAladdin, float yAladdin, int direction);
	void Render(Camera *camera);
	void SetFinish(bool i) { this->isFinish = i; }
	bool GetFinish() { return isFinish; }
	virtual void GetBoundingBox(float &left, float &top, float &right, float &bottom);
};

