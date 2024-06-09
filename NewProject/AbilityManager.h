#pragma once

#include <vector>
#include "Skill.h"
#include "Player.h"
#include "AlcoholSpray.h"
#include "BoosterShot.h"
#include "NurseMajorBook.h"
#include "Protecter.h"
#include "Shoes.h"
#include "KF94Mask.h"
#include "Utility.h"
#include "MainScene.h"


class AbilityManager {
public:
    static const int AbilityCardWidth = 15;
    static const int AbilityCardHeight = 12;
    static const int AbilityCardOffsetX = -8;
    static const int PaddingX = 5;

    static std::vector<ItemSkill> allSkills;
    static std::vector<ItemSkill> selectedSkills;
    static int _selectedNumber;
    static int first;
    static int second;
    static int third;

    AbilityManager();

    static void ShowLevelUpUI();
    static void SelectRandomSkill();
    static void ShowAbility(int cursorX, int cursorY, int index);
    static bool SelectInput();
};
