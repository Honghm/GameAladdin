#pragma once
#include "Player.h"
#include "AladdinState.h"
#include"AladdinFallingState.h"


class AladdinJumpingThrowState :public AladdinState
{

	bool AllowThrow;
public:
	AladdinJumpingThrowState(AladdinData *aladdinData);
	~AladdinJumpingThrowState();

	void Update(float dt, vector<LPGAMEOBJECT> *coObjects = NULL);

	void HandleKeyboard(std::map<int, bool> keys);

	virtual StateName GetState();

};