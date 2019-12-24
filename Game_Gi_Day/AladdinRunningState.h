#pragma once
#include "Player.h"
#include "AladdinState.h"

class AladdinRunningState:public AladdinState
{

public:
	AladdinRunningState(AladdinData *aladdinData);
	~AladdinRunningState();

	void Update(float dt, vector<LPGAMEOBJECT> *coObjects = NULL);

	void HandleKeyboard(std::map<int, bool> keys);

	virtual StateName GetState();
};

 