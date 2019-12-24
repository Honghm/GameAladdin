#include "AladdinStandingAttackState.h"
#include "AladdinLookUpState.h"



AladdinStandingAttackState::AladdinStandingAttackState(AladdinData * aladdinData)
{
	this->mAladdinData = aladdinData;
	this->mAladdinData->player->SetVx(0);
	this->mAladdinData->player->SetVy(0);
}

AladdinStandingAttackState::~AladdinStandingAttackState()
{
}

void AladdinStandingAttackState::Update(float dt, vector<LPGAMEOBJECT>* coObjects)
{
	this->mAladdinData->player->sprite->SetTimeAnimation(150);
	if (this->mAladdinData->player->index <= ALADDIN_ANI_STANDINGATTACK_END)
	{
		this->mAladdinData->player->sprite->Update(dt);
	}
	else
		this->mAladdinData->player->SetState(new AladdinLookUpState(this->mAladdinData));
}

void AladdinStandingAttackState::HandleKeyboard(std::map<int, bool> keys)
{
}

AladdinState::StateName AladdinStandingAttackState::GetState()
{
	return AladdinState::StandingAttack;
}
