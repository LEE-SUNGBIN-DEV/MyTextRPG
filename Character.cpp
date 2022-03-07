#include "Character.h"

// --------------------------------- CLASS
// --------------------------------- CHARACTER
// ��� �Լ�
void Character::Rebirth()
{
    this->alive = true;
    std::cout << this->name << "��(��) ��Ȱ�Ͽ����ϴ�." << std::endl;
}

void Character::Death()
{
    this->alive = false;
    std::cout << this->name << "��(��) ����Ͽ����ϴ�." << std::endl;
}

void Character::FreeMemory()
{
    delete(this);
}

// ĳ���� ���� ���
void Character::PrintInfo()
{
    std::cout << "-------------------------------------" << std::endl;
    std::cout << "   Name: " << this->name << std::endl;
    std::cout << "   HP: " << this->hp << std::endl;
    std::cout << "   MP: " << this->mp << std::endl;
    std::cout << "   �̵��ӵ�: " << this->moveSpeed << std::endl;
    if (this->alive == true)
        std::cout << "   ����: ����" << std::endl;
    else if (this->alive == false)
        std::cout << "   ����: ���" << std::endl;
    std::cout << "-------------------------------------" << std::endl;

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
}