#ifndef ENDINGSCENE_H
#define ENDINGSCENE_H

#include "header.h"
#include "const.h"
#include "SceneManager.h"

class EndingScene
{
public:
    static int servivedTime;
    static int killCount;
    static void End();
    static void Start();
    static void Update();
};

#endif