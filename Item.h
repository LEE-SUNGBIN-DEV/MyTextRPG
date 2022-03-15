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
    std::string originName;
    std::string itemName;
    bool isEquip;
    int honingLevel;
    int itemType;
    int itemNum;
    int itemPrice;
    int dmg;
    int def;
    int hp;
    int mp;

public:
    // 생성자
    Item()
    {
        this->SetItemName("NONE");
        this->SetOriginName(this->GetItemName());
        this->SetHoningLevel(0);
        this->SetItemType(ENUM_ITEM_NONE);
        this->SetItemNum(1);
        this->SetItemPrice(0);
        this->SetHp(0);
        this->SetMp(0);
        this->SetDmg(0);
        this->SetDef(0);
        this->SetIsEquip(false);
    }

    Item(std::string _itemName, int _itemNum) : Item()
    {
        this->SetItemName(_itemName);
        this->SetOriginName(this->GetItemName());
        this->SetItemNum(_itemNum);
    }

    Item(std::string _itemName, int _itemNum, int _itemPrice) : Item()
    {
        this->SetItemName(_itemName);
        this->SetOriginName(this->GetItemName());
        this->SetItemNum(_itemNum);
        this->SetItemPrice(_itemPrice);
    }

    // 기능
    virtual void UseItem();
    virtual void UseItem(Player* player);
    virtual void PrintItem();
    virtual void PrintItem(int _index);

    // get
    virtual std::string GetOriginName();
    virtual std::string GetItemName();
    virtual int GetItemNum();
    virtual int GetItemPrice();
    virtual int GetItemType();
    virtual int GetHoningLevel();
    virtual int GetDmg();
    virtual int GetDef();
    virtual int GetHp();
    virtual int GetMp();
    virtual bool GetIsEquip();

    // set
    virtual void SetOriginName(std::string _originName);
    virtual void SetItemName(std::string _itemName);
    virtual void SetItemNum(int _itemNum);
    virtual void SetItemPrice(int _itemPrice);
    virtual void SetItemType(int _itemType);
    virtual void SetHoningLevel(int _honingLevel);
    virtual void SetDmg(int _dmg);
    virtual void SetDef(int _def);
    virtual void SetHp(int _hp);
    virtual void SetMp(int _mp);
    virtual void SetIsEquip(bool _isEquip);
};