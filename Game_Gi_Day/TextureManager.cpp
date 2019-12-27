#include "TextureManager.h"

TextureManager* TextureManager::__Instance = NULL;

TextureManager * TextureManager::GetInstance()
{
	if (__Instance == NULL)
		__Instance = new TextureManager();
	return __Instance;
}

void TextureManager::AddTexture(eType type, CTexture *texture)
{
	_ArrTextures[type] = texture;
}

CTexture * TextureManager::GetTexture(eType type)
{
	return _ArrTextures[type];
}

void TextureManager::LoadResource()
{

	//map
	AddTexture(eType::MAP1, new CTexture("Resources/TileMap.png", 69, 35, 2411));
	AddTexture(eType::MAP2, new CTexture("Resources/Boss/Map_Boss.png", 26, 11, 276,0,0,0));
	AddTexture(eType::BACKGROUND, new CTexture("Resources/Boss/BackgroundBoss.png"));

	AddTexture(eType::COLUMN1, new CTexture("Resources/Ground/column1.png"));
	AddTexture(eType::COLUMN2, new CTexture("Resources/Ground/column2.png"));
	AddTexture(eType::COLUMN3, new CTexture("Resources/Ground/column3.png"));
	AddTexture(eType::COLUMN4, new CTexture("Resources/Ground/column4.png"));
	AddTexture(eType::CONTINUE, new CTexture("Resources/Item/Exit.png"));
	//HeartCol
	AddTexture(eType::HEARTCOL, new CTexture("Resources/thanhmau150x90.png", 10, 4, 40));
	//FaceAladdin
	AddTexture(eType::FACEALADDIN, new CTexture("Resources/Item/mataladdin.png", 21, 1, 21));
	//Enemy
	AddTexture(eType::GUARD, new CTexture("Resources/Enemy/PalaceGuards.png", 7, 9, 63));
	AddTexture(eType::SOLDIER, new CTexture("Resources/Enemy/linhcanh.png", 12, 2, 24));
	AddTexture(eType::GHOST, new CTexture("Resources/Enemy/boxuong120x120.png", 12, 2, 24));
	AddTexture(eType::BAT, new CTexture("Resources/Enemy/bat80x80.png", 20, 1, 20));
	//Rock
	AddTexture(eType::ROCK, new CTexture("Resources/Platform/rock50x50.png", 5, 4, 20));
	//Thorn 
	AddTexture(eType::THORN, new CTexture("Resources/Platform/thorn70x50.png", 6, 2, 12));
	//Marble
	AddTexture(eType::MARBLE, new CTexture("Resources/Platform/marble80x80.png", 8, 8, 64));
	//apple1 
	AddTexture(eType::TAO, new CTexture("Resources/Item/apple40x40.png"));
	//player
	AddTexture(eType::ALADDIN, new CTexture("Resources/AladdinFull.png", 15, 16, 240));
	//Genie
	AddTexture(eType::GENIE, new CTexture("Resources/Item/genie80x80.png", 4, 1, 4));
	//Heart
	AddTexture(eType::HEART, new CTexture("Resources/Item/heart40x40.png", 3, 1, 3));
	//RedRock
	AddTexture(eType::REDROCK, new CTexture("Resources/Item/redrock40x40.png", 9, 1, 9));
	//RestartPoint
	AddTexture(eType::RESTARTPOINT, new CTexture("Resources/Item/restartpoint.png", 10, 1, 10));
	//Number
	AddTexture(eType::NUMBER, new CTexture("Resources/number10x10.png", 10, 1, 10, 106, 148, 189));
	//ground
	AddTexture(eType::BRICK_TRANSPARENT, new CTexture("Resources/Ground/Brick_Black.png", 1, 1, 1, 255, 0, 255));
	AddTexture(eType::OBJECT_HIDDEN, new CTexture("Resources/Ground/Brick_Black.png", 1, 1, 1, 255, 0, 255));
	// BBOX
	AddTexture(eType::RENDERBBOX, new CTexture("Resources/bbox.png", 1, 1, 1, 255, 0, 0));
	//WEAPON
	AddTexture(eType::KATANA, new CTexture("Resources/Weapon/Katana.png", 7, 3, 21));
	AddTexture(eType::APPLE, new CTexture("Resources/Weapon/Apple.png", 6, 1, 6));
	AddTexture(eType::BONE, new CTexture("Resources/Enemy/bone.png", 4, 1, 4));
	//EFFECT
	AddTexture(eType::EFFECT_1, new CTexture("Resources/Effect/Effect_1.png", 5, 1, 5));
	AddTexture(eType::EFFECT_2, new CTexture("Resources/Effect/Effect_2.png", 15, 1, 15, 186, 254, 202));
	AddTexture(eType::EFFECT_3, new CTexture("Resources/Effect/Effect_3.png", 3, 1, 3, 186, 254, 202));
	AddTexture(eType::EFFECT_4, new CTexture("Resources/Effect/Effect_4.png", 10, 1, 10, 186, 254, 202));

	//Boss
//Boss
	AddTexture(eType::BOSS, new CTexture("Resources/Boss/JafarAttack.png", 10, 4, 40));
	AddTexture(eType::BULLET, new CTexture("Resources/Boss/bullet.png", 3, 1, 3));
	AddTexture(eType::BURN, new CTexture("Resources/Boss/Burn.png", 8, 1, 8));
	AddTexture(eType::BURN_1, new CTexture("Resources/Boss/Burn2.png", 5, 1, 5, 186, 254, 202));
}

TextureManager::TextureManager()
{
	LoadResource();
}


TextureManager::~TextureManager()
{
	SAFE_DELETE(__Instance);
}
