#pragma once
#include "Player.h"
#include "AladdinState.h"

class AladdinBeingAttackState :public AladdinState
{
	bool isHurting;
public:
	AladdinBeingAttackState(AladdinData *aladdinData);
	~AladdinBeingAttackState();

	void Update(float dt, vector<LPGAMEOBJECT> *coObjects = NULL);

	void HandleKeyboard(std::map<int, bool> keys);

	virtual StateName GetState();

protected:
	//do bien tien van toc sau moi frame tinh bang pixel / s
	float acceleratorX;

};