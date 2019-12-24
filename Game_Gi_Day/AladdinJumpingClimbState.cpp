#include "AladdinJumpingClimbState.h"



AladdinJumpingClimbState::AladdinJumpingClimbState(AladdinData *aladdinData)
{
	this->mAladdinData = aladdinData;
	this->mAladdinData->player->vy = -ALADDIN_VJUMP;
}



AladdinJumpingClimbState::~AladdinJumpingClimbState()
{
}

void AladdinJumpingClimbState::Update(float dt, vector<LPGAMEOBJECT>* coObjects)
{
	if (this->mAladdinData->player->index > ALADDIN_ANI_JUMPINGCLIMB_END)
	{
		this->mAladdinData->player->sprite->SelectFrame(ALADDIN_ANI_JUMPINGCLIMB_BEGIN);
	}
	this->mAladdinData->player->sprite->Update(dt);//cập nhật frame mới

	
	this->mAladdinData->player->dx = this->mAladdinData->player->vx * dt;
	this->mAladdinData->player->dy = this->mAladdinData->player->vy * dt;
	//this->mAladdinData->player->y += this->mAladdinData->player->dy;
	this->mAladdinData->player->vy += ALADDIN_GRAVITY_JUMPING*dt;
	
}

void AladdinJumpingClimbState::HandleKeyboard(std::map<int, bool> keys)
{
	if (keys[DIK_RIGHT])
	{
		this->mAladdinData->player->SetDirection(1);
		this->mAladdinData->player->SetSpeed(0.25, -0.05);
		//allowMove = false;
	}
	else if (keys[DIK_LEFT])
	{
		this->mAladdinData->player->SetDirection(-1);
		this->mAladdinData->player->SetSpeed(-0.25, -0.05);
		//allowMove = false;
	}
}
AladdinState::StateName AladdinJumpingClimbState::GetState()
{
	return AladdinState::JumpingClimb;
}
