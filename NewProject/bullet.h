#pragma once
#include "header.h"
#include "const.h"
#include "Utility.h"
#include "MainScene2.h"

class Bullet {

public:
	Bullet();
	Bullet(int PosX, int PosY);

	static vector<Bullet> bullets;
	int PosX;
	int PosY;

	void Update(int _count);
	static void Shoot();
	void Move();
	void Remove();
	void HitCheck();
	void ShowBullets();
};