#include "Monster.h"
#include "Player.h"
#include "Character.h"

// --------------------------------- CLASS
// --------------------------------- MONSTER

    // ��� �Լ�
void Monster::PrintInfo()
{
    std::cout << "-------------------------------------" << std::endl;
    std::cout << "   Name: " << this->name << std::endl;
    std::cout << "   HP: " << this->hp << std::endl;
    std::cout << "   MP: " << this->mp << std::endl;
    std::cout << "   DMG: " << this->dmg << std::endl;
    std::cout << "   �̵��ӵ�: " << this->moveSpeed << std::endl;
    if (this->alive == true)
        std::cout << "   ����: ����" << std::endl;
    else if (this->alive == false)
        std::cout << "   ����: ���" << std::endl;
    std::cout << "   �Ӽ�: " << this->element << std::endl;
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