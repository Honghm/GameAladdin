#include "Bone.h"



Bone::Bone(float x, float y)
{
	Start = GetTickCount();
	this->x = x;
	this->y = y;
	type = eType::BONE;
	texture = TextureManager::GetInstance()->GetTexture(type);
	sprite = new CSprite(texture, 50);
	vx = -0.15 + (0.15 + 0.15)*rand() / RAND_MAX;
	vy = -0.15 + (0.15 + 0.15)*rand() / RAND_MAX;
	isFinish = false;
	
}

Bone::~Bone()
{
}

void Bone::Update(DWORD dt)
{
	Now = GetTickCount();
	DWORD time = Now - Start;

	if (isFinish == true)
		return;
	GameObject::Update(dt);
	int StartFrame = 0; // ánh xạ chỉ số frame bằng level thay vì ifelse 
	int EndFrame = 3;
	if (sprite->GetCurrentFrame() <= EndFrame)
	{
		isFinish = false;
		sprite->Update(dt);
	}
	else
	{
		isFinish = true;
	}
	//_RPT1(0, "Bone %d, %d\n", x, y);
	x += dx;
	y += dy;
	float l, t, r, b;
	GetBoundingBox(l, t, r, b);
	//_RPT1(0, "Bone updated %d, %d\n", x, y);
}

void Bone::Render(Camera * camera)
{
	if(isFinish == true)
		return;
	D3DXVECTOR2 pos = camera->Transform(x, y);
	sprite->Draw(pos.x, pos.y);
}

void Bone::GetBoundingBox(float & left, float & top, float & right, float & bottom)
{
	if (isFinish == true)
		return;
	else
	{
		left = x;
		right = left + this->GetWidth();
		top = y;
		bottom = top + this->GetHeight();
	}
}
