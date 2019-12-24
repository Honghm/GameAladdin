#include "AladdinAttackingState.h"
#include "AladdinStandingState.h"
#include "AladdinJumpingAttackState.h"

AladdinAttackingState::AladdinAttackingState(AladdinData *aladdinData)
{
	this->mAladdinData = aladdinData;
	this->mAladdinData->player->SetVx(0);
	this->mAladdinData->player->SetVy(0);
	this->mAladdinData->player->mWeapon.clear();
	this->mAladdinData->player->mWeapon.push_back(new Katana());
	AllowAtack = true;
}



AladdinAttackingState::~AladdinAttackingState()
{
}

void AladdinAttackingState::Update(float dt, vector<LPGAMEOBJECT>* coObjects)
{
	
	this->mAladdinData->player->sprite->SetTimeAnimation(100);
	if (AllowAtack == true)
	{
		if (this->mAladdinData->player->index < ALADDIN_ANI_ATTACKING_END)
		{
			this->mAladdinData->player->sprite->Update(dt);//cập nhật frame mới
		}
		else
			AllowAtack = false;
	}
	else
	{
		this->mAladdinData->player->isAttacking = false;
	}
}

void AladdinAttackingState::HandleKeyboard(std::map<int, bool> keys)
{
	if (AllowAtack == true)
	{
		if (this->mAladdinData->player->isAttacking == false)
		{
			this->mAladdinData->player->Attack(eType::KATANA);
		}
	}
	else
	{
		if (keys[DIK_LEFT])
		{
			this->mAladdinData->player->SetDirection(-1);
			this->mAladdinData->player->SetState(new AladdinRunningState(this->mAladdinData));
		}
		else if (keys[DIK_RIGHT])
		{
			this->mAladdinData->player->SetDirection(1);
			this->mAladdinData->player->SetState(new AladdinRunningState(this->mAladdinData));
		}
		else
			this->mAladdinData->player->SetState(new AladdinStandingState(this->mAladdinData));
	}
}
AladdinState::StateName AladdinAttackingState::GetState()
{
	return AladdinState::Attacking;
}
