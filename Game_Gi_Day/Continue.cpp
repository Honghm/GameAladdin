#include "Continue.h"



Continue::Continue(float X, float Y, int W, int H, int st)
{
	this->Health = 1;
	texture = TextureManager::GetInstance()->GetTexture(eType::CONTINUE);
	this->x = X;
	this->y = Y;
	this->width = W;
	this->height = H;
	sprite = new CSprite(texture, 0);
	this->type = eType::CONTINUE;

}

void Continue::Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects)
{
	
}

void Continue::Render(Camera * camera)
{
	sprite->SelectFrame(0);
	D3DXVECTOR2 pos = camera->Transform(x, y);
	sprite->Draw(pos.x, pos.y);
}

void Continue::GetBoundingBox(float & l, float & t, float & r, float & b)
{
	l = x + 20;
	t = y;
	r =l + 20;
	b = y + height;
}


Continue::~Continue()
{
}
