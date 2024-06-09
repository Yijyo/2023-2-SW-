#ifndef STRONGENEMY_H
#define STRONGENEMY_H

#include "Player.h"
#include "Entity.h"
#include "MainScene.h"
#include "Enemy.h"
#include "BossScene.h"

class StrongEnemy
{
public:
	static vector<StrongEnemy> strongenemies;

	int PosX;
	int PosY;
	int currentHP;
	bool isDead;
	static bool isInked;
	int a, b, c, d, e;
	int moveCnt;
	StrongEnemy();
	StrongEnemy(int x, int y, int maxHP);
	void Move(int _count);
	void Dead();
	void HitCheck();
	static void SpawnEnemy();
	void ShowEnemy(int _count);
	void Update(int _count);
};

#endif