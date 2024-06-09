#include "spiderWeb.h"
#include "MainScene.h"

vector<spiderWeb> spiderWeb::spiderWebs;
int spiderWeb::randX;
int spiderWeb::randY;
int spiderWeb::PosX;
int spiderWeb::PosY;

spiderWeb::spiderWeb()
{
	PosX = 0;
	PosY = 0;
}

spiderWeb::spiderWeb(int posX, int posY)
{
	this->PosX = posX;
	this->PosY = posY;
}

void spiderWeb::Showitem()
{
	COORD Cur;
	Cur.X = PosX;
	Cur.Y = PosY;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);//lightRed

	std::cout << "¢Ì";
}

void spiderWeb::SpawnFieldDropItem(int n)//»ý¼º
{
	if (n == 1)
	{
		srand((unsigned)time(NULL));
		randX = rand() % ConsoleSizeWidth / 2;
		randY = rand() % ConsoleSizeHeight + 4;

		COORD cur = { randX, randY };

		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);//lightRed

		std::cout << "¢Ì";

		spiderWeb newspiderWeb(randX, randY);
		spiderWebs.push_back(newspiderWeb);
	}

}


bool spiderWeb::HitCheck() {

	vector<spiderWeb>::iterator it;
	for (it = spiderWebs.begin(); it != spiderWebs.end(); it++)
	{
		if ((pow(((*it).PosX - MainScene::_player.PosX), 2) + pow(((*it).PosY - MainScene::_player.PosY), 2)) < 2)
		{
			spiderWebs.erase(it);
			Use();
			return true;
		}
	}
	return false;
}

void spiderWeb::Use()
{
	MainScene::_player.moveSpeed = 0;
}

void spiderWeb::Update()
{
	Showitem();
	HitCheck();
}