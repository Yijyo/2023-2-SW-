#include "MainScene2.h"

#include "header.h"
#include "MainScene.h"
#include "EndingScene.h"
#include "const.h"
#include "Enemy.h"

Player MainScene2::_player;
char MainScene2::charmap[ConsoleSizeHeight + 1][ConsoleSizeWidth + 1];
int MainScene2::map[ConsoleSizeHeight + 1][ConsoleSizeWidth + 1];

int MainScene2::_count;
std::chrono::time_point<std::chrono::system_clock> MainScene2::startTime;
int MainScene2::spawnCount;
int MainScene2::isReadyToSpawn;
int MainScene2::update_count;

MainScene2::MainScene2() {
	update_count = 0;
}

void MainScene2::ShowBackground()
{
	COORD Cur;

	for (int i = 0; i < ConsoleSizeHeight; i++)
	{
		for (int j = 0; j < ConsoleSizeWidth; j++)
		{
			cout << ' ';
			charmap[i][j] = ' ';
		}
		cout << endl;
	}

	for (int j = 2; j < ConsoleSizeHeight; j++)
	{
		Cur.X = ConsoleSizeWidth / 3;
		Cur.Y = j;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
		cout << "■";
	}

	for (int j = 2; j < ConsoleSizeHeight; j++)
	{
		Cur.X = 2 * ConsoleSizeWidth / 3;
		Cur.Y = j;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
		cout << "■";
	}

	Cur.X = 0;
	Cur.Y = 0;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);


	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // 기본 배경으로 초기화
	//system("color 0f");
}

void MainScene2::ShowUI()
{
	COORD Cur;
	Cur.X = 0;
	Cur.Y = 0;
	auto currentTime = chrono::system_clock::now();
	auto timeDiff = currentTime - startTime;
	chrono::seconds timeInSeconds = chrono::duration_cast<chrono::seconds>(timeDiff);

	for (int j = 2; j < ConsoleSizeHeight; j++)
	{
		Cur.X = ConsoleSizeWidth / 3;
		Cur.Y = j;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
		cout << "■";
	}

	for (int j = 2; j < ConsoleSizeHeight; j++)
	{
		Cur.X = 2 * ConsoleSizeWidth / 3;
		Cur.Y = j;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
		cout << "■";
	}


	Cur.X = 0;
	Cur.Y = 0;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);


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

	Cur.X = 0;
	Cur.Y = 0;
	// Hp Bar 출력
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
	for (int i = 0; i < ConsoleSizeWidth; i++)
	{
		if (i <= ConsoleSizeWidth * 100 / 100)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); // 빨간 배경
		}
		else
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // 기본 배경
		}

		/*if (i < 2)
		{
			cout << playerInfoText[i];
		}
		else
		{
		   cout << ' ';
		}*/
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // 기본 배경으로 초기화
}

void MainScene2::InitmapData()
{
	// map 데이터 초기화 로직
	map[ConsoleSizeHeight][ConsoleSizeWidth] = { 0 };
	charmap[ConsoleSizeHeight][ConsoleSizeWidth] = { 0 };
	ShowBackground();
}

void MainScene2::End()
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

void MainScene2::Update()
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

	Bullet::Shoot();

	for (int i = 0; i < Bullet::bullets.size(); i++) {
		Bullet::bullets[i].Update(_count);
	}

	if (update_count % 10 == 0)
		BossPattern::Shoot();

	for (int i = 0; i < BossPattern::bosspatterns.size(); i++) {
		BossPattern::bosspatterns[i].Update(_count);
	}

	BossPattern::Remove();

	if (_count < 30)
	{
		if (_count % 5 == 0)
		{
			Enemy::SpawnEnemy();
		}

		if (_count % 11 == 0)
		{
			StrongEnemy::SpawnEnemy();
		}
	}
	else if (_count < 90)
	{
		if (_count % 3 == 0)
		{
			Enemy::SpawnEnemy();
		}
		if (_count % 5 == 0)
		{
			StrongEnemy::SpawnEnemy();
		}
	}
	else
	{
		if (_count % 2 == 0)
		{
			Enemy::SpawnEnemy();
		}
		if (_count % 4 == 0)
		{
			StrongEnemy::SpawnEnemy();
		}
	}

	for (int i = 0; i < Enemy::enemies.size(); i++)
	{
		Enemy::enemies[i].Update(_count);
		if (Enemy::enemies[i].PosY == 29) {
			COORD Cur;
			Cur.X = Enemy::enemies[i].PosX;
			Cur.Y = Enemy::enemies[i].PosY;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
			std::cout << "  ";
			_player.CurrentHp -= 10;
			Enemy::enemies.erase(Enemy::enemies.begin() + i);
		}
	}

	for (int i = 0; i < Bullet::bullets.size(); i++) {
		for (int j = 0; j < Enemy::enemies.size(); j++)
		{
			if ((Bullet::bullets[i].PosX - 4 <= Enemy::enemies[j].PosX && Bullet::bullets[i].PosX + 4 >= Enemy::enemies[j].PosX) && Bullet::bullets[i].PosY == Enemy::enemies[j].PosY)
			{
				Enemy::enemies[j].currentHP -= (50 + 50 * _player.attackPower);						// 공격력 관련으로 수치 바꾸기
				if (Enemy::enemies[j].currentHP <= 0)
				{
					COORD Cur;
					Cur.X = Enemy::enemies[j].PosX;
					Cur.Y = Enemy::enemies[j].PosY;
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
					std::cout << "  ";
					Enemy::enemies.erase(Enemy::enemies.begin() + j);
					_player.CurrentExp += (5 + _player.expAmount);	// 수치 조정
				}
			}
		}
	}


	for (int i = 0; i < StrongEnemy::strongenemies.size(); i++)
	{
		StrongEnemy::strongenemies[i].Update(_count);
		if (StrongEnemy::strongenemies[i].PosY == 29)
		{
			COORD Cur;
			Cur.X = StrongEnemy::strongenemies[i].PosX;
			Cur.Y = StrongEnemy::strongenemies[i].PosY;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
			std::cout << "  ";
			_player.CurrentHp -= 10;
			StrongEnemy::strongenemies.erase(StrongEnemy::strongenemies.begin() + i);
		}
	}

	for (int i = 0; i < Bullet::bullets.size(); i++)
	{
		for (int j = 0; j < StrongEnemy::strongenemies.size(); j++)
		{
			if ((Bullet::bullets[i].PosX - 4 <= StrongEnemy::strongenemies[j].PosX && Bullet::bullets[i].PosX + 4 >= StrongEnemy::strongenemies[j].PosX) && Bullet::bullets[i].PosY == StrongEnemy::strongenemies[j].PosY)
			{
				StrongEnemy::strongenemies[j].currentHP -= (50 + 50 * _player.attackPower);
				if (StrongEnemy::strongenemies[j].currentHP <= 0)
				{
					cur.X = StrongEnemy::strongenemies[j].PosX;
					cur.Y = StrongEnemy::strongenemies[j].PosY;
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
					std::cout << "  ";
					StrongEnemy::strongenemies.erase(StrongEnemy::strongenemies.begin() + j);
					_player.CurrentExp += (10 + _player.expAmount * 2);
				}
			}
		}
	}


	cur.X = ConsoleSizeWidth / 2;
	cur.Y = ConsoleSizeHeight / 2;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
	
	int flag = 0;

	if (update_count % 251 == 0 && _count != 0)
	{
		Nuclear::SpawnFieldDropItem(1);
	}
	for (int i = 0; i < Nuclear::Nuclears.size(); i++)
	{
		Nuclear::Nuclears[i].Update();
	}

	if (update_count % 191 == 0 && _count != 0)
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

	if (_count % 30 == 0)
	{
		//MainScene::_player.moveSpeed = 1;
		for (int i = 0; i < Enemy::enemies.size(); i++)
		{
			Enemy::enemies[i].isInked = false;
		}
	}

	if (MainScene2::_player.isBombed == true)
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
			auto it = StrongEnemy::strongenemies.erase(StrongEnemy::strongenemies.begin());
		}
		MainScene2::_player.isBombed = false;
		system("color 0");
	}

	if (_player.CurrentExp >= _player.maxExp) {
		if (_player.level <= 10)
		{
			_player.LevelUp();
			AbilityManager::ShowLevelUpUI();
			_player.CurrentExp = 0;
			_player.maxExp += 50;
		}
		_player.CurrentHp += 20;
		if (_player.CurrentHp >= _player.maxHp)
			_player.CurrentHp = _player.maxHp;
	}

	if (_player.CurrentHp <= 0) {
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
		SceneManager::ChangeScene(EScene::BossSceneIntro);
		while (1)
		{
			SceneManager::Update(EScene::BossSceneIntro);
		}
	}


	std::this_thread::sleep_for(std::chrono::milliseconds(66));
}

void MainScene2::Start()
{
	for (int i = 0; i < Nuclear::Nuclears.size(); i++)
		Nuclear::Nuclears.erase(Nuclear::Nuclears.begin());

	for (int i = 0; i < Ink::inks.size(); i++)
		Ink::inks.erase(Ink::inks.begin());

	for (int i = 0; i < Meat::Meats.size(); i++)
		Meat::Meats.erase(Meat::Meats.begin());

	for (int i = 0; i < Enemy::enemies.size(); i++)
		Enemy::enemies.erase(Enemy::enemies.begin());

	_player = Player();
	EndingScene::killCount = 0;
	map[ConsoleSizeHeight + 1][ConsoleSizeWidth + 1] = { 0 };
	isReadyToSpawn = 1;
	MainScene2::_player.numberOfStage = 2;
	_count = 1;
	startTime = chrono::system_clock::now();
	InitmapData();
}

void MainScene2::isMainScene()
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
	MainScene2 mainScene;
	mainScene.Start();

	while (true)
	{
		mainScene.Update();
	}
}//인트로 씬에서 start하면 mainScene의 ismainScene함수 호출 종료는 여기서 말고  나중에 update에서 플레이어 죽으면 엔딩씬으로 이동하도록 하기

