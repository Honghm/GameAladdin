#pragma once
#include "Player.h"
#include "AladdinState.h"

class AladdinStandingAttackState :public AladdinState
{

public:
	AladdinStandingAttackState(AladdinData *aladdinData);
	~AladdinStandingAttackState();

	void Update(float dt, vector<LPGAMEOBJECT> *coObjects = NULL);

	void HandleKeyboard(std::map<int, bool> keys);

	virtual StateName GetState();

protected:
	//do bien tien van toc sau moi frame tinh bang pixel / s
	float acceleratorX;

};