#include "Monster.h"
#include "Player.h"

// --------------------------------- CLASS
// --------------------------------- MONSTER

// ----------------------���� �Լ�
void Monster::Attack(Player* player)
{
    std::cout << "[ " << this->GetName() << "��(��) "
        << player->GetName() << "���� �⺻ ����! ]" << std::endl;

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

// ----------------------��� �Լ�
// ���
void Monster::PrintInfo()
{
    Character::PrintInfo();
    std::cout << "[ �Ӽ�: " << this->GetElement() << " ]" << std::endl;
    std::cout << "[ ���ݷ�: " << this->GetDmg() << " ]" << std::endl;

    return;
}

void Monster::Death(Player* player)
{
    this->SetAlive(false);
    player->SetMoney(player->GetMoney());
    std::cout << "[ " << this->GetName() << "��(��) ����Ͽ����ϴ�. ]" << std::endl;
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