#include "Ghost.h"
#include "Brick.h"
#include "Bone.h"
Ghost::Ghost(int direction, float X, float Y, float BorderLeft, float BorderRight, int status)
{
	x = X;
	y = Y;
	this->direction = direction;
	borderLeft = BorderLeft;
	borderRight = BorderRight;
	this->status = status;
	BackupX = x;
	backupDirection = direction;
	texture = TextureManager::GetInstance()->GetTexture(eType::GHOST);
	sprite = new CSprite(texture, 80);
	isAttacking = false;
	Health = 1; // sét máu
	type = eType::GHOST;
	vx = GHOST_SPEED_X * this->direction;
	mBone.clear();
	for (int i = 0; i < 10; i++)
	{
		mBone.push_back(new Bone(this->x + 30, this->y + 30));
	}
	isFinish = false;
}

Ghost::~Ghost()
{
}

void Ghost::SetStatus(int s)
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
		vx = GHOST_SPEED_X * direction;
		//Health = 1;
		break;
	default:
		break;
	}
}
void Ghost::CollisionWithAladdin(Player * Aladdin)
{

	for (auto bone : mBone)
	{
		if (bone->isCollitionObjectWithObject(Aladdin))
		{
			Aladdin->SubHealth();
		}
	}
}
void Ghost::Update(DWORD dt, float xAladdin, float yAladdin, int dAladdin, Player* Aladdin)
{
	float l, t, r, b;
	float dentaX = this->x - xAladdin;
	float dentaY = this->y - yAladdin;
	if (dentaX <= 80 && dentaX >= -80)
	{
		if (dentaY >= -80 && dentaY <= 80)
		{
			status = ACTIVE;
		}

	}
	else
		status = INACTIVE;
	if (status == INACTIVE)
		return;
	if (this->Health <= 0)
	{
		status = INACTIVE;
	}
	if (status == ACTIVE)
	{
		if (sprite->GetCurrentFrame() <= GHOST_ANI_RUNNING_END)
		{
			sprite->Update(dt);
		}
		else
		{

			isFinish = true;
			for (auto obj : mBone)
			{
				obj->Update(dt);
			}
			status = INACTIVE;
		}
	}
	this->GetBoundingBox(l, t, r, b);
}

void Ghost::Render(Camera * camera)
{


	if (isFinish == false)
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
	else
	{

		for (auto obj : mBone)
		{
			obj->Render(camera);
		}
	}


}

void Ghost::GetActiveBoundingBox(float &left, float &top, float &right, float &bottom, int id)
{

}

void Ghost::GetBoundingBox(float & left, float & top, float & right, float & bottom)
{
	if (status == ACTIVE)
	{
		if (isAttacking)
		{
			if (direction == 1)
			{
				left = x;
				top = y + 40;
				right = left + GHOST_BBOX_WIDTH + 30;
				bottom = top + GHOST_BBOX_HEIGHT;
			}
			else
			{
				left = x + 30;
				top = y + 40;
				right = left + GHOST_BBOX_WIDTH + 40;
				bottom = top + GHOST_BBOX_HEIGHT;
			}
		}
		else
		{
			if (direction == 1)
			{
				left = x + 60;
				top = y + 35;
				right = left + GHOST_BBOX_WIDTH;
				bottom = top + GHOST_BBOX_HEIGHT;
			}
			else
			{
				left = x + 30;
				top = y + 40;
				right = left + GHOST_BBOX_WIDTH;
				bottom = top + GHOST_BBOX_HEIGHT;
			}
		}
	}
	else
		return;

}
