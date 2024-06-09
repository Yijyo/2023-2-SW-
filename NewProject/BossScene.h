#ifndef BOSSSCENE_H
#define BOSSSCENE_H

#include <chrono>
#include <vector>
#include <random>
#include <string>
#include "Player.h"
#include "Enemy.h"
#include "Nuclear.h"
#include "Ink.h"
#include "Meat.h"
#include "spiderWeb.h"
#include "AbilityManager.h"
#include "bullet.h"
#include "Boss.h"
#include "StrongEnemy.h"

using namespace std;

class BossScene
{
public:
    static Player _player;

    static int _count;
    static std::chrono::time_point<std::chrono::system_clock> startTime;
    static int spawnCount;
    static int isReadyToSpawn;
    static int update_count;

    static std::chrono::seconds time;

    //static AbilityManager abilityManager;

    std::random_device rd;
    std::uniform_int_distribution<> dis = std::uniform_int_distribution<>(0, 9);

    static char charmap[ConsoleSizeHeight + 1][ConsoleSizeWidth + 1];
    static int map[ConsoleSizeHeight + 1][ConsoleSizeWidth + 1];

    BossScene();
    ~BossScene() = default;
    static void ShowBackground();
    static void ShowUI();
    static void InitmapData();
    static void End();
    static void Update();
    static void Start();
    static void isMainScene();
};

#endif
