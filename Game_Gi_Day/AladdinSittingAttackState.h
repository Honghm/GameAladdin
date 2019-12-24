#pragma once
#include "Player.h"
#include "AladdinState.h"

class AladdinSittingAttackState :public AladdinState
{
	bool isSittingAttack;
public:
	AladdinSittingAttackState(AladdinData *aladdinData);
	~AladdinSittingAttackState();

	void Update(float dt, vector<LPGAMEOBJECT> *coObjects = NULL);

	void HandleKeyboard(std::map<int, bool> keys);

	virtual StateName GetState();

};