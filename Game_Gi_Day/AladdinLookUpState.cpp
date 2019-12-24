#include "AladdinLookUpState.h"
#include "AladdinStandingState.h"
#include "AladdinClimbingState.h"
#include "Player.h"
#include "Camera.h"
#include "AladdinStandingAttackState.h"
#include "AladdinWaitting_1.h"

AladdinLookUpState::AladdinLookUpState(AladdinData *aladdinData)
{
	this->mAladdinData = aladdinData;
	this->mAladdinData->player->SetVx(0);
	this->mAladdinData->player->SetVy(0);
	
	this->mAladdinData->player->isSitting = false;
	TimeStart = GetTickCount();
}


AladdinLookUpState::~AladdinLookUpState()
{

}

void AladdinLookUpState::Update(float dt, vector<LPGAMEOBJECT>* coObjects)
{
	this->mAladdinData->player->sprite->SetTimeAnimation(200);
	if (this->mAladdinData->player->index < ALADDIN_ANI_LOOKUP_END)
	{
		this->mAladdinData->player->sprite->Update(dt);//cập nhật frame mới
	}
	TimeNow = GetTickCount();
	if((TimeNow-TimeStart)>500)
		this->mAladdinData->player->camera->SetPosition(this->mAladdinData->player->x - SCREEN_WIDTH / 4 + 80,
			this->mAladdinData->player->y + (SCREEN_HEIGHT / 4) - 210);
}

void AladdinLookUpState::HandleKeyboard(std::map<int, bool> keys)
{
	if (keys[DIK_UP])
	{
		if (this->mAladdinData->player->isClimbing == true) //đang ở trạng thái leo thì leo lên
			this->mAladdinData->player->SetState(new AladdinClimbingState(this->mAladdinData));

		else if (keys[DIK_C])//đang nhìn mà đánh
		{
			this->mAladdinData->player->SetState(new AladdinStandingAttackState(this->mAladdinData));
			return;
		}
	}
	else
		if (this->mAladdinData->player->isLooking == false)
		{
			this->mAladdinData->player->SetState(new AladdinWaitting_1(this->mAladdinData));
			return;
		}
		else
		{
			this->mAladdinData->player->isLooking = true;
		}
}

AladdinState::StateName AladdinLookUpState::GetState()
{
	return AladdinState::Lookup;

}
