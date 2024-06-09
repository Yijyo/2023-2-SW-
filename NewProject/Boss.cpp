#include "Boss.h"

int Boss::PosX;
int Boss::PosY;
int Boss::isHit = 0;
int Boss::entity[8][22] =
{
	{0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0},
	{0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0},
	{1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0},
	{0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0},
	{0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0}
};

int Boss::CurrentHP = 10000;
int Boss::MaxHP = 10000;
vector<Boss> Boss::_boss;

Boss::Boss()
{
	PosX = ConsoleSizeWidth / 2;
	PosY = 5;
}

bool Boss::bossPattern1()
{
	for (int i = 0; i < 10; i++)
		BossPattern::Shoot();
	return true;
}

bool Boss::bossPattern2()
{
	return true;
}

bool Boss::bossPattern3()
{
	return true;
}

void Boss::hitCheck() {
	Boss::CurrentHP -= (10 + 10 * BossScene::_player.attackPower);
	isHit = 1;
}

void Boss::ShowEntity() {
	COORD Cur;
	Cur.Y = 3;
	for (int j = 0; j < 8; j++)
	{
		Cur.X = ConsoleSizeWidth / 2 - 10;
		Cur.Y += 1;
		for (int i = 0; i < 22; i++)
		{
			Cur.X += 1;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
			if (entity[j][i] == 1)
			{
				if (isHit == 1) {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
					std::cout << "o";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				}
				else {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					std::cout << "o";
				}
			}
		}

	}
}