#include "Knight.h"
#include "Monster.h"

// --------------------------------- CLASS
// --------------------------------- KNIGHT

// ���� �Լ�
bool Knight::Attack(Monster* monster)
{
    int dmg;
    int mul = 1;

    setColor(RED);
    std::cout << " [ " << this->GetName() << "��(��) "
        << monster->GetName() << "���� �⺻ ����! ]" << std::endl;

    dmg = mul * ((this->GetDmg() + this->GetDmgBuff())
        - (monster->GetDef() + monster->GetDefBuff()));
    if (dmg < 0) dmg = 0;

    monster->HpShieldManager(dmg);
    this->TurnManager();

    return true;
}
bool Knight::SkillA(Monster* monster)
{
    int dmg;
    int mul = 2;
    int needMana = 20;

    setColor(RED);
    if (this->GetMp() < needMana)
    {
        std::cout << " [ ������ �����մϴ�. ]" << std::endl;
        return false;
    }
    else
    {
        std::cout << " [ " << this->GetName() << "��(��) "
            << monster->GetName() << "���� �转 ���! (����: 1��) ]" << std::endl;

        monster->SetStunCnt(monster->GetStunCnt() + 1);

        dmg = mul * ((this->GetDmg() + this->GetDmgBuff())
            - (monster->GetDef() + monster->GetDefBuff()));
        if (dmg < 0) dmg = 0;

        this->SetMp(this->GetMp() - needMana);
        monster->HpShieldManager(dmg);
        this->TurnManager();

        return true;
    }

}
bool Knight::SkillB(Monster* monster)
{
    int dmg;
    int mul = 1;
    int needMana = 30;

    setColor(RED);
    if (this->GetMp() < needMana)
    {
        std::cout << " [ ������ �����մϴ�. ]" << std::endl;
        return false;
    }

    else
    {
        std::cout << " [ " << this->GetName()
            << "��(��) ��ü��ȭ ���! (���ݷ�+3, ����+3: 2��) ]" << std::endl;

        this->SetDmgBuff(this->GetDmgBuff() + 3);
        this->SetDmgBuffCnt(this->GetDmgBuffCnt() + 2);
        this->SetDefBuff(this->GetDefBuff() + 3);
        this->SetDefBuffCnt(this->GetDefBuffCnt() + 2);

        dmg = mul * ((this->GetDmg() + this->GetDmgBuff())
            - (monster->GetDef() + monster->GetDefBuff()));
        if (dmg < 0) dmg = 0;

        monster->HpShieldManager(dmg);
        this->SetMp(this->GetMp() - needMana);
        this->TurnManager();

        return true;
    }
}
bool Knight::SkillC(Monster* monster)
{
    int dmg;
    int mul = 5;
    int needMana = 50;

    setColor(RED);
    if (this->GetMp() < needMana)
    {
        std::cout << " [ ������ �����մϴ�. ]" << std::endl;
        return false;
    }

    else
    {
        std::cout << " [ " << this->GetName() << "��(��) "
            << monster->GetName() << "���� ���� ���!] " << std::endl;

        dmg = mul * ((this->GetDmg() + this->GetDmgBuff())
            - (monster->GetDef() + monster->GetDefBuff()));
        if (dmg < 0) dmg = 0;

        monster->HpShieldManager(dmg);
        this->SetMp(this->GetMp() - needMana);
        this->TurnManager();

        return true;
    }
}
