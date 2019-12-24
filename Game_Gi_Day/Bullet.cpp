#include "Bullet.h"

Bullet::Bullet(float x, float y)
{
	this->x = x;
	this->y = y;
	type = eType::BULLET;
	texture = TextureManager::GetInstance()->GetTexture(type);
	sprite = new CSprite(texture, 20);
	isFinish = false;
	status = ACTIVE;
}

Bullet::~Bullet()
{
}

void Bullet::Update(DWORD dt, float xAladdin, float yAladdin, int direction)
{
	if (isFinish == true)
		return;

	if (direction == -1)
	{
		vx = -0.5;
	}
	else
	{
		vx = 0.5;
	}

	if (y >= yAladdin)
		vy = 0;
	else
	{
		if (abs(x - xAladdin) < 30)
			vy = 0.5;
		else
			vy = 0.2;
	}

	GameObject::Update(dt);
	int StartFrame = 0; // ánh xạ chỉ số frame bằng level thay vì ifelse 
	int EndFrame = 2;
	if (sprite->GetCurrentFrame() < StartFrame || sprite->GetCurrentFrame() >= EndFrame)
	{
		sprite->SelectFrame(StartFrame);
	}
	x += dx;
	y += dy;
	if (x <= xAladdin && direction == -1)
		isFinish = true;
	if (x >= xAladdin && direction == 1)
		isFinish = true;
	sprite->Update(dt);
}

void Bullet::Render(Camera * camera)
{
	if (isFinish == true)
		return;
	D3DXVECTOR2 pos = camera->Transform(x, y);
	sprite->Draw(pos.x, pos.y);
	RenderBoundingBox(camera);
}

void Bullet::GetBoundingBox(float & left, float & top, float & right, float & bottom)
{
	if (status == ACTIVE)
	{
		left = x;
		top = y;
		right = left + 30;
		bottom = top + 20;
	}
	else
		return;
}
