#include"TextureManager.h"
#include"Player.h"
#include"Texture.h"
#include"Sprite.h"
#define REDROCK_ANI_BEGIN 0
#define REDROCK_ANI_END  8
class JewryRock
{
public:
	CTexture* texture;
	CSprite* sprite;
	int jewryrock;
public:
	void Render();
	void Update(DWORD dt);
	void SetJewryRock(int x);
	JewryRock();
	~JewryRock();

};