#include "Monster.h"
#include "Player.h"

// --------------------------------- CLASS
// --------------------------------- MONSTER

// ----------------------공격 함수
void Monster::Attack(Player* player)
{
    std::cout << "[ " << this->name << "이(가) "
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
    std::cout << "-------------------------------------" << std::endl;
    std::cout << "   Name: " << this->GetName() << std::endl;
    std::cout << "   HP: " << this->GetHp() << std::endl;
    std::cout << "   MP: " << this->GetMp() << std::endl;
    std::cout << "   DMG: " << this->GetDmg() << std::endl;
    std::cout << "   이동속도: " << this->GetMoveSpeed() << std::endl;
    if (this->GetAlive() == true)
        std::cout << "   상태: 생존" << std::endl;
    else if (this->GetAlive() == false)
        std::cout << "   상태: 사망" << std::endl;
    std::cout << "   속성: " << this->GetElement() << std::endl;
    std::cout << "-------------------------------------" << std::endl;

    return;
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