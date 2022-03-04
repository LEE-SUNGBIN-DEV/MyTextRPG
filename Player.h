#pragma once
#include <iostream>
#include <vector>
#include "Character.h"
#include "Item.h"

// 직업 목록
enum MyPlayerType
{
    ENUM_PLAYER_NONE,
    ENUM_PLAYER_KNIGHT,
    ENUM_PLAYER_MAGICIAN
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
    std::vector<Item> userInventory;
    std::string typeName;
    int playerType;
    int dmg;
    int def;
    int exp;

public:
    // 생성자
    Player()
    {
        this->playerType = ENUM_PLAYER_NONE;
        this->dmg = 0;
        this->def = 0;
        this->exp = 0;
    }

    Player(int sel)
    {
        switch (sel)
        {
        case 1:
        {
            this->SetHp(300);
            this->SetMp(100);
            this->typeName = "KNIGHT";
            this->playerType = ENUM_PLAYER_KNIGHT;
            this->dmg = 5;
            this->def = 10;
            this->exp = 0;
            break;
        }
        case 2:
        {
            this->SetHp(100);
            this->SetMp(300);
            this->typeName = "MAGICIAN";
            this->playerType = ENUM_PLAYER_MAGICIAN;
            this->dmg = 10;
            this->def = 5;
            this->exp = 0;
            break;
        }
        }
    }

    // 공격 함수
    void Attack(Monster* monster);
    void SkillA(Monster* monster);
    void SkillB(Monster* monster);
    void SkillC(Monster* monster);

    // 기능 함수
    void PrintInfo();
    void PrintUserInfo();

    void AddItem(std::string _itemName, int _itemNum);
    
    // Get Info
    std::vector<Item> GetInventory();
    std::string GetItemName(int i);
    std::string GetUserName();
    std::string GetTypeName();
    UserInfo GetUserInfo();
    int GetUserAge();
    int GetDmg();
    int GetExp();
    int GetItemNum(int i);
    int GetDef();
    int GetPlayerType();

    // Set Info
    void SetUserInfo(std::string _name, int _age);
    void SetDmg(int _dmg);
    void SetExp(int _exp);
    void SetDef(int _def);
    void SetPlayerType(int _sel);
};