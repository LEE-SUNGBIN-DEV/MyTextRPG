#include "Character.h"
#include <iostream>

void setColor(unsigned short text)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text);
}

// --------------------------------- CLASS
// --------------------------------- CHARACTER
// ��� �Լ�
void Character::Rebirth()
{
    setColor(YELLOW);
    this->SetAlive(true);
    std::cout << " [ " << this->GetName() << "��(��) ��Ȱ�Ͽ����ϴ�. ]" << std::endl;
}
void Character::Death()
{
    setColor(YELLOW);
    this->SetAlive(false);
    std::cout << " [ " << this->GetName() << "��(��) ����Ͽ����ϴ�. ]" << std::endl;
}
void Character::InitHp()
{
    this->SetHp(this->GetMaxHp());
    return;
}
void Character::InitMp()
{
    this->SetMp(this->GetMaxMp());
    return;
}

// ���� �Լ�
void Character::TurnManager()
{
    int turnValue = 1;

    // ��ȣ�� ��
    if (this->GetShieldCnt() > 0)
    {
        this->SetShieldCnt(this->GetShieldCnt() - turnValue);

        if (this->GetShieldCnt() == 0)
        {
            this->SetShield(0);
        }
    }

    // ���� ��
    if (this->GetStunCnt() > 0)
    {
        this->SetStunCnt(this->GetStunCnt() - turnValue);
    }

    // ���ݷ� ����
    if (this->GetDmgBuffCnt() > 0)
    {
        this->SetDmgBuffCnt(this->GetDmgBuffCnt() - turnValue);

        if (this->GetDmgBuffCnt() == 0)
        {
            this->SetDmgBuff(0);
        }
    }

    // ���� ����
    if (this->GetDefBuffCnt() > 0)
    {
        this->SetDefBuffCnt(this->GetDefBuffCnt() - turnValue);

        if (this->GetDefBuffCnt() == 0)
        {
            this->SetDefBuff(0);
        }
    }

    // ���� ȸ��
    if (this->GetMaxMp() - this->GetMp() > this->GetMpRecovery())
    {
        this->SetMp(this->GetMp() + this->GetMpRecovery());
    }

    // ü�� ȸ��
    if (this->GetMaxHp() - this->GetHp() > this->GetHpRecovery())
    {
        this->SetHp(this->GetHp() + this->GetHpRecovery());
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
    setColor(YELLOW);
    std::cout << "====================================" << std::endl;
    std::cout << " [ " << this->GetName() << " �������ͽ� ]" << std::endl;
    std::cout << "====================================" << std::endl;
    setColor(SKYBLUE);
    std::cout << " [ �г���: " << this->GetName() << " ]" << std::endl;
    std::cout << " [ HP: " << this->GetHp() << " ]" << std::endl;
    std::cout << " [ MP: " << this->GetMp() << " ]" << std::endl;
    std::cout << " [ ���ݷ�: " << this->GetDmg() << " ]" << std::endl;
    std::cout << " [ ����: " << this->GetDef() << " ]" << std::endl;
    std::cout << " [ ��ȣ��: " << this->GetShield() << " ]" << std::endl;
    if (this->GetAlive() == true)
        std::cout << " [ ����: ���� ]" << std::endl;
    else if (this->GetAlive() == false)
        std::cout << " [ ����: ��� ]" << std::endl;

    return;
}

// get
std::string Character::GetName() { return this->name; }
std::string Character::GetTitle() { return this->title; }
int Character::GetMaxHp() { return this->maxHp; }
int Character::GetMaxMp() { return this->maxMp; }
int Character::GetHp() { return this->hp; }
int Character::GetHpRecovery() { return this->hpRecovery; }
int Character::GetMp() { return this->mp; }
int Character::GetMpRecovery() { return this->mpRecovery; }
int Character::GetDmg() { return this->dmg; }
int Character::GetDef() { return this->def; }
int Character::GetShield() { return this->shield; }
int Character::GetShieldCnt() { return this->shieldCnt; }
int Character::GetStunCnt() { return this->stunCnt; }
int Character::GetDmgBuff() {return this->dmgBuff; }
int Character::GetDmgBuffCnt() { return this->dmgBuffCnt; }
int Character::GetDefBuff() { return this->defBuff; }
int Character::GetDefBuffCnt() { return this->defBuffCnt; }
bool Character::GetAlive() { return this->alive; }

// set
void Character::SetName(std::string _name)
{
    this->name = _name;
    return;
}
void Character::SetTitle(std::string _title)
{
    this->title = _title;
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
void Character::SetHpRecovery(int _hpRecovery)
{
    this->hpRecovery = _hpRecovery;
    return;
}
void Character::SetMp(int _mp)
{
    this->mp = _mp;
    return;
}
void Character::SetMpRecovery(int _mpRecovery)
{
    this->mpRecovery = _mpRecovery;
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
    this->shieldCnt = _cnt;
    return;
}
void Character::SetAlive(bool _alive)
{
    this->alive = _alive;
    return;
}
void Character::SetDmgBuff(int _dmgBuff)
{
    this->dmgBuff = _dmgBuff;
    return;
}
void Character::SetDmgBuffCnt(int _dmgBuffCnt)
{
    this->dmgBuffCnt = _dmgBuffCnt;
}
void Character::SetDefBuff(int _defBuff)
{
    this->defBuff = _defBuff;
    return;
}
void Character::SetDefBuffCnt(int _defBuffCnt)
{
    this->defBuffCnt = _defBuffCnt;
}
void Character::SetStunCnt(int _stunCnt)
{
    this->stunCnt = _stunCnt;
    return;
}