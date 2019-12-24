#include "AladdinStandingState.h"
#include "Player.h"
#include "AladdinRunningState.h"
#include "AladdinJumpingState.h"
#include "AladdinWaitting_1.h"
#include "AladdinLookUpState.h"
#include "AladdinSitting.h"

AladdinStandingState::AladdinStandingState(AladdinData *aladdinData)
{
	this->mAladdinData = aladdinData;
	this->mAladdinData->player->isWalking = false;
	this->mAladdinData->player->isLooking = false;
	this->mAladdinData->player->isSitting = false;
	this->mAladdinData->player->isClimbing = false;
	this->mAladdinData->player->isClimbing = false;
	this->mAladdinData->player->isAttacking = false;
	this->mAladdinData->player->AllowAttack = true;
	this->mAladdinData->player->isHurting = false;
	this->mAladdinData->player->isPush = false;
	this->mAladdinData->player->vy = 0;
	this->mAladdinData->player->dx = 0;
	TimeStart = GetTickCount();
}


AladdinStandingState::~AladdinStandingState()
{
}

void AladdinStandingState::Update(float dt, vector<LPGAMEOBJECT> *coObjects)
{
	TimeNow = GetTickCount();
	if ((TimeNow - TimeStart) > 300)
		this->mAladdinData->player->SetState(new AladdinWaitting_1(this->mAladdinData));
}
void AladdinStandingState::HandleKeyboard(std::map<int, bool> keys)
{
	if (keys[DIK_RIGHT])
	{
		this->mAladdinData->player->direction = 1;
		this->mAladdinData->player->SetState(new AladdinRunningState(this->mAladdinData));
	}
	if (keys[DIK_LEFT])
	{
		this->mAladdinData->player->direction = -1;
		this->mAladdinData->player->SetState(new AladdinRunningState(this->mAladdinData));
	}
}

AladdinState::StateName AladdinStandingState::GetState()
{
	return AladdinState::Standing;
}