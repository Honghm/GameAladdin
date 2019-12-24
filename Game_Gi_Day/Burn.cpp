#include "Burn.h"

Burn::Burn(float x, float y, int st)
{
	float l, t, r, b;
	this->x = x;
	this->y = y;
	if (st == 1)
		type = eType::BURN;
	else
	{
		type = eType::BURN_1;

	}
	texture = TextureManager::GetInstance()->GetTexture(type);
	sprite = new CSprite(texture, 100);
	this->isFinish = false;
	status = ACTIVE;
	state = st;
	GetBoundingBox(l, t, r, b);
}

Burn::~Burn()
{
}

void Burn::Update(DWORD dt, float xAladdin, float yAladdin, int direction)
{
	this->direction = direction;
	if (this->isFinish == true)
		return;


	if (state == 1)
	{

		if (direction == -1)
		{
			vx = -0.2;
		}
		else
		{
			vx = 0.2;
		}

		if (y >= 315)
			vy = 0;
		else
			vy = 0.2;
		GameObject::Update(dt);
		int StartFrame = 0; // ánh xạ chỉ số frame bằng level thay vì ifelse 
		int EndFrame = 7;
		if (sprite->GetCurrentFrame() < StartFrame || sprite->GetCurrentFrame() >= EndFrame)
		{
			sprite->SelectFrame(StartFrame);
		}
		x += dx;
		y += dy;
	}
	else if (state == 2)
	{
		float l, t, r, b;
		GetBoundingBox(l, t, r, b);
		int StartFrame = 0; // ánh xạ chỉ số frame bằng level thay vì ifelse 
		int EndFrame = 4;
		if (sprite->GetCurrentFrame() < StartFrame || sprite->GetCurrentFrame() >= EndFrame)
		{
			sprite->SelectFrame(StartFrame);
		}
	}
	sprite->Update(dt);
}

void Burn::Render(Camera * camera)
{
	if (this->isFinish == true)
		return;
	D3DXVECTOR2 pos = camera->Transform(x, y);
	if (direction == 1)
		sprite->Draw(pos.x, pos.y);
	else
		sprite->DrawFlipX(pos.x, pos.y);
	RenderBoundingBox(camera);
}

void Burn::GetBoundingBox(float & left, float & top, float & right, float & bottom)
{
	if (state == 1)
	{
		if (status == ACTIVE)
		{
			if (direction == 1)
			{
				left = x + 20;
				top = y + 20;
				right = left + 50;
				bottom = top + 30;
			}
			else
			{
				left = x + 20;
				top = y + 20;
				right = left + 60;
				bottom = top + 30;
			}
		}
		else
			return;
	}
	else if (state == 2)
	{
		if (status == ACTIVE)
		{
			left = x;
			top = y;
			right = left + 30;
			bottom = top + 60;
		}
		else
			return;

	}
}
