#include "Character.h"

// --------------------------------- CLASS
// --------------------------------- CHARACTER
// 기능 함수
void Character::Rebirth()
{
    this->SetAlive(true);
    std::cout << "[ " << this->GetName() << "이(가) 부활하였습니다. ]" << std::endl;
}

void Character::Death()
{
    this->SetAlive(false);
    std::cout << "[ " << this->GetName() << "이(가) 사망하였습니다. ]" << std::endl;
}

void Character::FreeMemory()
{
    delete(this);
}

// 캐릭터 정보 출력
void Character::PrintInfo()
{
    std::cout << "====================================" << std::endl;
    std::cout << "[ " << this->GetName() << "의 정보 ]" << std::endl;
    std::cout << "====================================" << std::endl;
    std::cout << "[ 닉네임: " << this->GetName() << " ]" << std::endl;
    std::cout << "[ HP: " << this->GetHp() << " ]" << std::endl;
    std::cout << "[ MP: " << this->GetMp() << " ]" << std::endl;
    if (this->GetAlive() == true)
        std::cout << "[ 상태: 생존 ]" << std::endl;
    else if (this->GetAlive() == false)
        std::cout << "[ 상태: 사망 ]" << std::endl;

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