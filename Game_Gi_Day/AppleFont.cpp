#include "AppleFont.h"



void AppleFont::Render()
{
	this->sprite->Draw(200, 150);
}


void AppleFont::Update(DWORD dt)
{
	this->sprite->SelectFrame(TAO_ANI_BEGIN);
}

void AppleFont::SetAppleFont(int x)
{
	applefont = x;
}

AppleFont::AppleFont()
{
	texture = TextureManager::GetInstance()->GetTexture(eType::TAO);
	sprite = new CSprite(texture, 150);
}


AppleFont::~AppleFont()
{
}
