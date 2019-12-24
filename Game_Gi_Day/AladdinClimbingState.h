#pragma once
#include "Player.h"
#include "AladdinState.h"
class AladdinClimbingState:public AladdinState
{
	bool isClimbing;
public:
	AladdinClimbingState(AladdinData *playerData);
	~AladdinClimbingState();

	void Update(float dt, vector<LPGAMEOBJECT> *coObjects = NULL);

	void HandleKeyboard(std::map<int, bool> keys);

	virtual StateName GetState();
};

