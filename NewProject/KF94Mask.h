#ifndef KF94MASK_H
#define KF94MASK_H

#include "header.h"
#include "Skill.h"      // �⺻ Ŭ���� Skill�� ���� ��� ����
#include "ItemSkill.h"  // �⺻ Ŭ���� ItemSkill�� ���� ��� ����
#include "Player.h"     // �⺻ Ŭ���� Player�� ���� ��� ����
#include "MainScene.h"

class KF94Mask : public ItemSkill
{
public:
	static int level;
	KF94Mask(char shape, string name, int maxLevel);
	static void Use();  // �������̵�� Use �Լ� ����
};

#endif
