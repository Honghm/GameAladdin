#include "AladdinThrowState.h"
#include "AladdinStandingState.h"


AladdinThrowState::AladdinThrowState(AladdinData *aladdinData)
{
	this->mAladdinData = aladdinData;
	this->mAladdinData->player->SetVx(0);
	this->mAladdinData->player->SetVy(0);
	this->mAladdinData->player->mWeapon.clear();
	this->mAladdinData->player->mWeapon.push_back(new Apple());
	AllowThrow = true;
	this->mAladdinData->player->sprite->SetTimeAnimation(160);
	Sound::GetInstance()->Play(eSound::sound_ThrowApple);
}



AladdinThrowState::~AladdinThrowState()
{
}

void AladdinThrowState::Update(float dt, vector<LPGAMEOBJECT>* coObjects)
{
	if (AllowThrow == true)
	{
		if (this->mAladdinData->player->index < ALADDIN_ANI_THROWSTANDDING_END)
		{
			this->mAladdinData->player->sprite->Update(dt);//cập nhật frame mới
		}
		else
			AllowThrow = false;
	}
	else
	{
		this->mAladdinData->player->isAttacking = false;
	}
	
}

void AladdinThrowState::HandleKeyboard(std::map<int, bool> keys)
{
	if (AllowThrow == true)
	{
		if (this->mAladdinData->player->isAttacking == false)
		{
			this->mAladdinData->player->Attack(eType::APPLE);
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
AladdinState::StateName AladdinThrowState::GetState()
{
	return AladdinState::Throw;
}
