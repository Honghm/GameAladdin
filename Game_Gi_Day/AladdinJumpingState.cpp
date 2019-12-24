#include "AladdinJumpingState.h"
#include "AladdinStandingState.h"
#include "AladdinData.h"
#include "AladdinJumpingAttackState.h"
#include "AladdinJumpingThrowState.h"
AladdinJumpingState::AladdinJumpingState(AladdinData *playerData)
{
	this->mAladdinData = playerData;
	this->mAladdinData->player->sprite->SetTimeAnimation(150);
	allowMove = true;
	isJumping = false;
}

AladdinJumpingState::~AladdinJumpingState()
{

}

void AladdinJumpingState::Update(float dt, vector<LPGAMEOBJECT> *coObjects)
{
	
	if (this->mAladdinData->player->index < ALADDIN_ANI_JUMPING_BEGIN || this->mAladdinData->player->index >= ALADDIN_ANI_JUMPING_END)
		this->mAladdinData->player->sprite->SelectFrame(ALADDIN_ANI_JUMPING_BEGIN);
	this->mAladdinData->player->sprite->Update(dt);
	this->mAladdinData->player->dx = this->mAladdinData->player->vx * dt;
	this->mAladdinData->player->dy = this->mAladdinData->player->vy * dt;
	//this->mAladdinData->player->y += this->mAladdinData->player->dy;
	this->mAladdinData->player->vy += ALADDIN_GRAVITY_JUMPING*dt;
	//this->mAladdinData->player->vx += 0.0001*dt*this->mAladdinData->player->direction;
	
}

void AladdinJumpingState::HandleKeyboard(std::map<int, bool> keys)
{
	if (allowMove == true)
	{
		if (keys[DIK_RIGHT])
		{
			this->mAladdinData->player->SetDirection(1);
			this->mAladdinData->player->SetSpeed(0.15, -0.2);
			allowMove = false;
		}
		else if (keys[DIK_LEFT])
		{
			this->mAladdinData->player->SetDirection(-1);
			this->mAladdinData->player->SetSpeed(-0.15, -0.2);
			allowMove = false;
		}
		else
		{
			if (isJumping == true)
				return;
			this->mAladdinData->player->vx = 0;
			this->mAladdinData->player->vy = -ALADDIN_VJUMP;
			isJumping = true;
		}
	}
	
}

AladdinState::StateName AladdinJumpingState::GetState()
{
	return AladdinState::Jumping;
}
