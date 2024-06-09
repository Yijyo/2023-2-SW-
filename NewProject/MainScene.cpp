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
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // 기본 배경으로 초기화
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

	// 문자열 포맷팅
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
	cout << "            공격력 : " << _player.attackPower << " 공격 속도 : " << _player.attackSpeed << " 이동 속도 : " << _player.moveSpeed << " 방어력 : " << _player.defense;

	Cur.X = ConsoleSizeWidth - 25;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
	cout << "Player's Experience : " << _player.CurrentExp;

	Cur.X = 300;
	Cur.Y = 300;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // 기본 배경으로 초기화
}

void MainScene::InitmapData()
{
	// map 데이터 초기화 로직
	map[ConsoleSizeHeight][ConsoleSizeWidth] = { 0 };
	charmap[ConsoleSizeHeight][ConsoleSizeWidth] = { 0 };
	ShowBackground();
}

void MainScene::End()
{
	system("cls"); // 콘솔을 지움

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
			Enemy::enemies[i].currentHP -= (40 + 40 * MainScene::_player.attackPower);						// 공격력 관련으로 수치 바꾸기
			if (Enemy::enemies[i].currentHP <= 0)
			{
				Enemy::enemies.erase(Enemy::enemies.begin() + i);
				_player.CurrentExp += 5 + _player.expAmount ;		// 수치 조정
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
			StrongEnemy::strongenemies[i].currentHP -= (40 + 40 * MainScene::_player.attackPower);						// 공격력 관련으로 수치 바꾸기
			if (StrongEnemy::strongenemies[i].currentHP <= 0)
			{
				StrongEnemy::strongenemies.erase(StrongEnemy::strongenemies.begin() + i);
				_player.CurrentExp += 10 + _player.expAmount * 2;		// 수치 조정
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
		// 여기에 Enemies, Items, Player 초기화 요망
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

	// 커서 정보를 가져와서 수정합니다.
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(consoleHandle, &cursorInfo);

	// 커서를 숨기려면 dwSize를 1로, bVisible을 FALSE로 설정합니다.
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = FALSE;

	// 수정된 커서 정보를 설정합니다.
	SetConsoleCursorInfo(consoleHandle, &cursorInfo);
	MainScene mainScene;
	mainScene.Start();

	while (true)
	{
		mainScene.Update();
	}
}//인트로 씬에서 start하면 mainScene의 ismainScene함수 호출 종료는 여기서 말고  나중에 update에서 플레이어 죽으면 엔딩씬으로 이동하도록 하기

