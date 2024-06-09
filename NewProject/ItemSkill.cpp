#include "ItemSkill.h"


ItemSkill::ItemSkill(char shape, std::string name, int maxLevel) :Skill(shape, name, maxLevel) {
    skillType = ESkillType::Item;
}

void ItemSkill::UpdateLevel() {
    Skill::level++;
}

void ItemSkill::Use() {};