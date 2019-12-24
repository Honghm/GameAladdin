#include "RedRock.h"



RedRock::RedRock(float X, float Y, int W, int H, int st)
{
	texture = TextureManager::GetInstance()->GetTexture(eType::REDROCK);
	this->x = X;
	this->y = Y;
	this->width = W;
	this->height = H;
	sprite = new CSprite(texture, 0);
	this->type = eType::REDROCK;

}

void RedRock::Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects)
{
	this->sprite->SetTimeAnimation(2000);
	if (this->sprite->GetCurrentFrame() <REDROCK_ANI_BEGIN || this->sprite->GetCurrentFrame() > REDROCK_ANI_END)
	{

		this->sprite->SelectFrame(REDROCK_ANI_BEGIN);
	}
	this->sprite->Update(dt);
}

void RedRock::Render(Camera * camera)
{
	if (isFinish)
		return;
	//sprite->SelectFrame(0);
	D3DXVECTOR2 pos = camera->Transform(x, y);
	sprite->Draw(pos.x, pos.y);

}

void RedRock::GetBoundingBox(float & l, float & t, float & r, float & b)
{
	l = x + 16;
	t = y + 16;
	r = x + width - 16;
	b = y + height - 16;
}


RedRock::~RedRock()
{
}
