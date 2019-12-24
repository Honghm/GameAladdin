#include "Bat.h"
#include "Brick.h"
Bat::Bat(int direction, float X, float Y, float BorderLeft, float BorderRight, int status)
{
	x = X;
	y = Y;
	this->direction = direction;
	Ox = BorderLeft;
	Oy = BorderRight;
	backupOx = BorderLeft;
	backupOy = BorderRight;
	this->status = status;
	BackupX = x;
	backupY = y;
	backupDirection = direction;
	texture = TextureManager::GetInstance()->GetTexture(eType::BAT);
	sprite = new CSprite(texture, 100);
	isAttacking = false;
	Health = 1; // sét máu
	type = eType::BAT;
	vx = BAT_SPEED_X * this->direction;
	vy = BAT_SPEED_Y * this->direction;
	
}

Bat::~Bat()
{
}

void Bat::SetStatus(int s)
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
		y = backupY;
		direction = backupDirection;
		vx = BAT_SPEED_X * direction;
		vy = BAT_SPEED_Y * direction;
		//Health = 1;
		break;
	default:
		break;
	}
}
void Bat::Move(float &x, float &y, int st)
{
	
	
}

void Bat::Update(DWORD dt, float xAladdin, float yAladdin, int dAladdin, vector<LPGAMEOBJECT>* coObjects)
{
	float detaX = this->x - xAladdin;
	if (this->Health <= 0)
	{
		status = INACTIVE;
	}
	if (status == ACTIVE)
	{
		if (sprite->GetCurrentFrame() <= BAT_ANI_RUNNING_BEGIN || sprite->GetCurrentFrame() >= BAT_ANI_RUNNING_END)
			sprite->SelectFrame(BAT_ANI_RUNNING_BEGIN);
		
		
		dy = vy;
		float Mx = x - Ox;
		float My = y - Oy;

		if (Mx <= 0 && My < 0)
		{
			x = -sqrt(abs(pow(66, 2) - ((pow(66, 2) / pow(47, 2))*pow(My, 2)))) + Ox;
			y += dy;
		}
		if (Mx < 0 && My >= 0)
		{
			x = -sqrt(abs(pow(66, 2) - ((pow(66, 2) / pow(47, 2))*pow(My, 2)))) + Ox;
			y += dy;
		}
		if (Mx >= 0 && My > 0)
		{
			x = sqrt(abs(pow(66, 2) - ((pow(66, 2) / pow(47, 2))*pow(My, 2)))) + Ox;
			y -= dy;
		}
		if (Mx > 0 && My <= 0)
		{
			x = sqrt(abs(pow(66, 2) - ((pow(66, 2) / pow(47, 2))*pow(My, 2)))) + Ox;
			y -= dy;
		}
	}
	sprite->Update(dt);
}

void Bat::Render(Camera * camera)
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

void Bat::GetActiveBoundingBox(float &left, float &top, float &right, float &bottom, int id)
{

}

void Bat::GetBoundingBox(float & left, float & top, float & right, float & bottom)
{
	if (status == ACTIVE)
	{
		left = x + 30;
		top = y + 50;
		right = left + BAT_BBOX_WIDTH;
		bottom = top + BAT_BBOX_HEIGHT;
	}
	else
		return;

}
