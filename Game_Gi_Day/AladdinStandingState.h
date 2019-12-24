#pragma once
#include "AladdinState.h"

class AladdinStandingState : public AladdinState
{
	DWORD TimeStart;
	DWORD TimeNow;
public:
	AladdinStandingState(AladdinData *aladdinData);
	~AladdinStandingState();

	void Update(float dt, vector<LPGAMEOBJECT> *coObjects = NULL);

	void HandleKeyboard(std::map<int, bool> keys);

	virtual StateName GetState();
};

