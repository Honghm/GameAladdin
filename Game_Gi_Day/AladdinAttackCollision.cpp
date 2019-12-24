#include "AladdinAttackCollision.h"
#include "AladdinStandingState.h"
#include "AladdinAttackingState.h"

AladdinAttackCollision::AladdinAttackCollision(AladdinData *aladdinData)
{
	this->mAladdinData = aladdinData;
	this->mAladdinData->player->SetVx(0);
	this->mAladdinData->player->SetVy(0);
}


AladdinAttackCollision::~AladdinAttackCollision()
{
}

void AladdinAttackCollision::Update(float dt, vector<LPGAMEOBJECT>* coObjects)
{
	this->mAladdinData->player->sprite->SetTimeAnimation(100);
	if (this->mAladdinData->player->index <= ALADDIN_ANI_ATTACKCOLLISION_END)
		this->mAladdinData->player->sprite->Update(dt);
	else
		this->mAladdinData->player->SetState(new AladdinStandingState(this->mAladdinData));
}

void AladdinAttackCollision::HandleKeyboard(std::map<int, bool> keys)
{
}

AladdinState::StateName AladdinAttackCollision::GetState()
{
	return  AladdinState::AttackCollision;
}
