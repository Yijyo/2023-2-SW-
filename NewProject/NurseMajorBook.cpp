#include "NurseMajorBook.h"

int NurseMajorBook::level = 1;

NurseMajorBook::NurseMajorBook(char shape, string name, int maxLevel) : ItemSkill(shape, name, maxLevel)
{
    this->explanation = "얻는 경험치가 증가합니다.";
    this->levelUpexplanation = "경험치량 상승";
}


void NurseMajorBook::Use() {
    level++;
    if (MainScene::_player.numberOfStage == 1)
        MainScene::_player.expAmount += 5;

    if (MainScene2::_player.numberOfStage == 2)
        MainScene2::_player.expAmount += 5;

    if (BossScene::_player.numberOfStage == 3)
        BossScene::_player.expAmount += 5;
}