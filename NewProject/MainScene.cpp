#include "header.h"
#include "MainScene.h"
#include "EndingScene.h"
#include "const.h"
#include "Enemy.h"

Player MainScene::_player;
//vector<Enemy> Enemy::enemies;

MainScene::MainScene() {
	update_count = 0;
}

void MainScene::ShowBackground()
{
	for (int i = 0; i < ConsoleSizeHeight; i++)
	{
		for (int j = 0; j < ConsoleSizeWidth; j++)
		{
			cout << ' ';
			charmap[i][j] = ' ';
		}
		cout << endl;
	}
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // �⺻ ������� �ʱ�ȭ
	//system("color 0f");
}

void MainScene::ShowUI()
{
	COORD Cur;
	Cur.X = 0;
	Cur.Y = 0;
	auto currentTime = chrono::system_clock::now();
	auto timeDiff = currentTime - startTime;
	chrono::seconds timeInSeconds = chrono::duration_cast<chrono::seconds>(timeDiff);

	// ���ڿ� ������
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
	cout << " HP(" << _player.CurrentHp << "/" << _player.maxHp << ")";
	Cur.X = ConsoleSizeWidth / 2 - 4;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
	printf("%02d:%02d:%02d", timeInSeconds.count() / 3600, (timeInSeconds.count() % 3600) / 60, timeInSeconds.count() % 60);

	Cur.X = ConsoleSizeWidth - 12;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
	cout << " Level : " + to_string(_player.level);

	Cur.X = 0;
	Cur.Y = 1;
	printf("   Remaining monsters : %02d", Enemy::enemies.size() + StrongEnemy::strongenemies.size());

	Cur.X = 60;
	cout << "            ���ݷ� : " << _player.attackPower << " ���� �ӵ� : " << _player.attackSpeed << " �̵� �ӵ� : " << _player.moveSpeed << " ���� : " << _player.defense;

	Cur.X = ConsoleSizeWidth - 25;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
	cout << "Player's Experience : " << _player.CurrentExp;

	Cur.X = 300;
	Cur.Y = 300;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // �⺻ ������� �ʱ�ȭ
}

void MainScene::InitmapData()
{
	// map ������ �ʱ�ȭ ����
	map[ConsoleSizeHeight][ConsoleSizeWidth] = { 0 };
	charmap[ConsoleSizeHeight][ConsoleSizeWidth] = { 0 };
	ShowBackground();
}

void MainScene::End()
{
	system("cls"); // �ܼ��� ����

	for (int i = 0; i < ConsoleSizeHeight; i++)
	{
		for (int j = 0; j < ConsoleSizeWidth; j++)
		{
			cout << ' ';
		}
		cout << endl;
	}
}

void MainScene::Update()
{
	COORD cur;
	update_count++;
	auto currentTime = chrono::system_clock::now();
	auto timeDiff = currentTime - startTime;
	chrono::seconds timeInSeconds = chrono::duration_cast<chrono::seconds>(timeDiff);
	_count = timeInSeconds.count();

	_player.HitCheck();
	_player.Update(_count);

	map[ConsoleSizeHeight][ConsoleSizeWidth] = { 0 };

	ShowUI();

	if (_count % 10 == 0)
	{
		Enemy::SpawnEnemy();
	}

	for (int i = 0; i < Enemy::enemies.size(); i++)
	{
		Enemy::enemies[i].Update(_count);
	}
	for (int i = 0; i < Enemy::enemies.size(); i++)
	{
		if (sqrt(pow(Enemy::enemies[i].PosX - _player.PosX, 2) + pow(Enemy::enemies[i].PosY - _player.PosY, 2)) < 3 && _player.isAttack == true)
		{
			Enemy::enemies[i].currentHP -= (40 + 40 * MainScene::_player.attackPower);						// ���ݷ� �������� ��ġ �ٲٱ�
			if (Enemy::enemies[i].currentHP <= 0)
			{
				Enemy::enemies.erase(Enemy::enemies.begin() + i);
				_player.CurrentExp += 5 + _player.expAmount ;		// ��ġ ����
			}
		}
	}

	if (_count % 21 == 0)
	{
		StrongEnemy::SpawnEnemy();
	}

	for (int i = 0; i < StrongEnemy::strongenemies.size(); i++)
	{
		StrongEnemy::strongenemies[i].Update(_count);
	}
	for (int i = 0; i < StrongEnemy::strongenemies.size(); i++)
	{
		if (sqrt(pow(StrongEnemy::strongenemies[i].PosX - _player.PosX, 2) + pow(StrongEnemy::strongenemies[i].PosY - _player.PosY, 2)) < 3 && _player.isAttack == true)
		{
			StrongEnemy::strongenemies[i].currentHP -= (40 + 40 * MainScene::_player.attackPower);						// ���ݷ� �������� ��ġ �ٲٱ�
			if (StrongEnemy::strongenemies[i].currentHP <= 0)
			{
				StrongEnemy::strongenemies.erase(StrongEnemy::strongenemies.begin() + i);
				_player.CurrentExp += 10 + _player.expAmount * 2;		// ��ġ ����
			}
		}
	}



	cur.X = ConsoleSizeWidth / 2;
	cur.Y = ConsoleSizeHeight / 2;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);

	if (update_count % 181 == 0 && _count != 0)
	{
		Nuclear::SpawnFieldDropItem(1);
	}
	for (int i = 0; i < Nuclear::Nuclears.size(); i++)
	{
		Nuclear::Nuclears[i].Update();
	}

	if (update_count % 251 == 0 && _count != 0)
	{
		Ink::SpawnFieldDropItem(1);
	}
	for (int i = 0; i < Ink::inks.size(); i++)
	{
		Ink::inks[i].Update();
	}

	if (update_count % 97 == 0 && _count != 0)
	{
		Meat::SpawnFieldDropItem(1);
	}
	for (int i = 0; i < Meat::Meats.size(); i++)
	{
		Meat::Meats[i].Update();
	}

	if (update_count >= 300)
		update_count = 0;


	//spiderWeb::SpawnFieldDropItem(update_count % 100);
	//for (int i = 0; i < spiderWeb::spiderWebs.size(); i++)
	//	spiderWeb::spiderWebs[i].Update();

	if (_count % 20 == 0)
	{
		for (int i = 0; i < Enemy::enemies.size(); i++)
		{
			Enemy::enemies[i].isInked = false;
		}
		for (int i = 0; i < StrongEnemy::strongenemies.size(); i++)
		{
			StrongEnemy::strongenemies[i].isInked = false;
		}
	}

	if (MainScene::_player.isBombed == true)
	{
		for (int i = 0; i < Enemy::enemies.size(); i++)
		{
			cur.X = Enemy::enemies[0].PosX;
			cur.Y = Enemy::enemies[0].PosY;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
			cout << "  ";
			Enemy::enemies.erase(Enemy::enemies.begin());
		}
		for (int i = 0; i < StrongEnemy::strongenemies.size(); i++)
		{
			cur.X = StrongEnemy::strongenemies[0].PosX;
			cur.Y = StrongEnemy::strongenemies[0].PosY;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
			cout << "  ";
			StrongEnemy::strongenemies.erase(StrongEnemy::strongenemies.begin());
		}
		MainScene::_player.isBombed = false;
	}

	if (_player.CurrentExp >= _player.maxExp) {
		_player.LevelUp();
		AbilityManager::ShowLevelUpUI();
		_player.CurrentHp += 30;
		if (_player.CurrentHp >= _player.maxHp)
			_player.CurrentHp = _player.maxHp;
		_player.CurrentExp = 0;
		_player.maxExp += 50;
	}

	if (_player.CurrentHp <= 0) {
		// ���⿡ Enemies, Items, Player �ʱ�ȭ ���
		EndingScene::killCount = _player.CurrentExp / 10;
		EndingScene::servivedTime = _count;

		_player = Player();
		Enemy::enemies = {};
		_player.Dead();
	}

	if (_count >= 120) {
		Enemy::enemies.clear();
		Ink::inks.clear();
		Nuclear::Nuclears.clear();
		Meat::Meats.clear();
		MainScene::End();
		MainScene2Intro::Start();
		while (1)
		{
			MainScene2Intro::Update();
		}
	}

	std::this_thread::sleep_for(std::chrono::milliseconds(66));
}

void MainScene::Start()
{
	_player = Player();
	_player.numberOfStage = 1;
	EndingScene::killCount = 0;
	startTime = chrono::system_clock::now();
	InitmapData();
}

void MainScene::ismainScene()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

	// Ŀ�� ������ �����ͼ� �����մϴ�.
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(consoleHandle, &cursorInfo);

	// Ŀ���� ������� dwSize�� 1��, bVisible�� FALSE�� �����մϴ�.
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = FALSE;

	// ������ Ŀ�� ������ �����մϴ�.
	SetConsoleCursorInfo(consoleHandle, &cursorInfo);
	MainScene mainScene;
	mainScene.Start();

	while (true)
	{
		mainScene.Update();
	}
}//��Ʈ�� ������ start�ϸ� mainScene�� ismainScene�Լ� ȣ�� ����� ���⼭ ����  ���߿� update���� �÷��̾� ������ ���������� �̵��ϵ��� �ϱ�

