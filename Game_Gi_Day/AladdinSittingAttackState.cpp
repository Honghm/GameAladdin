#include "AladdinSittingAttackState.h"
#include "AladdinSitting.h"



AladdinSittingAttackState::AladdinSittingAttackState(AladdinData * aladdinData)
{
	this->mAladdinData = aladdinData;
	this->mAladdinData->player->SetVx(0);
	this->mAladdinData->player->SetVy(0);
	isSittingAttack = false;
	this->mAladdinData->player->mWeapon.clear();
	this->mAladdinData->player->mWeapon.push_back(new Katana());
}

AladdinSittingAttackState::~AladdinSittingAttackState()
{
}

void AladdinSittingAttackState::Update(float dt, vector<LPGAMEOBJECT>* coObjects)
{
	this->mAladdinData->player->sprite->SetTimeAnimation(85);
	if (isSittingAttack == true)
	{
		if (this->mAladdinData->player->index <= ALADDIN_ANI_SITTINGATTACK_END)
		{
			this->mAladdinData->player->sprite->Update(dt);//cập nhật frame mới
		}
	}
	else
	{
		this->mAladdinData->player->isAttacking = false;
	}
	if (this->mAladdinData->player->isSitting == false)
	{
		isSittingAttack = false;
		this->mAladdinData->player->SetState(new AladdinStandingState(this->mAladdinData));
	}
}

void AladdinSittingAttackState::HandleKeyboard(std::map<int, bool> keys)
{

	if (this->mAladdinData->player->isAttacking == false)
	{
		this->mAladdinData->player->Attack(eType::KATANA);
		isSittingAttack = true;
	}
}

AladdinState::StateName AladdinSittingAttackState::GetState()
{
	return AladdinState::SittingAttack;
}
