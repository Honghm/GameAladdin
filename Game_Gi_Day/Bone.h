#pragma once
#include "GameObject.h"
class Bone :public GameObject
{
	bool isFinish;
	DWORD Start;
	DWORD Now;
public:
	
	Bone(float x, float y);
	virtual ~Bone();
	void Update(DWORD dt);
	void Render(Camera *camera);
	void SetFinish(bool i) { this->isFinish = i; }
	bool GetFinish(){ return isFinish; }
};

