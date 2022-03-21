#pragma once
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
    int dropGold;

public:
    // ������
    Monster()
    {
        this->SetDropGold(0);
    }
    Monster(std::string _name) : Monster()
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
    virtual void DropItem(Player* player);

    // get
    virtual int GetDropGold();

    // set
    virtual void SetDropGold(int _dropGold);
};