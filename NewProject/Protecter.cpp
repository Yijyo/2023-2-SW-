#include "Protecter.h"

int Protecter::level = 1;

Protecter::Protecter(char shape, string name, int maxLevel) : ItemSkill(shape, name, maxLevel)
{
	explanation = "최대 체력이 30 상승합니다.";
}

void Protecter::Use()
{
	level++;
	if (MainScene::_player.numberOfStage == 1)
	{
		MainScene::_player.maxHp += 30;
		MainScene::_player.CurrentHp += 30;
		if (MainScene::_player.maxHp <= MainScene::_player.CurrentHp)
			MainScene::_player.CurrentHp = MainScene::_player.maxHp;
	}

	if (MainScene2::_player.numberOfStage == 2)
	{
		MainScene2::_player.maxHp += 30;
		MainScene2::_player.CurrentHp += 30;
		if (MainScene2::_player.maxHp <= MainScene2::_player.CurrentHp)
			MainScene2::_player.CurrentHp = MainScene2::_player.maxHp;
	}

	if (BossScene::_player.numberOfStage == 3)
	{
		BossScene::_player.maxHp += 30;
		BossScene::_player.CurrentHp += 30;
		if (BossScene::_player.maxHp <= BossScene::_player.CurrentHp)
			BossScene::_player.CurrentHp = BossScene::_player.maxHp;
	}
}