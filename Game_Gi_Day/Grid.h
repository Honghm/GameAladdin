#pragma once
#define	__GRID_H__

#include "Game.h" 
#include "Sprite.h"  
#include "GameObject.h"


using namespace std;

#define GRID_CELL_WIDTH 284
#define GRID_CELL_HEIGHT 1120


class Unit;
class Grid
{
private:
	int mapWidth;
	int mapHeight;

	int cellWidth;
	int cellHeight;

	int numCol;
	int numRow;

	vector<vector<Unit*>> cells;
	const char * filepath;

public:
	Grid(int map_width, int map_height, int cell_width = GRID_CELL_WIDTH, int cell_height = GRID_CELL_HEIGHT);
	~Grid();

	void SetFile(const char * str); // Đọc các object từ file
	void ReloadGrid();


	GameObject * GetNewObject(int id, int direction, int type, float x, float y, int w, int h, float bl, float br, int st);
	void Insert(int id, int type, int direction, float x, float y, int w, int h, float bl, float br, int st); //Thêm object vào grid
	void GetListObject(vector<Unit*>& listUnits, Camera * camera);
	void Add(Unit  *unit);
	void Move(Unit * unit, float x, float y);
};

class Unit
{
	friend class Grid;
private:
	Grid *grid;
	LPGAMEOBJECT obj;
	float x;
	float y;
	Unit *prev;
	Unit *next;

public:
	Unit(Grid * grid, LPGAMEOBJECT obj, float x, float y);
	void Move(float x, float y);
	LPGAMEOBJECT GetObj() { return this->obj; }
};