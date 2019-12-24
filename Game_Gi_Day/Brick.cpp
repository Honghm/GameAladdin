#include "Brick.h"




Brick::Brick(float X, float Y, int W, int H)
{

	texture = TextureManager::GetInstance()->GetTexture(eType::BRICK_TRANSPARENT);// loại trong suốt 

	type = eType::BRICK;
	sprite = new CSprite(texture, 1000);
	this->x = X;
	this->y = Y;
	this->width = W;
	this->height = H;
}

void Brick::Render(Camera * camera)
{
	
}

void Brick::GetBoundingBox(float &l, float &t, float &r, float &b)
{
	l = x;
	t = y;
	float a = ceil(width / texture->GetFrameWidth());
	int bb = width / texture->GetFrameWidth();
	r = x + (float)width / texture->GetFrameWidth()*texture->GetFrameWidth();
	b = y + (float)height / texture->GetFrameHeight()*texture->GetFrameHeight();
}

