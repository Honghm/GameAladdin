#pragma once
#include "Player.h"
#include "AladdinState.h"
class AladdinAttackCollision:public AladdinState
{
public:
	AladdinAttackCollision(AladdinData *aladdinData);

	~AladdinAttackCollision();

	void Update(float dt, vector<LPGAMEOBJECT> *coObjects = NULL);

	void HandleKeyboard(std::map<int, bool> keys);

	virtual StateName GetState();
};

