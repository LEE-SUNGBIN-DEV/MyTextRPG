#include "Item.h"
#include "Player.h"
#include "windows.h"

// --------------------------------- CLASS
// --------------------------------- ITEM
void Item::UseItem()
{
    setColor(SKYBLUE);
    if (this->GetItemNum() > 0)
    {
        std::cout << " [ " << this->GetItemName()
            << " 아이템을 사용하였습니다. ]" << std::endl;
    }

    else
    {
        std::cout << "ERROR: NOT ENOUGH ITEM" << std::endl;
    }
}
void Item::UseItem(Player* player)
{
    setColor(SKYBLUE);
    if (this->GetItemNum() > 0)
    {
        std::cout << " [" << this->GetItemName()
            << " 아이템을 사용하였습니다. ]" << std::endl;
    }

    else
    {
        std::cout << "ERROR: NOT ENOUGH ITEM" << std::endl;
    }
}

void Item::PrintItem()
{
    setColor(SKYBLUE);
    std::cout << "--------------------------------" << std::endl;
    std::cout << " [" << this->GetItemName() << "] "
        << "[ 수량: " << this->GetItemNum() << "]" << std::endl;
    std::cout << "--------------------------------" << std::endl;
}
void Item::PrintItem(int _index)
{
    setColor(SKYBLUE);
    std::cout << "--------------------------------" << std::endl;
    std::cout << " [ 슬롯 번호: " << _index << "] "
        << "[" << this->GetItemName() << "] "
        << "[ 수량: " << this->GetItemNum() << "]" << std::endl;
    std::cout << "--------------------------------" << std::endl;
}

// get
std::string Item::GetOriginName() { return this->originName; }
std::string Item::GetItemName() { return this->itemName; }
int Item::GetHoningLevel() { return this->honingLevel; }
int Item::GetItemNum() { return this->itemNum; }
int Item::GetItemPrice() { return this->itemPrice; }
int Item::GetItemType() { return this->itemType; }
int Item::GetDmg() { return this->dmg; }
int Item::GetDef() { return this->def; }
int Item::GetHp() { return this->hp; }
int Item::GetMp() { return this->mp; }
bool Item::GetIsEquip() { return this->isEquip; }

// set
void Item::SetOriginName(std::string _originName)
{
    this->originName = _originName;
}
void Item::SetItemName(std::string _itemName)
{
    this->itemName = _itemName;
}
void Item::SetHoningLevel(int _honingLevel)
{
    this->honingLevel = _honingLevel;
    return;
}
void Item::SetItemNum(int _itemNum)
{
    this->itemNum = _itemNum;
}
void Item::SetItemPrice(int _itemPrice)
{
    this->itemPrice = _itemPrice;
}
void Item::SetItemType(int _itemType)
{
    this->itemType = _itemType;
}
void Item::SetDmg(int _dmg)
{
    this->dmg = _dmg;
    return;
}
void Item::SetDef(int _def)
{
    this->def = _def;
    return;
}
void Item::SetHp(int _hp)
{
    this->hp = _hp;
    return;
}
void Item::SetMp(int _mp)
{
    this->mp = _mp;
    return;
}
void Item::SetIsEquip(bool _isEquip)
{
    this->isEquip = _isEquip;
    return;
}