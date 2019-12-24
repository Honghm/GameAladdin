#include "AladdinJumping2State.h"
#include "AladdinData.h"
#include "AladdinStandingState.h"


AladdinJumping2State::AladdinJumping2State(AladdinData *playerData)
{
	this->mAladdinData = playerData;
}



AladdinJumping2State::~AladdinJumping2State()
{
}

void AladdinJumping2State::Update(float dt, vector<LPGAMEOBJECT>* coObjects)
{
	this->mAladdinData->player->sprite->SetTimeAnimation(100);
	if (this->mAladdinData->player->index <= ALADDIN_ANI_JUMPING_2_END)
	{
		this->mAladdinData->player->sprite->Update(dt);//cập nhật frame mới
		this->mAladdinData->player->dx = this->mAladdinData->player->vx * dt;
		this->mAladdinData->player->dy = this->mAladdinData->player->vy * dt;
		this->mAladdinData->player->vy += ALADDIN_GRAVITY_JUMPING * dt;
	}
	else
	{
		this->mAladdinData->player->SetState(new AladdinStandingState(this->mAladdinData));
	}
	
}

void AladdinJumping2State::HandleKeyboard(std::map<int, bool> keys)
{
	
}
AladdinState::StateName AladdinJumping2State::GetState()
{
	return AladdinState::Jumping2;
}
