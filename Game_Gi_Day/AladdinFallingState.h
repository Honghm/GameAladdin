#pragma once
#include "Player.h"
#include "AladdinState.h"

class AladdinFallingState :public AladdinState
{
public:
	AladdinFallingState(AladdinData *aladdinData);
	~AladdinFallingState();

	void Update(float dt, vector<LPGAMEOBJECT> *coObjects = NULL);

	virtual StateName GetState();
};

