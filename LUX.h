#pragma once
#include "Monster.h"

// --------------------------------- CLASS
// --------------------------------- LUX
class Player;

class LUX : public Monster
{
private:

public:
    // ������
    LUX()
    {
        this->SetHp(70);
        this->SetDmg(7);
        this->SetDef(0);
        this->SetDropGold(100);
        this->SetName("����");
    }

    // ���� �Լ�
    void RandomAttack(Player* player);
    bool Attack(Player* player);
    bool SkillA(Player* player);
    bool SkillB(Player* player);
    bool SkillC(Player* player);

    // ����Լ�
    void DropItem(Player* player);
};