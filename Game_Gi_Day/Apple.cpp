#include "Apple.h"

Apple * Apple::Instance = NULL;

Apple::Apple()
{
	type = eType::APPLE;
	texture = TextureManager::GetInstance()->GetTexture(type);
	sprite = new CSprite(texture, 200);
	mState = 0;
	isAttacked = false;
	//vy = 0;
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
	if (StartFrame <= sprite->GetCurrentFrame() && sprite->GetCurrentFrame() < EndFrame)
	{
		sprite->Update(dt);
	}
	else
	{
		sprite->SelectFrame(StartFrame);
		isFinish = true;
	}
	
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
	if (isFinish)
		return;
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
