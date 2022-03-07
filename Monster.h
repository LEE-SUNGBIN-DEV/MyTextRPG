#pragma once
#include <iostream>
#include "Character.h"

class Player;

// ���� Ÿ�� ���
enum MyMonsterType
{
    ENUM_MONSTER_SLIME,
    ENUM_MONSTER_GOBLIN,
    ENUM_MONSTER_DRAGON
};

// �Ӽ� ���
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
    // ������
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

    // ���� �Լ�
    void Attack(Player* player);
    void SkillA(Player* player);
    void SkillB(Player* player);
    void SkillC(Player* player);

    // ��� �Լ�
    void PrintInfo();

    // Get Info
    std::string GetElement();
    int GetDmg();

    // Set Info
    void SetElement(std::string _element);
    void SetDmg(int _dmg);
};