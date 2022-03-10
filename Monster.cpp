#include "Monster.h"
#include "Player.h"

// --------------------------------- CLASS
// --------------------------------- MONSTER

// ----------------------공격 함수
void Monster::Attack(Player* player)
{
    std::cout << "[ " << this->GetName() << "이(가) "
        << player->GetName() << "에게 기본 공격! ]" << std::endl;

    player->SetHp(player->GetHp() - this->GetDmg());
}
void Monster::SkillA(Player* player)
{
    int mul = 2;

    player->SetHp(player->GetHp() - (this->GetDmg() * mul));
}
void Monster::SkillB(Player* player)
{
    int mul = 3;

    player->SetHp(player->GetHp() - (this->GetDmg() * mul));
}
void Monster::SkillC(Player* player)
{
    int mul = 4;

    player->SetHp(player->GetHp() - (this->GetDmg() * mul));
}

// ----------------------기능 함수
// 출력
void Monster::PrintInfo()
{
    Character::PrintInfo();
    std::cout << "[ 속성: " << this->GetElement() << " ]" << std::endl;
    std::cout << "[ 공격력: " << this->GetDmg() << " ]" << std::endl;

    return;
}

void Monster::Death(Player* player)
{
    this->SetAlive(false);
    player->SetMoney(player->GetMoney());
    std::cout << "[ " << this->GetName() << "이(가) 사망하였습니다. ]" << std::endl;
}

// Get Info
std::string Monster::GetElement() { return this->element; }
int Monster::GetDmg() { return this->dmg; }


// Set Info
void Monster::SetElement(std::string _element)
{
    this->element = _element;
    return;
}
void Monster::SetDmg(int _dmg)
{
    this->dmg = _dmg;
    return;
}