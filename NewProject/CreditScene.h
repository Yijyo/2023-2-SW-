#ifndef CREDITSCENE_H
#define CREDITSCENE_H

#include "header.h"
#include "SceneManager.h"

class CreditScene
{
public:
    static string _creditString[4];
    static void End();
    static void Start();
    static void Update();
};

#endif