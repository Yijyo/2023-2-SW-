#ifndef SHOES_H
#define SHOES_H

#include <string>
#include "Skill.h"     
#include "ItemSkill.h" 
#include "MainScene.h"

class Shoes : public ItemSkill
{
public:
    static int level;
    Shoes(char shape, std::string name, int maxLevel);
    static void Use(); 
};

#endif
