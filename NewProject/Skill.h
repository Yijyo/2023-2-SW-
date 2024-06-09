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


    // ��� ����
    std::string name;
    std::string explanation;
    std::string levelUpexplanation;
    ESkillType skillType = ESkillType::None;
    int level = 1;
    int maxLevel;
    char shape;

    virtual void dummy();

    // ��� �Լ�(���⼭�� �����ڸ� ����)
    // �ٸ� ��� �Լ����� �ִٸ� ���⿡ ������Ÿ���� �����ؾ� �մϴ�.

private:
    // ����� ��� ������ �Լ��� �ִٸ� ���⿡ �����մϴ�.

};

#endif // SKILL_H
