#include "ColumnWall.h"

ColumnWall::ColumnWall(float X, float Y, int W, int H, int st)
{
	switch (st)
	{
	case 1:
		type = eType::COLUMN1;
		break;
	case 2:
		type = eType::COLUMN2;
		break;
	case 3:
		type = eType::COLUMN3;
		break;
	case 4:
		type = eType::COLUMN4;
		break;
	}
	x = X;
	y = Y;
	width = W;
	height = H;
	texture = TextureManager::GetInstance()->GetTexture(type);
	sprite = new CSprite(texture, 1000);
}

ColumnWall::~ColumnWall()
{
}

void ColumnWall::GetBoundingBox(float & left, float & top, float & right, float & bottom)
{
	left = x;
	top = y;
	right = x + width;
	bottom = y + height;
}

void ColumnWall::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
}

void ColumnWall::Render(Camera * camera)
{
	D3DXVECTOR2 pos = camera->Transform(x, y);
	sprite->Draw(pos.x, pos.y);
}
