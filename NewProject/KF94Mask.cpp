#include "KF94Mask.h"

int KF94Mask::level = 1;

KF94Mask::KF94Mask(char shape, string name, int maxLevel) : ItemSkill(shape, name, maxLevel)
{
	this->explanation = "방어력이 증가합니다.";
	this->levelUpexplanation = "방어력 상승";
}

void KF94Mask::Use()
{
	level++;
	if (MainScene::_player.numberOfStage == 1)
		MainScene::_player.defense++;

	if (MainScene2::_player.numberOfStage == 2)
		MainScene2::_player.defense++;

	if (BossScene::_player.numberOfStage == 3)
		BossScene::_player.defense++;

}