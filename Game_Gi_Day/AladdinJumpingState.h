#pragma once
#include "Player.h"
#include "AladdinState.h"
#include "GameObject.h"

class AladdinJumpingState : public AladdinState
{
	bool allowMove;
	bool isJumping;
public:
	AladdinJumpingState(AladdinData *playerData);
	~AladdinJumpingState();

	void Update(float dt, vector<LPGAMEOBJECT> *coObjects = NULL);

	void HandleKeyboard(std::map<int, bool> keys);

	virtual StateName GetState();
};

