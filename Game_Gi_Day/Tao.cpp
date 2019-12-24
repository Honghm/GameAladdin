#include "Tao.h"



Tao::Tao(float X, float Y, int W, int H, int st)
{
	this->Health = 1;
	texture = TextureManager::GetInstance()->GetTexture(eType::TAO);
	this->x = X;
	this->y = Y;
	this->width = W;
	this->height = H;
	sprite = new CSprite(texture, 0);
	this->type = eType::TAO;

}

void Tao::Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects)
{
	float l, t, r, b;
	GetBoundingBox(l, t, r, b);
}

void Tao::Render(Camera * camera)
{
	if (this->isFinish==true || this->Health==0)
		return;
	sprite->SelectFrame(0);
	D3DXVECTOR2 pos = camera->Transform(x, y);
	sprite->Draw(pos.x, pos.y);
}

void Tao::GetBoundingBox(float & l, float & t, float & r, float & b)
{
	if (this->isFinish == true || this->Health == 0)
		return;
	l = x + 16;
	t = y + 16;
	r = x + width - 16;
	b = y + height - 16;
}


Tao::~Tao()
{
}
