#pragma once

#include "header.h"
#include "const.h"
#include "Utility.h"
#include "BossScene.h"
#include "Boss.h"
#include "BossPatternEnemy.h"

class BossPattern
{
public:
	BossPattern();
	BossPattern(int PosX, int PosY);

	static vector<BossPattern> bosspatterns;
	int PosX, PosY, e;

	void Update(int _count);
	static void Shoot();
	void Move();
	static void Remove();
	void HitCheck();
	void ShowPatterns();
};