#ifndef SKILL_H
#define SKILL_H

#include <string>

class Skill {
public:
    enum ESkillType {
        None,
        Active,
        Item
    };

    Skill(char shape, std::string name, int maxLevel);


    // 멤버 변수
    std::string name;
    std::string explanation;
    std::string levelUpexplanation;
    ESkillType skillType = ESkillType::None;
    int level = 1;
    int maxLevel;
    char shape;

    virtual void dummy();

    // 멤버 함수(여기서는 생성자만 정의)
    // 다른 멤버 함수들이 있다면 여기에 프로토타입을 선언해야 합니다.

private:
    // 비공개 멤버 변수나 함수가 있다면 여기에 선언합니다.

};

#endif // SKILL_H
