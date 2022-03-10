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

// ĳ���� ���� ���
void Character::PrintInfo()
{
    std::cout << "====================================" << std::endl;
    std::cout << "[ " << this->GetName() << "�� ���� ]" << std::endl;
    std::cout << "====================================" << std::endl;
    std::cout << "[ �г���: " << this->GetName() << " ]" << std::endl;
    std::cout << "[ HP: " << this->GetHp() << " ]" << std::endl;
    std::cout << "[ MP: " << this->GetMp() << " ]" << std::endl;
    if (this->GetAlive() == true)
        std::cout << "[ ����: ���� ]" << std::endl;
    else if (this->GetAlive() == false)
        std::cout << "[ ����: ��� ]" << std::endl;

    return;
}

// Get Info
std::string Character::GetName() { return this->name; }
int Character::GetHp() { return this->hp; }
int Character::GetMp() { return this->mp; }
float Character::GetMoveSpeed() { return this->moveSpeed; }
bool Character::GetAlive() { return this->alive; }

// Set Info
void Character::SetName(std::string _name)
{
    this->name = _name;
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
void Character::SetMoveSpeed(float _moveSpeed)
{
    this->moveSpeed = _moveSpeed;
    return;
}

void Character::SetAlive(bool _alive)
{
    this->alive = _alive;
    return;
}