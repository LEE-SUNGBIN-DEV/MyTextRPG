#include "Wizard.h"
#include "Monster.h"

// --------------------------------- CLASS
// --------------------------------- WIZARD

// ----------------------공격 함수
bool Wizard::Attack(Monster* monster)
{
    int dmg;
    int mul = 1;

    dmg = mul * (this->GetDmg() + this->GetDmgBuff()) - monster->GetDef();
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
        dmg = mul * (this->GetDmg() + this->GetDmgBuff()) - monster->GetDef();
        if (dmg < 0) dmg = 0;

        std::cout << "[ " << this->GetName() << "이(가) "
            << monster->GetName() << "에게 파이어 볼 사용! ]" << std::endl;

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

    if (this->GetMp() < needMana)
    {
        std::cout << "[ 마나가 부족합니다. ]" << std::endl;
        return false;
    }

    else
    {
        this->SetDmgBuff(this->GetDmgBuff() + 5);
        this->SetDmgBuffCnt(this->GetDmgBuffCnt() + 2);

        dmg = mul * (this->GetDmg() + this->GetDmgBuff()) - monster->GetDef();

        if (dmg < 0) dmg = 0;

        std::cout << "[ " << this->GetName() << "이(가) "
            << monster->GetName() << "에게 아이스 스피어 사용! ]" << std::endl;
        std::cout << "[ 빙결(2턴) ]" << std::endl;

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

    if (this->GetMp() < needMana)
    {
        std::cout << "[ 마나가 부족합니다. ]" << std::endl;
        return false;
    }

    else
    {
        dmg = mul * (this->GetDmg() + this->GetDmgBuff()) - monster->GetDef();
        if (dmg < 0) dmg = 0;

        std::cout << "[ " << this->GetName() << "이(가) "
            << monster->GetName() << "에게 메테오 사용!] " << std::endl;

        monster->HpShieldManager(dmg);
        this->SetMp(this->GetMp() - needMana);
        this->TurnManager();

        return true;
    }
}

