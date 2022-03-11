#include "Monster.h"
#include "Player.h"

// --------------------------------- CLASS
// --------------------------------- MONSTER

// ----------------------���� �Լ�
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

    std::cout << "[ " << this->GetName() << "��(��) "
        << player->GetName() << "���� �⺻ ����! ]" << std::endl;

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
        std::cout << "[ ������ �����մϴ�. ]" << std::endl;
        return false;
    }

    else
    {
        dmg = mul * this->GetDmg() - player->GetDef();

        if (dmg < 0) dmg = 0;

        std::cout << "[ " << this->GetName() << "��(��) "
            << player->GetName() << "���� ��ųA�� ���! ]" << std::endl;

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
        std::cout << "[ ������ �����մϴ�. ]" << std::endl;
        return false;
    }

    else
    {
        dmg = mul * this->GetDmg() - player->GetDef();

        if (dmg < 0) dmg = 0;

        std::cout << "[ " << this->GetName() << "��(��) "
            << player->GetName() << "���� ��ųB�� ���! ]" << std::endl;

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
        std::cout << "[ ������ �����մϴ�. ]" << std::endl;
        return false;
    }

    else
    {
        dmg = mul * this->GetDmg() - player->GetDef();

        if (dmg < 0) dmg = 0;

        std::cout << "[ " << this->GetName() << "��(��) "
            << player->GetName() << "���� ��ųC�� ���! ]" << std::endl;

        this->SetMp(this->GetMp() - needMana);
        player->HpShieldManager(dmg);
        this->TurnManager();

        return true;
    }
}

// ----------------------��� �Լ�
// ���
void Monster::PrintInfo()
{
    Character::PrintInfo();

    return;
}