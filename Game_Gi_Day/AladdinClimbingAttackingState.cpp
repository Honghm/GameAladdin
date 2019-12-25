#include "AladdinClimbingAttackingState.h"
#include "AladdinClimbingState.h"
#include "Sound.h"

AladdinClimbingAttackingState::AladdinClimbingAttackingState(AladdinData *aladdinData)
{
	Sound::GetInstance()->Play(eSound::sound_HighSword);
	this->mAladdinData = aladdinData;
	this->mAladdinData->player->SetVx(0);
	this->mAladdinData->player->SetVy(0);
	//isClimbAttack = false;
	this->mAladdinData->player->sprite->SetTimeAnimation(100);
	this->mAladdinData->player->mWeapon.clear();
	this->mAladdinData->player->mWeapon.push_back(new Katana(0, 0));
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
	{
		this->mAladdinData->player->isAttacking == false;
		this->mAladdinData->player->SetState(new AladdinClimbingState(this->mAladdinData));
	}
}

void AladdinClimbingAttackingState::HandleKeyboard(std::map<int, bool> keys)
{
	if (this->mAladdinData->player->isAttacking == false)
	{
		this->mAladdinData->player->Attack(eType::KATANA);
	}
}

AladdinState::StateName AladdinClimbingAttackingState::GetState()
{
	return StateName::ClimbingAttack;
}
