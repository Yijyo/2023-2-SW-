#ifndef ITEMSKILL_H
#define ITEMSKILL_H

#include <string>
#include "Player.h"
#include "Skill.h"  // �⺻ Ŭ���� Skill�� ���� ��� ���� ����

class ItemSkill : public Skill {
public:
    ItemSkill(char shape, std::string name, int maxLevel);

    void Use();  // ���� ���� �Լ� ����
    void UpdateLevel();

    // �߰����� ��� ������ �Լ��� �ִٸ� ���⿡ �����մϴ�.

private:
    // ����� ��� ������ �Լ��� �ִٸ� ���⿡ �����մϴ�.

};

#endif // ITEMSKILL_H
