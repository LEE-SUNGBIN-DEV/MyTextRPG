#pragma once
#include "Monster.h"

// --------------------------------- CLASS
// --------------------------------- VAYNE
class Player;

class Vayne : public Monster
{
private:

public:
    // 생성자
    Vayne()
    {
        this->SetHp(100);
        this->SetDmg(10);
        this->SetDef(1);
        this->SetDropGold(150);
        this->SetName("베인");
    }

    // 공격 함수
    void RandomAttack(Player* player);
    bool Attack(Player* player);
    bool SkillA(Player* player);
    bool SkillB(Player* player);
    bool SkillC(Player* player);

    // 기능함수
    void DropItem(Player* player);
};