#include "Boss.h"
#include "AladdinBeingAttackState.h"
Boss::Boss(int direction, float X, float Y, int status)
{
	x = X;
	y = Y;
	this->direction = direction;
	this->status = status;
	BackupX = x;
	backupDirection = direction;
	texture = TextureManager::GetInstance()->GetTexture(eType::BOSS);
	sprite = new CSprite(texture, 150);
	type = eType::BOSS;
	Health = 11;
	state = 1;
	isSnake = false;
}

Boss::~Boss()
{
}

void Boss::Update(DWORD dt, float xAladdin, float yAladdin, int dAladdin, Player* Aladdin)
{
	float dentaX = this->x - xAladdin;
	if (dentaX > 0)
		this->direction = -1;
	else
		this->direction = 1;

	if (state == 1)
	{
		if (sprite->GetCurrentFrame() <= BOSS_ANI_ATTACK_END)
		{
			sprite->Update(dt);
		}
		if (sprite->GetCurrentFrame() == 6)
		{
			mBullet.push_back(new Bullet(x, y + 40));
			sprite->SelectFrame(5);
		}
		if (mBullet.size() == 10)
			sprite->SelectFrame(BOSS_ANI_ATTACK_BEGIN);

		for (auto obj : mBullet)
		{
			obj->Update(dt, xAladdin + 50, yAladdin + 60, this->direction);
			CollisionWithAladdin(Aladdin);
		}
		if (mBullet.size() == 10)
		{
			mBullet.clear();
		}
	}
	else
	{
		if (isSnake == false)
		{
			sprite->SetTimeAnimation(50);
			if (sprite->GetCurrentFrame() <= BOSS_ANI_SNAKE_ATTACK_END)
				sprite->Update(dt);
			if (sprite->GetCurrentFrame() == BOSS_ANI_SNAKE_ATTACK_END)
				isSnake = true;
		}
		else
		{
			sprite->SetTimeAnimation(150);
			if (sprite->GetCurrentFrame() < BOSS_ANI_SNAKE_ATTACK_BEGIN || sprite->GetCurrentFrame() >= BOSS_ANI_SNAKE_ATTACK_END)
			{
				if (yAladdin <= 220 && Aladdin->isCollisionWithBrick)
				{
					if(mBurn.size() > 3)
						mBurn.clear();
					mBurn.push_back(new Burn(xAladdin + 40, yAladdin + 30, 2));
				}
				else
				{
					mBurn.clear();
					mBurn.push_back(new Burn(x, y + 40, 1));
				}
				sprite->SelectFrame(BOSS_ANI_SNAKE_ATTACK_BEGIN);
			}
			sprite->Update(dt);
			for (auto obj : mBurn)
			{
				obj->Update(dt, xAladdin + 50, yAladdin + 30, this->direction);
				CollisionWithAladdin(Aladdin);
			}
		}

	}
	for (auto obj : listEffect)
	{
		if (!dynamic_cast<Effect*>(obj)->IsFinish())
			obj->Update(dt);
	}
	//Aladdin->Update(dt);
}

void Boss::Render(Camera * camera)
{
	D3DXVECTOR2 pos = camera->Transform(x, y);
	if (direction == 1)
		sprite->Draw(pos.x, pos.y);
	else
		sprite->DrawFlipX(pos.x, pos.y);
	for (auto obj : mBullet)
	{
		obj->Render(camera);
	}
	for (auto obj : mBurn)
	{
		obj->Render(camera);
	}
	for (auto obj : listEffect)
	{
		obj->Render(camera);
	}
}

void Boss::GetBoundingBox(float & left, float & top, float & right, float & bottom)
{
	if (state == 1)
	{
		left = x + 60;
		top = y + 30;
		right = left + 25;
		bottom = top + 70;
	}
	else
	{
		left = x + 45;
		top = y + 20;
		right = left + 75;
		bottom = top + 85;
	}
}

void Boss::GetActiveBoundingBox(float & left, float & top, float & right, float & bottom, int id)
{
}

void Boss::SetStatus(int s)
{
}

void Boss::SetState(int a)
{
	switch (a)
	{
	case 1:
		state = 1;
		sprite->SelectFrame(BOSS_ANI_ATTACK_BEGIN);
		break;
	case 2:
		state = 2;
		sprite->SelectFrame(BOSS_ANI_SNAKE_BEGIN);
	}

}

void Boss::CollisionWithAladdin(Player * Aladdin)
{
	float l, t, r, b;
	for (auto bullet : mBullet)
	{
		if (bullet->isCollitionObjectWithObject(Aladdin))
		{
			Aladdin->isCollisionWithBurn = false;
			Aladdin->isCollisionWithBullet = true;
			bullet->status = INACTIVE;
			bullet->SetFinish(true);
			listEffect.push_back(new Effect(Aladdin->x, Aladdin->y, eType::ALADDIN, 3));
			bullet->GetBoundingBox(l, t, r, b);
			if (this->direction == -1)
			{
				Aladdin->SetSpeed(0.2, 0);
				Aladdin->x += 5;
			}
			else
			{
				Aladdin->vx = -0.2;
				Aladdin->x -= 5;
			}
		}
		else
			Aladdin->isCollisionWithBullet = false;
	}
	for (auto burn : mBurn)
	{

		if (burn->isCollitionObjectWithObject(Aladdin))
		{
			Aladdin->isCollisionWithBullet = false;
			Aladdin->isCollisionWithBurn = true;
			burn->status = INACTIVE;
			burn->GetBoundingBox(l, t, r, b);
			Aladdin->SubHealth();

		}
		else
			Aladdin->isCollisionWithBurn = false;
	}
}
