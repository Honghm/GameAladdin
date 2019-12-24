#pragma once
#include "Player.h"
#include "AladdinState.h"

class AladdinAttackingState :public AladdinState
{
	bool AllowAtack;
public:
	AladdinAttackingState(AladdinData *aladdinData);

	~AladdinAttackingState();

	void Update(float dt, vector<LPGAMEOBJECT> *coObjects = NULL);

	void HandleKeyboard(std::map<int, bool> keys);

	virtual StateName GetState();
}; 