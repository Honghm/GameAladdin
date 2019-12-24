#include "Rock.h"



Rock::Rock(float X, float Y, int W, int H, int st)
{
	texture = TextureManager::GetInstance()->GetTexture(eType::ROCK);
	this->x = X;
	this->y = Y;
	this->width = W;
	this->height = H;
	this->state = st;
	sprite = new CSprite(texture, 800);
	this->type = eType::ROCK;
	this->isEnable = false;
}

void Rock::Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects)
{
	if (state == 1)
	{
		if (this->sprite->GetCurrentFrame() <= ROCK_ANI_BEGIN_1 || this->sprite->GetCurrentFrame() >= ROCK_ANI_END_1)
		{
			this->sprite->SelectFrame(ROCK_ANI_BEGIN_1);
		}
		if (this->sprite->GetCurrentFrame() == 4)
		{
			this->sprite->SetTimeAnimation(3200);
		}
		else
		{
			this->sprite->SetTimeAnimation(800);
		}
	}
	if (state == -1)
	{
		if (this->sprite->GetCurrentFrame() <= ROCK_ANI_BEGIN_2 || this->sprite->GetCurrentFrame() >= ROCK_ANI_END_2)
		{
			this->sprite->SelectFrame(ROCK_ANI_BEGIN_2);
		}
		if (this->sprite->GetCurrentFrame() == 8)
		{
			this->sprite->SetTimeAnimation(3200);

		}
		else
		{
			this->sprite->SetTimeAnimation(800);
		}
	}
	if ((sprite->GetCurrentFrame() >= 3 && sprite->GetCurrentFrame() <= 5)
		|| (sprite->GetCurrentFrame() == 8)
		|| (sprite->GetCurrentFrame() == 9)
		|| (sprite->GetCurrentFrame() == 15))
	{
		this->isEnable = true;
	}
	else
		this->isEnable = false;
	this->sprite->Update(dt);
}

void Rock::Render(Camera * camera)
{
	D3DXVECTOR2 pos = camera->Transform(x, y);
	sprite->Draw(pos.x, pos.y);
}

void Rock::GetBoundingBox(float & l, float & t, float & r, float & b)
{
	if (this->isEnable == true)
	{
		l = x;
		t = y;
		r = l + 30;
		b = t + 20;
	}
	else
		return;
}


Rock::~Rock()
{
}
