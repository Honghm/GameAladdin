#include "Soldier.h"
#include "Brick.h"

Soldier::Soldier(int direction, float X, float Y, float BorderLeft, float BorderRight, int status)
{
	x = X;
	y = Y;
	this->direction = direction;
	borderLeft = BorderLeft;
	borderRight = BorderRight;
	this->status = status;
	BackupX = x;
	backupDirection = direction;
	texture = TextureManager::GetInstance()->GetTexture(eType::SOLDIER);
	sprite = new CSprite(texture, 100);
	isAttacking = false;
	Health = 1; // sét máu
	type = eType::SOLDIER;
	vx = SOLDIER_SPEED_X * this->direction;
}

Soldier::~Soldier()
{
}

void Soldier::SetStatus(int s)
{
	Enemy::SetStatus(s);

	switch (this->status)
	{
	case ACTIVE:
		break;
	case DEATH:
		break;
	case INACTIVE:
		x = BackupX;
		direction = backupDirection;
		vx = SOLDIER_SPEED_X * direction;
		//Health = 1;
		break;
	default:
		break;
	}
}
void Soldier::Update(DWORD dt, float xAladdin, float yAladdin, int dAladdin, vector<LPGAMEOBJECT>* coObjects)
{
	if (status == INACTIVE)
		return;
	if (this->Health <= 0)
	{
		status = INACTIVE;
	}
	float detaX = this->x - xAladdin;
	if (detaX > 60 || detaX < -60)
	{
		isAttacking = false;
		if (this->GetX() >= borderLeft && this->GetX() <= borderRight)
		{
			if (sprite->GetCurrentFrame() < SOLDIER_ANI_RUNNING_BEGIN || sprite->GetCurrentFrame() > SOLDIER_ANI_RUNNING_END)
			{
				this->sprite->SelectFrame(SOLDIER_ANI_RUNNING_BEGIN);
			}
			vx = SOLDIER_SPEED_X;
		}
		else
		{
			if (this->sprite->GetCurrentFrame() == SOLDIER_ANI_RUNNING_END)
				return;
			this->sprite->SelectFrame(SOLDIER_ANI_RUNNING_END);
			vx = 0;
		}
	}
	else
	{
		if (sprite->GetCurrentFrame() >= SOLDIER_ANI_ATTACK_END || sprite->GetCurrentFrame() < SOLDIER_ANI_ATTACK_BEGIN)
			sprite->SelectFrame(SOLDIER_ANI_ATTACK_BEGIN);
		vx = 0;
		if ((sprite->GetCurrentFrame() >= 12) && (sprite->GetCurrentFrame() <= 14))
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
		else if (this->x > borderRight)
			this->x = borderRight;
	}
	float l, t, r, b;
	GetBoundingBox(l, t, r, b);

	sprite->Update(dt);
}

void Soldier::Render(Camera * camera)
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

void Soldier::GetActiveBoundingBox(float &left, float &top, float &right, float &bottom, int id)
{
	
}

void Soldier::GetBoundingBox(float & left, float & top, float & right, float & bottom)
{
	if (status == ACTIVE)
	{
		if (isAttacking)
		{
			if (direction == 1)
			{
				left = x;
				top = y + 40;
				right = left + SOLDIER_BBOX_WIDTH + 30;
				bottom = top + SOLDIER_BBOX_HEIGHT;
			}
			else
			{
				left = x + 30;
				top = y + 40;
				right = left + SOLDIER_BBOX_WIDTH + 40;
				bottom = top + SOLDIER_BBOX_HEIGHT;
			}
		}
		else
		{
			if (direction == 1)
			{
				left = x + 60;
				top = y + 35;
				right = left + SOLDIER_BBOX_WIDTH;
				bottom = top + SOLDIER_BBOX_HEIGHT;
			}
			else
			{
				left = x + 30;
				top = y + 40;
				right = left + SOLDIER_BBOX_WIDTH;
				bottom = top + SOLDIER_BBOX_HEIGHT;
			}
		}
	}
	else
		return;

}
