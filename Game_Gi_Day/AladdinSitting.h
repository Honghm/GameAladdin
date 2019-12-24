#pragma once
#include"AladdinState.h"
#include"Player.h"
#include"AladdinStandingState.h"
class AladdinSitting:public AladdinState
{
	DWORD TimeStart;
	DWORD TimeNow;
	bool isSitting;
public:
	AladdinSitting(AladdinData *aladdinData);
	~AladdinSitting();

	void Update(float dt, vector<LPGAMEOBJECT> *coObjects = NULL);

	void HandleKeyboard(std::map<int, bool> keys);

	virtual StateName GetState();
};

