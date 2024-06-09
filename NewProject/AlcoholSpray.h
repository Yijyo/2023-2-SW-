#ifndef ALCOHOLSPRAY_H
#define ALCOHOLSPRAY_H

#include <string>
#include "Skill.h"      // 기본 클래스 Skill에 대한 헤더 파일
#include "ItemSkill.h"  // 기본 클래스 ItemSkill에 대한 헤더 파일
#include "MainScene.h"     // 기본 클래스 Player에 대한 헤더 파일

class AlcoholSpray : public ItemSkill
{
public:
    static int level;
    AlcoholSpray(char shape, std::string name, int maxLevel);
    static void Use();
};

#endif // ALCOHOLSPRAY_H
