#include "Item.h"
#include "Player.h"

// --------------------------------- CLASS
// --------------------------------- ITEM
void Item::UseItem()
{
    if (this->GetItemNum() > 0)
    {
        std::cout << this->GetItemName() << " �������� ����Ͽ����ϴ�." << std::endl;
    }

    else
    {
        std::cout << "ERROR: NOT ENOUGH ITEM" << std::endl;
    }
}

void Item::UseItem(Player* player)
{
    if (this->GetItemNum() > 0)
    {
        std::cout << this->GetItemName() << " �������� ����Ͽ����ϴ�." << std::endl;
    }

    else
    {
        std::cout << "ERROR: NOT ENOUGH ITEM" << std::endl;
    }
}

void Item::PrintItem()
{
    std::cout << "--------------------------------" << std::endl;
    std::cout << "[" << this->GetItemName() << "] "
        << "[" << this->GetItemNum() << "]" << std::endl;
    std::cout << "--------------------------------" << std::endl;
}

void Item::PrintItem(int _index)
{
    std::cout << "--------------------------------" << std::endl;
    std::cout << "[���� ��ȣ: " << _index << "] "
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