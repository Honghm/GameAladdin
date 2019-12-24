#include "JewryRock.h"



void JewryRock::Render()
{
	this->sprite->Draw(250, 145);
}


void JewryRock::Update(DWORD dt)
{
	if (this->sprite->GetCurrentFrame() >REDROCK_ANI_END)
	{
		this->sprite->SelectFrame(REDROCK_ANI_BEGIN);
	}
	this->sprite->Update(dt);
}

void JewryRock::SetJewryRock(int x)
{
	jewryrock = x;
}



JewryRock::JewryRock()
{
	texture = TextureManager::GetInstance()->GetTexture(eType::REDROCK);
	sprite = new CSprite(texture, 150);
}


JewryRock::~JewryRock()
{
}
