#ifndef INK_H
#define INK_H

#include "header.h"
#include "const.h"
#include "Player.h"
#include "MainScene.h"
#include "Enemy.h"
#include "StrongEnemy.h"

class Ink
{
public:
	static vector<Ink> inks;
	static int randX, randY;
	int posX, posY;
	Ink();
	Ink(int posX, int posY);
	static void SpawnFieldDropItem(int n);
	void showInk();
	static bool HitCheck();
	static void Use();
	void Update();
};

#endif