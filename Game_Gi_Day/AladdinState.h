#pragma once
#include"AladdinData.h"
#include <map>
#include "Brick.h"
#include "ObjectHidden.h"

/*PlayerState là 1 lớp trừu tượng dùng cho kế thừa, mỗi State là 1 class nên khi chuyển State ta chỉ việc chuyển con trỏ state trong class Player đến State mới*/
class AladdinState
{
public:
	enum StateName
	{
		Standing,
		StandingAttack,

		Waitting,

		Running,
		Running2,
		RunningAttacking,

		Sitting,
		SittingThrow,
		SittingAttack,

		Jumping,
		Jumping2,
		JumpingForward,
		JumpingThrow,
		JumpingAttack,
		JumpingClimb,

		Climbing,
		ClimbingThow,
		ClimbingAttack,
		Lookup,

		Throw,
		
		Attacking,
		AttackCollision,
		Push,

		Dead,

		BeingAttack,

		Falling,
		Die,

	};

	~AladdinState();

	virtual void Update(float dt, vector<LPGAMEOBJECT> *coObjects = NULL);

	virtual void HandleKeyboard(std::map<int, bool> keys);

	//ham thuan ao bat buoc phai ke thua
	virtual StateName GetState() = 0;
protected:
	AladdinState(AladdinData *aladdinData);
	AladdinState();
	int Direction;
	AladdinData *mAladdinData;
};

