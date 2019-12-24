#include "Katana.h"

Katana::Katana()
{
	type = eType::KATANA;
	texture = TextureManager::GetInstance()->GetTexture(type);
	sprite = new CSprite(texture, 85);
	mState = 0;
	isAttacked = false;
	
}

Katana::~Katana()
{

}

void Katana::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	GameObject::Update(dt);
	int StartFrame;
	int EndFrame;
	if (mState == 1)
	{
		//sprite->SetTimeAnimation(140);
		isFinish = sprite->GetCurrentFrame() == KATANA_STANDING_END;
		StartFrame = KATANA_STANDING_START;
		EndFrame = KATANA_STANDING_END;
	}
	else if (mState == 2)
	{
		//sprite->SetTimeAnimation(150);
		isFinish = sprite->GetCurrentFrame() == KATANA_SITTING_END;
		StartFrame = KATANA_SITTING_START;
		EndFrame = KATANA_SITTING_END;
	}
	else if (mState == 3)
	{
		isFinish = sprite->GetCurrentFrame() == KATANA_JUMPING_END;
		StartFrame = KATANA_JUMPING_START;
		EndFrame = KATANA_JUMPING_END;
	}
	else if (mState == 4)
	{
		
		isFinish = sprite->GetCurrentFrame() == KATANA_RUNNING_END;
		StartFrame = KATANA_RUNNING_START;
		EndFrame = KATANA_RUNNING_END;
	}
	if (isAttacked == true)
	{
		if (StartFrame <= sprite->GetCurrentFrame() && sprite->GetCurrentFrame() < EndFrame)
		{
			if (mState == 1)
			{
				if (sprite->GetCurrentFrame() == 4)
					SetStatus(ACTIVE);
			}
			else if (mState == 2)
			{
				if (sprite->GetCurrentFrame() == 10)
					SetStatus(ACTIVE);
			}
			else if (mState == 3)
			{
				if (sprite->GetCurrentFrame() == 3)
					SetStatus(ACTIVE);
			}
			else if (mState == 4)
			{
				if (sprite->GetCurrentFrame() == 19|| sprite->GetCurrentFrame()==20)
					SetStatus(ACTIVE);
			}
			else
				SetStatus(INACTIVE);

			this->dx = this->vx*dt;
			this->dy = this->vy*dt;
			this->x += dx;
			this->y += dy;

			float l, t, r, b;
			GetBoundingBox(l, t, r, b);
			
			sprite->Update(dt);
		}
	}
	else
	{
		sprite->SelectFrame(StartFrame);
	}
}

void Katana::Render(Camera * camera)
{
	D3DXVECTOR2 pos = camera->Transform(x, y);
	if (direction == 1)
		sprite->Draw(pos.x, pos.y);
	else
		sprite->DrawFlipX(pos.x, pos.y);
	RenderBoundingBox(camera);
}

void Katana::GetBoundingBox(float & left, float & top, float & right, float & bottom)
{
	if (status == ACTIVE)
	{
		if (direction == 1)
		{
			left = x;
			top = y;
			right = left + 54;
			bottom = top + 56;
		}
		else
		{
			left = x;
			top = y;
			right = left + 54;
			bottom = top + 56;
		}
	}
	else
		return;
	
}

void Katana::Attack(float X, float Y, int Direction, int st)
{
	Weapon::Attack(X, Y, Direction,st);
	mState = st;
	if(st == 1)
		sprite->SelectFrame(KATANA_STANDING_START);
	else if(st == 2)
		sprite->SelectFrame(KATANA_SITTING_START);
	else if(st == 3)
		sprite->SelectFrame(KATANA_JUMPING_START);
	else if(st==4)
		sprite->SelectFrame(KATANA_RUNNING_START);
	UpdatePositionFitCharacter();
	sprite->ResetTime();

}

bool Katana::ableCollision(GameObject * obj)
{
	if (sprite->GetCurrentFrame() == KATANA_STANDING_START|| sprite->GetCurrentFrame() == KATANA_SITTING_START
		||sprite->GetCurrentFrame()==KATANA_JUMPING_START||sprite->GetCurrentFrame()==KATANA_RUNNING_START)
		return false;
	return Weapon::ableCollision(obj);
}

void Katana::UpdatePositionFitCharacter()
{
	if (mState == 1)// đang đứng
	{
		if (direction == -1)
		{
			this->x = x - 15;
			this->y = y + 15;
		}
		else
		{
			this->x = x + 60;
			this->y = y + 15;
			
		}
	}
	if(mState == 2) //ngồi
	{
		
		if (direction == -1)
		{
			this->x = x - 20;
			this->y = y + 30;
		}
		else
		{
			this->x = x + 65;
			this->y = y + 30;
		}
	}
	if (mState == 3)
	{
		this->vy = 0.1f*this->direction;
		if (direction == -1)
		{
			this->x = x - 10;
			this->y = y + 10;
		}
		else
		{
			this->x = x + 60;
			this->y = y + 30;
		}
	}
	if (mState == 4)
	{
		this->vx = 0.2f*this->direction;
		if (direction == -1)
		{
			this->x = x - 10;
			this->y = y + 10;
		}
		else
		{
			this->x = x + 60;
			this->y = y + 20;
		}
	}
}

void Katana::RenderIcon(float X, float Y)
{
}

void Katana::SetStatus(int s)
{
	Weapon::SetStatus(s);
}




//sao sao