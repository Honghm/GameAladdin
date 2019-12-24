#include "AladdinRunningAttackingState.h"
#include "AladdinData.h"
#include "AladdinStandingState.h"

AladdinRunningAttackingState::AladdinRunningAttackingState(AladdinData *playerData)
{
	this->mAladdinData = playerData;
	this->mAladdinData->player->AllowAttack = true;
	//isRunAttack = false;
	this->mAladdinData->player->mWeapon.clear();
	this->mAladdinData->player->mWeapon.push_back(new Katana());
}


AladdinRunningAttackingState::~AladdinRunningAttackingState()
{
}

void AladdinRunningAttackingState::Update(float dt, vector<LPGAMEOBJECT>* coObjects)
{
	if (this->mAladdinData->player->isHurting)
		return;
	if (this->mAladdinData->player->AllowAttack == true)
	{
		this->mAladdinData->player->sprite->SetTimeAnimation(100);
		if (this->mAladdinData->player->index < ALADDIN_ANI_WALKINGATTACKING_END)
		{
			this->mAladdinData->player->sprite->Update(dt);
			this->mAladdinData->player->dx = this->mAladdinData->player->vx*dt;
			this->mAladdinData->player->x += this->mAladdinData->player->dx;
		}
		else
			this->mAladdinData->player->AllowAttack = false;
	}
	else
	{
		this->mAladdinData->player->sprite->SelectFrame(ALADDIN_ANI_WALKING_BEGIN);
		this->mAladdinData->player->SetState(new AladdinStandingState(this->mAladdinData));
	}
}

void AladdinRunningAttackingState::HandleKeyboard(std::map<int, bool> keys)
{
	if (this->mAladdinData->player->isAttacking == false)
	{
		this->mAladdinData->player->Attack(eType::KATANA);
	}
	if (keys[DIK_RIGHT])
	{
		this->mAladdinData->player->SetDirection(1);
		this->mAladdinData->player->vx = ALADDIN_WALKING_SPEED;
	}
	else if (keys[DIK_LEFT])
	{
		this->mAladdinData->player->SetDirection(-1);
		this->mAladdinData->player->vx = ALADDIN_WALKING_SPEED * -1;
	}
}

AladdinState::StateName AladdinRunningAttackingState::GetState()
{
	return AladdinState::RunningAttacking;
}
