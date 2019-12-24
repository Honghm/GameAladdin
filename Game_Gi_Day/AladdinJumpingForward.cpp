#include "AladdinJumpingForward.h"
#include "AladdinJumpingAttackState.h"
#include "AladdinJumpingThrowState.h"


AladdinJumpingForward::AladdinJumpingForward(AladdinData *aladdinData)
{
	this->mAladdinData = aladdinData;
	this->mAladdinData->player->sprite->SetTimeAnimation(150);
	isJumpingForward = false;
}


AladdinJumpingForward::~AladdinJumpingForward()
{
}

void AladdinJumpingForward::Update(float dt, vector<LPGAMEOBJECT>* coObjects)
{
	
	if (this->mAladdinData->player->index < ALADDIN_ANI_JUMPINGFORWARD_BEGIN || this->mAladdinData->player->index >= ALADDIN_ANI_JUMPINGFORWARD_END)
		this->mAladdinData->player->sprite->SelectFrame(ALADDIN_ANI_JUMPINGFORWARD_BEGIN);
	this->mAladdinData->player->sprite->Update(dt); 
	
	this->mAladdinData->player->dx = this->mAladdinData->player->vx * dt;
	this->mAladdinData->player->dy = this->mAladdinData->player->vy * dt;
	this->mAladdinData->player->vy += ALADDIN_GRAVITY_JUMPING * dt;
	
}

void AladdinJumpingForward::HandleKeyboard(std::map<int, bool> keys)
{
	if (isJumpingForward)
		return;

	this->mAladdinData->player->SetSpeed(ALADDIN_WALKING_JUMPING_SPEED*this->mAladdinData->player->GetDirection(), -ALADDIN_VJUMP);
	isJumpingForward = true;
	if (keys[DIK_X])
	{
		this->mAladdinData->player->SetSpeed(0.2*this->mAladdinData->player->direction, -ALADDIN_VJUMP);
	}
	if (keys[DIK_C])
	{
		this->mAladdinData->player->SetSpeed(0.2*this->mAladdinData->player->direction, -ALADDIN_VJUMP);
	}
}
AladdinState::StateName AladdinJumpingForward::GetState()
{
	return AladdinState::JumpingForward;
}
