#pragma once
#include <iostream>
#include <random>
#include "Monster.h"

// --------------------------------- CLASS
// --------------------------------- LUX
class Player;

class LUX : public Monster
{
private:

public:
    // 생성자
    LUX()
    {
        this->SetDmg(10);
        this->SetDef(1);
        this->SetName("럭스");
    }

    // 공격 함수
    void RandomAttack(Player* player);
    bool Attack(Player* player);
    bool SkillA(Player* player);
    bool SkillB(Player* player);
    bool SkillC(Player* player);
};