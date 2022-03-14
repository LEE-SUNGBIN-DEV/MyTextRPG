#pragma once
#include "Monster.h"

// --------------------------------- CLASS
// --------------------------------- MASTER YI
class Player;

class MasterYi : public Monster
{
private:

public:
    // ������
    MasterYi()
    {
        this->SetHp(200);
        this->SetDmg(18);
        this->SetDef(4);
        this->SetDropGold(300);
        this->SetName("������ ��");
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