#pragma once

#include "Player.h"
#include "Entity.h"
#include "MainScene.h"

class BossPatternEnemy
{
public:
	static vector<BossPatternEnemy> bossPatternEnemies;

	int PosX;
	int PosY;
	int currentHP;
	BossPatternEnemy(int x, int y, int maxHP);
	void Move(int _count);
	void Dead();
	void HitCheck();
	static void SpawnEnemy();
	void ShowEnemy(int _count);
	void Update(int _count);

};