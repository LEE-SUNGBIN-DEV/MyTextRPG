#include "Item.h"

void Item::useItem()
{
    if (this->itemNum > 0)
    {
        this->itemNum = this->itemNum - 1;
        std::cout << this->itemName << " �������� ����Ͽ����ϴ�." << std::endl;
    }

    else
    {
        std::cout << "ERROR: NOT ENOUGH ITEM" << std::endl;
    }
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