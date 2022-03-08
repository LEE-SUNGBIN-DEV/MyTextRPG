#include "Item.h"

void Item::UseItem()
{
    if (this->itemNum > 0)
    {
        std::cout << this->itemName << " 아이템을 사용하였습니다." << std::endl;
    }

    else
    {
        std::cout << "ERROR: NOT ENOUGH ITEM" << std::endl;
    }
}

void Item::PrintItem()
{
    std::cout << "==========================" << std::endl;
    std::cout << "아이템명: " << this->itemName << std::endl;
    std::cout << "수량: " << this->itemNum << std::endl;
    std::cout << "==========================" << std::endl;
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

// set
void Item::SetItemName(std::string _itemName)
{
    this->itemName = _itemName;
}

void Item::SetItemNum(int _itemNum)
{
    this->itemNum = _itemNum;
}