#include "BoosterShot.h"

int BoosterShot::level = 1;

BoosterShot::BoosterShot(char shape, string name, int maxLevel) : ItemSkill(shape, name, maxLevel)
{
    this->explanation = "공격속도가 증가합니다.";
    this->levelUpexplanation = "공격속도 상승";
}

void BoosterShot::Use() {
    level++;
    if (MainScene::_player.numberOfStage == 1)
        MainScene::_player.attackSpeed++;

    if (MainScene2::_player.numberOfStage == 2)
        MainScene2::_player.attackSpeed++;

    if (BossScene::_player.numberOfStage == 3)
        BossScene::_player.attackSpeed++;
}