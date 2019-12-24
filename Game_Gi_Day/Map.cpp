#include "Map.h"



Map::Map()
{

}


Map::~Map()
{
	SAFE_DELETE(sprite);
}


void Map::LoadMap(eType type)
{
	switch (type)
	{
	case eType::MAP1:
		ReadMapTXT("Resources/TileMap.txt");
		break;
	case eType::MAP2:
		ReadMapTXT("Resources/Boss/Map_Boss.txt");
		break;
	case eType::BACKGROUND:
		ReadMapTXT("Resources/Boss/TileBackground.txt");
		break;
	default:
		break;
	}
	texture = TextureManager::GetInstance()->GetTexture(type);
	sprite = new CSprite(texture, 100); //load toàn bộ tilemap lên

}

/*Đọc vị trí của các tile từ file txt -> lưu vào mảng 2 chiều*/
void Map::ReadMapTXT(const char * filename) 
{
	ifstream inp(filename, ios::in);
	inp >> RowMap >> ColumnMap >> ColumnTile >> RowTile >> TotalTiles >> HeightBoard;
	for (int i = 0; i < RowMap; i++)
		for (int j = 0; j < ColumnMap; j++)
			inp >> TileMap[i][j];
	inp.close();

}

/*Vẽ map lên tương ứng với vùng camera đang focus*/
void Map::DrawMap(Camera *camera, int R, int G, int B)
{
	int row = (int)(camera->GetYCam()) / texture->GetFrameHeight(); //hàng đầu tiền của tile trong vùng camera focus
	int column = (int)(camera->GetXCam()) / texture->GetFrameHeight(); //cột đầu tiên của tile trong vùng camera focus

	float x = -(float)((int)(camera->GetXCam()) % texture->GetFrameHeight()); 
	float y = -(float)((int)(camera->GetYCam()) % texture->GetFrameHeight());

	for (int i = 0; i < SCREEN_HEIGHT / texture->GetFrameHeight() + 1; i++)
		for (int j = 0; j < SCREEN_WIDTH / texture->GetFrameWidth() + 1; j++)
		{
			if (!(row + i < 0 || row + i >= RowMap || j + column < 0 || j + column > ColumnMap))
				sprite->DrawFrame(TileMap[row + i][column + j], x + texture->GetFrameWidth()*j, y + texture->GetFrameHeight()*i + HeightBoard, 255, R, G, B);
		}
	
}

int Map::GetMapWidth()
{
	return ColumnMap * texture->GetFrameWidth();
}

int Map::GetMapHeight()
{
	return RowMap * texture->GetFrameHeight();
}
