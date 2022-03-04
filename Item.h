#pragma once
#include <iostream>

class Item
{
private:
    std::string itemName;
    int itemNum = 0;

public:
    // ������
    Item(std::string _itemName, int _itemNum)
    {
        this->itemName = _itemName;
        this->itemNum = _itemNum;
    }

    // ���
    void useItem();

    // get
    std::string GetItemName();
    int GetItemNum();

    // set
    void SetItemName(std::string _itemName);
    void SetItemNum(int _itemNum);
};