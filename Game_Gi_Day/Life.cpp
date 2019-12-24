#include "Life.h"



void Life::Render()
{
	this->sprite->Draw(0,150);
}


void Life::Update(DWORD dt)
{
	if (this->sprite->GetCurrentFrame() >ANI_ALADDIN_END )
	{
		this->sprite->SelectFrame(ANI_ALADDIN_BEGIN);
	}
	this->sprite->Update(dt);
}

void Life::SetLife(int x)
{
	life = x;
}

Life::Life()
{
	texture = TextureManager::GetInstance()->GetTexture(eType::FACEALADDIN);
	sprite = new CSprite(texture, 150);
}


Life::~Life()
{
}
