#include "Player.h"
#include "AladdinJumpingState.h"
#include "AladdinStandingState.h"
#include "AladdinRunningState.h"
#include"AladdinStandingAttackState.h"
#include"AladdinSitting.h"
#include"AladdinAttackingState.h"
#include"AladdinBeingAttackState.h"
#include"AladdinDeadState.h"
#include"AladdinJumping2State.h"
#include"AladdinJumpingAttackState.h"
#include"AladdinJumpingClimbState.h"
#include"AladdinJumpingForward.h"
#include"AladdinJumpingThrowState.h"
#include"AladdinLookUpState.h"
#include"AladdinPushState.h"
#include"AladdinRunning2State.h"
#include"AladdinSittingAttackState.h"
#include"AladdinSittingThrowState.h"
#include"AladdinWaitting_1.h"
#include"AladdinThrowState.h"
#include "AladdinClimbingState.h"
#include "AladdinRunningAttackingState.h"
#include "TextureManager.h"
#include "AladdinClimbingAttackingState.h"
#include "AladdinClimbingThowingState.h"
#include "AladdinAttackCollision.h"
#include "AladdinFallingState.h"
#include "Debug.h"
#include "Guard.h"
#include "Soldier.h"
#include "Bat.h"
Player::Player(Camera * camera)
{
	this->Health = 8;
	this->apple = 50;
	this->jewryrock = 99;
	this->life = 7;
	texture = TextureManager::GetInstance()->GetTexture(eType::ALADDIN);
	sprite = new CSprite(texture, 100);
	this->mAladdinData = new AladdinData();
	this->mAladdinData->player = this;
	this->vx = 0;
	this->vy = 0;
	this->camera = camera;
	timeWait = GetTickCount();
	BackupX = x;
	backupY = y;
	direction = 1;
	isWalking = 0;
	//isJumping = true;
	isGetNewStage = false;
	isFall = false;
	isClimbing = false;
	isClimbUp = false;
	isSitting = false;
	isLooking = false;
	isStanding = true;
	//isJumpForward = false;
	isPush = false;
	AllowAttack = true;
	isHurting = false;
	AllowPush = false;
	AllowMove = true;
	isCollisionWithBrick = false;
	isCollisionWithBullet = false;
	isCollisionWithBurn = false;
	isCollisionWithEnemy = false;
	isRestart = false;
	this->SetState(new AladdinFallingState(this->mAladdinData));	
}

Player::~Player()
{
}

void Player::Update(float dt, vector<LPGAMEOBJECT> *coObjects)
{
	if (this->Health >= 0)
	{
		isRestart = isSetState = false;
		dem2 = 0;
		float l, r, t, b;
		if (GetX() < camera->GetBoundaryLeft() - 10)
		{
			x = camera->GetBoundaryLeft() - 10;
		}
		if (GetX() > camera->GetBoundaryRight() + SCREEN_WIDTH - 400) //Set lại tọa độ khi aladdin vượt quá biên bên phải
			x = (float)(camera->GetBoundaryRight() + SCREEN_WIDTH - 400);

		index = sprite->GetCurrentFrame();
		GetBoundingBox(l, t, r, b);
		if (this->mAladdinData->state)
		{
			this->mAladdinData->state->Update(dt, coObjects);
		}
		if (mCurrentState != AladdinState::Lookup && mCurrentState != AladdinState::Sitting)
			camera->SetPosition(x - SCREEN_WIDTH / 4 + 80, y + (SCREEN_HEIGHT / 4) - 150);
		
		
		if (timehurt == 0)
		{
			CollisionWithEnemyArea(coObjects);
			CollisionWithPlatform(coObjects);
		}
		else
			timehurt--;
		CollisionWithItems(coObjects);
		CollisionWeaponWithObj(coObjects);
		CollisiongWithWall(coObjects);
		CollisionWithBrick(coObjects);
		CollisiongWithRope(coObjects);
		for (auto obj : mWeapon)
		{
			if (obj->GetFinish() == false)
			{
				obj->Update(dt, coObjects);
			}
		}
		for (auto obj : listEffect)
		{
			if (!dynamic_cast<Effect*>(obj)->IsFinish())
				obj->Update(dt);
		}
	}
	else
	{
		isRestart = true;
		vy = 0;
		SceneManager::GetInstance()->SetPlayerState(-1);
		if (!isSetState)
		{
			this->SetState(new AladdinDeadState(this->mAladdinData));
			isSetState = true;
		}
		dem2++;
		if (dem2 >= 100) {
			SceneManager::GetInstance()->SetPlayerState(1);
			this->Health = 8;
			this->life--;
			this->SetState(new AladdinStandingState(this->mAladdinData));
		}
	}
}

//set frame bắt đầu tương ứng từng animation
void Player::changeAnimation(AladdinState::StateName state)
{
	switch (state)
	{
	case AladdinState::Running:
		sprite->SelectFrame(ALADDIN_ANI_WALKING_BEGIN);
		break;
	case AladdinState::Standing:
		sprite->SelectFrame(ALADDIN_ANI_IDLE);
		break;
	case AladdinState::Jumping:
		sprite->SelectFrame(ALADDIN_ANI_JUMPING_BEGIN);
		break;
	case AladdinState::Climbing:
		sprite->SelectFrame(ALADDIN_ANI_CLIMBING_BEGIN);
		break;
		case AladdinState::Waitting:
		sprite->SelectFrame(ALADDIN_ANI_WAITTING_1_BEGIN);
		break;
	case AladdinState::Sitting:
		sprite->SelectFrame(ALADDIN_ANI_SITTING_BEGIN);
		break;
	case AladdinState::Attacking:
		sprite->SelectFrame(ALADDIN_ANI_ATTACKING_BEGIN);
		break;
	case AladdinState::StandingAttack:
		sprite->SelectFrame(ALADDIN_ANI_STANDINGATTACK_BEGIN);
		break;
	case AladdinState::BeingAttack:
		sprite->SelectFrame(ALADDIN_ANI_BEINGATTACKED_BEGIN);
		break;
	case AladdinState::Dead:
		sprite->SelectFrame(ALADDIN_ANI_DEAD_BEGIN);
		break;
	case AladdinState::Jumping2:
		sprite->SelectFrame(ALADDIN_ANI_JUMPING_2_BEGIN);
		break;
	case AladdinState::JumpingAttack:
		sprite->SelectFrame(ALADDIN_ANI_JUMPINGATTACK_BEGIN);
		break;
	case AladdinState::JumpingClimb:
		sprite->SelectFrame(ALADDIN_ANI_JUMPINGCLIMB_BEGIN);
		break;
	case AladdinState::JumpingForward:
		sprite->SelectFrame(ALADDIN_ANI_JUMPINGFORWARD_BEGIN);
		break;
	case AladdinState::JumpingThrow:
		sprite->SelectFrame(ALADDIN_ANI_JUMPINGTHROW_BEGIN);
		break;
	case AladdinState::Lookup:
		sprite->SelectFrame(ALADDIN_ANI_LOOKUP_BEGIN);
		break;
	case AladdinState::Push:
		sprite->SelectFrame(ALADDIN_ANI_PUSH_BEGIN);
		break;
	case AladdinState::Running2:
		sprite->SelectFrame(ALADDIN_ANI_RUNNING2_BEGIN);
		break;
	case AladdinState::SittingAttack:
		sprite->SelectFrame(ALADDIN_ANI_SITTINGATTACK_BEGIN);
		break;
	case AladdinState::SittingThrow:
		sprite->SelectFrame(ALADDIN_ANI_SITTINGTHROW_BEGIN);
		break;
	case AladdinState::Throw:
		sprite->SelectFrame(ALADDIN_ANI_THROWSTANDING_BEGIN);
		break;
	case AladdinState::RunningAttacking:
		sprite->SelectFrame(ALADDIN_ANI_WALKINGATTACKING_BEGIN);
		break;
	case AladdinState::ClimbingThow:
		sprite->SelectFrame(ALADDIN_ANI_CLIMBINGTHOW_BEGIN);
		break;
	case AladdinState::ClimbingAttack:
		sprite->SelectFrame(ALADDIN_ANI_CLIMBINGATTACK_BEGIN);
		break;
	case AladdinState::AttackCollision:
		sprite->SelectFrame(ALADDIN_ANI_ATTACKCOLLISION_BEGIN);
		break;
	case AladdinState::Falling:
		sprite->SelectFrame(22);
		break;
	}

}

void Player::Render(Camera * camera)
{
	D3DXVECTOR2 pos = camera->Transform(GetX(), GetY());

	int alpha = 255;
	for (auto obj : mWeapon)
	{
		if (obj->GetFinish() == false)
			obj->Render(camera);
	}
	if(GetDirection() == 1)
		sprite->Draw(pos.x, pos.y, alpha);
	else
		sprite->DrawFlipX(pos.x, pos.y, alpha);
	this->RenderBoundingBox(camera);

	for (auto obj : listEffect)
	{
		if (!dynamic_cast<Effect*>(obj)->IsFinish())
			obj->Render(camera);
	}
	
}

void Player::SetState(AladdinState * newState)
{
	delete this->mAladdinData->state;

	this->mAladdinData->state = newState;

	this->changeAnimation(newState->GetState());

	mCurrentState = newState->GetState();
}

AladdinState::StateName Player::getState() //lấy state hiện tại
{
	return mCurrentState;
}

void Player::HandleKeyboard(std::map<int, bool> keys)
{
	if (this->mAladdinData->state)
	{
		this->mAladdinData->state->HandleKeyboard(keys);
	}
}

void Player::OnKeyPressed(int key) 
{
	if (key == DIK_Z) //Nhảy
	{  
		if (isCollisionWithBrick)
		{
			if (mCurrentState == AladdinState::Waitting || mCurrentState == AladdinState::Standing) //đang ở trạng thái chờ thì cho phép nhảy
			{
				this->SetState(new AladdinJumpingState(this->mAladdinData));
			}
			else if (mCurrentState == AladdinState::Running) //đang đi mà nhảy thì nhảy dài
				this->SetState(new AladdinJumpingForward(this->mAladdinData));
			isCollisionWithBrick = false;
		}
		if (mCurrentState == AladdinState::Climbing) //đang ở trạng thái leo thì nhảy lên và thoát khỏi trạng thái leo
			this->SetState(new AladdinJumpingClimbState(this->mAladdinData));
	}
	
	if (key == DIK_UP)
	{
		if(mCurrentState==AladdinState::Climbing || isClimbUp == true) //đang ở trạng thái leo thì cho leo lên
			this->SetState(new AladdinClimbingState(this->mAladdinData));
		else if(mCurrentState==AladdinState::Waitting|| mCurrentState == AladdinState::Standing) //đang ở trạng thái chờ thì chuyển sang trạng thái nhìn lên
			this->SetState(new AladdinLookUpState(this->mAladdinData));
	}
		
	if (key == DIK_DOWN)
	{
		if (mCurrentState == AladdinState::Waitting|| mCurrentState == AladdinState::Standing)//đang ở trạng thái chờ thì cho ngồi xuống
			this->SetState(new AladdinSitting(this->mAladdinData));
		else if (mCurrentState == AladdinState::Climbing||isClimbUp==true)//đang ở trạng thái leo thì cho leo xuống
			this->SetState(new AladdinClimbingState(this->mAladdinData));
		else
			this->SetState(new AladdinStandingState(this->mAladdinData));
	}

	if (key == DIK_W)
	{
		this->SetState(new AladdinDeadState(this->mAladdinData));
	}

	if (key == DIK_X) //trạng thái ném
	{
		if (mCurrentState == AladdinState::JumpingForward||mCurrentState==AladdinState::Jumping) //đang nhảy thì chuyển sang trạng thái nhảy ném
			this->SetState(new AladdinJumpingThrowState(this->mAladdinData));

		else if (mCurrentState == AladdinState::Sitting || mCurrentState == AladdinState::SittingThrow|| mCurrentState == AladdinState::SittingAttack) //chuyển sang trạng thái ngồi ném
			this->SetState(new AladdinSittingThrowState(this->mAladdinData));

		else if(mCurrentState==AladdinState::Running||mCurrentState==AladdinState::Waitting|| mCurrentState == AladdinState::Standing) //chuyển sang trạng thái đứng ném
			this->SetState(new AladdinThrowState(this->mAladdinData));

		else if (mCurrentState == AladdinState::Climbing)
			this->SetState(new AladdinClimbingThowingState(this->mAladdinData));
	}
	
	if (key == DIK_C)
	{
		if (mCurrentState == AladdinState::JumpingForward|| mCurrentState == AladdinState::Jumping)//chuyển sang trạng thái nhảy đánh
			this->SetState(new AladdinJumpingAttackState(this->mAladdinData));
		else if (mCurrentState == AladdinState::Sitting || mCurrentState == AladdinState::SittingAttack || mCurrentState == AladdinState::SittingThrow)//chuyển sang trạng thái ngồi đánh
			this->SetState(new AladdinSittingAttackState(this->mAladdinData));
		else if (mCurrentState == AladdinState::Standing || mCurrentState == AladdinState::Waitting || mCurrentState == AladdinState::BeingAttack)//chuyển sang trạng thái đứng đánh
			this->SetState(new AladdinAttackingState(this->mAladdinData));

		else if (mCurrentState == AladdinState::Running)
		{
			if (AllowAttack == true)
				this->SetState(new AladdinRunningAttackingState(this->mAladdinData));
		}
		else if (mCurrentState == AladdinState::Climbing)
			this->SetState(new AladdinClimbingAttackingState(this->mAladdinData));
	}
	
	if (key == DIK_RIGHT)
	{
		isWalking = true;
		TimeStart = GetTickCount();
		if (mCurrentState == AladdinState::Standing || mCurrentState == AladdinState::Waitting || mCurrentState == AladdinState::BeingAttack)
		{
			SetDirection(1);
			this->SetState(new AladdinRunningState(this->mAladdinData));
		}
		if (mCurrentState == AladdinState::JumpingForward)
		{
			return;
		}
	}

	if (key == DIK_LEFT)
	{
		isWalking = true;
		TimeStart = GetTickCount();
		if (mCurrentState == AladdinState::Standing || mCurrentState == AladdinState::Waitting||mCurrentState == AladdinState::BeingAttack)
		{
			SetDirection(-1);
			this->SetState(new AladdinRunningState(this->mAladdinData));
		}
		if (mCurrentState == AladdinState::JumpingForward)
		{
			return;
		}
	}
}

void Player::OnKeyUp(int key)//tra ve su kien khi tha phim
{
	
	if (key == DIK_UP)
	{
		isLooking = false;
	}

	if (key == DIK_DOWN)
	{
		isSitting = false;
	}
	if(mCurrentState==AladdinState::Running)
		if (key == DIK_RIGHT||key==DIK_LEFT)
		{
			TimeNow = GetTickCount();
			Time = TimeNow - TimeStart;
			
			/*nếu từ lúc nhấn phím tới lúc thả phím quá 3s thì chuyển sang trạng thái dừng gấp*/
			if (Time > 3000)
				this->SetState(new AladdinRunning2State(this->mAladdinData));
			else
				this->SetState(new AladdinStandingState(this->mAladdinData));
		}
	if (mCurrentState == AladdinState::Push)
		if (key == DIK_RIGHT || key == DIK_LEFT)
		{
			this->SetState(new AladdinStandingState(this->mAladdinData));
		}
	if (key == DIK_C)
		AllowAttack = true;
}

void Player::Stop()
{
	vx = 0;
	vy = 0;
	isWalking = false;
}

void Player::Attack(eType typeWeapon)
{
	if (isAttacking)
		return;
	switch (typeWeapon)
	{
	case eType::KATANA:
		if (mWeapon.front()->GetFinish()) // vũ khí đã kết thúc thì mới đc tấn công tiếp
		{
			isAttacking = true; // set trang thái tấn công
			sprite->ResetTime();
			if(mCurrentState==AladdinState::Attacking)
				mWeapon.back()->Attack(x, y, this->direction, 1); // set vị trí weapon theo Aladdin
			else if(mCurrentState==AladdinState::SittingAttack)
				mWeapon.back()->Attack(x, y, this->direction, 2); // set vị trí weapon theo Aladdin
			else if(mCurrentState==AladdinState::JumpingAttack)
				mWeapon.back()->Attack(x, y, this->direction, 3);
			else if(mCurrentState == AladdinState::RunningAttacking)
				mWeapon.back()->Attack(x, y, this->direction, 4);
			else if (mCurrentState == AladdinState::ClimbingAttack)
			{
				mWeapon.back()->Attack(x, y, -this->direction, 5);
			}
			mWeapon.back()->isAttacked = true;
		}
		break;
	case eType::APPLE:
		if (mWeapon.front()->GetFinish()) // vũ khí đã kết thúc thì mới đc tấn công tiếp
		{
			if (GetApple() == 0)
				break;
			SubApple();
			isAttacking = true; // set trang thái tấn công
			sprite->ResetTime();
			mWeapon.back()->SetSpeed(0.25f * direction, 0);
			if(mCurrentState==AladdinState::Throw)
				mWeapon.back()->Attack(x, y, this->direction, 1);
			else if (mCurrentState == AladdinState::SittingThrow)
				mWeapon.back()->Attack(x, y, this->direction, 2);
			else if (mCurrentState == AladdinState::JumpingThrow)
			{
				if(this->vx==0)
					mWeapon.back()->SetSpeed(0.25f * direction, 0);
				else
					mWeapon.back()->SetSpeed(0.4f * direction, 0);
				mWeapon.back()->Attack(x, y, this->direction, 3);
			}
			else if (mCurrentState == AladdinState::ClimbingThow)
			{
				mWeapon.back()->SetSpeed(-0.25f * direction, 0);
				mWeapon.back()->Attack(x, y, -this->direction, 4);
			}
			mWeapon.back()->isAttacked = true;
		}
		break;
	default:
		break;
	}
}

void Player::GetBoundingBox(float & left, float & top, float & right, float & bottom) //set BBOX để xét va chạm
{
	if (direction == 1)
	{
		left = x + 40;
		top = y + 30;
		right = x + ALADDIN_BBOX_WIDTH - 38;
		bottom = y + ALADDIN_BBOX_HEIGHT - 20;
		if (mCurrentState==AladdinState::Jumping)
		{
			top = y + 23;
			bottom = y + ALADDIN_BBOX_HEIGHT - 12;
		}
		if (isWalking == true)
		{
			left = x + 35;
			top = y + 25;
			bottom = y + ALADDIN_BBOX_HEIGHT - 20;
		}
		if (mCurrentState == AladdinState::JumpingForward)
		{
			left = x + 30;
			top = y + 30;
			right = x + ALADDIN_BBOX_WIDTH - 33;
			bottom = y + ALADDIN_BBOX_HEIGHT - 20;
		}
		if (isSitting == true)
		{
			left = x + 38;
			top = y + 48;
			right = x + ALADDIN_BBOX_WIDTH - 30;
			bottom = y + ALADDIN_BBOX_HEIGHT - 20;
		}
		if (isClimbUp || isClimbing)
		{
			left = x + 47.5;
			top = y + 20;
			right = x + ALADDIN_BBOX_WIDTH - 47.5;
			bottom = y + ALADDIN_BBOX_HEIGHT - 20;
		}
		if (isPush == true)
		{
			left = x + 30;
			top = y + 40;
			right = x + ALADDIN_BBOX_WIDTH - 20;
			bottom = y + ALADDIN_BBOX_HEIGHT - 20;
		}
		
	}
	else
	{
		left = x + 38;
		top = y + 30;
		right = x + ALADDIN_BBOX_WIDTH - 40;
		bottom = y + ALADDIN_BBOX_HEIGHT - 20;
		if (mCurrentState == AladdinState::Jumping)
		{
			top = y + 23;
			bottom = y + ALADDIN_BBOX_HEIGHT - 12;
		}
		if (isWalking == true)
		{
			right = x + ALADDIN_BBOX_WIDTH - 32;
			top = y + 25;
			bottom = y + ALADDIN_BBOX_HEIGHT - 20;
		}
		if (mCurrentState == AladdinState::JumpingForward)
		{
			left = x + 33;
			top = y + 30;
			right = x + ALADDIN_BBOX_WIDTH - 30;
			bottom = y + ALADDIN_BBOX_HEIGHT - 20;
		}
		if (isSitting == true)
		{
			left = x + 32;
			top = y + 48;
			right = x + ALADDIN_BBOX_WIDTH - 38;
			bottom = y + ALADDIN_BBOX_HEIGHT - 20;
		}
		if (isPush == true)
		{
			left = x + 40;
			top = y + 40;
			right = x + ALADDIN_BBOX_WIDTH;
			bottom = y + ALADDIN_BBOX_HEIGHT - 20;
		}
		if (isClimbUp|| isClimbing)
		{
			left = x + 47.5;
			top = y+20;
			right = x + ALADDIN_BBOX_WIDTH - 47.5;
			bottom = y + ALADDIN_BBOX_HEIGHT-20;
		}
	
	}
}

void Player::GetBoundingBoxBrick(float & left, float & top, float & right, float & bottom) //set BBOX khi va chạm với brick
{
	if (direction == 1)
	{
		left = x + 40;
		top = y + 30;
		right = x + ALADDIN_BBOX_WIDTH - 38;
		bottom = y + ALADDIN_BBOX_HEIGHT - 20;
		if (mCurrentState == AladdinState::Jumping)
		{
			top = y + 23;
			bottom = y + ALADDIN_BBOX_HEIGHT - 12;
		}
		if (isWalking == true)
		{
			left = x + 35;
			top = y + 25;
			bottom = y + ALADDIN_BBOX_HEIGHT - 20;
		}
		if (mCurrentState == AladdinState::JumpingForward)
		{
			left = x + 30;
			top = y + 30;
			right = x + ALADDIN_BBOX_WIDTH - 33;
			bottom = y + ALADDIN_BBOX_HEIGHT - 20;
		}
		if (isSitting == true)
		{
			left = x + 38;
			top = y + 48;
			right = x + ALADDIN_BBOX_WIDTH - 30;
			bottom = y + ALADDIN_BBOX_HEIGHT - 20;
		}
		if (isClimbUp || isClimbing)
		{
			left = x + 47.5;
			top = y + 20;
			right = x + ALADDIN_BBOX_WIDTH - 47.5;
			bottom = y + ALADDIN_BBOX_HEIGHT - 20;
		}
		if (isPush == true)
		{
			left = x + 30;
			top = y + 40;
			right = x + ALADDIN_BBOX_WIDTH - 20;
			bottom = y + ALADDIN_BBOX_HEIGHT - 20;
		}

	}
	else
	{
		left = x + 38;
		top = y + 30;
		right = x + ALADDIN_BBOX_WIDTH - 40;
		bottom = y + ALADDIN_BBOX_HEIGHT - 20;
		if (mCurrentState == AladdinState::Jumping)
		{
			top = y + 23;
			bottom = y + ALADDIN_BBOX_HEIGHT - 12;
		}
		if (isWalking == true)
		{
			right = x + ALADDIN_BBOX_WIDTH - 32;
			top = y + 25;
			bottom = y + ALADDIN_BBOX_HEIGHT - 20;
		}
		if (mCurrentState == AladdinState::JumpingForward)
		{
			left = x + 33;
			top = y + 30;
			right = x + ALADDIN_BBOX_WIDTH - 30;
			bottom = y + ALADDIN_BBOX_HEIGHT - 20;
		}
		if (isSitting == true)
		{
			left = x + 32;
			top = y + 48;
			right = x + ALADDIN_BBOX_WIDTH - 38;
			bottom = y + ALADDIN_BBOX_HEIGHT - 20;
		}
		if (isPush == true)
		{
			left = x + 40;
			top = y + 40;
			right = x + ALADDIN_BBOX_WIDTH;
			bottom = y + ALADDIN_BBOX_HEIGHT - 20;
		}
		if (isClimbUp || isClimbing)
		{
			left = x + 47.5;
			top = y + 20;
			right = x + ALADDIN_BBOX_WIDTH - 47.5;
			bottom = y + ALADDIN_BBOX_HEIGHT - 20;
		}

	}
}

void Player::CollisionWithEnemyArea(const vector<LPGAMEOBJECT>* coObject)
{
	vector<LPCOLLISIONEVENT> coEvents;
	vector<LPCOLLISIONEVENT> coEventsResult;
	
	coEvents.clear();

	vector<LPGAMEOBJECT> listEnemy;
	listEnemy.clear();
	for (UINT i = 0; i < coObject->size(); i++)
	{
		LPGAMEOBJECT cO = coObject->at(i);
		if ((cO->GetType() == eType::BAT || cO->GetType() == GUARD || cO->GetType() == SOLDIER || cO->GetType() == GHOST)
			&& cO->GetHealth() != 0)
			listEnemy.push_back(coObject->at(i));
	}

	CalcPotentialCollisions(&listEnemy, coEvents, flag);
	//if (coEvents.size() == 0)
	//{
	//	/*for (UINT i = 0; i < listEnemy.size(); i++)
	//	{
	//		LPGAMEOBJECT e = listEnemy.at(i);
	//		if (checkAABB(e) && e->GetHealth() != 0)
	//		{
	//			y -= 0.5;
	//			isCollisionWithEnemy = true;
	//			vx = 0;
	//			SubHealth();
	//			if (mCurrentState == AladdinState::Climbing || mCurrentState == AladdinState::ClimbingAttack || mCurrentState == AladdinState::ClimbingThow)
	//			{
	//				Sound::GetInstance()->Play(eSound::sound_AladdinHurt);
	//				this->SetState(new AladdinClimbingState(this->mAladdinData));
	//			}
	//			else
	//				this->SetState(new AladdinBeingAttackState(this->mAladdinData));
	//			timehurt = 30;
	//		}
	//	}*/
	//}
	if (coEvents.size() != 0)
	{
		float min_tx, min_ty, nx = 0, ny;
		FilterCollision(coEvents, coEventsResult, min_tx, min_ty, nx, ny);
		for (UINT i = 0; i < coEventsResult.size(); i++)
		{
			vx = 0;
			vy = 0;
			isCollisionWithEnemy = true;
			LPCOLLISIONEVENT e = coEventsResult[i];
			LPGAMEOBJECT enemy = e->obj;
			SubHealth();
			if (mCurrentState == AladdinState::Climbing || mCurrentState == AladdinState::ClimbingAttack || mCurrentState == AladdinState::ClimbingThow)
			{
				Sound::GetInstance()->Play(eSound::sound_AladdinHurt);
				this->SetState(new AladdinClimbingState(this->mAladdinData));
			}
			else
				this->SetState(new AladdinBeingAttackState(this->mAladdinData));
			timehurt = 30;
		}
	}
}

void Player::CollisionWeaponWithObj(const vector<LPGAMEOBJECT> *coObjects) //xét va chạm của vũ khí với các obj
{
	vector<LPGAMEOBJECT> coEnemys;
	vector<LPGAMEOBJECT> coBricks;
	vector<LPGAMEOBJECT> coItems;
	vector<LPGAMEOBJECT> coPushs;

	//lấy danh sách các enemy
	for (UINT i = 0; i < coObjects->size(); i++)
	{
		if (dynamic_cast<Enemy*>(coObjects->at(i)))
		{
			if (dynamic_cast<Enemy*>(coObjects->at(i))->GetStatus() == ACTIVE)
				coEnemys.push_back(coObjects->at(i));
		}
	}

	//lấy danh sách các brick
	for (UINT i = 0; i < coObjects->size(); i++)
	{
		if (dynamic_cast<Brick*>(coObjects->at(i)))
		{
			coBricks.push_back(coObjects->at(i));
		}
	}

	for (UINT i = 0; i < coObjects->size(); i++)
	{
		if (dynamic_cast<ObjectHidden*>(coObjects->at(i)))
		{
			if (coObjects->at(i)->GetType() == OBJECT_PUSH)
				coPushs.push_back(coObjects->at(i));
		}
	}

	//lấy danh sách các item
	for (UINT i = 0; i < coObjects->size(); i++)
	{
		if (dynamic_cast<Item*>(coObjects->at(i)))
		{
			coItems.push_back(coObjects->at(i));
		}
	}
	for (auto weapon : mWeapon)
	{
		if (weapon->GetFinish() == false)
		{
			//Xét va chạm của vũ khí với quái
			for (UINT i = 0; i < coEnemys.size(); i++)
			{
				if (weapon->GetLastTimeAttack() > weapon->GetLastTimeAttacked()) // tránh trường hợp xét quá nhiều lần attack
				{
					if (weapon->ableCollision(coEnemys.at(i)) == true)
					{
						GameObject *obj = coEnemys.at(i);
						switch (obj->GetType())
						{
						case eType::GUARD:
						{
							if (dynamic_cast<Guard*>(obj)->GetIsAttacking() == true)
							{
								dynamic_cast<Guard*>(obj)->sprite->SelectFrame(26);
								weapon->SetFinish(true);
								this->SetState(new AladdinAttackCollision(this->mAladdinData));
								Sound::GetInstance()->Play(eSound::sound_GuardHit);
								return;
							}
							else
							{
								listEffect.push_back(new Effect(obj->GetX(), obj->GetY(), eType::GUARD, 1));
								dynamic_cast<Guard*>(obj)->SetStatus(1);
								if (weapon->GetType() == APPLE)
								{
									weapon->SetFinish(true);
									Sound::GetInstance()->Play(eSound::sound_GuardPant);
								}
							}

							break;
						}
						case eType::SOLDIER:
						{
							listEffect.push_back(new Effect(obj->GetX(), obj->GetY(), eType::SOLDIER, 1));
							dynamic_cast<Soldier*>(obj)->SetStatus(1);
							if (weapon->GetType() == APPLE)
							{
								weapon->SetFinish(true);
								Sound::GetInstance()->Play(eSound::sound_Iiee);
							}
							break;
						}
						case eType::BAT:
						{
							listEffect.push_back(new Effect(obj->GetX(), obj->GetY(), eType::BAT, 1));
							dynamic_cast<Bat*>(obj)->SetStatus(1);
							if (weapon->GetType() == APPLE)
								weapon->SetFinish(true);
							break;
						}
						case eType::BOSS:
						{
							
							int a = dynamic_cast<Boss*>(obj)->GetHealth();
							if (weapon->GetType() == APPLE)
							{
								if(a<=0)
									listEffect.push_back(new Effect(obj->GetX(), obj->GetY(), 0, 4));
								else
									listEffect.push_back(new Effect(obj->GetX(), obj->GetY(), eType::BOSS, 2));
									
								dynamic_cast<Boss*>(obj)->SetHealth(a - 1);
								weapon->SetFinish(true);
								if (a <= 10)
									dynamic_cast<Boss*>(obj)->SetState(2);
							}
						}
						default:
							break;
						}
						obj->SetLastTimeAttacked(weapon->GetLastTimeAttack());
					}
				}
			}
			
			//Xét va chạm của quả táo với brick
			for (UINT i = 0; i < coBricks.size(); i++)
			{
				if (weapon->GetType() == APPLE)
				{
					if (weapon->CollisionWithBrick(&coBricks) == true)
					{
						Sound::GetInstance()->Play(eSound::sound_AppleSplat);
						listEffect.push_back(new Effect(weapon->x, weapon->y - 10, eType::BRICK, 1)); //hiệu ứng nổ
						weapon->SetFinish(true);
					}
				}
			}

			//Xét va chạm của vũ khí với item
			for (UINT i = 0; i < coItems.size(); i++)
			{
				if (weapon->GetType() == KATANA)
				{
					if (weapon->ableCollision(coItems.at(i)) == true)
					{
						GameObject *objItem = coItems.at(i);
						if (dynamic_cast<Item*>(objItem)->GetFinish() == true||objItem->GetHealth()==0)
							return;
						dynamic_cast<Item*>(objItem)->SetFinish(true);
						if(objItem->GetType()==eType::TAO)
							AddApple();
					}
				}
			}

			//Xét va chạm của cục đá với tường
			for (UINT i = 0; i < coPushs.size(); i++)
			{
				if (weapon->GetType() == KATANA)
				{
					if (weapon->ableCollision(coPushs.at(i)) == true)
					{
						if(mCurrentState==AladdinState::ClimbingAttack)
							this->SetState(new AladdinClimbingState(this->mAladdinData));
						else
							this->SetState(new AladdinAttackCollision(this->mAladdinData));
						weapon->SetFinish(true);
					}
				}
			}
		}
	}
}

bool Player::CheckAABBActiveArea(float l, float t, float r, float b) // kiem tra va cham trong vung active cua enemy bang AABB
{
	float player_l, player_t, player_r, player_b;
	this->GetBoundingBox(player_l, player_t, player_r, player_b);

	if (Game::GetInstance()->checkAABB(player_l, player_t, player_r, player_b, l, t, r, b))
		return true;

	return false;
}

void Player::CollisionWithPlatform(const vector<LPGAMEOBJECT>* coObjects)
{
	vector<LPGAMEOBJECT> coMarble;
	vector<LPGAMEOBJECT> coThorn;
	vector<LPGAMEOBJECT> coRock;
	vector<LPGAMEOBJECT> coPush;

	//lấy danh sách các Marble
	for (UINT i = 0; i < coObjects->size(); i++)
	{
		if (dynamic_cast<Marble*>(coObjects->at(i))) 
		{
			coMarble.push_back(coObjects->at(i));
		}
	}

	//lấy danh sách các Thorn
	for (UINT i = 0; i < coObjects->size(); i++)
	{
		if (dynamic_cast<Thorn*>(coObjects->at(i))) 
		{
			coThorn.push_back(coObjects->at(i));
		}
	}

	//lấy danh sách các Rock
	for (UINT i = 0; i < coObjects->size(); i++)
	{
		if (dynamic_cast<Rock*>(coObjects->at(i))) 
		{
			coRock.push_back(coObjects->at(i));
		}
	}

	

	//xét va chạm của aladdin với các platform
	for (UINT i = 0; i < coMarble.size(); i++)
	{
		GameObject *obj = coMarble.at(i);
		if (obj->isCollitionObjectWithObject(this))
		{
			if (isHurting == false)
			{
				if (obj->isEnable == true)
				{
					vx = 0;
					vy = 0;
					SubHealth();
					y -= 0.5;
					this->SetState(new AladdinBeingAttackState(this->mAladdinData));
					timehurt = 30;
				}
			}
		}
	}

	for (UINT i = 0; i < coThorn.size(); i++)
	{
		GameObject *obj = coThorn.at(i);
		if (obj->isCollitionObjectWithObject(this))
		{
			if (isHurting == false)
			{
				if (obj->isEnable == true)
				{
					vx = 0;
					vy = 0;
					SubHealth();
					y -= 0.5;
					this->SetState(new AladdinBeingAttackState(this->mAladdinData));
					timehurt = 30;
				}
			}
		}
	}
}

void Player::CollisionWithItems(vector<LPGAMEOBJECT>* coObject)
{
	float rX, rY;
	vector<LPGAMEOBJECT> listItems;
	listItems.clear();
	for (int i = 0; i < coObject->size(); i++)
		if (coObject->at(i)->GetType() == eType::TAO || coObject->at(i)->GetType() == eType::REDROCK || coObject->at(i)->GetType() == eType::GENIE ||
			coObject->at(i)->GetType() == eType::HEART || coObject->at(i)->GetType() == eType::RESTARTPOINT)
			if (coObject->at(i)->GetHealth() != 0)
				listItems.push_back(coObject->at(i));

	vector<LPCOLLISIONEVENT> coEvents;
	vector<LPCOLLISIONEVENT> coEventsResult;

	coEvents.clear();
	coEventsResult.clear();

	CalcPotentialCollisions(&listItems, coEvents,flag);

	if (coEvents.size() == 0)//khong co xay ra va cham
	{
		for (int i = 0; i < listItems.size(); i++)
		{
			LPGAMEOBJECT e = listItems.at(i);
			if (checkAABB(e) && e->GetHealth() != 0)
			{
				e->SubHealth(1);
				if (e->GetType() == eType::TAO)
					AddApple();
				else if (e->GetType() == eType::HEART)
				{
					AddHealth(3);
					if (GetHealth() >= 8)
						SetHealth(8);
				}
				else if (e->GetType() == eType::GENIE)
				{
					AddScore(250);
					Sound::GetInstance()->Play(eSound::sound_Wow);
				}
				else if (e->GetType() == eType::REDROCK)
				{
					AddJewryrock();
				}
				else if (e->GetType() == eType::RESTARTPOINT)
				{
					e->GetPosition(rX, rY);
					restartPoint.x = rX;
					restartPoint.y = rY - 50;
					Sound::GetInstance()->Play(eSound::sound_ContinuePoint);
				}
			}
		}
	}
	else
	{
		float min_tx, min_ty, nx = 0, ny;
		FilterCollision(coEvents, coEventsResult, min_tx, min_ty, nx, ny);
		for (UINT i = 0; i < coEventsResult.size(); i++)
		{
			LPCOLLISIONEVENT e = coEventsResult[i];
			LPGAMEOBJECT item = e->obj;
			item->SubHealth(1);
			if (item->GetType() == eType::HEART)
			{
				AddHealth(3);
				if (GetHealth() >= 8)
					SetHealth(8);
			}
			else if (item->GetType() == eType::GENIE)
			{
				AddScore(250);
				Sound::GetInstance()->Play(eSound::sound_Wow);
			}
			else if (item->GetType() == eType::REDROCK)
				AddJewryrock();
			else if (item->GetType() == eType::TAO)
				AddApple();
			else if (item->GetType() == eType::RESTARTPOINT)
			{
				item->GetPosition(rX, rY);
				restartPoint.x = rX;
				restartPoint.y = rY - 50;
				Sound::GetInstance()->Play(eSound::sound_ContinuePoint);
			}
			item->SubHealth(1);
			item->Update(dt, coObject);

		}
	}
	for (UINT i = 0; i < coEvents.size(); i++) delete coEvents[i];
}

void Player::CollisiongWithWall(vector<LPGAMEOBJECT>* coObjects)
{
	vector<LPCOLLISIONEVENT> coEvents;
	vector<LPCOLLISIONEVENT> coEventsResult;

	coEvents.clear();
	coEventsResult.clear();
	vector<LPGAMEOBJECT> listEnemy;

	listEnemy.clear();


	for (UINT i = 0; i < coObjects->size(); i++)
	{
		if (coObjects->at(i)->GetType() == eType::OBJECT_PUSH)
		{
			listEnemy.push_back(coObjects->at(i));
		}
	}

	CalcPotentialCollisions(&listEnemy, coEvents, flag);//gọi hàm xét va chạm với các obj

	if (coEvents.size() == 0)
	{
		for (UINT i = 0; i < listEnemy.size(); i++)
		{
			GameObject *obj = listEnemy.at(i);
			if (obj->isCollitionObjectWithObject(this))
			{
				if (mCurrentState == AladdinState::Running)
				{
					if (isPush == false)
					{
						dx = 0;
						isPush = true;
						this->SetState(new AladdinPushState(this->mAladdinData));
					}
				}

				/*if (mCurrentState == AladdinState::Jumping)
					x -= 30 * direction;*/
			}
		}
	}
	else
	{
		float min_tx, min_ty, nx = 0, ny;

		FilterCollision(coEvents, coEventsResult, min_tx, min_ty, nx, ny); //lọc các obj có khả năng va chạm với aladdin
		for (UINT i = 0; i < coEventsResult.size(); i++)
		{
			LPCOLLISIONEVENT e = coEventsResult[i];
			
			if (e->nx != 0)//va chạm theo phương Ox
			{
				dx = 0;
				if (mCurrentState == AladdinState::Running2)
				{
					vx = 0;
					x -= 10 * this->direction;
					this->SetState(new AladdinStandingState(this->mAladdinData));
				}
				else if (mCurrentState == AladdinState::Jumping || mCurrentState == AladdinState::JumpingForward)
				{
					vx = 0;
					x -= 10 * this->direction;
					this->SetState(new AladdinFallingState(this->mAladdinData));
				}
				else
					this->SetState(new AladdinPushState(this->mAladdinData));
			}
			else
			{
				if (e->ny == 1)
				{
					//vx = 0;
					y += dy;
					x += dx;
				}
			}
		}
	}
}

void Player::CollisiongWithRope(vector<LPGAMEOBJECT>* coObject)
{
	vector<LPCOLLISIONEVENT> coEvents;
	vector<LPCOLLISIONEVENT> coEventsResult;

	coEvents.clear();
	coEventsResult.clear();

	//lay ds cac brick trong list object hien co

	vector<LPGAMEOBJECT> list_Rope;
	list_Rope.clear();
	for (UINT i = 0; i < coObject->size(); i++)
	{
		if (coObject->at(i)->GetType() == eType::OBJECT_CLIMB)
		{
			list_Rope.push_back(coObject->at(i));
		}
	}
	for (int i = 0; i < list_Rope.size(); i++)
	{
		LPGAMEOBJECT e = list_Rope.at(i);
		B_top = e->bordertop;
		B_bottom = e->borderbottom;
		if (checkAABB(e))
		{
			if ((mCurrentState == AladdinState::Jumping || mCurrentState == AladdinState::JumpingForward))
			{
				//y = B_top;
				vx = 0;
				dx = 0;
				x = e->x - 50;
				this->SetState(new AladdinClimbingState(this->mAladdinData));
			}
			
			
		}
	}
	CalcPotentialCollisions(&list_Rope, coEvents,flag);

	if (coEvents.size() == 0)//co xay ra va cham
	{
		isClimbing = false;
	}
	else
	{
		float min_tx, min_ty, nx = 0, ny;
		FilterCollision(coEvents, coEventsResult, min_tx, min_ty, nx, ny);
		for (UINT i = 0; i < coEventsResult.size(); i++)
		{
			B_top = coEventsResult[i]->obj->bordertop;
			B_bottom = coEventsResult[i]->obj->borderbottom;
			LPCOLLISIONEVENT e = coEventsResult[i];
			if (e->ny == 1|| e->nx!=0)
			{
				
				if ((mCurrentState == AladdinState::Jumping || mCurrentState == AladdinState::JumpingForward) && y < B_top)
					y = B_top;
				vx = 0;
				dx = 0;
				x = coEventsResult[i]->obj->x - 50;
				this->SetState(new AladdinClimbingState(this->mAladdinData));
			}
			
		}
	}
	for (UINT i = 0; i < coEvents.size(); i++) delete coEvents[i];
}

void Player::CollisionWithBrick(const vector<LPGAMEOBJECT>* coObject)
{
	flag = 1;
	if (this->y > 1100)
	{
		isFall = true;
		x = BackupX;
		y = backupY;
	}
	vector<LPCOLLISIONEVENT> coEvents;
	vector<LPCOLLISIONEVENT> coEventsResult;

	coEvents.clear();
	coEventsResult.clear();

	//lay ds cac brick trong list object hien co

	vector<LPGAMEOBJECT> list_Brick;
	list_Brick.clear();
	for (UINT i = 0; i < coObject->size(); i++)
	{
		if (coObject->at(i)->GetType() == eType::BRICK || coObject->at(i)->GetType() == eType::ROCK)
		{
			list_Brick.push_back(coObject->at(i));
		}
	}
	/*for (int i = 0; i < list_Brick.size(); i++)
	{
		LPGAMEOBJECT e = list_Brick.at(i);
		if (checkAABB(e)&&e->GetType()==eType::BRICK)
		{
			if (mCurrentState == AladdinState::Running)
			{
				y -= 5;
				this->SetState(new AladdinStandingState(this->mAladdinData));
			}
		}
	}*/
	CalcPotentialCollisions(&list_Brick, coEvents,flag);

	if (coEvents.size() == 0)//khong va cham
	{
		x += dx;
		y += dy;
	}
	else
	{
		float min_tx, min_ty, nx, ny;
		FilterCollision(coEvents, coEventsResult, min_tx, min_ty, nx, ny);
		y += min_ty * dy + ny * 0.4f;
		//if (nx != 0) vx = 0;
		//xet logic va cham voi brick
		for (UINT i = 0; i < coEventsResult.size(); i++)
		{
			LPCOLLISIONEVENT e = coEventsResult[i];

			if (dynamic_cast<Brick *>(e->obj))//e->obj is Brick
			{
				if (e->nx != 0)//co xay ra va cham theo phuong Ox
				{
					x += dx;
				}
				else//k xay ra va cham theo phuong Ox
				{
					x += min_tx * dx + nx * 0.4f;
				}
				if (ny == -1)//dang di xuong
				{
					isCollisionWithBrick = true;
					if (mCurrentState == AladdinState::Jumping||mCurrentState==AladdinState::Falling||mCurrentState==AladdinState::JumpingForward
						||mCurrentState==AladdinState::JumpingAttack||mCurrentState == AladdinState::JumpingThrow)
					{
						this->SetState(new AladdinStandingState(this->mAladdinData));
					}
					if (mCurrentState == AladdinState::JumpingClimb)
					{
						vx = 0;
						this->SetState(new AladdinJumping2State(this->mAladdinData));
					}
				}
				else// Nhay duoi len
				{
					y += dy;
					//x += dx;
				}
			}

			else if (dynamic_cast<Rock *>(e->obj))
			{
				if (e->nx != 0)
				{
					x += dx;
					y += dy;
				}
				else
				{
					x += min_tx * dx + nx * 0.4f;
				}
				if (ny == -1)
				{
					isCollisionWithBrick = true;
					if (mCurrentState == AladdinState::Jumping || mCurrentState == AladdinState::Falling || mCurrentState == AladdinState::JumpingForward
						|| mCurrentState == AladdinState::JumpingAttack || mCurrentState == AladdinState::JumpingThrow)
					{
						this->SetState(new AladdinStandingState(this->mAladdinData));
					}
				}
				else// Nhay duoi len
				{
					y += dy;
					//x += dx;
				}
			}
			else
				y += dy;
		}
	}

	for (UINT i = 0; i < coEvents.size(); i++) 
		delete coEvents[i];
}