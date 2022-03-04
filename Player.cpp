#include "Monster.h"
#include "Player.h"
#include "Character.h"
#include "Item.h"

// --------------------------------- CLASS
// --------------------------------- PLAYER

// 공격 함수
void Player::Attack(Monster* monster)
{
    monster->SetHp(monster->GetHp() - this->GetDmg());
}
void Player::QSkill(Monster* monster)
{
    int mul = 2;

    monster->SetHp(monster->GetHp() - (this->GetDmg()*mul));
}
void Player::WShill(Monster* monster)
{

}
void Player::ESkill(Monster* monster)
{

}
void Player::RSkill(Monster* monster)
{

}

// 기능 함수
void Player::PrintInfo()
{
    std::cout << "-------------------------------------" << std::endl;
    std::cout << "   Name: " << this->GetName() << std::endl;
    std::cout << "   HP: " << this->GetHp() << std::endl;
    std::cout << "   MP: " << this->GetMp() << std::endl;
    std::cout << "   DMG: " << this->GetDmg() << std::endl;
    std::cout << "   이동속도: " << this->GetMoveSpeed() << std::endl;
    if (this->GetAlive() == true)
        std::cout << "   상태: 생존" << std::endl;
    else if (this->GetAlive() == false)
        std::cout << "   상태: 사망" << std::endl;
    std::cout << "   exp: " << this->GetExp() << std::endl;
    std::cout << "   userAge: " << this->GetUserAge() << std::endl;
    std::cout << "-------------------------------------" << std::endl;

    return;
}

void Player::AddItem(std::string _itemName, int _itemNum)
{
    for (int i = 0; i < userInventory.size(); i++)
    {
        // 인벤에 같은 아이템이 존재할 경우
        if (userInventory[i].GetItemName() == _itemName)
        {
            // 수량만 추가
            userInventory[i].SetItemNum(userInventory[i].GetItemNum() + _itemNum);
            return;
        }
    }

    // 존재하지 않을 경우 새로 추가
    this->userInventory.push_back(Item(_itemName, _itemNum));
    return;
}

// Get
UserInfo Player::GetUserInfo() { return this->userInfo; }
std::vector<Item> Player::GetInventory() { return this->userInventory; }
std::string Player::GetItemName(int i) { return this->userInventory[i].GetItemName(); }
std::string Player::GetClassName() { return this->className; }
std::string Player::GetUserName() { return this->userInfo.userName; }
int Player::GetDmg() { return this->dmg; }
int Player::GetExp() { return this->exp; }
int Player::GetUserAge() { return this->userInfo.userAge; }
int Player::GetItemNum(int i) { return this->userInventory[i].GetItemNum(); }
int Player::GetDef() { return this->def; }
int Player::GetPlayerClass() { return this->playerClass; }

// Set Info
void Player::SetUserInfo(std::string _name, int _age)
{
    this->userInfo.userName = _name;
    this->userInfo.userAge = _age;
}
void Player::SetDmg(int _dmg)
{
    this->dmg = _dmg;
    return;
}
void Player::SetExp(int _exp)
{
    this->exp = _exp;
    return;
}
void Player::SetDef(int _def)
{
    this->def = _def;
    return;
}
void Player::SetPlayerClass(int _sel)
{
    this->playerClass = _sel;
    return;
}