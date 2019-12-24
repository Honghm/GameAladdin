#include "Thorn.h"



Thorn::Thorn(float X, float Y, int W, int H, int st)
{
	texture = TextureManager::GetInstance()->GetTexture(eType::THORN);
	this->x = X;
	this->y = Y;
	this->width = W;
	this->height = H;
	this->state = st;
	sprite = new CSprite(texture, 500);
	this->type = eType::THORN;
	this->isEnable = false;
}

void Thorn::Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects)
{
	if (state == 1)
	{
		if (this->sprite->GetCurrentFrame() <= THORN_ANI_BEGIN_1 || this->sprite->GetCurrentFrame() > THORN_ANI_END_1)
		{
			this->sprite->SelectFrame(THORN_ANI_BEGIN_1);

		}
	}
	if (state == -1)
	{
		if (this->sprite->GetCurrentFrame() <= THORN_ANI_BEGIN_2 || this->sprite->GetCurrentFrame() > THORN_ANI_END_2)
		{
			this->sprite->SelectFrame(THORN_ANI_BEGIN_2);

		}
	}
	if (this->sprite->GetCurrentFrame() == 5 || this->sprite->GetCurrentFrame() == 6)
		this->sprite->SetTimeAnimation(3000);
	else
		this->sprite->SetTimeAnimation(500);
	if (sprite->GetCurrentFrame() == 1 || sprite->GetCurrentFrame() == 7)
		this->isEnable = true;
	else
		this->isEnable = false;
	this->sprite->Update(dt);
}

void Thorn::Render(Camera * camera)
{
	D3DXVECTOR2 pos = camera->Transform(x, y);
	sprite->Draw(pos.x, pos.y);
}

void Thorn::GetBoundingBox(float & l, float & t, float & r, float & b)
{
	if (isEnable == true)
	{
		l = x + 10;
		t = y + 10;
		r = l + 40;
		b = t + 20;
	}
	else
		return;
}


Thorn::~Thorn()
{
}
