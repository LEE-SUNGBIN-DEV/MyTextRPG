#include "Player.h"
#include "Monster.h"
#include "Item.h"

// --------------------------------- CLASS
// --------------------------------- PLAYER

// ----------------------���� �Լ�
void Player::Attack(Monster* monster)
{
    std::cout << "==========================" << std::endl;
    std::cout << this->name << "��(��) "
        << monster->GetName() << "���� �⺻ ����!" << std::endl;
    std::cout << "==========================" << std:: endl;
    monster->SetHp(monster->GetHp() - this->GetDmg());
}
void Player::SkillA(Monster* monster)
{
    int mul = 2;
    std::cout << "==========================" << std::endl;
    std::cout << this->name << "��(��) "
        << monster->GetName() << "���� ��ųA�� ���!" << std::endl;
    std::cout << "==========================" << std::endl;

    monster->SetHp(monster->GetHp() - (this->GetDmg()*mul));
}
void Player::SkillB(Monster* monster)
{
    int mul = 3;

    std::cout << "==========================" << std::endl;
    std::cout << this->name << "��(��) "
        << monster->GetName() << "���� ��ųB�� ���!" << std::endl;
    std::cout << "==========================" << std::endl;

    monster->SetHp(monster->GetHp() - (this->GetDmg() * mul));
}
void Player::SkillC(Monster* monster)
{
    int mul = 4;
    std::cout << "==========================" << std::endl;
    std::cout << this->name << "��(��) "
        << monster->GetName() << "���� ��ųC�� ���!" << std::endl;
    std::cout << "==========================" << std::endl;

    monster->SetHp(monster->GetHp() - (this->GetDmg() * mul));
}

// ----------------------��� �Լ�
// ���� ���
void Player::PrintInfo()
{
    std::cout << "====================================" << std::endl;
    std::cout << "   �г���: " << this->GetName() << std::endl;
    std::cout << "   ����: " << this->GetTypeName() << std::endl;
    std::cout << "   HP: " << this->GetHp() << std::endl;
    std::cout << "   MP: " << this->GetMp() << std::endl;
    std::cout << "   ���ݷ�: " << this->GetDmg() << std::endl;
    std::cout << "   �̵��ӵ�: " << this->GetMoveSpeed() << std::endl;
    if (this->GetAlive() == true)
        std::cout << "   ����: ����" << std::endl;
    else if (this->GetAlive() == false)
        std::cout << "   ����: ���" << std::endl;
    std::cout << "   exp: " << this->GetExp() << std::endl;
    std::cout << "====================================" << std::endl;

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
    for (int i = 0; i < this->userInventory.size(); i++)
    {
        this->userInventory[i]->PrintItem();
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
}
void Player::UseInventoryItem(int _index)
{
    this->RemoveItem(_index);
    this->userInventory[_index]->UseItem();
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