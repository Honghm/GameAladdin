#include "HealthCol.h"



void HealthCol::Render()
{
	this->sprite->Draw(0, -20);
	int x = this->health;
}


void HealthCol::Update(DWORD dt)
{
	if (health > 8)
	{
		health = 8;
	}
	if (health < 0)
	{
		health = 0;
	}
	if (health ==8)
	{
		if (this->sprite->GetCurrentFrame() < ANI_HEALTH_8_END ||this->sprite->GetCurrentFrame() > ANI_HEALTH_8_END)
		{
			this->sprite->SelectFrame(ANI_HEALTH_8_BEGIN);
		}
		this->sprite->Update(dt);
	}
	 if (health == 7)
	{
		if (this->sprite->GetCurrentFrame() < ANI_HEALTH_7_END || this->sprite->GetCurrentFrame() > ANI_HEALTH_7_END)
		{
			this->sprite->SelectFrame(ANI_HEALTH_7_BEGIN);
		}
		this->sprite->Update(dt);
	}
	 if (health == 6)
	{
		if (this->sprite->GetCurrentFrame() < ANI_HEALTH_6_END || this->sprite->GetCurrentFrame() > ANI_HEALTH_6_END)
		{
			this->sprite->SelectFrame(ANI_HEALTH_6_BEGIN);
		}
		this->sprite->Update(dt);
	}
	 if (health == 5)
	{
		if (this->sprite->GetCurrentFrame() < ANI_HEALTH_5_END || this->sprite->GetCurrentFrame() > ANI_HEALTH_5_END)
		{
			this->sprite->SelectFrame(ANI_HEALTH_5_BEGIN);
		}
		this->sprite->Update(dt);
	}
	 if (health == 4)
	{
		if (this->sprite->GetCurrentFrame() < ANI_HEALTH_4_END || this->sprite->GetCurrentFrame() > ANI_HEALTH_4_END)
		{
			this->sprite->SelectFrame(ANI_HEALTH_4_BEGIN);
		}
		this->sprite->Update(dt);
	}
	 if (health == 3)
	{
		if (this->sprite->GetCurrentFrame() < ANI_HEALTH_3_END || this->sprite->GetCurrentFrame() > ANI_HEALTH_3_END)
		{
			this->sprite->SelectFrame(ANI_HEALTH_3_BEGIN);
		}
		this->sprite->Update(dt);
	}
	if (health == 2)
	{
		if (this->sprite->GetCurrentFrame() < ANI_HEALTH_2_END || this->sprite->GetCurrentFrame() > ANI_HEALTH_2_END)
		{
			this->sprite->SelectFrame(ANI_HEALTH_2_BEGIN);
		}
		this->sprite->Update(dt);
	}
	if (health == 1)
	{
		if (this->sprite->GetCurrentFrame() < ANI_HEALTH_1_END || this->sprite->GetCurrentFrame() > ANI_HEALTH_1_END)
		{
			this->sprite->SelectFrame(ANI_HEALTH_1_BEGIN);
		}
		this->sprite->Update(dt);
	}
	
	if (health == 0)
	{
		this->sprite->SelectFrame(ANI_HEALTH_0);
	}
	
}

void HealthCol::SetHealth(int x)
{
	 health = x;
}

HealthCol::HealthCol()
{	
	texture = TextureManager::GetInstance()->GetTexture(eType::HEARTCOL);
	sprite = new CSprite(texture, 150);
}


HealthCol::~HealthCol()
{
}
