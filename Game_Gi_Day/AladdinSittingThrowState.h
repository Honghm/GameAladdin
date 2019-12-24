#pragma once
#include "Player.h"
#include "AladdinState.h"

class AladdinSittingThrowState :public AladdinState
{
	bool AllowThrow;
public:
	AladdinSittingThrowState(AladdinData *aladdinData);
	~AladdinSittingThrowState();

	void Update(float dt, vector<LPGAMEOBJECT> *coObjects = NULL);

	void HandleKeyboard(std::map<int, bool> keys);

	virtual StateName GetState();

};