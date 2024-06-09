#ifndef NURSEMAJORBOOK_H
#define NURSEMAJORBOOK_H

#include <string>
#include "Skill.h"      
#include "ItemSkill.h"
#include "MainScene.h"

class NurseMajorBook : public ItemSkill
{
public:
    static int level;
    NurseMajorBook(char shape, std::string name, int maxLevel);
    static void Use() ; 
};

#endif // NURSEMAJORBOOK_H
