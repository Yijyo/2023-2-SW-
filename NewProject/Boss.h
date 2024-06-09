#ifndef BOSS_H
#define BOSS_H

#include "header.h"
#include "Player.h"
#include "Enemy.h"
#include "BossScene.h"
#include "BossPattern.h"

class Boss
{
public:
	Boss();
	~Boss() = default;
	static int entity[8][22];
	static int PosX, PosY;
	static int CurrentHP;
	static int isHit;
	static int MaxHP;
	static vector<Boss> _boss;

	static bool bossPattern1();
	static bool bossPattern2();
	static bool bossPattern3();
	static void hitCheck();
	static void ShowEntity();
};

#endif
