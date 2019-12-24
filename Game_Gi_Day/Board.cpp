#include "Board.h"



string Board::FillNumber(string s, UINT MaxNumber)
{
	while (s.size() < MaxNumber)
		s = "0" + s;
	return s;
}


Board::Board()
{	

	health = new HealthCol();
	life = new Life();
	apple = new AppleFont();
	jewryrock = new JewryRock();
	mfont = new Font();
	
}


Board::~Board()
{

}

void Board::Update(DWORD dt,int health,int life,int apple,int jewryrock )
{
	this->health->SetHealth(health);
	this->health->Update(dt);
	this->life->SetLife(life);
	this->life->Update(dt);
	this->apple->SetAppleFont(apple);
	this->apple->Update(dt);
	this->jewryrock->SetJewryRock(jewryrock);
	this->jewryrock->Update(dt);
}

void Board::Render(int numapple,int numjewryrock,int numpoint,int numlife)
{
	this->health->Render();
	this->life->Render();
	this->jewryrock->Render();
	this->apple->Render();
	this->mfont->Render(265, 165, FillNumber(std::to_string(numjewryrock), 2));
	this->mfont->Render(210, 165, FillNumber(std::to_string(numapple), 2));
	this->mfont->Render(220,20, FillNumber(std::to_string(numpoint), 6));
	this->mfont->Render(20, 165, FillNumber(std::to_string(numlife), 2));
}
