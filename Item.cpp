#include "Item.h"

void Item::UseItem()
{
    if (this->itemNum > 0)
    {
        std::cout << this->itemName << " �������� ����Ͽ����ϴ�." << std::endl;
    }

    else
    {
        std::cout << "ERROR: NOT ENOUGH ITEM" << std::endl;
    }
}

void Item::PrintItem()
{
    std::cout << "==========================" << std::endl;
    std::cout << "�����۸�: " << this->itemName << std::endl;
    std::cout << "����: " << this->itemNum << std::endl;
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