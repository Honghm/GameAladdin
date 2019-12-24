#pragma once
#include"GameObject.h"
#include"TextureManager.h"
#include"Player.h"
#include"Texture.h"
#include"Sprite.h"


#define ANI_HEALTH_0 32
#define ANI_HEALTH_1_BEGIN 28  
#define ANI_HEALTH_1_END 31
#define ANI_HEALTH_2_BEGIN 24 
#define ANI_HEALTH_2_END 27
#define ANI_HEALTH_3_BEGIN 20
#define ANI_HEALTH_3_END 23
#define ANI_HEALTH_4_BEGIN 16
#define ANI_HEALTH_4_END 19
#define ANI_HEALTH_5_BEGIN 12
#define ANI_HEALTH_5_END 15
#define ANI_HEALTH_6_BEGIN 8 
#define ANI_HEALTH_6_END 11
#define ANI_HEALTH_7_BEGIN 4 
#define ANI_HEALTH_7_END 7
#define ANI_HEALTH_8_BEGIN 0
#define ANI_HEALTH_8_END 3
class HealthCol
{
public:
	CTexture* texture;
	CSprite* sprite;
	int health;
public:
	void Render();
	void Update(DWORD dt);
	void SetHealth(int x);
	HealthCol();
	~HealthCol();
	
};

