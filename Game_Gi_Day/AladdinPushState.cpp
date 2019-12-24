#include "AladdinPushState.h"
#include"AladdinStandingState.h"


AladdinPushState::AladdinPushState(AladdinData *aladdinData)
{
	this->mAladdinData = aladdinData;
	this->mAladdinData->player->SetVx(0);
	this->mAladdinData->player->SetVy(0);
	this->mAladdinData->player->x -= 20 * this->mAladdinData->player->direction;
}



AladdinPushState::~AladdinPushState()
{
}

void AladdinPushState::Update(float dt, vector<LPGAMEOBJECT>* coObjects)
{
	this->mAladdinData->player->sprite->SetTimeAnimation(150);
	if (this->mAladdinData->player->index <= ALADDIN_ANI_PUSH_BEGIN || this->mAladdinData->player->index >= ALADDIN_ANI_PUSH_END)
	{
		this->mAladdinData->player->sprite->SelectFrame(ALADDIN_ANI_PUSH_BEGIN);
	}
	this->mAladdinData->player->sprite->Update(dt);
		
	
	
	
}

void AladdinPushState::HandleKeyboard(std::map<int, bool> keys)
{
	
}
AladdinState::StateName AladdinPushState::GetState()
{
	return AladdinState::Push;
}
