#ifndef SPIDERWEB_H
#define SPIDERWEB_H

#include "header.h"
#include "const.h"
#include "Player.h"
#include "MainScene.h"
#include "Enemy.h"

class spiderWeb
{

public:
	static vector<spiderWeb> spiderWebs;
	static int randX, randY;
	static int PosX, PosY;

	spiderWeb();
	spiderWeb(int posX, int posY);
	static void SpawnFieldDropItem(int n);
	static bool HitCheck();
	static void Use();
	static void Showitem();
	static void Update();
};

#endif SPIDERWEB_H
