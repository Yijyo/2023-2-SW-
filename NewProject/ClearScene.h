#pragma once
#include "header.h"
#include "const.h"
#include "SceneManager.h"

class ClearScene {
public:
    static int servivedTime;
    static int killCount;
    static void End();
    static void Start();
    static void Update();
};