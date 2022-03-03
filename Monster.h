#pragma once
#include <iostream>
#include "Character.h"

// --------------------------------- CLASS
// --------------------------------- MONSTER
class Monster : public Character
{
public:
    std::string element;
    int dmg;

public:
    // ������
    Monster()
    {
        this->element = "NONE";
        this->name = "NONE";
        this->dmg = 1;
    }

    // ��� �Լ�
    void PrintInfo();

    // Get Info
    std::string GetElement();
    int GetDmg();

    // Set Info
    void SetElement(std::string _element);
    void SetDmg(int _dmg);
};