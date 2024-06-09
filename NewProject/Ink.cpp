#include "Ink.h"

vector<Ink> Ink::inks;
int Ink::randX;
int Ink::randY;

Ink::Ink()
{
    posX = 0;
    posY = 0;
}

Ink::Ink(int posX, int posY)
{
    this->posX = posX;
    this->posY = posY;
}

void Ink::SpawnFieldDropItem(int n) 
{
    if (n == 1 && MainScene::_player.numberOfStage == 1)
    {
        srand((unsigned)time(NULL));
        randX = rand() % ConsoleSizeWidth - 4;
        randX /= 2;
        randX *= 2;
        randY = rand() % ConsoleSizeHeight + 4;

        COORD cur = { randX, randY };

        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
        std::cout << "¡Ü";

        Ink newInk(randX, randY);
        inks.push_back(newInk);
    }
    else if (n == 1 && MainScene2::_player.numberOfStage == 3)
    {
        randX = Utility::Clamp(rand() % 43 + 40, 43, 75);
        randX /= 2;
        randX *= 2;
        randY = rand() % ConsoleSizeHeight / 2 + ConsoleSizeHeight / 2;
        COORD cur = { randX, randY };

        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
        std::cout << "¡Ü";

        Ink newInk(randX, randY);
        inks.push_back(newInk);
    }
}

void Ink::showInk() {

    COORD Cur;
    Cur.X = posX;
    Cur.Y = posY;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
    std::cout << "¡Ü";

}

bool Ink::HitCheck() {

    vector<Ink>::iterator it;
    for (it = inks.begin(); it != inks.end(); it++)
    {
        if (sqrt(pow(((*it).posX - MainScene::_player.PosX), 2) + pow(((*it).posY - MainScene::_player.PosY), 2)) < 2)
        {
            Use();
            inks.erase(it);
            return true;
        }
        else if (sqrt(pow(((*it).posX - MainScene2::_player.PosX), 2) + pow(((*it).posY - MainScene2::_player.PosY), 2)) < 2)
        {
            Use();
            inks.erase(it);
            return true;
        }
        else if (sqrt(pow(((*it).posX - BossScene::_player.PosX), 2) + pow(((*it).posY - BossScene::_player.PosY), 2)) < 2)
        {
            Use();
            inks.erase(it);
            return true;
        }

    }
    return false;
}

void Ink::Use()
{
    for (int i = 0; i < Enemy::enemies.size(); i++)
    {
        Enemy::enemies[i].isInked = true;
        
    }
    for (int i = 0; i < StrongEnemy::strongenemies.size(); i++)
        StrongEnemy::strongenemies[i].isInked = true;
}

void Ink::Update()
{
    showInk();
    HitCheck();
}