#pragma once
#include <iostream>

class Player;
// --------------------------------- CLASS
// --------------------------------- ITEM
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
        this->SetItemName("NONE");
        this->SetItemNum(0);
        this->SetItemPrice(0);
    }

    Item(std::string _itemName, int _itemNum)
    {
        this->SetItemName(_itemName);
        this->SetItemNum(_itemNum);
        this->SetItemPrice(0);
    }

    Item(std::string _itemName, int _itemNum, int _itemPrice)
    {
        this->SetItemName(_itemName);
        this->SetItemNum(_itemNum);
        this->SetItemPrice(_itemPrice);
    }
    ~Item()
    {
    }

    // 기능
    virtual void UseItem();
    virtual void UseItem(Player* player);
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