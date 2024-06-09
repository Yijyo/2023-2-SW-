#ifndef ALCOHOLSPRAY_H
#define ALCOHOLSPRAY_H

#include <string>
#include "Skill.h"      // �⺻ Ŭ���� Skill�� ���� ��� ����
#include "ItemSkill.h"  // �⺻ Ŭ���� ItemSkill�� ���� ��� ����
#include "MainScene.h"     // �⺻ Ŭ���� Player�� ���� ��� ����

class AlcoholSpray : public ItemSkill
{
public:
    static int level;
    AlcoholSpray(char shape, std::string name, int maxLevel);
    static void Use();
};

#endif // ALCOHOLSPRAY_H
