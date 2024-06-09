#ifndef BOOSTERSHOT_H
#define BOOSTERSHOT_H

#include <string>
#include "Skill.h"
#include "ItemSkill.h" 
#include "MainScene.h"

class BoosterShot : public ItemSkill
{
public:
    static int level;
    BoosterShot(char shape, std::string name, int maxLevel);
    static void Use();  
};

#endif // BOOSTERSHOT_H
