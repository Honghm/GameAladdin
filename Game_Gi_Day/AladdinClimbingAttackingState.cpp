#include "AladdinClimbingAttackingState.h"
#include "AladdinClimbingState.h"


AladdinClimbingAttackingState::AladdinClimbingAttackingState(AladdinData *aladdinData)
{
	this->mAladdinData = aladdinData;
	this->mAladdinData->player->SetVx(0);
	this->mAladdinData->player->SetVy(0);
	this->mAladdinData->player->sprite->SetTimeAnimation(100);
}


AladdinClimbingAttackingState::~AladdinClimbingAttackingState()
{
}

void AladdinClimbingAttackingState::Update(float dt, vector<LPGAMEOBJECT>* coObjects)
{
	if (this->mAladdinData->player->index <= ALADDIN_ANI_CLIMBINGATTACK_END)
	{
		this->mAladdinData->player->sprite->Update(dt);//cập nhật frame mới
	}
	else
		this->mAladdinData->player->SetState(new AladdinClimbingState(this->mAladdinData));
}

void AladdinClimbingAttackingState::HandleKeyboard(std::map<int, bool> keys)
{
	if (keys[DIK_LEFT])
		this->mAladdinData->player->SetDirection(-1);
	if (keys[DIK_RIGHT])
		this->mAladdinData->player->SetDirection(1);
}

AladdinState::StateName AladdinClimbingAttackingState::GetState()
{
	return StateName::ClimbingAttack;
}
