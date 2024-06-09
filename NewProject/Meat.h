#ifndef MEAT_H
#define MEAT_H

#include "header.h"
#include "const.h"
#include "Player.h"
#include "MainScene.h"
#include "Enemy.h"

class Meat
{
public:
	static vector<Meat> Meats;
	static int randX, randY;
	int posX, posY;
	Meat();
	Meat(int posX, int posY);
	static void SpawnFieldDropItem(int n);
	void ShowMeat();
	static bool HitCheck();
	static void Use();
	void Update();
};

#endif
