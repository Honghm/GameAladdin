#pragma once
#include "GameObject.h"
class ObjectHidden : public GameObject
{
private:
	int width;
	int height;
	
public:
	float b_top, b_bottom;
	ObjectHidden(float X, float Y, int W, int H, float bt, float bb, int st);
	~ObjectHidden();

	virtual void GetBoundingBox(float &left, float &top, float &right, float &bottom);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects = NULL);
	virtual void Render(Camera * camera);

};

