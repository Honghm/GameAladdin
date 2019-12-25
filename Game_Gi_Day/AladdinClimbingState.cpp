#include "AladdinClimbingState.h"
#include "AladdinJumpingState.h"
#include "AladdinStandingState.h"
#include "AladdinJumpingClimbState.h"
#include"AladdinFallingState.h"
#include "AladdinJumping2State.h"
AladdinClimbingState::AladdinClimbingState(AladdinData *playerData)
{
	this->mAladdinData = playerData;
	this->mAladdinData->player->isLooking = false;
	this->mAladdinData->player->isSitting = false;
	isClimbing = true;
	this->mAladdinData->player->isAttacking = false;
}


AladdinClimbingState::~AladdinClimbingState()
{
}

void AladdinClimbingState::Update(float dt, vector<LPGAMEOBJECT>* coObjects)
{
	if (this->mAladdinData->player->isUp == true)
	{
		this->mAladdinData->player->sprite->SetTimeAnimation(50);
		if (this->mAladdinData->player->index < ALADDIN_ANI_CLIMBING_BEGIN || this->mAladdinData->player->index == ALADDIN_ANI_CLIMBING_END)
			this->mAladdinData->player->sprite->SelectFrame(ALADDIN_ANI_CLIMBING_BEGIN);
		this->mAladdinData->player->dy = this->mAladdinData->player->vy*dt;
		this->mAladdinData->player->y += this->mAladdinData->player->dy;
		this->mAladdinData->player->sprite->Update(dt);
		//this->mAladdinData->player->isAttacking = false;
	}
	else
	{
		this->mAladdinData->player->dy = 0;
		this->mAladdinData->player->sprite->SelectFrame(ALADDIN_ANI_CLIMBING_BEGIN);
	}
	
}

void AladdinClimbingState::HandleKeyboard(std::map<int, bool> keys)
{
	if (keys[DIK_UP])
	{
		this->mAladdinData->player->isUp = true;

		if (this->mAladdinData->player->y >= this->mAladdinData->player->B_top) // vị trí biên trên khi leo lên thang
		{
			this->mAladdinData->player->vy = -0.01f;
		}
		else
		{
			this->mAladdinData->player->vy = 0;
			this->mAladdinData->player->dy = 0;
		}
	}
	else if (keys[DIK_DOWN])
	{
		this->mAladdinData->player->isUp = true;

		if (this->mAladdinData->player->y <= this->mAladdinData->player->B_bottom) //vị trí biên dưới khi leo xuống thang
		{
			this->mAladdinData->player->vy = 0.01f;
		}
		else
		{
			this->mAladdinData->player->vy = ALADDIN_GRAVITY;
			isClimbing = false;
			this->mAladdinData->player->SetState(new AladdinJumping2State(this->mAladdinData));
			return;
		}
	}
	else
	{
		this->mAladdinData->player->isUp = false;
		this->mAladdinData->player->vy = 0;
	}
	if (keys[DIK_LEFT])
		this->mAladdinData->player->direction = -1;
	if (keys[DIK_RIGHT])
		this->mAladdinData->player->direction = 1;
}

AladdinState::StateName AladdinClimbingState::GetState()
{
	return StateName::Climbing;
}
