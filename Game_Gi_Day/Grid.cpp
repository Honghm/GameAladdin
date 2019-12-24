#include "define.h"
#include "Guard.h"
#include "Grid.h"
#include "Camera.h"
#include "Brick.h"
#include "ObjectHidden.h"
#include"Rock.h"
#include"Marble.h"
#include"Thorn.h"
#include"Tao.h"
#include"RedRock.h"
#include"Genie.h"
#include"Heart.h"
#include "Soldier.h"
#include "Ghost.h"
#include "Bat.h"
#include "ColumnWall.h"
#include "Boss.h"


Unit::Unit(Grid * grid, LPGAMEOBJECT obj, float x, float y)
{
	this->grid = grid;
	this->obj = obj;
	this->x = x;
	this->y = y;

	this->prev = NULL;
	this->next = NULL;

	grid->Add(this);
}

void Unit::Move(float x, float y)
{
	grid->Move(this, x, y);
}
Grid::Grid(int mapWidth, int mapHeight, int cellWidth, int cellHeight)
{
	this->mapWidth = mapWidth;
	this->mapHeight = mapHeight;

	this->cellWidth = cellWidth;
	this->cellHeight = cellHeight;

	numCol = mapWidth / cellWidth;
	numRow = mapHeight / cellHeight;

	cells.resize(numRow);

	for (int i = 0; i < numRow; i++)
		cells[i].resize(numCol);

	for (int i = 0; i < numRow; i++)
		for (int j = 0; j < numCol; j++)
			cells[i][j] = NULL;
}

Grid::~Grid()
{

}

void Grid::SetFile(const char * str)
{
	filepath = str;
}

void Grid::ReloadGrid()
{
	for (int i = 0; i < numRow; i++)
		for (int j = 0; j < numCol; j++)
			cells[i][j] = NULL;
	int id, type, direction, w, h, status, n;
	float x, y, borderL, borderR;

	ifstream inp(filepath, ios::in);
	inp >> n;
	for (int i = 0; i < n; i++)
	{
		inp >> id >> type >> direction >> x >> y >> w >> h >> borderL >> borderR >> status;
		Insert(id, type, direction, x, y, w, h, borderL, borderR, status);
	}
	inp.close();
}

GameObject * Grid::GetNewObject(int id, int direction, int type, float x, float y, int w, int h, float bl, float br, int st)
{
	switch (type)
	{
	case eType::BRICK:
		return new Brick(x, y, w, h);
		break;
	case eType::OBJECT_HIDDEN:
		return new ObjectHidden(x, y, w, h, bl, br, st);
		break;
	case eType::OBJECT_CLIMB:
		return new ObjectHidden(x, y, w, h,bl, br, st);
		break;
	case eType::OBJECT_CLIMBUP:
		return new ObjectHidden(x, y, w, h, bl, br, st);
		break;
	case eType::OBJECT_PUSH:
		return new ObjectHidden(x, y, w, h, bl, br, st);
		break;
	case eType::COLUMN1:
	case eType::COLUMN2:
	case eType::COLUMN3:
	case eType::COLUMN4:
		return new ColumnWall(x, y, w, h, st);
		break;
		//Platform
	case eType::ROCK:
		return new Rock(x, y, w, h, st);
		break;
	case eType::THORN:
		return new Thorn(x, y, w, h, st);
		break;
	case eType::MARBLE:
		return new Marble(x, y, w, h, st);
		break;

		//Item
	case eType::TAO:
		return new Tao(x, y, w, h, st);
		break;
	case eType::REDROCK:
		return new RedRock(x, y, w, h, st);
		break;
	case eType::GENIE:
		return new Genie(x, y, w, h, st);
		break;
	case eType::HEART:
		return new Heart(x, y, w, h, st);
		break;

		//Enemy
	case eType::GUARD:
		return new Guard(direction, x, y, bl, br, st);
		break; 
	case eType::SOLDIER:
		return new Soldier(direction, x, y, bl, br, st);
		break;
	case eType::GHOST:
		return new Ghost(direction, x, y, bl, br, st);
		break;
	case eType::BAT:
		return new Bat(direction, x, y, bl, br, st);
		break;
	case eType::BOSS:
		return new Boss(direction, x, y, st);
		break;
	
	}
	return NULL;
}

void Grid::GetListObject(vector<Unit*>& listUnit, Camera * camera)
{
	int start_col = (int)(camera->GetXCam() / cellWidth);//left  phai xét top với bootom 
	int end_col = ceil((camera->GetXCam() + SCREEN_WIDTH) / cellWidth); //right
	if (end_col > numCol)
		end_col = numCol;
	for (int i = 0; i < numRow; i++)
		for (int j = start_col; j < end_col; j++)
		{
			Unit * unit = cells[i][j];

			while (unit != NULL)
			{
				if (true)
					listUnit.push_back(unit);

				unit = unit->next;
			}
		}
}
void Grid::Insert(int id, int type, int direction, float x, float y, int w, int h, float bl, float br, int st)
{
	GameObject * obj = GetNewObject(id, direction, type, x, y, w, h, bl, br, st);
	if (obj == NULL)
		return;
	obj->SetId(id);
	obj->SetDirection(direction);
	Unit *unit = new Unit(this, obj, x, y);
}
void Grid::Add(Unit *unit)
{
	int row = (int)(unit->y / cellHeight);
	int col = (int)(unit->x / cellWidth);

	// thêm vào đầu cell - add head
	unit->prev = NULL;
	unit->next = cells[row][col];
	cells[row][col] = unit;

	if (unit->next != NULL)
		unit->next->prev = unit;
}

void Grid::Move(Unit *unit, float x, float y)
{
	// lấy chỉ số cell cũ
	int old_row = (int)(unit->y / cellHeight);
	int old_col = (int)(unit->x / cellWidth);

	// lấy chỉ số cell mới
	int new_row = (int)(y / cellHeight);
	int new_col = (int)(x / cellWidth);

	// nếu object ra khỏi vùng viewport -> không cần cập nhật
	if (new_row < 0 || new_row >= numRow || new_col < 0 || new_col >= numCol)
		return;

	// cập nhật toạ độ mới
	unit->x = x;
	unit->y = y;

	// cell không thay đổi
	if (old_row == new_row && old_col == new_col)
		return;

	// huỷ liên kết với cell cũ
	if (unit->prev != NULL)
	{
		unit->prev->next = unit->next;
	}

	if (unit->next != NULL)
	{
		unit->next->prev = unit->prev;
	}

	if (cells[old_row][old_col] == unit)
	{
		cells[old_row][old_col] = unit->next;
	}
	// thêm vào cell mới
	Add(unit);
}