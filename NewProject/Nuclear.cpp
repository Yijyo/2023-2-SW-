#include "Nuclear.h"
#include "MainScene.h"

vector<Nuclear> Nuclear::Nuclears;
int Nuclear::randX;
int Nuclear::randY;
int Nuclear::PosX;
int Nuclear::PosY;

Nuclear::Nuclear()
{
	PosX = 0;
	PosY = 0;
}

Nuclear::Nuclear(int posX, int posY)
{
	this->PosX = posX;
	this->PosY = posY;
}


void Nuclear::Showitem()
{
	COORD Cur;
	Cur.X = PosX;
	Cur.Y = PosY;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);//lightRed

	std::cout << "♨";
}
void Nuclear::SpawnFieldDropItem(int n)//생성
{
	if (n == 1 && MainScene::_player.numberOfStage == 1)
	{
		srand((unsigned)time(NULL));
		randX = rand() % ConsoleSizeWidth - 4;
		randX /= 2;
		randX *= 2;
		randY = rand() % ConsoleSizeHeight + 4;

		COORD cur = { randX, randY };

		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);//lightRed

		std::cout << "♨";

		Nuclear newNuclear(randX, randY);
		Nuclears.push_back(newNuclear);
	}
	else if (n == 1 && MainScene2::_player.numberOfStage == 2)
	{
		randX = Utility::Clamp(rand() % 43 + 40, 43, 75);
		randX /= 2;
		randX *= 2;
		randY = rand() % ConsoleSizeHeight / 2 + ConsoleSizeHeight / 2;
		COORD cur = { randX, randY };

		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);//lightRed

		std::cout << "♨";

		Nuclear newNuclear(randX, randY);
		Nuclears.push_back(newNuclear);
	}
	else if (n == 1 && MainScene2::_player.numberOfStage == 3)
	{
		randX = Utility::Clamp(rand() % 43 + 40, 43, 75);
		randX /= 2;
		randX *= 2;
		randY = rand() % ConsoleSizeHeight / 2 + ConsoleSizeHeight / 2;
		COORD cur = { randX, randY };

		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);//lightRed

		std::cout << "♨";

		Nuclear newNuclear(randX, randY);
		Nuclears.push_back(newNuclear);
	}

}


bool Nuclear::HitCheck() {

	vector<Nuclear>::iterator it;
	for (it = Nuclears.begin(); it != Nuclears.end(); it++)
	{
		if (sqrt(pow(((*it).PosX - MainScene::_player.PosX), 2) + pow(((*it).PosY - MainScene::_player.PosY), 2)) < 2)
		{
			Use();
			Nuclears.erase(it);
			return true;
		}
		else if (sqrt(pow(((*it).PosX - MainScene2::_player.PosX), 2) + pow(((*it).PosY - MainScene2::_player.PosY), 2)) < 2)
		{
			Use();
			Nuclears.erase(it);
			return true;
		}
		else if (sqrt(pow(((*it).PosX - BossScene::_player.PosX), 2) + pow(((*it).PosY - BossScene::_player.PosY), 2)) < 2)
		{
			Use();
			Nuclears.erase(it);
			return true;
		}
	}
	return false;
}

void Nuclear::Use()
{
	MainScene::_player.isBombed = true;
	system("color 3"); //색상 변경 -> 죽이면  죽이는 코드 뒤에 system("color 0"); 해주세욤
	Sleep(50);
	//system("color 0");
}

void Nuclear::Update()
{
	Showitem();
	HitCheck();
}