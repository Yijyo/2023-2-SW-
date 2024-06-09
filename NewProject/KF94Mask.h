#ifndef KF94MASK_H
#define KF94MASK_H

#include "header.h"
#include "Skill.h"      // 기본 클래스 Skill에 대한 헤더 파일
#include "ItemSkill.h"  // 기본 클래스 ItemSkill에 대한 헤더 파일
#include "Player.h"     // 기본 클래스 Player에 대한 헤더 파일
#include "MainScene.h"

class KF94Mask : public ItemSkill
{
public:
	static int level;
	KF94Mask(char shape, string name, int maxLevel);
	static void Use();  // 오버라이드된 Use 함수 선언
};

#endif
