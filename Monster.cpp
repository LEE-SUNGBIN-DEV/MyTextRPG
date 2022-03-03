#include "Monster.h"
#include "Player.h"
#include "Character.h"

// --------------------------------- CLASS
// --------------------------------- MONSTER

    // 기능 함수
void Monster::PrintInfo()
{
    std::cout << "-------------------------------------" << std::endl;
    std::cout << "   Name: " << this->name << std::endl;
    std::cout << "   HP: " << this->hp << std::endl;
    std::cout << "   MP: " << this->mp << std::endl;
    std::cout << "   DMG: " << this->dmg << std::endl;
    std::cout << "   이동속도: " << this->moveSpeed << std::endl;
    if (this->alive == true)
        std::cout << "   상태: 생존" << std::endl;
    else if (this->alive == false)
        std::cout << "   상태: 사망" << std::endl;
    std::cout << "   속성: " << this->element << std::endl;
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