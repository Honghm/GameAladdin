#include "AladdinBeingAttackState.h"
#include "AladdinStandingState.h"


AladdinBeingAttackState::AladdinBeingAttackState(AladdinData *aladdinData)
{
	Sound::GetInstance()->Play(eSound::sound_AladdinHurt);
	this->mAladdinData = aladdinData;
	this->mAladdinData->player->isAttacking = false;
	isHurting = true;
}



AladdinBeingAttackState::~AladdinBeingAttackState()
{
}

void AladdinBeingAttackState::Update(float dt, vector<LPGAMEOBJECT>* coObjects)
{
	
	this->mAladdinData->player->sprite->SetTimeAnimation(100);
	if (isHurting == true)
	{
		if (this->mAladdinData->player->index < ALADDIN_ANI_BEINGATTACKED_END)
		{
			this->mAladdinData->player->sprite->Update(dt);
		}
		else
		{
			isHurting = false;
		}
		
		this->mAladdinData->player->dx = this->mAladdinData->player->vx * dt;
		this->mAladdinData->player->dy = this->mAladdinData->player->vy * dt;
		this->mAladdinData->player->vy += ALADDIN_GRAVITY_JUMPING * dt;
		
		
	
	}
	else
		this->mAladdinData->player->SetState(new AladdinStandingState(this->mAladdinData));

	
}

void AladdinBeingAttackState::HandleKeyboard(std::map<int, bool> keys)
{

}
AladdinState::StateName AladdinBeingAttackState::GetState()
{
	return AladdinState::BeingAttack;
}
