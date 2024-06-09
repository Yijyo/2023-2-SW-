#include <iostream>
#include <vector>
#include <windows.h>
#include "const.h"
#include "Entity.h"
#include "Player.h"
#include "SceneManager.h"

bool Player::isAttack = false;
bool Player::isBombed = false;
bool Player::isInked = false;
int Player::numberOfStage = 1;
int Player::defense = 0;

Player::Player() : level(1), isRight(true), moveSpeed(1), expAmount(0), PosX(ConsoleSizeWidth / 2),PosY(ConsoleSizeHeight / 2), _entity('бс'), CurrentHp(100), maxHp(100), _currentExp(0), attackSpeed(1), attackPower(1)
{
	maxExp = 100;
	CurrentHp = 100;
	CurrentExp = 0;
}

void Player::Move()
{
	COORD Cur;
	Cur.X = PosX;
	Cur.Y = PosY;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
	if (MainScene::_player.numberOfStage == 1)
	{
		if (GetAsyncKeyState((int)('W')) != 0) {
			std::cout << "  ";
			PosY -= moveSpeed;
			PosY = Utility::Clamp(PosY, 2, ConsoleSizeHeight - 1);
		}
		if (GetAsyncKeyState((int)('A')) != 0) {
			//isRight = false;
			std::cout << "  ";
			PosX -= moveSpeed * 2;
			PosX = Utility::Clamp(PosX, 0, ConsoleSizeWidth - 2);
		}
		if (GetAsyncKeyState((int)('S')) != 0) {
			std::cout << "  ";
			PosY += moveSpeed;
			PosY = Utility::Clamp(PosY, 2, ConsoleSizeHeight - 1);
		}
		if (GetAsyncKeyState((int)('D')) != 0) {
			//isRight = true;
			std::cout << "  ";
			PosX += moveSpeed * 2;
			PosX = Utility::Clamp(PosX, 0, ConsoleSizeWidth - 2);
		}
	}
	else if (MainScene2::_player.numberOfStage == 2)
	{
		if (GetAsyncKeyState((int)('W')) != 0) {
			std::cout << "  ";
			PosY -= moveSpeed;
			PosY = Utility::Clamp(PosY, 2, ConsoleSizeHeight - 1);
		}
		if (GetAsyncKeyState((int)('A')) != 0) {
			//isRight = false;
			std::cout << "  ";
			PosX -= moveSpeed * 2;
			PosX = Utility::Clamp(PosX, ConsoleSizeWidth / 3 + 2, 2 * ConsoleSizeWidth / 3 + 2);
		}
		if (GetAsyncKeyState((int)('S')) != 0) {
			std::cout << "  ";
			PosY += moveSpeed;
			PosY = Utility::Clamp(PosY, 2, ConsoleSizeHeight - 1);
		}
		if (GetAsyncKeyState((int)('D')) != 0) {
			//isRight = true;
			std::cout << "  ";
			PosX += moveSpeed * 2;
			PosX = Utility::Clamp(PosX, ConsoleSizeWidth / 3, 2 * ConsoleSizeWidth / 3 - 2);
		}
	}
	else if (BossScene::_player.numberOfStage == 3)
	{
		if (GetAsyncKeyState((int)('W')) != 0) {
			std::cout << "  ";
			PosY -= moveSpeed;
			PosY = Utility::Clamp(PosY, 2, ConsoleSizeHeight - 1);
		}
		if (GetAsyncKeyState((int)('A')) != 0) {
			//isRight = false;
			std::cout << "  ";
			PosX -= moveSpeed * 2;
			PosX = Utility::Clamp(PosX, ConsoleSizeWidth / 3 + 2, 2 * ConsoleSizeWidth / 3 + 2);
		}
		if (GetAsyncKeyState((int)('S')) != 0) {
			std::cout << "  ";
			PosY += moveSpeed;
			PosY = Utility::Clamp(PosY, 2, ConsoleSizeHeight - 1);
		}
		if (GetAsyncKeyState((int)('D')) != 0) {
			//isRight = true;
			std::cout << "  ";
			PosX += moveSpeed * 2;
			PosX = Utility::Clamp(PosX, ConsoleSizeWidth / 3, 2 * ConsoleSizeWidth / 3 - 2);
		}
	}
}

void Player::ShowEntity()
{
	COORD Cur;

	if (MainScene::_player.numberOfStage == 1)
	{
		Cur.X = PosX;
		Cur.Y = PosY + 1;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
		std::cout << "  ";

		Cur.X = PosX;
		Cur.Y = PosY + 2;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
		std::cout << "  ";

		Cur.X = PosX + 2;
		Cur.Y = PosY + 2;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
		std::cout << "  ";

		Cur.X = PosX - 2;
		Cur.Y = PosY + 2;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
		std::cout << "  ";


		Cur.X = PosX;
		Cur.Y = PosY - 1;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
		std::cout << "  ";

		Cur.X = PosX;
		Cur.Y = PosY - 2;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
		std::cout << "  ";

		Cur.X = PosX - 2;
		Cur.Y = PosY - 2;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
		std::cout << "  ";

		Cur.X = PosX + 2;
		Cur.Y = PosY - 2;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
		std::cout << "  ";

		Cur.X = PosX + 2;
		Cur.Y = PosY;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
		std::cout << "  ";

		Cur.X = PosX - 2;
		Cur.Y = PosY;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
		std::cout << "  ";

		Cur.X = PosX + 2;
		Cur.Y = PosY + 1;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
		std::cout << "  ";

		Cur.X = PosX - 2;
		Cur.Y = PosY + 1;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
		std::cout << "  ";

		Cur.X = PosX + 2;
		Cur.Y = PosY - 1;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
		std::cout << "  ";

		Cur.X = PosX - 2;
		Cur.Y = PosY - 1;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
		std::cout << "  ";

		Cur.X = PosX;
		Cur.Y = PosY;

		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		std::cout << "  ";
	}

	Move();
	Cur.X = PosX;
	Cur.Y = PosY;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
	std::cout << "бс";

	std::cout << "  ";

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

void Player::Attack(int count)
{
	COORD Cur;

	if (MainScene::_player.numberOfStage == 1)
	{
		if (count % 3 >= (3 - attackSpeed))
		{
			Cur.X = PosX;
			Cur.Y = PosY + 1;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
			std::cout << "##";

			Cur.X = PosX;
			Cur.Y = PosY + 2;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
			std::cout << "##";

			Cur.X = PosX + 2;
			Cur.Y = PosY + 2;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
			std::cout << "##";

			Cur.X = PosX - 2;
			Cur.Y = PosY + 2;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
			std::cout << "##";

			Cur.X = PosX - 2;
			Cur.Y = PosY - 2;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
			std::cout << "##";

			Cur.X = PosX + 2;
			Cur.Y = PosY - 2;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
			std::cout << "##";

			Cur.X = PosX;
			Cur.Y = PosY - 1;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
			std::cout << "##";

			Cur.X = PosX;
			Cur.Y = PosY - 2;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
			std::cout << "##";

			Cur.X = PosX + 2;
			Cur.Y = PosY;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
			std::cout << "##";

			Cur.X = PosX - 2;
			Cur.Y = PosY;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
			std::cout << "##";

			Cur.X = PosX + 2;
			Cur.Y = PosY + 1;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
			std::cout << "##";

			Cur.X = PosX - 2;
			Cur.Y = PosY + 1;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
			std::cout << "##";

			Cur.X = PosX + 2;
			Cur.Y = PosY - 1;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
			std::cout << "##";

			Cur.X = PosX - 2;
			Cur.Y = PosY - 1;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
			std::cout << "##";

			isAttack = true;
		}
		else isAttack = false;
	}
	

}

void Player::LevelUp()
{
	level++;
}

void Player::AddSkill(Skill skill) {
	if (skill.skillType == Skill::ESkillType::Active)
	{
	}
	else if (skill.skillType == Skill::ESkillType::Item)
	{
		ItemSkill* itemSkill = dynamic_cast<ItemSkill*>(&skill);
		itemSkill->Use();
	}
}

void Player::Dead()
{
	SceneManager::ChangeScene(EScene::Ending);
	while (1)
	{
		SceneManager::Update(EScene::Ending);
	}
}

void Player::HitCheck()
{

}

void Player::Update(int count)
{
	ShowEntity();
	Attack(count);
}

