﻿#include "AladdinClimbingThowingState.h"
#include "AladdinClimbingState.h"


AladdinClimbingThowingState::AladdinClimbingThowingState(AladdinData * aladdinData)
{
	this->mAladdinData = aladdinData;
	this->mAladdinData->player->SetVx(0);
	this->mAladdinData->player->SetVy(0);
	this->mAladdinData->player->sprite->SetTimeAnimation(100);
	this->mAladdinData->player->mWeapon.clear();
	this->mAladdinData->player->mWeapon.push_back(new Apple());
}


AladdinClimbingThowingState::~AladdinClimbingThowingState()
{
}

void AladdinClimbingThowingState::Update(float dt, vector<LPGAMEOBJECT>* coObjects)
{
	if (this->mAladdinData->player->index <= ALADDIN_ANI_CLIMBINGTHOW_END)
	{
		this->mAladdinData->player->sprite->Update(dt);//cập nhật frame mới
	}
	else
	{
		this->mAladdinData->player->isAttacking = false;
		this->mAladdinData->player->SetState(new AladdinClimbingState(this->mAladdinData));
	}
}

void AladdinClimbingThowingState::HandleKeyboard(std::map<int, bool> keys)
{
	if (this->mAladdinData->player->isAttacking == false)
	{
		this->mAladdinData->player->Attack(eType::APPLE);
	}
	if (keys[DIK_LEFT])
		this->mAladdinData->player->SetDirection(-1);
	if (keys[DIK_RIGHT])
		this->mAladdinData->player->SetDirection(1);
}

AladdinState::StateName AladdinClimbingThowingState::GetState()
{
	return StateName::ClimbingThow;
}
