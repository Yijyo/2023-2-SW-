#include "bullet.h"

vector<Bullet> Bullet::bullets;

Bullet::Bullet(int PosX, int PosY) {
	this->PosX = PosX;
	this->PosY = PosY;
}

void Bullet::Move() {
	COORD Cur;
	Cur.X = PosX;
	Cur.Y = PosY;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);

	std::cout << "  ";
	PosY--;
	PosY = Utility::Clamp(PosY, 2, ConsoleSizeHeight - 1);
}

void Bullet::Shoot() {
	int key;
	if (_kbhit() != 0) {
		key = _getch();

		if (key == 'K' || key == 'k') {
			if (MainScene2::_player.numberOfStage == 2) {
				Bullet newBullet(MainScene2::_player.PosX, MainScene2::_player.PosY - 1);
				bullets.push_back(newBullet);
			}
			else {
				Bullet newBullet(BossScene::_player.PosX, BossScene::_player.PosY - 1);
				bullets.push_back(newBullet);
			}
			
		}
	}
}

void Bullet::Update(int _count) {
	Move();
	ShowBullets();
	Remove();
}

void Bullet::ShowBullets() {
	COORD Cur;
	Cur.X = PosX;
	Cur.Y = PosY;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
	std::cout << "  ";
	Move();
	Cur.X = PosX;
	Cur.Y = PosY;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);

	if (Enemy::isInked == true)
	{
		cout << " ";
	}
	else
	{
		cout << "ก่";
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

}

void Bullet::Remove() {
	for (int i = 0; i < bullets.size(); i++) {
		if (bullets[i].PosY <= 3) {
			COORD Cur;
			Cur.X = bullets[i].PosX;
			Cur.Y = bullets[i].PosY;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);

			std::cout << "  ";
			bullets.erase(bullets.begin() + i);
		}
	}
}

void Bullet::HitCheck() {

}