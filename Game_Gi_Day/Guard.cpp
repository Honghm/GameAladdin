#include "Guard.h"
#include "Brick.h"

Guard::Guard(int direction, float X, float Y, float BorderLeft, float BorderRight, int status)
{
	x = X;
	y = Y;
	this->direction = direction;
	borderLeft = BorderLeft;
	borderRight = BorderRight;
	this->status = status;
	BackupX = x;
	backupDirection = direction;
	texture = TextureManager::GetInstance()->GetTexture(eType::GUARD);
	sprite = new CSprite(texture, 150);
	isAttacking = false;
	Health = 1; // sét máu
	type = eType::GUARD;
	vx = GUARD_SPEED_X * this->direction;
}

Guard::~Guard()
{
}

void Guard::SetStatus(int s)
{
	Enemy::SetStatus(s);

	switch (this->status)
	{
	case ACTIVE:
		break;
	case DEATH:
		break;
	case INACTIVE:
		break;
	default:
		break;
	}
}
void Guard::Update(DWORD dt, Player* Aladdin)
{
	isCollisionWithAladdin = Aladdin->isCollisionWithEnemy;
	if (status == INACTIVE)
		return;
	if (this->Health <= 0)
	{
		status = INACTIVE;
	}
	float detaX = this->x - Aladdin->x;
	float detaY = this->y - Aladdin->y;
	if ((detaX > 100 || detaX < -100) && (detaY > 80 || detaY < -80))
	{
		
		isAttacking = false;
		if (this->GetX() < borderLeft || this->GetX() > borderRight)
		{
			if (sprite->GetCurrentFrame() >= GUARD_ANI_AROUSE_END || sprite->GetCurrentFrame() < GUARD_ANI_AROUSE_BEGIN)
			{
				sprite->SelectFrame(GUARD_ANI_AROUSE_BEGIN);
			}

		}
		else
		{
			if (sprite->GetCurrentFrame() >= GUARD_ANI_RUNNING_END || sprite->GetCurrentFrame() < GUARD_ANI_AROUSE_BEGIN)
				sprite->SelectFrame(GUARD_ANI_AROUSE_BEGIN);
			if (sprite->GetCurrentFrame() >= GUARD_ANI_RUNNING_BEGIN && sprite->GetCurrentFrame() <= GUARD_ANI_RUNNING_END)
			{
				vx = GUARD_SPEED_X;
			}
			else
				vx = 0;
		}
	}
	else
	{
		
		if (sprite->GetCurrentFrame() >= GUARD_ANI_ATTACK2_END || sprite->GetCurrentFrame() < GUARD_ANI_ATTACK1_BEGIN)
		{
			sprite->SelectFrame(GUARD_ANI_ATTACK1_BEGIN);
			Aladdin->isCollisionWithEnemy = false;
		}
		vx = 0;
		if (((sprite->GetCurrentFrame() == 21) || (sprite->GetCurrentFrame() == 25))
			|| sprite->GetCurrentFrame() == 29 || sprite->GetCurrentFrame() == 31)
			isAttacking = true;
		else
			isAttacking = false;
	}
	if (this->x >= borderLeft && this->x <= borderRight)
	{
		if (detaX > 0)
		{
			this->direction = 1;
			dx = vx * dt;
			x -= dx;
		}
		else
		{
			this->direction = -1;
			dx = vx * dt;
			x += dx;
		}
	}
	else
	{
		if (this->x < borderLeft)
			this->x = borderLeft;
		else if(this->x > borderRight)
			this->x = borderRight;
	}
	float l, t, r, b;
	GetBoundingBox(l, t, r, b);
	sprite->Update(dt);
	
}

void Guard::Render(Camera * camera)
{

	if (this->status == INACTIVE)
	{
		return;
	}
	D3DXVECTOR2 pos = camera->Transform(x, y);
	if (direction == 1)
		sprite->Draw(pos.x, pos.y);
	else
		sprite->DrawFlipX(pos.x, pos.y);

}

void Guard::GetActiveBoundingBox(float &left, float &top, float &right, float &bottom, int id)
{
	if (id == - 1)
	{
		left = x + 40 - 160;
		top = y + 40;
		right = left + GUARD_BBOX_WIDTH - 40;
		bottom = top + GUARD_BBOX_HEIGHT;
	}
	else
	{
		left = x + 30 + 160;
		top = y + 40;
		right = left + GUARD_BBOX_WIDTH - 40;
		bottom = top + GUARD_BBOX_HEIGHT;
	}
}

void Guard::GetBoundingBox(float & left, float & top, float & right, float & bottom)
{
	if (isCollisionWithAladdin == true)
		return;
	if (status == ACTIVE)
	{
		if (isAttacking)
		{
			if (direction == 1)
			{
				left = x;
				top = y + 40;
				right = left + GUARD_BBOX_WIDTH + 30;
				bottom = top + GUARD_BBOX_HEIGHT;
			}
			else
			{
				left = x + 30;
				top = y + 40;
				right = left + GUARD_BBOX_WIDTH + 40;
				bottom = top + GUARD_BBOX_HEIGHT;
			}
		}
		else
		{
			if (direction == 1)
			{
				left = x + 40;
				top = y + 40;
				right = left + GUARD_BBOX_WIDTH;
				bottom = top + GUARD_BBOX_HEIGHT;
			}
			else
			{
				left = x + 30;
				top = y + 40;
				right = left + GUARD_BBOX_WIDTH;
				bottom = top + GUARD_BBOX_HEIGHT;
			}
		}
	}
	else
		return;
	
}
