#pragma once
#include "Player.h"
#include "AladdinState.h"

class AladdinJumpingAttackState :public AladdinState
{
	bool isJumpAttack;
public:
	AladdinJumpingAttackState(AladdinData *aladdinData);
	~AladdinJumpingAttackState();
	 
	void Update(float dt, vector<LPGAMEOBJECT> *coObjects = NULL);

	void HandleKeyboard(std::map<int, bool> keys);

	virtual StateName GetState();
};