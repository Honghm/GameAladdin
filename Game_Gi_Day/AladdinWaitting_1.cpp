#include "AladdinWaitting_1.h"
#include "AladdinJumpingState.h"
#include "Player.h"


AladdinWaitting_1::AladdinWaitting_1(AladdinData *aladdinData)
{
	this->mAladdinData = aladdinData;
}


AladdinWaitting_1::~AladdinWaitting_1()
{
}

void AladdinWaitting_1::Update(float dt, vector<LPGAMEOBJECT>* coObjects)
{
	if (this->mAladdinData->player->index < ALADDIN_ANI_WAITTING_3_END)
	{
		if(this->mAladdinData->player->index==33|| this->mAladdinData->player->index == 40|| this->mAladdinData->player->index == 54)
			this->mAladdinData->player->sprite->SetTimeAnimation(1500);
		else
		{
			this->mAladdinData->player->sprite->SetTimeAnimation(200);
		}
		
		this->mAladdinData->player->sprite->Update(dt); // dt này được cập nhật khi gọi update; 
	}
	else
	{
		this->mAladdinData->player->sprite->SelectFrame(ALADDIN_ANI_WAITTING_1_BEGIN);
	}
}


void AladdinWaitting_1::HandleKeyboard(std::map<int, bool> keys)
{
	
}

AladdinState::StateName AladdinWaitting_1::GetState()
{
	return AladdinState::Waitting;
}
