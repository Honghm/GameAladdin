#pragma once
#include "Player.h"
#include "AladdinState.h"
class AladdinClimbingThowingState:public AladdinState
{
public:
	AladdinClimbingThowingState(AladdinData *aladdinData);
	~AladdinClimbingThowingState();
	void Update(float dt, vector<LPGAMEOBJECT> *coObjects = NULL);

	void HandleKeyboard(std::map<int, bool> keys);

	virtual StateName GetState();
};

