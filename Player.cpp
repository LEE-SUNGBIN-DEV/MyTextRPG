#include "Player.h"
#include "Monster.h"
#include "Item.h"

// --------------------------------- CLASS
// --------------------------------- PLAYER

// ----------------------���� �Լ�
void Player::Attack(Monster* monster)
{
    std::cout << "[ " << this->GetName() << "��(��) "
        << monster->GetName() << "���� �⺻ ����! ]" << std::endl;
    monster->SetHp(monster->GetHp() - this->GetDmg());
}
void Player::SkillA(Monster* monster)
{
    int mul = 2;

    std::cout << "[ " << this->GetName() << "��(��) "
        << monster->GetName() << "���� ��ųA ���! ]" << std::endl;

    monster->SetHp(monster->GetHp() - (this->GetDmg()*mul));
}
void Player::SkillB(Monster* monster)
{
    int mul = 3;

    std::cout << "[ " << this->GetName() << "��(��) "
        << monster->GetName() << "���� ��ųB ���! ]" << std::endl;

    monster->SetHp(monster->GetHp() - (this->GetDmg() * mul));
}
void Player::SkillC(Monster* monster)
{
    int mul = 4;

    std::cout << "[ " << this->GetName() << "��(��) "
        << monster->GetName() << "���� ��ųC ���!] " << std::endl;

    monster->SetHp(monster->GetHp() - (this->GetDmg() * mul));
}

// ----------------------��� �Լ�
// ���� ���
void Player::PrintInfo()
{
    Character::PrintInfo();
    std::cout << "[ ����: " << this->GetTypeName() << " ]" << std::endl;
    std::cout << "[ ���ݷ�: " << this->GetDmg() << " ]" << std::endl;
    std::cout << "[ ����: " << this->GetDef() << " ]" << std::endl;
    std::cout << "[ ������: " << this->GetMoney() << std::endl;
    std::cout << "[ ����ġ: " << this->GetExp() << " ]" << std::endl;

    return;
}
void Player::PrintUserInfo()
{
    std::cout << "==========================" << std::endl;
    std::cout << "���� : " << this->GetUserName() << std::endl;
    std::cout << "���� : " << this->GetUserAge() << std::endl;
    std::cout << "==========================" << std::endl;
}
void Player::PrintInventory()
{
    if (this->userInventory.size() == 0)
    {
        std::cout << "[ �κ��丮�� ������ϴ�. ]" << std::endl;
    }
    for (int i = 0; i < this->userInventory.size(); i++)
    {
        this->userInventory[i]->PrintItem(i);
    }
}

// ������ �߰�
void Player::AddItem(std::string _itemName)
{
    for (int i = 0; i < userInventory.size(); i++)
    {
        // �κ��� ���� �������� ������ ���
        if (userInventory[i]->GetItemName() == _itemName)
        {
            // ������ �߰�
            userInventory[i]->SetItemNum(userInventory[i]->GetItemNum() + 1);
            return;
        }
    }

    // �������� ���� ��� ���� �߰�
    this->userInventory.push_back(new Item(_itemName, 1));
    return;
}
void Player::AddItem(std::string _itemName, int _itemNum)
{
    for (int i = 0; i < userInventory.size(); i++)
    {
        // �κ��� ���� �������� ������ ���
        if (userInventory[i]->GetItemName() == _itemName)
        {
            // ������ �߰�
            userInventory[i]->SetItemNum(userInventory[i]->GetItemNum() + _itemNum);
            return;
        }
    }

    // �������� ���� ��� ���� �߰�
    this->userInventory.push_back(new Item(_itemName, _itemNum));
    return;
}

// ������ ����
void Player::RemoveItem(int _index) // �ε����� ����
{
    // 1�� �̻��� ���
    if (userInventory[_index]->GetItemNum() > 1)
    {
        userInventory[_index]->SetItemNum(userInventory[_index]->GetItemNum() - 1);
        return;
    }

    // 1�� �� ���
    else
    {
        userInventory.erase(userInventory.begin() + _index);
    }

    return;
}
void Player::RemoveItem(std::string _name)
{
    for (int i = 0; i < userInventory.size(); i++)
    {
        // ������ ���
        if (userInventory[i]->GetItemName() == _name)
        {
            // 1�� �̻��� ���
            if (userInventory[i]->GetItemNum() > 1)
            {
                userInventory[i]->SetItemNum(userInventory[i]->GetItemNum() - 1);
                return;
            }

            // 1�� �� ���
            else
            {
                userInventory.erase(userInventory.begin() + i);
            }
        }
    }

    return;
}
void Player::RemoveItem(std::string _name, int _itemNum)
{
    for (int i = 0; i < userInventory.size(); i++)
    {
        // ������ ���
        if (userInventory[i]->GetItemName() == _name)
        {
            // ���� ������ �������� �������� ������
            if (userInventory[i]->GetItemNum() <= _itemNum)
            {
                // ���� ������
                userInventory.erase(userInventory.begin() + i);
                return;
            }

            else
            {
                userInventory[i]->SetItemNum(userInventory[i]->GetItemNum() - _itemNum);
                return;
            }
            
        }
    }

    return;
}

int Player::SearchItem(std::string _name)
{
    for (int i = 0; i < this->userInventory.size(); i++)
    {
        if (this->userInventory[i]->GetItemName() == _name)
        {
            return i;
        }
    }

    return -1;
}
void Player::UseInventoryItem(int _index)
{
    if (this->userInventory[_index]->GetItemNum() > 0)
    {
        this->userInventory[_index]->UseItem();
        this->RemoveItem(_index);
    }
}

// Get
UserInfo Player::GetUserInfo() { return this->userInfo; }
std::vector<Item*> Player::GetInventory() { return this->userInventory; }
std::string Player::GetItemName(int i) { return this->userInventory[i]->GetItemName(); }
std::string Player::GetTypeName() { return this->typeName; }
std::string Player::GetUserName() { return this->userInfo.userName; }
int Player::GetDmg() { return this->dmg; }
int Player::GetExp() { return this->exp; }
int Player::GetUserAge() { return this->userInfo.userAge; }
int Player::GetItemNum(int i) { return this->userInventory[i]->GetItemNum(); }
int Player::GetDef() { return this->def; }
int Player::GetPlayerType() { return this->playerType; }
int Player::GetMoney() { return this->money; }

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
void Player::SetPlayerType(int _sel)
{
    this->playerType = _sel;
    return;
}

void Player::SetMoney(int _money)
{
    this->money = _money;
    return;
}