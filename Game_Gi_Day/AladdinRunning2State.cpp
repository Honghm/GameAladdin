#include "AladdinRunning2State.h"
#include "AladdinStandingState.h"


AladdinRunning2State::AladdinRunning2State(AladdinData *aladdinData)
{
	this->mAladdinData = aladdinData;
	this->mAladdinData->player->sprite->SetTimeAnimation(100);
}



AladdinRunning2State::~AladdinRunning2State()
{
}

void AladdinRunning2State::Update(float dt, vector<LPGAMEOBJECT>* coObjects)
{
	if (this->mAladdinData->player->index <= ALADDIN_ANI_RUNNING2_END)
	{
		this->mAladdinData->player->sprite->Update(dt);//cập nhật frame mới
		this->mAladdinData->player->dx = this->mAladdinData->player->vx*dt;
		this->mAladdinData->player->x += this->mAladdinData->player->dx;
		if (this->mAladdinData->player->vx <= 0)
			this->mAladdinData->player->vx = 0;
		else
			this->mAladdinData->player->vx -= 0.001*this->mAladdinData->player->direction;
	}
	else
	{
		this->mAladdinData->player->SetState(new AladdinStandingState(this->mAladdinData));
	}

	
}

void AladdinRunning2State::HandleKeyboard(std::map<int, bool> keys)
{
}
AladdinState::StateName AladdinRunning2State::GetState()
{
	return AladdinState::Running2;
}
