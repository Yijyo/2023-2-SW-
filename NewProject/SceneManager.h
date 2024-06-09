#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H
#include "const.h"
#include "IntroScene.h"
#include "InfoScene.h"
#include "CreditScene.h"
#include "EndingScene.h"
#include "MainScene.h"
#include "MainScene2.h"
#include "BossSceneIntro.h"
#include "ClearScene.h"

class SceneManager
{
public:
    static EScene currentScene;

    static void ChangeScene(EScene scene);
    static EScene Update(EScene scene);
    static void EndScene(EScene scene);
};

#endif