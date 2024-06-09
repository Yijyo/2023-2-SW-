#include "Shoes.h"

int Shoes::level = 1;

Shoes::Shoes(char shape, string name, int maxLevel) : ItemSkill(shape, name, maxLevel)
{
    explanation = "�̵��ӵ��� �����մϴ�.";
    levelUpexplanation = "�̵��ӵ� ���";
}

void Shoes::Use() {
    level++;
    if (MainScene::_player.numberOfStage == 1)
        MainScene::_player.moveSpeed++;
    if (MainScene2::_player.numberOfStage == 2)
        MainScene2::_player.moveSpeed++;
    if (BossScene::_player.numberOfStage == 3)
        BossScene::_player.moveSpeed++;
}