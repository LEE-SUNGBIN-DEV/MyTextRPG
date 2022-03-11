#include "Character.h"

// --------------------------------- CLASS
// --------------------------------- CHARACTER
// ��� �Լ�
void Character::Rebirth()
{
    this->SetAlive(true);
    std::cout << "[ " << this->GetName() << "��(��) ��Ȱ�Ͽ����ϴ�. ]" << std::endl;
}
void Character::Death()
{
    this->SetAlive(false);
    std::cout << "[ " << this->GetName() << "��(��) ����Ͽ����ϴ�. ]" << std::endl;
}
void Character::FreeMemory()
{
    delete(this);
}

// ���� �Լ�
void Character::TurnManager()
{
    int manaRecovery = 5;

    // ��ȣ�� ��
    if (this->GetShieldCnt() > 0)
    {
        this->SetShieldCnt(this->GetShieldCnt() - 1);

        if (this->GetShieldCnt() == 0)
        {
            this->SetShield(0);
        }
    }

    // ���� ȸ��
    if (this->GetMaxMp() - this->GetMp() > manaRecovery)
    {
        this->SetMp(this->GetMp() + manaRecovery);
    }

    return;
}
void Character::HpShieldManager(int _dmg)
{
    if (_dmg > 0)
    {
        if (this->GetShield() > 0)
        {
            this->SetShield(this->GetShield() - _dmg);

            if (this->GetShield() < 0)
            {
                this->SetHp(this->GetHp() + this->GetShield());
                this->SetShield(0);
                this->SetShieldCnt(0);
            }
        }
        else
        {
            this->SetHp(this->GetHp() - _dmg);
        }
    }
}

// ĳ���� ���� ���
void Character::PrintInfo()
{
    std::cout << "====================================" << std::endl;
    std::cout << "[ " << this->GetName() << "�� ���� ]" << std::endl;
    std::cout << "====================================" << std::endl;
    std::cout << "[ �г���: " << this->GetName() << " ]" << std::endl;
    std::cout << "[ HP: " << this->GetHp() << " ]" << std::endl;
    std::cout << "[ MP: " << this->GetMp() << " ]" << std::endl;
    std::cout << "[ ���ݷ�: " << this->GetDmg() << " ]" << std::endl;
    std::cout << "[ ����: " << this->GetDef() << " ]" << std::endl;
    std::cout << "[ ��ȣ��: " << this->GetShield() << " ]" << std::endl;
    if (this->GetAlive() == true)
        std::cout << "[ ����: ���� ]" << std::endl;
    else if (this->GetAlive() == false)
        std::cout << "[ ����: ��� ]" << std::endl;

    return;
}

// Get Info
std::string Character::GetName() { return this->name; }
int Character::GetMaxHp() { return this->maxHp; }
int Character::GetMaxMp() { return this->maxMp; }
int Character::GetHp() { return this->hp; }
int Character::GetMp() { return this->mp; }
int Character::GetDmg() { return this->dmg; }
int Character::GetDef() { return this->def; }
int Character::GetShield() { return this->shield; }
int Character::GetShieldCnt() { return this->shieldTurn; }
bool Character::GetAlive() { return this->alive; }

// Set Info
void Character::SetName(std::string _name)
{
    this->name = _name;
    return;
}
void Character::SetMaxHp(int _maxHp)
{
    this->maxHp = _maxHp;
    return;
}
void Character::SetMaxMp(int _maxMp)
{
    this->maxMp = _maxMp;
    return;
}
void Character::SetHp(int _hp)
{
    this->hp = _hp;

    if (this->hp <= 0)
        Death();

    return;
}
void Character::SetMp(int _mp)
{
    this->mp = _mp;
    return;
}
void Character::SetDmg(int _dmg)
{
    this->dmg = _dmg;
    return;
}
void Character::SetDef(int _def)
{
    this->def = _def;
    return;
}
void Character::SetShield(int _shield)
{
    this->shield = _shield;
    return;
}
void Character::SetShieldCnt(int _cnt)
{
    this->shieldTurn = _cnt;
    return;
}
void Character::SetAlive(bool _alive)
{
    this->alive = _alive;
    return;
}