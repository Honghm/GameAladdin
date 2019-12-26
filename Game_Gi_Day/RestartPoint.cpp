#include "RestartPoint.h"
#include"AladdinData.h"
#include"AladdinState.h"

RestartPoint::RestartPoint(float X, float Y, int W, int H, int st)
{
	texture = TextureManager::GetInstance()->GetTexture(eType::RESTARTPOINT);
	this->x = X;
	this->y = Y;
	this->width = W;
	this->height = H;
	this->Health = 1;
	sprite = new CSprite(texture, 50);
	this->type = eType::RESTARTPOINT;
	

}

void RestartPoint::Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects)
{
	if (this->Health > 0)
	{
		sprite->SelectFrame(0);	
	}
	else
	{
		for (int i = RESTARTPOINT_ANI_BEGIN + 1; i <= RESTARTPOINT_ANI_END; i++)
		{
			sprite->SelectFrame(i);
		}
	}
}

void RestartPoint::Render(Camera * camera)
{
	D3DXVECTOR2 pos = camera->Transform(x, y);
	sprite->Draw(pos.x, pos.y);
}

void RestartPoint::GetBoundingBox(float & l, float & t, float & r, float & b)
{
	l = x ;
	t = y ;
	r = x + width-50;
	b = y + height -50;
}


RestartPoint::~RestartPoint()
{
}
