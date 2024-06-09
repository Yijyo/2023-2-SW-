#ifndef ACTIVESKILL_H
#define ACTIVESKILL_H

#include <vector>
#include <iostream>
#include <string>
#include <Windows.h>  // Windows-specific header for console operations
#include "Skill.h"    // Include the base class header
#include "const.h"    // If there are constants defined that this class uses

class ActiveSkill : public Skill {
public:
    ActiveSkill(char shape, std::string name, int maxLevel, int damage, int skillCount, int skillDuration);

    void Show();
    void UnShow();
    void Use();
    void Finish();
    void SetRange();
    void Attack(int count);
    void LevelUp();

private:
    int damage;
    int skillCount;
    int skillDuration;
    bool isUsing;
    std::vector<std::pair<int, int>> range;

    void gotoxy(int x, int y);
};

#endif // ACTIVESKILL_H
