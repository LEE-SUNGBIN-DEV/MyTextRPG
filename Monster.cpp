#include <random>
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
    int mul = 1;

    setColor(BLUE);
    std::cout << "[ " << this->GetName() << "��(��) "
        << player->GetName() << "���� �⺻ ����! ]" << std::endl;

    dmg = mul * (this->GetDmg() + this->GetDmgBuff()) - player->GetDef();
    if (dmg < 0) dmg = 0;

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
        setColor(BLUE);
        std::cout << "[ ������ �����մϴ�. ]" << std::endl;
        return false;
    }

    else
    {
        setColor(BLUE);
        std::cout << "[ " << this->GetName() << "��(��) "
            << player->GetName() << "���� ��ųA�� ���! ]" << std::endl;

        dmg = mul * (this->GetDmg() + this->GetDmgBuff()) - player->GetDef();
        if (dmg < 0) dmg = 0;

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
        setColor(BLUE);
        std::cout << "[ ������ �����մϴ�. ]" << std::endl;
        return false;
    }

    else
    {
        setColor(BLUE);
        std::cout << "[ " << this->GetName() << "��(��) "
            << player->GetName() << "���� ��ųB�� ���! ]" << std::endl;

        dmg = mul * (this->GetDmg() + this->GetDmgBuff()) - player->GetDef();
        if (dmg < 0) dmg = 0;

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
        setColor(BLUE);
        std::cout << "[ ������ �����մϴ�. ]" << std::endl;
        return false;
    }

    else
    {
        setColor(BLUE);
        std::cout << "[ " << this->GetName() << "��(��) "
            << player->GetName() << "���� ��ųC�� ���! ]" << std::endl;

        dmg = mul * (this->GetDmg() + this->GetDmgBuff()) - player->GetDef();
        if (dmg < 0) dmg = 0;

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

void Monster::DropItem(Player* player)
{
    player->SetGold(player->GetGold() + this->GetDropGold());
}

// get
int Monster::GetDropGold()
{
    return this->dropGold;
}

// set
void Monster::SetDropGold(int _dropGold)
{
    this->dropGold = _dropGold;
}