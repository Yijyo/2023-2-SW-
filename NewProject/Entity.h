#ifndef ENTITY_H
#define ENTITY_H

#include "const.h"
#include "Utility.h"
#include "header.h"

class Entity 
{
public:
    int maxHp = 100;
    int _currentHp;
    int _posX;
    int _posY;
    char _entity;
    bool isDead = false;

    int PosX();
    void PosX(int value);
    int PosY();
    void PosY(int value);
    int CurrentHp();
    void CurrentHp(int value);

    virtual void Move() = 0;
    virtual void Dead() = 0;
    virtual void HitCheck() = 0;
    virtual void Update(int count) = 0;
};

#endif