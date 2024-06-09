#ifndef PLAYER_H
#define PLAYER_H
#include "Entity.h"
#include "const.h"
#include "Skill.h"
#include "ItemSkill.h"

class Player : public Entity 
{
public:
    char _entity;
    int PosX;
    int PosY;
    int CurrentHp;
    int maxHp;
    int level;
    int CurrentExp;
    bool isRight;
    int moveSpeed;
    int expAmount;
    int _currentExp;
    int attackPower;
    int attackSpeed;
    int maxExp;
    static int numberOfStage;
    static bool isAttack;
    static bool isBombed;
    static bool isWebed;
    static bool isInked;
    static int defense;

    Player();
    ~Player() = default;
    void Move();
    void ShowEntity();
    void Attack(int count);
    void LevelUp();
    void Dead();
    void HitCheck();
    void Update(int count);
    void AddSkill(Skill skill);
};

#endif