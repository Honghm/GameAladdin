#include"TextureManager.h"
#include"Player.h"
#include"Texture.h"
#include"Sprite.h"
#define ANI_ALADDIN_BEGIN 0
#define ANI_ALADDIN_END 20
class Life
{
public:
	CTexture* texture;
	CSprite* sprite;
	int life;
public:
	void Render();
	void Update(DWORD dt);
	void SetLife(int x);
	Life();
	~Life();

};
