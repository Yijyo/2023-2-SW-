#ifndef MELEEATTACKSKILL_H
#define MELEEATTACKSKILL_H

#include <string>
#include "ActiveSkill.h"  // 기본 클래스 ActiveSkill에 대한 헤더 파일

class MeleeAttackSkill : public ActiveSkill {
public:
    MeleeAttackSkill(char shape, std::string name, int maxLevel, int damage, int skillCount, int skillDuration);

    void Attack(int count);  // 오버라이드된 Attack 함수 선언

    // SetRange와 다른 가상 함수가 있다면, 여기에 선언합니다.
    // virtual void SetRange() = 0;

private:
    // 비공개 멤버 변수나 함수가 있다면 여기에 선언합니다.

};

#endif // MELEEATTACKSKILL_H
