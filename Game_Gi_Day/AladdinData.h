﻿#pragma once
//pre define
//Quản lý con trỏ
/*Class giúp chuyển đổi các state trong class Player và AladdinState
Các class state sẽ thông qua class này để lấy các thông tin trong class Player*/
class AladdinState;
class Player;
class AladdinData
{
public:
	AladdinData();
	~AladdinData();

	Player      *player;
	AladdinState *state;

protected:

};


//BBOX
#define ALADDIN_BBOX_WIDTH 100
#define ALADDIN_BBOX_HEIGHT 100

#define PULL_UP_ALADDIN_AFTER_SITTING 2.0f // Kéo ALADDIN lên 18px sau khi ngồi rồi đứng dậy, tránh overlaping do BBOX bottom thu lại khi ngồi

#define ALADDIN_VJUMP 0.5f //0.4
#define ALADDIN_VJUMP_HURTING 0.5f // nhảy lúc bị đau
#define PULL_UP_ALADDIN_AFTER_JUMPING 2.0f // Kéo ALADDIN lên 18px sau khi nhảy, tránh overlaping do BBOX bottom thu lại khi nhảy

#define ALADDIN_STATE_IDLE 0

//Jumping
#define ALADDIN_GRAVITY 0.05f 
#define ALADDIN_GRAVITY_JUMPING 0.00155f 
#define ALADDIN_GRAVITY_HURTING 0.003f
#define ALADDIN_ANI_JUMPING_BEGIN 13
#define ALADDIN_ANI_JUMPING_END 22


//Running
#define ALADDIN_WALKING_SPEED 0.1f
#define ALADDIN_WALKING_JUMPING_SPEED 0.2f
#define ALADDIN_ANI_WALKING_BEGIN 1
#define ALADDIN_ANI_WALKING_END 12
#define ALADDIN_ANI_WALKINGATTACKING_BEGIN 190
#define ALADDIN_ANI_WALKINGATTACKING_END 197

#define ALADDIN_ANI_IDLE 0


//Climbing
#define ALADDIN_ANI_CLIMBING_BEGIN 23
#define ALADDIN_ANI_CLIMBING_END 32

#define ALADDIN_ANI_CLIMBINGTHOW_BEGIN 202
#define ALADDIN_ANI_CLIMBINGTHOW_END 208
#define ALADDIN_ANI_CLIMBINGATTACK_BEGIN 209
#define ALADDIN_ANI_CLIMBINGATTACK_END 215

//Sitting
#define ALADDIN_ANI_SITTING_BEGIN 98
#define ALADDIN_ANI_SITTING_END  101

//Waitting
#define ALADDIN_ANI_WAITTING_1_BEGIN 33
#define ALADDIN_ANI_WAITTING_1_END 40 

#define ALADDIN_ANI_WAITTING_2_BEGIN 42 
#define ALADDIN_ANI_WAITTING_2_END 53 

#define ALADDIN_ANI_WAITTING_3_BEGIN 54 
#define ALADDIN_ANI_WAITTING_3_END 71

//Attacking
#define ALADDIN_ANI_ATTACKING_BEGIN 77
#define ALADDIN_ANI_ATTACKING_END 83

//Sitting & Attacking
#define ALADDIN_ANI_SITTINGATTACK_BEGIN 107 
#define ALADDIN_ANI_SITTINGATTACK_END 112

//Standing attack
#define ALADDIN_ANI_STANDINGATTACK_BEGIN 82
#define ALADDIN_ANI_STANDINGATTACK_END 94

//Looking
#define ALADDIN_ANI_LOOKUP_BEGIN 95
#define ALADDIN_ANI_LOOKUP_END  97

//Throw standing
#define ALADDIN_ANI_THROWSTANDING_BEGIN 72
#define ALADDIN_ANI_THROWSTANDDING_END 75

//Throw sitting
#define ALADDIN_ANI_SITTINGTHROW_BEGIN 102
#define ALADDIN_ANI_SITTINGTHROW_END 106 

#define ALADDIN_ANI_JUMPING_2_BEGIN 114
#define ALADDIN_ANI_JUMPING_2_END 125 

#define ALADDIN_ANI_JUMPINGFORWARD_BEGIN 127
#define ALADDIN_ANI_JUMPINGFORWARD_END 135 

#define ALADDIN_ANI_JUMPINGTHROW_BEGIN 135 
#define ALADDIN_ANI_JUMPINGTHROW_END 139

#define ALADDIN_ANI_JUMPINGATTACK_BEGIN 140
#define ALADDIN_ANI_JUMPINGATTACK_END 144

#define ALADDIN_ANI_RUNNING2_BEGIN 145
#define ALADDIN_ANI_RUNNING2_END 151

#define ALADDIN_ANI_JUMPINGCLIMB_BEGIN 153
#define ALADDIN_ANI_JUMPINGCLIMB_END 161

#define ALADDIN_ANI_PUSH_BEGIN 163
#define ALADDIN_ANI_PUSH_END 170

#define ALADDIN_ANI_BEINGATTACKED_BEGIN 172
#define ALADDIN_ANI_BEINGATTACKED_END 177

#define ALADDIN_ANI_DEAD_BEGIN 179 
#define ALADDIN_ANI_DEAD_END  188

#define ALADDIN_ANI_ATTACKCOLLISION_BEGIN 218 
#define ALADDIN_ANI_ATTACKCOLLISION_END  220
