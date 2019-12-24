﻿#include "SceneGame.h"
#include <stdlib.h>
#include <ctime>
#include "Player.h"
#include "Soldier.h"
#include "Ghost.h"
#include "Bat.h"
#include "Boss.h"
SceneGame::SceneGame()
{
	LoadResources();

}

SceneGame::~SceneGame()
{
	SAFE_DELETE(TileMap);
	SAFE_DELETE(grid);
}

void SceneGame::KeyState(BYTE * state)
{
	player->HandleKeyboard(keys);
}

void SceneGame::OnKeyDown(int KeyCode)
{
	keys[KeyCode] = true;
	player->OnKeyPressed(KeyCode);
	if (KeyCode == DIK_N)
	{
		if (StateCurrent == 1)
		{
			InitGame(eType::MAP2);
			
		}
		else
			InitGame(eType::MAP1);
	}
}

void SceneGame::OnKeyUp(int KeyCode)
{
	keys[KeyCode] = false;
	player->OnKeyUp(KeyCode);
}

void SceneGame::LoadResources()
{
	TextureManager * textureManager = TextureManager::GetInstance();
	
	gameTime = new GameTime();
	TileMap = new Map();
	camera = new Camera(SCREEN_WIDTH, SCREEN_HEIGHT);
	grid = new Grid(2272, 1120);
	player = new Player(camera);
	board = new Board();
	InitGame();
}

void SceneGame::InitGame(eType map)
{
	LoadMap(map);
	
	gameTime->SetTime(0); // đếm lại từ 0
}


void SceneGame::ResetResource()
{
	grid->ReloadGrid();
	listObj.clear();
	listUnit.clear();
	camera->SetAllowFollowAladdin(true);
	isGameOver = false;
	remainTime = 0;
	count = 1;
	//ReplayMusicGame(StateCurrent);
}


void SceneGame::Update(DWORD dt)
{
	listObj.clear();
	listUnit.clear(); // lay obj co trong vung camera thong qua unit
	grid->GetListObject(listUnit, camera);
	for (UINT i = 0; i < listUnit.size(); i++)
	{
		LPGAMEOBJECT obj = listUnit[i]->GetObj();
		
		obj->Update(dt,&listObj);
		listObj.push_back(obj);
	}
	
	player->Update(dt,&listObj);
	board->Update(dt, player->GetHealth(),player->GetLife(),player->GetApple(),player->GetJewryRock());
	for (UINT i = 0; i < listObj.size(); i++)
	{
		LPGAMEOBJECT obj = listObj[i];
		if (dynamic_cast<Guard*>(listObj[i]))
		{
			Guard *guard = dynamic_cast<Guard*>(listObj[i]);
			guard->Update(dt, player);
		}
		else if (dynamic_cast<Soldier*>(listObj[i]))
		{
			Soldier *soldier = dynamic_cast<Soldier*>(listObj[i]);
				soldier->Update(dt, player->GetX(), player->GetY(), player->GetDirection(), &listObj);
		}
		else if (dynamic_cast<Ghost*>(listObj[i]))
		{
			Ghost *ghost = dynamic_cast<Ghost*>(listObj[i]);
			ghost->Update(dt, player->GetX(), player->GetY(), player->GetDirection(), player);
		}
		else if (dynamic_cast<Bat*>(listObj[i]))
		{
			Bat *bat = dynamic_cast<Bat*>(listObj[i]);
			bat->Update(dt, player->GetX(), player->GetY(), player->GetDirection(), &listObj);
		}
		else if (dynamic_cast<Boss*>(listObj[i]))
		{
			Boss *boss = dynamic_cast<Boss*>(listObj[i]);
			boss->Update(dt, player->GetX(), player->GetY(), player->GetDirection(), player);
		}
		else
			obj->Update(dt, &listObj);
	}
	camera->Update(dt);
	
	gameTime->Update(dt);

	UpdateGrid();
	//CheckCollision(dt);
}

void SceneGame::CheckDropItem()
{
	
}

void SceneGame::SetInactiveEnemy()
{
	
}

void SceneGame::UpdateGrid()
{
	for (int i = 0; i < listUnit.size(); i++)
	{
		LPGAMEOBJECT obj = listUnit[i]->GetObj();

		float newPos_x, newPos_y;
		obj->GetPosition(newPos_x, newPos_y);
		listUnit[i]->Move(newPos_x, newPos_y);
	}
}

void SceneGame::Render()
{
	if (!isGameOver)
	{
		TileMap->DrawMap(camera, 255, 255, 255);
		for (int i = 0; i < listUnit.size(); i++)
		{
			LPGAMEOBJECT obj = listUnit[i]->GetObj();
			
				obj->RenderBoundingBox(camera);
				obj->Render(camera);
			
		}
		player->Render(camera);
		for (int i = 0; i < listUnit.size(); i++)
		{
			LPGAMEOBJECT obj = listUnit[i]->GetObj();
			if(obj->GetType()==COLUMN1|| obj->GetType() == COLUMN2|| obj->GetType() == COLUMN3|| obj->GetType() == COLUMN4)
				obj->Render(camera);
		}
		board->Render(player->GetApple(), player->GetJewryRock(), player->GetScore(), player->GetLife());
	}
}


void SceneGame::LoadMap(eType x)
{
	mapCurrent = x;

	switch (x)
	{
	case eType::MAP1:
		grid->SetFile("Resources/ObjectMap.txt"); //load các obj có trong map

		TileMap->LoadMap(eType::MAP1);

		camera->SetAllowFollowAladdin(true);

		camera->SetBoundary(0.0f, (float)(TileMap->GetMapWidth() - camera->GetWidth() / 2 + 15), 0.0f, (float)(TileMap->GetMapHeight() - camera->GetHeight() / 2 + 38)); // set biên camera dựa vào kích thước map

		camera->SetBoundaryBackup(camera->GetBoundaryLeft(), camera->GetBoundaryRight(), camera->GetBoundaryTop(), camera->GetBoundaryBottom()); // backup lại biên
		player->SetPosition(0, 1000);
		camera->SetPosition(0, 1120);

		camera->SetAllowFollowAladdin(true);

		StateCurrent = 1;

		break;
	case eType::MAP2:
	{
		grid->SetFile("Resources/Boss/ObjectBoss.txt");

		TileMap->LoadMap(eType::MAP2);
		
		camera->SetAllowFollowAladdin(true);

		camera->SetBoundary(0.0f, (float)(TileMap->GetMapWidth() - camera->GetWidth() / 2 + 15), 0.0f, (float)(TileMap->GetMapHeight() - camera->GetHeight() / 2 + 38)); // set biên camera dựa vào kích thước map

		camera->SetBoundaryBackup(camera->GetBoundaryLeft(), camera->GetBoundaryRight(), camera->GetBoundaryTop(), camera->GetBoundaryBottom()); // backup lại biên

		player->SetPosition(0, 262);

		camera->SetPosition(0, 400);

		camera->SetAllowFollowAladdin(true);

		StateCurrent = 2;
		break;
	}
	}

	ResetResource();
}
//void SceneGame::CheckCollision(DWORD dt)
//{
//	CheckCollisonOfAladdin(dt); // kt vũ khí với enemy và aladdin với enemy
//
//}

//void SceneGame::CheckCollisonOfAladdin(DWORD dt)
//{
//	player->CollisionWeaponWithObj(&listObj);
//	player->CollisionWithEnemyArea(&listObj);
//	player->CollisionWithItems(&listObj);
//	player->CollisionWithPlatform(&listObj);
//	player->CollisiongWithWall(&listObj);
//	player->CollisionWithBrick(&listObj);
//}

//void SceneGame::CollisionWithItems(DWORD dt)
//{
//	for (UINT i = 0; i < listObj.size(); i++)
//	{
//		if (dynamic_cast<Item*> (listObj[i]))
//		{
//			if (!dynamic_cast<Item*>(listObj[i])->GetFinish() && dynamic_cast<Item*>(listObj[i])->isCollitionObjectWithObject(player))
//			{
//				dynamic_cast<Item*> (listObj[i])->SetFinish(true);
//				/*switch (dynamic_cast<Item*>(listObj[i])->GetType())
//				{
//				case eType::TAO:
//					dynamic_cast<Item*> (listObj[i])->SetFinish(true);
//					break;
//				default:
//					break;
//				}*/
//				
//			}
//		}
//	}
//}

void SceneGame::ReplayMusicGame(int map)
{
	

}

