#ifndef MAINSCENE_H
#define MAINSCENE_H

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
#include "MainScene2.h"
#include "MainScene2Intro.h"
#include "StrongEnemy.h"

using namespace std;

class MainScene 
{
public:
    static Player _player;

    int _count = 1;
    std::chrono::time_point<std::chrono::system_clock> startTime;
    int spawnCount;
    int isReadyToSpawn = 1;
    int update_count;

    std::chrono::seconds time;

    //static AbilityManager abilityManager;

    std::random_device rd;
    std::uniform_int_distribution<> dis = std::uniform_int_distribution<>(0, 9);

    char charmap[ConsoleSizeHeight + 1][ConsoleSizeWidth + 1];
    int map[ConsoleSizeHeight + 1][ConsoleSizeWidth + 1] = { 0 };

    MainScene();
    ~MainScene() = default;
    void ShowBackground();
    void ShowUI();
    void InitmapData();
    void End();
    void Update();
    void Start();
    static void ismainScene();
};

#endif