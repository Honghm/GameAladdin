#include "AladdinJumpingAttackState.h"
#include "AladdinStandingState.h"
#include"AladdinFallingState.h"

AladdinJumpingAttackState::AladdinJumpingAttackState(AladdinData *aladdinData)
{
	this->mAladdinData = aladdinData;
	this->mAladdinData->player->sprite->SetTimeAnimation(150);
	isJumpAttack = false;
	this->mAladdinData->player->mWeapon.clear();
	this->mAladdinData->player->mWeapon.push_back(new Katana());
}



AladdinJumpingAttackState::~AladdinJumpingAttackState()
{
}

void AladdinJumpingAttackState::Update(float dt, vector<LPGAMEOBJECT>* coObjects)
{
	if (this->mAladdinData->player->isHurting)
		return;
	this->mAladdinData->player->sprite->SetTimeAnimation(100);
	
		if(this->mAladdinData->player->index < ALADDIN_ANI_JUMPINGATTACK_END)
		{
			this->mAladdinData->player->sprite->Update(dt);
			this->mAladdinData->player->dx = this->mAladdinData->player->vx * dt;
			this->mAladdinData->player->dy = this->mAladdinData->player->vy * dt;
			this->mAladdinData->player->vy += ALADDIN_GRAVITY_JUMPING * dt;
		}
	else
		this->mAladdinData->player->SetState(new AladdinFallingState(this->mAladdinData));
}

void AladdinJumpingAttackState::HandleKeyboard(std::map<int, bool> keys)
{
	if (this->mAladdinData->player->isAttacking == false)
	{
		this->mAladdinData->player->Attack(eType::KATANA);
		isJumpAttack = true;
	}
}
AladdinState::StateName AladdinJumpingAttackState::GetState()
{
	return AladdinState::JumpingAttack;
}
