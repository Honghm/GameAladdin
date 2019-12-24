#include "Marble.h"



Marble::Marble(float X, float Y, int W, int H, int st)
{
	texture = TextureManager::GetInstance()->GetTexture(eType::MARBLE);
	this->x = X;
	this->y = Y;
	this->width = W;
	this->height = H;
	this->state = st;
	sprite = new CSprite(texture, 200);
	this->type = eType::MARBLE;
	this->isEnable = false;

}

void Marble::Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects)
{
	if (state == 1)
	{
		if (this->sprite->GetCurrentFrame() < Marble_ANI_BEGIN_1 || this->sprite->GetCurrentFrame() >= Marble_ANI_END_1)
		{
			this->sprite->SelectFrame(Marble_ANI_BEGIN_1);
		}
	}

	if (state == -1)
	{
		if (this->sprite->GetCurrentFrame() < Marble_ANI_BEGIN_2 || this->sprite->GetCurrentFrame() >= Marble_ANI_END_2)
		{
			this->sprite->SelectFrame(Marble_ANI_BEGIN_2);
		}
	}
	if (sprite->GetCurrentFrame() == 14 || sprite->GetCurrentFrame() == 30 || sprite->GetCurrentFrame() == 61)
		this->isEnable = true;
	else
		this->isEnable = false;
	float l, t, r, b;
	GetBoundingBox(l, t, r, b);
	this->sprite->Update(dt);

}

void Marble::Render(Camera * camera)
{
	D3DXVECTOR2 pos = camera->Transform(x, y);
	sprite->Draw(pos.x, pos.y);
}

void Marble::GetBoundingBox(float & l, float & t, float & r, float & b)
{
	if (this->isEnable == true)
	{
		l = x + 32;
		t = y + 40;
		r = l + 35;
		b = t + 30;
	}
	else
		return;

}
Marble::~Marble()
{
}
