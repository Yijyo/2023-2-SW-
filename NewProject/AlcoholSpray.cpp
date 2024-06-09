#include "AlcoholSpray.h"

int AlcoholSpray::level = 1;

AlcoholSpray::AlcoholSpray(char shape, string name, int maxLevel) : ItemSkill(shape, name, maxLevel)
{
    this->explanation = "���ݷ��� �����մϴ�.";
    this->levelUpexplanation = "���ݷ� ���";
}

void AlcoholSpray::Use() {
    level++;
    if (MainScene::_player.numberOfStage == 1)
        MainScene::_player.attackPower++;
    if (MainScene2::_player.numberOfStage == 2)
        MainScene2::_player.attackPower++;
    if (BossScene::_player.numberOfStage == 3)
        BossScene::_player.attackPower++;
}