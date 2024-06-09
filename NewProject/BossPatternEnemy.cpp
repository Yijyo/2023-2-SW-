#include "BossPatternEnemy.h"
#include "EndingScene.h"

vector<BossPatternEnemy> BossPatternEnemy::bossPatternEnemies;

BossPatternEnemy::BossPatternEnemy(int x, int y, int maxHP)
{
	this->PosX = x;
	this->PosY = y;
	this->currentHP = maxHP;
}

void BossPatternEnemy::Dead()
{
	EndingScene::killCount += 1;
	BossScene::_player.CurrentExp = 20 * BossScene::_player.expAmount;
}

void BossPatternEnemy::SpawnEnemy()
{
	int randX = Utility::Clamp(rand() % 43 + 40, 43, 75);
	randX /= 2;
	randX *= 2;
	BossPatternEnemy newBossPatternEnemy(randX, Utility::Clamp(rand() % 30, 13, 16), 500);
	bossPatternEnemies.push_back(newBossPatternEnemy);
}

void BossPatternEnemy::ShowEnemy(int _count)
{
	COORD Cur;
	Cur.X = PosX;
	Cur.Y = PosY;
	if (_count)
	{
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
		cout << "бр";
	}
}

void BossPatternEnemy::Update(int _count)
{
	ShowEnemy(_count);
}