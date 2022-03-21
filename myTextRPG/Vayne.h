#pragma once
#include "Monster.h"

// --------------------------------- CLASS
// --------------------------------- VAYNE
class Player;

class Vayne : public Monster
{
private:

public:
    // ������
    Vayne()
    {
        this->SetHp(100);
        this->SetDmg(10);
        this->SetDef(1);
        this->SetDropGold(150);
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