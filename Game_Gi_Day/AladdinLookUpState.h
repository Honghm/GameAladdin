#pragma once
#include"AladdinState.h"
#include"Player.h"
#include"AladdinStandingState.h"
class AladdinLookUpState :public AladdinState
{
	DWORD TimeStart;
	DWORD TimeNow;
public:
	AladdinLookUpState(AladdinData *aladdinData);
	~AladdinLookUpState();

	void Update(float dt, vector<LPGAMEOBJECT> *coObjects = NULL);

	void HandleKeyboard(std::map<int, bool> keys);

	virtual StateName GetState();
};