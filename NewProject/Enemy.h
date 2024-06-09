#ifndef ENEMY_H
#define ENEMY_H

#include "Player.h"
#include "Entity.h"
#include "MainScene.h"

class Enemy
{
public:
	static vector<Enemy> enemies;

	int PosX;
	int PosY;
	int currentHP;
	bool isDead;
	static bool isInked;
	int a, b, c, d, e;

	Enemy();
	Enemy(int x, int y, int maxHP);
	void Move(int _count);
	void Dead();
	void HitCheck();
	static void SpawnEnemy();
	void ShowEnemy(int _count);
	void Update(int _count);
};

#endif