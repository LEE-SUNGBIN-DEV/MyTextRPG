#include "Player.h"
#include "Monster.h"
#include "Item.h"

// --------------------------------- CLASS
// --------------------------------- PLAYER

// ----------------------���� �Լ�
bool Player::Attack(Monster* monster)
{
    int dmg;
    int mul = 1;

    setColor(RED);
    std::cout << "[ " << this->GetName() << "��(��) "
        << monster->GetName() << "���� �⺻ ����! ]" << std::endl;

    dmg = mul * (this->GetDmg() + this->GetDmgBuff()) - monster->GetDef();
    if (dmg < 0) dmg = 0;

    monster->HpShieldManager(dmg);
    this->TurnManager();

    return true;
}
bool Player::SkillA(Monster* monster)
{
    int dmg;
    int mul = 2;
    int needMana = 20;

    setColor(RED);
    if (this->GetMp() < needMana)
    {
        std::cout << "[ ������ �����մϴ�. ]" << std::endl;
        return false;
    }
    else
    {
        std::cout << "[ " << this->GetName() << "��(��) "
            << monster->GetName() << "���� ��ųA ���! ]" << std::endl;

        dmg = mul * (this->GetDmg() + this->GetDmgBuff()) - monster->GetDef();
        if (dmg < 0) dmg = 0;

        this->SetMp(this->GetMp() - needMana);
        monster->HpShieldManager(dmg);
        this->TurnManager();

        return true;
    }
    
}
bool Player::SkillB(Monster* monster)
{
    int dmg;
    int mul = 3;
    int needMana = 30;

    setColor(RED);
    if (this->GetMp() < needMana)
    {
        std::cout << "[ ������ �����մϴ�. ]" << std::endl;
        return false;
    }

    else
    {
        std::cout << "[ " << this->GetName() << "��(��) "
            << monster->GetName() << "���� ��ųB ���! ]" << std::endl;

        dmg = mul * (this->GetDmg() + this->GetDmgBuff()) - monster->GetDef();
        if (dmg < 0) dmg = 0;

        monster->HpShieldManager(dmg);
        this->SetMp(this->GetMp() - needMana);
        this->TurnManager();

        return true;
    }
}
bool Player::SkillC(Monster* monster)
{
    int dmg;
    int mul = 4;
    int needMana = 50;

    setColor(RED);
    if (this->GetMp() < needMana)
    {
        std::cout << "[ ������ �����մϴ�. ]" << std::endl;
        return false;
    }

    else
    {
        std::cout << "[ " << this->GetName() << "��(��) "
            << monster->GetName() << "���� ��ųC ���!] " << std::endl;

        dmg = mul * (this->GetDmg() + this->GetDmgBuff()) - monster->GetDef();
        if (dmg < 0) dmg = 0;

        monster->HpShieldManager(dmg);
        this->SetMp(this->GetMp() - needMana);
        this->TurnManager();

        return true;
    }
}

// ----------------------��� �Լ�
// ���� ���
void Player::PrintInfo()
{
    Character::PrintInfo();
    std::cout << "[ ����: " << this->GetTypeName() << " ]" << std::endl;
    std::cout << "[ ������: " << this->GetGold() << " ]" << std::endl;
    std::cout << "[ ����ġ: " << this->GetExp() << " ]" << std::endl;

    return;
}
void Player::PrintUserInfo()
{
    setColor(YELLOW);
    std::cout << "==========================" << std::endl;
    std::cout << "���� : " << this->GetUserName() << std::endl;
    std::cout << "���� : " << this->GetUserAge() << std::endl;
    std::cout << "==========================" << std::endl;
}
void Player::PrintInventory()
{
    if (this->userInventory.size() == 0)
    {
        setColor(GREEN);
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
void Player::AddItem(Item* _item)
{
    for (int i = 0; i < userInventory.size(); i++)
    {
        // �κ��� ���� �������� ������ ���
        if (userInventory[i]->GetItemName() == _item->GetItemName())
        {
            // ������ �߰�
            userInventory[i]->SetItemNum(userInventory[i]->GetItemNum() + 1);
            delete(_item);

            return;
        }
    }
    this->userInventory.push_back(_item);
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
        this->userInventory[_index]->UseItem(this);
        if (this->userInventory[_index]->GetItemType() != ENUM_ITEM_EQUIP)
        {
            this->RemoveItem(_index);
        }
    }
}

// Get
UserInfo Player::GetUserInfo() { return this->userInfo; }
std::vector<Item*> Player::GetInventory() { return this->userInventory; }
std::string Player::GetItemName(int i) { return this->userInventory[i]->GetItemName(); }
std::string Player::GetTypeName() { return this->typeName; }
std::string Player::GetUserName() { return this->userInfo.userName; }
int Player::GetExp() { return this->exp; }
int Player::GetUserAge() { return this->userInfo.userAge; }
int Player::GetItemNum(int i) { return this->userInventory[i]->GetItemNum(); }
int Player::GetPlayerType() { return this->playerType; }
int Player::GetGold() { return this->gold; }
std::string Player::GetSkillNameA() { return this->SkillNameA; }
std::string Player::GetSkillNameB() { return this->SkillNameB; }
std::string Player::GetSkillNameC() { return this->SkillNameC; }

// Set Info
void Player::SetUserInfo(std::string _name, int _age)
{
    this->userInfo.userName = _name;
    this->userInfo.userAge = _age;
}
void Player::SetExp(int _exp)
{
    this->exp = _exp;
    return;
}
void Player::SetPlayerType(int _sel)
{
    this->playerType = _sel;
    return;
}
void Player::SetGold(int _money)
{
    this->gold = _money;
    return;
}
void Player::SetTypeName(std::string _typeName)
{
    this->typeName = _typeName;
    return;
}
void Player::SetSkillNameA(std::string _skillName)
{
    this->SkillNameA = _skillName;
    return;
}
void Player::SetSkillNameB(std::string _skillName)
{
    this->SkillNameB = _skillName;
    return;
}
void Player::SetSkillNameC(std::string _skillName)
{
    this->SkillNameC = _skillName;
    return;
}