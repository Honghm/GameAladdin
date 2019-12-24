#pragma once
#include "Player.h"
#include "AladdinState.h"
class AladdinClimbingAttackingState:public AladdinState
{
public:
	AladdinClimbingAttackingState(AladdinData *aladdinData);
	~AladdinClimbingAttackingState();
	void Update(float dt, vector<LPGAMEOBJECT> *coObjects = NULL);

	void HandleKeyboard(std::map<int, bool> keys);

	virtual StateName GetState();
};

