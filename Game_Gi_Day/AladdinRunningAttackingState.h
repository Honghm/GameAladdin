#pragma once
#include "Player.h"
#include "AladdinState.h"
class AladdinRunningAttackingState:public AladdinState
{
	//bool isRunAttack;
public:
	AladdinRunningAttackingState(AladdinData *aladdinData);
	~AladdinRunningAttackingState();
	void Update(float dt, vector<LPGAMEOBJECT> *coObjects = NULL);

	void HandleKeyboard(std::map<int, bool> keys);

	virtual StateName GetState();
};

