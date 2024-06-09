#include "StrongEnemy.h"
#include "EndingScene.h"

vector<StrongEnemy> StrongEnemy::strongenemies;
bool StrongEnemy::isInked = false;

StrongEnemy::StrongEnemy()
{
    a = 0; b = 0; c = 0; d = 0; e = 0;
    PosX = 0;
    PosY = 0;
    moveCnt = 0.0f;
    isDead = false;
    isInked = false;
}

StrongEnemy::StrongEnemy(int x, int y, int maxHP)
{
    this->PosX = x;
    this->PosY = y;
    this->currentHP = maxHP;
    isDead = false;
}

void StrongEnemy::Move(int _count)//수정할게여 + 좌우 움직임 추가 예정
{
    COORD Cur;
    int flag = 0;
    int randX;
    Cur.X = PosX;
    Cur.Y = PosY;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);

    if (MainScene::_player.numberOfStage == 1)
    {
        a++;
        if (a % 3 == 0 || a % 2 == 0)
        {
            if (PosX < MainScene::_player.PosX)
            {

                std::cout << "  ";
                PosX++;
                PosX = Utility::Clamp(PosX, 0, ConsoleSizeWidth - 2);

            }
            else
            {

                std::cout << "  ";
                PosX--;
                PosX = Utility::Clamp(PosX, 0, ConsoleSizeWidth - 2);

            }
            if (PosY < MainScene::_player.PosY)
            {

                std::cout << "  ";
                PosY++;
                PosY = Utility::Clamp(PosY, 2, ConsoleSizeHeight - 1);

            }
            else
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
            moveCnt++;
            if (moveCnt % 2 == 0)
            {
                PosY++;
                PosY = Utility::Clamp(PosY, 2, ConsoleSizeHeight - 1);
            }
            else if(moveCnt == 3)
            {
                PosY++;
                PosY = Utility::Clamp(PosY, 2, ConsoleSizeHeight - 1);
                moveCnt = 0;
            }
            
            randX = rand() % 2;
            switch (randX)
            {
            case 0:
                PosX += 2;
                PosX = Utility::Clamp(PosX, ConsoleSizeWidth / 3 + 2, 2 * ConsoleSizeWidth / 3-2);
                break;
            case 1:
                PosX -= 2;
                PosX = Utility::Clamp(PosX, ConsoleSizeWidth / 3 + 2, 2 * ConsoleSizeWidth / 3 -2);
                break;
            }

        }
    }
    flag = 0;
}

void StrongEnemy::Dead()
{
    isDead = true;
    EndingScene::killCount = 1;
    MainScene::_player.CurrentExp = 10 * MainScene::_player.expAmount;
}

void StrongEnemy::SpawnEnemy()
{
    if (MainScene::_player.numberOfStage == 1)
    {
        StrongEnemy newEnemy(rand() % 130, rand() % 30, 200);
        strongenemies.push_back(newEnemy);
    }
    else if (MainScene::_player.numberOfStage == 2 || BossScene::_player.numberOfStage == 3)
    {
        StrongEnemy newEnemy(Utility::Clamp(rand() % 43 + 40, 43, 75), Utility::Clamp(rand() % 30, 3, 7), 300);
        strongenemies.push_back(newEnemy);
    }
}

void StrongEnemy::ShowEnemy(int _count)
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
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);

        if (StrongEnemy::isInked == true)
        {
            cout << " ";
        }
        else
        {
            cout << "▼";
        }
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
    }
}

void StrongEnemy::HitCheck()
{
    if (PosX == MainScene::_player.PosX && PosY == MainScene::_player.PosY)
        MainScene::_player.CurrentHp -= 10;

    if (PosX == MainScene2::_player.PosX && PosY == MainScene2::_player.PosY)
        MainScene2::_player.CurrentHp -= (10 - MainScene2::_player.defense * 2);
    
    if (PosX == BossScene::_player.PosX && PosY == BossScene::_player.PosY)
        BossScene::_player.CurrentHp -= (10 - BossScene::_player.defense * 2);

}

void StrongEnemy::Update(int _count)
{
    ShowEnemy(_count);
    HitCheck();
}