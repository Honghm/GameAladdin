#pragma once
#include"AladdinState.h"
class AladdinWaitting_1:public AladdinState
{
public:
	AladdinWaitting_1(AladdinData *aladdinData);
	~AladdinWaitting_1();
	void Update(float dt, vector<LPGAMEOBJECT> *coObjects = NULL);

	void HandleKeyboard(std::map<int, bool> keys);

	virtual StateName GetState();

protected:
};

