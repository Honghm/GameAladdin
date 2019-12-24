#include "Effect.h"


Effect::Effect(float X, float Y, int st, int state)
{
	x = X;
	y = Y;
	this->state = state;
	switch (state)
	{
	case 1:
		type = eType::EFFECT_1;
		break;
	case 2:
		type = eType::EFFECT_2;
		break;
	case 3:
		type = eType::EFFECT_3;
		break;
	case 4:
		type = eType::EFFECT_4;
		break;
	default:
		break;
	}

	texture = TextureManager::GetInstance()->GetTexture(type);
	sprite = new CSprite(texture, 70);
	isFinish = false;
	UpdatePositionFitCharacter(st);
}

Effect::~Effect()
{
}

//void Effect::GetBoundingBox(float & left, float & top, float & right, float & bottom)
//{
//	left = x;
//	top = y;
//	right = x + width;
//	bottom = y + height;
//}

void Effect::Update(DWORD dt)
{
	if (state == 1)
	{
		if (sprite->GetCurrentFrame() >= 4)
			isFinish = true;
		else
			isFinish = false;
	}
	else if (state == 2)
	{
		if (sprite->GetCurrentFrame() >= 14)
			isFinish = true;
		else
			isFinish = false;
	}
	else if (state == 3)
	{
		if (sprite->GetCurrentFrame() >= 2)
			isFinish = true;
		else
			isFinish = false;
	}
	else if (state == 4)
	{
		if (sprite->GetCurrentFrame() >= 9)
			isFinish = true;
		else
			isFinish = false;
	}
	sprite->Update(dt);

}

void Effect::Render(Camera * camera)
{
	if (isFinish == true)
		return;
	D3DXVECTOR2 pos = camera->Transform(x, y);
	sprite->Draw(pos.x, pos.y);
}

void Effect::UpdatePositionFitCharacter(int st)
{
	switch (st)
	{
	case eType::GUARD:
		x += 60;
		y += 60;
		break;
	case eType::SOLDIER:
		x += 60;
		y += 60;
		break;
	case eType::BAT:
		x += 30;
		y += 50;
		break;
	case eType::BOSS:
		x += 50;
		y += 50;
		break;
	case eType::ALADDIN:
		x += 25;
		y += 50;
		break;
	case 0:
		x += 40;
		break;
	}

}
