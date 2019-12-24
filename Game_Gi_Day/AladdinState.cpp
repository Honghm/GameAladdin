#include "AladdinState.h"





AladdinState::AladdinState(AladdinData * aladdinData)
{
	this->mAladdinData = aladdinData;
}

AladdinState::AladdinState()
{
}


AladdinState::~AladdinState()
{
}

void AladdinState::Update(float dt, vector<LPGAMEOBJECT> *coObjects)
{
}

void AladdinState::HandleKeyboard(std::map<int, bool> keys)
{
}
