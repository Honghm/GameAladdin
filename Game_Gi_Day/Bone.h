#pragma once
#include "GameObject.h"
class Bone :public GameObject
{

	DWORD Start;
	DWORD Now;
public:
	bool isFinish;
	Bone(float x, float y);
	virtual ~Bone();
	void Update(DWORD dt);
	void Render(Camera *camera);
	void SetFinish(bool i) { this->isFinish = i; }
	bool GetFinish(){ return isFinish; }
	void GetBoundingBox(float &left, float &top, float &right, float &bottom);
};

