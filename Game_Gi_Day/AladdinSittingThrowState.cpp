#include "AladdinSittingThrowState.h"
#include "AladdinSitting.h"



AladdinSittingThrowState::AladdinSittingThrowState(AladdinData * aladdinData)
{
	this->mAladdinData = aladdinData;
	this->mAladdinData->player->SetVx(0);
	this->mAladdinData->player->SetVy(0);
	AllowThrow = true;
	this->mAladdinData->player->mWeapon.clear();
	this->mAladdinData->player->mWeapon.push_back(new Apple());
	Sound::GetInstance()->Play(eSound::sound_ThrowApple);
}

AladdinSittingThrowState::~AladdinSittingThrowState()
{
}

void AladdinSittingThrowState::Update(float dt, vector<LPGAMEOBJECT>* coObjects)
{
	if (AllowThrow == true)
	{
		if (this->mAladdinData->player->index <= ALADDIN_ANI_SITTINGTHROW_END)
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
	if (this->mAladdinData->player->isSitting == false)
	{
		this->mAladdinData->player->SetState(new AladdinStandingState(this->mAladdinData));
	}
}

void AladdinSittingThrowState::HandleKeyboard(std::map<int, bool> keys)
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
			this->mAladdinData->player->SetState(new AladdinStandingState(this->mAladdinData));
		}
		else if (keys[DIK_RIGHT])
		{
			this->mAladdinData->player->SetDirection(1);
			this->mAladdinData->player->SetState(new AladdinStandingState(this->mAladdinData));
		}
	}
	
	
}

AladdinState::StateName AladdinSittingThrowState::GetState()
{
	return AladdinState::SittingThrow;
}
