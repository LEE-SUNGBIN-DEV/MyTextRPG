#include "Monster.h"
#include "Player.h"
#include "Character.h"


// --------------------------------- CLASS
// --------------------------------- MONSTER

// ��� �Լ�
void Monster::PrintInfo()
{
    std::cout << "-------------------------------------" << std::endl;
    std::cout << "   Name: " << this->GetName() << std::endl;
    std::cout << "   HP: " << this->GetHp() << std::endl;
    std::cout << "   MP: " << this->GetMp() << std::endl;
    std::cout << "   DMG: " << this->GetDmg() << std::endl;
    std::cout << "   �̵��ӵ�: " << this->GetMoveSpeed() << std::endl;
    if (this->GetAlive() == true)
        std::cout << "   ����: ����" << std::endl;
    else if (this->GetAlive() == false)
        std::cout << "   ����: ���" << std::endl;
    std::cout << "   �Ӽ�: " << this->GetElement() << std::endl;
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