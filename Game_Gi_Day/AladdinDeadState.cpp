#include "AladdinDeadState.h"
#include "AladdinStandingState.h"


AladdinDeadState::AladdinDeadState(AladdinData *aladdinData)
{
	this->mAladdinData = aladdinData;
	this->mAladdinData->player->SetVx(0);
	this->mAladdinData->player->SetVy(0);
}



AladdinDeadState::~AladdinDeadState()
{
}

void AladdinDeadState::Update(float dt, vector<LPGAMEOBJECT>* coObjects)
{
	this->mAladdinData->player->sprite->SetTimeAnimation(250);
	if (this->mAladdinData->player->index <= ALADDIN_ANI_DEAD_END)
	{
		this->mAladdinData->player->sprite->Update(dt);//cập nhật frame mới
	}
	else
		this->mAladdinData->player->SetState(new AladdinStandingState(this->mAladdinData));

}

void AladdinDeadState::HandleKeyboard(std::map<int, bool> keys)
{
}
AladdinState::StateName AladdinDeadState::GetState()
{
	return AladdinState::Dead;
}
