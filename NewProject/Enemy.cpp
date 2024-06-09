#include "Enemy.h"
#include "EndingScene.h"

vector<Enemy> Enemy::enemies;
bool Enemy::isInked = false;

Enemy::Enemy()
{
    a = 0; b = 0; c = 0; d = 0; e = 0;
    PosX = 0;
    PosY = 0;
    currentHP = 100;
    isDead = false;
    isInked = false;
}

Enemy::Enemy(int x, int y, int maxHP)
{
    this->PosX = x;
    this->PosY = y;
    this->currentHP = maxHP;
    isDead = false;
}

void Enemy::Move(int _count)
{
    COORD Cur;
    int flag = 0;
    Cur.X = PosX;
    Cur.Y = PosY;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);

    if (MainScene::_player.numberOfStage == 1)
    {
        if (PosX < MainScene::_player.PosX)
        {
            a++;
            if (a % 2 == 0)
            {
                std::cout << "  ";
                PosX++;
                PosX = Utility::Clamp(PosX, 0, ConsoleSizeWidth - 2);
            }
        }
        else
        {
            b++;
            if (b % 2 == 0)
            {
                std::cout << "  ";
                PosX--;
                PosX = Utility::Clamp(PosX, 0, ConsoleSizeWidth - 2);
            }
        }
        if (PosY < MainScene::_player.PosY)
        {
            c++;
            if (c % 2 == 0)
            {
                std::cout << "  ";
                PosY++;
                PosY = Utility::Clamp(PosY, 2, ConsoleSizeHeight - 1);
            }
        }
        else
        {
            d++;
            if (d % 2 == 0)
            {
                std::cout << "  ";
                PosY--;
                PosY = Utility::Clamp(PosY, 2, ConsoleSizeHeight - 1);
            }
        }
    }

    else if (MainScene2::_player.numberOfStage == 2 || BossScene::_player.numberOfStage == 3)
    {
        e++;
        if (e % 3 == 0)
        {
            std::cout << "  ";
            PosY++;
            PosY = Utility::Clamp(PosY, 2, ConsoleSizeHeight - 1);
        }
    }
    flag = 0;
}

void Enemy::Dead()
{
    isDead = true;
    EndingScene::killCount = 1;
    MainScene::_player.CurrentExp = 10 * MainScene::_player.expAmount;
}

void Enemy::SpawnEnemy()
{
    if (MainScene::_player.numberOfStage == 1)
    {
        Enemy newEnemy(rand() % 130, rand() % 30, 100);
        enemies.push_back(newEnemy);
    }
    else if (MainScene::_player.numberOfStage == 2)
    {
        int randX = Utility::Clamp(rand() % 43 + 40, 43, 75);
        randX /= 2;
        randX *= 2;
        Enemy newEnemy(randX, Utility::Clamp(rand() % 30, 3, 7), 100);
        enemies.push_back(newEnemy);
    }
    else if (BossScene::_player.numberOfStage == 3)
    {
        int randX = Utility::Clamp(rand() % 43 + 40, 43, 75);
        randX /= 2;
        randX *= 2;
        Enemy newEnemy(randX, Utility::Clamp(rand() % 30, 8, 11), 100);
        enemies.push_back(newEnemy);
    }
}

void Enemy::ShowEnemy(int _count)
{
    COORD Cur;
    Cur.X = PosX;
    Cur.Y = PosY;

    if (_count) {
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
        std::cout << "  ";
        Move(_count);
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
            cout << "бу";
        }
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    }
}

void Enemy::HitCheck()
{
    if (PosX == MainScene::_player.PosX && PosY == MainScene::_player.PosY)
        MainScene::_player.CurrentHp -= (10 - MainScene::_player.defense * 2);

    if (PosX == MainScene2::_player.PosX && PosY == MainScene2::_player.PosY)
        MainScene2::_player.CurrentHp -= (10 - MainScene2::_player.defense * 2);

    if (PosX == BossScene::_player.PosX && PosY == BossScene::_player.PosY)
        BossScene::_player.CurrentHp -= (10 - BossScene::_player.defense * 2);
}

void Enemy::Update(int _count)
{
    ShowEnemy(_count);
    HitCheck();
}