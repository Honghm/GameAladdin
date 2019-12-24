#include "Font.h"

Font * Font::_instance = NULL;

Font::Font()
{
	texture = TextureManager::GetInstance()->GetTexture(eType::NUMBER);
	sprite = new CSprite(texture, 150);
}


Font::~Font()
{
}

Font * Font::GetInstance()
{
	if (_instance == NULL)
	{
		_instance = new Font();
	}
	return _instance;
}

void Font::Render(float x, float y, const string & s)
{
	for (UINT i = 0; i < s.size(); i++)
	{
		int number = s[i] - '0';
		switch (number)
		{
		case 0:
			sprite->SelectFrame(ANI_NUMBER_0);
			break;
		case 1:
			sprite->SelectFrame(ANI_NUMBER_1);
			break;
		case 2:
			sprite->SelectFrame(ANI_NUMBER_2);
			break;
		case 3:
			sprite->SelectFrame(ANI_NUMBER_3);
			break;
		case 4:
			sprite->SelectFrame(ANI_NUMBER_4);
			break;
		case 5:
			sprite->SelectFrame(ANI_NUMBER_5);
			break;
		case 6:
			sprite->SelectFrame(ANI_NUMBER_6);
			break;
		case 7:
			sprite->SelectFrame(ANI_NUMBER_7);
			break;
		case 8:
			sprite->SelectFrame(ANI_NUMBER_8);
			break;
		case 9:
			sprite->SelectFrame(ANI_NUMBER_9);
			break;

		}
		sprite->Draw(x + 20.0f + i * 8, y);

	}
}

void Font::Set(int left, int top, int right, int bottom)
{
	
}
