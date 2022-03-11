#pragma once
#include <iostream>
#include <random>
#include "Character.h"

class Player;

// ���� Ÿ�� ���
enum MyMonsterType
{
    ENUM_MONSTER_LUX,
    ENUM_MONSTER_VAYNE,
    ENUM_MONSTER_MASTERYI,
    ENUM_MONSTER_YASUO
};

// --------------------------------- CLASS
// --------------------------------- MONSTER
class Monster : public Character
{
private:

public:
    // ������
    Monster()
    {
    }
    Monster(std::string _name)
    {
        this->SetName(_name);
    }

    // ���� �Լ�
    virtual void RandomAttack(Player* player);
    virtual bool Attack(Player* player);
    virtual bool SkillA(Player* player);
    virtual bool SkillB(Player* player);
    virtual bool SkillC(Player* player);

    // ��� �Լ�
    virtual void PrintInfo();
};