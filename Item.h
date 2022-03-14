#pragma once
#include <iostream>

enum ItemType
{
    ENUM_ITEM_NONE,
    ENUM_ITEM_POTION,
    ENUM_ITEM_EQUIP
};

class Player;
// --------------------------------- CLASS
// --------------------------------- ITEM
class Item
{
private:
    std::string itemName;
    int itemType;
    int itemNum;
    int itemPrice;

public:
    // 생성자
    Item()
    {
        this->SetItemName("NONE");
        this->SetItemType(ENUM_ITEM_NONE);
        this->SetItemNum(1);
        this->SetItemPrice(0);
    }

    Item(std::string _itemName, int _itemNum) : Item()
    {
        this->SetItemName(_itemName);
        this->SetItemNum(_itemNum);
    }

    Item(std::string _itemName, int _itemNum, int _itemPrice) : Item()
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
    virtual void PrintItem();
    virtual void PrintItem(int _index);

    // get
    std::string GetItemName();
    int GetItemNum();
    int GetItemPrice();
    int GetItemType();

    // set
    void SetItemName(std::string _itemName);
    void SetItemNum(int _itemNum);
    void SetItemPrice(int _itemPrice);
    void SetItemType(int _itemType);
};