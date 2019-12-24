#ifndef __SCENEGAME_H__
#define __SCENEGAME_H__

#include "Scenes.h"
#include "Camera.h"
#include "Sprite.h"
#include "Camera.h"
#include "Map.h"
#include "GameTime.h"
#include "Texture.h"
#include "Player.h"
#include "Guard.h"
#include "Grid.h"
#include "Item.h"
#include"Board.h"
#define GAME_TIME_MAX 150





#define TIME_FOR_DEATH 4000
class SceneGame : public Scene
{
protected:

private:

	Grid *grid;
	vector<Unit*> listUnit;
	Map * TileMap;
	Camera *camera;
	GameTime * gameTime;
	std::map<int, bool> keys;
	Player *player;
	Board *board;


	int StateCurrent;
	vector<LPGAMEOBJECT> listObj;
	eType mapCurrent;
	int timeFreeze = 5000;
	DWORD timeBeginFreeze;
	
	bool isGameOver;
	DWORD EndTime;
	float remainTime;
	
	CSprite *OtherMap;
	CTexture *texture;

	int count;
public:
	SceneGame();
	~SceneGame();

	void KeyState(BYTE *state);
	void OnKeyDown(int KeyCode);
	void OnKeyUp(int KeyCode);
	void LoadResources();

	void InitGame(eType map = MAP1); // khởi tạo lại như chơi từ đầu
	void ResetResource(); // reset lai resource khi simon mất 1 mạng



	void Update(DWORD dt);
	void UpdateGrid();
	void Render();
	void SetInactiveEnemy();

	void LoadMap(eType);



	void CheckCollision(DWORD dt);
	void CheckCollisonOfAladdin(DWORD dt);
	void CheckDropItem();
	void CollisionWithItems(DWORD dt);

	void ReplayMusicGame(int map);



};
#endif
