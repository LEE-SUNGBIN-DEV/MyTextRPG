#pragma once
#include "Monster.h"

// --------------------------------- CLASS
// --------------------------------- MASTER YI
class Player;

class MasterYi : public Monster
{
private:

public:
    // 생성자
    MasterYi()
    {
        this->SetHp(200);
        this->SetDmg(18);
        this->SetDef(4);
        this->SetDropGold(300);
        this->SetName("마스터 이");
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