#include "AladdinRunningState.h"
#include "AladdinStandingState.h"
#include "AladdinJumpingState.h"
#include "AladdinAttackingState.h"
#include "AladdinData.h"
#include "AladdinRunning2State.h"
#include "AladdinThrowState.h"
#include "AladdinJumpingForward.h"
#include "AladdinPushState.h"
#include "AladdinRunningAttackingState.h"

AladdinRunningState::AladdinRunningState(AladdinData *playerData)
{
	this->mAladdinData = playerData;
}

AladdinRunningState::~AladdinRunningState()
{
}

void AladdinRunningState::Update(float dt, vector<LPGAMEOBJECT> *coObjectsz)
{

	this->mAladdinData->player->sprite->SetTimeAnimation(100);
	if (this->mAladdinData->player->index < ALADDIN_ANI_WALKING_BEGIN || this->mAladdinData->player->index >= ALADDIN_ANI_WALKING_END)
		this->mAladdinData->player->sprite->SelectFrame(ALADDIN_ANI_WALKING_BEGIN);
	this->mAladdinData->player->sprite->Update(dt); 
	this->mAladdinData->player->vx = ALADDIN_WALKING_SPEED * this->mAladdinData->player->GetDirection();
	this->mAladdinData->player->dx = this->mAladdinData->player->vx*dt;
	this->mAladdinData->player->x += this->mAladdinData->player->dx;
	
}

void AladdinRunningState::HandleKeyboard(std::map<int, bool> keys)
{

}

AladdinState::StateName AladdinRunningState::GetState()
{
	return AladdinState::Running;
}
