#pragma once
#include <iostream>
#include <vector>
#include "Item.h"
#include "Character.h"

class Monster;

// 직업 목록
enum MyPlayerType
{
    ENUM_PLAYER_NONE,
    ENUM_PLAYER_KNIGHT,
    ENUM_PLAYER_WIZARD
};

struct UserInfo
{
    std::string userName;
    int userAge;

    UserInfo()
    {
        this->userName = "NONE";
        this->userAge = 0;
    }
};

// --------------------------------- CLASS
// --------------------------------- PLAYER
class Player : public Character
{
private:
    UserInfo userInfo;
    std::vector<Item*> userInventory;
    std::string typeName;
    int playerType;
    int exp;
    int money;

public:
    // 생성자
    Player()
    {
        this->SetPlayerType(ENUM_PLAYER_NONE);
        this->SetExp(0);
        this->SetMoney(50);
    }

    ~Player()
    {
    }

    // 공격 함수
    virtual bool Attack(Monster* monster);
    virtual bool SkillA(Monster* monster);
    virtual bool SkillB(Monster* monster);
    virtual bool SkillC(Monster* monster);

    // 기능 함수
    void PrintInfo();
    void PrintUserInfo();
    void PrintInventory();

    void AddItem(std::string _itemName);
    void AddItem(std::string _itemName, int _itemNum);
    void AddItem(Item* _item);
    void RemoveItem(int _index);
    void RemoveItem(std::string _name);
    void RemoveItem(std::string _name, int _itemNum);
    int SearchItem(std::string _name);
    void UseInventoryItem(int _index);

    // Get Info
    std::vector<Item*> GetInventory();
    std::string GetItemName(int i);
    std::string GetUserName();
    std::string GetTypeName();
    UserInfo GetUserInfo();
    int GetUserAge();
    int GetExp();
    int GetItemNum(int i);
    int GetPlayerType();
    int GetMoney();

    // Set Info
    void SetUserInfo(std::string _name, int _age);
    void SetExp(int _exp);
    void SetPlayerType(int _sel);
    void SetMoney(int _money);
    void SetTypeName(std::string _typeName);
};