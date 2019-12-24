#include "AladdinSitting.h"
#include "AladdinStandingState.h"
#include "AladdinClimbingState.h"
#include "AladdinSittingAttackState.h"
#include "AladdinSittingThrowState.h"
#include "AladdinWaitting_1.h"

AladdinSitting::AladdinSitting(AladdinData *aladdinData)
{
	this->mAladdinData = aladdinData;
	this->mAladdinData->player->SetVx(0);
	this->mAladdinData->player->SetVy(0);
	this->mAladdinData->player->sprite->SetTimeAnimation(150);
	TimeStart = GetTickCount();
	isSitting = false;
}


AladdinSitting::~AladdinSitting()
{

}

void AladdinSitting::Update(float dt, vector<LPGAMEOBJECT>* coObjects)
{
	
	if (this->mAladdinData->player->index < ALADDIN_ANI_SITTING_END)
	{
		this->mAladdinData->player->isSitting = true;
		this->mAladdinData->player->sprite->Update(dt);//cập nhật frame mới
	}
	TimeNow = GetTickCount();
	if ((TimeNow - TimeStart) > 500)
		this->mAladdinData->player->camera->SetPosition(this->mAladdinData->player->x - SCREEN_WIDTH / 4 + 80,
			this->mAladdinData->player->y + (SCREEN_HEIGHT / 4) - 90);
	
}

void AladdinSitting::HandleKeyboard(std::map<int, bool> keys)
{
	
	if (keys[DIK_LEFT])
	{
		this->mAladdinData->player->SetDirection(-1);
	}
	else if (keys[DIK_RIGHT])
	{
		this->mAladdinData->player->SetDirection(1);
	}

	else if (keys[DIK_DOWN])
	{
		if (this->mAladdinData->player->isClimbing == true)
			this->mAladdinData->player->SetState(new AladdinClimbingState(this->mAladdinData));
	}
	else
		if (this->mAladdinData->player->isSitting == false)
			this->mAladdinData->player->SetState(new AladdinStandingState(this->mAladdinData));
}

AladdinState::StateName AladdinSitting::GetState()
{
	return AladdinState::Sitting;

}
