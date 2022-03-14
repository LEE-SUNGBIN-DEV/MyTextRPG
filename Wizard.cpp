#include "Wizard.h"
#include "Monster.h"

// --------------------------------- CLASS
// --------------------------------- WIZARD

// ----------------------���� �Լ�
bool Wizard::Attack(Monster* monster)
{
    int dmg;
    int mul = 1;

    setColor(RED);
    std::cout << "[ " << this->GetName() << "��(��) "
        << monster->GetName() << "���� �⺻ ����! ]" << std::endl;

    dmg = mul * (this->GetDmg() + this->GetDmgBuff()) - monster->GetDef();
    if (dmg < 0) dmg = 0;

    monster->HpShieldManager(dmg);
    this->TurnManager();

    return true;
}
bool Wizard::SkillA(Monster* monster)
{
    int dmg;
    int mul = 2;
    int needMana = 20;

    setColor(RED);
    if (this->GetMp() < needMana)
    {
        std::cout << "[ ������ �����մϴ�. ]" << std::endl;
        return false;
    }
    else
    {
        std::cout << "[ " << this->GetName() << "��(��) "
            << monster->GetName() << "���� ���̾� �� ���! ]" << std::endl;

        dmg = mul * (this->GetDmg() + this->GetDmgBuff()) - monster->GetDef();
        if (dmg < 0) dmg = 0;

        this->SetMp(this->GetMp() - needMana);
        monster->HpShieldManager(dmg);
        this->TurnManager();

        return true;
    }

}
bool Wizard::SkillB(Monster* monster)
{
    int dmg;
    int mul = 1;
    int needMana = 30;

    setColor(RED);
    if (this->GetMp() < needMana)
    {
        std::cout << "[ ������ �����մϴ�. ]" << std::endl;
        return false;
    }

    else
    {
        std::cout << "[ " << this->GetName() << "��(��) "
            << monster->GetName() << "���� ���̽� ���Ǿ� ���! (����: 2��) ]" << std::endl;

        dmg = mul * (this->GetDmg() + this->GetDmgBuff()) - monster->GetDef();
        if (dmg < 0) dmg = 0;

        monster->SetStunCnt(2);
        monster->HpShieldManager(dmg);
        this->SetMp(this->GetMp() - needMana);
        this->TurnManager();

        return true;
    }
}
bool Wizard::SkillC(Monster* monster)
{
    int dmg;
    int mul = 5;
    int needMana = 50;

    setColor(RED);
    if (this->GetMp() < needMana)
    {
        std::cout << "[ ������ �����մϴ�. ]" << std::endl;
        return false;
    }

    else
    {
        std::cout << "[ " << this->GetName() << "��(��) "
            << monster->GetName() << "���� ���׿� ���!] " << std::endl;

        dmg = mul * (this->GetDmg() + this->GetDmgBuff()) - monster->GetDef();
        if (dmg < 0) dmg = 0;

        monster->HpShieldManager(dmg);
        this->SetMp(this->GetMp() - needMana);
        this->TurnManager();

        return true;
    }
}

