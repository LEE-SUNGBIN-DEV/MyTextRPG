#include "Knight.h"
#include "Monster.h"

// --------------------------------- CLASS
// --------------------------------- KNIGHT

// ----------------------���� �Լ�
bool Knight::Attack(Monster* monster)
{
    int dmg;
    int mul = 1;

    dmg = mul * (this->GetDmg() + this->GetDmgBuff()) - monster->GetDef();
    if (dmg < 0) dmg = 0;

    std::cout << "[ " << this->GetName() << "��(��) "
        << monster->GetName() << "���� �⺻ ����! ]" << std::endl;

    monster->HpShieldManager(dmg);
    this->TurnManager();

    return true;
}
bool Knight::SkillA(Monster* monster)
{
    int dmg;
    int mul = 2;
    int needMana = 20;

    if (this->GetMp() < needMana)
    {
        std::cout << "[ ������ �����մϴ�. ]" << std::endl;
        return false;
    }
    else
    {
        dmg = mul * (this->GetDmg() + this->GetDmgBuff()) - monster->GetDef();
        if (dmg < 0) dmg = 0;

        std::cout << "[ " << this->GetName() << "��(��) "
            << monster->GetName() << "���� �转 ���! ]" << std::endl;
        std::cout << "[ ����(1��) ]" << std::endl;

        monster->SetStunCnt(1);
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

    if (this->GetMp() < needMana)
    {
        std::cout << "[ ������ �����մϴ�. ]" << std::endl;
        return false;
    }

    else
    {
        this->SetDmgBuff(this->GetDmgBuff() + 5);
        this->SetDmgBuffCnt(this->GetDmgBuffCnt() + 2);

        dmg = mul * (this->GetDmg() + this->GetDmgBuff()) - monster->GetDef();

        if (dmg < 0) dmg = 0;

        std::cout << "[ " << this->GetName() << "��(��) ��ü��ȭ ���! ]" << std::endl;
        std::cout << "[ ���ݷ� ���� +5 (2��) ]" << std::endl;

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

    if (this->GetMp() < needMana)
    {
        std::cout << "[ ������ �����մϴ�. ]" << std::endl;
        return false;
    }

    else
    {
        dmg = mul * (this->GetDmg() + this->GetDmgBuff()) - monster->GetDef();
        if (dmg < 0) dmg = 0;

        std::cout << "[ " << this->GetName() << "��(��) "
            << monster->GetName() << "���� ���� ���!] " << std::endl;

        monster->HpShieldManager(dmg);
        this->SetMp(this->GetMp() - needMana);
        this->TurnManager();

        return true;
    }
}
