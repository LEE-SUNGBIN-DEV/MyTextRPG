#include "Monster.h"
#include "Player.h"

// --------------------------------- CLASS
// --------------------------------- MONSTER

// ----------------------공격 함수
void Monster::RandomAttack(Player* player)
{
    int randNum;
    std::random_device rd;

    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(0, 99);

    randNum = dis(gen);

    if (randNum > 90)
    {
        this->SkillC(player);
    }
    else if (randNum > 75 && randNum <= 90)
    {
        this->SkillB(player);
    }
    else if (randNum > 60 && randNum <= 75)
    {
        this->SkillA(player);
    }
    else
    {
        this->Attack(player);
    }
}
bool Monster::Attack(Player* player)
{
    int dmg;

    dmg = this->GetDmg() - player->GetDef();

    if (dmg < 0) dmg = 0;

    std::cout << "[ " << this->GetName() << "이(가) "
        << player->GetName() << "에게 기본 공격! ]" << std::endl;

    player->HpShieldManager(dmg);
    this->TurnManager();

    return true;
}
bool Monster::SkillA(Player* player)
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
        dmg = mul * this->GetDmg() - player->GetDef();

        if (dmg < 0) dmg = 0;

        std::cout << "[ " << this->GetName() << "이(가) "
            << player->GetName() << "에게 스킬A를 사용! ]" << std::endl;

        this->SetMp(this->GetMp() - needMana);
        player->HpShieldManager(dmg);
        this->TurnManager();

        return true;
    }
}
bool Monster::SkillB(Player* player)
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
        dmg = mul * this->GetDmg() - player->GetDef();

        if (dmg < 0) dmg = 0;

        std::cout << "[ " << this->GetName() << "이(가) "
            << player->GetName() << "에게 스킬B를 사용! ]" << std::endl;

        this->SetMp(this->GetMp() - needMana);
        player->HpShieldManager(dmg);
        this->TurnManager();

        return true;
    }
}
bool Monster::SkillC(Player* player)
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
        dmg = mul * this->GetDmg() - player->GetDef();

        if (dmg < 0) dmg = 0;

        std::cout << "[ " << this->GetName() << "이(가) "
            << player->GetName() << "에게 스킬C를 사용! ]" << std::endl;

        this->SetMp(this->GetMp() - needMana);
        player->HpShieldManager(dmg);
        this->TurnManager();

        return true;
    }
}

// ----------------------기능 함수
// 출력
void Monster::PrintInfo()
{
    Character::PrintInfo();

    return;
}