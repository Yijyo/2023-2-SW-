#ifndef NUCLEAR_H
#define NUCLEAR_H

#include "header.h"
#include "const.h"
#include "Player.h"
#include "MainScene.h"
#include "Enemy.h"

class Nuclear
{
public:
	static vector<Nuclear> Nuclears;
	static int randX, randY;
	static int PosX, PosY;
	int attackPower;

	Nuclear();
	Nuclear(int posX, int posY);
	static void SpawnFieldDropItem(int n);
	static bool HitCheck();
	static void Showitem();
	static void Use();
	static void Update();
};

#endif NUCLEAR_H
#pragma once
