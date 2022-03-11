#include "Wizard.h"
#include "Monster.h"

// --------------------------------- CLASS
// --------------------------------- WIZARD

// ----------------------���� �Լ�
bool Wizard::Attack(Monster* monster)
{
    int dmg;

    dmg = this->GetDmg() - monster->GetDef();
    if (dmg < 0) dmg = 0;

    std::cout << "[ " << this->GetName() << "��(��) "
        << monster->GetName() << "���� �⺻ ����! ]" << std::endl;

    monster->HpShieldManager(dmg);
    this->TurnManager();

    return true;
}
bool Wizard::SkillA(Monster* monster)
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
        dmg = mul * this->GetDmg() - monster->GetDef();
        if (dmg < 0) dmg = 0;

        std::cout << "[ " << this->GetName() << "��(��) "
            << monster->GetName() << "���� ��ųA ���! ]" << std::endl;

        this->SetMp(this->GetMp() - needMana);
        monster->HpShieldManager(dmg);
        this->TurnManager();

        return true;
    }

}
bool Wizard::SkillB(Monster* monster)
{
    int dmg;
    int mul = 3;
    int needMana = 30;

    if (this->GetMp() < needMana)
    {
        std::cout << "[ ������ �����մϴ�. ]" << std::endl;
        return false;
    }

    else
    {
        dmg = mul * this->GetDmg() - monster->GetDef();
        if (dmg < 0) dmg = 0;

        std::cout << "[ " << this->GetName() << "��(��) "
            << monster->GetName() << "���� ��ųB ���! ]" << std::endl;

        monster->HpShieldManager(dmg);
        this->SetMp(this->GetMp() - needMana);
        this->TurnManager();

        return true;
    }
}
bool Wizard::SkillC(Monster* monster)
{
    int dmg;
    int mul = 4;
    int needMana = 50;

    if (this->GetMp() < needMana)
    {
        std::cout << "[ ������ �����մϴ�. ]" << std::endl;
        return false;
    }

    else
    {
        dmg = mul * this->GetDmg() - monster->GetDef();
        if (dmg < 0) dmg = 0;

        std::cout << "[ " << this->GetName() << "��(��) "
            << monster->GetName() << "���� ��ųC ���!] " << std::endl;

        monster->HpShieldManager(dmg);
        this->SetMp(this->GetMp() - needMana);
        this->TurnManager();

        return true;
    }
}
