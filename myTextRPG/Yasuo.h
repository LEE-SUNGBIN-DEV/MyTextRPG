#pragma once
#include "Monster.h"

// --------------------------------- CLASS
// --------------------------------- YASUO
class Player;

class Yasuo : public Monster
{
private:

public:
    // 생성자
    Yasuo()
    {
        this->SetHp(130);
        this->SetDmg(15);
        this->SetDef(3);
        this->SetDropGold(200);
        this->SetName("야스오");
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