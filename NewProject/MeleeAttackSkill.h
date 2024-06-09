#ifndef MELEEATTACKSKILL_H
#define MELEEATTACKSKILL_H

#include <string>
#include "ActiveSkill.h"  // �⺻ Ŭ���� ActiveSkill�� ���� ��� ����

class MeleeAttackSkill : public ActiveSkill {
public:
    MeleeAttackSkill(char shape, std::string name, int maxLevel, int damage, int skillCount, int skillDuration);

    void Attack(int count);  // �������̵�� Attack �Լ� ����

    // SetRange�� �ٸ� ���� �Լ��� �ִٸ�, ���⿡ �����մϴ�.
    // virtual void SetRange() = 0;

private:
    // ����� ��� ������ �Լ��� �ִٸ� ���⿡ �����մϴ�.

};

#endif // MELEEATTACKSKILL_H
