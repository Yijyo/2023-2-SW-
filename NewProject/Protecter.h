#ifndef PROTECTER_H
#define PROTECTER_H

#include <string>
#include "Skill.h"     
#include "ItemSkill.h"
#include "MainScene.h"

class Protecter : public ItemSkill
{
public:
    static int level;
    Protecter(char shape, std::string name, int maxLevel);
    static void Use(); 
};

#endif
