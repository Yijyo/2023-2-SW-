#ifndef ITEMSKILL_H
#define ITEMSKILL_H

#include <string>
#include "Player.h"
#include "Skill.h"  // 기본 클래스 Skill에 대한 헤더 파일 포함

class ItemSkill : public Skill {
public:
    ItemSkill(char shape, std::string name, int maxLevel);

    void Use();  // 순수 가상 함수 선언
    void UpdateLevel();

    // 추가적인 멤버 변수나 함수가 있다면 여기에 선언합니다.

private:
    // 비공개 멤버 변수나 함수가 있다면 여기에 선언합니다.

};

#endif // ITEMSKILL_H
