#include "Apple.h"

Apple * Apple::Instance = NULL;

Apple::Apple()
{
	type = eType::APPLE;
	texture = TextureManager::GetInstance()->GetTexture(type);
	sprite = new CSprite(texture, 200);
	mState = 0;
	isAttacked = false;
	isCollisionWithBrick = false;
}

Apple::~Apple()
{
}

void Apple::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	if (isFinish)
		return;
	GameObject::Update(dt); // update dt,dx,dy 
	x += dx;
	y += dy;
	if(mState == 3)
		vy += APPLE_JUMP_GRAVITY;
	else
		vy += APPLE_GRAVITY;
	
	int StartFrame = 0; // ánh xạ chỉ số frame bằng level thay vì ifelse 
	int EndFrame = 5;
	if (StartFrame < sprite->GetCurrentFrame() && sprite->GetCurrentFrame() >= EndFrame)
	{
		sprite->SelectFrame(StartFrame);
		
	}
	sprite->Update(dt);
}

void Apple::Attack(float X, float Y, int Direction, int st)
{
	Weapon::Attack(X, Y, Direction, st);
	mState = st;
	UpdatePositionFitCharacter();
	sprite->SelectFrame(0);
	sprite->ResetTime();
}

void Apple::RenderIcon(float X, float Y)
{
}

void Apple::UpdatePositionFitCharacter()
{
	if (mState == 1)
	{
		if (direction == 1)
		{
			this->x = x + 30;
			this->y = y + 20;
		}
		else
		{
			this->x = x + 40;
			this->y = y + 20;
		}
	}
	if (mState == 2)
	{
		if (direction == 1)
		{
			this->x = x + 30;
			this->y = y + 40;
		}
		else
		{
			this->x = x + 40;
			this->y = y + 40;
		}
	}
	if (mState == 3)
	{
		if (direction == 1)
		{
			this->x = x + 30;
			this->y = y + 20;
		}
		else
		{
			this->x = x + 40;
			this->y = y + 20;
		}
	}
}

void Apple::Render(Camera * camera)
{
	D3DXVECTOR2 pos = camera->Transform(x, y);
	if (direction == 1)
		sprite->Draw(pos.x, pos.y);
	else
		sprite->DrawFlipX(pos.x, pos.y);
}

Apple * Apple::getInstance()
{
	if (Instance == NULL)
		Instance = new Apple();
	return Instance;
}

bool Apple::ableCollision(GameObject * obj)
{
	if (isFinish)
		return false;
	return Weapon::ableCollision(obj);

}

bool Apple::CollisionWithBrick(vector<LPGAMEOBJECT>* coObjects)
{
	vector<LPGAMEOBJECT> coBricks;
	coBricks.clear();
	for (UINT i = 0; i < coObjects->size(); i++)
	{
		if (dynamic_cast<Brick*>(coObjects->at(i)))
		{
			coBricks.push_back(coObjects->at(i));
		}
	}
	vector<LPCOLLISIONEVENT> coEvents;
	vector<LPCOLLISIONEVENT> coEventsResult;

	coEvents.clear();
	coEventsResult.clear();
	CalcPotentialCollisions(&coBricks, coEvents, flag);
	if (coEvents.size() == 0)
	{
		/*for (int i = 0; i < coBricks.size(); i++)
		{
			LPGAMEOBJECT e = coBricks.at(i);
			if (checkAABB(e))
			{
				return true;
			}
		}
		return false;*/
	}
	else 
	{
		float min_tx, min_ty, nx = 0, ny;
		FilterCollision(coEvents, coEventsResult, min_tx, min_ty, nx, ny);
		for (UINT i = 0; i < coEventsResult.size(); i++)
		{
			LPCOLLISIONEVENT e = coEventsResult[i];
			if (e->ny == -1)
			{
				isFinish = true;
				vx = 0;
				vy = 0;
				return true;
			}
			else
			{
				x += dx;
				y += dy;
				return false;
			}
		}
	}
	
}
