#include "Meat.h"

vector<Meat> Meat::Meats;
int Meat::randX;
int Meat::randY;

Meat::Meat()
{
    srand((unsigned)time(NULL));
    posX = 0;
    posY = 0;
}

Meat::Meat(int posX, int posY)
{
    this->posX = posX;
    this->posY = posY;
}

void Meat::SpawnFieldDropItem(int n) {
    if (n == 1 && MainScene2::_player.numberOfStage == 1)
    {
        randX = rand() % ConsoleSizeWidth - 4;
        randX /= 2;
        randX *= 2;
        randY = rand() % ConsoleSizeHeight + 4;

        COORD cur = { randX, randY };

        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
        std::cout << "¡Ü";

        Meat newInk(randX, randY);
        Meats.push_back(newInk);
    }
    else if (n == 1 && MainScene2::_player.numberOfStage == 2)
    {
        randX = Utility::Clamp(rand() % 43 + 40, 43, 75);
        randX /= 2;
        randX *= 2;
        randY = rand() % ConsoleSizeHeight / 2 + ConsoleSizeHeight / 2;
        COORD cur = { randX, randY };

        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
        std::cout << "¡Ü";
        //std::cout << "  ";

        Meat newInk(randX, randY);
        Meats.push_back(newInk);
    }
    else if (n == 1 && MainScene2::_player.numberOfStage == 3)
    {
        randX = Utility::Clamp(rand() % 43 + 40, 43, 75);
        randX /= 2;
        randX *= 2;
        randY = rand() % ConsoleSizeHeight / 2 + ConsoleSizeHeight / 2;
        COORD cur = { randX, randY };

        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
        std::cout << "¡Ü";
        //std::cout << "  ";

        Meat newInk(randX, randY);
        Meats.push_back(newInk);
    }

}

void Meat::ShowMeat()
{
    COORD Cur;
    Cur.X = posX;
    Cur.Y = posY;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
    std::cout << "¡Ü";

}

bool Meat::HitCheck() {

    vector<Meat>::iterator it;
    for (it = Meats.begin(); it != Meats.end(); it++)
    {
        if (sqrt(pow(((*it).posX - MainScene::_player.PosX), 2) + pow(((*it).posY - MainScene::_player.PosY), 2)) < 2)
        {
            Use();
            Meats.erase(it);
            return true;
        }
        if (sqrt(pow(((*it).posX - MainScene2::_player.PosX), 2) + pow(((*it).posY - MainScene2::_player.PosY), 2)) < 2)
        {
            Use();
            Meats.erase(it);
            return true;
        }
        if (sqrt(pow(((*it).posX - BossScene::_player.PosX), 2) + pow(((*it).posY - BossScene::_player.PosY), 2)) < 2)
        {
            Use();
            Meats.erase(it);
            return true;
        }
    }
    return false;
}

void Meat::Use()
{
    if (MainScene::_player.CurrentHp < MainScene::_player.maxHp)
        MainScene::_player.CurrentHp += 30;

    if (MainScene::_player.CurrentHp >= MainScene::_player.maxHp)
        MainScene::_player.CurrentHp = MainScene::_player.maxHp;

    if (MainScene2::_player.CurrentHp < MainScene2::_player.maxHp)
        MainScene2::_player.CurrentHp += 30;

    if (MainScene2::_player.CurrentHp >= MainScene2::_player.maxHp)
        MainScene2::_player.CurrentHp = MainScene2::_player.maxHp;

    if (BossScene::_player.CurrentHp < BossScene::_player.maxHp)
        BossScene::_player.CurrentHp += 30;

    if (BossScene::_player.CurrentHp >= BossScene::_player.maxHp)
        BossScene::_player.CurrentHp = BossScene::_player.maxHp;


}

void Meat::Update()
{
    ShowMeat();
    HitCheck();
}