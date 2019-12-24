#include"TextureManager.h"
#include"Player.h"
#include"Texture.h"
#include"Sprite.h"
#define TAO_ANI_BEGIN 0
#define TAO_ANI_END  5
class AppleFont
{
public:
	CTexture* texture;
	CSprite* sprite;
	int applefont;
public:
	void Render();
	void Update(DWORD dt);
	void SetAppleFont(int x);
	AppleFont();
	~AppleFont();

};
