#pragma once
#include "Player.h"
#include "AladdinState.h"
#include "GameObject.h"
class AladdinJumping2State :public AladdinState
{

public:
	AladdinJumping2State(AladdinData *aladdinData);
	~AladdinJumping2State();

	void Update(float dt, vector<LPGAMEOBJECT> *coObjects = NULL);

	void HandleKeyboard(std::map<int, bool> keys);

	virtual StateName GetState();
};