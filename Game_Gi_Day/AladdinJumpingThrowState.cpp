#include "AladdinJumpingThrowState.h"


AladdinJumpingThrowState::AladdinJumpingThrowState(AladdinData *aladdinData)
{
	this->mAladdinData = aladdinData;
	this->mAladdinData->player->mWeapon.clear();
	this->mAladdinData->player->mWeapon.push_back(new Apple());
	AllowThrow = true;
	Sound::GetInstance()->Play(eSound::sound_ThrowApple);
}



AladdinJumpingThrowState::~AladdinJumpingThrowState()
{
}

void AladdinJumpingThrowState::Update(float dt, vector<LPGAMEOBJECT>* coObjects)
{
	this->mAladdinData->player->sprite->SetTimeAnimation(100);
	if (this->mAladdinData->player->index < ALADDIN_ANI_JUMPINGTHROW_END)
	{
		this->mAladdinData->player->sprite->Update(dt);
		this->mAladdinData->player->dx = this->mAladdinData->player->vx * dt;
		this->mAladdinData->player->dy = this->mAladdinData->player->vy * dt;
		this->mAladdinData->player->vy += ALADDIN_GRAVITY_JUMPING * dt;
	}
	else
		this->mAladdinData->player->SetState(new AladdinFallingState(this->mAladdinData));
}

void AladdinJumpingThrowState::HandleKeyboard(std::map<int, bool> keys)
{
	if (AllowThrow == true)
	{
		if (this->mAladdinData->player->isAttacking == false)
		{
			this->mAladdinData->player->Attack(eType::APPLE);
		}
	}
}
AladdinState::StateName AladdinJumpingThrowState::GetState()
{
	return AladdinState::JumpingThrow;
}
