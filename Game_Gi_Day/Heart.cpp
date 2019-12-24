#include "Heart.h"



Heart::Heart(float X, float Y, int W, int H, int st)
{
	texture = TextureManager::GetInstance()->GetTexture(eType::HEART);
	this->x = X;
	this->y = Y;
	this->width = W;
	this->height = H;
	sprite = new CSprite(texture, 0);
	this->type = eType::HEART;

}

void Heart::Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects)
{
	this->sprite->SetTimeAnimation(2000);
	if (this->sprite->GetCurrentFrame() < HEART_ANI_BEGIN || this->sprite->GetCurrentFrame() > HEART_ANI_END)
	{

		this->sprite->SelectFrame(HEART_ANI_BEGIN);
	}
	this->sprite->Update(dt);
}

void Heart::Render(Camera * camera)
{
	if (isFinish)
		return;
	//sprite->SelectFrame(0);
	D3DXVECTOR2 pos = camera->Transform(x, y);
	sprite->Draw(pos.x, pos.y);

}

void Heart::GetBoundingBox(float & l, float & t, float & r, float & b)
{
	l = x + 16;
	t = y + 16;
	r = x + width - 16;
	b = y + height - 16;
}


Heart::~Heart()
{
}
