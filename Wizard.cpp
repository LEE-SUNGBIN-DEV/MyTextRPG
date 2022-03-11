#include "Wizard.h"
#include "Monster.h"

// --------------------------------- CLASS
// --------------------------------- WIZARD

// ----------------------공격 함수
bool Wizard::Attack(Monster* monster)
{
    int dmg;

    dmg = this->GetDmg() - monster->GetDef();
    if (dmg < 0) dmg = 0;

    std::cout << "[ " << this->GetName() << "이(가) "
        << monster->GetName() << "에게 기본 공격! ]" << std::endl;

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
        std::cout << "[ 마나가 부족합니다. ]" << std::endl;
        return false;
    }
    else
    {
        dmg = mul * this->GetDmg() - monster->GetDef();
        if (dmg < 0) dmg = 0;

        std::cout << "[ " << this->GetName() << "이(가) "
            << monster->GetName() << "에게 스킬A 사용! ]" << std::endl;

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
        std::cout << "[ 마나가 부족합니다. ]" << std::endl;
        return false;
    }

    else
    {
        dmg = mul * this->GetDmg() - monster->GetDef();
        if (dmg < 0) dmg = 0;

        std::cout << "[ " << this->GetName() << "이(가) "
            << monster->GetName() << "에게 스킬B 사용! ]" << std::endl;

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
        std::cout << "[ 마나가 부족합니다. ]" << std::endl;
        return false;
    }

    else
    {
        dmg = mul * this->GetDmg() - monster->GetDef();
        if (dmg < 0) dmg = 0;

        std::cout << "[ " << this->GetName() << "이(가) "
            << monster->GetName() << "에게 스킬C 사용!] " << std::endl;

        monster->HpShieldManager(dmg);
        this->SetMp(this->GetMp() - needMana);
        this->TurnManager();

        return true;
    }
}
