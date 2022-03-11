#pragma once
#include <iostream>
#include <random>
#include "Monster.h"

// --------------------------------- CLASS
// --------------------------------- YASUO
class Player;

class Yasuo : public Monster
{
private:

public:
    // ������
    Yasuo()
    {
        this->SetDmg(10);
        this->SetDef(1);
        this->SetName("�߽���");
    }

    // ���� �Լ�
    void RandomAttack(Player* player);
    bool Attack(Player* player);
    bool SkillA(Player* player);
    bool SkillB(Player* player);
    bool SkillC(Player* player);
};