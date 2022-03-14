#include "Item.h"
#include "Player.h"
#include "windows.h"

// --------------------------------- CLASS
// --------------------------------- ITEM
void Item::UseItem()
{
    setColor(VIOLET);
    if (this->GetItemNum() > 0)
    {
        std::cout << this->GetItemName() << " 아이템을 사용하였습니다." << std::endl;
    }

    else
    {
        std::cout << "ERROR: NOT ENOUGH ITEM" << std::endl;
    }
}

void Item::UseItem(Player* player)
{
    setColor(VIOLET);
    if (this->GetItemNum() > 0)
    {
        std::cout << this->GetItemName() << " 아이템을 사용하였습니다." << std::endl;
    }

    else
    {
        std::cout << "ERROR: NOT ENOUGH ITEM" << std::endl;
    }
}

void Item::PrintItem()
{
    setColor(VIOLET);
    std::cout << "--------------------------------" << std::endl;
    std::cout << "[" << this->GetItemName() << "] "
        << "[" << this->GetItemNum() << "]" << std::endl;
    std::cout << "--------------------------------" << std::endl;
}

void Item::PrintItem(int _index)
{
    setColor(VIOLET);
    std::cout << "--------------------------------" << std::endl;
    std::cout << "[슬롯 번호: " << _index << "] "
        << "[" << this->GetItemName() << "] "
        << "[" << this->GetItemNum() << "]" << std::endl;
    std::cout << "--------------------------------" << std::endl;
}

// get
std::string Item::GetItemName()
{
    return this->itemName;
}
int Item::GetItemNum()
{
    return this->itemNum;
}
int Item::GetItemPrice()
{
    return this->itemPrice;
}
int Item::GetItemType()
{
    return this->itemType;
}

// set
void Item::SetItemName(std::string _itemName)
{
    this->itemName = _itemName;
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