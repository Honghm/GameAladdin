#pragma once
#include "Player.h"
#include "AladdinState.h"

class AladdinDeadState :public AladdinState
{

public:
	AladdinDeadState(AladdinData *aladdinData);
	~AladdinDeadState();

	void Update(float dt, vector<LPGAMEOBJECT> *coObjects = NULL);

	void HandleKeyboard(std::map<int, bool> keys);

	virtual StateName GetState();

protected:
	//do bien tien van toc sau moi frame tinh bang pixel / s
	float acceleratorX;

};