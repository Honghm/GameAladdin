#pragma once
#include "Player.h"
#include "AladdinState.h"

class AladdinThrowState :public AladdinState
{

public:
	AladdinThrowState(AladdinData *aladdinData);
	~AladdinThrowState();

	void Update(float dt, vector<LPGAMEOBJECT> *coObjects = NULL);

	void HandleKeyboard(std::map<int, bool> keys);

	virtual StateName GetState();

protected:
	bool AllowThrow;

};