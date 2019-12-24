#include "Weapon.h"



Weapon::Weapon()
{
	type = eType::WEAPON;
	isFinish = true;
}

Weapon::~Weapon()
{
}

int Weapon::GetDirection()
{
	return direction;
} 

void Weapon::SetDirection(int Direction)
{
	this->direction = Direction;
}

void Weapon::Attack(float X, float Y, int Direction, int st)
{
	this->x = X;
	this->y = Y;
	this->direction = Direction;
	isFinish = false; // chưa kết thúc

	LastTimeAttack = GetTickCount(); // lưu lại thời điểm lúc vừa tấn công, làm đánh dấu tránh 1 hit đánh nhiều lần cho các object, có health >1.
}
void Weapon::SelectFrame(int state)
{
}
bool Weapon::ableCollision(GameObject* obj)//kiểm tra va chạm với các obj khác
{
	return isCollitionObjectWithObject(obj);
}

bool Weapon::CollisionWithBrick(vector<LPGAMEOBJECT>* coObjects)
{
	return false;
}

void Weapon::GetBoundingBox(float &left, float &top, float &right, float &bottom)
{
	left = x;
	top = y;
	right = left + texture->GetFrameWidth();
	bottom = top + texture->GetFrameHeight();
}

void Weapon::Render(Camera * camera)
{
	if (isFinish)
		return;
	D3DXVECTOR2 pos = camera->Transform(x, y);
	if (direction == 1)
		sprite->Draw(pos.x, pos.y);
	else
		sprite->DrawFlipX(pos.x, pos.y);
}

void Weapon::UpdatePositionFitCharacter()
{
}

bool Weapon::GetFinish()
{
	return isFinish;
}

int Weapon::GetStatus()
{
	return status;
}

void Weapon::SetStatus(int s)
{
	status = s;
}

void Weapon::SetFinish(bool b)
{
	isFinish = b;
}

DWORD Weapon::GetLastTimeAttack()
{
	return LastTimeAttack;
}
