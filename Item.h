#pragma once
#include <iostream>

class Item
{
private:
    std::string itemName;
    int itemNum;
    int itemPrice;

public:
    // 생성자
    Item()
    {
        this->itemName = "NONE";
        this->itemNum = 0;
        this->itemPrice = 0;
    }

    Item(std::string _itemName, int _itemNum)
    {
        this->itemName = _itemName;
        this->itemNum = _itemNum;
        this->itemPrice = 0;
    }

    Item(std::string _itemName, int _itemNum, int _itemPrice)
    {
        this->itemName = _itemName;
        this->itemNum = _itemNum;
        this->itemPrice = _itemPrice;
    }
    ~Item()
    {
        std::cout << "[ 아이템이 사라졌습니다. ]" << std::endl;
    }

    // 기능
    void UseItem();
    void PrintItem();
    void PrintItem(int _index);

    // get
    std::string GetItemName();
    int GetItemNum();
    int GetItemPrice();

    // set
    void SetItemName(std::string _itemName);
    void SetItemNum(int _itemNum);
    void SetItemPrice(int _itemPrice);
};