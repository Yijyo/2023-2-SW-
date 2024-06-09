#include "BoosterShot.h"

int BoosterShot::level = 1;

BoosterShot::BoosterShot(char shape, string name, int maxLevel) : ItemSkill(shape, name, maxLevel)
{
    this->explanation = "���ݼӵ��� �����մϴ�.";
    this->levelUpexplanation = "���ݼӵ� ���";
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