#pragma once
#include <iostream>
#include "Character.h"

class Player;

// 몬스터 타입 목록
enum MyMonsterType
{
    ENUM_MONSTER_SLIME,
    ENUM_MONSTER_GOBLIN,
    ENUM_MONSTER_DRAGON
};

// 속성 목록
enum MyElementType
{
    ENUM_ELEMENT_FIRE,
    ENUM_ELEMENT_WATER,
    ENUM_ELEMENT_WIND,
    ENUM_ELEMENT_LAND,
    ENUM_ELEMENT_LIGHT,
    ENUM_ELEMENT_DARK
};

// --------------------------------- CLASS
// --------------------------------- MONSTER
class Monster : public Character
{
private:
    std::string element;
    int dmg;

public:
    // 생성자
    Monster()
    {
        this->element = "NONE";
        this->dmg = 1;
    }
    Monster(std::string _name)
    {
        this->SetName(_name);
        this->element = "NONE";
        this->dmg = 1;
    }

    // 공격 함수
    void Attack(Player* player);
    void SkillA(Player* player);
    void SkillB(Player* player);
    void SkillC(Player* player);

    // 기능 함수
    void PrintInfo();

    // Get Info
    std::string GetElement();
    int GetDmg();

    // Set Info
    void SetElement(std::string _element);
    void SetDmg(int _dmg);
};