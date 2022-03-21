#pragma once
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
        this->SetHp(130);
        this->SetDmg(15);
        this->SetDef(3);
        this->SetDropGold(200);
        this->SetName("�߽���");
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