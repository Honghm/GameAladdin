#pragma once
#include <d3d9.h>
#include <d3dx9.h>
#include "Camera.h"
#include "Sprite.h"
#include "AladdinData.h"
#include "AladdinState.h"
#include "Brick.h"
#include "ObjectHidden.h"
#include "AladdinRunningState.h"
#include "GameObject.h"
#include "GameTime.h"
#include "Enemy.h"
#include "Weapon.h"
#include "Katana.h"
#include "Apple.h"
#include "Effect.h"
#include "Item.h"
#include "Marble.h"
#include "Thorn.h"
#include "Rock.h"
#include "Boss.h"
class Player:public GameObject
{
	int life;
	int apple;
	int score;
	int jewryrock;
protected:
	AladdinData *mAladdinData;
	
	void changeAnimation(AladdinState::StateName state);
	AladdinState::StateName mCurrentState;
	
	//bool mCurrentReverse;
	
	
public:
	

#pragma region Biến kiểm tra các trạng thái của nhân vật
	bool isUp; 
	bool isAttacking;
	bool isHurting;
	bool isWalking;
	bool isSitting; 
	bool isClimbing; 
	bool isClimbUp; 
	bool isFall;
	bool isLooking;
	bool isStanding;
	bool isPush;
	bool AllowAttack;
	bool AllowPush;
	bool AllowMove;
	bool isCollisionWithBrick;
	bool isCollisionWithBullet;
	bool isCollisionWithBurn;
	bool isCollisionWithEnemy;
	bool isDied;
#pragma endregion

	
	bool isGetNewStage;
	DWORD timeWait;
	int index;
	DWORD TimeStart;
	DWORD TimeNow;
	DWORD Time, lastTimeHurted = 0;
	Camera *camera;
	vector<Effect*> listEffect;
	float B_top;
	float B_bottom;
public:
	int dem = 0;
	list<Weapon*> mWeapon;
	Player(Camera *camera);
	~Player();

	void Update(float dt, vector<LPGAMEOBJECT> *coObjects = NULL);
	void Render(Camera *camera);

	void SetState(AladdinState *newState);
	

	AladdinState::StateName getState();

	void HandleKeyboard(std::map<int, bool> keys);

	void OnKeyPressed(int key);

	void OnKeyUp(int key);
	//void SetReverse(bool flag); //Set lại animation
	int flag = 0;
	void CollisionWithBrick(const vector<LPGAMEOBJECT> *coObjects = NULL);
	
	void Stop();
	void Attack(eType typeWeapon);

	int GetHealth() { return this->Health; }
	void SubHealth() { this->Health--; }
	void AddHealth(int x) { this->Health = this->Health + x; }
	int GetJewryRock() { return this->jewryrock; }
	void AddJewryrock() { this->jewryrock++; }
	int GetApple() { return this->apple; }
	void AddApple() { this->apple++; }
	int GetScore() { return this->score; }
	void AddScore(int x) { this->score = this->score + x; }
	int GetLife() { return this->life; }
	void AddLife() { this->life++; }
	void SubApple() { this->apple--; }
	virtual void GetBoundingBox(float & left, float & top, float & right, float & bottom);
	virtual void GetBoundingBoxBrick(float & left, float & top, float & right, float & bottom);
	void CollisionWithEnemyArea(const vector<LPGAMEOBJECT>* coObjects=NULL);
	void CollisionWeaponWithObj(const vector<LPGAMEOBJECT>* coObjects);
	bool CheckAABBActiveArea(float l, float t, float r, float b);
	void CollisionWithPlatform(const vector<LPGAMEOBJECT>* coObjects);
	void CollisionWithItems(vector<LPGAMEOBJECT>* coObject);
	void CollisiongWithWall(vector<LPGAMEOBJECT>* coObject);
	void CollisiongWithRope(vector<LPGAMEOBJECT>* coObject);
	void ChangeState();
};

