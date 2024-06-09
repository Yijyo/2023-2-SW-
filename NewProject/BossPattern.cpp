#include "BossPattern.h"

vector<BossPattern> BossPattern::bosspatterns;

BossPattern::BossPattern(int PosX, int PosY)
{
	this->PosX = PosX;
	this->PosY = PosY;
	this->e = 0;
}

void BossPattern::Move()
{
	COORD Cur;

	Cur.X = PosX;
	Cur.Y = PosY;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);

	std::cout << "  ";
	PosY+= 1;
	PosY = Utility::Clamp(PosY, 2, ConsoleSizeHeight - 1);

	
}

void BossPattern::Shoot()
{
	int random_num = rand() % 35;
	int randX = ConsoleSizeWidth / 2 + random_num - 16;
	randX /= 2;
	randX *= 2;

	BossPattern newBossPattern1(randX, 3);
	bosspatterns.push_back(newBossPattern1);
}

void BossPattern::Update(int _count)
{
	ShowPatterns();
	HitCheck();
	Remove();
}

void BossPattern::ShowPatterns()
{
	COORD Cur;
	Cur.X = PosX;
	Cur.Y = PosY;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
	std::cout << "  ";
	Move();
	Cur.X = PosX;
	Cur.Y = PosY;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);

	if (Enemy::isInked == true)
	{
		cout << " ";
	}
	else
	{
		cout << "¡Ü";
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

}

void BossPattern::Remove()
{
	for (int i = 0; i < bosspatterns.size(); i++) 
	{
		if (bosspatterns[i].PosY == 29)
		{
			COORD Cur;
			Cur.X = bosspatterns[i].PosX;
			Cur.Y = bosspatterns[i].PosY;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);

			std::cout << "  ";
			auto it = bosspatterns.erase(bosspatterns.begin() + i);
			if (it == bosspatterns.end())
				break;
		}
	}
}

void BossPattern::HitCheck()
{
	vector<BossPattern>::iterator it;
	COORD Cur;
	if (MainScene2::_player.numberOfStage == 2)
	{
		for (it = bosspatterns.begin(); it != bosspatterns.end(); it++)
		{
			if (sqrt(pow(((*it).PosX - MainScene2::_player.PosX), 2) + pow(((*it).PosY - MainScene2::_player.PosY), 2)) < 1.5)
			{
				MainScene2::_player.CurrentHp -= (30 - MainScene2::_player.defense * 10);
				Cur.X = (*it).PosX;
				Cur.Y = (*it).PosY;
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
				cout << "  ";
				it = bosspatterns.erase(it);
				if (it == bosspatterns.end())
					break;
			}
		}

	}
	else if (BossScene::_player.numberOfStage == 3)
	{
		for (it = bosspatterns.begin(); it != bosspatterns.end(); it++)
		{
			if (sqrt(pow(((*it).PosX - BossScene::_player.PosX), 2) + pow(((*it).PosY - BossScene::_player.PosY), 2)) < 1.5)
			{
				BossScene::_player.CurrentHp -= (30 - BossScene::_player.defense * 10);
				Cur.X = (*it).PosX;
				Cur.Y = (*it).PosY;
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
				cout << "  ";
				it = bosspatterns.erase(it);
				if (it == bosspatterns.end())
					break;
			}
		}
	}

}