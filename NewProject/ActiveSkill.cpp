#include "ActiveSkill.h"

ActiveSkill::ActiveSkill(char shape, std::string name, int maxLevel, int damage, int skillCount, int skillDuration)
    : Skill(shape, name, maxLevel), damage(damage), skillCount(skillCount), skillDuration(skillDuration), isUsing(false)
{
    skillType = ESkillType::Active;
}

void ActiveSkill::gotoxy(int x, int y) {
    COORD pos = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}



void ActiveSkill::Show()
{
    for (const auto& pair : range)
    {
        int x = pair.first;
        int y = pair.second;

        if (x >= 0 && x < ConsoleSizeWidth && y >= 0 && y < ConsoleSizeHeight)
        {
            gotoxy(x, y);
            std::cout << shape;
        }
    }
}

void ActiveSkill::UnShow()
{
    for (const auto& pair : range)
    {
        int x = pair.first;
        int y = pair.second;

        if (x >= 0 && x < ConsoleSizeWidth && y >= 0 && y < ConsoleSizeHeight)
        {
            gotoxy(x, y);
            std::cout << ' ';
        }
    }
}

void ActiveSkill::Use() { isUsing = true; }

void ActiveSkill::Finish() { isUsing = false; }

void ActiveSkill::SetRange() {};

void ActiveSkill::Attack(int count) {};

void ActiveSkill::LevelUp() {};