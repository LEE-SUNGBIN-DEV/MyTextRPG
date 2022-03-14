#include "Knight.h"
#include "Monster.h"

// --------------------------------- CLASS
// --------------------------------- KNIGHT

// ----------------------공격 함수
bool Knight::Attack(Monster* monster)
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
bool Knight::SkillA(Monster* monster)
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
            << monster->GetName() << "에게 배쉬 사용! ]" << std::endl;
        std::cout << "[ 스턴(1턴) ]" << std::endl;

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
        std::cout << "[ 마나가 부족합니다. ]" << std::endl;
        return false;
    }

    else
    {
        this->SetDmgBuff(this->GetDmgBuff() + 5);
        this->SetDmgBuffCnt(this->GetDmgBuffCnt() + 2);

        dmg = mul * (this->GetDmg() + this->GetDmgBuff()) - monster->GetDef();

        if (dmg < 0) dmg = 0;

        std::cout << "[ " << this->GetName() << "이(가) 신체강화 사용! ]" << std::endl;
        std::cout << "[ 공격력 버프 +5 (2턴) ]" << std::endl;

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
        std::cout << "[ 마나가 부족합니다. ]" << std::endl;
        return false;
    }

    else
    {
        dmg = mul * (this->GetDmg() + this->GetDmgBuff()) - monster->GetDef();
        if (dmg < 0) dmg = 0;

        std::cout << "[ " << this->GetName() << "이(가) "
            << monster->GetName() << "에게 심판 사용!] " << std::endl;

        monster->HpShieldManager(dmg);
        this->SetMp(this->GetMp() - needMana);
        this->TurnManager();

        return true;
    }
}
