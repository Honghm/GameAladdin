#pragma once
#include "GameObject.h"
class ColumnWall : public GameObject
{
private:
	int width;
	int height;
public:
	ColumnWall(float X, float Y, int W, int H, int st);
	~ColumnWall();

	virtual void GetBoundingBox(float &left, float &top, float &right, float &bottom);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects = NULL);
	virtual void Render(Camera * camera);
};

