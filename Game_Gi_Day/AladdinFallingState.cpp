#include "AladdinFallingState.h"
#include "AladdinStandingState.h"


AladdinFallingState::AladdinFallingState(AladdinData *aladdinData)
{
	this->mAladdinData = aladdinData;
}


AladdinFallingState::~AladdinFallingState()
{

}

void AladdinFallingState::Update(float dt, vector<LPGAMEOBJECT>* coObjects)
{
	this->mAladdinData->player->dx = this->mAladdinData->player->vx * dt;
	this->mAladdinData->player->dy = this->mAladdinData->player->vy * dt;
	this->mAladdinData->player->vy += ALADDIN_GRAVITY_JUMPING * dt;
}

AladdinState::StateName AladdinFallingState::GetState()
{
	return AladdinState::Falling;
}
